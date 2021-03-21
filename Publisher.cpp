#include "Publisher.h"

void Publisher::operator() () {
    while (true) {
        std::unique_lock<std::mutex> lock(mutex_);
        variable_.wait(lock, [&finish_ = this->finish_, &buffer_ = this->buffer_] () {return finish_ || buffer_!= nullptr;});
        if (finish_) {
            break;
        }
        for (std::shared_ptr<Processor>& ptr : workers_) {
            ptr->Process(*buffer_);
        }
        buffer_ = nullptr;
        variable_.notify_all();
    }
}

void Publisher::AddWorker(std::shared_ptr<Processor> worker) {
    workers_.push_back(std::move(worker));
}

void Publisher::SetBuffer(std::shared_ptr<std::vector<std::shared_ptr<Figure>>> buffer) {
    buffer_ = std::move(buffer);
}

void Publisher::Notify() {
    std::unique_lock<std::mutex> lock(mutex_);
    variable_.notify_all();
    variable_.wait(lock, [this] () { return buffer_ == nullptr;});
}

void Publisher::Finish() {
    finish_ = true;
    variable_.notify_all();
}

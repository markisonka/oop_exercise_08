#pragma once

#include <mutex>
#include <memory>
#include <condition_variable>
#include "Processor.h"

class Publisher {
public:
    void operator() ();

    void AddWorker(std::shared_ptr<Processor> worker);

    void SetBuffer(std::shared_ptr<std::vector<std::shared_ptr<Figure>>> buffer);

    void Notify();

    void Finish();

private:
    std::mutex mutex_;
    std::condition_variable variable_;
    std::vector<std::shared_ptr<Processor>> workers_;
    std::shared_ptr<std::vector<std::shared_ptr<Figure>>> buffer_;
    bool finish_ = false;
};
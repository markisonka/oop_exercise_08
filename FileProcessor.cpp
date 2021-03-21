#include "FileProcessor.h"

void FileProcessor::Process(const std::vector<std::shared_ptr<Figure>> &buf) {
    std::ofstream fs("Buffer_" + std::to_string(counter_++), std::ios::out | std::ios::trunc);
    if (!fs) {
        throw std::runtime_error("File wasnt open");
    }
    for (const std::shared_ptr<Figure>& ptr : buf) {
        ptr->Print(fs);
        fs << "\n";
    }
}
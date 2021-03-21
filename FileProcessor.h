#pragma once

#include <fstream>
#include "../Processor.h"

class FileProcessor : public Processor {
public:
    void Process(const std::vector<std::shared_ptr<Figure>>& buf) override;

private:
    unsigned counter_ = 1;
};
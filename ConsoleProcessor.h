#pragma once

#include "../Processor.h"

class ConsoleProcessor : public Processor {
public:
    void Process(const std::vector<std::shared_ptr<Figure>>& buf) override;
};
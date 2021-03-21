#pragma once

#include <vector>
#include <memory>
#include "Figure.h"

class Processor {
public:
    virtual void Process(const std::vector<std::shared_ptr<Figure>>& buf) = 0;
};
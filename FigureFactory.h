#pragma once

#include "Figures/Pentagon.h"
#include "Figures/Trapeze.h"
#include <string>
#include "Figures/Rhombus.h"
#include <memory>

class FigureFactory {
public:
    static std::unique_ptr<Figure> CreateFigure(std::istream& is);
};
//
// Created by ilya on 29.12.2019.
//

#include "FigureFactory.h"

std::unique_ptr<Figure> FigureFactory::CreateFigure(std::istream& is) {
    std::string figure_type;
    is >> figure_type;
    for (char& c : figure_type) {
        c = std::tolower(c);
    }
    if (figure_type == "trapeze") {
        return std::make_unique<Trapeze>(is);
    } else if (figure_type == "pentagon") {
        return std::make_unique<Pentagon>(is);
    } else if (figure_type == "rhombus") {
        return std::make_unique<Rhombus>(is);
    } else {
        throw std::logic_error("Wrong type of figure");
    }
}
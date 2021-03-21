#pragma once
#include "../Figure.h"

class Rhombus : public Figure {
public:
    Rhombus(std::istream& is);
    Rhombus(Point p1_, Point p2_, Point p3_, Point p4_);
    void Print(std::ostream& os) const override;

private:
    Point p1_, p2_, p3_, p4_;
};
#pragma once

#include "../Figure.h"

class Pentagon : public Figure {
public:
    Pentagon(std::istream& is);
    explicit Pentagon(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5);
    void Print(std::ostream& os) const override;

private:
    Point p1_, p2_, p3_, p4_, p5_;
};
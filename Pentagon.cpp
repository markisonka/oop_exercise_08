#include "Pentagon.h"

Pentagon::Pentagon(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5)
        : p1_(p1), p2_(p2), p3_(p3), p4_(p4), p5_(p5) {}


void Pentagon::Print(std::ostream& os) const {
    os << "Pentagon, p1: " << p1_ << ", p2: " << p2_ << ", p3: " << p3_ << ", p4: " << p4_ << ", p5: " << p5_;
}

Pentagon::Pentagon(std::istream &is) {
    Point p1, p2, p3, p4, p5;
    is >> p1 >> p2 >> p3 >> p4 >> p5;
    *this = Pentagon(p1,p2,p3,p4,p5);
}
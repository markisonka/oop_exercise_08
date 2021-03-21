#pragma once

#include <numeric>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

struct Point {
    double x = 0;
    double y = 0;
};

std::ostream& operator << (std::ostream& os, const Point& p);
std::istream& operator >> (std::istream& is, Point& p);
Point operator + (Point lhs, Point rhs);
Point operator - (Point lhs, Point rhs);
Point operator / (Point lhs, double a);
Point operator * (Point lhs, double a);

class Vector {
public:
    explicit Vector(double a, double b);
    explicit Vector(Point a, Point b);
    bool operator == (Vector rhs);
    Vector operator - ();
    friend double operator * (Vector lhs, Vector rhs);
    double length() const;
    double x;
    double y;
};

bool is_parallel(const Vector& lhs, const Vector& rhs);
bool is_perpendecular(const Vector& lhs, const Vector& rhs);
double point_and_line_distance(Point p1, Point p2, Point p3);

class Figure {
public:
    virtual void Print(std::ostream& os) const = 0;
    virtual ~Figure() = default;
};

std::ostream& operator << (std::ostream& os, const Figure& fig);
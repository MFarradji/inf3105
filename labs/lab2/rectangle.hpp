#pragma once
#include "point.hpp"

class Rectangle {
  public:
    Rectangle();
    Rectangle(const Point& p1, const Point& p2);
  private:
    Point point1;
    Point point2;
};

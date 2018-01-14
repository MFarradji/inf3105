#include "rectangle.hpp"

Rectangle::Rectangle() {}

Rectangle::Rectangle(const Point& p1, const Point& p2) : point1(p1) {
  point2 = p2;
}

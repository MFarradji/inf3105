#include <assert.h>
#include <cmath>
#include "point.hpp"

Point::Point(double _x, double _y) : x(_x), y(_y) {
  cerr << "Point(double, double) " << this << endl;
}

Point::Point(const Point& point) : x(point.x), y(point.y) {
  cerr << "Point(const Point&) " << this << endl;
}

Point::~Point() {
  cerr << "~Point() " << this << endl;
}

double Point::distance(const Point& point) const {
  double dx = x - point.x;
  double dy = y - point.y;
  return sqrt(dx * dx + dy * dy);
}

ostream& operator << (ostream& os, const Point& point) {
  os << "(" << point.x << "," << point.y << ")";
  return os;
}

istream& operator >> (istream& is, Point& point) {
  char po, vir, pf;
  is >> po;
  if (is) {
    is >> point.x >> vir >> point.y >> pf;
    assert(po == '(');
    assert(vir == ',');
    assert(pf == ')');
  }
}

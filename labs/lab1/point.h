/*
  UQAM / Département d'informatique
  INF3105
  Laboratoire 1
*/

// Ces deux lignes (directives au préprocesseur) permettent d'éviter d'inclure 2 fois ce .h à la compilation.
#if !defined(__POINT_H__)
#define __POINT_H__
// attention : toujours fermer le #if par un #endif à la toute fin!

#include <iostream>

class Point {
  public:
    Point(){}
    Point(double x, double y);
    Point(const Point&);

    double distance(const Point&) const;

  private:
    double x;
    double y;

  friend std::ostream& operator << (std::ostream&, const Point&);
  friend std::istream& operator >> (std::istream&, Point&);
};

#endif // fin du #if plus haut

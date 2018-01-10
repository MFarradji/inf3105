/*
  à compléter ...

*/

// Ces deux lignes (directives au préprocesseur) permettent d'éviter d'inclure 2 fois ce .h à la compilation.
#if !defined(__POINT_H__)
#define __POINT_H__
// attention : toujours fermer le #if par un #endif à la toute fin!

#include <iostream>


class Point {
  public:
    Point(){}
    Point(float x, float y);
    Point(const Point&);

    float distance(const Point&) const;

  //private: // ne pas décommenter tout de suite
    float x;
    float y;

  friend std::ostream& operator << (std::ostream&, const Point&);
  friend std::istream& operator >> (std::istream&, Point&);
};

#endif // fin du #if plus haut


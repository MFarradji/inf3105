#include <iostream>
#include <math.h>

using namespace std;

class Forme2D {
  public:
    Forme2D(double x = 0, double y = 0);
    Forme2D(const Forme2D&);
    virtual double surface() = 0;
  protected:
    double centre_x;
    double centre_y;
};

class Cercle : virtual public Forme2D {
  public:
    Cercle(double x = 0, double y = 0, double r = 0);
    Cercle(const Cercle&);
    double surface();
  protected:
    double rayon;
};

class Forme3D : virtual public Forme2D {
  public:
    Forme3D(double x = 0, double y = 0, double z = 0);
    virtual double volume() = 0;
  protected:
    double centre_z;
};

class Cylindre : virtual public Cercle, virtual public Forme3D {
  public:
    Cylindre(double x = 0, double y = 0, double z = 0, double r = 0, double h = 0);
    double surface();
    double volume();
  protected:
    double hauteur;
};

class Sphere : virtual public Cercle, virtual public Forme3D {
  public:
    Sphere(double x = 0, double y = 0, double z = 0, double r = 0);
    double surface();
    double volume();
};

const double PI = 3.1415926;

Forme2D::Forme2D(double x, double y) {
  centre_x = x;
  centre_y = y;
}

Forme2D::Forme2D(const Forme2D& forme2D) {
  centre_x = forme2D.centre_x;
  centre_y = forme2D.centre_y;
}

Cercle::Cercle(double x, double y, double r) : Forme2D(x, y) {
  rayon = r;
}

Cercle::Cercle(const Cercle& cercle) : Forme2D(cercle.centre_x, cercle.centre_y) {
  rayon = cercle.rayon;
}

double Cercle::surface() {
  return PI * pow(rayon, 2);
}

Forme3D::Forme3D(double x, double y, double z) : Forme2D(x, y) {
  centre_z = z;
}

Cylindre::Cylindre(double x, double y, double z, double r, double h) : Forme3D(x, y, z) {
  rayon = r;
  hauteur = h;
}

double Cylindre::surface() {
  return (2 * PI * rayon * hauteur) + (2 * Cercle::surface());
}

double Cylindre::volume() {
  return Cercle::surface() * hauteur;
}

Sphere::Sphere(double x, double y, double z, double r) : Forme3D(x, y, z) {
  rayon = r;
}

double Sphere::surface() {
  return 4 * Cercle::surface();
}

double Sphere::volume() {
  return surface() * rayon / 3;
}

int main() {
  Cercle cercle1;
  Cercle cercle2(1, 1, 1);
  Cercle cercle3(cercle2);
  cout << "surface de cercle1 = " << cercle1.surface() << endl;
  cout << "surface de cercle2 = " << cercle2.surface() << endl;
  cout << "surface de cercle3 = " << cercle3.surface() << endl;

  Cylindre cylindre1;
  Cylindre cylindre2(1, 1, 1, 1, 3);
  cout << "surface de cylindre1 = " << cylindre1.surface() << endl;
  cout << "surface de cylindre2 = " << cylindre2.surface() << endl;
  cout << "volume de cylindre1 = " << cylindre1.volume() << endl;
  cout << "volume de cylindre2 = " << cylindre2.volume() << endl;

  Sphere sphere1;
  Sphere sphere2(1, 1, 1, 1);
  cout << "surface de sphere1 = " << sphere1.surface() << endl;
  cout << "surface de sphere2 = " << sphere2.surface() << endl;
  cout << "volume de sphere1 = " << sphere1.volume() << endl;
  cout << "volume de sphere2 = " << sphere2.volume() << endl;
}

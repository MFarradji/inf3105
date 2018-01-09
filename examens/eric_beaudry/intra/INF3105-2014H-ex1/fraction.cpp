/* fraction.cpp */
#include "fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction(int n, int d) : numerateur(n) {
  denominateur = d;
  cout << "F" << n << "/" << d << " ";
  simplifier();
}

Fraction::~Fraction() {
  cout << "K" << numerateur << "/" << denominateur << " ";
  numerateur = denominateur = 0;
}

void Fraction::simplifier() {

}

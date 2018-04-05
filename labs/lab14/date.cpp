#include "date.h"

Date::Date(int a, int M, int j, int h, int m, int s) : annee(a), mois(M), jour(j), heure(h), minute(m), seconde(s) {}

int Date::hash() const {
  return jour ^ heure ^ minute;
  //return annee + mois + jour + heure + minute + seconde;
}

bool Date::operator==(const Date& d) const {
  return annee == d.annee && mois == d.mois && jour == d.jour && heure == d.heure && minute == d.minute && seconde == d.seconde;
}

bool Date::operator!=(const Date& d) const {
  return !(*this == d);
}

bool Date::operator<(const Date& d) const {
  if (annee != d.annee)
    return annee < d.annee;
  if (mois != d.mois)
    return mois < d.mois;
  if (jour != d.jour)
    return jour < d.jour;
  if (heure != d.heure)
    return heure < d.heure;
  if (minute != d.minute)
    return minute < d.minute;
  return seconde < d.seconde;
}

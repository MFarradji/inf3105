#if !defined(DATE_H)
#define DATE_H

class Date {
  public:
    Date(int a = 2000, int M = 1, int j = 1, int h = 0, int m = 1, int s = 0);

    int hash() const;
    bool operator==(const Date& d) const;
    bool operator!=(const Date& d) const;
    bool operator<(const Date& d) const;

  protected:
    int annee;
    int mois;
    int jour;
    int heure;
    int minute;
    int seconde;
};

#endif

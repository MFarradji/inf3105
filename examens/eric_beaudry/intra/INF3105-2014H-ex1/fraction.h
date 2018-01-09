/* fraction.h */
class Fraction {
  public:
    Fraction(int n = 0, int d = 1);
    ~Fraction();

    Fraction& operator += (const Fraction& f) const;
    Fraction operator + (const Fraction& f) const;
    bool operator < (const Fraction& f) const;
  private:
    int numerateur, denominateur;
    void simplifier();
};

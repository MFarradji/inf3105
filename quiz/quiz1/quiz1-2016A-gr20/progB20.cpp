/* Programme B pour groupe 20 */
#include <iostream>
using namespace std;
int c1=0, c2=0, c3=0;

class A{
  public:
    A(int y=1) : z(y){
      c1+=z; 
    }
    ~A(){
        c2+=z;
    }
  private:
    int z;
};

class B{
  public:
    B(){
      a1 = new A(++c3);
    }
  private:
    A *a1;
    A  a2;
};
void main2(){
    B* b1=new B();
    A a2(2), a3(3);
    a2=a3;
    delete b1;
}
int main(){
    A a(-2);
    main2();
    cout << "c1=" << c1 << '\t'
         << "c2=" << c2 << '\t'
         << "c3=" << c3 << endl;
}

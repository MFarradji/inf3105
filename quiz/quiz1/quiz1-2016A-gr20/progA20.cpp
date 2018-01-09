/* Programme A pour groupe 20 */
#include <iostream>
using namespace std;

int f(int *tab, int n){
    int* t1 = new int[n];
    int* t2 = new int[n];
    int k1=0, k2=0;
    for(int i=0;i<n;i++){
        bool ok=true;
        for(int j=0;j<k1;j++)
            if(tab[i]==t1[j])
                ok=false;
        if(ok)
            t1[k1++] = tab[i];
        else
            t2[k2++] = tab[i];
    }
    for(int i=0;i<k1;i++)
        tab[i]=t1[i];
    for(int i=0;i<k2;i++)
        tab[k1+i]=t2[i];
    if(k1+k2==n){
        delete[] t1;
        delete[] t2;
    }
    return k1;
}
int main(){
    int n=0;
    cin >> n; // hypothèse n>=1
    int* tab = new int[n];
    for(int i=0;i<n;i++)
        cin >> tab[i];
    int k = f(tab, n);
    for(int i=0;i<n;i++)
        cout << tab[i] << '\t';
    cout << endl << k << endl;
    delete[] tab;
}

/* Programme A pour groupe 30 */
#include <iostream>
using namespace std;
void f(int *tab, int n){
    int* t = new int[n];
    int k=0, l=n;
    do{
        int x=tab[0], m=l;
        l=0;
        for(int i=0;i<m;i++)
            if(tab[i]>=x){
            
                x = tab[i];
                t[k++] = x;
            }else{
                tab[l++] = tab[i];
                
            }
    }while(l>0);
    if(k!=n){
        cout << "?" << endl;
        return;
    }
    for(int i=0;i<n;i++)
        tab[i] = t[i];
    delete[] t;
}
int main(){
    int n=0;
    cin >> n;
    int* tab = new int[n];
    for(int i=0;i<n;i++)
        cin >> tab[i];
    f(tab, n);
    for(int i=0;i<n;i++)
        cout << tab[i] << '\t';
    cout << endl;
    delete[] tab;
}

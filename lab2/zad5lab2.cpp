#include <iostream>
using namespace std;

void zam(int *x, int *y){
        int a=*x;
        *x=*y;
        *y=a;
}
int main(){
    int a,b;
    cout<<"Wprowadz dwie liczby a i b:"<<endl;
    cin>>a;
    cin>>b;
    cout<<"Adres liczby a = "<<&a<<" Wartosc liczby a = "<<a<<endl;
    cout<<"Adres liczby b = "<<&b<<" Wartosc liczby b = "<<b<<endl;
    zam(&a,&b);
    cout<<"Po zamianie: adres liczby a = "<<&a<<" Wartosc liczby a = "<<a<<endl;
    cout<<"Po zamianie: adres liczby b = "<<&b<<" Wartosc liczby b = "<<b<<endl;
    return 0;
    }

#include <iostream>
using namespace std;

void zam(int &x, int &y){
        int a = y;
        y = x;
        x = a;
}

int main(){
    int a,b;
    cout<<"Wprowadz dwie liczby a i b:"<<endl;
    cin>>a;
    cin>>b;
    cout<<"Liczby przed zamiana:"<<endl;
    cout<<"a = "<<a<<"  b = "<<b<<endl;
    zam(a, b);
    cout<<"Liczby po zamianie"<<endl;
    cout<<"a = "<<a<<"  b = "<<b<<endl;
    return 0;
}

#include <iostream>
using namespace std;

int fun(int &x, int y){
        int ilocz = x*y;
        x+=y;
        return ilocz;
}
int main(){
    int a,b, ilocz;
    cout<<"Wprowadz dwie liczby a i b:"<<endl;
    cin>>a;
    cin>>b;
    cout<<"Liczby przed funkcja:"<<endl;
    cout<<"a = "<<a<<"  b = "<<b<<endl;
    ilocz=fun(a,b);
    cout<<"Suma a i b = "<<a<<endl;
    cout<<"Iloczyn a i b = "<<ilocz<<endl;
    return 0;
    }

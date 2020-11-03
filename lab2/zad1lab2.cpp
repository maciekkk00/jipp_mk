#include <iostream>
using namespace std;

void zam(int *x,int *y)
{
    if(*y < *x){
        int a = *x;
        *x = *y;
        *y = a;
    }

}
int main()
{
    int a,b;
    int x,y;
    cout<<"Wprowadz dwie liczby a i b:"<<endl;
    cin>>a;
    cin>>b;
    cout<<"Liczby przed zamiana:"<<endl;
    cout<<"a = "<<a<<"  b = "<<b<<endl;
    x=a;
    y=b;
    zam(&a,&b);
    cout<<"Liczby po zamianie"<<endl;
    cout<<"a = "<<a<<"  b = "<<b<<endl;
    return 0;
}

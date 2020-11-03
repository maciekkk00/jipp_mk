#include <iostream>
using namespace std;

void zam(int &a, int *b){
        int x = a;
        a = *b;
        *b = x;
}
int main(){
    int x,y;
    cout<<"Wprowadz dwie liczby x i y:"<<endl;
    cin>>x;
    cin>>y;
    cout<<"Liczby przed zamiana:"<<endl;
    cout<<"x = "<<x<<"  y = "<<y<<endl;
    zam(x,&y);
    cout<<"Liczby po zamianie"<<endl;
    cout<<"x = "<<x<<"  y = "<<y<<endl;
    return 0;
    }

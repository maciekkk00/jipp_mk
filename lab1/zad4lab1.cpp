#include <iostream>
using namespace std;

int main()
{
 cout<<"Sprawdzanie liczb skojarzonych"<<endl;
 int x,y,sum1=0,sum2=0;
 cout<<"Wprowadz pierwsza liczbe "<<endl;
 cin>>x;
 cout<<"Wprowadz druga liczbe "<<endl;
 cin>>y;
 cout<<" Dzielniki pierwszej liczby: ";
 for (int i=1; i<x; i++)
 if (x%i==0) {
 cout<<i<<" ";
 sum1+=i;
 }
cout<<endl;
cout<<" Suma dzilnikow pierwszej liczby:  "<<sum1<<endl;
cout<<" Dzielniki drugiej liczby: ";
for (int i=1; i<y; i++)
if (y%i==0) {
cout<<i<< " ";
sum2+=i;
}
cout<<endl;
cout<<" Suma dzielnikow drugiej liczby = "<<sum2<<endl;
if (sum1==y+1 && sum2==x+1) 
cout<<" Sa to liczby skojarzone "<<endl;
else cout<<" Nie sa to liczby skojarzone "<<endl;
return 0;
}
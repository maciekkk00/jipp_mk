#include <iostream>

using namespace std;

int main()
{
    int tab1[2][3],tab2[2][3],tab3[2][3];
    int i,j;
   cout<<"Wprowadz 1 macierz o rozmiarach [2]x[3]"<<endl;
   for(int i=0;i<2;i++)
   for(int j=0;j<3;j++)
   cin>>tab1[i][j];
   
   cout<<"Wprowadz 2 macierz o rozmiarach [2]x[3]"<<endl; 
   for(int i=0;i<2;i++)
   for(int j=0;j<3;j++)
   {
   cin>>tab2[i][j];
   tab3[i][j] = tab1[i][j] + tab2[i][j];
   }
   cout<<"Suma macierzy: "<<endl;
    for (i=0; i<2; i++) {
        for (j=0; j<3; j++) 
           cout<<tab3[i][j]<<" ";
           cout<<endl;
        
    }
   
   return 0;
}
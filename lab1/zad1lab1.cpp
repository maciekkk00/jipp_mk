#include<iostream>
#include<cstdlib>
using namespace std;

void sort(int tab[],int k)
{
	for(int i=0;i<k;i++)
		for(int j=1;j<k-i;j++)
		if(tab[j-1]>tab[j])
			swap(tab[j-1], tab[j]);
}

int main()
{
	int *tab, k;
	cout<<"Podaj ilosc liczb do posortowania "<<endl;
	cin>>k;
	tab = new int [k];
	cout<<"Podaj cyfry "<<endl;
	for(int i=0;i<k;i++)
		cin>>tab[i];
	
	sort(tab,k);
	
	cout<<"Wynik: "<<endl;
	for(int i=0;i<k;i++)
          cout<<tab[i]<<" ";
      cout<<endl;
  system("pause");
  return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

bool spr(char tab[])
{
	int k; 
	k = strlen(tab); 
	--k; 
	for(int i=0;i<=k/2;i++)
	  if(tab[i]!=tab[k-i]) 
	  	return false;		
	  return true; 	
}
int main()
{
	int s; 
	char slowo[100];
	cout<<"Wprowadz liczbe slow ktore chcesz sprawdzic"<<endl;
	cin>>s; 
	
	while(s--) 
	{
	    cout<<"Wpisz slowo"<<endl;
		cin>>slowo;
		
		if(spr(slowo)) 
		   cout<<"To slowo jest palindromem tekstowym"<<endl;
		else
		   cout<<"To slowo nie jest palindromem tekstowym "<<endl;
		
	}
	   
	return 0;
}
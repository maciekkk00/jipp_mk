#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Lab6/employee.hpp>
#include <Lab6/hrms.hpp>

using namespace std;

int main() {
    Employee em1,em2,em3,em4,em5,em6,em7,em8,em9,em10;
    HRMS hr;
	srand(time(NULL));

    em1.utworzPrac("001","Jaroslaw","Rys","Programista");
    em2.utworzPrac("002","Roksana", "Caban","Programista");
    em3.utworzPrac("003","Natalia","Kot","Programista");
    em4.utworzPrac("004","Wiktoria","Dybiec","Grafik");
    em5.utworzPrac("005","Daniel","Pelikan","Grafik");
    em6.utworzPrac("006","Grzegorz","Gaza","Grafik");
    em7.utworzPrac("007","Emil","Baran","Ksiegowy");
    em8.utworzPrac("008","Piotr","Sasin","Ksiegowy");
    em9.utworzPrac("009","Janusz","Malarz","Ksiegowy");
    em10.utworzPrac("010","Robert","Maciaszek","Prezes");

    hr.add(em1, "Netflix", (rand()%50)*100+1000);
    hr.add(em2, "Netflix", (rand()%50)*100+1000);
    hr.add(em3, "HBOGO", (rand()%50)*100+1000);
    hr.add(em4, "HBOGO", (rand()%50)*100+1000);
    hr.add(em5, "HBOGO", (rand()%50)*100+1000);
    hr.add(em6, "Netflix", (rand()%50)*100+1000);
    hr.add(em7, "AppleTV", (rand()%50)*100+1000);
    hr.add(em8, "AppleTV", (rand()%50)*100+1000);
    hr.add(em9, "HBOGO", (rand()%50)*100+1000);
    hr.add(em10, "Netflix", (rand()%50)*100+1000);
    
    
    cout<<endl<<"Pracownicy pracujacy w departamencie Netflix:";
    hr.printDepartment("Netflix");
    cout<<endl;

    cout<<"Pracownicy pracujacy w departamencie HBOGO:";
    hr.printDepartment("HBOGO");
    cout<<endl;

    cout<<"Pracownicy pracujacy w departamencie AppleTV:";
    hr.printDepartment("AppleTV");
    cout<<endl;

    cout<<"Zarobki:";
    hr.printSalaries();
    cout<<endl;

    //zmiana salary dla Jaroslawa Rysia
    hr.changeSalary("001",5000);

    cout<<"Posortowane zarobki pracownikow:";
    hr.printSalariesSorted();
    cout<<endl;

    return 0;
}

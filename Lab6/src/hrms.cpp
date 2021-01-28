#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include <map>
#include <algorithm>
#include <Lab6/employee.hpp>
#include <Lab6/hrms.hpp>
#include <privateException.hpp>

using namespace std; 
vector<Employee> listaPr; // kontener w ktorym beda przchowywani wszyscy pracownicy
map<string, string> idDepPra; //kontener w ktorym bedzie przechowywane mapowanie pomiedzy identyfikatorami departamentow a identyfikatorami wszystkich pracownikow danego departamentu
map<string, double> salaryPra; //kontener w ktroym beda przechowywane informacje o zarobkach pracownikow

void HRMS::add(Employee employee, string departmentId, double salary) 
{
    employee.setDepartmentId(departmentId); 
    listaPr.push_back(employee); 
    idDepPra.insert(make_pair(departmentId, employee.getId())); 
    salaryPra.insert(make_pair(employee.getId(),salary));
}

void HRMS::printDepartment(string departmentId) 
{
    BrakPra brakPra; 
    BrakDep brakDep;
    try {
        if(listaPr.size()==0) throw brakPra; 
        if(idDepPra.size()==0) throw brakDep; 
        cout<<endl;
        for(int i=0; i<listaPr.size(); i++) {
            if(listaPr[i].getDepartmentId()==departmentId) 
			{
                cout<<"ID: "; 
                cout.width(4); 
                cout<<left<<listaPr[i].getId()<<" Imie i nazwisko: "; 
                cout.width(15);
                cout<<listaPr[i].getName()<<" ";
                cout.width(15);
                cout<<listaPr[i].getSurname()<<" Stanowisko: ";
                cout.width(25);
                cout<<listaPr[i].getPosition()<<endl;
            }
        }
    }
    catch(exception &e) 
	{
        cout<<e.what()<<endl; 
    }
}

void HRMS::changeSalary(string employeeId, double salary) 
{
    BrakIdPra brakIdPra; 
    try {
        if(employeeId.size()==0) throw brakIdPra; 
        salaryPra[employeeId]=salary; 
    }
    catch(exception &e){ 
        cout<<e.what()<<endl; 
    }
}

void HRMS::printSalaries() 
{
    BrakPra brakPra; 
    try {
        if(listaPr.size()==0) throw brakPra; 
        map<string, double>::iterator itr; 
        cout<<endl;
        for(itr=salaryPra.begin(); itr!=salaryPra.end(); itr++) 
		{
            string temp=itr->first; 
            Employee tempEmp; 

            for(int i=0; i<listaPr.size(); i++)
                if(temp==listaPr[i].getId()) tempEmp=listaPr[i]; 

            cout<<" Wyplata: ";
            cout.width(4);
            cout<<itr->second<<" ID: ";
            cout.width(4);
            cout<<left<<temp<<" Imie i nazwisko: ";
            cout.width(15);
            cout<<tempEmp.getName()<<" ";
            cout.width(15);
            cout<<tempEmp.getSurname()<<" Department ID: ";
            cout.width(10);
            cout<<tempEmp.getDepartmentId()<<" Stanowisko: ";
            cout.width(25);
            cout<<tempEmp.getPosition()<<endl;
        }
    }
    catch(exception &e){
        cout<<e.what()<<endl; 
    }
}

void HRMS::printSalariesSorted() 
{
    BrakPra brakPra; 
    try {
        if(listaPr.size()==0) throw brakPra;
        map<string, double>::iterator itr; 
        typedef pair<double, string>pary; 
        vector<pary> vec; 

        cout<<endl;

        for(itr=salaryPra.begin(); itr!=salaryPra.end(); itr++) 
		{
            vec.push_back(make_pair(itr->second, itr->first)); 
        }

        sort(vec.begin(), vec.end()); 

        for(int i=0; i<vec.size();i++) 
		{
            string temp=vec[i].second; 
            Employee tempEmp;

            for(int j=0; j<listaPr.size(); j++)
                if(temp==listaPr[j].getId()) tempEmp=listaPr[j]; 

            cout<<" Wyplata: ";//<<vec[i].first<<"\n ID: "<<temp<<"\n Imie i nazwisko: "<<tempEmp.getName()<<" "<<tempEmp.getSurname()<<"\n Department ID: "<<tempEmp.getDepartmentId()<<"\n Stanowsiko: "<<tempEmp.getPosition()<<endl; 
            cout.width(4);
            cout<<vec[i].first<<" ID: ";
            cout.width(4);
            cout<<left<<temp<<" Imie i nazwisko: ";
            cout.width(15);
            cout<<tempEmp.getName()<<" ";
            cout.width(15);
            cout<<tempEmp.getSurname()<<" Department ID: ";
            cout.width(10);
            cout<<tempEmp.getDepartmentId()<<" Stanowsiko: ";
            cout.width(25);
            cout<<tempEmp.getPosition()<<endl;
        }
    }
    catch(exception &e)
	{
        cout<<e.what()<<endl;
    }
}

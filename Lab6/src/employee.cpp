#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <Lab6/employee.hpp> 

using namespace std;
//create
void Employee::utworzPrac(string id, string name, string surname, string position) {  
    this->id=id; 
    this->name=name;
    this->surname=surname;
    this->position=position;
}
//getery
string Employee::getId()  
{
    return this->id; 
}
string Employee::getName() 
{
    return this->name;
}
string Employee::getSurname() 
{
    return this->surname;
}
string Employee::getDepartmentId() 
{
    return this->departmentId;
}
string Employee::getPosition() 
{
    return this->position;
}
//setery
void Employee::setId(string id) 
{
    this->id=id;
}
void Employee::setName(string name) 
{
    this->name=name;
}
void Employee::setSurname(string surname) 
{
    this->surname=surname;
}
void Employee::setDepartmentId(string departmentId) 
{
    this->departmentId=departmentId;
}
void Employee::setPosition(string position) 
{
    this->position=position;
}

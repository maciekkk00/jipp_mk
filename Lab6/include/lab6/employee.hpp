#include <string>
#ifndef EMPLOYEE_HEADER  
#define EMPLOYEE_HEADER

using namespace std;

class Employee 
{
    private:                    
        string id;
        string name;
        string surname;
        string departmentId;  
        string position;

    public: 
        //create
        void utworzPrac(string id, string name, string surname, string position); 
		//getery
        string getId();
        string getName();
        string getSurname();
        string getDepartmentId();
        string getPosition();
		//setery
        void setId(string id);
        void setName(string name);
        void setSurname(string surname);
        void setDepartmentId(string departmentId);
        void setPosition(string position);

};

#endif 

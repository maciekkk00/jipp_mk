#include <string>
#ifndef HRMS_HEADER 
#define HRMS_HEADER

using namespace std;

class HRMS { 
    private:
    
    public: 
    void add(Employee employee, string departmentId, double salary); //metoda ktora dodaje uzytkownikow do systemu, do danego departamentu, majacego dane wynagrodzenie
    void printDepartment(string departmentId); //metoda ktora wypisuje wszystkich pracownikow danego departamentu
    void changeSalary(string employeeId, double salary); //metoda ktora zmienia wynagrodzenie danego pracownika
    void printSalaries(); //metoda ktora wypisuje wynagrodzenia wszystkich pracownikow z informacjami o tych pracownikach
    void printSalariesSorted(); //metoda ktora wypisuje wynagrodzenia wszystkich pracownikow z informacjami o pracownikach w kolejnosci malejacego wynagrodzenia (sortowanie ma byc wykonane z uzyciem algorithm)
}; 

#endif 

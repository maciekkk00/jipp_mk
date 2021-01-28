#include <exception>

using namespace std;

class BrakPra : public exception 
{
    virtual const char *what() const throw() 
    {
        return "Nie ma pracownikow";
    }
};
class BrakDep : public exception
{
    virtual const char *what() const throw()
    {
        return "Nie ma departamentow";
    }
};
class BrakIdPra : public exception
{
    virtual const char *what() const throw()
    {
        return "Nie ma id pracownika";
    }
};



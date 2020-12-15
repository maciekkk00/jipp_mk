#include <iostream>
#include <fstream>

#include <tablica/tablica.h>

using namespace std; 

int main()
{
	Matrix t1(4, 6);
	Matrix t2(4, 6);
	Matrix t3(6, 4);
	Matrix t4(4);
	
    t1.set(0, 0, 4); t1.set(0, 1, 3); t1.set(0, 2, 7); t1.set(0, 3, 2); t1.set(0, 4, 2); t1.set(0, 5, 4);
    t1.set(1, 0, 7); t1.set(1, 1, 2); t1.set(1, 2, 5); t1.set(1, 3, 8); t1.set(1, 4, 9); t1.set(1, 5, 8);
    t1.set(2, 0, 5); t1.set(2, 1, 9); t1.set(2, 2, 8); t1.set(2, 3, 1); t1.set(2, 4, 4); t1.set(2, 5, 9);
    t1.set(3, 0, 2); t1.set(3, 1, 1); t1.set(3, 2, 3); t1.set(3, 3, 9); t1.set(3, 4, 3); t1.set(3, 5, 1);
    cout<<"Pierwsza macierz: "<<endl;
	t1.print();
    
	t2.set(0, 0, 5); t2.set(0, 1, 7); t2.set(0, 2, 2); t2.set(0, 3, 4); t2.set(0, 4, 3); t2.set(0, 5, 7);
    t2.set(1, 0, 2); t2.set(1, 1, 2); t2.set(1, 2, 3); t2.set(1, 3, 1); t2.set(1, 4, 6); t2.set(1, 5, 2);
    t2.set(2, 0, 6); t2.set(2, 1, 5); t2.set(2, 2, 7); t2.set(2, 3, 2); t2.set(2, 4, 1); t2.set(2, 5, 3);
    t2.set(3, 0, 1); t2.set(3, 1, 2); t2.set(3, 2, 1); t2.set(3, 3, 7); t2.set(3, 4, 7); t2.set(3, 5, 1);
    cout<<"Druga macierz: "<<endl;
	t2.print();
    
	cout << "Dodawanie:" << endl;
    t1.add(t2).print();
    
    cout << "Odejmowanie:" << endl;
    t1.subtract(t2).print();
    
	t3.set(0, 0, 3); t3.set(0, 1, 4); t3.set(0, 2, 5); t3.set(0, 3, 8);
    t3.set(1, 0, 7); t3.set(1, 1, 1); t3.set(1, 2, 1); t3.set(1, 3, 2);
    t3.set(2, 0, 1); t3.set(2, 1, 7); t3.set(2, 2, 2); t3.set(2, 3, 3);
    t3.set(3, 0, 7); t3.set(3, 1, 3); t3.set(3, 2, 7); t3.set(3, 3, 7);
    t3.set(4, 0, 2); t3.set(4, 1, 6); t3.set(4, 2, 2); t3.set(4, 3, 2);
    t3.set(5, 0, 7); t3.set(5, 1, 1); t3.set(5, 2, 8); t3.set(5, 3, 1);
    cout << "Trzecia macierz:" << endl;
	t3.print();

    cout << "Mnozenie macierzy pierwszej przez trzecia" << endl;
    t1.multiply(t3).print();
    
	cout << "Liczba kolumn pierwszej macierzy:" << endl;
    cout << t1.cols() << endl;
    
	cout << "Liczba wierszy pierwszej macierzy:" << endl;
    cout << t1.rows() << endl;
    
	t4.set(0, 0, 7); t4.set(0, 1, 7); t4.set(0, 2, 2); t4.set(0, 3, 7);
    t4.set(1, 0, 2); t4.set(1, 1, 2); t4.set(1, 2, 7); t4.set(1, 3, 1);
    t4.set(2, 0, 7); t4.set(2, 1, 5); t4.set(2, 2, 3); t4.set(2, 3, 3);
    t4.set(3, 0, 8); t4.set(3, 1, 1); t4.set(3, 2, 2); t4.set(3, 3, 7);
    
	cout << "Macierz kwadratowa:" << endl;
	t4.print();
    
	cout << "Zapisywanie czwartej macierzy do pliku i tworzenie macierzy piatej:" << endl;
    t4.store("t4.txt", ".");
    Matrix t5("t4.txt", ".");
    t5.print();
    return 0;
}
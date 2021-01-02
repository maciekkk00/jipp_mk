#include <iostream>
#include <fstream>
#include <exception>

using namespace std; 

class Matrix
{
	private:
		int w, sz;
		double *macierz;
    public:
      	Matrix(int n, int m);
  		Matrix(int n);
  		Matrix(std::string filename, string path);
		void set(int n, int m, double val);
		double get(int n, int m);
		Matrix add(Matrix& m2);
		Matrix subtract(Matrix& m2);
		double mnozeniewsz(int n, int m, Matrix m2);
		Matrix multiply(Matrix& m2);
		int cols();
		int rows();
		void print(); 
		void store(string filename, string path);
};

class wiersze : public exception
{
    virtual const char *what() const throw()
    {
        return "Zla ilosc wierszy w macierzach";
    }
};
class kolumny : public exception
{
    virtual const char *what() const throw()
    {
        return "Zla ilosc kolumn w macierzach";
    }
};
class kolumnywiersze : public exception
{
    virtual const char *what() const throw()
    {
        return "Liczba kolumn pierwszej macierzy nie zgadza sie z liczba wierszy drugiej macierzy";
    }
};
class wierszekolumny : public exception
{
    virtual const char *what() const throw()
    {
        return "Liczba wierszy pierwszej macierzy nie zgadza sie z liczba kolumn drugiej macierzy";
    }
};
class plik : public exception
{
    virtual const char *what() const throw()
    {
        return "Blad pliku";
    }
};


Matrix::Matrix(int n, int m)
{
    macierz = new double[n*m*sizeof(double)];
    w=n; 
	sz=m;
    for (int i=0; i<m*n; i++)
    {
        macierz[i]=0;
    }
}
Matrix::Matrix(int n)
{
    macierz=new double[n*n*sizeof(double)];
    w=n; 
	sz=n;
    for (int i=0; i<n*n; i++)
    {
        macierz[i]=0;
    }
}

Matrix::Matrix(string filename, string path)
{
    ifstream tablica;

    path=path+"/"+filename;
    tablica.open(path.c_str());
    tablica>>w>>sz;
    macierz = new double[w*sz*sizeof(double)];
    for (int i=0; i<w; i++)
    {
        for (int j=0; j<sz; j++)
        {
		
            tablica>>macierz[i*sz+j];
        }
    }
}
void Matrix::set(int n, int m, double val)
{
    macierz[n*sz+m] = val;
}
double Matrix::get(int n, int m)
{
    return macierz[n*sz+m];
}
Matrix Matrix::add(Matrix& m2)
{
	wiersze wier;
    kolumny kol;
    try {
        if(w != m2.w) throw wier;
        if(sz != m2.sz) throw kol;
    Matrix wynik(w, sz);
    for (int i=0; i<w; i++)
    {
        for (int j=0; j<sz; j++)
        {
            wynik.set(i, j, get(i, j)+m2.get(i, j));
        }
    }
    return wynik;
	}
    catch(exception &e){
        cout<<e.what()<<endl;
    }
}
Matrix Matrix::subtract(Matrix& m2)
{
	wiersze wier;
    kolumny kol;
    try {
        if(w != m2.w) throw wier;
        if(sz != m2.sz) throw kol;
    Matrix wynik(w, sz);
    for (int i=0; i<w; i++)
    {
        for (int j=0; j<sz; j++)
        {
            wynik.set(i, j, get(i, j)-m2.get(i, j));
        }
    }
    return wynik;
	}
	catch(exception &e){
        cout<<e.what()<<endl;
    }
}
double Matrix::mnozeniewsz(int n, int m, Matrix m2)
{
    double wynik=0;
    for (int i=0; i<sz; i++)
    {
        wynik+=get(n, i)*m2.get(i, m);
    }
    return wynik;
}
Matrix Matrix::multiply(Matrix& m2)
{
	kolumnywiersze kw;
    wierszekolumny wk;
    
    try {
        if(w != m2.sz) throw wk;           
        if(sz != m2.w) throw kw;
        Matrix wynik(m2.sz, w);
    for (int i=0; i<wynik.w; i++)
    {
        for (int j=0; j<wynik.sz; j++)
        {
            wynik.set(i, j, mnozeniewsz(i, j, m2));
        }
    }
    return wynik;
	}
	 catch(exception &e){
        cout<<e.what()<<endl;
    }
}
int Matrix::cols()
{
    return sz;
}
int Matrix::rows()
{
    return w;
}
void Matrix::print()
{
    for (int i=0; i<w; i++)
    {
        for (int j=0; j<sz; j++)
        {
            cout<<get(i, j)<< " ";
        }
        cout<<endl;
    }
}
void Matrix::store(string filename, string path)
{
    
    plik p;
    try {
    	ofstream tablica;
        path=path+"/"+filename;
    tablica.open(path.c_str());
    if(!tablica) throw p;
    tablica<<rows()<<" "<<cols()<<endl;
    for (int i=0; i<w; i++)
    {
        for (int j=0; j<sz; j++)
        {
            tablica<<get(i, j)<< " ";
        }
        tablica<<endl;
    }
    tablica.close();
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
}

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

#include <iostream>
#include <fstream>

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
Matrix Matrix::subtract(Matrix& m2)
{
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
    ofstream tablica;

    path=path+"/"+filename;
    tablica.open(path.c_str());
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


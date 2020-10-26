#include <iostream>

using namespace std;

int main()
{
    float m;
    double w,BMI;
    cout<<"Program do liczenia BMI"<<endl;
    cout<<"Wprowadz swoja mase w kg"<<endl;
    cin>>m;
    cout<<"Wprowadz swoj wzrost w m"<<endl;
    cin>>w;
    BMI=m/(w*w);
    if (BMI<16)
    cout<<"Twoje BMI = "<<BMI<<" jest to wyglodzenie"<<endl;
    if (BMI>=16 && BMI<=16.99)
    cout<<"Twoje BMI = "<<BMI<<" jest to wychudzenie"<<endl;
    if (BMI>=17 && BMI<=18.49)
    cout<<"Twoje BMI = "<<BMI<<" jest to niedowaga"<<endl;
    if (BMI>=18.5 && BMI<=24.99)
    cout<<"Twoje BMI = "<<BMI<<" jest to wartosc prawidlowa"<<endl;
    if (BMI>=25 && BMI<=29.99)
    cout<<"Twoje BMI = "<<BMI<<" jest to nadwaga"<<endl;
    if (BMI>=30 && BMI<=34.99)
    cout<<"Twoje BMI = "<<BMI<<" jest to I stopien otylosci"<<endl;
    if (BMI>=35 && BMI<=39.99)
    cout<<"Twoje BMI = "<<BMI<<" jest to II stopien otylosci"<<endl;
    if (BMI>=40)
    cout<<"Twoje BMI = "<<BMI<<" jest to otylosc skrajna"<<endl;
    
    return 0;
}
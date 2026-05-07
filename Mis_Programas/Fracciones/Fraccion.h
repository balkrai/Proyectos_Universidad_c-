#include <iostream>
#include <string>
using namespace std;


class Fraccion
{
    
    private:
        double numerador,denominador;
        
    public:
        Fraccion();
       friend ostream & operator<<(ostream &,Fraccion&);
       friend istream & operator >>(istream &, Fraccion&);
       Fraccion(double , double);
       
};

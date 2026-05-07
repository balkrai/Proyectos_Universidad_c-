#include <iostream>
#include <string>
#include "Fraccion.h"
using namespace std;


Fraccion::Fraccion()
{
    numerador = 0.0;
    denominador = 0.0;
}
Fraccion::Fraccion(double num , double den)
{
    numerador = num;
    denominador = den;
}

ostream & operator<< (ostream & o , Fraccion & f)
{
   
    o  <<f.numerador << "/"  <<f.denominador << endl ;
   
    
    
    return o;
}

istream & operator >>(istream &i,  Fraccion & f)
{
    i >> f.numerador;
    i.ignore();
    i >> f.denominador;
    
    return i;
}


#include <iostream>
#include "Error.h"
using namespace std;
/**
* Se muestra si la pila esta llena, se muestra "Pila llena".
*/
ErrorLlena::ErrorLlena(): std::out_of_range( "Pila llena" ) {}
/**
* Se muestra si la pila esta vacia, se muestra "Pila vacia".
*/
ErrorVacia::ErrorVacia(): std::out_of_range( "Pila vacia" ) {}


#include <iostream>
#include <string>
#include "Tabla.h"
#include <windows.h>
#include <iomanip>
#include <fstream>
using namespace std;

string ObtenerResultado(string);

int main()
{

   
	 
	 	Tabla t;
	 	string dato;
	 	
	 	t.LeerFichero("archivo.txt");
	 	t.Mostrar();
	 	
	 	t.SacarDato(dato,7,3);
	 	
	 	cout << dato;

}



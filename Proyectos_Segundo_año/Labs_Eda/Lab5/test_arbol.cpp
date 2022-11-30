#include <iostream>
#include "abb.h"
#include "alumno.h"
#include <map>
using namespace std;

const int MAX = 1000;

void EjerciciosABB();
void EjerciciosMAP();


int main()
{
	
//	EjerciciosABB();
    EjerciciosMAP();

	
	
	return 0;
}

void EjerciciosABB()
{
	ABB <unsigned,Alumno> arbol;
	
	string dni;
	Alumno alumno;
	
	for(int i = 0; i < MAX; i++)
	{
	    Alumno al(5);
	    dni = al.getDNI();
	    dni.pop_back();
	    arbol.insertar(stoi(dni), al);
		
	}
	
	arbol.Grafico(cout);
	cout << "Altura: " << arbol.Altura() << endl;
	cout << "Profundidad: " << arbol.Tam() << endl;
	
	if( arbol.buscar(41,alumno))
	{
		cout << "encontrado 41" << endl;
	}
    if( arbol.buscar(40,alumno))
	{
		cout << "encontrado 40" << endl;
	}
    if(!arbol.buscar(13000,alumno))
	{
		cout << "No encontrado 13000" << endl;
	}
	cout << "La suma es: "<<arbol.mediaDNI() << endl;
	cout << "Elementos entre rango: "<<arbol.cuentaDNI42() << endl;
	if(arbol.EstaEquilibrado())
	{
		cout << "Si, esta equilibrado" << endl;
	}
	else
	{
		cout << "No, no lo esta" << endl;
	}
}


void EjerciciosMAP()
{
	map <unsigned,Alumno> arbol;
	int cont = 0;
	
	string dni;
	
	  Alumno al(5);
	for(int i = 0; i < MAX; i++)
	{
	    Alumno al(5);
	    dni = al.getDNI();
	    dni.pop_back();
	    arbol.insert( { stoi(dni), al });		
	}
	arbol.insert({42000600,al});
    
    	
   	for (auto itr = arbol.lower_bound(42000000); itr != arbol.upper_bound(42999999); ++itr) 
   	{
        	cont++;
		cout << "Posicion " << cont << ": "<<itr->first << "\t" << itr->second << "\n";
	}


}


/**
 * Practica 6.
 *
 * Practicas Estructuras de Datos y Algoritmos
 * Curso 2022 - 2023
 *
 * (c) Departament d'Informatica.
 *     Universitat de Valencia
 * 
 * @author Borja Somovilla y Carlos Piquer
 *
 * @file test_tabla.cpp
 */
#include <iostream>
#include "tabla.h"
#include "alumno.h"
using namespace std;

const int MAX = 1000;

int main ()
{
    string dni;
    Tabla<int,Alumno> tabla(MAX*2);
    Alumno p1(1);
    Alumno p2(1);

    for(int i = 0; i < MAX; i++)
    {
        Alumno a(i);
        dni = a.getDNI();
        dni.pop_back();
        tabla.insertar(stoi(dni),a);
    }
    tabla.insertar(22,p1);
    tabla.insertar(23,p2);
    tabla.mostrar(cout);
 
    if(tabla.buscar(22,p1))
    {
        cout << "Se ha encontrado el alumno con el dni " << p1 << endl;
    }
  
    if(tabla.buscar(23,p2))
    {
        cout << "Se ha encontrado el alumno con el dni " << p1 << endl;
    }

    if(!tabla.buscar(24,p1))
    {
        cout << "NO EXISTE" << endl;
    }
    cout << "El factor de carga es: " << tabla.factorCarga() << endl;
    cout << "Num listas con 0 elementos: " << tabla.num_posN(0) << endl;
    cout << "Num listas con 1 elementos " << tabla.num_posN(1) << endl;
    return 0; 

}

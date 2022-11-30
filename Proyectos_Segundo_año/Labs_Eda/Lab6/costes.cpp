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
 * @file costes.cpp
 */
#include <iostream>
#include "alumno.h"
#include <vector>
#include <fstream>
#include <map>
#include <ctime>
#include "abb.h"
#include "tabla.h"
using namespace std;
void calculoCoste(unsigned ini, unsigned fin, int inc, float (*f)(unsigned),ostream &);
float FuncionAuxTabla(unsigned);
float FuncionAuxABB(unsigned);
float FuncionAuxMap(unsigned);

void RellenaTabla(int talla,Tabla<int,Alumno> & t ,vector<int>&v);
void RellenaABB(int talla,ABB<int,Alumno> & t ,vector<int>&v);
void RellenaMap(int talla,map<int,Alumno> & t ,vector<int>&v);

const int MAX = 1000;


int main()
{
    ofstream f_tabla;
    ofstream f_ABB;
    ofstream f_Map;


	
    f_tabla.open("medioTabla.txt");
    f_ABB.open("medioABB.txt");
    f_Map.open("medioMap.txt");
    calculoCoste(500,5000,500,FuncionAuxTabla,f_tabla);
    calculoCoste(500,5000,500,FuncionAuxABB,f_ABB);
    calculoCoste(500,5000,500,FuncionAuxMap,f_Map);
	
    return 0;
}
/**
*
* param [in] ini inicio del vector
*
* param [in] fin fin del vector
*
* param [in] inc de cuanto en cuanto se incrementa la funcion
* 
* @return Devuelve el coste de la funcion en segundos
*/
void calculoCoste(unsigned ini, unsigned fin, int inc, float (*f)(unsigned), ostream & file)
{
    struct timespec ini_time, fin_time;
    double segundos;
    double suma = 0;
          
    for(unsigned i = ini; i <= fin; i = i + inc)
    {	 
        clock_gettime(CLOCK_REALTIME, &ini_time); 
        f(i);
        clock_gettime(CLOCK_REALTIME, &fin_time);

        segundos = (fin_time.tv_sec - ini_time.tv_sec) + (fin_time.tv_nsec * 1.0e-9 - ini_time.tv_nsec * 1.0e-9);

        suma+=segundos/i;


        file << i << " " << segundos/i << endl;

	}

    cout << "Coste en segundos: " << suma << endl;

}
/**
*
* param [in] talla introducimos por parametro la talla de la tabla
* 
* @return Función auxiliar para crear una tabla
*/
float FuncionAuxTabla(unsigned talla)
{
    Tabla <int,Alumno>tabla(talla*2);
    vector<int> v_dni;
    RellenaTabla(talla,tabla,v_dni);
    Alumno a1;
	
    for(int i = 0; i < MAX; i++)
    {
        for(unsigned j = 0; j < v_dni.size(); j++)
            tabla.buscar(v_dni[i],a1);
    }
		
    return 0.0;
}
/**
*
* param [in] talla pasamos por parametro la talla de la tabla
*
* param [in] & t pasamos por referencia el numero de alumnos
*
* param [in] & v vector por referencia de los alumnos
* 
* @return Funcion para rellenar una tabla
*/
void RellenaTabla(int talla,Tabla<int,Alumno> & t ,vector<int>&v)
{
    string dni;
    for(int i = 0; i < talla; i++)
    {
        Alumno a(i);
        dni = a.getDNI();
        dni.pop_back();
        v.push_back(stoi(dni));
        t.insertar(stoi(dni),a);
    }
}
/**
*
* param [in] talla introducimos por parametro la talla de la tabla
* 
* @return Función auxiliar para crear un arbol
*/
float FuncionAuxABB(unsigned talla)
{
    ABB <int,Alumno>arbol;
    vector<int> v_dni;
    RellenaABB(talla,arbol,v_dni);
    Alumno a1;
	
    for(int i = 0; i < MAX; i++)
    {
        for(unsigned j = 0; j < v_dni.size(); j++)
            arbol.buscar(v_dni[i],a1);
    }
	
    return 0.0;
}
/**
*
* param [in] talla introducimos por parametro la talla de la tabla
* 
* @return Función auxiliar para crear un mapa
*/
float FuncionAuxMap(unsigned talla)
{
    map <int,Alumno>arbol;
    vector<int> v_dni;
    RellenaMap(talla,arbol,v_dni);
    Alumno a1;
	
    for(int i = 0; i < MAX; i++)
	{
        for(unsigned j = 0; j < v_dni.size(); j++)
            arbol.find(v_dni[i]);
	}
	
    return 0.0;
}
/**
*
* param [in] talla pasamos por parametro la talla de la tabla
*
* param [in] & t pasamos por referencia el numero de alumnos
*
* param [in] & v vector por referencia de los alumnos
* 
* @return Funcion para rellenar el arbol
*/
void RellenaABB(int talla,ABB<int,Alumno> & t ,vector<int>&v)
{
    string dni;
    for(int i = 0 ; i < talla; i++)
    {	
        Alumno a (i);
        dni = a.getDNI();
        dni.pop_back();
        v.push_back(stoi(dni));
        t.insertar(stoi(dni),a);
    }
}
/**
*
* param [in] talla pasamos por parametro la talla de la tabla
*
* param [in] & t pasamos por referencia el numero de alumnos
*
* param [in] & v vector por referencia de los alumnos
* 
* @return Funcion para rellenar el mapa
*/
void RellenaMap(int talla,map<int,Alumno> & t ,vector<int>&v)
{
    string dni;
     
     for(int i = 0 ; i < talla; i++)
    {	
        Alumno a (i);
        dni = a.getDNI();
        dni.pop_back();
        v.push_back(stoi(dni));
        t.insert( {stoi(dni), a});		
    }

}

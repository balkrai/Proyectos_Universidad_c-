/**
 * Tabla hash
 * Curso 2021/2022
 * @file tabla.h
 */

#ifndef _TABLA_H
#define _TABLA_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "alumno.h"

using namespace std;

template<typename TipoClave, typename TipoDato>
class Tabla
{
public:

    struct ParDato
    {
        TipoClave clave;
        TipoDato dato;
    };
    Tabla(unsigned); 
    bool buscar(TipoClave, TipoDato&); 
    void insertar(TipoClave, const TipoDato&); 
    unsigned hash(TipoClave) const;
    void mostrar(ostream & sal) const;
    float factorCarga() const;
    unsigned num_posN(int) const;

private:
	
    typedef list<ParDato> ListaDatos;    
    vector<ListaDatos> t;
};
/*
* Constructor por defecto de la clase tabla.
*/
template <typename TipoClave,typename TipoDato>
Tabla<TipoClave,TipoDato>::Tabla(unsigned tam)
{
    t.resize(tam);
}
/*
* Funcion para insertar informacion en la tabla.
*/
template <typename TipoClave,typename TipoDato>
void Tabla<TipoClave,TipoDato>::insertar(TipoClave elem, const TipoDato & valor)
{
	unsigned i;
	i = hash(elem);
	t[i].push_back( ParDato{elem, valor} ); // C++11
}
/*
* Funcion para buscar datos en una tabla.
*/
template <typename TipoClave,typename TipoDato>
bool Tabla<TipoClave,TipoDato>::buscar(TipoClave elem, TipoDato & valor)
{
	unsigned i;
	i = hash(elem);
	
	for(unsigned j=0; j < t[i].size(); j++)
	{	
        
        for(ParDato d:  t[i])
	    {
   		    if(d.clave == elem)
			   {
			   	valor = d.dato;
			   	return true;	
			   	
               }  	 
    	}
	
}
	return false;
}
/*
* Funcion Hash.
*/
template <typename TipoClave,typename TipoDato>
unsigned Tabla<TipoClave,TipoDato>::hash(TipoClave elem) const
{
    return elem%t.size();
}
/*
* Funcion para mostrar los elementos de la tabla.
*/
template <typename TipoClave,typename TipoDato>
void Tabla<TipoClave,TipoDato>::mostrar(ostream & sal) const
{
	ListaDatos aux;
	for(unsigned i = 0; i < t.size();i++)
	{	sal << "=== " << i+1 << " ====\n";
         aux = t[i];
		for(ParDato d: aux)
	    {
	    	sal << d.clave << " " << d.dato << endl;
  
    	}
    		sal << "=== " << i+1 << " ====\n";
	}
}
/*
* Funcion para definir el factor carga de la tabla para luego
* ser mostrado.
*/
template <typename TipoClave,typename TipoDato>
float Tabla<TipoClave,TipoDato>::factorCarga() const
{	unsigned NumElementos = 0;
    ListaDatos aux;

		for(unsigned i=0; i < t.size(); i++)
	    {	
            NumElementos += t[i].size();
        }

	
	
	return float (NumElementos)/ float (t.size());
}
/*
* Funcion para devolver el numero de posiciones de la tabla
*/
template <typename TipoClave,typename TipoDato>
unsigned Tabla<TipoClave,TipoDato>::num_posN(int num) const
{
    int suma = 0;	
    
    for(unsigned i = 0; i < t.size();i++)
  		if(t[i].size() == unsigned (num))
  		   suma++;
  		   
    return suma;
}




#endif

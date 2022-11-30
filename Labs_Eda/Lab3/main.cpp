/**
 * Practica 3.
 *
 * Practicas Estructuras de Datos y Algoritmos
 * Curso 2022 - 2023
 *
 * (c) Departament d'Informatica.
 *     Universitat de Valencia
 * 
 * @author Borja Somovilla y Carlos Piquer
 *
 * @file main.cpp
 */
#include <iostream>
#include "Pila.h"
#include "Error.h"


int altura(Pila );
int altura2(Pila & );
int Suma(Pila&);
Pila borrar(Pila, int Elem, int n);
void Rellenar(Pila &);
int imparMenosPar(Pila &);
 
int main() {

	Pila p(11);
	
		Rellenar(p);
		
	try
	{
	   	 cout << "Num Elementos: " <<  altura(p) << endl;
	     cout << "Num Elementos; " << altura2(p) << endl;
	 	
	  	 Rellenar(p);
	   	 cout << "Suma elementos: " << Suma(p) << endl;
	   	 Rellenar(p);
	   	 
	   	 
	   	 
	   	 cout << "Suma pares Y resta Impares: " <<  imparMenosPar(p) << endl;
	   	 
	   	 Rellenar(p);
	   	 p.mostrar();
	   	 Pila pila = borrar(p,3,5);
	     pila.mostrar();
   
   } catch(out_of_range & e)
   {
       e.what();
   }
  
  
  	
	return 0;
}

/**
* param [in] p la pila
* 
* @return Devuelve la altura de la pila
*/
int altura(Pila  p)
{
    int dato = 0;



    if(p.vacia())
    {
        dato = 0;
    }
    else
    {

        p.desapilar();
        dato =  dato + altura(p);
        dato++;

    }

    return dato;

}
/**
* param [in] p la pila
* 
* @return Devuelve la altura de la pila
*/
int altura2(Pila  &p)
{
	int dato = 0;


    if(p.vacia())
    {
		dato = 0;
    }
    else
    {

        p.desapilar();
        dato =  dato + altura2(p);
        dato++;

    }

    return dato;

}

/**
* param [in] p la pila
* 
* @return Devuelve la suma de los elementos de la pila
*/
int Suma(Pila& p)
{
    int suma = 0;
    int num = 0;

    if(p.vacia())
      suma = 0;
    else
    {
        num = p.Cima();
        p.desapilar();
        suma += Suma(p);

        suma+= num;
    }

    return suma;
}
/**
* param [in] p la pila
*
* param [in] Elem el elemento que quieres eliminar
*
* param [in] n el numero de posiciones que quieres borrar
* 
* @return Devuelve la altura de la pila
*/
Pila  borrar(Pila p, int Elem, int n)
{
	
	int num;
	Pila pila (p.GetMax()+1);

	
	if(p.vacia() || n == 0)
	{
		pila = p;
	}
	  
    else
    {
        num = p.Cima();
        p.desapilar();
        
        if(num == Elem)
        {
        	Pila aux = borrar(p,Elem,n-1);
        	pila = aux;
		}
		else
		{
			Pila aux = borrar(p,Elem,n);
			pila = aux;
			pila.apilar(num);
		}
        
	}
	
	return pila;
	
}
/**
* param [in] p la pila
* 
* @return suma los elementos impares de la pila y resta los pares.
*/
int imparMenosPar(Pila& p)
{
	int suma = 0;
	int num1 = 0;
	int num2 = 0;
	if(p.vacia())
	  suma = 0;
    else
    {
  		num1 = p.Cima();
    	p.desapilar();
    	num2 = p.Cima();
    	p.desapilar();
    	
    	suma += imparMenosPar(p);
    	
    	suma += num1;
    	suma -= num2;

    	
	}
	
	return suma;
	
}
/**
* param [in] p la pila por referencia
* 
* @return Rellena la pila pasada por referencia
*/
void Rellenar(Pila & p)
{
   for(int i = 1; i <= 10 ; i++)
	    p.apilar(3);
}

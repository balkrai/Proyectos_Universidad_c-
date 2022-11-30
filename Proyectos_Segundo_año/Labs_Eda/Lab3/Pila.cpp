#include "Pila.h"
#include "Error.h"
/**
* Constructor de la clase Pila
*/
Pila::Pila(int n) 
{
	arr = new int[n];
	Max = n;
}
/**
* Borra elementos de la pila
*/
Pila::~Pila()
{
    delete [] arr;
}
/**
* Sobrecarga del operador =.
* @param p Parametro por referencia de la pila
* @return la pila copiada
*/
Pila &Pila::operator=( Pila & p) 
{
	
	 delete[] arr;                                 
     arr = new int[p.GetMax()]; 
     Max = p.GetMax();
	
	 for(int i = 0; i < p.GetMax(); i++)
		{
			apilar(p.arr[i]);
		}
	cima = p.cima;	
	
	return * this;
}
/**
* Copia la pila vieja en una nueva
*/
Pila::Pila(const Pila & p1)
{
	arr = new int [p1.Max];
    
        for(int i = 0; i < p1.Max; i++)
		{
		   arr[i] = p1.arr[i];
		
		}
	Max = p1.Max;
	accesos = p1.accesos;
	cima = p1.cima;
	
		
}
/**
* Apila los elementos de la pila.
*/
void Pila::apilar(int valor)
{

		if(cima + 1 != Max ) 
		   {
		   		cima++;
		        arr[cima] = valor;
		   }
		    
	
    
    
	
	accesos++;
}
/**
* Desapila los elementos de la pila
*/
void Pila::desapilar()
{

		if(!vacia())
		{
			arr[cima] = 0;
			cima--;
	    }
	    /*else
	       throw ErrorVacia();*/
	
}
/**
* Da el valor de la cima de la pila
* @return El valor de la cima
*/
int Pila::Cima()
{
	int valor = -1;
	
	if(!vacia())
	    valor = arr[cima];
	
	return valor;
}  
/**
* Devuelve si la palia esta vacia o no.
*/
bool Pila::vacia()
{

	
	
	return cima == -1;
}
/**
* Funcion que te devuelve los accesos
* @return los accesos de la pila
*/		 
unsigned Pila::getAccesos()
{
	
	return accesos;
}
/**
* Funcion que hace reset de los accesos.
*/
void Pila::resetAccesos()
{
	accesos = 0;
}
/**
* Devuelve el maximo de la pila.
* @return maximo de la pila
*/
int Pila::GetMax()
{
	
	return Max;
}
/**
* Muestra la pila.
*/
void Pila::mostrar()
{

	for(int i = 0; i <= cima; i++)
	{
	    cout << arr[i] << " ";
	}
	
	cout << endl;		
}

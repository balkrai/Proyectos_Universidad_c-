#include <iostream>
using namespace std;


class Pila
{
	public:
	
	 Pila& operator=(Pila &p);
	int GetMax();
	 void apilar(int); //< Apila un entero.
	 void desapilar(); //< Desapila la cima.
	 int Cima();    //<devuelve el elemento de la cima. No desapila.
	 bool vacia();  //< indica si la pila está vacía.
	 unsigned getAccesos(); //< Devuelve el número de accesos realizados a la pila.
	 void resetAccesos(); //< Pone a cero el número de accesos.
	 void mostrar(); //< Muestra la pila
	 Pila(int);
	 ~Pila();
	 Pila(const Pila & p1);

	 
	 private:
	 	int *arr;
	 	int Max;
	 	int cima = -1;
	 	unsigned accesos = 0;
	
};

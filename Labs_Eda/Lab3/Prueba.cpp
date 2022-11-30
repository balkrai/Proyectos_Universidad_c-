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
void PasarPila(Pila p);

int main() {

		
	
	Pila p (10);
	
	
	for(int i = 1; i <= 10 ; i++ )
			p.apilar(i);


			
    p.desapilar();
    PasarPila(p);

	
	return 0;
}

void PasarPila(Pila p)
{
	p.mostrar();
}




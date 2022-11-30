#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "VElement.h"
#include <unistd.h>
using namespace std;

void MezclaOrd(vector <VElement> & v, int iz, int der, vector <VElement> & aux);
void Mezcla(vector <VElement>&v,int izquierda, int PuntoCentro,
int Derecha, vector <VElement> & aux);
void Evaluar(unsigned ini, unsigned fin, int inc, float (*f)(unsigned), ostream & file);
float fMergeAuxMedio(unsigned n);
vector <VElement> GenerarVector(unsigned n);
void MuestraVector(vector<VElement>);
void calculoCoste(unsigned ini, unsigned fin, int inc, float (*f)(unsigned),
ostream & file);

int main ()
{
	ofstream fich1, fich2;	
	fich1.open("tiempo.txt");	
	fich2.open("medio.txt");
	
    

   calculoCoste(50,5000,50, fMergeAuxMedio,fich1);
   Evaluar(50,5000,50, fMergeAuxMedio,fich2);

	return 0;
}

void calculoCoste(unsigned ini, unsigned fin, int inc, float (*f)(unsigned),
ostream & file)
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
			suma+=segundos;

     		file << i << " " << segundos << endl;
		}
		cout << "Coste en segundos: " << suma;
	
}



void Evaluar(unsigned ini, unsigned fin, int inc, float (*t)(unsigned), ostream & file)
{
		float pasos = 0;

		for(unsigned i = ini; i <= fin; i = i + inc)
		{	    
			pasos = t(i);
     		file << i << " " << pasos << endl;
		}
}

int CalculaPasos(vector<VElement> v)
{
	int suma = 0;
	
	for(unsigned int i = 0; i < v.size(); i++)
	{
		suma += v.at(i).getNAssign() + v.at(i).getNComparison();	
		v.at(i).initNComparison();
		v.at(i).initNAssign();
	}
	
	return suma;
}

float fMergeAuxMedio(unsigned n)
{	
	vector <VElement> aux;
	float suma = 0;
	
	for (unsigned i = 0; i < 100; i++)
	{
	    vector <VElement> v = GenerarVector(n);
        MezclaOrd(v,0,v.size(), aux);
	    suma += CalculaPasos(v);
	}	
	return suma/(100);
}





vector <VElement> GenerarVector(unsigned n)
{
	vector <VElement> v(n);	
	srand(time(NULL));


	int num;

	for(unsigned i = 0; i < n; i++)
	{
        num = rand()% 100;
		v.push_back(num);

	}

	return v;
}

void MuestraVector(vector<VElement> v)
{
	
    for(unsigned int i = 0; i < v.size(); i++)
        cout << v.at(i).get() << " ";
    cout << endl;
}


void MezclaOrd(vector <VElement> & v, int iz, int der, vector <VElement> & aux)
{ 
    if (iz < der )
    {
        int m = (iz+der)/2;
        
        MezclaOrd(v,iz,m,aux);
        MezclaOrd(v,m+1,der, aux);
        Mezcla(v,iz,m,der, aux);		
    }
    
   
}

void Mezcla(vector <VElement>&v,int izquierda, int PuntoCentro, int Derecha, vector <VElement> & aux)
{
    int i, j;

	i = izquierda;
	j = PuntoCentro + 1;
	

	while (i <= PuntoCentro && j <= Derecha) {

		if (v[i] <= v[j]) {
			aux.push_back(v[i]);
			i++;
		}
		else {
			aux.push_back(v[j]);
			j++;
		}

	}

	while (i < PuntoCentro) {
		aux.push_back(v[i]);
		i++;
	}

	while (j <= Derecha) {
		aux.push_back(v[j]);
		j++;
	}

	for (int i = izquierda; i <= Derecha; ++i)
		v[i] = aux[i - izquierda];

  }


#include <string>
#include <string>
#include <iostream>
#include<windows.h>
#include <fstream>

using namespace std;

void MostrarDibujo(int restantes);
void MostrarB(string);
bool SeHaPerdido(int);
void GenerarPuntos(string&, string);
bool RevisarLetra(string&, string palabra,  char);
bool Comprobar(string, string);




int main()
{
 	int intentos = 8;
 	string palabra;
 	string letrasacertadas = "";
 	int opcion = -1;
 	char letra;	
 	string p_sol;
 	bool Ganado = false;

 		
 	
 	MostrarB("Bienvenida.txt");
 	cout << endl;
 	
 	cout << "Inserte la palabra ";
 	getline(cin,palabra);
 	
    GenerarPuntos(letrasacertadas, palabra);

   system("cls");   
   	
 	while(!SeHaPerdido(intentos) && Ganado == false)
 	{
		cout << "Cadena a averiguar: " << letrasacertadas << endl;
		cout << endl;
		
 		cout << "***********************************" << endl;
 		cout << "1-Letra" << endl; 		
	    cout << "2-Resolver" << endl;
   		cout << "***********************************" << endl;

       
        cout << "Dame opcion: ";
        cin >> opcion;
        
        if(opcion == 1)
        {
        	cout << "Dame la letra: " ;
        	cin >> letra;
        	
        	if(!RevisarLetra(letrasacertadas,palabra,letra))
                 intentos--; 													
		}
		else
		{
			cout << "Dame la posible solucion: ";
			cin.ignore();
			getline(cin,p_sol);
			
			if(Comprobar(p_sol, palabra))
		       Ganado = true;
		}
        

 		MostrarDibujo(intentos);
	   cout << endl;
	   cout << endl;
    }
    
	if(Ganado == true)
	   cout << "FELICIDADES, GANASTE WEH"; 	
 
	return 0;
}

void MostrarDibujo(int restantes)
{
	string nombre = to_string(restantes) +".txt";	
	ifstream f;
	string linea;
	
	
	f.open(nombre);
	
	while(getline(f,linea))
    cout << linea << endl;
}

void MostrarB(string nombre)
{
	
	ifstream f;
	string linea;
	
	
	f.open(nombre);
	
	while(getline(f,linea))
    cout << linea << endl;
}

bool SeHaPerdido(int intentos)
{
	return intentos == 0;
}

void GenerarPuntos(string & letrasacertadas, string palabra)
{
	for(unsigned int i = 0; i < palabra.length(); i++)
	    {
	    	if(palabra[i] == ' ')
	    	    letrasacertadas+=" ";
 	        else if (!iswalnum(palabra[i]))
 	        	 letrasacertadas+= palabra[i];
 	        else
 	            letrasacertadas += "*";
		}
}

bool RevisarLetra(string  &cadena, string palabra,   char letra)
{
	bool acertado = false;
	string let;
	
	for(unsigned int i = 0; i < palabra.length(); i++)
	{	
		if(tolower(palabra[i]) == tolower(letra))
        {
 	      
        	  let+= palabra[i];
      	    

             acertado = true;
             cadena.replace(i,1,let);
		}
		let = "";
	}
	
	
	return acertado;
}

bool Comprobar(string p_sol, string palabra)
{
	bool correcto = true;
	
	for(unsigned int i = 0; i < palabra.length(); i++)
	{
		if(tolower(palabra[i]) != tolower(p_sol[i]))
            correcto = false;
	}
	 return correcto;
}


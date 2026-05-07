#include <iostream>
#include "Tabla.h"
#include <fstream>
#include<iomanip>
#include <string>
using namespace std;


void Tabla::PonerEnFila(string dato)
{
	datos.push_back(dato);
	filas ++;
}

Tabla::Tabla()
{
	 filas = columnas = 0;
	
}

void Tabla::Vaciar()
{
	filas = columnas = 0;
	datos.clear();
	campos.clear();
}

void Tabla::GeneraLongitud(vector <int> & longi)
{
	unsigned int max = 0;
	string dato="";
	
	for(unsigned int i = 0; i < campos.size(); i++)			
	{
		max = 0;
		  
		for(unsigned int j = i; j < datos.size(); j+=columnas)
		{
		   
			dato = datos.at(j);
			
			if(max < dato.length())
               max = dato.length();
              
		}
		
		longi.push_back(max+5);
	}
	
}

void Tabla::Formatea(string & cadena, unsigned int num)
{
	bool es = false;
	 int pos;
	
	if(cadena == "")
 	   es = true;

	while(cadena.length() <= num)
        cadena +=" ";
        
   	if(es == true)
        cadena.replace((cadena.length()/2)-1,1,"_");
    
   	pos = cadena.find('\t');

    while(pos != int (string::npos) )
    {
    	cadena.replace(pos,2,"  ");
    	
    	pos = cadena.find('\t');
	}
}


void Tabla::InsertarCampos(string campo)
{
	campos.push_back(campo);
	columnas++;
}

void Tabla::Mostrar()
{
	
	vector <int> tams;   //Vector de tamaños de columnas
	string cabezera = "";  // Cadena de la cabezera , donde se muestran los campos
	int cont = 0;
	string cadena="";   
	
	
	if(columnas != 0)
	{
		GeneraLongitud(tams);   // Generamos la longitud maxima para cada columna
	
		for(int i = 0; i < columnas; i ++)
		{
		
		    cadena = campos.at(i); 
	        Formatea(cadena,tams.at(i));      //Añadimos el nombre del campo y lo formateamos
	
			cabezera += cadena+"|";
		}
        GeneraLineasDelim(cabezera);		// Generamos los delimitadores

		   
	    cout << cabezera ;
	   
	    GeneraLineasDelim(cabezera);
	    
	   
	    
	    for(int i = 0; i < filas/columnas; i++)     //Para mostrar dividimos filas entre columnas para tener la cantidad real de filas
	    {	
	    	for(int j = 0; j < columnas; j++)
	    	{
	            cadena = datos.at(cont);
	            Formatea(cadena,tams.at(j));     // Sacamos el dato, lo guardamos en la variable cadena, lo formateamos y lo 
	    		
	    	    cout << cadena << "|"; 
	    	    cont ++;					// Dado que los datos estan en una lista normal usamos un contador para recorrerlo
			}
			if(i != filas/columnas-1)		//Para que cuando mostremos una fila meta un salto de linea
			  cout << endl;	    
			
		}
      GeneraLineasDelim(cabezera);
      
      cout << endl;

  }
	    
}


void Tabla::GeneraLineasDelim(string lon)
{
	cout << "\n";
	
	int pos = lon.find('|');
	for(unsigned short i = 0; i < lon.length(); i++)
	{
		if(i != pos)
		   cout << "=";
        else
        {
        	cout << "|";
        	lon.replace(pos,1,".");
        	pos = lon.find('|');
		}  	
	}

    cout << "\n";	
}

int Tabla::GetColumnas()
{
	return columnas;
}

int Tabla::GetFilas()
{
	return filas/columnas;
}

bool Tabla::LeerFichero(string nom)
{
	ifstream f;   //Fichero
	Vaciar();	 // Vaciamos la Tabla por si acaso
	bool leido = false;
	string cabezera;
	vector <string> CamposLeidos;
	vector <string> DatosLeidos;
	string Dato ;

	
	f.open(nom);
	
	if(f)
	{
		leido = true;
		getline(f,cabezera,'\n');
		CamposLeidos = SacarCampos(cabezera);
	

	for(unsigned int i = 0; i < CamposLeidos.size(); i++)
	{
		InsertarCampos(CamposLeidos.at(i));
		
		
	}

    while(getline(f,Dato,'\n'))
	{                                         
	     DatosLeidos = SacarCampos(Dato);
	     
     	for(unsigned int i = 0; i < DatosLeidos.size(); i++)
    	{
	    	PonerEnFila(DatosLeidos.at(i));
	    	
    	}
    	DatosLeidos.clear();
	}	
	f.close();
	}
	
	
	return leido;
	
}


vector<string> Tabla::SacarCampos(string cadena)
{
	vector <string> CamposLeidos;
	string cad;	
    size_t pos1 = cadena.find(';');
	int pos2 = 0;
	
	while(pos1 != string::npos)
	{
		cad = cadena.substr(pos2, pos1-pos2);
		CamposLeidos.push_back(cad);
		
		cadena.erase(pos1,1);
		pos2 = pos1;
		pos1 = cadena.find(';');
	
	}
	
		cad = cadena.substr(pos2, pos1-pos2);
		CamposLeidos.push_back(cad);
		
	return CamposLeidos;
	
}



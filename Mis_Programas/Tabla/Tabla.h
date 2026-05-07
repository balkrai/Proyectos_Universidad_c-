#include <iostream>
#include <vector>
using namespace std;


class Tabla
{
	private:
		int filas,columnas;
		vector <string> datos;
		vector <string> campos;
		void GeneraLineasDelim(string);
		void GeneraLongitud(vector<int>&);
		void Formatea(string&,unsigned int);
		vector<string> SacarCampos(string);
	public:
		bool LeerFichero(string);
		int GetColumnas();
		int GetFilas();
		Tabla();
		void Vaciar();
		template<typename Dato> void SacarDato(Dato&,int,int);
		void PonerEnFila(string dato);
		void Mostrar();
		void InsertarCampos(string campo);
        

		
};

template<typename Dato>void Tabla::SacarDato(Dato& d, int fila, int columna)
{
	int fil = 0;
	int cont = 0;
	

	if(fila <= filas && columna <= columnas)
	{
	   
	     	for(cont = 0; fil != fila; cont++)
	     	{
	     		if(cont%columnas == 0)
				   fil++;
	        }
	        
	        d = datos.at((cont-1)+columna-1);

    }
}



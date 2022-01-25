#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int TAM = 5;
typedef char Matriz[TAM][TAM];
void codificar(Matriz m, string palabra);
void Mostrar(Matriz m);
bool Descifrar(string nom_fich, string clave, 
string & texto_codificado, string &texto_decodificado);
bool MismaFila (char c1, char c2, const Matriz m, char&,char&);
bool MismaColumna(char c1, char c2, const Matriz m , char &, char&);
void Diagonal(const Matriz m, char c1, char c2, char & letra1, 
char & letra2);
void SacarPosicion(const Matriz, char c1, int & fil, int & col);
string QuitarX(string cadena);




int main(void)
{
	string nom_fich;
	string texto_codificado, texto_decodificado, clave;
	
	cout << "Dame nombre del fichero: ";
	cin >> nom_fich;
	
	cout << "Dame clave: ";
	cin >> clave;
	
	if (Descifrar(nom_fich, clave, texto_codificado, texto_decodificado))
	{
	cout << "El texto a descrifrar:\n";
	cout << texto_codificado << endl << endl;
	
	cout << "Texto decodificado: \n";
	cout << texto_decodificado<< endl;

	}
	else
	cout << "Imposible abrir el fichero.\n";
	
	return 0;
}

bool Descifrar(string nom_fich, string clave, 
string & texto_codificado, string &texto_decodificado)
{
	bool descifrado;
	ifstream f;
	Matriz m;
	int i;
	char c1,c2, letra1,letra2;
	
	codificar(m,clave);
	Mostrar(m);
	
	
	f.open(nom_fich);
	
	if(f)
	{
		descifrado = true;
		i = 0;
		
		getline(f,texto_codificado);
		if(texto_codificado.length() % 2 != 0)
			texto_codificado+= 'Z';
		
		while(i < texto_codificado.length())
		{
			c1 = texto_codificado[i];
			c2 = texto_codificado[i+1];
			
		
		
			
			if(MismaFila(c1,c2,m,letra1,letra2))
			{
				texto_decodificado += letra1;
				texto_decodificado += letra2;

			}
			else if (MismaColumna(c1,c2,m,letra1,letra2))
			{
				texto_decodificado += letra1;
				texto_decodificado += letra2;
			}
			else
			{
				Diagonal(m,c1,c2,letra1,letra2);
				texto_decodificado += letra1;
				texto_decodificado += letra2;	
			}

			i += 2; 
			
		}
		
		texto_decodificado = QuitarX(texto_decodificado);
		
		
		f.close();
		
	}
	else
		descifrado = false;
	
	
	return descifrado;
}

void codificar(Matriz m, string palabra)
{
	string anyadidos;
	char c;
	int x;

	for(int i = 0; i < palabra.length(); i ++)
		if(isalpha(palabra[i]) && anyadidos.find(palabra[i]) == -1 
			&& palabra[i]!='W')	
			anyadidos += toupper(palabra[i]);
			
	
	for(c = 'A'; c <= 'Z'; c++)
		if(isalpha(c) && anyadidos.find(c) == -1 && c != 'W')	
			anyadidos += c;
		
	x = 0;	
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
		{
			m[i][j] = anyadidos[x];
			x++;
		}
		

}

void Mostrar(Matriz m)
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		cout << m[i][j] << " ";
		cout << endl;
	}
}

bool MismaFila (char c1, char c2, const Matriz m, 
char & letra1,char & letra2)
{
	bool misma;
	int fil1,col1,fil2,col2;
	
	SacarPosicion(m,c1,fil1,col1);
	SacarPosicion(m,c2,fil2,col2);
	
	if(fil1 == fil2)
	{	
		misma = true;
		if(col1-1 > 0)
			letra1 = m[fil1][col1-1]; 
		else
			letra1 = m[fil1][TAM-1];
	
		if(col2-1 > 0)
			letra2 = m[fil2][col2-1]; 
		else
			letra2 = m[fil2][TAM-1];
	}
	else
		misma = false;
	
		
	return misma;
		
}

bool MismaColumna(char c1, char c2, const Matriz m
 , char & letra1, char& letra2)
{
	bool misma;
	int fil1,col1,fil2,col2;
	
	SacarPosicion(m,c1,fil1,col1);
	SacarPosicion(m,c2,fil2,col2);
	
	if(col1 == col2)
	{	
		misma = true;
		if(fil1-1 != -1)
			letra1 = m[fil1-1][col1]; 
		else
			letra1 = m[TAM-1][col1];
	
		if(fil2-1 != -1)
			letra2 = m[fil2-1][col2]; 
		else
			letra2 = m[TAM-1][col2];
		
	}
	else
		misma = false;
	
	return misma;
}

void Diagonal(const Matriz m, char c1, char c2, char & letra1, 
char & letra2)
{
	int fil1,col1,fil2,col2;
	
	SacarPosicion(m,c1,fil1,col1);
	SacarPosicion(m,c2,fil2,col2);

	letra2 = m[fil2][col1];
	letra1 = m[fil1][col2];
	
	return;

}
void SacarPosicion(const Matriz m, char c1, int & fil, int & col)
{
	int i,j;
	for( i = 0; i < TAM; i++)
		for( j = 0; j < TAM; j++)
		{
			if(m[i][j] == c1)	
			{
				fil = i;
				col = j;	
			}
		}

}

string QuitarX(string  cadena)
{
	int i ;
	string formateado;
	
	for(i = 0; i < cadena.length(); i++)
	{
		if(cadena[i] == 'X')
			formateado+= ' ';
		else
			formateado += cadena[i];	
	}
	
	return formateado;
}


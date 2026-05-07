#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int elevar(int base, int ex)
{
    int res = 1;
    
    for(int i = ex; i > 0; i--)
    res = res * base;
    
    return res;
}
//Funciona, separa las palabras (tomando como separador un espacio)
vector<string> Separar (string frase)
{
    vector <string> lista; 
    string palabra;
    unsigned int  ant, pos;
    ant = 0;

    while(frase.find(' ')  != string::npos)
    {
        pos = frase.find(' ');
        palabra = frase.substr(ant, pos - ant);
 
        lista.push_back(palabra);     
        ant = pos;
        
        frase.erase(pos,1);
      
    }
   
    palabra = frase.substr(ant, frase.length() - ant);
    lista.push_back(palabra);
    
    return lista;
}

// Convierte una letra a mayuscula, si ya lo esta la deja tal cual
char Mayuscula(char c)
{
    char res;
    
    if(c >= 'A' && c <= 'Z')
        res = c;
    else
        res = c-' ';
        
    return res;
}

// Convierte una letra a minuscula, si ya lo esta la deja tal cual
char Minuscula(char c)
{
    char res;
    
    if(c >= 'a' && c <= 'z')
        res = c;
    else
        res = c +' ';
        
    return res;
}

int mcm(int n1, int n2)
{
   int mcm = 0;
   
   int a = max(n1,n2);
   int b = min(n1,n2);
   
   mcm = (a/mod(a,b)) *b;
   
  return mcm;
}



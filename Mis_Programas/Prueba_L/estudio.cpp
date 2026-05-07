#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>      

using namespace std;

const int TAM = 17;

void FormateaNombre(string & n);
string ObtenerResultado(string cmd);
void Convierte(string nombre);




int main(void)
{
    string res = ObtenerResultado("dir C:\\Users\\borja\\OneDrive\\Desktop\\Programas\\Prueba_L\\Json");
    stringstream ss (res);
    string linea;
    
    
    getline(ss,linea);
    getline(ss,linea);
    while(getline(ss,linea))
    {
        if(linea.find('dir')  != string::npos && linea.find('.json') != string::npos)
            cout << linea << endl;
        
        
    }
    
    
   
    
    Convierte("09CC.0000.MP01.PIRATE_COSTUME.SOLEIL_TWINS-sharedassets0.assets-7284-MonoBehaviour.json");
    
    return 0;
}

void FormateaNombre(string & n)
{
  
    n.erase(n.length()-4, n.length()-(n.length()-4));

}


void Convierte(string nombre)
{


   string cadena = "1 string LineText";
    string aux, encontrada, texto;
    ifstream f;
    int pos;
    ofstream g;
    bool found = false;
    
    
    f.open(nombre);
    
    if(f)
    {
        while(getline(f,aux) && encontrada == "") 
        {
            if(aux.find(cadena) != string::npos)
            {
                 encontrada = aux;
                 found = true;
            }
               
            
        }  
        
        if(found)
        {
            encontrada.erase(encontrada.find('"'),1);
            encontrada.erase(encontrada.find('"'),1);
            
             
            pos = encontrada.find('"');
            encontrada.erase(encontrada.find('"'),1);
            
            texto = encontrada.substr(pos,encontrada.find('"') - pos);
            
            
            FormateaNombre(nombre);  
            g.open(nombre +"doc");
      
            g << texto << endl;
        }
             
    }
}
    
   
string ObtenerResultado(string cmd)
{
	ifstream f;
	string comando, linea;
	string res = "";
	string n_archivo = "archivo1.txt";
	string borrado = "del "+ n_archivo; 
	comando = cmd + " > " + n_archivo;
	
    system(comando.c_str());
    
    
    f.open(n_archivo);
    
    if(f)
    {
  	  while(getline(f,linea))
      {
    	res +=linea;
    	res += "\n";
	  }
	  f.close();
	  
	  system(borrado.c_str());
	  
	}
   
      return res;

}




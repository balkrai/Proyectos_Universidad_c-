#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "estudio.h"
#include <sstream>

//Es posible que en algun momento no lea todos y lea solo X ultimo (x = numero entero positivo)
//Eso se debe a que por ejemplo cuando pones si se ha examinado una vacuna (1,0) no has puesto nada
//Y por ende se ralla y lee solo unos pocos



const string HOSPITALIZACION = "resumenes/hospitalizacion.txt";
const string MORTALIDAD = "resumenes/mortalidad.txt";
const string REVISIONES = "resumenes/revisiones.txt";
const string PFIZER = "resumenes/pfizer.txt";
const string TRANSMISION = "resumenes/transmision.txt";



struct PaisNum
{
    string pais = "";
    int num_estudios = 0;
};

typedef PaisNum V_paises[300];

using namespace std;
void Muestra(vector <Estudio>);
vector <Estudio>LeeDatos(string);
void GeneraMort(vector<Estudio>);
vector <PaisNum> SacaPaises(vector <Estudio>);
bool Esta(string, vector<PaisNum> , int &);
void MuestraPaises(vector<PaisNum>);
void OrdenarInsercion (V_paises & v, int n);
void GeneraRevisiones(vector<Estudio>);
void GeneraHosp(vector<Estudio> v);
void GeneraTransmision(vector<Estudio> v);

void GeneraPfizer(vector<Estudio> v);
void GeneraPorPais(vector<Estudio> v,  vector <PaisNum>);
void MuestraMenu();




int main()
{

    setlocale (LC_ALL, "spanish");
  
    MuestraMenu();

    return 0;
    
}

void MuestraMenu()
{
    vector <Estudio> e;
    vector <PaisNum> paises;
    int opcion = -1;
    
    e = LeeDatos("vacunas.csv");
    paises = SacaPaises(e); 
    
    cout << "Se han leido " << e.size() << " estudios \n";
    cout << "\n";
    
    Muestra(e);
    MuestraPaises(paises);
   
    do
    {
        cout << "===========================================================\n";
        cout << "1-Generar Fichero con estudios de la mortalidad" << endl;
        cout << "2-Generar Fichero con revisiones de estudios" << endl;
        cout << "3-Generar Fichero con estudios de la hospitalizacion" << endl;
        cout << "4-Generar Fichero con estudios sobre la vacuna de pfizer" << endl;
        cout << "5-Generar Ficheros con estudios por pais" << endl;
        cout << "6-Generar Fichero con estudios de la transmision" << endl;
        cout << "7-Recargar" << endl;
        cout <<"8-Muestra estudios por pais" << endl;
        cout << "==============================================================\n";
        cout << "Dame opcion: ";
        cin >> opcion;
        
        switch(opcion)
        {
            case 1:
                GeneraMort(e);
                break;
            case 2:
                 GeneraRevisiones(e);
                break;
            case 3:
                GeneraHosp(e);
                break;
            case 4:
                GeneraPfizer(e);
                break;
            case 5:
                paises = SacaPaises(e); 
                GeneraPorPais(e,paises);
                break;
            case 6:
                GeneraTransmision(e);
                break;
             case 7:
                  system("cls");
                e = LeeDatos("vacunas.csv");
                Muestra(e);
                break;
            case 8:
                system("cls");
                MuestraPaises(paises);
                break;
            default:
                cout << "Saliendo del programa\n";
                break; 
        }

        
        
        
        
    }while(opcion != 0);
}



void GeneraTransmision(vector<Estudio> v)
{
    ofstream o;
    o.open(TRANSMISION);
    int i = int(v.size()-1);
    int num = 1;
   
   while(i > -1)
   {
       if(v.at(i).Transmision() != -1)
       {
           o << num << "-" << v.at(i).Link() << endl;
           num++;
       }
            
      
      
      i--;
   }
}


vector <PaisNum> SacaPaises(vector <Estudio> e)
{
    vector <PaisNum> paises;
    int posicion;
    string pais;
    
    
    for(unsigned int i = 0; i < e.size(); i ++)
    {
        PaisNum p;
        if(!e.at(i).EsRevision())
        {
            if(e.at(i).Pais().find(",") != string::npos)
            {
                stringstream aux(e.at(i).Pais());
                
                while(getline(aux,pais,','))
                {
                    if(!Esta(pais, paises, posicion))
                    {
                        
                        p.pais = pais;
                        p.num_estudios = 1;
                        paises.push_back(p);      
                    }
                    else
                    {
                       
                        paises.at(posicion).num_estudios++;
                    }
                }
                
            }
            else
            {
            
          
                if(!Esta(e.at(i).Pais(), paises, posicion))
                {
                 
                    p.pais = e.at(i).Pais();
                    p.num_estudios++;
                    paises.push_back(p);
                }
                else
                {
                    paises.at(posicion).num_estudios++;
                }
            }
        }
       
    }
  
    
    return  paises;
    
}

void MuestraPaises(vector<PaisNum> paises )
{
    V_paises v;

    for(unsigned int i = 0; i < paises.size(); i ++)
    {
        v[i] = paises.at(i);          
    }
    OrdenarInsercion(v, paises.size());
    
    for(unsigned int i = 0; i < paises.size(); i ++)
    {
       
             cout << v[i].pais;
             cout << ":" << v[i].num_estudios<< endl;
        
       
         
    }
      
    
    
}

void OrdenarInsercion (V_paises & v, int n)
{
    int i, j;
    for (i = n-2; i>=0; i--)
    {
        v[n] = v[i];
        j = i+1;
        while ( v[j].num_estudios > v[n].num_estudios )
        {
            v[j-1] = v[j];
            j++;
        }
        v[j-1] = v[n];
    }
}

bool Esta(string pais, vector<PaisNum> paises, int & pos)
{
    pos = -1;
    bool esta = false;
    unsigned int i = 0;
  
    
        while(i < paises.size() && esta == false)
        {
             
            if(paises.at(i).pais == pais)
            {
                esta = true;
                pos = i;
            }
            i++;
        }
    
    
    return esta;
    
}

void GeneraMort(vector<Estudio> v)
{
    ofstream o;
    o.open(MORTALIDAD);
    int i = int(v.size()-1);
    int num = 1;
   
   while(i > -1)
   {
       if(v.at(i).Muerte() != -1)
       {
           o << num << "-" << v.at(i).Link() << endl;
           num++;
       }
            
      
      
      i--;
   }
}

void GeneraHosp(vector<Estudio> v)
{
    ofstream o;
    o.open(HOSPITALIZACION);
    int i = int(v.size()-1);
    int num = 1;
   
   while(i > -1)
   {
       if(v.at(i).Hospitalizacion() != -1)
       {
           o << num << "-" << v.at(i).Link() << endl;
           num++;
       }
            
      
      
      i--;
   }
}

void GeneraRevisiones(vector<Estudio> v)
{
    ofstream o;
    o.open(REVISIONES);
    int i = int(v.size()-1);
    int num = 1;
    
    while(i > -1)
   {
       if(v.at(i).EsRevision() )
       {
           o << num << "-" << v.at(i).Link() << endl;
           num++;
       }
            
      
      
      i--;
   }
}

void GeneraPfizer(vector<Estudio> v)
{
    ofstream o;
    o.open(PFIZER);
    int i = int(v.size()-1);
    int num = 1;
   
   while(i > -1)
   {
       if(v.at(i).esPfizer())
       {
           o << num << "-" << v.at(i).Link() << endl;
           num++;
       }
            
      
      
      i--;
   }
}

void GeneraPorPais(vector<Estudio> v,  vector <PaisNum> pa)
{
    string ruta = "ResumenesPorPaises/";
    string rutapais;
    ofstream f;
    string num_est;
    int num;
    
    for(unsigned int i = 0; i < pa.size(); i++)
    {
        num_est = to_string(pa.at(i).num_estudios);
        rutapais = ruta + pa.at(i).pais+"("+num_est+").txt";
        f.open(rutapais);
        num = 1;
        for(unsigned int j = 0; j < v.size(); j++)
        {
            if(v.at(j).Pais() == pa.at(i).pais 
            || v.at(j).Pais().find(pa.at(i).pais) != string::npos)
            {
                f << num << "-" << v.at(j).Link() << endl;
                num++;
                
                
            }
        }
        f.close();
    }
     
    
}




void Muestra(vector <Estudio> v)
{
    int i = int(v.size()-1);
   
   while(i > -1)
   {
      
      if(i < 10 )
       v.at(i).Muestra();
       i--;
   }
        
   
   
        
}

vector <Estudio>LeeDatos(string nom)
{
    vector <Estudio> e;
    string linea;
    Estudio estudio;
    ifstream i; 
    i.open(nom); 
    
    if(i)
    {
        getline(i,linea);
        while(estudio.Leer(i))
            e.push_back(estudio);
        i.close();    
       
    } 
    
    return e;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "estudio.h"


Estudio::Estudio()
{
       autorPrincipal = " ";
       titulo = " ";
       anyo = -1;
       infeccion = "-1";
       hospitalizacion = "-1";
       uci = "-1"; 
       muerte = "-1";
       pfizer = false;
       moderna = false ;
       jyj = false;
       astrazeneca = false;
}

bool Estudio::EsRevision()
{
    bool es = false;
    
    if(titulo.find("Review") != string::npos || 
    titulo.find("review") != string::npos ||
    titulo.find("meta-analysis") != string::npos || 
    titulo.find("Meta-analysis") != string::npos || 
    titulo.find("Meta-Analysis") != string::npos || 
    pais.find("estudios") != string::npos)
        es = true;
   
        
    return es;
}

string Estudio::Link()
{
    return link;
}

void Estudio::Muestra()
{
    setlocale (LC_ALL, "spanish");
    string linea = "";
    string texto = "";
    string inf,hosp,u,muer, tr;
   
    construyeAp(inf,hosp,u,muer,tr);
    
    
    
    if(reduccion == true)
        texto = "Reduccion ";
    else 
        texto = "Efectividad ";
        
    cout << autorPrincipal << " (";
    cout << anyo << ") ";
    cout  << titulo << endl;
    if(!EsRevision())
    cout  << "Pais: " << pais << endl;
    else
        cout  << "Numero de estudios: " << pais << endl;

    cout << "=============================================== \n";
    cout << texto << "Transmision: " << tr << endl;
    cout << texto << "infeccion: " << inf << endl;
    cout << texto<< "hospitalizacion: " << hosp << endl;
    cout << texto << "ingreso UCI: " << u<< endl;
    cout << texto << "contra la muerte: " << muer << endl;
    
    if(pfizer == true)
        linea += "Pfizer ";
    if(moderna == true)
        linea += "Moderna ";
    if(jyj == true)
        linea += "J&J ";
    if(astrazeneca == true)
        linea += "Astrazeneca ";
     if(Sinopharm == true)
        linea += "Sinopharm ";
        
    if(pfizer == false && moderna == false && jyj == false && Sinopharm == false)
        linea = "Otra vacuna";
    cout << "Vacunas Examinadas: " << linea << endl;
    cout << "Link: " << link << endl;
    cout << endl;
    
   
    
}

void Estudio::construyeAp(string& i,string& h,string& u,string&m, string & t)
{
    i = "No examinado";
    h = "No examinado";
    u = "No examinado";
    m = "No examinado";
    t ="No examinado";
    
    if(infeccion != "")
        i = infeccion +"%";    
    
    if(hospitalizacion != "")
        h = hospitalizacion +"%";
     
    if(uci != "")
        u = uci +"%";
     
    if(muerte != "")
        m = muerte +"%";
    if(transmision != "")
        t = transmision +"%";
   
}

bool Estudio::esReduccion()
{
    return reduccion;
}

bool Estudio::Leer(ifstream & v)
{
    bool leido = false;
   setlocale (LC_ALL, "spanish");
    
  
  if(getline(v,autorPrincipal,';'))
  {
        leido = true;
        
        getline(v,anyo,';');
        getline(v,titulo,';');
        getline(v,pais,';');   
        getline(v,transmision,';');      
        getline(v,infeccion,';');
        getline(v,hospitalizacion,';');
        getline(v,uci,';');
        getline(v,muerte,';');
       
        v >> pfizer;
        v.ignore();
        v >> moderna;
        v.ignore();
        v >> jyj;
        v.ignore();
        v >> astrazeneca;
        v.ignore();
        v >>  Sinopharm;
        v.ignore();
        v >> reduccion;
        v.ignore();
        getline(v,link,'\n');

        if(pais == "Espanya")
            pais = "España";
        
        Formatea(titulo);
    }
    else
        leido = false;
   
    return leido;
    
}

bool Estudio::esSinopharm()
{
    return Sinopharm;
}
void Estudio::Formatea(string & v)
{
    int esp = 9;
    int espacios = 0;
    string aux = "";
    
    if(v.length() > 60)
        esp = 12;
    
    for(unsigned int i = 0; i < v.length(); i ++)
    {
        aux += v[i];
        
        if(v.at(i) == ' ')
            espacios++;
        
        if(espacios == esp && v.at(i) == ' ')
            aux += "\n";
    }
    v = aux;
    
}



int Estudio::Anyo()
{
    return stoi(anyo);
}

string Estudio::Autor()
{
    return autorPrincipal;
}

bool Estudio::esAstrazeneca()
{
    return astrazeneca;
}

bool Estudio::esJyJ()
{
    return jyj;
}


bool Estudio::esModerna()
{
    return moderna;
}

bool Estudio::esPfizer()
{
    return pfizer;
}

int Estudio::Hospitalizacion()
{
     int valor = -1;
    
    if(hospitalizacion != "")
        valor = stoi(hospitalizacion);
    
    return valor;
}

int Estudio::Infeccion()
{
     int valor = -1;
    
    if(infeccion != "")
        valor = stoi(infeccion);
        
    return valor;
}

int Estudio::Transmision()
{
    int valor = -1;
    
    if(transmision != "")
        valor = stoi(transmision);
        
    return valor;
}



int Estudio::Muerte()
{
    int valor = -1;
    
    if(muerte != "")
        valor = stoi(muerte);
    
    return valor;
}

int Estudio::Uci()
{
     int valor = -1;
     
      if(uci != "")
        valor = stoi(uci);
        
    return valor;
}

string Estudio::Titulo()
{
    return titulo;
}

string Estudio::Pais()
{
    return pais;
}





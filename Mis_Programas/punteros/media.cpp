

#include <iostream>
#include "Tiempo.h"
#include <fstream>
#include "Media.h"

using namespace std;


Media::Media()
{
    titulo = info = ruta = "<Sin asignar>";  
}


void Media::EstableceMedia(string t,string i,string r,Tiempo ti)
{
    titulo = t;
    info = i;
    ruta = r;
    tiempo = ti; 
}
void Media::EstableceTitulo(string t)
{
    titulo = t; 
}
void Media::EstableceInfo(string i)
{
    info = i;
}
void Media::EstableceRuta(string r)
{
    ruta = r;
}
void Media::EstableceDuracion(Tiempo t)
{
    tiempo = t;
}

string Media::DevuelveTitulo()
{
    return titulo;
}
string Media::DevuelveInfo()
{
    return info;
}
string Media::DevuelveRuta()
{
    return ruta;
}
Tiempo Media::DevuelveDuracion()
{
    return tiempo;
}


ostream& operator<<(ostream& o,Media & m)
{
    o << "Titulo: " << m.titulo << endl;
    o << "Duracion: " << m.tiempo << endl;
    o << "Informacion: " << m.info << endl;
    o << "Ruta en el sistema: " << m.ruta << endl;
    
    return o;
}


 istream& operator>>(istream& i,Media & m)
{
    getline(i,m.titulo);
    getline(i,m.info);
    getline(i,m.ruta);
    i >> m.tiempo;
  
    return i;
}

bool Media::LeerMedia(ifstream & i)
{
    bool leido = false;
    
     if(getline(i,titulo))
     {
        leido = true;   
        getline(i,info);
        getline(i,ruta);
        i >> tiempo;
        i.ignore();
    }
    
    return leido;
   
}



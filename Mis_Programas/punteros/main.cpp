#include <iostream>
#include <fstream>

#include "Tiempo.h"
#include "Media.h"
#include "Lista.h"

using namespace std;

void NuevoMedia(Lista &l);
void NuevoMediaPos(Lista &l);
void Eliminar(Lista&);



int main()
{
    int opcion = -1; 
    Lista l;
    
    setlocale (LC_ALL, "spanish");
    
    cout << endl;
    l.MostrarActivo();
    
    do
    {
        cout << "1-Añadir Media al final" << endl;
        cout << "2-Añadir Media en posicion" << endl;
        cout << "3-Eliminar" << endl;
        cout << "4-Mover al final" << endl;
        cout << "5-Avanzar" << endl;
        cout << "6-Retroceder" << endl;
        cout << "7-Guardar" << endl;
        cout << "8-Recuperar Lista" << endl;
        
        cout << "Dame opcion: ";
        cin >> opcion;
    
        switch(opcion)
        {
            case 1:
                NuevoMedia(l);
                l.MostrarActivo();
                break;
            case 2:
                NuevoMediaPos(l);
                l.MostrarActivo();
                break;
            case 3:
                Eliminar(l);
                l.MostrarActivo();
                break;      
            case 4:
                l.Mover();
                l.MostrarActivo();
                break;
            case 5:
                l.Avanzar();
                l.MostrarActivo();
                break;
            case 6:
                l.Retroceder();
                l.MostrarActivo();
                break;
            case 7:
                l.Guardar();
                l.MostrarActivo();
                break;
            case 8:
                l.Leer();
                l.MostrarActivo();
                break;     
        }
    
    }while(opcion != 0);
  
    return 0;
}

void NuevoMedia(Lista & l)
{
    string titulo,info,ruta;
    Tiempo tiempo;
    Media m;
    
    cin.ignore();
    cout << "Dame titulo: ";
    getline(cin,titulo);
    
    cout << "Dame info:";
    getline(cin,info);
    
    cout << "Dame ruta: ";
    getline(cin,ruta);
    
    cout << "Dame duracion ";
    cin >> tiempo;
    
    m.EstableceMedia(titulo,info,ruta,tiempo);
  
    l.Insertar(m,0);
    l.MoverAlFinal();
}

void NuevoMediaPos(Lista & l)
{
    string titulo,info,ruta;
    Tiempo tiempo;
    Media m;
    int pos;
    cin.ignore();
    
    cout << "\nDame titulo ";
    getline(cin,titulo);
    
    cout << "Dame info ";
    getline(cin,info);
    
    cout << "Dame ruta ";
    getline(cin,ruta);
    
    cout << "Dame duracion ";
    cin >> tiempo;
    
    cout << "Posicion ";
    cin >> pos;
    
    m.EstableceMedia(titulo,info,ruta,tiempo);
  
    l.InsertarPos(m,pos);
    l.MoverAlFinal(); 
}

void Eliminar(Lista & l)
{
    int pos;
    
    cout << "Dame posicion a eliminar ";
    cin >> pos;
    
    l.EliminarPos(pos);
    cout << endl;
}


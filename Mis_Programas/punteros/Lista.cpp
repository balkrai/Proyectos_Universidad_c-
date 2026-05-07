/******* Pr6_Carta.cpp *************************************************/ /**
 *
 * @file Pr6_Carta.cp
 *
 * Implementación de los métodos de la clase Carta
 *
 * @version 1.0
 * @author Jesús Albert
 * @author Miguel A. Gamón
 * @date 19/04/2022
 *  
 ***************************************************************************/

#include "Lista.h"
#include <string>
#include <fstream>
#include<istream>
#include<sstream>
#include <iomanip>

/**************************************************************************/ /**
 *
 *  Construye una carta y asigna valores iniciales a los atributos:
 *  1 de Oros ('O').
 *
 */ /*************************************************************************/
using namespace std;

Lista::Lista()
{
    cabeza = new NodoDoble;
    cabeza->sig = cabeza;
    cabeza->ant = cabeza;
    pto = cabeza;
    activo = cuantos = total = 0;
}

void Lista::Vaciar (void)
{
    pto = cabeza->sig;
    while (Eliminar());
}

bool Lista::Eliminar()
{
    bool ok;
    
    PunteroDoble p_aux ;
    if (pto == cabeza)
        ok = false;
    else
    {
        p_aux = cabeza->sig;
        ok = true;
        p_aux = pto->sig;
        pto->sig->ant = pto->ant;
        pto->ant->sig = pto->sig;
        delete pto;
        pto = p_aux;      
    }
    return ok;
}

void Lista::Guardar()
{
    string n; 
    ofstream f;
    
    cout << "Nombre del archivo :";
    cin >> n;
    
    f.open(n);
    
    pto = cabeza -> sig;
    
    while(pto != cabeza)
    {
        f << pto->info;
        pto = pto-> sig;
    }
}
int Lista::sacaPos()
{
    int contador = 1;
    
    PunteroDoble aux;
    
    aux = cabeza ->sig;
    
    if(aux!=pto)
    {
    
        while(aux != pto) 
        {
            aux = aux -> sig;
            contador++;
        }
    }
    
    return contador;  
}

void Lista::Mover()
{
    PunteroDoble aux;
    PunteroDoble poner;
       
    if(pto != cabeza -> ant)
    {
        aux = pto;
        poner = aux -> sig;
        pto = cabeza->ant;
     
        aux -> ant -> sig  = poner;
        poner -> ant = aux-> ant;
        
        aux -> sig = cabeza;
        pto -> sig = aux;
        aux -> ant = pto; 
        cabeza -> ant = aux;
        if(pto != poner && poner != cabeza)
            pto = poner;
        else
        {
            Avanzar();
        }
    }
}


void Lista::MostrarActivo()
{
    int cont = 0;
   
    Media m;
    cout << "=======================================\n";
    if(pto != cabeza)
    {
        m = pto->info;
        cont = sacaPos();
        cout << "[" << cont<<"/" <<Size()<<"]";
        cout << pto-> info;
       
        cout << "=======================================\n"; 
    }
    MostrarPantallaConFormateo();    
}

void Lista::MostrarPantallaConFormateo()
{
    PunteroDoble aux;
    Media m;
    string nombreMod;
    aux = cabeza->sig;
    int max = DevuelvetamayoGrande();
    int con = 1;
    
    while(aux != cabeza)
    {
        m = aux->info;
        nombreMod = m.DevuelveTitulo();
        Modifica(nombreMod,max);
        
        if(aux == pto)
        {
            if(con < 10)
                cout << setw(5)<<">> " <<con <<". " << nombreMod 
                << setw(11) <<  m.DevuelveDuracion()<< endl;
                
            else
                cout << setw(4)<<">> " <<con <<". " << nombreMod << setw(11) 
            <<  m.DevuelveDuracion()<< endl;
        }
        else 
        {
            cout << setw(6)<<con <<". " << nombreMod << setw(11) ; 
            cout <<m.DevuelveDuracion() << setw(6) << endl; 
        }
        aux = aux->sig;
        con ++;
    }
    cout << "\t\t\t   TIEMPO TOTAL   " << CalculaTiempo()<< endl;
    cout << "=========================\n";
}

bool Lista::EliminarPos(int pos)
{
    bool ok;
    int pos1 = 1;
    PunteroDoble p_aux ;
  
    if(pos <= Size())  
    { 
        ok = true;
        p_aux = cabeza->sig;
        
        while(pos1 < pos)
        {
            p_aux = p_aux->sig; 
            pos1++;
        }
        
        if(p_aux == pto)
            Retroceder();
       
        p_aux -> ant-> sig = p_aux -> sig;
        p_aux -> sig-> ant = p_aux-> ant;
        delete p_aux;          
    }
    

    return ok;
}


bool Lista::ListaVacia ()
{
    return (cabeza == cabeza->sig);
}

void Lista::Copiar (const Lista & ori)
{
    PunteroDoble p_aux, q_aux;
    //Se recorre la lista original
    p_aux = ori.cabeza->sig;
    while (p_aux != ori.cabeza)
    {
        //Se reserva espacio y actualiza la informacion
        q_aux = new NodoDoble;
        q_aux->info = p_aux->info;
        //Se van añadiendo los elementos delante de la cabeza
        //es decir, al final de la lista
        q_aux->sig = cabeza;
        q_aux->ant = cabeza->ant;
        cabeza->ant->sig = q_aux;
        cabeza->ant = q_aux;
        //Si estamos copiando el pto de interés lo fijamos en
        //la copia
        if (p_aux == ori.pto)
        pto = q_aux;
        p_aux = p_aux->sig;
    }
}


Lista::~Lista (void)
{
    Vaciar();
}

Lista::Lista (const Lista & ori)
{
    cabeza = new NodoDoble;
    cabeza->sig = cabeza;
    cabeza->ant = cabeza;
    Copiar (ori) ;
}

/**************************************************************************/ /**
 *
 *  Construye una carta y asigna valores a los atributos a partir de los
 *  parámetros.
 *  @param  [in]	p	palo de la carta
 *  @param  [in]	n	número de la carta
 *
 */ /*************************************************************************/
void Lista::Insertar( Media v, int e )
{
   
    PunteroDoble aux = new NodoDoble;
    aux->info = v;
    if(e == 0)
    {
        aux->sig = pto->sig;
        aux->ant = pto;
        pto->sig = aux;
        aux->sig->ant = aux;
    }
    else if(e == 1)
    {
        aux->sig = pto;
        aux->ant = pto->ant;
        aux->ant->sig = aux;
        pto->ant = aux;
    }
    else
    {
        cout << "NO.\n";
    }
}

void Lista::Leer()
{
    string n; 
    ifstream f;
    cout << "Nombre del archivo: ";
    cin >> n;
    f.open(n);
    Media m;
    
    if(f)
    {
        while(m.LeerMedia(f))    
        { 
            cout << m << endl;
            Insertar(m,0);
            pto = pto -> sig;
        }
        f.close();
        MueveAlInicio();
    }
    
}

bool Lista::MueveAlInicio()
{
    bool movido = false;
    
    if(!ListaVacia())
    {
         pto = cabeza->sig;
         movido = true;
    }
     
    return movido;  
}



void Lista::InsertarPos(Media m,int pos)
{
    int i = 1;
    if(pos > Size())
    {
        MoverAlFinal();
        Insertar(m, 0);
    }
    else
    {
        pto = cabeza -> sig;
        
        while(i < pos)
        {
            pto = pto -> sig;
            i++;
        }
        Insertar(m,1);  
    }  
}

int Lista::Size()
{
    int tam = 0;
    PunteroDoble aux;
    aux  = cabeza->sig;
    
    while(aux != cabeza)
    {
        aux = aux->sig;
        tam++;
    }
    
    return tam;
}


/**********************************************************************/ /**
 *
 *  Asigna el palo de la carta. Los valores correctos para asignar el
 *  palo deben ser ('O', 'C', 'E', 'B').
 *
 *  @param  [in]	p	palo de la carta
 *
 */ /**********************************************************************/
bool Lista::MoverAlFinal() //Preguntar
{
    bool res = false;
    if(pto->sig != cabeza)
    {
        while(pto->sig != cabeza)
            pto = pto->sig;
        res = true;
    }
    return res;
}



/**********************************************************************/ /**
 *
 *  Asigna el número de la carta. Los valores correctas para asignar el
 *  número deben del 1 al 12.
 *
 *  @param  [in]	n	número de la carta
 *
 */ /**********************************************************************/
bool Lista::Retroceder()
{
    bool res = true;
           
        if(pto -> ant != cabeza)
            pto = pto->ant;
        else
        {
            pto = cabeza -> ant;
        }
        
    return res;
}

bool Lista::Avanzar()
{
    bool res = true;
        
        if(pto -> sig != cabeza)
            pto = pto->sig;
        else
        {
            pto = cabeza->sig;
        }

    return res;
}

void Lista::Modifica(string & s, unsigned int d)
{
    while(s.length() < d)
        s+= " ";
}


int Lista::DevuelvetamayoGrande()
{
   unsigned int max = 0;
   PunteroDoble aux = cabeza->sig;
   Media m;
  
    while(aux != cabeza)
    {
        m = aux->info;
         if(m.DevuelveTitulo().length() > max)
         {
            max = m.DevuelveTitulo().length();
         }
         aux = aux-> sig;      
    }
     
    return max;
}

Tiempo Lista::CalculaTiempo()
{
    Tiempo p;
    PunteroDoble aux;
    aux = cabeza->sig;
    Media m;
    
    while(aux != cabeza)
    {
        m = aux->info;
        p += m.DevuelveDuracion();
        aux = aux-> sig;
    }
    
    return p;
}


/**********************************************************************/ /**
 *
 *  Devuelve el palo de la carta.
 *
 *  @return  Palo de la carta
 *
 */ /**********************************************************************/

/**********************************************************************/ /**
 *
 *  Devuelve el número de la carta.
 *
 *  @return  Número de la carta
 *
 */ /**********************************************************************/
bool Lista::GuardarEnFichero(string n)
{
    bool res = true;
    ofstream f;
    f.open(n);
    if(f)
    {
        pto = cabeza->sig;
        while(pto != cabeza)
        {
            cout << pto->info;
            pto = pto->sig;
        }
        res = true;
    }
    return res;
}

/**********************************************************************/ /**
 *
 * Sobrecarga del operador << para sacar la información de la carta
 * por un stream (fichero, consola, ...).
 *
 * @param [in, out] out	stream por el que vamos a sacar la información.
 * @param [in] 		c  	objeto Carta que queremos sacar por el stream.
 *
 * @return  El stream modificado tras su utilización
 *
 */ /**********************************************************************/
bool Lista::RecuperarDeFichero(string n)
{
    bool res = false;
    Media m;
    ifstream f;
    f.open(n);
    if(f)
    {
        MoverAlFinal();
        while(f>>m)
        {
            Insertar(m,0);
        }
        res = true;
    }
    else
    {
        cout << "Error con el fichero.\n";
    }
    return res;
}

/**
 * Arbol Binario de Búsqueda (ABB)
 * Curso 2022/2023
 * @file abb.h
 */

#ifndef _ABB_H
#define _ABB_H

#include<iostream>
#include<iomanip>

using namespace std;

template<typename TipoClave, typename TipoDato>
class ABB
{
public:
    ABB(); 
    ~ABB();
    bool buscar(const TipoClave &, TipoDato&) ; 
    bool insertar(const TipoClave &, const TipoDato&); 
    bool vacio() const;
    void Grafico(ostream & sal) const;
    unsigned Altura();
    unsigned Tam();
    double mediaDNI() ;
    unsigned cuentaDNI42();
   	bool EstaEquilibrado();

    
private:
    class NodoBin
    {
    public:
        TipoClave clave; 
        TipoDato  dato;
        NodoBin * izq;
        NodoBin * der;

        NodoBin(): izq(NULL), der(NULL) {};
        NodoBin(TipoClave c, TipoDato d)
        : clave(c), dato(d), izq(NULL), der(NULL) {};
        ~NodoBin();
    };

    typedef NodoBin * PtrNodoBin;

    void GraficoAux(ostream& out, int indent, PtrNodoBin subarbol) const;
    bool buscarAux(PtrNodoBin, const TipoClave &, TipoDato&) const; 
    bool insertarAux(PtrNodoBin &, const TipoClave &, const TipoDato&); 
    void inordenAux(ostream & sal, PtrNodoBin) const;
    unsigned TamAux(PtrNodoBin);
    unsigned AlturaAux(PtrNodoBin raiz);
    double mediaDNIAux(PtrNodoBin);
    unsigned cuentaDNI42Aux(PtrNodoBin);
	bool EstaEquilibradoAux(PtrNodoBin);




    PtrNodoBin miRaiz;

  
};
/**
*
* Destructor de la clase nodo
*
*/
template <typename TipoClave,typename TipoDato>
ABB<TipoClave,TipoDato>::NodoBin::~NodoBin()
{
    delete izq;
    delete der;
	
}
/**
*
* Devuelve si el arbol esta equilibrado o no
*
*/

template <typename TipoClave,typename TipoDato>
bool ABB<TipoClave,TipoDato>::EstaEquilibradoAux(PtrNodoBin raiz)
{
    bool equil = false;
    int izquierda;
    int derecha;
 
    if (raiz == NULL)
        equil = true;
    else
    {
        izquierda = TamAux(raiz->izq);
        derecha = TamAux(raiz->der);
 
    if (abs(izquierda - derecha) <= 1 && EstaEquilibradoAux(raiz->izq) && EstaEquilibradoAux(raiz->der))
        equil = true;
    }
 
    return equil;
}
/**
*
* Devuelve si el arbol esta equilibrado o no
*
*/
template <typename TipoClave,typename TipoDato>
bool ABB<TipoClave,TipoDato>::EstaEquilibrado()
{
    return EstaEquilibradoAux(miRaiz);
}


/**
*
* Devuelve la cantidad de dni
*
*/
template <typename TipoClave,typename TipoDato>
unsigned ABB<TipoClave,TipoDato>::cuentaDNI42Aux(PtrNodoBin raiz)
{
    unsigned  suma = 0;
    unsigned v2;
    unsigned v1 = v2 = 0;
	
    if (raiz == NULL)
        return 0;
    else
    {
        if(42000000 < raiz->clave)
            v1 = cuentaDNI42Aux(raiz->izq);
	 	else if(raiz->clave < 42000000)
            v2 = cuentaDNI42Aux(raiz->der);
            suma += v1 + v2;
        if(raiz->clave >= 42000000 && raiz->clave <= 42999999)
	        suma++;
	}
 
    return suma;
	
}
/**
*
* Devuelve la cantidad de dni
*
*/
template <typename TipoClave,typename TipoDato>
unsigned  ABB<TipoClave,TipoDato>::cuentaDNI42() 
{

    return 	cuentaDNI42Aux(miRaiz);
}

/**
*
* Devuelve la cantidad media de dni
*
*/

template <typename TipoClave,typename TipoDato>
double ABB<TipoClave,TipoDato>::mediaDNIAux(PtrNodoBin raiz)
{
    double  suma = 0;
    if (raiz == NULL)
        return 0;
    else
    {
        suma += raiz -> clave +mediaDNIAux(raiz->izq)+ mediaDNIAux(raiz->der);
	}
 
    return suma;
	
}
/**
*
* Devuelve la cantidad media de dni
*
*/
template <typename TipoClave,typename TipoDato>
double  ABB<TipoClave,TipoDato>::mediaDNI() 
{
    return 	mediaDNIAux(miRaiz)/ Tam();
}

/**
*
* Devuelve la altura del arbol
*
*/
template <typename TipoClave,typename TipoDato>
unsigned ABB<TipoClave,TipoDato>::AlturaAux(PtrNodoBin raiz)
{
    int izquierda = 0;
    int derecha = 0;
    if (raiz == NULL)
        return 0;
    else
    {
        izquierda = TamAux(raiz->izq);
        derecha = TamAux(raiz->der);	
	}
 
    return 1+ max(izquierda,derecha);
	
}
/**
*
* Devuelve la altura del arbol
*
*/
template <typename TipoClave,typename TipoDato>
unsigned  ABB<TipoClave,TipoDato>::Altura() 
{
    return 	AlturaAux(miRaiz);
}

/**
*
* Devuelve el tamaño del arbol
*
*/

template <typename TipoClave,typename TipoDato>
unsigned ABB<TipoClave,TipoDato>::TamAux(PtrNodoBin raiz)
{
    int suma = 0;
    if (raiz == NULL)
        return 0;
    else
    {
        suma = 1+ TamAux(raiz->izq)+ TamAux(raiz->der);	
	}
 
    return suma;
	
}
/**
*
* Devuelve el tamaño del arbol
*
*/
template <typename TipoClave,typename TipoDato>
unsigned  ABB<TipoClave,TipoDato>::Tam()
{
    return 	TamAux(miRaiz);;
}

/**
*
* Devuelve si esta vacio
*
*/
template <typename TipoClave,typename TipoDato>
bool ABB<TipoClave,TipoDato>::vacio() const
{
    return miRaiz == nullptr;
}
/**
*
* Constructor de la clase
*
*/
template <typename TipoClave,typename TipoDato>
ABB<TipoClave,TipoDato>::ABB()
{
    miRaiz = nullptr;
}
/**
*
* Destructor de la clase
*
*/
template <typename TipoClave,typename TipoDato>
ABB<TipoClave,TipoDato>::~ABB()
{
    delete miRaiz;
    miRaiz = nullptr;
}
/**
*
* Busca en el arbol
*
*/
template <typename TipoClave,typename TipoDato>
bool ABB<TipoClave,TipoDato>::buscar(const TipoClave & elem, TipoDato & valor)
{ 
    return buscarAux(miRaiz, elem, valor); 
}
/**
*
* Busca en el arbol
*
*/
template <typename TipoClave,typename TipoDato>
bool ABB<TipoClave,TipoDato>::buscarAux(PtrNodoBin raiz, const TipoClave & elem, TipoDato& valor) const 
{
    if(raiz == nullptr)
            return false;
	if(elem < raiz->clave)
            return(buscarAux(raiz->izq, elem, valor) );
    else if(raiz->clave < elem)
        return(buscarAux(raiz->der, elem, valor) );
    else // encontrado
	{
        valor = raiz->dato;
        return true;
	}
}
/**
*
* Inserta en el arbol
*
*/
template <typename TipoClave,typename TipoDato>
bool ABB<TipoClave,TipoDato>::insertar(const TipoClave & elem, const TipoDato & valor)
{ 
    return insertarAux(miRaiz, elem, valor); 
}

template <typename TipoClave,typename TipoDato>
bool ABB<TipoClave,TipoDato>::insertarAux(ABB::PtrNodoBin & raiz, const TipoClave & elem, const TipoDato & valor)
{ 
    bool ok = true;
	
    if(raiz == nullptr)
        raiz = new ABB::NodoBin(elem, valor);
    else if(elem < raiz->clave)
        return(insertarAux(raiz->izq, elem, valor));
    else if(raiz->clave < elem)
        return(insertarAux(raiz->der, elem, valor) );
    else // ya existe !
        ok = false;
		 
    return ok;
};
/**
*
* Se muestran los dnis por pantalla en forma de arbol
*
*/
template <typename TipoClave,typename TipoDato>
inline void ABB<TipoClave,TipoDato>::Grafico(ostream& out) const
{
    GraficoAux(out,0,miRaiz);
}
/**
*
* funcion auxiliar que muestra los dnis por pantalla en forma de arbol
*
*/
template <typename TipoClave,typename TipoDato>
void ABB< TipoClave, TipoDato>::GraficoAux(ostream& out, int indent, PtrNodoBin subarbol) const
{
    if(subarbol != 0)
    {
        GraficoAux(out,indent+8,subarbol->der);
        out << setw(indent) << " " << subarbol-> dato.getDNI() << endl;
        GraficoAux(out,indent+8,subarbol->izq);

	}
}


#endif

/******* Pr6_Carta.h ***************************************************/ /**
 *
 * @file Pr6_Carta.h
 *
 * Fichero de cabecera de la clase Carta
 *
 * @version 1.0
 * @author Jesús Albert
 * @author Miguel A. Gamón
 * @date 19/04/2022
 *  
 ***************************************************************************/
  
#include <iostream>
#include <string>
#include <fstream>
#include "Media.h"


using namespace std;

#ifndef _LOTE_H_
#define _LOTE_H_

/**
 * @brief Clase para el manejo de cartas
 *
 * Interfaz de la clase Carta, que representa cartas de la baraja española
 * identificadas por un palo (oros, copas, espadas y bastos) y por un número
 * en el rango 1 a 12.
 */

class Lista
{
    public:
        // Constructor por defecto
    void Insertar(Media, int);
    void InsertarPos(Media,int);
    bool MoverAlFinal();
    bool Retroceder();
    void MostrarPantallaConFormateo();
    bool GuardarEnFichero(string);
    bool RecuperarDeFichero(string);
    Lista();
    Lista (const Lista &);
    ~Lista (void);
    bool ListaVacia ();
    void Copiar (const Lista & ori);
    void Vaciar (void);
    bool Eliminar ();
    bool EliminarPos(int pos);
    bool Avanzar();
    void Mover();
    void MostrarActivo();
    void Guardar();
    void Leer();
    bool MueveAlInicio();


    private:
        int sacaPos();
        Tiempo CalculaTiempo();
        int DevuelvetamayoGrande();
        void Modifica(string & s, unsigned int d);
        int Size();


        struct NodoDoble;
        typedef NodoDoble* PunteroDoble;
        struct NodoDoble
        {
            Media info;
            PunteroDoble ant;
            PunteroDoble sig;
        };

        PunteroDoble cabeza, pto;
        int activo,cuantos,total;
};

#endif

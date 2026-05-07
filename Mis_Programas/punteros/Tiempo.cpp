/****** Tiempo.cpp ************************************************/ /**
 *
 * @file Tiempo.cpp
 *
 * @brief Implementacion de los metodos de la clase Tiempo
 *
 * @version 1.1
 * @author Vicente Cerverón
 * @author Emiliano Torres
 * @date 10-05-2022
 */ /**************************************************************************/

#include "Tiempo.h"
#include <iomanip>

/**** Tiempo::Tiempo () ***************************************************/ /**
 *
 * Constructor por defecto de la clase Tiempo.
 *
 */ /********************************************************************************/
Tiempo::Tiempo()
{
    horas = 0;
    minutos = 0;
    segundos = 0;
}

/**** Tiempo::Tiempo (int hh, int mm, float ss) ***************************************************/ /**
 *
 * Constructor con un argumentos de la clase Tiempo.
 * Asigna los valores de horas, minutos y segundos
 * 
 * @param[in]  hh     horas
 * @param[in]  mm     minutos
 * @param[in]  ss     segundos
 *
 */ /********************************************************************************/
Tiempo::Tiempo(int hh, int mm, int ss)
{   
    if(hh >= 0 && mm >= 0 && mm < 60 && ss >= 0 && ss < 60)
    {
        horas = hh;
        minutos = mm;
        segundos = ss;
    }      
}

/**** bool Tiempo::SetTiempo (int hh, int mm, float ss) ***************************************************/ /**
 *
 * Asigna los valores de horas, minutos y segundos y devuelve si se ha podido asignar
 * 
 * @param[in]  hh     horas
 * @param[in]  mm     minutos
 * @param[in]  ss     segundos
 *
 */ /********************************************************************************/
bool Tiempo::SetTiempo(int hh, int mm, int ss)
{   
    bool correcto;
    
    if(hh >= 0 && mm >= 0 && mm < 60 && ss >= 0 && ss < 60)
    {
        horas = hh;
        minutos = mm;
        segundos = ss;
        correcto = true;
    }      
    else
        correcto = false;
        
    return correcto;    
}

/****  int Tiempo::GetHoras () ******************************************/ /**
 *
 * Devuelve las horas
 *
 * @return     horas
 */ /**************************************************************************/
int Tiempo::GetHoras()
{
    return horas;
}
              
/****  int Tiempo::GetMinutos () ******************************************/ /**
 *
 * Devuelve los minutos
 *
 * @return     minutos
 */ /**************************************************************************/
int Tiempo::GetMinutos()
{
    return minutos;
}
              
/****  float Tiempo::GetSegundos () ******************************************/ /**
 *
 * Devuelve los segundos
 *
 * @return     segundos
 */ /**************************************************************************/
int Tiempo::GetSegundos()
{
    return segundos;
}
              

/*** istream & operator>> (istream & in, Tiempo & t) ************************/ /**
 *
 *  Sobrecarga del operador '>>' para asignar la información de un Tiempo 
 *  desde un stream (fichero, teclado, ...).
 *
 *  @param [in, out]  in  stream del que vamos a obtener la informacion.
 *  @param [out]     t        objeto Tiempo que queremos rellenar con la
 *                            informacion obtenida del stream.
 *
 *  @return  El stream modificado tras su utilizacion
 *
 */ /**********************************************************************/
istream& operator>> (istream & in, Tiempo & t)
{
    in >> t.horas;
    in.ignore();
    in >> t.minutos;
    in.ignore();
    in >> t.segundos;
    
    return in;
}

/*** ostream & operator<< (ostream &, Tiempo& ) ******************/ /**
 *
 *  Sobrecarga del operador '<<' para sacar la información de un Tiempo 
 *  por un stream (fichero, consola, ...).
 *
 *  @param [in, out]  out    stream por el que vamos a sacar la informacion.
 *  @param [in]      t      objeto Tiempo que queremos sacar por el stream.
 *
 *  @return  El stream modificado tras su utilizacion
 *
 */ /**********************************************************************/
ostream& operator<< (ostream& out, Tiempo t)
{
    out << setw(3) << t.horas << ":" << setw(2) << setfill('0') << t.minutos << setfill(' ') << ":" ;
    if(t.segundos < 10)
        out << "0";
    out << t.segundos;

    return out;
}



/*** void operator+=(Tiempo& t, Tiempo t2) ******************/ /**
 *
 *  Sobrecarga del operador '+=' para sumar a un tiempo otro tiempo dado
 *
 *  @param [in, out]  t       Tiempo que queremos modificar.
 *  @param [in]      t2      Tiempo que queremos añadir.
 *
 */ /**********************************************************************/
void operator+=(Tiempo &t, Tiempo t2)
{
    t.horas += t2.horas;
    t.minutos += t2.minutos;
    t.segundos += t2.segundos;
    
    if(t.segundos >= 60)
    {
        t.minutos ++;
        t.segundos -= 60;
    }
    if(t.minutos >= 60)
    {
        t.horas ++;
        t.minutos -= 60;
    }

    return;
}

/*** void operator-=(Tiempo& t, Tiempo t2) ******************/ /**
 *
 *  Sobrecarga del operador '-=' para restar a un tiempo otro tiempo dado
 *
 *  @param [in, out]  t       Tiempo que queremos modificar.
 *  @param [in]      t2      Tiempo que queremos restar.
 *
 */ /**********************************************************************/
void operator-=(Tiempo &t, Tiempo t2)
{
    t.horas -= t2.horas;
    t.minutos -= t2.minutos;
    t.segundos -= t2.segundos;
    
    if(t.segundos < 0)
    {
        t.minutos --;
        t.segundos += 60;
    }
    if(t.minutos < 0)
    {
        t.horas --;
        t.minutos += 60;
    }

    return;
}

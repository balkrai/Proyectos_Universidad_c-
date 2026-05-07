

#ifndef _MEDIA_H_
#define _MEDIA_H_

#include <iostream>
#include "Tiempo.h"
#include <fstream>

using namespace std;




class Media
{
    public:
        Media();
        void EstableceMedia(string,string,string,Tiempo);
        void EstableceTitulo(string);
        void EstableceInfo(string);
        void EstableceRuta(string);
        void EstableceDuracion(Tiempo);
        
        string DevuelveTitulo();
        string DevuelveInfo();
        string DevuelveRuta();
        Tiempo DevuelveDuracion();
        bool LeerMedia(ifstream&i);
        
        friend ostream& operator<<(ostream&,Media&);
        friend istream& operator>>(istream&,Media&);
        
    private:
        string titulo,info,ruta;
        Tiempo tiempo;
};

#endif

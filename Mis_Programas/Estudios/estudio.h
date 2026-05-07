#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class Estudio
{
    
    private:
        string autorPrincipal,titulo, anyo,pais;
      
        string infeccion,hospitalizacion,uci,muerte, transmision;
        bool pfizer,moderna,jyj,astrazeneca, Sinopharm;
        void Formatea(string &);
        bool reduccion;
        string link;
        void construyeAp(string&,string&,string&,string&, string &);
    public:
        Estudio();
        string Autor();
        string Titulo();
        string Pais();
        int Anyo();
        int Infeccion();
        int Hospitalizacion();
        int Uci();
        int Muerte();
        bool esPfizer();
        bool esModerna();
        bool esJyJ();
        bool esAstrazeneca();
        bool esSinopharm();
        bool esReduccion();
        bool Leer(ifstream &);
        void Muestra();
        int Transmision();
        string Link();
        bool EsRevision();

};





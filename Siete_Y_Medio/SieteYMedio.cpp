/**
 
 @file SieteYMedio.cpp
 
 @brief Este programa simula el juego del siete y medio.

 
 @date 06/01/2022
 @author Jose Miguel Vallet Comes, Borja Somovilla del Saz

*/

#include <iostream>
#include <fstream>
#include <SFML/Audio.h>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

const int MAX_C = 40;  ///<Maximo numero de cartas en la baraja
const int MAX_P = 4;   ///<Maximo numero de palos
const int MAX_J = 10;  ///<Maximo numero de jugadores
const string FICHERO = "dinero.juego"; ///<Nombre del fichero de los jugadores
const string BIENVENIDA = "bienvenida.txt"; ///<Nombre del mensaje de bienvenida
string MUSICAFONDO = "Audio/MusicaFondo.wav";
string MUSICAOPCION = "Audio/Eleccion.wav";
string MUSICABARAJAR = "Audio/BarajarSonido.wav";
string MUSICACARTA = "Audio/DarCarta.wav";
string MUSICADINERO = "Audio/Dinero.wav";


sfMusic* music; ///<Musica de fondo
sfMusic* EfectoSonido; ///<Efecto de sonido de las opciones
sfMusic* BarajarSonido; ///<Efecto de sonido de barajar
sfMusic* DarCarta; ///<Efecto de sonido de dar una carta
sfMusic* Dinero; ///<Efecto de sonido de apostar




/** 
 * Vector para guardar los numeros repetidos cuando se baraja la baraja
 */
typedef int Repetidos[MAX_C];

/** 
 * Vector para guardas los distintos tipos de palos
 */
typedef string Palos[MAX_P];
const Palos PALOS = {"Oros","Bastos","Espadas","Copas"}; ///<Palos

/** 
 * Datos del jugador
 */
struct Jugador
{   
    string nombre; ///<nombre del jugador
    float dinero = 100; ///<dinero del jugador (por defecto a 100)
};

/** 
 * Vector de los jugadores
 */
typedef Jugador V_jugadores[MAX_J];

/** 
 * Agrupacion de jugadores
 */
struct Jugadores
{
    int n_jugadores = 0; ///<numero de jugadores
    V_jugadores v; ///<Vector de jugadores
};

/** 
 * Datos de cada carta
 */
struct Carta
{
    int numero; ///< Numero de la carta
    string palo; ///< Palo de cada carta
};
/** 
 *  Vector de cartas
 */
typedef Carta V_Cart[MAX_C];

/** 
 *  Agrupacion de cartas
 */
struct Baraja
{
    V_Cart Cartas; ///<Vector de cartas
    int n_cartas = 0; ///< Numero de cartas
};

//Declaracion de prototipos

Jugador IdentificarJugador(string nom, Jugadores & jugs);
void MostrarDinero(Jugador j);
void Salida(string n_f, Jugadores jugs);
Baraja GenerarBaraja(const Palos palos);
Baraja Barajar (Baraja);
bool Aparecido(Repetidos repe, int numero, int & tam);
void Jugar(Baraja baraja, Jugador & j_actual, Jugadores & jugs, string & nom);
void RepartirCarta(Baraja baraja, Baraja & Cartas_Repartidas, float & puntos, 
int & indice_baraja);
float Apostar(Jugador j_actual);
void UltimaPartida(string n);
void MostrarCartas (Baraja);
void ConstruirPalo (string, string & ,string &, string &, string &, string &);
string ConstruirSuperior (Carta);
Baraja LeerCartas(int, ifstream &);
void EscribirDatos(Baraja, ofstream &, float);
void MostrarBienvenida();


int main()
{ 
    int c;
    ifstream f_dinero;
    Jugador j, j_actual;
    Jugadores jugs;
    string nom_j = "Default";
    Baraja baraja;
    
    music = sfMusic_createFromFile(MUSICAFONDO.c_str());
    EfectoSonido = sfMusic_createFromFile(MUSICAOPCION.c_str());
    
	if (!music || !EfectoSonido)
		cout << "No se ha podido abrir el archivo de audio" << endl;
	else
    {
		sfMusic_setLoop(music,true);
		sfMusic_play(music);
	    MostrarBienvenida();
	    baraja = GenerarBaraja(PALOS);
	    f_dinero.open(FICHERO);
	    
	    if (!f_dinero)
	        cout << "Error en la apertura del fichero de informacion.\n"; 
	    else
		{
		    while(f_dinero >> j.nombre)
		    {
		        f_dinero >> j.dinero;
		        jugs.v[jugs.n_jugadores] = j;
		        jugs.n_jugadores++;
		    }
		    f_dinero.close();
		         
			do
		    {
		        EfectoSonido = sfMusic_createFromFile(MUSICAOPCION.c_str());
		        cout << "1-Identificar jugador.\n";
		        cout << "2-Mostrar dinero del jugador.\n";
		        cout << "3-Comenzar una partida.\n";
		        cout << "4-Mostrar ultima partida jugada.\n";
		        cout << "0-Salir.\n";
		        cin >> c;
		            
				switch(c)
		        {            
		            case 1:
			            sfMusic_play(EfectoSonido);
			            cout << "Introduzca el nombre del jugador: ";
			            cin >> nom_j;
			            j_actual = IdentificarJugador(nom_j, jugs);
			            cout << "Exito en el registro.\n";
			            break;
			            
		            case 2:
		                sfMusic_play(EfectoSonido);
		                if(nom_j == "Default")
		                {
		                    cout << "No se ha identificado ningun usuario.\n";
		                }
		                else
		                {
		                    MostrarDinero(j_actual);
		                }
		                break;
		                    
		            case 3:
		                sfMusic_play(EfectoSonido);
		                if(nom_j == "Default")
		                {
		                    cout << "No se ha identificado ningun usuario.\n";
		                }
		                else
		                {
		                	Jugar(baraja, j_actual, jugs, nom_j);
		                }
		                break;
		                
		            case 4:
		                sfMusic_play(EfectoSonido);
		                UltimaPartida("Ultima.partida");
		                break;
		                
		            case 0:
		                sfMusic_play(EfectoSonido);
		                cout << "Saliendo del juego.";
		                Salida(FICHERO, jugs);  
		                break; 
						                                     
		            default:
		                sfMusic_play(EfectoSonido);
		                cout << "Opcion no valida.\n";
		                break;
		        }
		            
		    }
		    while(c != 0);
		}
    sfMusic_destroy(music);
    sfMusic_destroy(EfectoSonido);
	} 
    return 0;
}

/** MostrarBienvenida**//**
 * 
 * Muestra un mensaje amigable de bienvenida
 *
 *//****************/
void MostrarBienvenida()
{
    ifstream f;
    f.open(BIENVENIDA);
    string linea;
    
    if (f)
    {
        while(getline(f,linea))
            cout << linea << endl;
        cout << endl;
    }
    else
        cout << "No se ha podido abrir el fichero" << endl;
    
    return;
}

/** IdentificarJugador**//**
 * 
 * Identifica un jugador
 *
 *@param [in] nom nombre del jugador
 *@param [out] jugs agrupacion de jugadores que manejara el programa
 *
 *//****************/
Jugador IdentificarJugador(string nom, Jugadores & jugs)
{
    Jugador res;
    bool existe = false;
    int i;
    for (i = 0; i < jugs.n_jugadores; i++)
    {
        if(jugs.v[i].nombre == nom)
        {
            existe = true;
            res.nombre = jugs.v[i].nombre;
            res.dinero = jugs.v[i].dinero;
        }
    }
    if(!existe)
    {
        res.nombre = nom;
        jugs.v[jugs.n_jugadores] = res;
        jugs.n_jugadores++;
    }
    
    return res;  
}

/** MostrarDinero**//**
 * 
 * Muestra el dinero del jugador que se le pasa
 *
 *@param [in] j jugador del que vamos a mostrar el dinero
 *
 *//****************/
void MostrarDinero(Jugador j)
{
    cout << "El jugador " << j.nombre << " tiene " << j.dinero <<
    " euros para apostar.\n";
    
    return;
}

/** GenerarBaraja**//**
 * 
 * Genera una baraja con 40 cartas (10 por palo)
 *
 *@param [in] Palos Vector de palos
 *
 *//****************/
Baraja GenerarBaraja(const Palos Palos)
{
    Baraja nueva;
    Carta nuevaCarta;

    int i, j;

    for(i = 0; i < MAX_P; i++)
    {
        for(j = 1; j <= 10; j++ )
        {
            nuevaCarta.palo = Palos[i];
            if(j <= 7)
                nuevaCarta.numero = j;
                
            else if(j > 7)
                nuevaCarta.numero = j + 2;
                
            nueva.Cartas[nueva.n_cartas] = nuevaCarta;
            nueva.n_cartas++;
        }
    }
    
    return nueva;
}

/** Salida**//**
 * 
 * Escribe los jugadores identificados en el fichero
 *
 *@param [in] n_f nombre del fichero
 *@param [in] jugs Agrupacion de jugadores
 *
 *//****************/
void Salida(string n_f, Jugadores jugs)
{
    ofstream f;
    int i;
    
    f.open(n_f);
    
    for(i = 0; i < jugs.n_jugadores; i++)
    {
        f << jugs.v[i].nombre << endl;
        f << jugs.v[i].dinero << endl;
    }
    f.close();
    
    return;
}

/** Jugar**//**
 * 
 * Funcion que hace el juego comience
 *
 *@param [in] baraja baraja con la que se jugara
 *@param [out] j_actual jugador que esta jugando
 *@param [out] jugs Agrupacion de jugadores
 *@param [out] nom Nombre del jugador activo
 *
 *//****************/
void Jugar(Baraja baraja, Jugador & j_actual, Jugadores & jugs, string & nom)
{
    char c;
    float dinero_apostado, puntos_ordenador = 0, puntos = 0;
    Baraja cartas_usuario, cartas_ordenador, baraja_barajada;
    int indice_baraja = 0;
    int posicion_borrar, posicion_dinero;
    bool ganar = false, encontrado = false, encontrado2 = false;
    ofstream f;
    
    BarajarSonido = sfMusic_createFromFile(MUSICABARAJAR.c_str());
    sfMusic_play(BarajarSonido);
    
    f.open("Ultima.partida", ios::binary);
    baraja_barajada = Barajar(baraja);
    
    RepartirCarta(baraja_barajada, cartas_ordenador, puntos_ordenador, 
    indice_baraja);
    cout << "Carta para el usuario.\n";
    RepartirCarta(baraja_barajada, cartas_usuario, puntos, indice_baraja);
    MostrarCartas(cartas_usuario);
    cout << "Puntos: " << puntos << endl;
    dinero_apostado = Apostar(j_actual);
    cout << "Mas cartas o te plantas (+/o): ";
    cin >> c;


    while(c == '+')
    {
    	DarCarta = sfMusic_createFromFile(MUSICACARTA.c_str());
		sfMusic_play(DarCarta);
		
        cout << "Nueva carta para el usuario.\n";
        RepartirCarta(baraja_barajada, cartas_usuario, puntos, indice_baraja);
        MostrarCartas(cartas_usuario);
        cout << "Puntos: " << puntos << endl;
        cout << "Mas cartas o te plantas (+/o): ";
        cin >> c; 
    }
    cout << "Juega la banca.\n";
    MostrarCartas(cartas_ordenador);
    cout << "Puntos: " << puntos_ordenador << endl; 
    
    while(puntos_ordenador < 6 && puntos_ordenador < 8)
    {
        cout << "Siguiente jugada de la banca.\n";
        RepartirCarta(baraja_barajada, cartas_ordenador, puntos_ordenador, 
        indice_baraja);
        MostrarCartas(cartas_ordenador);
        cout << "Puntos: " << puntos_ordenador << endl;
    }
    cout << "La banca se planta." << endl;
    
    if(puntos > puntos_ordenador && puntos <= 7.5)
    {
        cout << "Gana el usuario: " << j_actual.nombre << endl;
        ganar = true;
    }
    else if(puntos_ordenador > 7.5 && puntos <= 7.5)
    {
        cout << "Gana el usuario: " << j_actual.nombre << endl;
        ganar = true;
    }
    
    if(ganar)
    {   
        int i = 0;
        j_actual.dinero += dinero_apostado;
        while(i < jugs.n_jugadores && !encontrado2)
        {
            if(jugs.v[i].nombre ==  j_actual.nombre)
            {
                posicion_dinero = i;
                encontrado2 = true;
            }
            i++;
        }
        jugs.v[posicion_dinero] = j_actual;
    }
    else
    {
        int j = 0;
        cout << "Gana la banca." << endl;
        j_actual.dinero -= dinero_apostado;

        while(j < jugs.n_jugadores && !encontrado2)
        {
            if(jugs.v[j].nombre ==  j_actual.nombre)
            {
                posicion_dinero = j;
                encontrado2 = true;
            }
            j++;
        }
        jugs.v[posicion_dinero] = j_actual;
    }
    if(j_actual.dinero <= 0)
    {
        int i = 0;
        cout << "El jugador actual ha perdido todo su dinero. Se eliminara"<<
        " y no podra jugar de nuevo.\n";
        nom = "Default";
        
        while(i < jugs.n_jugadores && !encontrado)
        {
            if(jugs.v[i].nombre ==  j_actual.nombre)
            {
                posicion_borrar = i;
                encontrado = true;
            }
            i++;
        }
        for(i = posicion_borrar; i < jugs.n_jugadores; i++)
        {
            jugs.v[i] = jugs.v[i + 1];
        }
        jugs.n_jugadores--;
    }
    EscribirDatos(cartas_usuario, f, puntos);
    EscribirDatos(cartas_ordenador, f, puntos_ordenador);  
    f.write((char*)(&dinero_apostado), sizeof(dinero_apostado));
    f.write((char*)(&ganar), sizeof(ganar));
    f.close();
  
    sfMusic_destroy(BarajarSonido);
    sfMusic_destroy(DarCarta);
 
    return;
}

/** EscribirDatos**//**
 * 
 * Escribe la informacion de la ultima partida
 *
 *@param [in] baraja baraja del jugador/banca
 *@param [out] f fichero donde se va a guardar
 *@param [in] puntos Puntos del jugador
 *
 *//****************/
void EscribirDatos(Baraja baraja, ofstream & f, float puntos)
{
    f.write((char*)(&baraja.n_cartas), sizeof(baraja.n_cartas));
    for(int i = 0; i < baraja.n_cartas; i++)
    {
        f.write((char*)(&baraja.Cartas[i].numero), 
        sizeof(baraja.Cartas[i].numero));
       f << baraja.Cartas[i].palo << endl ;     
    }
    f.write((char*)(&puntos), sizeof(puntos));
    
    return;
}

/** RepartirCarta**//**
 * 
 * Reparte una carta
 *
 *@param [in] baraja baraja de donde se va a repartir
 *@param [out] cartas_repartidas cartas ya repartidas
 *@param [out] puntos puntos actuales
 *@param [out] indice_baraja numero de cartas repartidas hasta el momento
 *
 *//****************/
void RepartirCarta(Baraja baraja, Baraja & cartas_repartidas, float & puntos, 
int & indice_baraja)
{
    if(baraja.Cartas[indice_baraja].numero > 7)
    {
        puntos += 0.5;
    }
    else if(baraja.Cartas[indice_baraja].numero <= 7)
    {
        puntos += baraja.Cartas[indice_baraja].numero; 
    }
    cartas_repartidas.Cartas[cartas_repartidas.n_cartas] = baraja.Cartas[indice_baraja];
    cartas_repartidas.n_cartas++;
    indice_baraja++;
    
    return;
}

/** Apostar**//**
 * 
 *Permite al jugador apostar dinero
 *
 *@param [in] j_actual jugador actual
 *
 *//****************/
float Apostar(Jugador j_actual)
{
    float dinero;
    bool correcto = true;
    Dinero = sfMusic_createFromFile(MUSICADINERO.c_str());
    
    while (correcto)
    {
        cout << "Dame apuesta (max " << j_actual.dinero << " euros): ";
        cin >> dinero;
        if(dinero > j_actual.dinero)
        {
            cout << "No tienes suficiente dinero.\n";
        }
        else if(dinero <= 0)
        {
            cout << "El valor debe ser mayor a cero.\n";
        }
        else
        {
            correcto = false;
        }
    }
    sfMusic_play(Dinero);
    sfMusic_destroy(Dinero);
	  
    return dinero;
}

/** Barajar**//**
 * 
 * Baraja baraja
 *
 *@param [in] baraja baraja a barajar
 *@return agrupacion de cartas
 *
 *//****************/
Baraja Barajar (Baraja baraja)
{
    Repetidos repe;
    int tam, random;
    Baraja barajada;
    srand(time(0));
    tam = 0;
    
    while (barajada.n_cartas < MAX_C)
    {
        random = rand() % 40; 
        if(!Aparecido(repe, random, tam))
        {
            barajada.Cartas[barajada.n_cartas] = baraja.Cartas[random];
            repe[tam] = random;
            barajada.n_cartas++;
            tam++;
        }
    }
    return barajada;
}

/**Aparecido**//**
 * 
 * Nos dice si la posicion ya ha aparecido
 *
 *@param [in] repe Vector de numeros ya aparecidos
 *@param [in] numero numero a comprobar si ha aparecido
 *@param [out] tam tamayo actual del vector
 *@return valor booleano que nos dice si ha aparecido
 *
 *//****************/
bool Aparecido(Repetidos repe, int numero, int & tam)
{
    int i = 0;
    bool aparece;
    aparece = false;
    while(i < tam && !aparece)
    {
        if(repe[i] == numero)
            aparece = true;
        i++;
    }
    
    return aparece;
}

/**LeerCartas**//**
 * 
 * Lee las cartas de cada jugador de un fichero binario
 *
 *@param [in] num Numero de cartas que hay en el fichero
 *@param [in] f fichero del que leemos
 *@return La agrupacion de cartas leida
 *
 *//****************/
Baraja LeerCartas(int num, ifstream & f)
{ 
    Baraja baraja;
    baraja.n_cartas = num;
    Carta carta;
    int i;
    
    for(i = 0; i < baraja.n_cartas; i++)
    {
        f.read((char*)(&carta.numero), sizeof(carta.numero));
        getline(f , carta.palo);
        baraja.Cartas[i] = carta;           
    }
    
    return baraja;
}

/**UltimaPartida**//**
 * 
 * Muestra la ultima partida
 *
 *@param [in] n nombre del fichero del que leemos
 *
 *//****************/
void UltimaPartida(string n)
{
    ifstream f;
    Baraja cartas_usuario, cartas_ordenador;
    bool ganar;
    float puntuacion_jugador, puntuacion_banca, dinero_apostado;
    
    f.open(n, ios::binary);
    
    if(f)
    {
        f.read((char*)(&cartas_usuario.n_cartas), 
        sizeof(cartas_usuario.n_cartas));
        cartas_usuario = LeerCartas(cartas_usuario.n_cartas, f); 
        f.read((char*)(&puntuacion_jugador), sizeof(puntuacion_jugador));
       
        cout << "Puntuacion del jugador: " << puntuacion_jugador << endl;
        MostrarCartas(cartas_usuario);
        
        f.read((char*)(&cartas_ordenador.n_cartas), 
        sizeof(cartas_ordenador.n_cartas)); 
        cartas_ordenador = LeerCartas(cartas_ordenador.n_cartas, f);  
        f.read((char*)(&puntuacion_banca), sizeof(puntuacion_banca));
        f.read((char*)(&dinero_apostado), sizeof(dinero_apostado));
        f.read((char*)(&ganar), sizeof(ganar));
        
        cout << "Puntuacion de la banca: " << puntuacion_banca << endl;
        MostrarCartas(cartas_ordenador); 
        cout << "Dinero apostado: " << dinero_apostado << endl;  

        if(ganar)
        {
            cout << "Gana el jugador. Pierde la banca." << endl;
        }
        else
        {
            cout << "Gana la banca. Pierde el jugador." << endl;
        }
        f.close();
    }
    else
    {
        cout << "Error en la lectura.\n";
    }
    
    return;
}

/**MostrarCartas**//**
 * 
 * Muestra la baraja de cada jugador
 *
 *@param [in] b baraja a mostrar
 *
 *//****************/
void MostrarCartas (Baraja b)
{
    string p1, p2, p3, p4, p5, p6, p7;
    Carta carta;
    string num; 
    
    for(int i = 0 ; i < b.n_cartas; i++)
    {
        carta = b.Cartas[i];
        p2 += ConstruirSuperior(carta);
        ConstruirPalo(carta.palo, p3, p4, p5, p6, p7);
        p1 += "+-------+ ";  
    }
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << p4 << endl;
    cout << p5 << endl;
    cout << p6 << endl;
    cout << p7 << endl;
    cout << p2 << endl;
    cout << p1 << endl;
    
    return;
}

/**ConstruirSuperior**//**
 * 
 * construye la parte superior de la carta
 *
 *@param [in] carta carta que vamos a representar
 *
 *//****************/
string ConstruirSuperior (Carta carta)
{
    string p2, num;
     
    if(carta.numero < 8)
    {
        num = to_string(carta.numero);
        p2 += "|" + num;  
        p2 += "     " + num;    
        p2 +=  "| ";
    }
    else if(carta.numero == 10)
        p2 += "|  Sota | "; 
    else if (carta.numero == 11)
        p2 += "|Caballo| ";
    else if (carta.numero == 12)
        p2 += "|  Rey  | "; 
          
    return p2;
}

/**ConstruirPalo**//**
 * 
 * construye el palo (devuelve 5 partes)
 *
 *@param [in] palo palo a construir
 *@param [out] p1 parte 1
 *@param [out] p2 parte 2
 *@param [out] p3 parte 3
 *@param [out] p4 parte 4
 *@param [out] p5 parte 5
 *
 *//****************/
void ConstruirPalo (string palo, string & p1, string& p2, string & p3,
string & p4 ,string & p5)
{
    if(palo == "Oros")
    {
        p1 += "|       | ";
        p2 += "|  ***  | ";
        p3 += "| *   * | ";
        p4 += "| *   * | ";
        p5 += "|  ***  | ";
    }
    else if (palo == "Bastos")
    {
        p1 += "|   *   | ";
        p2 += "|  ***  | ";
        p3 += "|  ***  | ";
        p4 += "|   *   | ";
        p5 += "|   *   | ";
    }
    else if (palo == "Copas")
    {
        p1 += "|       | ";
        p2 += "| *   * | ";
        p3 += "|  ***  | ";
        p4 += "|   *   | ";
        p5 += "| ***** | ";
    }
    else if (palo == "Espadas")
    {
        p1 += "|   *   | ";
        p2 += "|   *   | ";
        p3 += "|   *   | ";
        p4 += "|  ***  | ";
        p5 += "|   *   | ";
    }   
    
    return;
}
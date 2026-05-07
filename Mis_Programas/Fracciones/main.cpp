#include <iostream>
#include <string>
#include "Fraccion.h"
#include <fstream>
using namespace std;


int main ()
{
    
    string s = "Max Max Max Super Max Max Super super Max Max Max";
    string palabra;
    int pos, ant;
    
    ant = 0;
    
    pos = s.find(' ');

  
    while(pos  != string::npos)
    {
        palabra = s.substr(ant,pos - ant);
       
        
        cout << palabra << endl;
        
        ant = pos;
        
        s.erase(pos,1);
        pos = s.find(' '); 
        
    }
    cout << s.substr(ant, s.length() - ant);
    
    
    
   
 
  
    
    
   
    
   
}

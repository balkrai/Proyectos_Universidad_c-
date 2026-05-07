#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

const int MAYOR = 3;



using namespace std;


int main()
{ 
    int num = 1;
    int cont = 0;
    string nums = "";

    do
    {
         cout << "Dame numero ";
         cin >> num;  
         
         if(num > MAYOR)
         {
             nums += to_string(num) +" ";
             cont ++;
         } 
    }while(num != 0);
    
    cout << "Hay " << cont << " nums mayores que " << MAYOR << " y son: " << endl;
    cout << nums;
    return 0;
}


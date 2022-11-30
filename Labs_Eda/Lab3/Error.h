#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


class ErrorLlena: public std::out_of_range{
    
    public:
        ErrorLlena();

};


class ErrorVacia: public std::out_of_range{
    
    public:
        ErrorVacia();

};

#ifndef FICHA_H
#define FICHA_H

#include <cstdlib>
#include <iostream>
#include "string"
#include <vector>
#include "time.h"

using namespace std;

class Ficha{
public:
    int* pos;
    bool rojo;
    bool azul;
    bool* conectainicio;
    bool* conectafinal;
    vector<int*> coneci;
    vector<int*> conecf;
    Ficha();    // constructor
    ~Ficha();   // destructor
    void operator~();

};
#endif /* FICHA_H */

#ifndef TABLERO_H
#define TABLERO_H

#include "ficha.h"

using namespace std;

class Tablero{
public:
    Ficha** tablero;
    int size;
    bool ganar;

    Tablero();      // constructor
    ~Tablero();     // destructor
    Tablero(int t);

    bool ponroja(int a, int b);
    bool ponazul(int a, int b);
    void operator~();
};
#endif /* TABLERO_H */

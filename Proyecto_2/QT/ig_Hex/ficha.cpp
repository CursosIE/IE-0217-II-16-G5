#include "ficha.h"

Ficha::Ficha(){
    bool* conectai = new bool[1];
    bool* conectaf = new bool[1];
    int* posi= new int[2];
    pos=posi;
    conectainicio=conectai;
    conectafinal=conectaf;
    rojo=false;
    azul=false;
    pos[0]=0;
    pos[1]=0;
    conectainicio[0]=false;
    conectafinal[0]=false;
}

Ficha::~Ficha(){
}

void Ficha::operator~(){
    cout<<"Color de ficha: ";
        if(this->rojo){cout<<"Rojo"<<endl;}
        else if(this->azul){cout<<"Azul"<<endl;}
        else{cout<<"Sin color"<< endl;}
    cout<<"Anclada al inicio: ";
        if(*conectainicio){cout<<"Sí"<<endl;}
        else{cout<<"No"<<endl;}
    cout<<"Anclada al final: ";
        if(*conectafinal){cout<<"Sí"<<endl;}
        else{cout<<"No"<<endl;}
}

#include "tablero.h"

Tablero::Tablero(){
}

Tablero::Tablero(int i){
    this->size=i;
    Ficha** tab = new Ficha*[i];
    for(int j=0; j<i; j++){
        tab[j]=new Ficha[i];
    }
    this->tablero=tab;
}

Tablero::~Tablero(){
}

void Tablero::operator~(){
    int m=1;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(tablero[i][j].rojo){cout<<"R ";}
            if(tablero[i][j].azul){cout<<"A ";}
            else if(tablero[i][j].rojo==false && tablero[i][j].azul==false){cout<<"0 ";}
            }
        cout<<endl;
        for(int k=0; k<m; k++){
        cout<<" ";}
        m++;
        }
    cout<<endl;
    }

///Función que coloca una ficha roja en el tablero y busca si existe camino posible hasta el inicio o final del tablero, verificando el gane
bool Tablero::ponroja(int a, int b){
    if(tablero[a][b].azul==false){
        tablero[a][b].rojo=true;
        tablero[a][b].pos[0]=a;
        tablero[a][b].pos[1]=b;
        tablero[a][b].coneci.push_back(tablero[a][b].pos);
        tablero[a][b].conecf.push_back(tablero[a][b].pos);
        //verificacion de conexion con inicio
        if(b==0){
            *tablero[a][b].conectainicio=true;
            if(a!=0 && tablero[a-1][b+1].rojo==true){
                *tablero[a-1][b+1].conectainicio = true;
                for(int i=0; i<tablero[a-1][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b+1].coneci[i]);
                            }
                }
            if(tablero[a][b+1].rojo==true){
                *tablero[a][b+1].conectainicio = true;
                for(int i=0; i<tablero[a][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b+1].coneci[i]);
                            }
                }
            if(a!=0 && tablero[a-1][b+1].rojo==true && *tablero[a-1][b+1].conectafinal==true ){
                *tablero[a][b].conectafinal = true;
                }
            if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectafinal==true){
                *tablero[a][b].conectafinal = true;
                }
            if(tablero[a][b+1].rojo==true){
                *tablero[a][b+1].conectainicio = true;
                for(int i=0; i<tablero[a][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b+1].coneci[i]);
                            }
                }
            if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectafinal==false){
                        for(int i=0; i<tablero[a][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b+1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].coneci[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
            if(a!=0 && tablero[a-1][b+1].rojo==true && *tablero[a-1][b+1].conectafinal==false){
                        for(int i=0; i<tablero[a-1][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b+1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
            }
        if(b==size-1){
            if(a!=size-1 && tablero[a+1][b-1].rojo==true){
                for(int i=0; i<tablero[a+1][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b-1].coneci[i]);
                            }
                }
            if(tablero[a][b-1].rojo==true){
                for(int i=0; i<tablero[a][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b-1].coneci[i]);
                            }
                }
            if(a!=size-1 && tablero[a+1][b-1].rojo==true && *tablero[a+1][b-1].conectafinal==true ){
                *tablero[a][b].conectafinal = true;
                }
            if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectafinal==true){
                *tablero[a][b].conectafinal = true;
                }

            if(tablero[a][b-1].rojo==true){
                for(int i=0; i<tablero[a][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b-1].coneci[i]);
                            }
                }
            }
        else if(b!=0 && b!=size-1){
            if(*tablero[a][b].conectainicio==true){
                if(a!=0 && a!=size-1){
                    if(tablero[a-1][b+1].rojo==true){
                        for(int i=0; i<tablero[a-1][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b+1].coneci[i]);
                            }
                        }
                    if(tablero[a+1][b-1].rojo==true){
                        for(int i=0; i<tablero[a+1][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b-1].coneci[i]);
                            }
                        }
                    if(tablero[a][b+1].rojo==true){
                        for(int i=0; i<tablero[a][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b+1].coneci[i]);
                            }
                        }
                    if(tablero[a][b-1].rojo==true){
                        for(int i=0; i<tablero[a][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b-1].coneci[i]);
                            }
                        }
                    if(tablero[a-1][b].rojo==true){
                        for(int i=0; i<tablero[a-1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b].coneci[i]);
                            }
                        }
                    if(tablero[a+1][b].rojo==true){
                        for(int i=0; i<tablero[a+1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b].coneci[i]);
                            }
                        }
                    }
                else if(a==0){
                    if(tablero[a+1][b-1].rojo==true){
                        for(int i=0; i<tablero[a+1][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b-1].coneci[i]);
                            }
                        }
                    if(tablero[a][b+1].rojo==true){
                        for(int i=0; i<tablero[a][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b+1].coneci[i]);
                            }
                        }
                    if(tablero[a][b-1].rojo==true){
                        for(int i=0; i<tablero[a][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b-1].coneci[i]);
                            }
                        }
                    if(tablero[a+1][b].rojo==true){
                        for(int i=0; i<tablero[a+1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b].coneci[i]);
                            }
                        }
                    }
                else if(a==size-1){
                    if(tablero[a-1][b+1].rojo==true){
                        for(int i=0; i<tablero[a-1][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b+1].coneci[i]);
                            }
                        }
                    if(tablero[a][b+1].rojo==true){
                        for(int i=0; i<tablero[a][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b+1].coneci[i]);
                            }
                        }
                    if(tablero[a][b-1].rojo==true){
                        for(int i=0; i<tablero[a][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b-1].coneci[i]);
                            }
                        }
                    if(tablero[a-1][b].rojo==true){
                        for(int i=0; i<tablero[a-1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b].coneci[i]);
                            }
                        }
                    }
                }
            else if(*tablero[a][b].conectainicio==false){
                if(a!=0 && a!=size-1){
                    if(tablero[a-1][b+1].rojo==true && *tablero[a-1][b+1].conectainicio==false){
                        for(int i=0; i<tablero[a-1][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b+1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a+1][b-1].rojo==true && *tablero[a+1][b-1].conectainicio==false){
                        for(int i=0; i<tablero[a+1][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b-1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectainicio==false){
                        for(int i=0; i<tablero[a][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b+1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectainicio==false){
                        for(int i=0; i<tablero[a][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b-1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a-1][b].rojo==true && *tablero[a-1][b].conectainicio==false){
                        for(int i=0; i<tablero[a-1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a+1][b].rojo==true && *tablero[a+1][b].conectainicio==false){
                        for(int i=0; i<tablero[a+1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    }
                else if(a==0){
                    if(tablero[a+1][b-1].rojo==true && *tablero[a+1][b-1].conectainicio==false){
                        for(int i=0; i<tablero[a+1][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b-1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectainicio==false){
                        for(int i=0; i<tablero[a][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b+1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectainicio==false){
                        for(int i=0; i<tablero[a][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b-1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a+1][b].rojo==true && *tablero[a+1][b].conectainicio==false){
                        for(int i=0; i<tablero[a+1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    }
                else if(a==size-1){
                    if(tablero[a-1][b+1].rojo==true && *tablero[a-1][b+1].conectainicio==false){
                        for(int i=0; i<tablero[a+1][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b+1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectainicio==false){
                        for(int i=0; i<tablero[a][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b+1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectainicio==false){
                        for(int i=0; i<tablero[a][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b-1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a-1][b].rojo==true && *tablero[a-1][b].conectainicio==false){
                        for(int i=0; i<tablero[a-1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    }
                if(a!=0 && a!=size-1){
                    if(tablero[a-1][b+1].rojo==true && *tablero[a-1][b+1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a+1][b-1].rojo==true && *tablero[a+1][b-1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectainicio==true){
                        *tablero[a][b].conectainicio = true;
                        }
                    if(tablero[a-1][b].rojo==true && *tablero[a-1][b].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a+1][b].rojo==true && *tablero[a+1][b].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    }
                else if(a==0){
                    if(tablero[a+1][b-1].rojo==true && *tablero[a+1][b-1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a+1][b].rojo==true && *tablero[a+1][b].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    }
                else if(a==size-1){
                    if(tablero[a-1][b+1].rojo==true && *tablero[a-1][b+1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a-1][b].rojo==true && *tablero[a-1][b].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    }



                }

        }
        if(*tablero[a][b].conectainicio==true){
            while(tablero[a][b].coneci.empty()==false){
                *tablero[tablero[a][b].coneci.back()[0]][tablero[a][b].coneci.back()[1]].conectainicio=true;
                tablero[a][b].coneci.pop_back();
                }
            }
        //verificacion de conexion con el final
        if(b==size-1){
            *tablero[a][b].conectafinal=true;
            if(a!=size-1 && tablero[a+1][b-1].rojo==true){
                *tablero[a+1][b-1].conectafinal = true;
                for(int i=0; i<tablero[a+1][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b-1].conecf[i]);
                            }
                }
            if(tablero[a][b-1].rojo==true){
                *tablero[a][b-1].conectafinal = true;
                for(int i=0; i<tablero[a][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b-1].conecf[i]);
                            }
                }
            if(a!=size-1 && tablero[a+1][b-1].rojo==true && *tablero[a+1][b-1].conectainicio==true){
                *tablero[a][b].conectainicio=true;
                }
            if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectainicio==true){
                *tablero[a][b].conectainicio=true;
                }
            }
        else if(b!=size-1 && b!=0){
            if(*tablero[a][b].conectafinal==true){
                if(a!=0 && a!=size-1){
                    if(tablero[a-1][b+1].rojo==true){
                        for(int i=0; i<tablero[a-1][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b+1].conecf[i]);
                            }
                        }
                    if(tablero[a+1][b-1].rojo==true){
                        for(int i=0; i<tablero[a+1][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b-1].conecf[i]);
                            }
                        }
                    if(tablero[a][b+1].rojo==true){
                        for(int i=0; i<tablero[a][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b+1].conecf[i]);
                            }
                        }
                    if(tablero[a][b-1].rojo==true){
                        for(int i=0; i<tablero[a][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b-1].conecf[i]);
                            }
                        }
                    if(tablero[a-1][b].rojo==true){
                        for(int i=0; i<tablero[a-1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b].conecf[i]);
                            }
                        }
                    if(tablero[a+1][b].rojo==true){
                        for(int i=0; i<tablero[a+1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b].conecf[i]);
                            }
                        }
                    }
                else if(a==0){
                    if(tablero[a+1][b-1].rojo==true){
                        for(int i=0; i<tablero[a+1][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b-1].conecf[i]);
                            }
                        }
                    if(tablero[a][b+1].rojo==true){
                        for(int i=0; i<tablero[a][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b+1].conecf[i]);
                            }
                        }
                    if(tablero[a][b-1].rojo==true){
                        for(int i=0; i<tablero[a][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b-1].conecf[i]);
                            }
                        }
                    if(tablero[a+1][b].rojo==true){
                        for(int i=0; i<tablero[a+1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b].conecf[i]);
                            }
                        }
                    }
                else if(a==size-1){
                    if(tablero[a-1][b+1].rojo==true){
                        for(int i=0; i<tablero[a-1][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b+1].conecf[i]);
                            }
                        }
                    if(tablero[a][b+1].rojo==true){
                        for(int i=0; i<tablero[a][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b+1].conecf[i]);
                            }
                        }
                    if(tablero[a][b-1].rojo==true){
                        for(int i=0; i<tablero[a][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b-1].conecf[i]);
                            }
                        }
                    if(tablero[a-1][b].rojo==true){
                        for(int i=0; i<tablero[a-1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b].conecf[i]);
                            }
                        }
                    }
                }
            else if(*tablero[a][b].conectafinal==false){
                if(a!=0 && a!=size-1){
                    if(tablero[a-1][b+1].rojo==true && *tablero[a-1][b+1].conectafinal==false){
                        for(int i=0; i<tablero[a-1][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b+1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a+1][b-1].rojo==true && *tablero[a+1][b-1].conectafinal==false){
                        for(int i=0; i<tablero[a+1][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b-1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectafinal==false){
                        for(int i=0; i<tablero[a][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b+1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectafinal==false){
                        for(int i=0; i<tablero[a][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b-1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a-1][b].rojo==true && *tablero[a-1][b].conectafinal==false){
                        for(int i=0; i<tablero[a-1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a+1][b].rojo==true && *tablero[a+1][b].conectafinal==false){
                        for(int i=0; i<tablero[a+1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    }
                else if(a==0){
                    if(tablero[a+1][b-1].rojo==true && *tablero[a+1][b-1].conectafinal==false){
                        for(int i=0; i<tablero[a+1][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b-1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectafinal==false){
                        for(int i=0; i<tablero[a][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b+1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectafinal==false){
                        for(int i=0; i<tablero[a][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b-1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a+1][b].rojo==true && *tablero[a+1][b].conectafinal==false){
                        for(int i=0; i<tablero[a+1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    }
                else if(a==size-1){
                    if(tablero[a-1][b+1].rojo==true && *tablero[a-1][b+1].conectafinal==false){
                        for(int i=0; i<tablero[a-1][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b+1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectafinal==false){
                        for(int i=0; i<tablero[a][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b+1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectafinal==false){
                        for(int i=0; i<tablero[a][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b-1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a-1][b].rojo==true && *tablero[a-1][b].conectafinal==false){
                        for(int i=0; i<tablero[a-1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    }
                if(a!=0 && a!=size-1){
                    if(tablero[a-1][b+1].rojo==true && *tablero[a-1][b+1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a+1][b-1].rojo==true && *tablero[a+1][b-1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectafinal==true){
                        *tablero[a][b].conectafinal = true;
                        }
                    if(tablero[a-1][b].rojo==true && *tablero[a-1][b].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a+1][b].rojo==true && *tablero[a+1][b].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    }
                else if(a==0){
                    if(tablero[a+1][b-1].rojo==true && *tablero[a+1][b-1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a+1][b].rojo==true && *tablero[a+1][b].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    }
                else if(a==size-1){
                    if(tablero[a-1][b+1].rojo==true && *tablero[a-1][b+1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a][b+1].rojo==true && *tablero[a][b+1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a][b-1].rojo==true && *tablero[a][b-1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a-1][b].rojo==true && *tablero[a-1][b].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    }


                }

        }
        if(*tablero[a][b].conectafinal==true){
            while(tablero[a][b].conecf.empty()==false){
                *tablero[tablero[a][b].conecf.back()[0]][tablero[a][b].conecf.back()[1]].conectafinal=true;
                tablero[a][b].conecf.pop_back();
                }
            }
        return 1;
        }
    else if(tablero[a][b].azul==true){
        cout<<"Movimiento inválido"<< endl;
        return 0;
        }
    }





///Función que coloca una ficha azul en el tablero y busca si existe camino posible hasta el inicio o final del tablero, verificando el gane
bool Tablero::ponazul(int a, int b){
    if(tablero[a][b].rojo==false){
        tablero[a][b].azul=true;
        tablero[a][b].pos[0]=a;
        tablero[a][b].pos[1]=b;
        tablero[a][b].coneci.push_back(tablero[a][b].pos);
        tablero[a][b].conecf.push_back(tablero[a][b].pos);
        //verificacion de conexion con inicio
        if(a==0){
            *tablero[a][b].conectainicio=true;
            if(b!=0 && tablero[a+1][b-1].azul==true){
                *tablero[a+1][b-1].conectainicio = true;
                for(int i=0; i<tablero[a+1][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b-1].coneci[i]);
                            }
                }
            if(tablero[a+1][b].azul==true){
                *tablero[a+1][b].conectainicio = true;
                for(int i=0; i<tablero[a+1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b].coneci[i]);
                            }
                }
            if(b!=0 && tablero[a+1][b-1].azul==true && *tablero[a+1][b-1].conectafinal==true){
                *tablero[a][b].conectafinal = true;
                }
            if(tablero[a+1][b].azul==true && *tablero[a+1][b].conectafinal==true){
                *tablero[a][b].conectafinal = true;
                }
            if(tablero[a+1][b].azul==true && *tablero[a+1][b].conectafinal==false){
                        for(int i=0; i<tablero[a+1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].coneci[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
            if(b!=0 && tablero[a+1][b-1].azul==true && *tablero[a+1][b-1].conectafinal==false){
                        for(int i=0; i<tablero[a+1][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b-1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
            }

        if(a==size-1){
            if(b!=size-1 && tablero[a-1][b+1].azul==true){
                for(int i=0; i<tablero[a-1][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b+1].coneci[i]);
                            }
                }
            if(tablero[a-1][b].azul==true){
                for(int i=0; i<tablero[a-1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b].coneci[i]);
                            }
                }
            if(b!=size-1 && tablero[a-1][b+1].azul==true && *tablero[a-1][b+1].conectainicio==true){
                *tablero[a][b].conectainicio=true;
                }
            if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectainicio==true){
                *tablero[a][b].conectainicio=true;
                }
            if(b!=size-1 && tablero[a-1][b+1].azul==true && *tablero[a-1][b+1].conectafinal==true ){
                *tablero[a][b].conectafinal = true;
                }
            if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectafinal==true){
                *tablero[a][b].conectafinal = true;
                }

            if(tablero[a-1][b].azul==true){
                for(int i=0; i<tablero[a-1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b].coneci[i]);
                            }
                }
            }

        else if(a!=0 && a!=size-1){
            if(*tablero[a][b].conectainicio==true){
                if(b!=0 && b!=size-1){
                    if(tablero[a-1][b+1].azul==true){
                        for(int i=0; i<tablero[a-1][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b+1].coneci[i]);
                            }
                        }
                    if(tablero[a+1][b-1].azul==true){
                        for(int i=0; i<tablero[a+1][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b-1].coneci[i]);
                            }
                        }
                    if(tablero[a][b+1].azul==true){
                        for(int i=0; i<tablero[a][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b+1].coneci[i]);
                            }
                        }
                    if(tablero[a][b-1].azul==true){
                        for(int i=0; i<tablero[a][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b-1].coneci[i]);
                            }
                        }
                    if(tablero[a-1][b].azul==true){
                        for(int i=0; i<tablero[a-1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b].coneci[i]);
                            }
                        }
                    if(tablero[a+1][b].azul==true){
                        for(int i=0; i<tablero[a+1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b].coneci[i]);
                            }
                        }
                    }
                else if(b==0){
                    if(tablero[a-1][b+1].azul==true){
                        for(int i=0; i<tablero[a-1][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b+1].coneci[i]);
                            }
                        }
                    if(tablero[a+1][b].azul==true){
                        for(int i=0; i<tablero[a+1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b].coneci[i]);
                            }
                        }
                    if(tablero[a-1][b].azul==true){
                        for(int i=0; i<tablero[a-1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b].coneci[i]);
                            }
                        }
                    if(tablero[a][b+1].azul==true){
                        for(int i=0; i<tablero[a][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b+1].coneci[i]);
                            }
                        }
                    }
                else if(b==size-1){
                    if(tablero[a+1][b-1].azul==true){
                        for(int i=0; i<tablero[a+1][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b-1].coneci[i]);
                            }
                        }
                    if(tablero[a-1][b].azul==true){
                        for(int i=0; i<tablero[a-1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b].coneci[i]);
                            }
                        }
                    if(tablero[a+1][b].azul==true){
                        for(int i=0; i<tablero[a+1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b].coneci[i]);
                            }
                        }
                    if(tablero[a][b-1].azul==true){
                        for(int i=0; i<tablero[a][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b-1].coneci[i]);
                            }
                        }
                    }
                }
            else if(*tablero[a][b].conectainicio==false){
                if(b!=0 && b!=size-1){
                    if(tablero[a-1][b+1].azul==true && *tablero[a-1][b+1].conectainicio==false){
                        for(int i=0; i<tablero[a-1][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b+1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a+1][b-1].azul==true && *tablero[a+1][b-1].conectainicio==false){
                        for(int i=0; i<tablero[a+1][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b-1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a][b+1].azul==true && *tablero[a][b+1].conectainicio==false){
                        for(int i=0; i<tablero[a][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b+1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a][b-1].azul==true && *tablero[a][b-1].conectainicio==false){
                        for(int i=0; i<tablero[a][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b-1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectainicio==false){
                        for(int i=0; i<tablero[a-1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a+1][b].azul==true && *tablero[a+1][b].conectainicio==false){
                        for(int i=0; i<tablero[a+1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    }
                else if(b==size-1){
                    if(tablero[a+1][b-1].azul==true && *tablero[a+1][b-1].conectainicio==false){
                        for(int i=0; i<tablero[a+1][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b-1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectainicio==false){
                        for(int i=0; i<tablero[a-1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a][b-1].azul==true && *tablero[a][b-1].conectainicio==false){
                        for(int i=0; i<tablero[a][b-1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b-1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a+1][b].azul==true && *tablero[a+1][b].conectainicio==false){
                        for(int i=0; i<tablero[a+1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    }
                else if(b==0){
                    if(tablero[a-1][b+1].azul==true && *tablero[a-1][b+1].conectainicio==false){
                        for(int i=0; i<tablero[a-1][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b+1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a][b+1].azul==true && *tablero[a][b+1].conectainicio==false){
                        for(int i=0; i<tablero[a][b+1].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a][b+1].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a+1][b].azul==true && *tablero[a+1][b].conectainicio==false){
                        for(int i=0; i<tablero[a+1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a+1][b].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectainicio==false){
                        for(int i=0; i<tablero[a-1][b].coneci.size();i++){
                            tablero[a][b].coneci.push_back(tablero[a-1][b].coneci[i]);
                            }
                        for(int i=0; i<tablero[a][b].coneci.size();i++){
                            tablero[tablero[a][b].coneci[i][0]][tablero[a][b].coneci[i][1]].coneci=tablero[a][b].coneci;
                            }
                        }
                    }
                if(b!=0 && b!=size-1){
                    if(tablero[a-1][b+1].azul==true && *tablero[a-1][b+1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a+1][b-1].azul==true && *tablero[a+1][b-1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a][b+1].azul==true && *tablero[a][b+1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a][b-1].azul==true && *tablero[a][b-1].conectainicio==true){
                        *tablero[a][b].conectainicio = true;
                        }
                    if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a+1][b].azul==true && *tablero[a+1][b].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    }
                else if(b==size-1){
                    if(tablero[a+1][b-1].azul==true && *tablero[a+1][b-1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a+1][b].azul==true && *tablero[a+1][b].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a][b-1].azul==true && *tablero[a][b-1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    }
                else if(b==0){
                    if(tablero[a-1][b+1].azul==true && *tablero[a-1][b+1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a][b+1].azul==true && *tablero[a][b+1].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a+1][b].azul==true && *tablero[a+1][b].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectainicio==true){
                        *tablero[a][b].conectainicio=true;
                        }
                    }



                }

        }
        if(*tablero[a][b].conectainicio==true){
            while(tablero[a][b].coneci.empty()==false){
                *tablero[tablero[a][b].coneci.back()[0]][tablero[a][b].coneci.back()[1]].conectainicio=true;
                tablero[a][b].coneci.pop_back();
                }
            }
        //verificacion de conexion con el final
        if(a==size-1){
            *tablero[a][b].conectafinal=true;
            if(tablero[a-1][b+1].azul==true){
                *tablero[a-1][b+1].conectafinal = true;
                for(int i=0; i<tablero[a-1][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b+1].conecf[i]);
                            }
                }
            if(tablero[a-1][b].azul==true){
                *tablero[a-1][b].conectafinal = true;
                for(int i=0; i<tablero[a-1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b].conecf[i]);
                            }
                }
            if(tablero[a-1][b+1].azul==true && *tablero[a-1][b+1].conectainicio==true){
                *tablero[a][b].conectainicio=true;
                }
            if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectainicio==true){
                *tablero[a][b].conectainicio=true;
                }
            }
        else if(a!=size-1 && a!=0){
            if(*tablero[a][b].conectafinal==true){
                if(b!=0 && b!=size-1){
                    if(tablero[a-1][b+1].azul==true){
                        for(int i=0; i<tablero[a-1][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b+1].conecf[i]);
                            }
                        }
                    if(tablero[a+1][b-1].azul==true){
                        for(int i=0; i<tablero[a+1][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b-1].conecf[i]);
                            }
                        }
                    if(tablero[a][b+1].azul==true){
                        for(int i=0; i<tablero[a][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b+1].conecf[i]);
                            }
                        }
                    if(tablero[a][b-1].azul==true){
                        for(int i=0; i<tablero[a][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b-1].conecf[i]);
                            }
                        }
                    if(tablero[a-1][b].azul==true){
                        for(int i=0; i<tablero[a-1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b].conecf[i]);
                            }
                        }
                    if(tablero[a+1][b].azul==true){
                        for(int i=0; i<tablero[a+1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b].conecf[i]);
                            }
                        }
                    }
                else if(b==0){
                    if(tablero[a-1][b+1].azul==true){
                        for(int i=0; i<tablero[a-1][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b+1].conecf[i]);
                            }
                        }
                    if(tablero[a][b+1].azul==true){
                        for(int i=0; i<tablero[a][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b+1].conecf[i]);
                            }
                        }
                    if(tablero[a-1][b].azul==true){
                        for(int i=0; i<tablero[a-1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b].conecf[i]);
                            }
                        }
                    if(tablero[a+1][b].azul==true){
                        for(int i=0; i<tablero[a+1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b].conecf[i]);
                            }
                        }
                    }
                else if(b==size-1){
                    if(tablero[a+1][b-1].azul==true){
                        for(int i=0; i<tablero[a+1][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b-1].conecf[i]);
                            }
                        }
                    if(tablero[a+1][b].azul==true){
                        for(int i=0; i<tablero[a+1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b].conecf[i]);
                            }
                        }
                    if(tablero[a][b-1].azul==true){
                        for(int i=0; i<tablero[a][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b-1].conecf[i]);
                            }
                        }
                    if(tablero[a-1][b].azul==true){
                        for(int i=0; i<tablero[a-1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b].conecf[i]);
                            }
                        }
                    }
                }
            else if(*tablero[a][b].conectafinal==false){
                if(b!=0 && b!=size-1){
                    if(tablero[a-1][b+1].azul==true && *tablero[a-1][b+1].conectafinal==false){
                        for(int i=0; i<tablero[a-1][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b+1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a+1][b-1].azul==true && *tablero[a+1][b-1].conectafinal==false){
                        for(int i=0; i<tablero[a+1][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b-1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a][b+1].azul==true && *tablero[a][b+1].conectafinal==false){
                        for(int i=0; i<tablero[a][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b+1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a][b-1].azul==true && *tablero[a][b-1].conectafinal==false){
                        for(int i=0; i<tablero[a][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b-1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectafinal==false){
                        for(int i=0; i<tablero[a-1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a+1][b].azul==true && *tablero[a+1][b].conectafinal==false){
                        for(int i=0; i<tablero[a+1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    }
                else if(b==0){
                    if(tablero[a-1][b+1].azul==true && *tablero[a-1][b+1].conectafinal==false){
                        for(int i=0; i<tablero[a-1][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b+1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a][b+1].azul==true && *tablero[a][b+1].conectafinal==false){
                        for(int i=0; i<tablero[a][b+1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b+1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectafinal==false){
                        for(int i=0; i<tablero[a-1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a+1][b].azul==true && *tablero[a+1][b].conectafinal==false){
                        for(int i=0; i<tablero[a+1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    }
                else if(b==size-1){
                    if(tablero[a+1][b-1].azul==true && *tablero[a+1][b-1].conectafinal==false){
                        for(int i=0; i<tablero[a+1][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a+1][b-1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectafinal==false){
                        for(int i=0; i<tablero[a-1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a][b-1].azul==true && *tablero[a][b-1].conectafinal==false){
                        for(int i=0; i<tablero[a][b-1].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a][b-1].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectafinal==false){
                        for(int i=0; i<tablero[a-1][b].conecf.size();i++){
                            tablero[a][b].conecf.push_back(tablero[a-1][b].conecf[i]);
                            }
                        for(int i=0; i<tablero[a][b].conecf.size();i++){
                            tablero[tablero[a][b].conecf[i][0]][tablero[a][b].conecf[i][1]].conecf=tablero[a][b].conecf;
                            }
                        }
                    }
                if(b!=0 && b!=size-1){
                    if(tablero[a-1][b+1].azul==true && *tablero[a-1][b+1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a+1][b-1].azul==true && *tablero[a+1][b-1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a][b+1].azul==true && *tablero[a][b+1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a][b-1].azul==true && *tablero[a][b-1].conectafinal==true){
                        *tablero[a][b].conectafinal = true;
                        }
                    if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a+1][b].azul==true && *tablero[a+1][b].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    }
                else if(b==0){
                    if(tablero[a-1][b+1].azul==true && *tablero[a-1][b+1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a][b+1].azul==true && *tablero[a][b+1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a+1][b].azul==true && *tablero[a+1][b].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    }
                else if(b==size-1){
                    if(tablero[a+1][b-1].azul==true && *tablero[a+1][b-1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a+1][b].azul==true && *tablero[a+1][b].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a][b-1].azul==true && *tablero[a][b-1].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    if(tablero[a-1][b].azul==true && *tablero[a-1][b].conectafinal==true){
                        *tablero[a][b].conectafinal=true;
                        }
                    }


                }

        }
        if(*tablero[a][b].conectafinal==true){
            while(tablero[a][b].conecf.empty()==false){
                *tablero[tablero[a][b].conecf.back()[0]][tablero[a][b].conecf.back()[1]].conectafinal=true;
                tablero[a][b].conecf.pop_back();
                }
            }
        return 1;
        }
    else if(tablero[a][b].rojo==true){
        cout<<"Movimiento inválido"<< endl;
        return 0;
        }
    }

#include <stdio.h>
#include <stdlib.h>}
///Este es una funcion que suma argumentos ingresados desde consola 
int sum(int argc, char** argv) 
{
    double sum=0.000;
    int i=0; 
    for(i=0; i<argc; i++){
        sum+= atof(argv[i]);
        }
    printf("%f\n", sum);
    return 0;
}
///Esta es un main que corre la funcion sum
int main(int argc, char** argv){
   sum(argc, argv);	
}

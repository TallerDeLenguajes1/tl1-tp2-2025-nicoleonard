#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int velocidad;      // Velocidad de procesamiento en GHz (valor entre 1 y 3) 
    int anio;           // Año de fabricación (valor entre 2015 y 2024) 
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8) 
    char *tipo_cpu;     // Tipo de procesador (apuntador a cadena de caracteres)    
}compu;

char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", 
    "Pentium"};

void generarCompus(compu *compu);

int main(){
    compu listaCompus[5];
    generarCompus(listaCompus);

}


void generarCompus(compu *listaCompu){
    int i;
 
    for(i=0;i<5;i++){
        (listaCompu+i)->velocidad= rand()%3+1;
        (listaCompu+i)->anio= 2015+rand()%10;
        (listaCompu+i)->cantidad_nucleos= rand()%8+1;
        (listaCompu+i)->tipo_cpu[rand()%6];
    }
}
#include <stdio.h>
#include <stdlib.h>

typedef struct compu{
    int velocidad;      // Velocidad de procesamiento en GHz (valor entre 1 y 3) 
    int anio;           // Año de fabricación (valor entre 2015 y 2024) 
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8) 
    char *tipo_cpu;     // Tipo de procesador (apuntador a cadena de caracteres)    
}compu;

char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", 
    "Pentium"};

void generarCompus(compu *compu);
void listarPCs(compu pcs[], int cantidad);
void mostrarMasVieja(compu pcs[], int cantidad);
void mostrarMasVeloz(compu pcs[], int cantidad);



int main(){
    compu listaCompus[5];
    generarCompus(listaCompus);

}


void generarCompus(compu *listaCompu){
    for(int i=0;i<5;i++){
        (listaCompu+i)->velocidad= rand()%3+1;
        (listaCompu+i)->anio= 2015+rand()%10;
        (listaCompu+i)->cantidad_nucleos= rand()%8+1;
        (listaCompu+i)->tipo_cpu[rand()%6];
    }
}

void listarPCs(compu listaCompu[], int cantidadElementos){
    for(int i=0; i<cantidadElementos; i++){
        printf("velocidad: %d - ", listaCompu[i].velocidad);
        printf("cantidad de nucleos: %d - ", listaCompu[i].cantidad_nucleos);
        printf("tipo de cpu: %s - ", listaCompu[i].tipo_cpu);
        printf("año de fabricacion: %d", listaCompu[i].anio);
        printf("\n --------------------------- ");
    }   
}


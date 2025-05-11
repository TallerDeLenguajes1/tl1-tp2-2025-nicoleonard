#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    listarPCs(listaCompus,5);
    mostrarMasVeloz(listaCompus, 5);
    mostrarMasVieja(listaCompus, 5);
}


void generarCompus(compu *listaCompu){
    for(int i=0;i<5;i++){
        (listaCompu+i)->velocidad= rand()%3+1;
        (listaCompu+i)->anio= 2015+rand()%10;
        (listaCompu+i)->cantidad_nucleos= rand()%8+1;
        (listaCompu+i)->tipo_cpu =tipos[rand()%6];
    }
}

void listarPCs(compu listaCompu[], int cantidadElementos){
    printf("Lista PC \n");
    for(int i=0; i<cantidadElementos; i++){
        printf("velocidad: %d Ghz- ", listaCompu[i].velocidad);
        printf("cantidad de nucleos: %d - ", listaCompu[i].cantidad_nucleos);
        printf("tipo de cpu: %s - ", listaCompu[i].tipo_cpu);
        printf("año de fabricacion: %d", listaCompu[i].anio);
        printf("\n --------------------------- \n");
    }   
}

void mostrarMasVieja(compu listaCompu[], int cantidadElementos){
    int indicePCVieja;
    int auxAnio =2025;
    for(int i=0; i<cantidadElementos; i++){
        if(listaCompu[i].anio <= auxAnio){
            indicePCVieja=i;
            auxAnio=listaCompu[i].anio;
        }
    }
    printf("\n pc mas vieja \n");
    printf("velocidad: %d Ghz- ", listaCompu[indicePCVieja].velocidad);
    printf("cantidad de nucleos: %d - ", listaCompu[indicePCVieja].cantidad_nucleos);
    printf("tipo de cpu: %s - ", listaCompu[indicePCVieja].tipo_cpu);
    printf("año de fabricacion: %d", listaCompu[indicePCVieja].anio);
    printf("\n --------------------------- \n");
    
}

void mostrarMasVeloz(compu listaCompu[], int cantidadElementos){
    int indicePCVeloz;
    int auxVelocidad =0;
    for(int i=0; i<cantidadElementos; i++){
        if(listaCompu[i].velocidad >= auxVelocidad){
            indicePCVeloz=i;
            auxVelocidad=listaCompu[i].velocidad;
        }
    }
    printf("\n pc mas veloz \n");
    printf("velocidad: %d Ghz- ", listaCompu[indicePCVeloz].velocidad);
    printf("cantidad de nucleos: %d - ", listaCompu[indicePCVeloz].cantidad_nucleos);
    printf("tipo de cpu: %s - ", listaCompu[indicePCVeloz].tipo_cpu);
    printf("año de fabricacion: %d", listaCompu[indicePCVeloz].anio);
    printf("\n --------------------------- \n");
}
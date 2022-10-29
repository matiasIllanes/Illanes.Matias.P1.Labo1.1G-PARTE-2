#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"


int mostrarDestino(eDestino destino[], int tam, int clear){

    int todoOk=0;
    if(destino!=NULL && tam>0 && clear>=0 && clear<=1){
        if(clear==1){
            system("cls");
        }
        printf("*********** Lista de Destinos ***********\n\n");
        printf("Id                Descripcion              Precio\n");
        printf("---------------------------------------------------\n");
        for(int i=0;i<tam;i++){
            printf("%d        %15s        %8.1f\n", destino[i].id, destino[i].descripcion, destino[i].precio);
        }
        printf("\n\n");
    }
    return todoOk;
}


int validarIdDestino(int id, eDestino destino[], int tam){
    int esValido=0;
    if(destino!=NULL && tam>0 ){
        for(int i=0;i<tam;i++){
            if(destino[i].id==id){
                esValido=1;
                break;
            }
        }
    }
    return esValido;
}

int obtenerDescripcionDestino(int id, char descripcion[], eDestino destino[], int tam){
    int todoOk=1;
    if(destino!=NULL && tam>0 && descripcion!=NULL){
        for(int i=0;i<tam;i++){
            if(destino[i].id==id){
                strcpy(descripcion, destino[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}

int obtenerPrecioDestino(int id, float* precio, eDestino destino[], int tam){
    int todoOk=1;
    if(destino!=NULL && tam>0 && precio!=NULL){
        for(int i=0;i<tam;i++){
            if(destino[i].id==id){
                *precio = destino[i].precio;
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}

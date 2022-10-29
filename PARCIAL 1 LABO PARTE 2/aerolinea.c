#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aerolinea.h"

int mostrarAerolinea(eAerolinea aero[], int tam, int clear){

    int todoOk=0;
    if(aero!=NULL && tam>0 && clear>=0 && clear<=1){
        if(clear==1){
            system("cls");
        }
        printf("************ Lista de Aerolineas ***********\n\n");
        printf("Id                 Descripcion\n");
        printf("-----------------------------\n");
        for(int i=0;i<tam;i++){
            printf("%d        %20s\n", aero[i].id, aero[i].descripcion);
        }
        printf("\n\n");
    }
    return todoOk;
}

int obtenerDescripcionAerolinea(int id, char descripcion[], eAerolinea aero[], int tam){
    int todoOk=1;
    if(aero!=NULL && tam>0 && descripcion!=NULL){
        for(int i=0;i<tam;i++){
            if(aero[i].id==id){
                strcpy(descripcion, aero[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}



int validarIdAerolinea(int id, eAerolinea aero[], int tam){
    int esValido=0;
    if(aero!=NULL && tam>0 ){
        for(int i=0;i<tam;i++){
            if(aero[i].id==id){
                esValido=1;
                break;
            }
        }
    }
    return esValido;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int mostrarTipo(eTipo tipo[], int tam, int clear){

    int todoOk=0;
    if(tipo!=NULL && tam>0 && clear>=0 && clear<=1){
        if(clear==1){
            system("cls");
        }
        printf("*********** Lista de Tipos ***********\n\n");
        printf("Id                Descripcion\n");
        printf("-----------------------------\n");
        for(int i=0;i<tam;i++){
            printf("%d        %20s\n", tipo[i].id, tipo[i].descripcion);
        }
        printf("\n\n");
    }
    return todoOk;
}

int obtenerDescripcionTipo(int id, char descripcion[], eTipo tipo[], int tam){
    int todoOk=1;
    if(tipo!=NULL && tam>0 && descripcion!=NULL){
        for(int i=0;i<tam;i++){
            if(tipo[i].id==id){
                strcpy(descripcion, tipo[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}



int validarIdTipo(int id, eTipo tipo[], int tam){
    int esValido=0;
    if(tipo!=NULL && tam>0 ){
        for(int i=0;i<tam;i++){
            if(tipo[i].id==id){
                esValido=1;
                break;
            }
        }
    }
    return esValido;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"
char menu()
{
    char opcion;
    system("cls");

    printf(" *** ABM SERVICIO DE VUELOS ***\n");
    printf("A- Alta Avion\n");
    printf("B- Modificar Avion\n");
    printf("C- Baja Avion\n");
    printf("D- Listar Aviones\n");
    printf("E- Listar Aerolineas\n");
    printf("F- Listar Tipos\n");
    printf("G- Listar Destinos\n");
    printf("H- Alta Vuelo\n");
    printf("I- Listar Vuelos\n");
    printf("J- MENU INFORMES\n");
    printf("K- Salir\n");


    opcion = getCaracter("\nIngrese opcion: ");
    opcion = toupper(opcion);

    system("cls");

    return opcion;
}

int menuInformes(){
    int opcion;
    system("cls");

    printf(" *** MENU DE INFORMES ***\n");
    printf("1- Lista de aviones segun aerolinea\n");
    printf("2- Lista de aviones segun tipo\n");
    printf("3- Promedio de Aviones jet sobre el total de aviones de una aerolinea\n");
    printf("4- Listado de aviones, separados por aerolinea\n");
    printf("5- Aerolinea/s que pueden transportar mas pasajeros\n");
    printf("6- Aerolinea/s con menor cantidad de aviones\n");
    printf("7- Vuelos según avion\n");
    printf("8- Costo total en vuelos por avion\n");
    printf("9- Aviones y fecha segun destino\n");
    printf("10- Vuelos segun fecha\n");
    printf("11- Volver Atras");

   opcion = getEntero("\nIngrese opcion: ");

   system("cls");
    return opcion;
}


int getIntValid(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
    int num;
    int todoOk=0;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {

        printf("%s", mensaje);
        while(scanf("%d",&num)!=1 || num<minimo || num>maximo)
        {
            fflush(stdin);
            printf("%s", mensajeError);
            printf("%s", mensaje);
        }
        *pResultado = num;
        todoOk=1;
    }
    return todoOk;
}
int getIntValidMin(int* pResultado, char* mensaje, char* mensajeError, int minimo){
    int num;
    int todoOk=0;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {

        printf("%s", mensaje);
        while(scanf("%d",&num)!=1 || num<minimo)
        {
            fflush(stdin);
            printf("%s", mensajeError);
            printf("%s", mensaje);
        }
        *pResultado = num;
        todoOk=1;
    }
    return todoOk;


}

int getFloatValid(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo)
{
    float num;
    int todoOk=0;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        printf("%s", mensaje);
        while(scanf("%f",&num)!=1 || num<minimo || num>maximo)
        {
            fflush(stdin);
            printf("%s", mensajeError);
            printf("%s", mensaje);
        }
        *pResultado = num;
        todoOk=1;
    }
    return todoOk;
}


int getCharValid(char* pCaracter, char* mensaje, char* mensajeError, char caracterA, char caracterB)
{
    int todoOk=0;
    char caracter;
    if(pCaracter!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c", &caracter);
        *pCaracter = caracter;
        while(caracter!= caracterA && caracter!= caracterB)
        {
            printf("%s", mensajeError);
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &caracter);
            *pCaracter = caracter;
        }

        todoOk=1;
    }

    return todoOk;
}


int getString(char string[], char mensaje[], int tam)
{
    char auxString[1000];
    int todoOk=0;
    if (string != NULL && mensaje != NULL)
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%[^\n]", auxString);
        while (strlen(auxString) > tam)
        {
            printf("Reingrese: ");
            fflush(stdin);
            scanf("%[^\n]", auxString);
        }
        strcpy(string, auxString);
        todoOk=1;
    }
    return todoOk;
}

int getEntero(char mensaje[])
{
    int numeroIngresado;
    printf("%s", mensaje);
    scanf("%d", &numeroIngresado);
    return numeroIngresado;
}

float getFlotante(char mensaje[])
{
    float numeroIngresado;
    printf("%s", mensaje);
    scanf("%f", &numeroIngresado);
    return numeroIngresado;
}

char getCaracter(char mensaje[])
{
    char caracterIngresado;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &caracterIngresado);
    return caracterIngresado;
}

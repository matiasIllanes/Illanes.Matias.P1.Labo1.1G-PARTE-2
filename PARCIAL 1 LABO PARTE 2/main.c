#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"
#include "avion.h"
#include "vuelo.h"
#include "informes.h"


#define TAM_A 15
#define TAM_T 4
#define TAM_AE 5
#define TAM_D 4
#define TAM_V 15

int main()
{
    char salir = 'n';
    char salirInformes = 'n';
    eAvion aviones[TAM_A];
    eVuelo vuelos[TAM_V];
    int nextAvionId=100;
    int nextVueloId=0;
    int flagVuelo=0;
    int contAvion=0;

    eAerolinea aero[TAM_AE]=
    {
        {1000, "Lan"},
        {1001, "Iberia"},
        {1002, "Norgwegian"},
        {1003, "American"},
        {1004, "Austral"},
    };

    eTipo tipos[TAM_T]=
    {
        {5000, "Jet"},
        {5001, "Helice"},
        {5002, "Planeador"},
        {5003, "Carga"},
    };

    eDestino destinos[TAM_D]=
    {
        {20000, "Calafate", 22250},
        {20001, "Miami", 103000},
        {20002, "Milan", 84400},
        {20003, "Amsterdann", 95600},
    };


    inicializarAviones(aviones, TAM_A);

     hardcodearAviones(&nextAvionId, aviones, TAM_A, 11);
     contAvion=11;

    inicializarVuelos(vuelos, TAM_V);
    hardcodearVuelos(&nextVueloId, vuelos, TAM_V, 11);
    flagVuelo=1;

    do
    {
        switch(menu())
        {
        case 'A':
            if(altaAvion(&nextAvionId, aviones, aero, tipos, TAM_A, TAM_AE, TAM_T)==1)
            {
                printf("Alta Exitosa\n");
                contAvion++;
            }
            else
            {
                printf("Alta ERRONEA\n");
            }
            break;

        case 'B':
            if(contAvion==0)
            {
                printf("PRIMERO DEBE DAR DE ALTA UN AVION \n");
                break;
            }
            modificarAvion(aviones, aero, tipos, TAM_A, TAM_AE, TAM_T);
            break;
        case 'C':
            if(contAvion==0)
            {
                printf("PRIMERO DEBE DAR DE ALTA UN AVION \n");
                break;
            }
            bajaAvion(aviones, aero, tipos, TAM_A, TAM_AE, TAM_T);
            contAvion--;
            break;

        case 'D':

            mostrarAvionesCompleto(aviones, aero, tipos, TAM_A, TAM_AE, TAM_T, 1);

            break;
        case 'E':
            //LISTAR AEROLINEAS
            mostrarAerolinea(aero, TAM_AE, 1);
            break;
        case 'F':
            //LISTAR TIPOS
            mostrarTipo(tipos, TAM_T, 1);
            break;
        case 'G':
            //LISTAR DESTINOS
            mostrarDestino(destinos, TAM_D, 1);
            break;
        case 'H':
            if(contAvion==0)
            {
                printf("PRIMERO DEBE DAR DE ALTA UN AVION \n");
                break;
            }
            if(altaVuelo(&nextVueloId, vuelos, aviones, destinos, tipos, aero, TAM_V, TAM_A, TAM_D, TAM_T, TAM_AE)==1)
            {
                printf("Alta Exitosa");
                flagVuelo=1;
            }
            else
            {
                printf("Carga Erronea");
            }
            break;
        case 'I':
            if(contAvion==0 || flagVuelo==0)
            {
                printf("\nDEBE DAR DE ALTA EL AVION Y EL VUELO\n");
                break;
            }
            mostrarVuelos(vuelos, aviones, destinos, aero, tipos, TAM_V, TAM_D, TAM_A, TAM_AE, TAM_T, 1);
            break;
        case 'J':
            //INFORMES

            do
            {

                switch(menuInformes())
                {
                case 1: //Lista de aviones segun aerolinea
                    listarAvionesAerolinea(aviones, aero, tipos, TAM_A, TAM_AE, TAM_T);
                    break;

                case 2: //Lista de aviones segun tipo
                    listarAvionesTipo(aviones, aero, tipos, TAM_A, TAM_AE, TAM_T);
                    break;

                case 3: //Promedio de Aviones jet sobre el total de aviones de una aerolinea
                    mostrarPorcentajeJetAerolinea(aviones, aero, tipos, TAM_A, TAM_AE, TAM_T);
                    break;

                case 4: //Listado de aviones, separados por aerolinea
                    listarAvionesTodasAerolineas(aviones, aero, tipos, TAM_A, TAM_AE, TAM_T);
                    break;

                case 5: //Aerolinea/s que pueden transportar mas pasajeros
                    mostrarAerolineaMasPasajeros(aviones, aero, tipos, TAM_A, TAM_AE, TAM_T);
                    break;

                case 6: //Aerolinea/s con menor cantidad de aviones
                    mostrarAerolineaMenosAviones(aviones, aero, tipos, TAM_A, TAM_AE, TAM_T);
                    break;

                case 7: //Vuelos segun avion
                    listarVuelosAvion(vuelos, destinos, aviones, aero, tipos, TAM_V, TAM_D, TAM_A, TAM_AE, TAM_T);
                    break;

                case 8: //Costo total en vuelos por avion
                    mostrarPrecioVuelosAvion(vuelos, destinos, aviones, aero, tipos, TAM_V, TAM_D, TAM_A, TAM_AE, TAM_T);
                    break;

                case 9: //Aviones y fecha segun destino
                    break;

                case 10: //Vuelos segun fecha
                    printf("hola");

                    break;

                case 11:
                    salirInformes='s';
                    break;

                default:
                    printf("\nOpcion invalida\n");
                    break;

                }
                system("pause");
            }while(salirInformes == 'n');
            break;

        case 'K':
            salir='s';
            break;
        default:
            printf("OPCION INCORRECTA \n");
            break;
        }
        system("pause");
    }while(salir == 'n');
    return 0;
}






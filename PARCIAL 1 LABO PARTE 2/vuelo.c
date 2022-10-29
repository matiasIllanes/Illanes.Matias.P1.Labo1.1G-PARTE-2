#include "vuelo.h"
#include "destino.h"

int buscarLibreVuelo(int* pIndice, eVuelo vecVuelo[], int tamV)
{
    int todoOk=0;
    if(pIndice!=NULL && vecVuelo!=NULL && tamV>0)
    {
        *pIndice=-1;
        for(int i=0; i<tamV; i++)
        {

            if(vecVuelo[i].isEmpty==1)
            {
                *pIndice=i;
                break;
            }
        }

        todoOk=1;
    }
    return todoOk;
}

int inicializarVuelos(eVuelo vecVuelo[], int tamV)
{
    {
        int todoOk=0;
        if(vecVuelo!=NULL && tamV>0)
        {
            for(int i=0; i<tamV; i++)
            {
                vecVuelo[i].isEmpty=1;
            }
            todoOk=1;
        }
        return todoOk;
    }
}


int altaVuelo(int* pIdVuelo, eVuelo vecVuelo[], eAvion vecAvion[], eDestino vecDestino[], eTipo vecTipo[], eAerolinea vecAerolinea[], int tamV, int tamA, int tamD, int tamT, int tamAe)
{
    int todoOk=0;
    int indice;
    eVuelo auxVuelo;
    if(vecVuelo!=NULL && vecAvion!= NULL && vecDestino!=NULL && vecAerolinea!= NULL && vecAerolinea!=NULL && tamV>0 && tamA>0 && tamD && tamT>0 && tamAe>0)
    {
        buscarLibreVuelo(&indice, vecVuelo, tamV);
        if(indice==-1)
        {
            //NO HAY LUGAR PARA DAR DE ALTA
            printf("No hay lugar en el sistema para el alta\n");
        }
        else
        {
            auxVuelo.id = *pIdVuelo;

            //PIDO AVION
            mostrarAvionesCompleto(vecAvion, vecAerolinea, vecTipo, tamA, tamAe, tamT, 1);
            printf("Ingrese Id de Avion: ");
            scanf("%d", &auxVuelo.idAvion);
            while(validarIdAvion(auxVuelo.idAvion, vecAvion, tamA)==0)
            {
                printf("ERROR DE ID. Ingrese Id de avion: ");
                scanf("%d", &auxVuelo.idAvion);
            }

            //PIDO DESTINO
            mostrarDestino(vecDestino, tamD, 1);
            printf("Ingrese Id de Destino: ");
            scanf("%d", &auxVuelo.idDestino);

            while(validarIdDestino(auxVuelo.idDestino, vecDestino, tamD)==0)
            {
                printf("ERROR DE ID. Ingrese Id de destino: ");
                scanf("%d", &auxVuelo.idDestino);
            }
            //PIDO FECHA
            system("cls");
            printf("Ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d", &auxVuelo.fecha.dia, &auxVuelo.fecha.mes, &auxVuelo.fecha.anio);
            while(auxVuelo.fecha.dia>31 || auxVuelo.fecha.dia<1 || auxVuelo.fecha.mes<1 || auxVuelo.fecha.mes>12 || auxVuelo.fecha.anio>2022 || auxVuelo.fecha.anio<1950)
            {
                printf("ERROR.Ingrese una fecha valida dd/mm/aaaa : ");
                scanf("%d/%d/%d", &auxVuelo.fecha.dia, &auxVuelo.fecha.mes, &auxVuelo.fecha.anio);
            }

            auxVuelo.isEmpty = 0;
            vecVuelo[indice] = auxVuelo;

            *pIdVuelo = *pIdVuelo+1;
            todoOk=1;
        }
    }
    return todoOk;
}

void mostrarVueloFila (eVuelo vecVuelo, eAvion vecAvion[], eDestino vecDestino[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamD, int tamA, int tamAe, int tamT){
    char descripcionDestino[20];
    float precioDestino;
    char descripcionTipo[20];
    char descripcionAerolinea[20];
    int indiceAvion;

    buscarIndiceAvion(vecAvion, tamA, vecVuelo.idAvion, &indiceAvion);
    if(indiceAvion==-1){
        printf("\nNO HAY AVION\n");
    }
    else{
        obtenerDescripcionDestino(vecVuelo.idDestino, descripcionDestino, vecDestino, tamD);
        obtenerPrecioDestino(vecVuelo.idDestino, &precioDestino, vecDestino, tamD);
        obtenerDescripcionAerolinea(vecAvion[indiceAvion].idAerolinea, descripcionAerolinea, vecAerolinea, tamAe);
        obtenerDescripcionTipo(vecAvion[indiceAvion].idTipo, descripcionTipo, vecTipo, tamT);
        printf("%2d  %15s  %13s       %3d %15s   %02d/%02d/%04d     %6.2f\n", vecVuelo.id
                                                                                , descripcionAerolinea
                                                                                , descripcionTipo
                                                                                , vecAvion[indiceAvion].capacidad
																				, descripcionDestino
																				, vecVuelo.fecha.dia
																				, vecVuelo.fecha.mes
																				, vecVuelo.fecha.anio
																				, precioDestino);
    }
}




int mostrarVuelos(eVuelo vecVuelo[], eAvion vecAvion[], eDestino vecDestino[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamV, int tamD, int tamA, int tamAe, int tamT, int clear)
{

    int todoOk=0;
    int flag=1;

    if(vecVuelo!=NULL && vecAvion!=NULL && vecDestino!=NULL && vecAerolinea!=NULL && vecTipo!=NULL && tamV && tamA>0 && tamT>0 && tamAe>0 && clear>=0 && clear<=1)
    {
        if(clear==1)
        {
            system("cls");
        }

        printf("         **** Lista de Vuelos ****\n\n\n");
        printf("ID Vuelo   Aerolinea    Avion Tipo     Capacidad     Destino     Fecha       Precio\n");
        printf("----------------------------------------------------------------------------------------\n");
        for(int i=0; i<tamV; i++)
        {
            if(vecVuelo[i].isEmpty==0)
            {
                mostrarVueloFila(vecVuelo[i], vecAvion, vecDestino, vecAerolinea, vecTipo, tamD, tamA, tamAe, tamT);
                flag=0;
            }
        }
        if(flag==1)
        {
            printf("\n - No hay vuelos para listar - \n");
        }
        todoOk=1;
    }
    return todoOk;

}





int hardcodearVuelos(int* pId, eVuelo vecVuelo[], int tam, int cant)
{
    int todoOk=0;
    eVuelo vuelos[11]={
        {0, 106, 20001, {03,05,2015}},
        {1, 101, 20000, {15,05,2015}},
        {2, 103, 20002, {19,05,2022}},
        {3, 101, 20003, {15,05,2014}},
        {4, 106, 20002, {19,12,2021}},
        {5, 104, 20000, {11,10,2018}},
        {6, 101, 20002, {19,07,2020}},
        {7, 102, 20001, {01,01,2011}},
        {8, 107, 20000, {06,05,2022}},
        {9, 108, 20003, {16,02,2016}},
        {10, 109, 20001, {07,11,2017}}
        };


    if(pId!=NULL && vecVuelo!=NULL && tam>0 && cant<=tam )
    {
        for(int i=0; i<cant; i++)
        {
            vecVuelo[i] = vuelos[i];
            *pId = *pId+1;
        }
        todoOk=1;
    }
    return todoOk;
}


#include "informes.h"

int listarAvionesAerolinea(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT)
{
    int auxIdAero;
    int flag=0;
    int todoOk=0;
    char auxDescripcionAero[20];

    system("cls");
    printf("*** AVIONES SEGUN AEROLINEA ***\n\n");
    mostrarAerolinea(vecAerolinea, tamAe, 0);


    printf("Ingrese Id de Aerolinea: ");
    scanf("%d", &auxIdAero);

    while(validarIdAerolinea(auxIdAero, vecAerolinea, tamAe)==0)
    {
        printf("ERROR DE ID. Ingrese Id de Aerolinea: ");
        scanf("%d", &auxIdAero);
    }

    system("cls");
    if(vecAvion!=NULL && vecAerolinea!=NULL && vecTipo!=NULL && tamA>0 && tamAe>0 && tamT>0)
    {
        printf("ID AVION   AEROLINEA      TIPO AVION     CAPACIDAD\n");
        printf("---------------------------------------------------------\n");
        for(int i=0; i<tamA; i++)
        {
            if(vecAvion[i].isEmpty == 0 && vecAvion[i].idAerolinea == auxIdAero)
            {
                mostrarAvionFila(vecAvion[i], vecAerolinea, vecTipo, tamAe, tamT);
                flag=1;
            }
        }
        if(flag==0)
        {
            obtenerDescripcionAerolinea(auxIdAero,auxDescripcionAero,vecAerolinea, tamAe);
            printf("\n\nNo hay aviones de: %s\n\n", auxDescripcionAero);
        }

        todoOk=1;
    }
    return todoOk;
}

int listarAvionesTipo(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT)
{
    int auxIdTipo;
    int flag=0;
    int todoOk=0;
    char auxDescripcionTipo[20];

    system("cls");
    printf("*** AVIONES SEGUN TIPO ***\n\n");
    mostrarTipo(vecTipo, tamT, 0);

    printf("Ingrese Id de Tipo: ");
    scanf("%d", &auxIdTipo);

    while(validarIdTipo(auxIdTipo, vecTipo, tamT)==0)
    {
        printf("ERROR DE ID. Ingrese Id de Tipo: ");
        scanf("%d", &auxIdTipo);
    }
    system("cls");
    if(vecAvion!=NULL && vecAerolinea!=NULL && vecTipo!=NULL && tamA>0 && tamAe>0 && tamT>0)
    {
        printf("ID AVION   AEROLINEA      TIPO AVION     CAPACIDAD\n");
        printf("---------------------------------------------------------\n");
        for(int i=0; i<tamA; i++)
        {
            if(vecAvion[i].isEmpty == 0 && vecAvion[i].idTipo == auxIdTipo)
            {
                mostrarAvionFila(vecAvion[i], vecAerolinea, vecTipo, tamAe, tamT);
                flag=1;
            }
        }
        if(flag==0)
        {
            obtenerDescripcionTipo(auxIdTipo,auxDescripcionTipo,vecTipo, tamT);
            printf("\n\nNo hay aviones de: %s\n\n", auxDescripcionTipo);
        }

        todoOk=1;
    }
    return todoOk;
}



int mostrarPorcentajeJetAerolinea(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT)
{
    int auxIdAero;
    int flag=0;
    int todoOk=0;
    int contJet=0;
    int contAero=0;
    float porcentaje;
    system("cls");
    printf("*** PORCENTAJE DE AVIONES JET SEGUN AEROLINEA ***\n\n");
    mostrarAerolinea(vecAerolinea, tamAe, 0);

    getIntValidMin(&auxIdAero, "\nIngrese ID de Aerolinea: ", "ERROR. ", 1000);
    system("cls");
    if(vecAvion!=NULL && vecAerolinea!=NULL && vecTipo!=NULL && tamA>0 && tamAe>0 && tamT>0)
    {

        for(int i=0; i<tamA; i++)
        {
            if(vecAvion[i].isEmpty == 0 && vecAvion[i].idAerolinea == auxIdAero && vecAvion[i].idTipo == 5000)
            {
                contJet++;
                flag=1;
            }
            if(vecAvion[i].isEmpty == 0 && vecAvion[i].idAerolinea == auxIdAero)
            {
                contAero++;
            }
        }
        if(flag==0)
        {
            printf("\n\nNo hay aviones tipo Jet\n\n");
        }
        else
        {
            porcentaje = (float)contJet/contAero*100;
            printf("El porcentaje de aviones tipo Jet segun la aerolinea seleccionada es: %.2f\n\n", porcentaje);
        }

        todoOk=1;
    }
    return todoOk;
}



int listarAvionesTodasAerolineas(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT)
{
    int flag=0;
    int todoOk=0;
    system("cls");
    printf("*** AVIONES DE CADA AEROLINEA   AEROLINEA ***\n\n");

    if(vecAvion!=NULL && vecAerolinea!=NULL && vecTipo!=NULL && tamA>0 && tamAe>0 && tamT>0)
    {

        for(int i=0; i<tamAe; i++)
        {
            flag=0;
            printf("\n\n******************Aviones de: %s\n", vecAerolinea[i].descripcion);
            printf("ID AVION   AEROLINEA      TIPO AVION     CAPACIDAD\n");
            printf("---------------------------------------------------------\n");
            for(int j=0; j<tamA; j++)
            {
                if(vecAvion[j].isEmpty == 0 && vecAvion[j].idAerolinea == vecAerolinea[i].id)
                {
                    mostrarAvionFila(vecAvion[j], vecAerolinea, vecTipo, tamAe, tamT);
                    flag=1;
                }
            }
            if(flag==0)
            {
                printf("\nNo hay aviones de: %s\n", vecAerolinea[i].descripcion);
            }
        }
        todoOk=1;

    }
    return todoOk;
}



int mostrarAerolineaMasPasajeros(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT)
{
    int todoOk=0;
    int contadorPasajeros[]= {0,0,0,0,0};
    int mayor;

    system("cls");
    printf("*** AEROLINEA/s CON MAS PASAJEROS ***\n\n");

    if(vecAvion!=NULL && vecAerolinea!=NULL && vecTipo!=NULL && tamA>0 && tamAe>0 && tamT>0)
    {

        for (int i=0; i<tamAe; i++)
        {
            for(int j=0; j<tamA; j++)
            {
                if(vecAvion[j].isEmpty==0 && vecAvion[j].idAerolinea==vecAerolinea[i].id){
                    contadorPasajeros[i] = contadorPasajeros[i] + vecAvion[j].capacidad;

                }
            }
        }

        for(int i=0; i<tamAe; i++)
        {
            if(i==0 || contadorPasajeros[i]>mayor)
            {
                mayor = contadorPasajeros[i];
            }
        }

        for(int i=0; i<tamAe; i++)
        {
            if(contadorPasajeros[i]==mayor)
            {
                printf("%s  --> Capacidad Total: %d\n", vecAerolinea[i].descripcion, mayor);
            }
        }

        todoOk=1;

    }
    return todoOk;
}


int mostrarAerolineaMenosAviones(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT)
{
    int todoOk=0;
    int contadorAviones[]= {0,0,0,0,0};
    int menor;

    system("cls");
    printf("*** AEROLINEA/s CON MENOS AVIONES ***\n\n");

    if(vecAvion!=NULL && vecAerolinea!=NULL && vecTipo!=NULL && tamA>0 && tamAe>0 && tamT>0)
    {

        for (int i=0; i<tamAe; i++)
        {
            for(int j=0; j<tamA; j++)
            {
                if(vecAvion[j].isEmpty==0 && vecAvion[j].idAerolinea==vecAerolinea[i].id)
                {
                    contadorAviones[i]++;
                }
            }

        }

        for(int i=0; i<tamAe; i++)
        {
            if(i==0 || contadorAviones[i]<menor)
            {
                menor = contadorAviones[i];
            }
        }

        for(int i=0; i<tamAe; i++)
        {
            if(contadorAviones[i]==menor)
            {
                printf("%s  --> Aviones: %d\n", vecAerolinea[i].descripcion, menor);
            }
        }

        todoOk=1;

    }
    return todoOk;
}


int listarVuelosAvion(eVuelo vecVuelo[], eDestino vecDestino[], eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamV, int tamD, int tamA, int tamAe, int tamT)
{
    int auxIdAvion;
    int flag=0;
    int todoOk=0;

    system("cls");
    printf("*** VUELOS SEGUN AVION ***\n\n");
    mostrarAvionesCompleto(vecAvion, vecAerolinea, vecTipo, tamA, tamAe, tamT, 0);

    printf("Ingrese Id de Avion: ");
    scanf("%d", &auxIdAvion);

    while(validarIdAvion(auxIdAvion, vecAvion, tamA)==0)
    {
        printf("ERROR DE ID. Ingrese Id de Avion: ");
        scanf("%d", &auxIdAvion);
    }

    system("cls");
    if(vecAvion!=NULL && vecAerolinea!=NULL && vecTipo!=NULL && tamA>0 && tamAe>0 && tamT>0)
    {
        printf("*** VUELOS SEGUN AVION ***\n\n");
        printf("ID Vuelo   Aerolinea    Avion Tipo     Capacidad     Destino     Fecha       Precio\n");
        printf("----------------------------------------------------------------------------------------\n");
        for(int i=0; i<tamV; i++)
        {
            if(vecVuelo[i].isEmpty == 0 && vecVuelo[i].idAvion == auxIdAvion)
            {
                mostrarVueloFila(vecVuelo[i], vecAvion, vecDestino, vecAerolinea, vecTipo, tamD, tamA, tamAe, tamT);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("\n\nNo hay vuelos \n\n");
        }

        todoOk=1;
    }
    return todoOk;
}

int mostrarPrecioVuelosAvion(eVuelo vecVuelo[], eDestino vecDestino[], eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamV, int tamD, int tamA, int tamAe, int tamT)
{
    int auxIdAvion;
    int todoOk=0;
    float acumPrecio=0;
    float auxPrecio;

    system("cls");
    printf("*** COSTO ACUMULADO SEGUN AVION ***\n\n");
    mostrarAvionesCompleto(vecAvion, vecAerolinea, vecTipo, tamA, tamAe, tamT, 0);

    printf("Ingrese Id de Avion: ");
    scanf("%d", &auxIdAvion);

    while(validarIdAvion(auxIdAvion, vecAvion, tamA)==0)
    {
        printf("ERROR DE ID. Ingrese Id de Avion: ");
        scanf("%d", &auxIdAvion);
    }

    system("cls");
    if(vecAvion!=NULL && vecAerolinea!=NULL && vecTipo!=NULL && tamA>0 && tamAe>0 && tamT>0)
    {
        for(int i=0; i<tamV; i++)
        {
            if(vecVuelo[i].isEmpty == 0 && vecVuelo[i].idAvion == auxIdAvion)
            {
                obtenerPrecioDestino(vecVuelo[i].idDestino, &auxPrecio, vecDestino, tamD);

                acumPrecio = acumPrecio+auxPrecio;
            }
        }
        printf("El precio acumulado es: %.2f \n", acumPrecio);

        todoOk=1;
    }
    return todoOk;
}


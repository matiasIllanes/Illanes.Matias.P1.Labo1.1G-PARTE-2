#include "avion.h"


int inicializarAviones(eAvion vecAvion[], int tamA)
{
    {
        int todoOk=0;
        if(vecAvion!=NULL && tamA>0)
        {
            for(int i=0; i<tamA; i++)
            {
                vecAvion[i].isEmpty=1;
            }
            todoOk=1;
        }
        return todoOk;
    }
}

int buscarLibre(int* pIndice, eAvion vecAvion[], int tamA)
{
    int todoOk=0;
    if(pIndice!=NULL && vecAvion!=NULL && tamA>0)
    {
        *pIndice=-1;
        for(int i=0; i<tamA; i++)
        {

            if(vecAvion[i].isEmpty==1)
            {
                *pIndice=i;
                break;
            }
        }

        todoOk=1;
    }
    return todoOk;
}


int altaAvion(int* pIdAvion, eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT)
{
    int todoOk=0;
    int indice;
    eAvion auxAvion;
    if(vecAvion!=NULL && vecAerolinea!= NULL && vecAerolinea!=NULL && tamA>0 && tamT>0 && tamAe>0)
    {
        buscarLibre(&indice, vecAvion, tamA);
        if(indice==-1)
        {
            //NO HAY LUGAR PARA DAR DE ALTA
            printf("No hay lugar en el sistema para el alta\n");
        }
        else
        {
            auxAvion.id = *pIdAvion;

            //PIDO TIPO
            mostrarTipo(vecTipo, tamT, 1);
            printf("Ingrese Id de tipo: ");
            scanf("%d", &auxAvion.idTipo);
            while(validarIdTipo(auxAvion.idTipo, vecTipo, tamT)==0)
            {
                printf("ERROR DE ID. Ingrese Id de tipo: ");
                scanf("%d", &auxAvion.idTipo);
            }

            //PIDO AEROLINEA
            mostrarAerolinea(vecAerolinea, tamAe, 1);
            printf("Ingrese Id de Aerolinea: ");
            scanf("%d", &auxAvion.idAerolinea);

            while(validarIdAerolinea(auxAvion.idAerolinea, vecAerolinea, tamAe)==0)
            {
                printf("ERROR DE ID. Ingrese Id de Aerolinea: ");
                scanf("%d", &auxAvion.idAerolinea);
            }
            //PIDO CAPACIDAD
            getIntValid(&auxAvion.capacidad, "Ingrese Capacidad (10-300): ", "Capacidad Incorrecta. ", 10, 300);

            auxAvion.isEmpty = 0;
            vecAvion[indice] = auxAvion;

            *pIdAvion = *pIdAvion+1;
            todoOk=1;
        }
    }
    return todoOk;
}


void mostrarUnAvion (eAvion vecAvion, eAerolinea vecAerolinea[], eTipo vecTipo[], int tamAe, int tamT)
{
    char descripcionAerolinea[20];
    char descripcionTipo[20];
    obtenerDescripcionAerolinea(vecAvion.idAerolinea, descripcionAerolinea, vecAerolinea, tamAe);
    obtenerDescripcionTipo(vecAvion.idTipo, descripcionTipo, vecTipo, tamT);


    printf(" \n\nID: %d \n Aerolinea: %s\n Tipo: %s\n Capacidad: %d \n\n\n"


           , vecAvion.id
           , descripcionAerolinea
           , descripcionTipo
           , vecAvion.capacidad);
}



void mostrarAvionFila (eAvion vecAvion, eAerolinea vecAerolinea[], eTipo vecTipo[], int tamAe, int tamT)
{
    char descripcionAerolinea[20];
    char descripcionTipo[20];

    obtenerDescripcionAerolinea(vecAvion.idAerolinea, descripcionAerolinea, vecAerolinea, tamAe);
    obtenerDescripcionTipo(vecAvion.idTipo, descripcionTipo, vecTipo, tamT);


    printf("%d     %10s       %10s      %3d \n"
           , vecAvion.id
           , descripcionAerolinea
           , descripcionTipo
           , vecAvion.capacidad);
}


int mostrarAvionesCompleto (eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT, int clear)
{

    int todoOk=0;
    int flag=1;

    if(vecAvion!=NULL && vecAerolinea!= NULL && vecAerolinea!=NULL && tamA>0 && tamT>0 && tamAe>0 && clear>=0 && clear<=1)
    {
        if(clear==1)
        {
            system("cls");
        }

        printf("         **** Lista de a Aviones ****\n\n\n");
        printf("ID       Aerolinea         Tipo     Capacidad\n");
        printf("--------------------------------------------------------\n");
        for(int i=0; i<tamA; i++)
        {
            if(vecAvion[i].isEmpty==0)
            {
                mostrarAvionFila(vecAvion[i], vecAerolinea, vecTipo, tamAe, tamT);
                flag=0;
            }
        }
        if(flag==1)
        {
            printf("\n - No hay Aviones para listar - \n");
        }
        todoOk=1;
    }
    return todoOk;

}


int ordenarAvionAerolineaCapacidad(eAvion aviones[], int tam)
{
    int todoOk = 0;
    eAvion auxAvion;
    if (aviones != NULL && tam > 0)
    {
        for (int i=0; i < tam -1; i++)
        {
            for (int j=i+1; j < tam; j++)
            {
                if ((aviones[i].idAerolinea > aviones[j].idAerolinea)  ||
                        (aviones[i].idAerolinea == aviones[j].idAerolinea && aviones[i].capacidad > aviones[j].capacidad))
                {
                    auxAvion = aviones[i];
                    aviones[i] = aviones[j];
                    aviones[j] = auxAvion;
                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}


int hardcodearAviones(int* pId, eAvion vecAviones[], int tam, int cant)
{
    int todoOk=0;
    eAvion aviones[11]=
    {
        {100, 1003, 5000, 150},
        {101, 1001, 5001, 250},
        {102, 1004, 5001, 350},
        {103, 1002, 5003, 50},
        {104, 1000, 5002, 75},
        {105, 1001, 5000, 100},
        {106, 1002, 5001, 85},
        {107, 1001, 5002, 170},
        {108, 1004, 5001, 200},
        {109, 1004, 5002, 250},
        {110, 1001, 5001, 280},
    };

    if(pId!=NULL && vecAviones!=NULL && tam>0 && cant<=tam )
    {
        for(int i=0; i<cant; i++)
        {
            vecAviones[i] = aviones[i];
            *pId = *pId+1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarAvion(int id, int* pIndice, eAvion vec[], int tam)
{

    int todoOk=0;
    if(pIndice!=NULL && vec!=NULL && tam>0)
    {
        *pIndice=-1;
        for(int i=0; i<tam; i++)
        {
            if(vec[i].isEmpty==0 && vec[i].id==id)
            {
                *pIndice=i;
                break;
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int modificarAvion(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT)
{
    int todoOk=0;
    int indice;
    int id;
    char confirma;

    int auxIdTipo;
    int auxCapacidad;

    if(vecAvion!=NULL && vecAerolinea!= NULL && vecTipo!=NULL && tamA>0 && tamAe>0 && tamT>0)
    {

        mostrarAvionesCompleto(vecAvion, vecAerolinea, vecTipo, tamA, tamAe, tamT, 1);

        getIntValidMin(&id, "Ingrese id que necesita modificar: ", "ERROR.", 0);


        buscarAvion(id, &indice, vecAvion, tamA);
        if(indice==-1)
        {
            printf("No existe avion con ID: %d\n", id);
        }
        else
        {
            mostrarUnAvion(vecAvion[indice], vecAerolinea, vecTipo, tamAe, tamT);

            getCharValid(&confirma, "Seguro desea realizar la modificacion ?s/n:  ", "ERROR. ", 's', 'n');

            if(confirma== 's')
            {
                system("cls");
                printf("Ingrese dato a modificar (ID: %d)\n\n", vecAvion[indice].id);
                switch(menuModificacion())
                {
                case 1:
                    printf("\n");

                    mostrarTipo(vecTipo, tamT, 1);
                    printf("Ingrese Id de tipo: ");
                    scanf("%d", &auxIdTipo);
                    while(validarIdTipo(auxIdTipo, vecTipo, tamT)==0)
                    {
                        printf("ERROR DE ID. Ingrese Id de tipo: ");
                        scanf("%d", &auxIdTipo);
                    }
                    vecAvion[indice].idTipo = auxIdTipo;
                    break;
                case 2:
                    getIntValid(&auxCapacidad, "Ingrese Capacidad (10-300): ", "Capacidad Incorrecta. ", 10, 300);
                    vecAvion[indice].capacidad = auxCapacidad;

                    break;
                default:
                    printf("Opcion invalida");
                }

            }
            else
            {
                printf("Se ha cancelado la Modificacion");
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int menuModificacion()
{
    int opcion;
    printf("   1-Tipo\n");
    printf("   2-Capacidad\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int bajaAvion(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT)
{
    int todoOk=0;
    int indice;
    int id;
    char confirma;

    if(vecAvion!=NULL && vecAerolinea!= NULL && vecTipo!=NULL && tamA>0 && tamAe>0 && tamT>0)
    {

        mostrarAvionesCompleto(vecAvion, vecAerolinea, vecTipo, tamA, tamAe, tamT, 1);

        getIntValidMin(&id, "Ingrese id que necesita dar de baja: ", "ERROR.", 0);


        buscarAvion(id, &indice, vecAvion, tamA);
        if(indice==-1)
        {
            printf("No existe avion con ID: %d\n", id);
        }
        else
        {
            mostrarUnAvion(vecAvion[indice], vecAerolinea, vecTipo, tamAe, tamT);

            getCharValid(&confirma, "Seguro desea realizar la baja ?s/n:  ", "ERROR. ", 's', 'n');

            if(confirma== 's')
            {
                vecAvion[indice].isEmpty=1;
                printf("\n Baja Exitosa! \n");
            }
            else
            {
                printf("Se ha cancelado la baja");
            }
        }
        todoOk=1;
    }
    return todoOk;
}


int validarIdAvion(int id, eAvion avion[], int tam)
{
    int esValido=0;
    if(avion!=NULL && tam>0 )
    {
        for(int i=0; i<tam; i++)
        {
            if(avion[i].id==id)
            {
                esValido=1;
                break;
            }
        }
    }
    return esValido;
}

int buscarIndiceAvion(eAvion vecAvion[], int tam, int id, int* pIndex)
{
    int todoOk=0;

    if(pIndex!=NULL && vecAvion!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(vecAvion[i].id == id)
            {
                *pIndex = i;
                todoOk=1;
            }
            else
            {
                todoOk=-1;
            }
        }
        return todoOk;
    }
}

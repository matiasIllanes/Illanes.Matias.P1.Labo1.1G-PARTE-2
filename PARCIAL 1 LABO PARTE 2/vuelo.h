#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED
#include "fecha.h"
#include "avion.h"

typedef struct{
    int id;
    int idAvion;
    int idDestino;
    eFecha fecha;
    int isEmpty;

}eVuelo;

/** \brief -> Inicializa los campos isEmpty en 1
 *
 * \param vecVuelo[]
 * \param tamV int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int inicializarVuelos(eVuelo vecVuelo[], int tamV);

/** \brief -> Busca la primer posicion vacia del vector
 *
 * \param pIndice int* -> Puntero Indice
 * \param vecVuelo[] eVuelo
 * \param tamV int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int buscarLibreVuelo(int* pIndice, eVuelo vecVuelo[], int tamV);
/** \brief  -> Da de alta un vuelo
 *
 * \param pIdVuelo int*  -> Puntero ID VUELO
 * \param vecVuelo[] eVuelo
 * \param vecAvion[] eAvion
 * \param vecDestino[] eDestino
 * \param vecTipo[] eTipo
 * \param vecAerolinea[] eAerolinea
 * \param tamV int
 * \param tamA int
 * \param tamD int
 * \param tamT int
 * \param tamAe int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int altaVuelo(int* pIdVuelo, eVuelo vecVuelo[], eAvion vecAvion[], eDestino vecDestino[], eTipo vecTipo[], eAerolinea vecAerolinea[], int tamV, int tamA, int tamD, int tamT, int tamAe);
void mostrarVueloFila (eVuelo vecVuelo, eAvion vecAvion[], eDestino vecDestino[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamD, int tamA, int tamAe, int tamT);
/** \brief -> Muestra el listado de todos los vuelos
 *
 * \param vecVuelo[] eVuelo
 * \param vecAvion[] eAvion
 * \param vecDestino[] eDestino
 * \param vecAerolinea[] eAerolinea
 * \param vecTipo[] eTipo
 * \param tamV int
 * \param tamD int
 * \param tamA int
 * \param tamAe int
 * \param tamT int
 * \param clear int -> 0 Si se quiere borrar la pantalla antes de informar, caso contrario: 1
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int mostrarVuelos(eVuelo vecVuelo[], eAvion vecAvion[], eDestino vecDestino[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamV, int tamD, int tamA, int tamAe, int tamT, int clear);

/** \brief Hardcodea lista de vuelos
 *
 * \param pId int* -> Puntero ID Inicial Vuelo
 * \param vecVuelo[] eVuelo
 * \param tam int
 * \param cant int -> Cantidad de vuelos a mostrar
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int hardcodearVuelos(int* pId, eVuelo vecVuelo[], int tam, int cant);

#endif // VUELO_H_INCLUDED



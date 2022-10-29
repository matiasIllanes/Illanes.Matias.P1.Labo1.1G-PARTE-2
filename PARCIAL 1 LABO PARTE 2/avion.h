#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"
#include "aerolinea.h"
#include "destino.h"
#include "tipo.h"




typedef struct{
    int id;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int isEmpty;
}eAvion;




/** \brief -> Inicializa los campos isEmpty en 1
 *
 * \param vecAvion[] eAvion
 * \param tamA int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int inicializarAviones(eAvion vecAvion[], int tamA);

/** \brief -> Busca la primer posicion vacia del vector
 *
 * \param pIndice int*
 * \param vecAvion[] eAvion
 * \param tamA int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int buscarLibre(int* pIndice, eAvion vecAvion[], int tamA);

/** \brief -> Da de alta un avion
 *
 * \param pIdAvion int* -> Puntero ID Avion
 * \param vecAvion[] eAvion
 * \param vecAerolinea[] eAerolinea
 * \param vecTipo[] eTipo
 * \param tamA int
 * \param tamAe int
 * \param tamT int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int altaAvion(int* pIdAvion, eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT);

/** \brief Muestra un avion en formato lista
 *
 * \param vecAvion[] eAvion
 * \param vecAerolinea[] eAerolinea
 * \param vecTipo[] eTipo
 * \param tamA int
 * \param tamAe int
 * \param tamT int
 * \return void
 *
 */
void mostrarUnAvion (eAvion vecAvion, eAerolinea vecAerolinea[], eTipo vecTipo[], int tamAe, int tamT);

/** \brief Muestra un avion en formato fila
 *
 * \param vecAvion[] eAvion
 * \param vecAerolinea[] eAerolinea
 * \param vecTipo[] eTipo
 * \param tamA int
 * \param tamAe int
 * \param tamT int
 * \return void
 *
 */
void mostrarAvionFila (eAvion vecAvion, eAerolinea vecAerolinea[], eTipo vecTipo[], int tamAe, int tamT);

/** \brief Muestra Todos los aviones en formato fila y columna
 *
 * \param vecAvion[] eAvion
 * \param vecAerolinea[] eAerolinea
 * \param vecTipo[] eTipo
 * \param tamA int
 * \param tamAe int
 * \param tamT int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int mostrarAvionesCompleto (eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT, int clear);

/** \brief Ordena aviones por nombre, y en caso de igualdad los ordena por capacidad
 *
 * \param aviones[] eAvion
 * \param tam int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int ordenarAvionAerolineaCapacidad(eAvion aviones[], int tam);

/** \brief hardcodea Lista Aviones
 *
 * \param pId int* -> Puntero ID Inicial aviones
 * \param vecAviones[] eAvion
 * \param tam int
 * \param cant int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int hardcodearAviones(int* pId, eAvion vecAviones[], int tam, int cant);

/** \brief Busca avion por ID y guarda el indice
 *
 * \param id int -> ID A buscar
 * \param pIndice int* -> Puntero Indice
 * \param vec[] eAvion
 * \param tam int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int buscarAvion(int id, int* pIndice, eAvion vec[], int tam);

/** \brief Modifica un avion
 *
 * \param vecAvion[] eAvion
 * \param vecAerolinea[] eAerolinea
 * \param vecTipo[] eTipo
 * \param tamA int
 * \param tamAe int
 * \param tamT int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int modificarAvion(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT);

/** \brief Menu para la modificacion
 *
 * \return int -> Devuelve opcion
 *
 */
int menuModificacion();

/** \brief  Da de baja un avion
 *
 * \param vecAvion[] eAvion
 * \param vecAerolinea[] eAerolinea
 * \param vecTipo[] eTipo
 * \param tamA int
 * \param tamAe int
 * \param tamT int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int bajaAvion(eAvion vecAvion[], eAerolinea vecAerolinea[], eTipo vecTipo[], int tamA, int tamAe, int tamT);
int buscarIndiceAvion(eAvion vecAvion[], int tam, int id, int* pIndex);

/** \brief Busca en el vector si la ID Recibida es valida.
 *
 * \param id int
 * \param avion[] eAvion
 * \param tam int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int validarIdAvion(int id, eAvion avion[], int tam);

#endif // AVION_H_INCLUDED



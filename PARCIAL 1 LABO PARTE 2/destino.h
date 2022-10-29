#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED
#include "avion.h"

typedef struct{
    int id;
    char descripcion[25];
    float precio;
}eDestino;

/** \brief Muestra listado de destinos
 *
 * \param destino[] eDestino
 * \param tam int
 * \param clear int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int mostrarDestino(eDestino destino[], int tam, int clear);

/** \brief Busca en el vector si la ID Recibida es valida.
 *
 * \param id int
 * \param destino[] eDestino
 * \param tam int
 * \return int Retorna 1 si la ID es valida, caso contrario retorna 0
 *
 */
int validarIdDestino(int id, eDestino destino[], int tam);

/** \brief -> Carga en un vector, la descripcion tipo
 *
 * \param id int
 * \param descripcion[] char
 * \param destino[] eDestino
 * \param tam int
 * \return int int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int obtenerDescripcionDestino(int id, char descripcion[], eDestino destino[], int tam);

/** \brief -> Carga en una variable el precio de un destino a partir del id
 *
 * \param id int
 * \param precio float*
 * \param destino[] eDestino
 * \param tam int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int obtenerPrecioDestino(int id, float* precio, eDestino destino[], int tam);
#endif // DESTINO_H_INCLUDED

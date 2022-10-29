#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eAerolinea;

/** \brief -> Muestra listado de aerolineas
 *
 * \param aero[] eAerolinea
 * \param tam int
 * \param clear int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int mostrarAerolinea(eAerolinea aero[], int tam, int clear);

/** \brief -> Carga en un vector, la descripcion aerolinea
 *
 * \param id int
 * \param descripcion[] char
 * \param aero[] eAerolinea
 * \param tam int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int obtenerDescripcionAerolinea(int id, char descripcion[], eAerolinea aero[], int tam);

/** \brief -> Busca en el vector si la ID Recibida es valida.
 *
 * \param id int
 * \param aero[] eAerolinea
 * \param tam int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int validarIdAerolinea(int id, eAerolinea aero[], int tam);



#endif // AEROLINEA_H_INCLUDED

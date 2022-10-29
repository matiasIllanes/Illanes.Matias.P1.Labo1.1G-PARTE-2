#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED
typedef struct{
    int id;
    char descripcion[20];
}eTipo;

/** \brief Muestra listado de tipos de aviones
 *
 * \param tipo[]
 * \param tam int
 * \param clear int -> 0 Si se quiere borrar la pantalla antes de informar, caso contrario: 1
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int mostrarTipo(eTipo tipo[], int tam, int clear);

/** \brief Carga en un vector, la descripcion tipo
 *
 * \param id int
 * \param descripcion[] char
 * \param tipo[] eTipo
 * \param tam int
 * \return int ->Devuelve 0 si hubo algun error, caso contrario retorna 1
 *
 */
int obtenerDescripcionTipo(int id, char descripcion[], eTipo tipo[], int tam);

/** \brief Busca en el vector si la ID Recibida es valida.
 *
 * \param id int
 * \param tipo[] eTipo
 * \param tam int
 * \return int Retorna 1 si la ID es valida, caso contrario retorna 0
 *
 */
int validarIdTipo(int id, eTipo tipo[], int tam);



#endif // TIPO_H_INCLUDED

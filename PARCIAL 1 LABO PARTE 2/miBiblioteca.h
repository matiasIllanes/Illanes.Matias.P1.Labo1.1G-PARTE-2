

/** \brief -> Muestra menu  Principal y recibe opcion
 *
 * \return char -> Devuelve letra ingresada
 *
 */
char menu();
/** \brief -> Muestra menu Informes y recibe opcion
 *
 * \return int -> Devuelve Entero Ingresado
 *
 */
int menuInformes();


/** \brief Recibe un entero y valida entre minimo y maximo
 *
 * \param pResultado -> int* Puntero Resultado
 * \param mensaje char* ->Mensaje, solicitud dato
 * \param mensajeError char* -> Mensaje de error
 * \param minimo int -> Minimo
 * \param maximo int ->Maximo
 * \return int 1 Si salio todo Ok, caso contrario retorna 0
 *
 */

int getIntValid(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);
/** \brief Recibe un float y valida entre minimo y maximo
 *
 * \param pResultado -> int* Puntero Resultado
 * \param mensaje char* ->Mensaje, solicitud dato
 * \param mensajeError char* -> Mensaje de error
 * \param minimo int -> Minimo
 * \param maximo int ->Maximo
 * \return int -> Retorna 1 Si salio todo Ok, caso contrario retorna 0
 *
 */
int getFloatValid(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo);
/** \brief Recibe un caracter y valida entre dos opciones
 *
 * \param pCaracter char* -> Puntero caracter
 * \param mensaje char* -> Mensaje solicitud caracter
 * \param mensajeError char* -> Mensaje de error
 * \param caracterA char -> Caracater A
 * \param caracterB char -> Caracter B
 * \return int ->Retorna 1 Si salio todo Ok, caso contrario retorna 0
 *
 */
int getCharValid(char* pCaracter, char* mensaje, char* mensajeError, char caracterA, char caracterB);
/** \brief -> Pide cadena de caracteres
 *
 * \param string[] char ->  cadena de caracteres
 * \param mensaje[] char ->  Mensaje
 * \param tam int -> tamaño de la cadena
 * \return int ->Retorna 1 Si salio todo Ok, caso contrario retorna 0
 *
 */
int getString(char string[], char mensaje[], int tam);
/** \brief Toma un entero
 *
 * \param mensaje[] char -> Mensaje
 * \return int -> Retorna el entero
 *
 */
int getEntero(char mensaje[]);
/** \brief Toma un flotante
 *
 * \param mensaje[] char  -> Mensaje
 * \return float -> Retorna el flotante
 *
 */
float getFlotante(char mensaje[]);
/** \brief Toma un caracter
 *
 * \param mensaje[] char -> Mensaeje de solicitud
 * \return char -> Retorna el caracter
 *
 */
char getCaracter(char mensaje[]);

/** \brief Pide un caracter y lo valida con un minimo
 *
 * \param pResultado int* -> Puntero Caracter
 * \param mensaje char* -> Mensaje de solicitud
 * \param mensajeError char* -> Mensaje de error
 * \param minimo int -> Minimo
 * \return int -> Retorna 1 Si salio todo Ok, caso contrario retorna 0
 *
 */
int getIntValidMin(int* pResultado, char* mensaje, char* mensajeError, int minimo);

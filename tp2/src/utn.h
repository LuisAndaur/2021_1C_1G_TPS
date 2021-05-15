#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */

/** \brief Valida el ingreso de un numero entero
 *
 * \param mensaje char*
 * \param pResultado int*
 * \return int 0 si pudo validar  o (-1) sif [el tamaño es invalido o recibio un puntero NULL]
 *
 */
int getInt(char* mensaje, int* pResultado);

/** \brief Valida el ingreso de un numero flotante
 *
 * \param mensaje char*
 * \param pResultado float*
 * \return float 0 si pudo validar  o (-1) si [el tamaño es invalido o recibio un puntero NULL]
 *
 */
float getFloat(char* mensaje, float* pResultado);

/** \brief Valida el ingreso de una cadena de caracteres
 *
 * \param mensaje char*
 * \param pResultado char*
 * \return int 0 si pudo validar  o (-1) si [el tamaño es invalido o recibio un puntero NULL]
 *
 */
int getString(char* mensaje, char* pResultado);

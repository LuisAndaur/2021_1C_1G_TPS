#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#endif // UTN_H_INCLUDED

/** \brief Valida que se reciban enteros
 *
 * \param mensaje char*
 * \param pResultado int*
 * \return int
 *
 */
int getInt(char* mensaje, int* pResultado);

/** \brief Valida que se reciban numeros
 *
 * \param mensaje char*
 * \param pResultado float*
 * \return float
 *
 */
float getFloat(char* mensaje, float* pResultado);

/** \brief Valida que la cadena no reciba datos incorrectos
 *
 * \param mensaje char*
 * \param pResultado char*
 * \return int
 *
 */
int getString(char* mensaje, char* pResultado);

/*
 * validation.h
 *
 *  Created on: 14 may. 2022
 *      Author: Fiorella Aguayo
 */

#ifndef VALIDATION_H_
#define VALIDATION_H_


#endif /* VALIDATION_H_ */
/**
 * @fn int getNumero(int*, char*, char*, int, int, int)
 * @brief obtener un numero del usuario
 *
 * @pre
 * @post
 * @param pResultado opcion elegida por el usuario
 * @param mensaje mensaje a mostrar
 * @param msjError mensaje de error
 * @param min rango minimo de error
 * @param max rango maximo de error
 * @param reintentos rango de intentos a probar
 * @return allOk 1 si está bien y 0 si está mal
 */
int getNumero(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos);
/**
 * @fn int pedirEntero(int*, char*, char*, int, int)
 * @brief pedir un numero entero
 *
 * @pre
 * @post
 * @param entero numero entero a pedir
 * @param mensaje mensaje a mostrar
 * @param mensajeError mensaje de error
 * @param min rango minimo de error
 * @param max rango maximo de error
 * @return allOk 1 si está bien y 0 si está mal
 */
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);
/**
 * @fn int pedirFlotante(float*, char*, char*, float, float)
 * @brief pedir un numero decimal
 *
 * @pre
 * @post
 * @param flotante numero decimal a pedir
 * @param mensaje mensaje a mostrar
 * @param mensajeError mensaje de error
 * @param min rango minimo de error
 * @param max rango maximo de error
 * @return allOk 1 si está bien y 0 si está mal
 */
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);
/**
 * @fn int pedirCadena(char*, char*)
 * @brief pedir una cadena de texto
 *
 * @pre
 * @post
 * @param cadena cadena de texto
 * @param mensaje mensaje que se imprimirá por pantalla
 * @return allOk 1 si está bien y 0 si está mal
 */
int pedirCadena(char* cadena, char* mensaje);
/**
 * @fn int primerLetraMayuscula(char[])
 * @brief acomodar array
 *
 * @pre
 * @post
 * @param name array de nombre
 * @return allOk 1 si está bien y 0 si está mal
 */
int primerLetraMayuscula(char name[]);
/**
 * @fn int validarLetras(char[])
 * @brief valida letras
 *
 * @pre
 * @post
 * @param string cadena de caracteres
 * @return allOk 1 si está bien y 0 si está mal
 */
int validarLetras(char string[]);

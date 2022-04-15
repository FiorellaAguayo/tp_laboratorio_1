/*
 * validaciones.h
 *
 *  Created on: 15 abr. 2022
 *      Author: Usuario
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */


/**
 * @fn int getNumero(int*, char*, char*, int, int, int)
 * @brief Funci�n que sirve para validar si la opci�n elegida por el usuario es correcta o err�nea.
 *
 * @param int pResultado Variable con puntero que guarda el n�mero ingresado por el usuario.
 * @param char mensaje Variable con puntero que muestra un mensaje en pantalla en caso correcto.
 * @param char msjError Variable con puntero que muestra un mensaje en pantalla en caso err�neo.
 * @param int min Variable que guarda la opci�n con el menor valor.
 * @param int max Variable que guarda la opci�n con el mayor valor.
 * @param int reintentos Variable que guarda la cantidad de intentos pued erealizar el usuario.
 * @return retorno Retorna 0 si est� bien y -1 si da error.
 */
int getNumero(int* pResultado, char* mensaje, char* msjError, int min, int max, int reintentos);

/**
 * @fn int getCaracter(char*, char*, char*, char, char)
 * @brief Funci�n que sirve para validar correcta o err�nea la opci�n elegida por el usuario.
 *
 * @param char caracter Variable con puntero donde se guarda el caracter ingresado por el usuario.
 * @param char mensaje Variable con puntero donde se guarda el mensaje que se mostrar� en pantalla en caso correcto.
 * @param char mensajeError Variable con puntero donde se guarda el mensaje que mostrar� en pantalla en caso de error.
 * @param char caracterVal1 Variable con puntero donde se guarda la opci�n 's'.
 * @param char caracterVal2 Variable con puntero donde se guarda la opci�n 'n'.
 * @return todoOk Retorna 0 si est� todoOk y -1 si da error.
 */
int getCaracter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2);

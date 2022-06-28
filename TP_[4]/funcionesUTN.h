/*
 * funcionesUTN.h
 *
 *  Created on: 20 jun. 2022
 *      Author: Usuario
 */

#ifndef FUNCIONESUTN_H_
#define FUNCIONESUTN_H_



#endif /* FUNCIONESUTN_H_ */

/**
 * @fn int getIntNumber(int*, char*, char*, int, int)
 * @brief funcion que valida numeros enteros
 *
 * @param entero variable de tipo entero que guarda el valor ingresado por el usuario
 * @param mensaje variable de tipo char que imprime mensaje
 * @param mensajeError variable de tipo char que imprime mensaje de error
 * @param min variable de tipo entero que guarda el rango mínimo que el usuario debe ingresar
 * @param max variable de tipo entero que guarda el rango mínimo que el usuario debe ingresar
 * @return retorna 0 si salio bien
 */
int getIntNumber(int* entero, char* mensaje, char* mensajeError, int min, int max);

/**
 * @fn int pedirFlotante(float*, char*, char*, float, float)
 * @brief esta funcion valida que el usuario solo ingrese un flotante
 *
 * @param flotante variable de tipo float que guarda el flotante ingresado por el usuario
 * @param mensaje  variable de tipo char donde se almacena el msj a imprimir en pantalla
 * @param mensajeError variable de tipo char que almacena el msj de error si el usuario ingresa algo que no sea un flotante
 * @param min varile de tipo float que almacena el minimo de flotantes que el usuario puede ingresar
 * @param max varile de tipo float que almacena el maximo de flotantes que el usuario puede ingresar
 * @return retorna 0 si salio bien
 */
int getFloat(float* flotante, char* mensaje, char* mensajeError, float min, float max);

/**
 * @fn int pedirCaracter(char*, char*, char*, char, char)
 * @brief
 *
 * @param caracter
 * @param mensaje
 * @param mensajeError
 * @param caracterVal1
 * @param caracterVal2
 * @return
 */
int getChar(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2);

/**
 * @fn int pedirCadena(char*, char*)
 * @brief funcion que valida que el usario ingrese cadena de caracteres es decir puede ingresar numeros y letras
 *
 * @param cadena variable de tipo char donde se almacena char ingresado por le usario
 * @param mensaje variable de tipo char donde se almacena el msj a imprimir en pantalla.
 * @return
 */
int getString(char* cadena, char* mensaje);

/**
 * @fn int primerLetraMayuscula(char[])
 * @brief funcion que sirve para que el usuario si escribe con mayusculas y minisculas su nombre se ordene poniendo
 * 		 la primer letra en Mayuscula
 *
 * @param name variable de tipo char donde se almacena el nombre ingresado por el usuario
 * @return
 */
int getFirstCapital(char* name);

/**
 * @fn int validarLetras(char[])
 * @brief funcion que valida que el usuario solo ingrese letras.
 *
 * @param string variable de tipo char donde se almacena los char ingresado por el usuario.
 * @return
 */
int validateLetters(char* string);

int sortMenu();

int modifyMenu();

int orderMenu();

/*
 * funcionesUTN.h
 *
 *  Created on: 25 jun. 2022
 *      Author: Aguayo Fiorella
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef FUNCIONESUTN_H_
#define FUNCIONESUTN_H_

#endif /* FUNCIONESUTN_H_ */

int getIntNumber(int* entero, char* mensaje, char* mensajeError, int min, int max);
int getString(char* cadena, char* mensaje);
int firstCapitalChar(char* name);
int validarLetras(char* string);
int getLegajo(int* entero, char* mensaje, char* mensajeError, int a, int b, int c);
int modifyMenu();
int sortMenu();
int getFloat(float* flotante, char* mensaje, char* mensajeError, float min, float max);
int getCharacter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2);

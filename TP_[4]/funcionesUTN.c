/*
 * funcionesUTN.c
 *
 *  Created on: 20 jun. 2022
 *      Author: Aguayo Fiorella
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesUTN.h"
#include <string.h>
#include <ctype.h>

int getIntNumber(int* entero, char* mensaje, char* mensajeError, int min, int max)
{

    int retorno = -1;
    int numeroIngresado;

    if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d", &numeroIngresado);

        while(numeroIngresado < min || numeroIngresado > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", &numeroIngresado);
        }

        *entero = numeroIngresado;
        retorno = 0;
    }
    return retorno;
}

int getFloat(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{
    int retorno = -1;
    float numeroIngresado;

    if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%f", &numeroIngresado);

        while(numeroIngresado < min || numeroIngresado > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%f", &numeroIngresado);
        }

        *flotante = numeroIngresado;
        retorno = 0;
    }
    return retorno;
}

int getChar(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2)
{
	int todoOk = -1;
	char caracterIngresado;

	if(caracter != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c", &caracterIngresado);
		caracterIngresado = tolower(caracterIngresado);

		while(caracterIngresado != caracterVal1 && caracterIngresado != caracterVal2)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%c", &caracterIngresado);
			caracterIngresado = tolower(caracterIngresado);
		}
		*caracter=caracterIngresado;
		todoOk=0;
	}
	return todoOk;
}

int getString(char* cadena, char* mensaje)
{
    int retorno = -1;

    if(cadena != NULL && mensaje != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        gets(cadena);

        retorno = 0;
    }
    return retorno;
}

int getFirstCapital(char* name)
{

	int i = 0;
	int error = -1;

	if(name != NULL)
	{
		strlwr(name);
		name[0] = toupper(name[0]);

		while(name[i] != '\0')
		{
		   if(name [i] == ' ')
		   {
			   name [i + 1] = toupper(name[i+1]);
		   }

		   i++;
		}
		    //puts(name);
	  error = 0;
	}
    return error;
}

int validateLetters(char* string)
{
    int i = 0;
    int error = 0;

    if(string != NULL)
    {
        while(string[i] != '\0')
        {
            if(string[i] != ' ' && (string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z'))
            {
                error= -1;

                while(error < 0)
                {
                    printf("ERROR. Se debe ingresar letras unicamente: ");
                    fflush(stdin);
                    gets(string);
                    error = 0;
                    i = 0;
                }
            }
            i++;
        }
    }
    return error;
}


int sortMenu()
{
    int option;

    system("cls");
	printf("\nIngrese la opción: ");
	printf("\n0. DESCENDENTE. (Z-A) (9-0)");
	printf("\n1. ASCENDENTE. (A-Z) (0-9)");
    printf("\nOpción: ");
    scanf("%d", &option);

    return option;
}

int modifyMenu()
{
	int option;

	system("cls");
	printf("\nIngrese la opción: ");
	printf("\n   1. Nombre.");
	printf("\n   2. Apellido.");
	printf("\n   3. Precio.");
	printf("\n   4. Código de vuelo.");
	printf("\n   5. Tipo de pasajero.");
	printf("\n   6. Estado de vuelo");
	scanf("%d", &option);

	return option;
}

int orderMenu()
{
    int option;

    system("cls");
    printf("\nIngrese la opción: ");
    printf("\n   1- ID.");
    printf("\n   2- Nombre.");
    printf("\n   3- Apellido.");
    printf("\n   4- Precio.");
    printf("\n   6- Código de vuelo.");
    printf("\n   7- Tipo de pasajero.");
    printf("\n   8- Estado de vuelo");
    printf("\n   9- Salir.");
    printf("\nOpción: ");
    scanf("%d", &option);

    return option;
}


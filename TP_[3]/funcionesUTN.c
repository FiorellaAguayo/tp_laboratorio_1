/*
 * funcionesUTN.c
 *
 *  Created on: 25 jun. 2022
 *      Author: Aguayo Fiorella
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Passenger.h"
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

int firstCapitalChar(char* name)
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

int validarLetras(char* string)
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

int getLegajo(int* entero, char* mensaje, char* mensajeError, int a, int b, int c)
{
	int retorno = 0;
	int legajoIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &legajoIngresado);

		while(legajoIngresado != a && legajoIngresado != b && legajoIngresado != c)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &legajoIngresado);
		}

		*entero = legajoIngresado;
		retorno = 0;
	}
	return retorno;
}

int modifyMenu()
{
	int option;

	printf("  1- nombre.\n");
	printf("  2- apellido.\n");
	printf("  3- precio.\n");
	printf("  4- c�digo de vuelo.\n");
	printf("  5- tipo de pasajero.\n");
	printf("  5- estado de vuelo.\n");
	printf("Ingrese opci�n: ");
	scanf("%d", &option);

	return option;
}

int sortMenu()
{
	int option;

	system("cls");
	printf("\n�En qu� orden lo quiere?");
	printf("   0- Decendente. (Z-A) (9-0)\n");
	printf("   1- Ascendente.(A-Z) (0-9)\n");
	printf("Ingrese opcion: ");
	scanf("%d", &option);

	return option;
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

int getCharacter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2)
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

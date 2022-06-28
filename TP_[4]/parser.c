/*
 * parser.c
 *
 *  Created on: 20 jun. 2022
 *      Author: Usuario
 */


#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "passenger.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int allOk = -1;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50],var7[50];
	sPassenger* newPassenger=NULL;
	int r=0;

	pFile=fopen("data.csv","r");
	if(pFile==NULL)
	{
		printf("El archivo es nulo");
	}

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7);

	while(!feof(pFile))
	{
		r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7);
		if(r<7)
		{
			break;
		}
		newPassenger = Passenger_newParametros(var1,var2,var3,var4,var5,var6,var7);

		if(newPassenger!=NULL)
		{
			ll_add(pArrayListPassenger,newPassenger);
			allOk=1;
		}
	}
	fclose(pFile);
	return allOk;
}



int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk;
	sPassenger* newPassenger;
	int aux;
	int id;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(feof(pFile) == 0)
		{
			newPassenger = Passenger_new();
			fread(newPassenger, sizeof(sPassenger), 1, pFile);

			if(!feof(pFile))
			{
				aux = ll_add(pArrayListPassenger, newPassenger);
				if(aux != 0)
				{
					Passenger_delete(newPassenger);
					todoOk = 0;
					break;
				}
				else
				{
					id = newPassenger->id;
					todoOk = 1;
				}
			}
			else
			{
				break;
			}
		}
		controller_saveNextId(id);
	}
    return todoOk;

}

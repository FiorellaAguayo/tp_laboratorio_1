/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Aguayo Fiorella
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include <string.h>
#include <ctype.h>

int optionMenu()
{
	int option;
	system("cls");
	printf("\n----------| MENÚ DE OPCIONES |----------");
	printf("\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).");
	printf("\n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).");
	printf("\n3. Alta de pasajero");
	printf("\n4. Modificar datos de pasajero");
	printf("\n5. Baja de pasajero");
	printf("\n6. Listar pasajeros");
	printf("\n7. Ordenar pasajeros");
	printf("\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).");
	printf("\n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).");
	printf("\n10. Salir");
	scanf("%d", &option);
	return option;
}

sPassenger* Passenger_new()
{
	sPassenger* newPassenger = (sPassenger*)malloc(sizeof(sPassenger));

	if(newPassenger != NULL)
	{
		newPassenger->id = 0;
		strcpy(newPassenger->name, " ");
		strcpy(newPassenger->name, " ");
		newPassenger->price = 0;
		strcpy(newPassenger->flycode, " ");
		strcpy(newPassenger->typePassenger, " ");
		strcpy(newPassenger->statusFlight, " ");
	}
	return newPassenger;
}

int Passenger_setId(sPassenger* this, int id)
{
	int allOk = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		allOk = 1;
	}
	else
	{
		printf("\nERROR. ID inválido.");
	}
	return allOk;
}

int Passenger_getId(sPassenger* this, int* id)
{
	int allOk = 0;
	if(this != NULL && id > 0)
	{
		*id = this->id;
		allOk = 1;
	}
	return allOk;
}

int Passenger_setName(sPassenger* this, char* name)
{
	int allOk = 0;
	if(this != NULL && name != NULL)
	{
		if(strlen(name) < 40 && strlen(name) > 1)
		{
			strcpy(this->name, name);
			strlwr(this->name);
			this->name[0] = toupper(this->name[0]);
			allOk = 1;
		}
	}
	else
	{
		printf("\nERROR. Nombre inválido.");
	}
	return allOk;
}

int Passenger_getName(sPassenger* this, char* name)
{
	int todoOk = 0;
	if(this != NULL && name != NULL)
	{
		strcpy(name, this->name);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setLastName(sPassenger* this, char* lastName)
{
	int allOk = 0;
	if(this != NULL && lastName != NULL)
	{
		if(strlen(lastName) < 30 && strlen(lastName) > 2)
		{
			strcpy(this->lastName, lastName);
			strlwr(this->lastName);
			this->lastName[0] = toupper(this->lastName[0]);
			allOk = 1;
		}
	}
	else
	{
		printf("ERROR. Apellido inválido.");
	}
	return allOk;

}

int Passenger_getLastName(sPassenger* this, char* lastName)
{
	int allOk = 0;
	if(this != NULL && lastName != NULL)
	{
		strcpy(lastName, this->lastName);
		allOk = 1;
	}
	return allOk;
}

int Passenger_setFlyCode(sPassenger* this, char* flyCode)
{
	int allOk=0;
	if(this != NULL && flyCode != NULL )
	{
		strcpy(this->flycode, flyCode);
	}
	allOk=1;
    return allOk;
}

int Passenger_getFlyCode(sPassenger* this, char* flyCode)
{
	int allOk = 0;
	if(this != NULL && flyCode != NULL)
	{
		strcpy(flyCode, this->flycode);
		allOk = 1;
	}
	return allOk;
}

int Passenger_setTypePassenger(sPassenger* this, char* typePassenger)
{
	int allOk=0;
	if(this != NULL && typePassenger != NULL)
	{
		strcpy(this->typePassenger,typePassenger);
		allOk=1;
	}
    return allOk;
}

int Passenger_getTypePassenger(sPassenger* this, char* typePassenger)
{
	int allOk = 0;
	if(this != NULL && typePassenger != NULL)
	{
		strcpy(typePassenger, this->typePassenger);
		allOk = 1;
	}
	return allOk;
}

int Passenger_setPrice(sPassenger* this, float price)
{
	int allOk=0;
	if(this != NULL && price > 0 && price <= 1000000000)
	{
		this->price= price;
		allOk=1;
	}
    return allOk;
}

int Passenger_getPrice(sPassenger* this, float* price)
{
    int allOk=0;
    if(this != NULL && price != 0)
    {
    	*price=this->price;
    	allOk=1;
    }
    return allOk;
}

int Passenger_setStatusFlight(sPassenger* this, char* statusFlight)
{
	int allOk=0;
	if(this != NULL && statusFlight != NULL )
	{
		strcpy(this->statusFlight, statusFlight);
	}
	allOk=1;
    return allOk;
}

int Passenger_getStatusFlight(sPassenger* this, char* estadoVuelo)
{
	int allOk = 0;
	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo, this->statusFlight);
		allOk = 1;
	}
	return allOk;
}

sPassenger* Passenger_newParametros(char* idStr,char* nameStr, char* lastNameStr, float* priceStr, char* flyCodeStr, char* typePassengerStr, char* statusFlight)
{
	sPassenger* newPassenger = Passenger_new();
	if(newPassenger != NULL)
	{
		if(!(Passenger_setId(newPassenger, atoi(idStr))
			 && Passenger_setName(newPassenger, nameStr)
			 && Passenger_setLastName(newPassenger, lastNameStr)
			 && Passenger_setPrice(newPassenger, priceStr)
			 && Passenger_setTypePassenger(newPassenger, typePassengerStr)
			 && Passenger_setStatusFlight(newPassenger, statusFlight)
			 && Passenger_setFlyCode(newPassenger, flyCodeStr)))
		{
			free(newPassenger);
			newPassenger = NULL;
		}
	}
	return newPassenger;
}

int Passenger_delete(sPassenger* this)
{
	int allOk = 0;
	if(this != NULL)
	{
		free(this);
		allOk = 1;
	}
	return allOk;
}

int Passenger_SortId(void* item1, void* item2)
{
	sPassenger* pas1 = NULL;
	sPassenger* pas2 = NULL;
	int id1;
	int id2;
	int allOk = 0;

	pas1 = (sPassenger*)item1;
	pas2 = (sPassenger*)item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getId(pas1, &id1) == 1 && Passenger_getId(pas2, &id2) == 1)
		{
			if(id1 > id2)
			{
				allOk = 1;
			}
			else if(id1 < id2)
			{
				allOk = -1;
			}
		}
	}
	return allOk;
}

int Passenger_SortName(void* item1, void* item2)
{
	sPassenger* pas1 = NULL;
	sPassenger* pas2 = NULL;
	char name1[128];
	char name2[128];
	int allOk = 0;
	pas1 = (sPassenger*)item1;
	pas2 = (sPassenger*)item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getName(pas1, name1) == 1 && Passenger_getName(pas2, name2) == 1)
		{
			if(strcmp(name1, name2) > 0)
			{
				allOk = 1;
			}
			else if(strcmp(name1, name2) < 0)
			{
				allOk = -1;
			}
		}
	}
	return allOk;
}

int Passenger_SortLastName(void* item1, void* item2)
{
	sPassenger* pas1 = NULL;
	sPassenger* pas2 = NULL;
	char lastName1[128];
	char lastName2[128];
	int allOk = 0;
	pas1 = (sPassenger*)item1;
	pas2 = (sPassenger*)item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getLastName(pas1, lastName1) == 1 && Passenger_getLastName(pas2, lastName2) == 1)
		{
			if(strcmp(lastName1, lastName2) > 0)
			{
				allOk = 1;
			}
			else if(strcmp(lastName1, lastName2) < 0)
			{
				allOk = -1;
			}
		}
	}
	return allOk;
}

int Passenger_SortPrice(void* item1, void* item2)
{
	sPassenger* pas1 = NULL;
	sPassenger* pas2= NULL;
	float price1;
	float price2;
	int allOk = 0;

	pas1 = (sPassenger*)item1;
	pas2 = (sPassenger*)item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getPrice(pas1, &price1) == 1 && Passenger_getPrice(pas2, &price2) == 1)
		{
			if(price1 > price2)
			{
				allOk = 1;
			}
			else if(price1 < price2)
			{
				allOk = -1;
			}
		}
	}
	return allOk;
}

int Passenger_SortStatusFlight(void* item1, void* item2)
{
	sPassenger* pasajero1 = NULL;
	sPassenger* pasajero2 = NULL;
	char status1[128];
	char status2[128];
	int allOk = 0;

	pasajero1 = (sPassenger*)item1;
	pasajero2 = (sPassenger*)item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getStatusFlight(pasajero1, status1) == 1 && Passenger_getStatusFlight(pasajero2, status2) == 1)
		{
			if(strcmp(status1, status2) > 0)
			{
				allOk = 1;
			}
			else if(strcmp(status1, status2) < 0)
			{
				allOk = -1;
			}
		}
	}
	return allOk;
}

int Passenger_SortFlyCode(void* item1, void* item2)
{
	sPassenger* pas1 = NULL;
	sPassenger* pas2 = NULL;
	char code1[128];
	char code2[128];
	int allOk = 0;

	pas1 = (sPassenger*) item1;
	pas2 = (sPassenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getFlyCode(pas1, code1) == 1 && Passenger_getFlyCode(pas2, code2) == 1)
		{
			if(strcmp(code1, code2) > 0)
			{
				allOk = 1;
			}
			else if(strcmp(code1, code2) < 0)
			allOk = -1;
		}
	}
	return allOk;
}


int Passenger_SortTypePassenger(void* item1, void* item2)
{
	sPassenger* pas1 = NULL;
	sPassenger* pas2 = NULL;
	char type1[128];
	char type2[128];
	int allOk = 0;

	pas1 = (sPassenger*)item1;
	pas2 = (sPassenger*)item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getTypePassenger(pas1, type1) == 1 && Passenger_getTypePassenger(pas2, type2) == 1)
		{
			if(strcmp(type1, type2) > 0)
			{
				allOk = 1;
			}
			else if(strcmp(type1, type2) < 0)
			{
				allOk = -1;
			}
		}
	}
	return allOk;
}

int searchIdPassenger(LinkedList* pArrayListPassenger, int id)
{
	int index = -1;
	int idFlag;
    sPassenger* newPassenger;
    if(pArrayListPassenger != NULL && id > 0)
	{
		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			newPassenger = ll_get(pArrayListPassenger, i);
			if(newPassenger != NULL)
			{
				Passenger_getId(newPassenger, &idFlag);
				if(idFlag == id)
				{
					index = i;
					break;
				}
			}
		}
    }
    return index;
}

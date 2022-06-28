/*
 * passenger.c
 *
 *  Created on: 20 jun. 2022
 *      Author: Usuario
 */


#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "passenger.h"
#include <string.h>
#include <ctype.h>

sPassenger* Passenger_new()
{
	sPassenger* newPassenger=(sPassenger*)malloc(sizeof(sPassenger));

	if(newPassenger != NULL)
	{
		newPassenger->id= 0;
		strcpy(newPassenger->name," ");
		strcpy(newPassenger->lastName," ");
		newPassenger->price = 0;
		strcpy(newPassenger->flyCode," ");
		strcpy(newPassenger->typePassenger, " ");
		strcpy(newPassenger->statusFlight, " ");
	}
	return newPassenger;
}


sPassenger* Passenger_newParametros(char* idStr,char* nameStr,char* lastNameStr,char* priceStr ,char* flyCodeStr,char* typePassengerStr,char* statusFlightStr)
{

	sPassenger* newPassenger = Passenger_new();
	if(newPassenger != NULL)
	{
		if( !(Passenger_setId(newPassenger, atoi(idStr))
			 && Passenger_setNombre(newPassenger, nameStr)
			 && Passenger_setApellido(newPassenger,lastNameStr)
			 && Passenger_setPrecio(newPassenger, atof(priceStr))
			 && Passenger_setCodigoVuelo(newPassenger, flyCodeStr)
			 && Passenger_setTipoPasajero(newPassenger,typePassengerStr)
			 && Passenger_setStatusFlight(newPassenger, statusFlightStr)
			 ))
		{
			free(newPassenger);
			newPassenger=NULL;
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

int Passenger_setId(sPassenger* this,int idPassenger)
{
	int allOk = 0;
	if(this != NULL && idPassenger > 0)
	{
		this->id = idPassenger;
		allOk = 1;
	}
	else
	{
		printf("Id Invalido\n");
	}
	return allOk;
}


int Passenger_getId(sPassenger* this,int* idPassenger)
{
	int allOk = 0;
	if(this != NULL && idPassenger != NULL)
	{
		*idPassenger = this->id;
		allOk = 1;
	}
	return allOk;
}



int Passenger_setName(sPassenger* this,char* nombre){
	int allOk = 0;
	if(this != NULL && nombre != NULL)
	{
		if(strlen(nombre) < 40 && strlen(nombre) > 1)
		{
			strcpy(this->name, nombre);
			strlwr(this->name);
			this->name[0] = toupper(this->name[0]);
			allOk = 1;
		}
	}
	else
	{
		printf("Nombre Invalido\n");
	}
	return allOk;
}

int Passenger_getName(sPassenger* this,char* nombre)
{
	int allOk = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->name);
		allOk = 1;
	}
	return allOk;
}

int Passenger_setLastName(sPassenger* this,char* apellido)
{
	int allOk = 0;
	if(this != NULL && apellido != NULL)
	{
		if(strlen(apellido) < 30 && strlen(apellido) > 2)
		{
			strcpy(this->lastName, apellido);
			strlwr(this->lastName);
			this->lastName[0] = toupper(this->lastName[0]);
			allOk = 1;
		}
	}
	else
	{
		printf("Apellido Invalido\n");
	}
	return allOk;

}
int Passenger_getLastName(sPassenger* this,char* apellido)
{
	int allOk = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->lastName);
		allOk = 1;
	}
	return allOk;
}

int Passenger_setFlyCode(sPassenger* this,char* codigoVuelo)
{
	int allOk=0;

	if(this != NULL && codigoVuelo != NULL )
	{
		strcpy(this->lastName, codigoVuelo);
	}
	allOk=1;

    return allOk;
}

int Passenger_getFlyCode(sPassenger* this,char* codigoVuelo)
{
	int allOk = 0;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->flyCode);
		allOk = 1;
	}
	return allOk;
}


int Passenger_setTypePassenger(sPassenger* this,char* tipoPasajero)
{
	int allOk=0;

	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(this->typePassenger,tipoPasajero);
	}
	allOk=1;

    return allOk;
}

int Passenger_getTypePassenger(sPassenger* this, char* tipoPasajero)
{
	int allOk = 0;
	if(this != NULL && tipoPasajero != NULL)
	{
		strcpy(tipoPasajero, this->typePassenger);
		allOk = 1;
	}
	return allOk;
}


int Passenger_setPrice(sPassenger* this,float precio)
{
	int allOk=0;

	if(this != NULL && precio > 0 && precio <= 1000000000)
	{
		this->price= precio;
	}
	allOk=1;

    return allOk;
}
int Passenger_getPrice(sPassenger* this, float* precio)
{
    int allOk=0;

    if(this != NULL && precio != 0)
    {
    	*precio=this->price;
    	allOk=1;
    }

    return allOk;
}
int Passenger_setStatusFlight(sPassenger* this, char* estadoVuelo)
{
	int allOk=0;

	if(this != NULL && estadoVuelo != NULL )
	{
		strcpy(this->statusFlight, estadoVuelo);
	}
	allOk=1;

    return allOk;
}

int Passenger_getStatusFlight(sPassenger* this, char* estadoVuelo)
{
	int allOk = 0;
	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo, this->statusFLight);
		allOk = 1;
	}
	return allOk;
}



int Passenger_SortId(void* item1, void* item2)
{
	int allOk = 0;
	sPassenger* Pasajero1 = NULL;
	sPassenger* Pasajero2 = NULL;
	int id1;
	int id2;

	Pasajero1 = (sPassenger*) item1;
	Pasajero2 = (sPassenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getId(Pasajero1, &id1) == 1 && Passenger_getId(Pasajero2, &id2) == 1)
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
	int allOk = 0;
	sPassenger* pasajero1 = NULL;
	sPassenger* pasajero2 = NULL;
	char name1[128];
	char name2[128];

	pasajero1 = (sPassenger*) item1;
	pasajero2 = (sPassenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getNombre(pasajero1, name1) == 1 && Passenger_getNombre(pasajero2, name2) == 1)
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
	int allOk = 0;
	sPassenger* pasajero1 = NULL;
	sPassenger* pasajero2 = NULL;
	char apellido1[128];
	char apellido2[128];

	pasajero1 = (sPassenger*) item1;
	pasajero2 = (sPassenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getNombre(pasajero1, apellido1) == 1 && Passenger_getNombre(pasajero2, apellido2) == 1)
		{
			if(strcmp(apellido1, apellido2) > 0)
			{
				allOk = 1;
			}
			else if(strcmp(apellido1, apellido2) < 0)
			{
				allOk = -1;
			}
		}
	}
	return allOk;
}

int Passenger_SortPrice(void* item1, void* item2)
{
	int allOk = 0;
	sPassenger* pasajero1 = NULL;
	sPassenger* pasajero2 = NULL;
	float price1;
	float price2;

	pasajero1 = (sPassenger*) item1;
	pasajero2 = (sPassenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getPrecio(pasajero1, &price1) == 1 && Passenger_getPrecio(pasajero2, &price2) == 1)
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
	int allOk = 0;
	sPassenger* pasajero1 = NULL;
	sPassenger* pasajero2 = NULL;
	char status1[128];
	char status2[128];

	pasajero1 = (sPassenger*) item1;
	pasajero2 = (sPassenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getNombre(pasajero1, status1) == 1 && Passenger_getNombre(pasajero2, status2) == 1)
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
	int allOk = 0;
	sPassenger* pasajero1 = NULL;
	sPassenger* pasajero2 = NULL;
	char code1[128];
	char code2[128];

	pasajero1 = (sPassenger*) item1;
	pasajero2 = (sPassenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getNombre(pasajero1, code1) == 1 && Passenger_getNombre(pasajero2, code2) == 1)
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
	int allOk = 0;
	sPassenger* pasajero1 = NULL;
	sPassenger* pasajero2 = NULL;
	char type1[128];
	char type2[128];

	pasajero1 = (sPassenger*) item1;
	pasajero2 = (sPassenger*) item2;
	if(item1 != NULL && item2 != NULL)
	{
		if(Passenger_getNombre(pasajero1, type1) == 1 && Passenger_getNombre(pasajero2, type2) == 1)
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



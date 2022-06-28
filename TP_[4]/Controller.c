/*
 * Controller.c
 *
 *  Created on: 20 jun. 2022
 *      Author: Usuario
 */


#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "passenger.h"
#include "parser.h"
#include "funcionesUTN.h"
#include <string.h>
#include <ctype.h>


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int allOk = 0;
	FILE* file;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		file = fopen(path, "r");
		if(ll_isEmpty(pArrayListPassenger) != 1)
		{
			parser_PassengerFromText(file, pArrayListPassenger);
		}
		printf("\nLISTADO EXITOSO");
		allOk = 1;
	}
	fclose(file);
    return allOk;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		printf("Enter Load 1\n");
		FILE* pFile = fopen(path,"rb");
		if(pFile != NULL)
		{
			printf("Enter Load 2\n");
			retorno = 0;
			parser_PassengerFromBinary(pFile, pArrayListPassenger);
			fclose(pFile);
		}
	}
	return retorno;
}


/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,char* path)
{
	int allOk = 0;

	int flagArchivo = 0;

	int id = 0;
	char name[50];
	char lastName[50];
	float price;
	int typePassengerInt;
	int statusFlightInt;
	char typePassenger;
	char flyCode;
	char statusFlight;
	char response;

	sPassenger* auxPasajero;

	system("cls");
	printf("\n----------| Alta Pasajero |----------");

	if(pArrayListPassenger != NULL)
	{
		auxPasajero = Passenger_new();
		if(auxPasajero != NULL)
		{
			FILE* pFile;
			pFile = fopen(path,"r");
			if(flagArchivo == 0)
			{
				id = controller_getMaxId(pFile)+1;
				flagArchivo = 1;
				fclose(pFile);
			}

			id = controller_nextId(pArrayListPassenger);
			Passenger_setId(auxPasajero, id);

			getString(name, "\nIngrese nombre: ");
			Passenger_setName(auxPasajero, name);

			getString(lastName, "\nIngrese apellido: ");
			Passenger_setLastName(auxPasajero, lastName);

			getFloat(&price, "\nIngrese precio (1-100000000): ", "Error. Ingrese precio (1-100000000): ", 1, 100000000);
			Passenger_setPrice(auxPasajero, price);

			getString(flyCode, "\nIngrese código de vuelo: " );
			Passenger_setFlyCode(auxPasajero, flyCode);

			getIntNumber(&typePassengerInt, "\nIngrese tipo de pasajero: \n 1) Económico \n 2) Primera clase \n 3) Ejecutivo","ERROR. Ingrese tipo de pasajero válido: ", 1, 3);
			switch(typePassengerInt)
			{
				case 1:
					strcpy(typePassenger, "Económico");
					break;
				case 2:
					strcpy(typePassenger, "Primera clase");
				    break;
				case 3:
					strcpy(typePassenger, "Ejecutivo");
					break;
			}

			Passenger_setTipoPasajero(auxPasajero,typePassenger);

			getIntNumber(&statusFlightInt, "\nIngrese estado de vuelo: \n 1) Activo \n 2) Demorado \n 3) Cancelado","ERROR. Ingrese tipo de pasajero válido: ", 1, 3);
			switch(statusFlightInt)
			{
				case 1:
					strcpy(statusFlight,"Activo");
					break;
				case 2:
					strcpy(statusFlight,"Demorado");
					break;
				case 3:
					strcpy(statusFlight,"Cancelsdo");
					break;
			}
			Passenger_setStatusFlight(auxPasajero, statusFlight);

			printf("\n----------|LISTA DE  PASAJEROS|----------");
			printf("\n| id |     NOMBRE      |     APELLIDO     |     PRECIO     |     CODIGO D EVUELO     |     TIPO D EPASAJERO     |     ESTADO DE VUELO");
			controller_mostrarPassenger(auxPasajero);

			getChar(&response, "\n¿Confirma alta? (s/n)", "Error. ¿Confirma alta? (s/n): ", 's', 'n');
			if(response  == 's')
			{
				ll_add(pArrayListPassenger, auxPasajero);
				controller_saveNextId(id);
				allOk = 1;
				printf("¡ALTA EXITOSA!");
			}
			else
			{
				printf("\nSe ha cancelado el alta");
			}
		}
	}
    return allOk;
}


int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int allOk = 0;
	char response = 's';
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int typePassengerInt;
	int statusFlightInt;
	char typePassenger;
	char flyCode;
	char statusFlight;
	int index;
	sPassenger* auxPassenger;

	system("cls");
	printf("\n----------| MODIFICACIÓN PASAJERO |----------");
	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		printf("\nIngrese el ID del pasajero que quiere modificar: ");
		scanf("%d", &id);
		if(controller_validarId(pArrayListPassenger, id) == -1)
		{
			printf("\nError. El ID ingresado no existe");
		}
		index = buscarPassengerId(pArrayListPassenger, id);
		auxPassenger = ll_get(pArrayListPassenger, index);

		if(index == -1)
		{
			printf("\nEl ID ingresado no existe");
		}
		else
		{
			printf("\n| id |     NOMBRE      |     APELLIDO     |     PRECIO     |     CODIGO D EVUELO     |     TIPO D EPASAJERO     |     ESTADO DE VUELO");
			controller_mostrarPassenger(auxPassenger);

			getChar(&response, "Are you sure you want to modify this passenger from the system? (s: YES and n: NO)", "Enter option again. Are you sure you want to modify this passenger in the system (s: YES and n: NO)?", 's', 'n');
			fflush(stdin);

			if(response == 's')
			{
				switch(modifyMenu())
				{
					case 1:
						getString(nombre, "\nIngresar nuevo nombre: ");
						Passenger_setName(auxPassenger, nombre);
						printf("Successful Modification!!!\n");
						break;
					case 2:
						getString(apellido, "\nIngresar nuevo apellido: ");
						Passenger_setLastName(auxPassenger, apellido);
						break;
					case 3:
						getFloat(&precio, "\nIngrese nuevo precio 1-100000000: ", "\nError. Ingrese nuevo precio 1-100000000: ", 1, 100000000);
						Passenger_setPrice(auxPassenger, precio);
						printf("\nMODIFICACIÓN EXITOSA");
						break;
					case 4:
						getString(flyCode, "\nIngrese nuevo codigo de vuelo: " );
						Passenger_setFlyCode(auxPassenger, flyCode);
						break;
					case 5:
						getIntNumber(&statusFlightInt, "\nIngrese nuevo estado de vuelo\n 1) Activo\n 2) Demorado \n 3) Cancelado","\nerror, Ingrese nuevo estado d evuelo: ",1,3);
						switch(statusFlightInt)
						{
							case 1:
								strcpy(statusFlight,"activo");
								break;
							case 2:
								strcpy(statusFlight,"demorado");
								break;
							case 3:
								strcpy(statusFlight,"cancelado");
								break;
						}
						Passenger_setStatusFlight(auxPassenger, statusFlight);

							getIntNumber(&typePassengerInt, "\nIngrese tipo de pasajero: \n 1) Económico \n 2) Primera clase \n 3) ejecutivo \n","error. Ingresa un tipo de pasajero válido: ",1,3);
							switch(typePassengerInt)
							{
								case 1:
									 strcpy(typePassenger,"económico");
									break;
								case 2:
									strcpy(typePassenger,"Primera clase");
									break;
								case 3:
									strcpy(typePassenger,"ejecutivo");
									break;
							}
							Passenger_setTipoPasajero(auxPassenger, typePassenger);

						printf("\nOpción inválida");
						break;
				}
			}
			else
			{
				printf("La modificación fue cancelada");
				break;
			}
		}
		allOk = 1;
	}
    return allOk;
}


/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int allOk = 0;
	int id;
	char response;
	int index;
	sPassenger* auxPassenger;


	system("cls");
	printf("\n----------| Remove Passenger |----------");
	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		printf("\nIngrese el ID del pasajero que quiere bajar: ");
		scanf("%d", &id);
		while(controller_validarId(pArrayListPassenger, id) == -1)
		{
			printf("Error. Ingrese le id del pasajero que quiere bajar: ");
			scanf("%d", &id);
		}
		index = buscarPassengerId(pArrayListPassenger, id);
		auxPassenger = ll_get(pArrayListPassenger, index);

		if(index == -1)
		{
			printf("\nEl id ingresado no exitse");
		}
		else
		{
			printf("\n----------| LISTA DE PASAJEROS |----------");
			printf("\n| id |     NOMBRE      |     APELLIDO     |     PRECIO     |     CODIGO D EVUELO     |     TIPO D EPASAJERO     |     ESTADO DE VUELO");

			getChar(&response, "\n¿Confirma baja? s/n", "\nERROR ¿Confirma baja? s/n", 's', 'n');
			if(response == 's')
			{
				ll_remove(pArrayListPassenger, index);
				Passenger_delete(auxPassenger);
				allOk = 1;
				printf("\nBAJA EXITOSA");
			}
			else
			{
				printf("\nLa baja fue cancelada");
			}
		}
	}
    return allOk;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	sPassenger* pAuxPassenger;
	int allOk = 0;

	if(pArrayListPassenger != NULL)
	{

		system("cls");
		printf("\n----------| LISTA DE PASAJEROS |----------");
		printf("\n| id |     NOMBRE      |     APELLIDO     |     PRECIO     |     CODIGO D EVUELO     |     TIPO D EPASAJERO     |     ESTADO DE VUELO");


		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			pAuxPassenger = ll_get(pArrayListPassenger, i);
			if(pAuxPassenger != NULL)
			{
				controller_mostrarPassenger(pAuxPassenger);
				allOk = 1;
			}
		}
	}
    return allOk;
}


/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int allOk = 0;
	int critery;
	LinkedList* sort;

	if(pArrayListPassenger != NULL)
	{
		sort = ll_clone(pArrayListPassenger);
		critery = sortMenu();

		switch(orderMenu())
		{
			case 1:
				ll_sort(sort, Passenger_SortId, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso");
				break;
			case 2:
				ll_sort(sort, Passenger_SortName, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso");
				break;
			case 3:
				ll_sort(sort, Passenger_SortLastName, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso");
				break;
			case 4:
				ll_sort(sort, Passenger_SortPrice, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso");
				break;
			case 5:
				ll_sort(sort, Passenger_SortFlyCode, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso");
				break;
			case 6:
				ll_sort(sort, Passenger_SortTypePassenger, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso");
				break;
			case 7:
				ll_sort(sort, Passenger_SortStatusFlight, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso");
				break;
			case 8:
				printf("Orden cancelado");
				break;
			default:
				printf("\nopción inválida");
				break;
		}
		ll_deleteLinkedList(sort);
		allOk = 1;
	}

    return allOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int allOk = 0;
	FILE* file;
	int id;
	char name[50];
	char lastName[50];
	float price;
	char typePassenger[15];
	char flyCode[15];
	char statusFlight[15];
	sPassenger* auxPassenger ;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		file = fopen(path, "w");

		auxPassenger = Passenger_new();

		fprintf(file, "id,name,Last name,price,Fly Code,Type Passenger, Status Flight\n");

		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPassenger = ll_get(pArrayListPassenger, i);
			if(auxPassenger != NULL)
			{
				Passenger_getId(auxPassenger, &id);
				Passenger_getNombre(auxPassenger, name);
				Passenger_getApellido(auxPassenger, lastName);
				Passenger_getPrecio(auxPassenger, &price);
				Passenger_getCodigoVuelo(auxPassenger, flyCode);
				Passenger_getTipoPasajero(auxPassenger, typePassenger);
				Passenger_getStatusFlight(auxPassenger, statusFlight);


				fprintf(file, "%d,%s,%s,%f,%s,%s,%s\n",id, name, lastName, price, flyCode, typePassenger,statusFlight);
				allOk = 1;
			}
			else
			{
				allOk = 0;
				break;
			}
		}
		fclose(file);
	}
    return allOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int allOk = 0;
	FILE* file;
	sPassenger* auxPassenger ;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		file = fopen(path, "wb");

		auxPassenger = Passenger_new();

		if(auxPassenger != NULL)
		{
			for(int i = 0; i < ll_len(pArrayListPassenger); i++)
			{
				auxPassenger = ll_get(pArrayListPassenger, i);
				fwrite(auxPassenger, sizeof(sPassenger), 1, file);
			}
			allOk = 1;
		}
		fclose(file);
	}
    return allOk;
}

int controller_mostrarPassenger(sPassenger* pArrayListPassenger)
{
	int id;
	char name[50];
	char lastName[50];
	float price;
	char typePassenger;
	char flyCode;
	char statusFlight;

	int allOk = 0;

	if(pArrayListPassenger!=NULL )
	{
		Passenger_getId(pArrayListPassenger,&id);

		Passenger_getNombre(pArrayListPassenger, name);

		Passenger_getApellido(pArrayListPassenger, lastName);

		Passenger_getPrecio(pArrayListPassenger, &price);

		Passenger_getCodigoVuelo(pArrayListPassenger, flyCode);

		Passenger_getTipoPasajero(pArrayListPassenger, typePassenger);

		Passenger_getStatusFlight(pArrayListPassenger, statusFlight);

		printf("\n %d   %s     %s     %f     %s     %s     %s ", id, name, lastName, price, flyCode, typePassenger, statusFlight);

		allOk = 1;
	}
	return allOk;
}

void controller_saveNextId(int id)
{
    FILE* file = fopen("ultimoID.txt", "r+");
    if(file == NULL)
    {
    	file = fopen("ultimoID.txt", "w");
    }
    fprintf(file,"%d", id);
    fclose(file);
}

int controller_nextId(LinkedList* pArrayListPassenger)
{
	FILE* file;
	int* idNow;
    int nextId;

    file = fopen("ultimoID.txt", "r");
    idNow = (int*) malloc(sizeof(int));

    if(file == NULL)
    {
    	nextId=0;
    }
    else
    {
        fscanf(file, "%d", idNow);
        nextId = *idNow+1;
    }
    fclose(file);
    return nextId;
}

int controller_getMaxId(FILE* pFile)
{
	sPassenger* newPassenger=NULL;
	int maxId=0;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50],var7[50];
	int r=0;
	pFile = fopen("data.csv","r");
	if(pFile == NULL)
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
			maxId++;
		}
	}
	fclose(pFile);
	return maxId;
}

int controller_validateId(LinkedList* pArrayListPassenger, int idPas)
{
	int seEncontroID;
	int i = -1;
	int len;
	sPassenger* auxPassenger;

	if(pArrayListPassenger != NULL && idPas >= 0)
	{
		len = ll_len(pArrayListPassenger);

		for (int i = 0; i < len; ++i) {

			auxPassenger = ll_get(pArrayListPassenger, i);

			if(auxPassenger != NULL)
			{
				Passenger_getId(auxPassenger, &i);

				if(idPas == seEncontroID)
				{
					i= 1;
					break;
				}
			}
		}
	}
	return i;
}

int searchPassengerId(LinkedList* pArrayListPassenger, int id)
{
	int i = - 1;
	int idCompare;
	sPassenger* newPassenger;
	if(pArrayListPassenger != NULL && id > 0)
	{
		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			newPassenger = ll_get(pArrayListPassenger, i);
			if(newPassenger != NULL)
			{
				Passenger_getId(newPassenger, &idCompare);
				if(idCompare == id)
				{
					idCompare = i;
					break;
				}
			}
		}
	}
	return i;
}


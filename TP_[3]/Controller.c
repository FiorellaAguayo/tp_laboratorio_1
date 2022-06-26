#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "funcionesUTN.h"
#include "parser.h"
#include <string.h>
#include <ctype.h>

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int allOk = 0;
	FILE* file;
	if(path != NULL && pArrayListPassenger != NULL)
	{
        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
		file = fopen(path, "r");
		if(file == NULL)
		{
			printf("\nHubo un error al abrir el archivo.");
		}
		else
		{
			if (parser_PassengerFromText(file, pArrayListPassenger))
			{
				printf("\n¡Carga de archivo de texto exitosa!");
				allOk = 1;
			}
		}
	}
	fclose(file);
	return allOk;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int allOk = 0;
	FILE* file;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		printf("\n2. Cargar los datos de los empleados desde el archivo data.bin (modo bin).");
		file = fopen(path, "rb");
		if(file == NULL)
		{
			printf("\nHubo un error al abrir el archivo.");
		}
		else
		{
			if(parser_PassengerFromBinary(file, pArrayListPassenger))
			{
				printf("\n¡Carga de archivo de texto exitosa!");
				allOk = 1;
			}
		}
	}
	fclose(file);
	return allOk;
}

int controller_addPassenger(LinkedList* pArrayListPassenger, char* path)
{
	sPassenger* newPassenger = NULL;
	int id;
	char name[51];
	char lastName[51];
	float price;
	int typePassengerInt;
	int statusFlightInt;
	char typePassenger;
	char flyCode[10];
	char statusFlight;
	int allOk = 0;
	int len;
	int flag = 10;
	int response;

	sPassenger* auxPassenger;

	system("cls");
	printf("\n----------| Alta Pasajero |----------");
	if(pArrayListPassenger != NULL)
	{
		auxPassenger = Passenger_new();
		if(auxPassenger != NULL)
		{

			FILE* file;
			file = fopen(path, "r");
			if(flag == 0)
			{
				id = controller_getMaxId(file)+1;
				flag = 1;
				fclose(file);
			}

			id = controller_nextId(pArrayListPassenger);
			Passenger_setId(auxPassenger, id);

			getString(name, "\nIngresar nombre: \n");
			fflush(stdin);
			Passenger_setName(auxPassenger, name);

			getString(lastName, "\nIngresar apellido: ");
			fflush(stdin);
			Passenger_setLastName(auxPassenger, lastName);

			getFloat(&price, "\nIngresar precio: ", "\nERROR. Ingresar precio válido ($1 - $100.000.000): ", 1, 100000000);
			Passenger_setPrice(auxPassenger, price);

			getString(flyCode, "\nIngresar código de vuelo: ");
			fflush(stdin);
			Passenger_setFlyCode(auxPassenger, flyCode);

			getIntNumber(&typePassengerInt, "\nIngresar tipo de pasajero: \n1. Económico \n2. Primera clase \n3. Ejecutivo\nOpción: ","\nERROR. Ingrese tipo de pasajero válido: ", 1, 3);
			switch(typePassengerInt)
			{
				case 1:
					strcpy(typePassenger,"Económico");
					break;

				case 2:
					strcpy(typePassenger,"Primera clase");
					break;

				case 3:
					strcpy(typePassenger,"Ejecutivo");
					break;
			}
			Passenger_setTipoPasajero(auxPassenger,typePassenger );

			getIntNumber(&statusFlightInt, "\nERROR. Ingrese estado de vuelo válido: \n1. Activo\n2. Demorado\n3. Cancelado\nOpción: ","\nIngrese estado de vuelo: \n1. Activo\n2. Demorado\n3. Cancelado\nOpción: ", 1, 3);
			switch(statusFlightInt)
			{
				case 1:
					strcpy(statusFlight,"Activo");
					break;
				case 2:
					strcpy(statusFlight,"Demorado");
					break;
				case 3:
					strcpy(statusFlight,"Cancelado");
					break;
			}
			Passenger_setStatusFlight(auxPassenger, statusFlight);

			printf("\n----------| LISTA DE PASAJEROS |----------");
			printf("\n| ID |     NOMBRE      |     APELLIDO     |     PRECIO     |     CÓDIGO DE VUELO     |     TIPO DE PASAJERO     |     ESTADO DE VUELO     ");
			controller_mostrarPassenger(auxPassenger);

			getChar(&response, "\n¿Quiere dar de alta al pasajero? (s/n): ", "\nERROR. ¿Quiere dar de alta al pasajero? (s/n): ", 's', 'n');
			if(response == 's')
			{
				ll_add(pArrayListPassenger, auxPassenger);
				controller_saveNextId(id);
				allOk = 1;
				printf("¡ALTA EXITOSA!\n");
			}
			else
			{
				printf("\nSe ha cancelado el alta.");
			}
		}
	}
	return allOk;
}

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	char response = 's';
	int allOk = 0;
	int id;
	char name[51];
	char lastName[51];
	float price;
	int typePassengerInt;
	int statusFlightInt;
	char typePassenger;
	char flyCode;
	char statusFlight;
	int index;

	sPassenger* auxPassenger;

	system("cls");
	printf("\n---------| MODIFICAR PASAJERO |----------");

	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		printf("\nIngrese el ID del pasajero: ");
		scanf("%d", &id);
		while(controller_validarId(pArrayListPassenger, id) == -1)
		{
			printf("\nERROR. ID inválido. Ingrese el ID del pasajero a modificar: ");
			scanf("%d", &id);
		}
		index = buscarPassengerId(pArrayListPassenger, id);
		auxPassenger = ll_get(pArrayListPassenger, index);

		if(index == -1)
		{
			printf("\nNo existe pasajero con ese ID");
		}
		else
		{
			printf("| ID |     NOMBRE      |     APELLIDO     |     PRECIO     |     CÓDIGO DE VUELO     |     TIPO DE PASAJERO     |     ESTADO DE VUELO     ");
			controller_mostrarPassenger(auxPassenger);
			getCharacter(&response, "\n¿Confirma modificación? s/n", "\nERROR. ¿Confirma modificación? s/n", 's', 'n');

			if(response == 's')
			{
				switch(modifyMenu())
				{
					case 1:
						getString(name, "\nIngresa nuevo nombre: ");
						Passenger_setNombre(auxPassenger, name);
						printf("¡MODIFICACIÓN EXITOSA!\n");
						break;

					case 2:
						getString(lastName, "\nIngresa nuevo apellido: ");
						Passenger_setApellido(auxPassenger, lastName);
						break;

					case 3:
						pedirFlotante(&price, "\nIngresa nuevo precio (1-100.000.000): ", "\nERROR. Ingresa nuevo precio (1-100.000.000): ", 1, 100000000);
						Passenger_setPrecio(auxPassenger, price);
						printf("¡MODIFICACIÓN EXITOSA!\n");
						break;

					case 4:
						getString(flyCode, "Ingrese código de vuelo: ");
						Passenger_setCodigoVuelo(auxPassenger, flyCode);
						break;

					case 5:
						getIntNumber(&statusFlightInt, "Enter Status flight\n 1) flying\n 2) Landed \n 3) Delayed flight","error, enter a valid number",1,3);
						switch(statusFlightInt)
						{
							case 1:
								strcpy(statusFlight,"flying");
								break;
							case 2:
								strcpy(statusFlight,"Landed");
								break;
							case 3:
								strcpy(statusFlight,"Delayed flight");
								break;
						}
						Passenger_setStatusFlight(auxPassenger, statusFlight);
						break;
						case 6:
							getIntNumber(&statusFlightInt, "\nERROR. Ingrese estado de vuelo válido: \n1. Activo\n2. Demorado\n3. Cancelado\nOpción: ","\nIngrese estado de vuelo: \n1. Activo\n2. Demorado\n3. Cancelado\nOpción: ", 1, 3);
							switch(statusFlightInt)
							{
								case 1:
									strcpy(statusFlight,"Activo");
									break;
								case 2:
									strcpy(statusFlight,"Demorado");
									break;
								case 3:
									strcpy(statusFlight,"Cancelado");
									break;
							}
							Passenger_setTypePassenger(auxPassenger, typePassenger);
							break;
					default:
						printf("\nOpción inválida");
						break;
				}
			}
			else
			{
				printf("\nSe ha cancelado la modificación");
			}
		}
		allOk = 1;
	}
	return allOk;
}

int controller_valideId(LinkedList* pArrayListPassenger, int id)
{
	int getId;
	int allOk = 0;
	int len;
	sPassenger* auxPassenger;

	if(pArrayListPassenger != NULL && id >= 0)
	{
		len = ll_len(pArrayListPassenger);

		for (int i = 0; i < len; ++i) {

			auxPassenger = ll_get(pArrayListPassenger, id);

			if(auxPassenger != NULL)
			{
				Passenger_getId(auxPassenger, &getId);

				if(id == getId)
				{
					allOk= 1;
					break;
				}
			}
		}
	}
	return allOk;
}

int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int allOk = 0;
	int id;
	char response;
	int index;
	sPassenger* auxPassenger;

	system("cls");
	printf("\n----------| BAJA PASAJERO |----------");
	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		printf("\nIngrese ID del pasajero: ");
		scanf("%d", &id);
		while(controller_validarId(pArrayListPassenger, id) == -1)
		{
			printf("Error. Invalid ID. Enter the ID of the passenger to be removed.");
			scanf("%d", &id);
		}
		index = buscarPassengerId(pArrayListPassenger, id);
		auxPassenger = ll_get(pArrayListPassenger, index);

		if(index == -1)
		{
			printf("The entered ID does not exist\n");
		}
		else
		{
			printf("                                    ***LIST PASSENGER***                 \n");
			printf("-------------------------------------------------------------------------------------------------------------------------\n");
			printf("\n| ID |     NOMBRE      |     APRLLIDO     |     PRECIO     |     CÓDIGO DE VUELO     |     TIPO DE PASAJERO     |     ESTADO DE VUELO     ");
			//controller_mostrarPassenger(auxPassenger);
			getCharacter(&response, "\n¿Confirma baja? s/n", "\nERROR. ¿Confirma baja? s/n", 's', 'n');
			if(response == 's')
			{
				ll_remove(pArrayListPassenger, index);
				Passenger_delete(auxPassenger);
				allOk = 1;
				printf("\n¡BAJA EXITOSA!");
			}
			else
			{
				printf("\nLa baja ha sido cancelada");
			}
		}
	}
	return allOk;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	sPassenger* auxPassenger;
	int allOk = 0;
	if(pArrayListPassenger != NULL)
	{
		system("cls");
		printf("\n----------| LISTA DE PASAJEROS |----------");
		printf("\n| ID |     NOMBRE      |     APELLIDO     |     PRECIO     |     CÓDIGO DE VUELO     |     TIPO DE PASAJEROS     |     ESTADO DE VUELO     ");
		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPassenger = ll_get(pArrayListPassenger, i);
			if(auxPassenger != NULL)
			{
				controller_mostrarPassenger(auxPassenger);
				allOk = 1;
			}
		}
	}
	return allOk;
}

int controller_showPassenger(sPassenger* pArrayListPassenger)
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char typePassenger;
	char flyCode[10];
	char statusFlight;
	int allOk=0;

	if(pArrayListPassenger != NULL)
	{
		Passenger_getId(pArrayListPassenger, &id);
		Passenger_getName(pArrayListPassenger, name);
		Passenger_getLastName(pArrayListPassenger, lastName);
		Passenger_getPrice(pArrayListPassenger, &price);
		Passenger_getflyCode(pArrayListPassenger, flyCode);
		Passenger_getTypePassenger(pArrayListPassenger, typePassenger);
		Passenger_getStatusFlight(pArrayListPassenger, statusFlight);
		printf("\n%d   %s     %s     %f     %s     %s     %s ", id, name, lastName, price, flyCode, typePassenger, statusFlight);
		allOk=1;
	}
	return allOk;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int allOk = 0;
	int critery;
	LinkedList* sort;
	if(pArrayListPassenger != NULL)
	{
		sort = ll_clone(pArrayListPassenger);
		critery = menuDeSort();

		switch(menuDeOrdenamiento())
		{
			case 1:
				ll_sort(sort, Passenger_SortId, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso!!n");
				break;
			case 2:
				ll_sort(sort, Passenger_SortName, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso!!");
				break;
			case 3:
				ll_sort(sort, Passenger_SortLastName, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso!!");
				break;
			case 4:
				ll_sort(sort, Passenger_SortPrice, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso!!");
				break;
			case 5:
				ll_sort(sort, Passenger_SortFlyCode, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso!!");
				break;
			case 6:
				ll_sort(sort, Passenger_SortTypePassenger, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso!!");
				break;
			case 7:
				ll_sort(sort, Passenger_SortStatusFlight, critery);
				printf("\nUn momento, la lista está siendo procesada...");
				controller_ListPassenger(sort);
				printf("\nOrden exitoso!!");
				break;
			case 8:
				printf("\nOrden cancelado");
				break;
			default:
				printf("\nOpción inválida");
				break;
		}
		ll_deleteLinkedList(sort);
		allOk = 1;
	}

    return allOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	sPassenger* auxPassenger ;
	FILE* pFile;
	int id;
	char name[51];
	char lastName[51];
	float price;
	char typePassenger;
	char flyCode[10];
	char statusFlight;
	int allOk = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "w");

		auxPassenger = Passenger_new();

		fprintf(pFile, "\n| ID | NOMBRE | APELLIDO | PRECIO | CÓDIGO D EVUELO | TIPO DE PASAJERO | ESTADO DE VUELO |");

		for(int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPassenger = ll_get(pArrayListPassenger, i);
			if(auxPassenger != NULL)
			{
				Passenger_getId(auxPassenger, &id);
				Passenger_getName(auxPassenger, name);
				Passenger_getLastName(auxPassenger, lastName);
				Passenger_getPrice(auxPassenger, &price);
				Passenger_getFlyCode(auxPassenger, flyCode);
				Passenger_getTypePassenger(auxPassenger, typePassenger);
				Passenger_getStatusFlight(auxPassenger, statusFlight);
				fprintf(pFile, "\n| %d | %s | %s | %f | %s | %s | %s |", id, name, lastName, price, flyCode, typePassenger, statusFlight);
				allOk = 1;
			}
			else
			{
				allOk = 0;
				break;
			}
		}
		fclose(pFile);
	}
	return allOk;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int allOk = 0;
	FILE* pFile;
	sPassenger* auxPassenger ;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "wb");
		auxPassenger = Passenger_new();
		if(auxPassenger != NULL)
		{
			for(int i = 0; i < ll_len(pArrayListPassenger); i++)
			{
				auxPassenger = ll_get(pArrayListPassenger, i);
				fwrite(auxPassenger, sizeof(sPassenger), 1, pFile);
			}
			allOk = 1;
		}
		fclose(pFile);
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

    fprintf(file, "%d", id);
    fclose(file);
}

int controller_nextId(LinkedList* pArrayListPassenger)
{
	FILE* file = fopen("ultimoID.txt", "r");
	int* currentId=(int*) malloc(sizeof(int));
    int nextId;

    if(file ==NULL)
    {
    	nextId = 0;
    }
    else
    {
        fscanf(file, "%d", currentId);
        nextId = *currentId + 1;
    }
    fclose(file);
    return nextId;
}


int controller_getMaxId(FILE* pFile)
{
	int maxId = 0;
	sPassenger* auxPassenger = NULL;
	int r = 0;
	char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50],var7[50];
	pFile = fopen("data.csv", "r");
	if(pFile == NULL)
	{
		printf("\nArchivo nulo");
	}
	else
	{
		//lectura fantasma
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7);
		//printf("%s	%s	%s	%s	%s	%s	%s\n\n",var1,var2,var3,var4,var5,var6,var7);
		while(!feof(pFile))
		{

			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7);
			if(r < 7)
			{
				break;
			}

			auxPassenger = Passenger_newParametros(var1,var2,var3,var4,var5,var6,var7);

			if(auxPassenger != NULL)
			{
				maxId++;
			}
		}
		fclose(pFile);
	}
	return maxId;
}



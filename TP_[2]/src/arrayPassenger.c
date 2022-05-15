/*
 * arrayPassenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: Fiorella Aguayo
 */

#include <stdio.h>
#include <stdlib.h>
#include "validation.h"
#include "arrayPassenger.h"
#include <string.h>


int menu()
{
    int option;
    system("cls");
    printf("\n\t\t*** ABM PASAJEROS ***\n");
    printf("  1- ALTA.\n");
    printf("  2- BAJA.\n");
    printf("  3- MODIFICAR.\n");
    printf("  4- INFORMAR.\n");
    printf("  5- CARGA FORZADA.\n");
    printf("  6- SALIR.\n");

    printf("Ingrese opción: ");
    scanf("%d", &option);

    return option;
}

int menuModificar()
{
    int option;

    printf("  1- nombre.\n");
    printf("  2- apellido.\n");
    printf("  3- precio.\n");
    printf("  4- código de vuelo.\n");
    printf("  5- tipo de pasajero.\n");
    printf("  5- estado de vuelo.\n");

    printf("Ingrese opción: ");
    scanf("%d", &option);

    return option;
}


int subMenu(Passenger* list, int len)
{
	int allOk=0;
	int option;
	int order;

	if(list != NULL && len > 0)
	{

			printf("   1.Mostrar pasajeros ordenados por Apellido y tipo\n");
		    printf("   2.Mostrar pasajeros ordenados por Codigo de vuelo y\n");
		    printf("   3.Mostrar precio total y precio promedio de los pasajes \n");
		    printf("   4.Mostrar pasajeros por codigo de vuelo y vuelo activo \n");


		    printf("Ingrese opcion: ");
		    scanf("%d", &option);

		    switch(option)
		    {
				case 1:
					printf("Ingrese en qué órden lo quiere: 0-ascendente  1-descendente");
					scanf("%d", &order);
					sortPassengers(list, len, order);
					showPassengers(list, len);
					break;
				case 2:
					printf("Ingrese en qué órden lo quiere: 0-ascendente  1-descendente");
					scanf("%d", &order);
					sortPassengersByCode(list , len, order);
					showPassengers(list, len);
					break;
				case 3:
					pricePromedy(list, len);
					break;
				case 4:
					listFlyCodeStatus(list ,len);
					break;
				default:
					printf("Opcion invalida.");
					break;
		    }
	allOk = 1;
	}

		    return allOk;

}


int initPassengers(Passenger* list, int len)
{
    int todoOk = 0;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        todoOk = 1;
    }

    return todoOk;
}

int findFreeSpace(Passenger* list, int len)
{
    int freeSpace = -1; //es porque está ocupado

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                freeSpace = i; //pongo su indice
                break; //un break porque es la búsqueda de la primer estructura vacía
            }
        }
    }

    return freeSpace;
}

int addPassenger(Passenger* list, int len, int* id)
{
    int allOk = 0;
    int freeSpace;
    Passenger auxPassenger;

    if(list != NULL && len > 0 && id != NULL)
    {
        system("cls");
        printf("\t *** ALTA PERSONA *** \n");

        freeSpace = findFreeSpace(list, len);
        if(freeSpace == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            auxPassenger.id = *id;
            (*id)++;

            printf("Ingrese nombre: ");   //CHAR
            fflush(stdin);
            gets(auxPassenger.name);

            printf("Ingrese apellido: ");   //CHAR
            fflush(stdin);
            gets(auxPassenger.lastName);

            printf("Ingrese precio: ");      //FLOAT
            fflush(stdin);
            scanf("%f", &auxPassenger.price);

            printf("Ingrese código de vuelo: "); //CHAR
            fflush(stdin);
            gets(auxPassenger.flycode);

            printf("Ingrese tipo de pasajero: ");  //INT
            fflush(stdin);
            scanf("%d", &auxPassenger.typePassenger);

            printf("Ingrese estado de vuelo: ");   //INT
            fflush(stdin);
            scanf("%d", &auxPassenger.statusFlight);

            auxPassenger.isEmpty = 0;
            list[freeSpace] = auxPassenger;

            allOk = 1;
        }
    }
    return allOk;
}

int findPassengerById(Passenger* list, int len, int* id)
{
    int freeSpace = -1; //es porque está ocupado

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(!list[i].isEmpty && list[i].id == *id) //está vacía
            {
                freeSpace = i; //pongo su indice
                break; //un break porque es la búsqueda de la primer estructura vacía
            }
        }
    }
    return freeSpace;
}

int removePassenger(Passenger* list, int len)
{
    int allOk = 0;
    int id;
    int index;
    char confirm;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("\t *** BAJA PERSONA *** \n\n");
        printf("Ingrese ID: ");
        scanf("%d", &id);

        index = findPassengerById(list, len, &id);

        if(index == -1)
        {
            printf("No existe un pasajero con ID: %d", id);
        }
        else
        {
            showPassenger(list[index]);

            printf("¿Confirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirm);

            if(confirm == 's')
            {
                list[index].isEmpty = 1;
                allOk = 1;
            }
            else
            {
                printf("Se ha cancelado la baja");
            }
        }
    }

    return allOk;
}

void showPassenger(Passenger unaPersona)
{
    printf("%d  %10s  %16s  %12.2f  %23s  %23d  %21d \n",
           unaPersona.id,    //INT
           unaPersona.name,  //CHAR
           unaPersona.lastName, //CHAR
           unaPersona.price,  //FLOAT
           unaPersona.flycode, //CHAR
           unaPersona.typePassenger, //INT
           unaPersona.statusFlight); //INT
    printf("******************************************************************************************************************************\n");
}


int showPassengers(Passenger* list, int len)
{
    int allOk = 0;
    int flag = 1;
    if(list != NULL && len > 0)
    {
        system("cls");
        printf("\t *** LISTADO DE PERSONAS ***\n");
        printf("ID \t NOMBRE \t APELLIDO \t PRECIO \t CÓDIGO DE VUELO \t TIPO DE PASAJERO \t ESTADO DE VUELO\n");
        printf("******************************************************************************************************************************\n");
        for(int i = 0; i < len; i++)
        {
            if(!list[i].isEmpty) // esta estructura está vacía? no, entonces muestro// es igual a 0 // 1 negado
            {
                showPassenger(list[i]);
                flag = 0;
            }
        }
        if(flag) //vale 1
        {
            printf(" NO HAY PERSONAS PARA MOSTRAR \n");
        }
        allOk = 1;
    }
    return allOk;
}

void hardcodePassengers(Passenger list[])
{
	Passenger aux[]= {
						{100,"Fiorella", "Aguayo", 12000, "AERT4",1,1,0},
						{101,"Jose", "Brites", 20000.50,"JUFH8",3,2,0},
						{102,"Ana", "Lorenzo", 42000.30,"MKHFW",2,1,0},
						{103,"Pablo","Ledesma",15000.80,"GJDO2",1,2,0},
						{104,"Agustin","Cantos",60000,"OPFJL",3,1,0}
	                  };

	for(int i = 0; i < 5; i++)
	{
		list[i] = aux[i];
	}
}

int modificarPassenger(Passenger* list, int len)
{
    system("cls");
    int allOk = 0;
    int id;
    int index;
    char confirm;
    char auxName[51];
    char auxLastName[51];
    float auxPrice;
    char auxFlyCode[10];
    int auxTypePassenger;
    int auxStatusFlight;

    printf("Ingrese ID que quiera modificar: ");
    scanf("%d", &id);

    index = findPassengerById(list, len, &id);

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("\t *** MODIFICAR PERSONA *** \n\n");
        printf("Ingrese ID: ");
        scanf("%d", &id);

        index = findPassengerById(list, len, &id);

        if(index == -1)
        {
            printf("No existe un pasajero con ID: %d", id);
        }
        else
        {
            showPassenger(list[index]);

            printf("¿Confirma modificación?: ");
            fflush(stdin);
            scanf("%c", &confirm);

            if(confirm == 's')
            {
                switch(menuModificar())
                {
                    case 1:
                        pedirCadena(auxName, "Ingrese nuevo nombre: ");
                        validarLetras(auxName);
                        primerLetraMayuscula(auxName);
                        strcpy(list[index].name, auxName);
                        break;

                    case 2:
                        pedirCadena(auxLastName, "Ingrese nuevo apellido: ");
                        validarLetras(auxLastName);
                        primerLetraMayuscula(auxLastName);
                        strcpy(list[index].lastName, auxLastName);
                        break;

                    case 3:
                        pedirFlotante(&auxPrice, "Ingrese nuevo precio: ", "ERROR. Reingrese nuevo precio:", 1000, 100000);
                        list[index].price = auxPrice;
                        break;

                    case 4:
                        pedirCadena(auxFlyCode, "Ingrese nuevo código de vuelo: ");
                        validarLetras(auxFlyCode);
                        primerLetraMayuscula(auxFlyCode);
                        strcpy(list[index].flycode, auxFlyCode);
                        break;
                    case 5:
                        pedirEntero(&auxTypePassenger, "Ingrese nuevo tipo de pasajero: 1- niño 2-adulto 3-anciano ", "ERROR. Reingrese nuevo tipo de pasajero:  1- niño 2-adulto 3-anciano ", 1, 3);
                        list[index].typePassenger = auxTypePassenger;
                        break;
                    case 6:
                        pedirEntero(&auxStatusFlight, "Ingrese nuevo estado de vuelo: 1-activo 2-demorado 3-cancelado", "ERROR. Reingrese nuevo estado de vuelo: 1-activo 2-demorado 3-cancelado", 1, 3);
                        list[index].statusFlight = auxStatusFlight;
                        break;

                    default:
                        printf("Opción inválida\n");
                }
                list[index].isEmpty = 1;
                allOk = 1;
            }
            else
            {
                printf("Se ha cancelado la baja");
            }
        }
    }

    return allOk;
}

int sortPassengers(Passenger* list, int len, int order)
{
    int allOk = 0;
    Passenger aux;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
            	if(order == 0) //ascendente
            	{
            		if((strcmp(list[i].lastName, list[j].lastName) > 0) || ((strcmp(list[i].lastName, list[j].lastName) == 0) && list[i].typePassenger > list[j].typePassenger))
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
            	}
            	else
            	{
            		if(order == 1) //descendente
            		{
            			if((strcmp(list[i].lastName, list[j].lastName) < 0) || ((strcmp(list[i].lastName, list[j].lastName) == 0) && list[i].typePassenger < list[j].typePassenger))
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
            		}
            	}
            }
        }
        allOk = 1;
    }

    return allOk;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int allOk = 0;
	Passenger aux;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len - 1; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if(order == 0) //ascendente
				{
					if((strcmp(list[i].flycode, list[j].flycode) > 0) || ((strcmp(list[i].flycode, list[j].flycode) == 0) && list[i].statusFlight > list[j].statusFlight))
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
				else
				{
					if(order == 1) //descendente
					{
						if((strcmp(list[i].flycode, list[j].flycode) < 0) || ((strcmp(list[i].flycode, list[j].flycode) == 0) && list[i].statusFlight < list[j].statusFlight))
						{
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
		}
		allOk = 1;
	}

    return allOk;
}

int pricePromedy(Passenger* list, int len)
{
	int allOk =0;
	float acumulator = 0;
	int acount = 0;
	float average = 0;
	int highPrice = 0;

	if(list !=NULL && len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				acumulator += list[i].price;
				acount++;
				allOk = 1;
			}
		}
		if(acount !=0)
		{
			average = acumulator/acount;
		}
		else
		{
			printf("No se ingresó ningún pasajero \n");
		}

		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].price > average)
			{
				highPrice++;
			}
		}

		printf("La suma total de precio es %.2f \n", acumulator);
		printf("El promedio de precio es %.2f \n", average);
		printf("Hay un total de pasajeros con un precio de pasaje mayor al promedio de %d", highPrice);
	}
	return allOk;
}

int listFlyCodeStatus(Passenger* list, int len)
{
	int todoOk=0;

	if(list !=NULL && len>0)
	{
		for(int i=0; i<len;i++)
		{
			if(list[i].isEmpty == 1 && list[i].statusFlight == 1)
			{
				showPassenger(list[i]);
			}
		}

	}
	return todoOk;
}

int reset(Passenger* list, int len, int* flag)
{
	int allOk  = 0;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				*flag = 1;
				allOk = 1;
				break;
			}
			else
			{
				*flag = 0;
			}
		}
	}
	return allOk;
}




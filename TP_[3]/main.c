#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"
#include "funcionesUTN.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);
	char response = 's';
    int contadorDePasajeros = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
        switch(optionMenu())
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                contadorDePasajeros = ll_len(listaPasajeros);
                break;
            case 2:
            	controller_loadFromBinary("data.bin",listaPasajeros);
            	contadorDePasajeros = ll_len(listaPasajeros);
				break;
            case 3:
            	controller_addPassenger(listaPasajeros, "data.csv");
            	contadorDePasajeros = ll_len(listaPasajeros);
				break;

            	break;
            case 4:
            	if(contadorDePasajeros > 0)
				{
					controller_editPassenger(listaPasajeros);
				}
				else
				{
					printf("\nNo se han cargado pasajeros en el sistema");
				}
				break;
            case 5:
            	if(contadorDePasajeros > 0)
				{
				controller_removePassenger(listaPasajeros);
				}
				else
				{
					printf("\nNo se han cargado pasajeros en el sistema");
				}
				break;
            case 6:
            	if(contadorDePasajeros > 0)
				{
					controller_ListPassenger(listaPasajeros);
				}
				else
				{
					printf("\nNo se han cargado pasajeros en el sistema");
				}
				break;
            case 7:
            	if(contadorDePasajeros > 0)
				{
					controller_sortPassenger(listaPasajeros);
				}
				else
				{
					printf("\nNo se han cargado pasajeros en el sistema");
				}
				break;
            case 8:
				controller_saveAsText("data.csv", listaPasajeros);
				break;
			case 9:
				controller_saveAsBinary("data.bin", listaPasajeros);
				break;
			case 10:
				response = 'n';
				printf("\nSalida exitosa");
				break;
			default:
				printf("\n¡Opción inválida!");
				break;
        }
    }while(response == 's');
    ll_deleteLinkedList(listaPasajeros);
    return 0;
}



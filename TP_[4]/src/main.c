/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main(void)
{
	startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort



    int respuestaMenuPrincipal;
    int option;
    int flagText = 0;
    int FlagBinary = 0;
	int flagGetInto = 0;
	char seguir = 'n';

    LinkedList* lista = ll_newLinkedList();
    do{
    		respuestaMenuPrincipal=getNumero(&option, "\nMENU DE OPCIONES\nIngrese una opción \n 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto). \n 2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario). \n 3. Alta de pasajero \n 4. Modificar datos de pasajero \n 5. Baja de pasajero \n 6. Listar pasajeros \n 7. Ordenar pasajeros \n 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto). \n 9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario). \n 10. Salir\n", "reingrese la opcion elegida", 1, 10, 3);
    		if(respuestaMenuPrincipal==0)
    		{
    			switch(option)
    			{
				case 1:
					flagText=1;
					controller_loadFromText("data.csv",lista);
					break;

				case 2:
					if(FlagBinary == 0 && flagText == 1)
					{
						printf("\nERROR. Ya se cargó modo texto");
					}
					else if(FlagBinary == 0)
					{
						controller_loadFromBinary("data.bin", lista);
						FlagBinary = 1;
					}
					else
					{
						printf("ERROR. No se pued");
					}
					break;

				case 3:
					controller_addPassenger(lista,"data.csv");
					break;

				case 4:
					if(lista->size)
					{
						controller_editPassenger(lista);
					}
					else
					{
						printf("\nNo se ingresaron pasajeros para modificar");
					}
					break;

				case 5:
					if(lista->size)
					{
						controller_removePassenger(lista);
					}
					else
					{
						printf("\nNo se ingresaron pasajeros");
					}
					break;

				case 6:
					if(lista->size)
					{
						controller_ListPassenger(lista);
					}
					else
					{
						printf("\nNO se ingresaron pasajeros");
					}
					break;

				case 7:
					if(lista->size)
					{
						controller_sortPassenger(lista);
					}
					else
					{
						printf("\nNO se ingresaron pasajeros");
					}
					break;

				case 8:
					if(lista->size)
					{
						controller_saveAsText("data.csv", lista);
						printf("\nGuardado con éxito");
					}
					else
					{
						printf("\nNo se ingresaron pasajeros");
					}
					flagGetInto = 1;
					break;

				case 9:
					if(lista->size)
					{
						controller_saveAsBinary("data.bin", lista);
						printf("\nGuardado con éxito");
					}
					else
					{
						printf("\nNo se ingresaron pasajeros");
					}
					flagGetInto = 1;
					break;

				case 10:
					if(flagGetInto == 1)
					{
						pedirCaracter(&seguir, "¿Esta seguro que desea salir? s/n.", "ERROR ¿Esta seguro que desea salir? s/n.", 's', 'n');
						fflush(stdin);
						if(seguir == 's')
						{
							ll_deleteLinkedList(lista);
							//SALIR
						}
					}
					else
					{
						printf("\nNo se han guardado pasajeros");
					}
					break;

				default:
					printf("\n¡opción inválida!");
					break;
    			}
    		}
    }while(seguir == 'n');
    return 0;
}


































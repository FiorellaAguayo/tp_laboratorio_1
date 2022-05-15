#include <stdio.h>
#include <stdlib.h>
#include "validation.h"
#include "arrayPassenger.h"
#include <string.h>
#define LEN 2000

int main()
{
	setbuf(stdout, NULL);

    char keep = 's';
    int nextId = 1;
    Passenger list[LEN];
    int flag = 0;


    if(!initPassengers(list, LEN))
    {
        printf("\nOcurrió un error en la inicialización.");
    }


    while(keep == 's')
    {
        switch(menu())
        {
            case 1:
                if(addPassenger(list, LEN, &nextId))
                {
                    printf("ALTA EXITOSA !!!\n");
                    flag = 1;
                }
                else
                {
                    printf("Hubo un problema al hacer el alta !!!\n");
                }
                break;

            case 2:
            	if(flag==0)
            	{
            		printf("No hay ningún pasajero para dar de baja\n");

            	}
            	else
            	{
            		  if(removePassenger(list, LEN))
            		  {
            			  printf("BAJA EXITOSA !!!\n");
            			  reset(list, LEN, &flag);
            		  {
            	}

                break;

            case 3:
            	if(flag==0)
				{
					printf("No hay ningún pasajero para modificar\n");

				}
            	else
            	{
            		if(modificarPassenger(list, LEN))
					{
						printf("MODIFICACIÓN EXITOSA !!!\n");
					}
            	}
                break;

            case 4:
					if(flag==0)
					{
						printf("No hay pasajeros para mostrar");
					}
					else
					{
						if( subMenu(list, LEN))
						{
							printf("LISTADO EXITOSO");
						}
					}
                break;

            case 5:
            	 	 hardcodePassengers(list);
            	 	 printf("CARGA FORZADA EXITOSA\n");
            	 	 flag = 1;
            	break;

            case 6:
                keep = 'n';
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
      system("pause");
     }
    }
   }

    return EXIT_SUCCESS;
}


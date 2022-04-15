/*
 ============================================================================
 Name        : TP.c
 Author      : AGUAYO FIORELLA
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"
#include "validaciones.h"

int main()
{
	setbuf(stdout, NULL);

    char respuesta = 'n';
    int numeroKM;
    float precioAerolinea;
    float precioLATAM;
    float descuentoAerolinea;
    float descuentoLATAM;
    float interesAerolinea;
    float interesLATAM;
    float precioAerolineasKM;
    float precioLatamKM;
    float bitcoinLATAM;
    float bitcoinAerolinea;
    float diferencia;
    int flag = 0;
    int respuestaMenu;
    int opcion;

    do
    {
    	respuestaMenu=getNumero(&opcion, "\n----------------------------------\n-        MENU VIAJES             -\n----------------------------------\n1) Ingresar Kilómetros. \n2) Ingresar Precio de Vuelos. (Aerolíneas=y, Latam=z)\n3) Calcular todos los costos.\n4) Informar Resultados.\n5) Carga forzada de datos.\n6) Salir.\nElija la opción: ", "Error. Reingrese opción: ", 1, 6, 9 );
		if(respuestaMenu == 0)
		{
			switch(opcion)
			{
				case 1:
					if(flag == 0)
					{
						numeroKM = pedirKilometros();
						flag = 1;
					}
					else
					{
						printf("Ya ingresaste kilómetros: \n");
					}
					break;
				case 2:
					if(flag == 1)
					{
						precioViaje(&precioAerolinea, &precioLATAM);
						flag = 2;
					}
					else
					{
						printf("Ya ingresaste datos. \n");
					}
					break;
				case 3:
					if(flag == 2)
					{
						//costos descuento
						descuentoAerolinea = tarjetaDebito(precioAerolinea);
						descuentoLATAM = tarjetaDebito(precioLATAM);

						//costos de interés
						interesAerolinea = tarjetaCredito(precioAerolinea);
						interesLATAM = tarjetaCredito(precioLATAM);

						bitcoinAerolinea = bitcoin(precioAerolinea);
						bitcoinLATAM = bitcoin(precioLATAM);

						precioAerolineasKM = precioPorKilometro(precioAerolinea, numeroKM);
						precioLatamKM = precioPorKilometro(precioLATAM, numeroKM);

						diferencia = diferenciaPrecio(precioAerolinea, precioLATAM);
						flag = 3;

						printf("Se calculó todo perfecto. ");
					}
					else
					{
						printf("Ya ingresó datos");
					}
					break;
				case 4:
					if(flag == 3)
					{
						mostrarResultados(precioAerolinea, numeroKM, descuentoAerolinea, interesAerolinea, bitcoinAerolinea, precioAerolineasKM, precioLATAM, descuentoLATAM, interesLATAM, bitcoinLATAM, precioLatamKM, diferencia);
						flag = 0;
						system("pause");
					}
					else
					{
						printf("ya ingresó");
					}
					break;
				case 5:
					cargaForzada();
					break;
				case 6:
					getCaracter(&respuesta, "¿Estas seguro que desea salir? s/n: ", "ERROR. Ingrese s/n: ", 's', 'n');
					break;
			}
			system("pause");
		}

    }while(respuesta == 'n');

    return EXIT_SUCCESS;
}

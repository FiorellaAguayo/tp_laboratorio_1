/*
 * miBiblioteca.c
 *
 *  Created on: 12 abr. 2022
 *      Author: AGUAYO FIORELLA
 */

#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

int pedirKilometros()
{
    int km;
    printf("Ingrese kilómetros: ");
    scanf("%d", &km);

    return km;
}

int precioViaje(float* y, float* z)
{
    float precioA;
    float precioL;
    int esValido = 0;

    if(y != NULL && z != NULL)
    {
        printf("Ingrese precio de Aerolínea: ");
        scanf("%f", &precioA);

        *y = precioA;

        printf("Ingrese precio de LATAM: ");
        scanf("%f", &precioL);

        *z = precioL;

        esValido = 1;
    }

    return esValido;
}

float tarjetaDebito(int precioViaje)
{
    float resultado;
    float descuento;

    resultado = precioViaje*10/100;
    descuento = precioViaje - resultado;

    return descuento;

}

float tarjetaCredito(int precioViaje)
{
    float resultado;
    float interes;

    resultado = precioViaje*25/100;
    interes = precioViaje + resultado;

    return interes;
}

float bitcoin(float precioViaje)
{
    float resultadoBitcoin;

    resultadoBitcoin = precioViaje/4606954.55;

    return resultadoBitcoin;
}

float precioPorKilometro(float precioViaje, float km)
{
    float precioPorKm;

    precioPorKm = precioViaje/km;

    return precioPorKm;
}

float diferenciaPrecio(float aerolinea, float latam)
{
    float diferencia;
    float maximo;
    float minimo;

    if(aerolinea > latam)
    {
        maximo = aerolinea;
        minimo = latam;
    }
    else
    {
        maximo = latam;
        minimo = aerolinea;
    }

    diferencia = maximo - minimo;

    return diferencia;
}

void mostrarResultados(float precioA, float km, float debitoAEROLINEAS, float creditoAEROLINEAS, float bitcoinAEROLINEAS, float unitarioAEROLINEAS, float precioL, float debitoLATAM, float creditoLATAM, float bitcoinLATAM, float unitarioLATAM, float diferencia)
{
    //system("cls");
    printf("\nPRECIO AEROLINEAS: %f\n", precioA);
    printf("KMs Ingresados: %.2f km\n", km);
    printf("a) Precio con tarjeta de débito: $%.2f\n", debitoAEROLINEAS);
    printf("b) Precio con tarjeta de crédito: $%.2f\n", creditoAEROLINEAS);
    printf("c) Precio pagando con bitcoin : %f BTC\n", bitcoinAEROLINEAS);
    printf("d) Precio unitario: $%.2f\n", unitarioAEROLINEAS);

    printf("\nPRECIO LATAM: %f\n", precioL);
    printf("a) Precio con tarjeta de débito: $%.2f\n", debitoLATAM);
    printf("b) Precio con tarjeta de crédito: $%.2f\n", creditoLATAM);
    printf("c) Precio pagando con bitcoin : %f BTC\n", bitcoinLATAM);
    printf("d) Precio unitario: $%.2f\n", unitarioLATAM);
    printf("La diferencia de precio es : $%.2f\n", diferencia);
}

void cargaForzada()
{
    //system("cls");
    printf("\n“Latam: $159339\n");
    printf("KMs Ingresados: 7090 km\n");
    printf("a) Precio con tarjeta de débito: $%.2f\n", tarjetaDebito(159339));
    printf("b) Precio con tarjeta de crédito: $%.2f\n", tarjetaCredito(159339));
    printf("c) Precio pagando con bitcoin : %f BTC\n", bitcoin(159339));
    printf("d) Precio unitario: $%.2f\n\n", precioPorKilometro(159339, 7090));

    printf("Aerolíneas: $162965\n");
    printf("a) Precio con tarjeta de débito: $%.2f\n", tarjetaDebito(162965));
    printf("b) Precio con tarjeta de crédito: $%.2f\n", tarjetaCredito(162965));
    printf("c) Precio pagando con bitcoin : %f BTC\n", bitcoin(162965));
    printf("d) Precio unitario: $%.2f\n", precioPorKilometro(162965, 7090));
    printf("La diferencia de precio es : $%.2f “\n", diferenciaPrecio(162965, 159339));
}




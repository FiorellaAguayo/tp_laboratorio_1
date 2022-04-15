/*
 * miBiblioteca.h
 *
 *  Created on: 12 abr. 2022
 *      Author: AGUAYO FIORELLA
 */

#ifndef MIBIBLIOTECA_H_
#define MIBIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>


#endif /* MIBIBLIOTECA_H_ */

/*------------------------------------------------------- PEDIR KILOMETROS ------------------------------------------------------------------*/

/**
 * @fn int pedirKilometros()
 * @brief Función que sirve para guardar los kilómetros ingresados por el usuario.
 *
 * @return int Retorna el valor ingresado por el usuario.
 */
int pedirKilometros();




/*------------------------------------------------------- PRECIO DE VIAJE -----------------------------------------------------------------------------------*/

/**
 * @fn int precioViaje(float*, float*)
 * @brief Función que sirve para guardar el precio de viaje en la aerolínea elegida.
 *
 * @param float x Precio de Aerolíneas ingresado por el usuario.
 * @param float z Precio de LATAM ingresado por el usuario.
 * @return Retorna 1 si es válido y si falló.
 */
int precioViaje(float* x, float* z);




/*------------------------------------------------------- TARJETA DE DÉBITO ----------------------------------------------------------------------------------*/

/**
 * @fn float tarjetaDebito(int)
 * @brief Función que sirve para calcular un descuento del 10% al precio ingresado.
 *
 * @param int precioViaje Precio ingresado por el usuario.
 * @return float descuento Retorna el precio ingresado con descuento.
 */
float tarjetaDebito(int precioViaje);




/*------------------------------------------------------- TARJETA DE CRÉDITO ---------------------------------------------------------------------------------*/

/**
 * @fn float tarjetaCredito(int)
 * @brief Función que sirve para calcular el precio ingresado con un interés del 25%.
 *
 * @param int precioViaje Precio ingresado por el usuario.
 * @return float interes Retorna el precio ingresado con interés.
 */
float tarjetaCredito(int precioViaje);




/*------------------------------------------------------- PRECIO EN BITCOIN --------------------------------------------------------------------------------*/
/**
 * @fn float bitcoin(float)
 * @brief Función que sirve para calcular el precio ingresado en valor de bitcoin.
 *
 * @param float precioViaje Valor entero que ingresa el usuario.
 * @return float resultadoBitcoin Retorna el precio ingresado en bitcoin.
 */
float bitcoin(float precioViaje);




/*------------------------------------------------------- PRECIO POR KILÓMETRO -------------------------------------------------------------------------------*/

/**
 * @fn float precioPorKilometro(float, float)
 * @brief Función que sirve para calcular el precio unitario (precio del viaje según los kilómetros).
 *
 * @param float precioViaje Variable que guarda el precio que ingresa el usuario.
 * @param float km Variable que guarda los kilómetros ingresados por el usuario.
 * @return float precioPorKm Retorna el precio por kilómetros.
 */
float precioPorKilometro(float precioViaje, float km);




/*-------------------------------------------------------- DIFERENCIA DE PRECIO -----------------------------------------------------------------------------*/

/**
 * @fn float diferenciaPrecio(float, float)
 * @brief Función que sirve para calcular la diferencia de precio ingresado para ambas aerolíneas.
 *
 * @param float aerolinea Variable que guarda el precio de viaje en Aerolíneas.
 * @param float latam Variable que guarda el precio de viaje en LATAM.
 * @return float diferencia Retorna la diferencia de precio.
 */

float diferenciaPrecio(float aerolinea, float latam);




/*---------------------------------------------------------- MOSTRAR RESULTADOS ----------------------------------------------------------------------------*/

/**
 * @fn void mostrarResultados(float, float, float, float, float, float, float, float, float, float)
 * @brief Función que sirve para mostrar los resultados.
 *
 * @param float km Variable que guardó kilómetros ingresados.
 * @param float debitoLATAM Variable que guardó el descuento para precio ingresado de LATAM.
 * @param float creditoLATAM Variable que guardó el interés para precio ingresado de LATAM.
 * @param float bitcoinLATAM Variable que guardó en bitcoin el precio ingresado de LATAM.
 * @param float unitarioLATAM Variable que guardó el precio unitario para vuelos de LATAM.
 * @param float debitoAEROLINEAS Variable que guardó el descuento para precio ingresado de Aerolíneas.
 * @param float creditoAEROLINEAS Variable que guardó el interés para precio ingresado de Aerolíneas.
 * @param float bitcoinAEROLINEAS Variable que guardó en bitcoin el precio ingresado de Aerolíneas.
 * @param float unitarioAEROLINEAS Variable que guardó el preico unitario para vuelos de Aerolíneas.
 * @param float diferencia Varibale que guardó la diferencia de precio entre ambas aerolíneas.
 * @return void No retorna nada.
 */
void mostrarResultados(float precioA, float km, float debitoAEROLINEAS, float creditoAEROLINEAS, float bitcoinAEROLINEAS, float unitarioAEROLINEAS, float precioL, float debitoLATAM, float creditoLATAM, float bitcoinLATAM, float unitarioLATAM, float diferencia);




/*------------------------------------------------------------- CARGA FORZADA ----------------------------------------------------------------------------*/

/**
 * @fn void cargaForzada()
 * @brief Función que sirve para mostrar el hardcodeo de datos.
 * @return void No retorna nada.
 */
void cargaForzada();





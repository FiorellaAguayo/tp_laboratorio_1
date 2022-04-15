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
 * @brief Funci�n que sirve para guardar los kil�metros ingresados por el usuario.
 *
 * @return int Retorna el valor ingresado por el usuario.
 */
int pedirKilometros();




/*------------------------------------------------------- PRECIO DE VIAJE -----------------------------------------------------------------------------------*/

/**
 * @fn int precioViaje(float*, float*)
 * @brief Funci�n que sirve para guardar el precio de viaje en la aerol�nea elegida.
 *
 * @param float x Precio de Aerol�neas ingresado por el usuario.
 * @param float z Precio de LATAM ingresado por el usuario.
 * @return Retorna 1 si es v�lido y si fall�.
 */
int precioViaje(float* x, float* z);




/*------------------------------------------------------- TARJETA DE D�BITO ----------------------------------------------------------------------------------*/

/**
 * @fn float tarjetaDebito(int)
 * @brief Funci�n que sirve para calcular un descuento del 10% al precio ingresado.
 *
 * @param int precioViaje Precio ingresado por el usuario.
 * @return float descuento Retorna el precio ingresado con descuento.
 */
float tarjetaDebito(int precioViaje);




/*------------------------------------------------------- TARJETA DE CR�DITO ---------------------------------------------------------------------------------*/

/**
 * @fn float tarjetaCredito(int)
 * @brief Funci�n que sirve para calcular el precio ingresado con un inter�s del 25%.
 *
 * @param int precioViaje Precio ingresado por el usuario.
 * @return float interes Retorna el precio ingresado con inter�s.
 */
float tarjetaCredito(int precioViaje);




/*------------------------------------------------------- PRECIO EN BITCOIN --------------------------------------------------------------------------------*/
/**
 * @fn float bitcoin(float)
 * @brief Funci�n que sirve para calcular el precio ingresado en valor de bitcoin.
 *
 * @param float precioViaje Valor entero que ingresa el usuario.
 * @return float resultadoBitcoin Retorna el precio ingresado en bitcoin.
 */
float bitcoin(float precioViaje);




/*------------------------------------------------------- PRECIO POR KIL�METRO -------------------------------------------------------------------------------*/

/**
 * @fn float precioPorKilometro(float, float)
 * @brief Funci�n que sirve para calcular el precio unitario (precio del viaje seg�n los kil�metros).
 *
 * @param float precioViaje Variable que guarda el precio que ingresa el usuario.
 * @param float km Variable que guarda los kil�metros ingresados por el usuario.
 * @return float precioPorKm Retorna el precio por kil�metros.
 */
float precioPorKilometro(float precioViaje, float km);




/*-------------------------------------------------------- DIFERENCIA DE PRECIO -----------------------------------------------------------------------------*/

/**
 * @fn float diferenciaPrecio(float, float)
 * @brief Funci�n que sirve para calcular la diferencia de precio ingresado para ambas aerol�neas.
 *
 * @param float aerolinea Variable que guarda el precio de viaje en Aerol�neas.
 * @param float latam Variable que guarda el precio de viaje en LATAM.
 * @return float diferencia Retorna la diferencia de precio.
 */

float diferenciaPrecio(float aerolinea, float latam);




/*---------------------------------------------------------- MOSTRAR RESULTADOS ----------------------------------------------------------------------------*/

/**
 * @fn void mostrarResultados(float, float, float, float, float, float, float, float, float, float)
 * @brief Funci�n que sirve para mostrar los resultados.
 *
 * @param float km Variable que guard� kil�metros ingresados.
 * @param float debitoLATAM Variable que guard� el descuento para precio ingresado de LATAM.
 * @param float creditoLATAM Variable que guard� el inter�s para precio ingresado de LATAM.
 * @param float bitcoinLATAM Variable que guard� en bitcoin el precio ingresado de LATAM.
 * @param float unitarioLATAM Variable que guard� el precio unitario para vuelos de LATAM.
 * @param float debitoAEROLINEAS Variable que guard� el descuento para precio ingresado de Aerol�neas.
 * @param float creditoAEROLINEAS Variable que guard� el inter�s para precio ingresado de Aerol�neas.
 * @param float bitcoinAEROLINEAS Variable que guard� en bitcoin el precio ingresado de Aerol�neas.
 * @param float unitarioAEROLINEAS Variable que guard� el preico unitario para vuelos de Aerol�neas.
 * @param float diferencia Varibale que guard� la diferencia de precio entre ambas aerol�neas.
 * @return void No retorna nada.
 */
void mostrarResultados(float precioA, float km, float debitoAEROLINEAS, float creditoAEROLINEAS, float bitcoinAEROLINEAS, float unitarioAEROLINEAS, float precioL, float debitoLATAM, float creditoLATAM, float bitcoinLATAM, float unitarioLATAM, float diferencia);




/*------------------------------------------------------------- CARGA FORZADA ----------------------------------------------------------------------------*/

/**
 * @fn void cargaForzada()
 * @brief Funci�n que sirve para mostrar el hardcodeo de datos.
 * @return void No retorna nada.
 */
void cargaForzada();





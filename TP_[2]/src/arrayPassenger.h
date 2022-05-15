/*
 * arrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: Fiorella Aguayo
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

 typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flycode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;
}Passenger;

#endif /* ARRAYPASSENGER_H_ */
/**
 * @fn int menu()
 * @brief mostrar un menu
 *
 * @pre
 * @post
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int menu();

/**
 * @fn int menuModificar()
 * @brief mostrar un submenu de modificaciones
 *
 * @pre
 * @post
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int menuModificar();

/**
 * @fn int subMenu(Passenger*, int)
 * @brief mostrar un submenu de informaciones
 *
 * @pre
 * @post
 * @param list array de pasajeros
 * @param len tamaño del array
 * @return allOk 1 si está bien y 0 si está mal
 */
int subMenu(Passenger* list, int len);

/**
 * @fn int initPassengers(Passenger*, int)
 * @brief inicializar lugares del array en desocupado
 *
 * @pre
 * @post
 * @param list array de pasajeros
 * @param len tamaño del array
 * @return allOk 1 si está bien y 0 si está mal
 */
//inicializa pasajeros, entonces isEmpty = 1, o sea, todas vacías
int initPassengers(Passenger* list, int len);

/**
 * @fn int findFreeSpace(Passenger*, int)
 * @brief  busca espacio libre en el array de pasajeros
 *
 * @pre
 * @post
 * @param list array de pasajeros
 * @param len tamaño del array
 * @return allOk 1 si está bien y 0 si está mal
 */
//me devuelve -1 si no hay lugar, o el índice del lugar desocupado (la primer estructura isEmpty
int findFreeSpace(Passenger* list, int len);

/**
 * @fn int addPassenger(Passenger*, int, int*)
 * @brief dar de alta un pasajero
 *
 * @pre
 * @post
 * @param list array de pasajeros
 * @param len tamaño del array
 * @param id id del pasajero
 * @return allOk 1 si está bien y 0 si está mal
 */
int addPassenger(Passenger* list, int len, int* id);

/**
 * @fn int findPassengerById(Passenger*, int, int*)
 * @brief buscar un pasajero por id
 *
 * @pre
 * @post
 * @param list array de pasajeros
 * @param len tamaño del array
 * @param id id del pasajero
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int findPassengerById(Passenger* list, int len, int* id);

/**
 * @fn int removePassenger(Passenger*, int)
 * @brief dar de baja un pasajero
 *
 * @pre
 * @post
 * @param list array de pasajeros
 * @param len tamaño de array
 * @return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
 */
int removePassenger(Passenger* list, int len);

/**
 * @fn void showPassenger(Passenger)
 * @brief mostrar pasajero por consola
 *
 * @pre
 * @post
 * @param unaPersona int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
 */
void showPassenger(Passenger unaPersona);

/**
 * @fn int showPassengers(Passenger*, int)
 * @brief mostrar pasajeros por consola
 *
 * @pre
 * @post
 * @param list array de pasajeros
 * @param len tamaño del array
 * @return allOk 1 si está bien y 0 si está mal
 */
int showPassengers(Passenger* list, int len);

/**
 * @fn void hardcodePassengers(Passenger[])
 * @brief carga forzada de pasajeros
 *
 * @pre
 * @post
 * @param list array de pasajeros
 */
void hardcodePassengers(Passenger list[]);

/**
 * @fn int modificarPassenger(Passenger*, int)
 * @brief modificar un pasajero
 *
 * @pre
 * @post
 * @param list array de pasajeros
 * @param len tamaño del array
 * @return allOk 1 si está bien y 0 si está mal
 */
int modificarPassenger(Passenger* list, int len);

/**
 * @fn int sortPassengers(Passenger*, int, int)
 * @brief ordenar pasajeros según apellido y tipo de pasajero
 *
 * @pre
 * @post
 * @param list array de pasajeros
 * @param len tamaño del array
 * @param order parametro de ordenamiento de pasajeros
 * @return allOk 1 si está bien y 0 si está mal
 */
int sortPassengers(Passenger* list, int len, int order);

/**
 * @fn int sortPassengersByCode(Passenger*, int, int)
 * @brief ordenar pasajeros según codigo y estado de vuelo
 *
 * @pre
 * @post
 * @param list array de pasajeros
 * @param len tamaño del array
 * @param order parametro de ordenamiento de pasajeros
 * @returnint Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int sortPassengersByCode(Passenger* list, int len, int order);

/**
 * @fn int pricePromedy(Passenger*, int)
 * @brief mostrar promedio total del precio
 *
 * @pre
 * @post
 * @param list array de pasajeros
 * @param len tamaño del array
 * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int pricePromedy(Passenger* list, int len);

/**
 * @fn int listFlyCodeStatus(Passenger*, int)
 * @brief mostrar lista de codigo y estado de vuelo
 *
 * @pre
 * @post
 * @param list array de pasajeros
 * @param len tamaño del array
 * @return allOk 1 si está bien y 0 si está mal
 */
int listFlyCodeStatus(Passenger* list, int len);

/**
 * @fn int reset(Passenger*, int, int*)
 * @brief
 *
 * @pre
 * @post
 * @param list array de pasajeros
 * @param len tamaño del array
 * @param flag bandera que cambiara su valor
 * @return allOk 1 si está bien y 0 si está mal
 */
int reset(Passenger* list, int len, int* flag);








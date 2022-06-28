/*
 * Controller.h
 *
 *  Created on: 20 jun. 2022
 *      Author: Usuario
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */


/**
 * @fn int controller_loadFromText(char*, LinkedList*)
 * @brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * @param path Nombre del archivo a cargar.
 * @param pArrayListPassenger Puntero a la lista de pasajeros.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/**
 * @fn int controller_loadFromBinary(char*, LinkedList*)
 * @brief Carga los datos de los pasajeros desde el archivo data.bin (modo binario).
 *
 * @param path Nombre del archivo a cargar.
 * @param pArrayListPassenger Puntero a la lista de pasajeros.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/**
 * @fn int controller_addPassenger(LinkedList*)
 * @brief Alta de pasajeros
 *
 * @param pArrayListPassenger Puntero a la lista de pasajeros.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,char* path);


/**
 * @fn int controller_editPassenger(LinkedList*)
 * @brief Modificar datos de pasajeros
 *
 * @param pArrayListPassenger Puntero a la lista de pasajeros.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);

/**
 * @fn int controller_removePassenger(LinkedList*)
 * @brief Baja de pasajero
 *
 * @param pArrayListEmployee Puntero a la lista de pasajero.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);

/**
 * @fn int controller_ListPassenger(LinkedList*)
 * @brief Listar pasajeros
 *
 * @param pArrayListEmployee Puntero a la lista de pasajeros.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/**
 * @fn int controller_sortPassenger(LinkedList*)
 * @brief  Ordenar pasajeros.
 *
 * @param pArrayListPassenger Puntero a la lista de pasajeros.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * @brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * @param path Nombre del archivo a guardar.
 * @param pArrayListPassenger Puntero a la lista de pasajeros.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/**
 * @fn int controller_saveAsBinary(char*, LinkedList*)
 * @brief   Guarda los datos de los pasajeros en el archivo data.bin (modo binario).
 *
 * @param path Nombre del archivo a guardar.
 * @param pArrayListPassenger Puntero a la lista de pasajeros.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


/**
 * @fn int controller_mostrarPassenger(Passenger*)
 * @brief funcion para mostrar los datos de un pasajero
 *
 * @param pArrayListPasseng Puntero a la lista de pasajeros.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk
 */
int controller_mostrarPassenger(sPassenger* pArrayListPassenger);



/**
 * @fn int controller_nextId(LinkedList*)
 * @brief Funcion que sirve para calcular el siguiente ID a utilizar teniendo en cuenta el ultimo ID utilizado.
 *
 * @param pArrayListPassenger
 * @return Retorna el siguiente ID a utilizar.
 */
int controller_nextId(LinkedList* pArrayListPassenger);

/**
 * @fn void controller_saveNextId(int)
 * @brief  Guarda el ultimo ID utilizado en un archivo de texto, para utilizarlo la siguiente vez que el programa se inicie.
 *
 * @param id idActual Es el ultimo ID que fue utilizado para guardar.
 */
void controller_saveNextId(int id);

/**
 * @fn int controller_validarId(LinkedList*, int)
 * @brief Funcion que validad que el id ingresado sea uno existente.
 *
 * @param pArrayListPassenger Puntero a la lista de pasajeros.
 * @param idPas id ingresado a comparar si es uno valido o no.
 * @return Retorna 0 si fallo y uno 1 si esta todoOk.
 */
int controller_validarId(LinkedList* pArrayListPassenger, int idPas);

int controller_getMaxId(FILE* pFile);

int controller_validateId(LinkedList* pArrayListPassenger, int idPas);

int searchPassengerId(LinkedList* pArrayListPassenger, int id);

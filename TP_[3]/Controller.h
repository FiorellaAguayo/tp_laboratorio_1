#include "Passenger.h"
#include "LinkedList.h"

/**
 * @fn int controller_loadFromText(char*, LinkedList*)
 * @brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * @param path char*
 * @param pArrayListPassenger LinkedList*
 * @return int
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/**
 * @fn int controller_loadFromBinary(char*, LinkedList*)
 * @brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * @param path char*
 * @param pArrayListPassenger LinkedList*
 * @return int
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);


/**
 * @fn int controller_addPassenger(LinkedList*)
 * @brief Alta pasajero
 *
 * @param path char*
 * @param pArrayListPassenger LinkedList*
 * @return int
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, char* path);


/**
 * @fn int controller_editPassenger(LinkedList*)
 * @brief Modificar datos de pasajero
 *
 * @param path char*
 * @param pArrayListPassenger LinkedList*
 * @return int
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);


/**
 * @fn int controller_validarId(LinkedList*, int)
 * @brief
 *
 * @param pArrayListPassenger
 * @param id
 * @return
 */
int controller_valideId(LinkedList* pArrayListPassenger, int id);


/**
 * @fn int controller_removePassenger(LinkedList*)
 * @brief Baja de pasajero
 *
 * @param path char*
 * @param pArrayListPassenger LinkedList*
 * @return int
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);



/**
 * @fn int controller_ListPassenger(LinkedList*)
 * @brief Listar pasajeros
 *
 * @pre
 * @post
 * @param path char*
 * @param pArrayListPassenger LinkedList*
 * @return int
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);



/**
 * @fn int controller_sortPassenger(LinkedList*)
 *brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);



/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/**
 * @fn int controller_saveAsBinary(char*, LinkedList*)
 * \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

/**
 * @fn int controller_showPassenger(sPassenger*)
 * @brief Muestra los pasajeros
 *
 * @param pArrayListPassenger LinkedList*
 * @return
 */
int controller_showPassenger(sPassenger* pArrayListPassenger);

/**
 * @fn int passenger_getMaxId(FILE*)
 * @brief Obtiene el ID MÁXIMO
 * @param pFile
 * @return int
 */
int passenger_getMaxId(FILE* pFile);

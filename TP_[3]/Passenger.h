/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flycode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;
}sPassenger;

int optionMenu();

sPassenger* Passenger_new();

int Passenger_setId(sPassenger* this, int id);

int Passenger_getId(sPassenger* this, int* id);

int Passenger_setName(sPassenger* this, char* name);

int Passenger_getName(sPassenger* this, char* name);

int Passenger_setLastName(sPassenger* this, char* lastName);

int Passenger_getLastName(sPassenger* this, char* lastName);

int Passenger_setFlyCode(sPassenger* this, char* flyCode);

int Passenger_getFlyCode(sPassenger* this, char* flyCode);

int Passenger_setTypePassenger(sPassenger* this, char* typePassenger);

int Passenger_getTypePassenger(sPassenger* this, char* typePassenger);

int Passenger_setPrice(sPassenger* this, float price);

int Passenger_getPrice(sPassenger* this, float* price);

sPassenger* Passenger_newParametros(char* idStr,char* nameStr, char* lastNameStr, float* priceStr, char* flyCodeStr, char* typePassengerStr, char* statusFlight);

int Passenger_delete(sPassenger* this);

int Passenger_SortId(void* item1, void* item2);

int Passenger_SortName(void* item1, void* item2);

int Passenger_SortLastName(void* item1, void* item2);

int Passenger_SortPrice(void* item1, void* item2);

int Passenger_SortStatusFlight(void* item1, void* item2);

int Passenger_SortFlyCode(void* item1, void* item2);

int Passenger_SortTypePassenger(void* item1, void* item2);

#endif /* PASSENGER_H_ */

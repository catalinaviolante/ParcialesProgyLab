/*
 * publicacion.h
 *
 *  Created on: 10 oct. 2020
 *      Author: Cat
 */

#ifndef PUBLICACION_H_
#define PUBLICACION_H_
#include "cliente.h"
#define TRUE 1
#define FALSE 0
#define PUBLICACION_LONG 64
#define ATTEMPTS 3
#define MIN_NUM 0
#define MAX_NUM 1000
#define RUBRO_MIN 1
#define RUBRO_MAX 4
#define ERROR "\nError! Ingrese una opcion valida.\n"


typedef struct
{
	int idPublicacion;
	char textoAviso[PUBLICACION_LONG];
	int rubro;
	int estado;
	int idCliente;
	int isEmpty;
}Publicacion;

int publicacion_findByID(Publicacion *list, int idPublicacion, int len, int * pIndex);
int publicacion_isEmpty(Publicacion *list, int len);
int publicacion_initList(Publicacion *list, int len);
int publicacion_searchFreeIndex(Publicacion *list, int len, int *pFreeIndex);
int publicacion_print(Publicacion *list, int len);
int publicacion_remove(Publicacion *list, int len, int id);
int publicacion_ordenarPorString(Publicacion *list,int len);
int publicacion_findId_cliente(Publicacion* listPublicacion, int lenPublicacion, Cliente *listCliente, int len, int idPublicacion, int* pIdCliente);
int publicacion_alta(Publicacion *listPublicacion, int lenPublicacion, Cliente *listCliente, int lenCliente);
int publicacion_baja(Publicacion *list, int len, Cliente *listCliente, int lenCliente);
int publicacion_changeStatus(Publicacion* listPublicacion, int lenPublicacion, Cliente* listCliente, int lenCliente, int choosenOption);
int publicacion_modify(Publicacion *list, int len);
int publicacion_printPublicacionesByIdCliente(Publicacion *listPublicacion, int len, int idCliente);
int publicacion_printClientActiveOnes(Publicacion * listPublicacion, int lenPublicacion, Cliente* listClient, int lenClient);
int publicacion_pausedAdsQty(Publicacion *publicacionList, int len, int *pCounter);
void publicacion_automaticCharging(Publicacion *list);

#endif /* PUBLICACION_H_ */

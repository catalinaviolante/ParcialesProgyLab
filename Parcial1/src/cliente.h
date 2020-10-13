/*
 * cliente.h
 *
 *  Created on: 10 oct. 2020
 *      Author: Cat
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define TRUE 1
#define FALSE 0
#define NAME_LONG 51
#define CUIT_LEN 13
#define ATTEMPTS 3
#define MIN_NUM 0
#define MAX_NUM 1000
#define ERROR "\nError! Ingrese una opcion valida.\n"


typedef struct
{
	int id;
	char name[NAME_LONG];
	char lastName[NAME_LONG];
	char cuit[CUIT_LEN];
	int isEmpty;
}Cliente;

void cliente_automaticCharging(Cliente *list);
int cliente_initList(Cliente *list, int len);
int cliente_findByID(Cliente *list, int id, int len, int *pIndex);
int cliente_searchFreeIndex(Cliente *list, int len, int *pFreeIndex);
int cliente_print(Cliente *list, int len);
int cliente_printById(Cliente * listCliente, int lenCliente, int idCliente);
int cliente_remove(Cliente *list, int len, int id);
int cliente_sortByString(Cliente *list,int len);
int cliente_add(Cliente *list, int len);
int cliente_delete(Cliente *list, int len);
int cliente_modify(Cliente *list, int len);
int cliente_isEmpty(Cliente *list, int len);

#endif /* CLIENTE_H_ */


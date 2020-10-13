/*
 * clientes.c
 *
 *  Created on: 10 oct. 2020
 *      Author: Cat
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "utn.h"
#include "cliente.h"

static int generateNewID(void);
//static int UpperFirstChar(char *string);

/**
 * \brief Function to converts an string to lowercase and it first letter to uppercase.
 * \param char *string: receive an string.

static int UpperFirstChar(char *string)
{
	int functionReturn = -1;
	if(string!=NULL)
	{
		char bufferName[NAME_LONG];
		strncpy(bufferName, string, NAME_LONG);
		bufferName[0] = toupper(bufferName[0]);
			for(int i=1;i<NAME_LONG;i++)
			{
				bufferName[i] = tolower(bufferName[i]);
			}
		strncpy(string, bufferName, NAME_LONG);
		functionReturn = 0;
	}
	return functionReturn;
}
*/

/**
 * \brief Function to search in the array for an no empty field
 * \param Cliente *list: Pointer to an Advertisement array
 * \param int len: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int cliente_isEmpty(Cliente *list, int len)
{
	int functionReturn =-1;
	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				functionReturn =0;
				break;
			}
		}
	}
	return functionReturn;
}

/** \brief find an Employee by Id en returns the index position in array.
 * \param list  		: current list of employees
 * \param len 			: list length
 * \param id 			: id of an employee
 * \param pFreeIndex 	: save a free index
 * \return functionReturn : (-1) if Error [Invalid len or the list is out of data or  id is less than 0] - (0) if Ok
 */
int cliente_findByID(Cliente *list, int id, int len, int *pIndex)
{
	int functionReturn = -1;
	if (list != NULL && len > 0 && id > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == FALSE)
			{
				*pIndex = i;
				functionReturn= 0;
			}
		}
	}
	return functionReturn;
}

/**
 * \brief Function to init isEmpty to TRUE and -1 to ID field of a client array
 * \param Cliente *list: Pointer to the Client array
 * \param int len: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int cliente_initList(Cliente *list, int len)
{
	int functionReturn = -1;
	if (list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			list[i].id = -1;
			list[i].isEmpty = TRUE;
		}
		functionReturn = 0;
	}
	return functionReturn;
}

/** \brief: Generate a new id
 */
static int generateNewID(void)
{
	static int id = 0;
	id = id + 1;
	return id;
}

/** \brief: Print the information of the
 * \param list  		: current list
 * \param len 			: list length
 * \param pFreeIndex 	: save a free index
 * \return functionReturn : (-1) if Error [Invalid len or  the list is out of data] - (0) if Ok
 */
int cliente_searchFreeIndex(Cliente *list, int len, int *pFreeIndex) {
	int functionReturn = -1;
	if (list != NULL)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == TRUE && list[i].id == -1)
			{
				*pFreeIndex = i;
				functionReturn = 0;
				break;
			}
		}
	}
	return functionReturn;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid len or NULL pointer or if can't find a employee] - (0) if Ok
 */
int cliente_remove(Cliente *list, int len, int id)
{
	int functionReturn = -1;
	int bufferIndex;
	if (list != NULL && len > 0)
	{
		cliente_findByID(list, len, id, &bufferIndex);
		if(bufferIndex != -1)
		{
			list[bufferIndex].isEmpty = TRUE;
			functionReturn = 0;
		}
	}
	return functionReturn;
}

int cliente_sortByString(Cliente *list,int len)
{
	/*int retorno=-1;
	int order;
	int sorted;
	Cliente bufferCliente;
	if(list!=NULL && len>0 && isEmpty(list, len)==0)
	{
		if(utn_getInt("\nOrdenar: \n1-Descendente\n2-Ascendente", ERROR, &order, ATTEMPTS, 1, 2)==0)
		{
			do
			{
				sorted=TRUE;
				for(int i = 0; i<(len-1);i++)
				{
					if((order == 1 &&
					  (strncmp(list[i].name, list[i + 1].name,NAME_LONG)>0 ||
					  (strncmp(list[i].name, list[i + 1].name,NAME_LONG)==0 &&
					   strncmp(list[i].name, list[i + 1].name,NAME_LONG)>0))) ||
					   (order == 2 &&
					  (strncmp(list[i].name, list[i + 1].name,NAME_LONG)<0 ||
					  (strncmp(list[i].name, list[i + 1].name,NAME_LONG)==0 &&
					   strncmp(list[i].name, list[i + 1].name,NAME_LONG)<0))))
					{
						bufferCliente = list[i];
						list[i] = list[i + 1];
						list[i + 1] = bufferCliente;
						sorted = FALSE;
					}
				}
			}while(sorted==FALSE);
			cliente_print(list, len);
			retorno=0;
		}
	}
return retorno;*/
	return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Function that charge automatically a list of advertisements in order to make easy testing the program.
 */
void cliente_automaticCharging(Cliente *list)
{

	list[0].id = generateNewID();
	strncpy(list[0].name,"Nisman",NAME_LONG);
	strncpy(list[0].lastName,"señor",NAME_LONG);
	strncpy(list[0].cuit,"27424350967",NAME_LONG);
	list[0].isEmpty = FALSE;

	list[1].id = generateNewID();
	strncpy(list[1].name,"carlos",NAME_LONG);
	strncpy(list[1].lastName,"bala",NAME_LONG);
	strncpy(list[1].cuit,"27424350897",NAME_LONG);
	list[1].isEmpty = FALSE;

	list[2].id = generateNewID();
	strncpy(list[2].name,"Trueno",NAME_LONG);
	strncpy(list[2].lastName,"Boka",NAME_LONG);
	strncpy(list[2].cuit,"27424350367",NAME_LONG);
	list[2].isEmpty = FALSE;

	list[3].id = generateNewID();
	strncpy(list[3].name,"luchi",NAME_LONG);
	strncpy(list[3].lastName,"castro",NAME_LONG);
	strncpy(list[3].cuit,"27424353367",NAME_LONG);
	list[3].isEmpty = FALSE;

    list[4].id = generateNewID();
    strncpy(list[4].name,"Stuart",NAME_LONG);
	strncpy(list[4].lastName,"Little",NAME_LONG);
	strncpy(list[4].cuit,"27454350367",NAME_LONG);
    list[4].isEmpty = FALSE;

    list[5].id = generateNewID();
    strncpy(list[5].name,"walter",NAME_LONG);
	strncpy(list[5].lastName,"gomex",NAME_LONG);
	strncpy(list[5].cuit,"27224350367",NAME_LONG);
    list[5].isEmpty = FALSE;

    list[6].id = generateNewID();
	strncpy(list[6].name,"Nacho",NAME_LONG);
	strncpy(list[6].lastName,"otero",NAME_LONG);
	strncpy(list[6].cuit,"27324350367",NAME_LONG);
    list[6].isEmpty = FALSE;

    list[7].id = generateNewID();
    strncpy(list[7].name,"Cacha",NAME_LONG);
	strncpy(list[7].lastName,"torres",NAME_LONG);
	strncpy(list[7].cuit,"27524350367",NAME_LONG);
    list[7].isEmpty = FALSE;

    list[8].id = generateNewID();
    strncpy(list[8].name,"Frank",NAME_LONG);
	strncpy(list[8].lastName,"Ocean",NAME_LONG);
	strncpy(list[8].cuit,"27426350367",NAME_LONG);
    list[8].isEmpty = FALSE;

    list[9].id = generateNewID();
	strncpy(list[9].name,"Wos",NAME_LONG);
	strncpy(list[2].lastName,"Wosito",NAME_LONG);
	strncpy(list[2].cuit,"27429350367",NAME_LONG);
    list[9].isEmpty = FALSE;
}

/**
 * \brief Function to add a client by asking for name, last name and cuit (ID is generated automatically)
 * \param Client *list: Pointer to a Client array
 * \param int len: Client array length
 * \return (-1) if something went wrong, (0)everything is OK.
 */
int cliente_add(Cliente *list, int len) {
	int functionReturn = -1;
	int index;
	Cliente bufferCliente;
	if(list!=NULL && len>0 && cliente_searchFreeIndex(list, len, &index)==0)
	{
		if(utn_getString("\nIngrese nombre",ERROR, bufferCliente.name, ATTEMPTS, NAME_LONG)==0 &&
			(utn_getString("\nIngrese apellido",ERROR, bufferCliente.lastName, ATTEMPTS, NAME_LONG)==0)	&&
			(utn_getCuit("Ingrese cuit", ERROR, bufferCliente.cuit, ATTEMPTS)== 0))
		{
			list[index] = bufferCliente;
			list[index].id= generateNewID();
			list[index].isEmpty=FALSE;
			printf("El id dado de alta es: %d ", list[index].id);
			functionReturn = 0;
		}
	}
	else
	{
		printf("\nNo hay espacio disponible\n");
	}
	return functionReturn;
}


/** \brief: Remove an employee from the list using their ID
 * \param list  		: current list of employees
 * \param len 			: list length
 * \param flagFirstLoad : if it is true we can use the function
 * \return functionReturn : (-1) if Error [Invalid len or  the list is out of data] - (0) if Ok
 */
int cliente_delete(Cliente *list, int len)
{
	int idToFind;
	int functionReturn = -1;
	int flagRemove = 2;
	if (list != NULL && len > 0 && cliente_isEmpty(list, len)==0)
	{
		do {
			if(utn_getInt("\nIngrese num: ",ERROR, &idToFind, ATTEMPTS, MIN_NUM,MAX_NUM)==0)
			{
				if (cliente_remove(list, idToFind, len) == 0)
				{
					functionReturn = 0;
					flagRemove = 2;
				}
				else
				{
					flagRemove = 1;
					utn_getInt("\nNo existe, intente de nuevo? \n1-Si \n2-No : ",ERROR, &flagRemove, ATTEMPTS,1,2);
				}
			}
		} while(flagRemove != 2);
	}
	return functionReturn;
}

/** \brief: Modify an employee from the list using their ID
 * \param Cliente*list :  list of clients
 * \param int len : list length
 * \return functionReturn : (-1) Error (0) Ok
 */
int cliente_modify(Cliente *list, int len)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar;
	Cliente bufferCliente;

	if (list != NULL && len>0 && cliente_isEmpty(list, len)==0)
	{
		if(utn_getInt("\nIngrese id a modificar",ERROR,&idBuscar, ATTEMPTS,MIN_NUM,MAX_NUM)==0 &&
				cliente_findByID(list, idBuscar, len, &indiceAModificar)==0)
		{
				bufferCliente = list[indiceAModificar];
				if(utn_getString("\nIngrese nuevo nombre",ERROR, bufferCliente.name, ATTEMPTS, NAME_LONG)==0 &&
					utn_getString("Ingrese un nuevo apellido", ERROR, bufferCliente.lastName, ATTEMPTS, NAME_LONG)==0 &&
					utn_getCuit("Ingrese cuit:", "Error.", bufferCliente.cuit, ATTEMPTS)==0)
				{
						list[indiceAModificar] = bufferCliente;
						retorno = 0;
				}
				else
				{
					printf("\nNo fue posible modificar al cliente.\n");
				}
		}
		else
		{
			printf("\n ID no encontrado.");
		}
	}

	return retorno;
}

/** \brief: Print client data using his/her ID to obtain it.
 * \param Cliente*list :  list of clients
 * \param int lenCliente : list length
 * \return functionReturn : (-1) Error (0) Ok
 */
int cliente_printById(Cliente * listCliente, int lenCliente, int idCliente)
{
	int functionReturn = -1;
	int i;
	if(listCliente != NULL && lenCliente >0 && idCliente > -1 && cliente_isEmpty(listCliente, lenCliente)==0)
	{
		for(i= 0; i< lenCliente; i++)
		{
			if(listCliente[i].id == idCliente)
			{
				printf(" %-6d %-15s %-15s %-15s \n",listCliente[i].id,listCliente[i].name,listCliente[i].lastName,listCliente[i].cuit );
				functionReturn= 0;
			}
		}

	}

	return functionReturn;
}


/** \brief: Print the information of the employees
 * \param list : current list of employees
 * \param len : list len
 * \return functionReturn : (-1) if Error [Invalid len or  the list is out of data] - (0) if Ok
 */
/**/

int cliente_print(Cliente *clientList, int clientLen)
{
	int functionReturn = -1;
		/*if (list != NULL && len > 0 && cliente_isEmpty(list, len)==0)
		{
			printf("\nREPORTE\n");
			printf("\nName       ID\n"); //Completar con lo que pidan en el reporte.

			for (int i = 0; i < len; i++)
			{
				if (list[i].isEmpty == FALSE)
				{
					printf("%-15s %-6d \n",list[i].name,list[i].id);
				}
			}
			functionReturn = 0;
	    }*/
	return functionReturn;
}


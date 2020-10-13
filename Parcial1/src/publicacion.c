/*
 * publicacion.c
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
#include "publicacion.h"

static int publicacion_generateNewID(void);
static int publicacion_bajarTodasLasPublicacionesDeunID(Publicacion *list, int len, int id);
static int publicacion_calculateActiveOnes(Publicacion * listPublicacion, int lenPublicacion, int idCliente, int *pCountPublicaciones);

/*
 * \brief Function to search in the array for an no empty field
 * \param Publicacion *list: Pointer to an Publicacion array
 * \param int len: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int publicacion_isEmpty(Publicacion *list, int len)
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

/** \brief find an Employee by Id and sends the index by pointer.
 * \param list: current list of employees
 * \param len: list length
 * \param id: id of an advertisement
 * \param peIndex: pointer to the index of the found advertisement
 * \return functionReturn : (-1)Error  (0)  Ok
 */
int publicacion_findByID(Publicacion *list, int idPublicacion, int len, int * pIndex)
{
	int functionReturn = -1;
	if (list != NULL && len > 0 && idPublicacion > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].idPublicacion == idPublicacion && list[i].isEmpty == FALSE)
			{
				*pIndex = i;
				functionReturn = 0;
			}
		}
	}
	return functionReturn;
}

/**
 * \brief Function to init isEmpty to TRUE and -1 to ID field of a client array
 * \param Client *list: Pointer to a Client array
 * \param int len: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int publicacion_initList(Publicacion *list, int len)
{
	int functionReturn = -1;
	if (list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			list[i].idPublicacion = -1;
			list[i].isEmpty = TRUE;
		}
		functionReturn = 0;
	}
	return functionReturn;
}

/** \brief: Generate a new id
 */
static int publicacion_generateNewID(void)
{
	static int id = 0;
	id = id + 1;
	return id;
}

/**
 * \brief Function that return as pointer the first free position in the array
 * \param Publicacion *list: Pointer to a Publicacion array
 * \param int len: Length of the array
 * \param int *pIndex: pointer of the index
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int publicacion_searchFreeIndex(Publicacion *list, int len, int *pFreeIndex) {
	int functionReturn = -1;
	if (list != NULL)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == TRUE && list[i].idPublicacion == -1)
			{
				*pFreeIndex = i;
				functionReturn = 0;
				break;
			}
		}
	}
	return functionReturn;
}

/** \brief: Print the advertisements
 * \param list : current list of advertisements
 * \param len : list length
 * \return functionReturn : (-1) if Error [Invalid len or  the list is out of data] - (0) if Ok
 */
int publicacion_print(Publicacion *list, int len) {
	int functionReturn = -1;
		if (list != NULL && len > 0 && publicacion_isEmpty(list, len)==0)
		{
			printf("\nREPORTE\n");
			printf("\nName       ID\n");
			for (int i = 0; i < len; i++)
			{
				if (list[i].isEmpty == FALSE)
				{
					printf("%-15s %-6d \n",list[i].textoAviso,list[i].idPublicacion);
				}
			}
			functionReturn = 0;
	    }
	return functionReturn;
}

/** \brief Remove a advertisement by Id (put isEmpty Flag in TRUE)
 * \param Publicacion *List *
 * \param int len: lenght of the list
 * \param int id: id of the advertisement.
 * \return int Returns (-1) if Error (0) if Ok
 */
int publicacion_remove(Publicacion *list, int len, int idPublicacion)
{
	int functionReturn = -1;
	int bufferIndex;
	if (list != NULL && len > 0)
	{
		publicacion_findByID(list, len, idPublicacion, &bufferIndex);
		if(bufferIndex != -1)
		{
			list[bufferIndex].isEmpty = TRUE;
			functionReturn = 0;
		}
	}
	return functionReturn;
}

int publicacion_ordenarPorString(Publicacion *list,int len)
{
	/*int retorno=-1;
	int order;
	int sorted;
	Publicacion bufferPublicacion;
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
					  (strncmp(list[i].textoAviso, list[i + 1].textoAviso,PUBLICACION_LONG)>0 ||
					  (strncmp(list[i].textoAviso, list[i + 1].textoAviso,PUBLICACION_LONG)==0 &&
					   strncmp(list[i].textoAviso, list[i + 1].textoAviso,PUBLICACION_LONG)>0))) ||
					   (order == 2 &&
					  (strncmp(list[i].textoAviso, list[i + 1].textoAviso,PUBLICACION_LONG)<0 ||
					  (strncmp(list[i].textoAviso, list[i + 1].textoAviso,PUBLICACION_LONG)==0 &&
					   strncmp(list[i].textoAviso, list[i + 1].textoAviso,PUBLICACION_LONG)<0))))
					{
						bufferPublicacion = list[i];
						list[i] = list[i + 1];
						list[i + 1] = bufferPublicacion;
						sorted = FALSE;
					}
				}
			}while(sorted==FALSE);
			publicacion_print(list, len);
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
void publicacion_automaticCharging(Publicacion *list)
{

	list[0].idPublicacion = publicacion_generateNewID();
	strncpy(list[0].textoAviso,"Aviso 0",PUBLICACION_LONG);
	list[0].rubro = 1;
	list[0].estado = 1;
	list[0].idCliente = 1;
	list[0].isEmpty = FALSE;

	list[1].idPublicacion = publicacion_generateNewID();
	strncpy(list[1].textoAviso,"Aviso 1",PUBLICACION_LONG);
	list[1].rubro = 1;
	list[1].estado = 1;
	list[1].idCliente = 2;
	list[1].isEmpty = FALSE;

	list[2].idPublicacion = publicacion_generateNewID();
	strncpy(list[2].textoAviso,"Aviso 2",PUBLICACION_LONG);
	list[2].rubro = 3;
	list[2].estado = 1;
	list[2].idCliente = 3;
	list[2].isEmpty = FALSE;

	list[3].idPublicacion = publicacion_generateNewID();
	strncpy(list[3].textoAviso,"Aviso 3",PUBLICACION_LONG);
	list[3].rubro = 4;
	list[3].estado = 1;
	list[3].idCliente = 4;
	list[3].isEmpty = FALSE;

    list[4].idPublicacion = publicacion_generateNewID();
    strncpy(list[4].textoAviso,"Aviso 4",PUBLICACION_LONG);
	list[4].rubro = 4;
	list[4].estado = 1;
	list[4].idCliente = 4;
    list[4].isEmpty = FALSE;

    list[5].idPublicacion = publicacion_generateNewID();
    strncpy(list[5].textoAviso,"Aviso 5",PUBLICACION_LONG);
	list[5].rubro = 2;
	list[5].estado = 1;
	list[5].idCliente = 6;
    list[5].isEmpty = FALSE;

    list[6].idPublicacion = publicacion_generateNewID();
    strncpy(list[6].textoAviso,"Aviso 6",PUBLICACION_LONG);
	list[6].rubro = 2;
	list[6].estado = 1;
	list[6].idCliente = 6;
    list[6].isEmpty = FALSE;

    list[7].idPublicacion = publicacion_generateNewID();
    strncpy(list[7].textoAviso,"Aviso 7",PUBLICACION_LONG);
	list[7].rubro = 1;
	list[7].estado = 1;
	list[7].idCliente = 7;
    list[7].isEmpty = FALSE;

    list[8].idPublicacion = publicacion_generateNewID();
    strncpy(list[8].textoAviso,"Aviso 8",PUBLICACION_LONG);
	list[8].rubro = 4;
	list[8].estado = 1;
	list[8].idCliente = 8;
    list[8].isEmpty = FALSE;

    list[9].idPublicacion = publicacion_generateNewID();
    strncpy(list[9].textoAviso,"Aviso 9",PUBLICACION_LONG);
	list[9].rubro = 2;
	list[9].estado = 1;
	list[9].idCliente = 9;
    list[9].isEmpty = FALSE;
}


int publicacion_alta(Publicacion *listPublicacion, int lenPublicacion, Cliente *listCliente, int lenCliente)
{
	int functionReturn = -1;
	int index;
	Publicacion bufferPublicacion;

	if(listPublicacion != NULL && lenPublicacion > 0 && publicacion_searchFreeIndex(listPublicacion, lenPublicacion, &index)== 0 &&
	cliente_isEmpty(listCliente, lenCliente)== 0)
	{
		if(utn_getInt("\nIngrese el ID del cliente: \n", "Ingrese un ID valido", &bufferPublicacion.idCliente, 3, MIN_NUM, MAX_NUM)==0 &&
			cliente_findByID(listCliente, bufferPublicacion.idCliente, lenCliente, &index)== 0 &&
			utn_getInt("\nIngrese rubro: 1.Moda, 2.Inmobiliario, 3.Automovilistico, 4.Construccion", "Error:ingrese un rubro valido", &bufferPublicacion.rubro, 3, RUBRO_MIN, RUBRO_MAX)== 0 &&
			utn_getLetrasYEspacios(bufferPublicacion.textoAviso, lenPublicacion, "\nIngrese texto del aviso:\n", "Error,texto invalido.", 3)== 0)
		{
			listPublicacion[index] = bufferPublicacion;
			listPublicacion[index].estado = 1;
			listPublicacion[index].idPublicacion= publicacion_generateNewID();
			listPublicacion[index].isEmpty=FALSE;
			printf("\nEl ID de su publicacion es: %d\n",listPublicacion[index].idPublicacion);
			functionReturn=0;
		}
		else
		{
			printf("No fue posible realizar el alta de la publicacion");
		}
	}
	return functionReturn;
}

//print publicaciones by id cliente
int publicacion_printPublicacionesByIdCliente(Publicacion *listPublicacion, int len, int idCliente)
{
	int functionReturn = -1;
	char estadoPublicacion[8];
	if(listPublicacion != NULL && len > 0 && publicacion_isEmpty(listPublicacion, len)==0 && idCliente > -1 )
	{
		printf("\nPublicaciones del cliente N°: %d \n",idCliente);
		printf("\n Texto Aviso	 | ID_Aviso  | Rubro | Estado | ID Cliente  \n");
		printf("_____________________________________________________________\n");
		for (int i = 0; i < len; i++)
		{
			if(listPublicacion[i].isEmpty == FALSE && listPublicacion[i].idCliente == idCliente)
			{
				if (listPublicacion[i].estado == 1 )
				{
					strncpy(estadoPublicacion,"ACTIVA",8);
				}
				else
				{
					strncpy(estadoPublicacion,"PAUSADA",8);
				}
				printf("%-15s | %-6d | %-8d | %-15s | %-15d \n",listPublicacion[i].textoAviso,listPublicacion[i].idPublicacion,listPublicacion[i].rubro,estadoPublicacion, listPublicacion[i].idCliente);
				functionReturn = 0;
			}
			else
			{
				functionReturn = 2;
			}
		}

	}
	return functionReturn;
}
static int publicacion_bajarTodasLasPublicacionesDeunID(Publicacion *list, int len, int id)
{
int retorno = -1;
	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].idCliente==id)
			{
				list[i].isEmpty=TRUE;
			}
			retorno=0;
		}
	}
return retorno;
}

/** \brief: Remove an employee from the list using their ID
 * \param list  		: current list of employees
 * \param len 			: list length
 * \param flagFirstLoad : if it is true we can use the function
 * \return functionReturn : (-1) if Error [Invalid len or  the list is out of data] - (0) if Ok
 */
int publicacion_baja(Publicacion *list, int len, Cliente *listCliente, int lenCliente)
{
	int idToFind;
	int indexToDelete;
	int functionReturn = -1;
	int flagRemove = 2;
	if (list != NULL && len > 0 && publicacion_isEmpty(list, len)==0 &&
			cliente_isEmpty(listCliente, lenCliente)==0)
	{
		if(utn_getInt("\nIngrese el ID del cliente: ",ERROR, &idToFind, ATTEMPTS, MIN_NUM,MAX_NUM)==0 &&
				cliente_findByID(listCliente, idToFind, len,&indexToDelete )== 0 &&
				publicacion_printPublicacionesByIdCliente(list, len, idToFind)!= -1)
		{
			utn_getInt("\nDesea continuar con la baja? 1.SI 2.NO \n", ERROR, &flagRemove, ATTEMPTS, 1, 2);
			if (flagRemove == 1 && publicacion_bajarTodasLasPublicacionesDeunID(list, len, idToFind)==0)
			{
				functionReturn = 0;
				listCliente[indexToDelete].isEmpty = TRUE;
			}
			else
			{
				printf("Regresando al menu...");
			}
		}
	}
	else
	{
		printf("Algo salio mal!");
	}
	return functionReturn;
}

int publicacion_changeStatus(Publicacion* listPublicacion, int lenPublicacion, Cliente* listCliente, int lenCliente, int choosenOption)
{
	int functionReturn = -1;
	int idPublicacion; //inicializar en 0??
	int indexPublicacion;
	int idCliente;
	int flagModificacion;
	if(listPublicacion !=NULL && lenPublicacion > 0 && listCliente !=NULL && lenCliente >0 && cliente_isEmpty(listCliente, lenCliente)==0)
	{
		switch(choosenOption)
		{
			case 5:
				printf("probando");
				if(utn_getInt("\nIngrese el ID de la publicacion a pausar\n", "Error, ingrese un ID valido", &idPublicacion, 3, 0, MAX_NUM)==0 &&
					publicacion_findByID(listPublicacion, idPublicacion, lenPublicacion,&indexPublicacion )== 0 &&
					publicacion_findId_cliente(listPublicacion, lenPublicacion, listCliente, lenCliente, idPublicacion, &idCliente)==0 &&
					cliente_printById(listCliente, lenCliente, idCliente)== 0 &&
					utn_getInt("\nDesea pausar esta publicacion? 1.Si 2.No.\n", "Error, seleccione una opcion validad" , &flagModificacion, 3, 1, 2)==0)
				{
					if(flagModificacion == 1)
					{
						listPublicacion[indexPublicacion].estado = 0;
						printf("Publicacion pausada.");
						functionReturn = 0;

					}
					else
					{
						printf("Volviendo al menu.");
					}
				}
			break;
			case 6:
				if(utn_getInt("\nIngrese el ID de la publicacion a reanudar.\n", "Error, ingrese un ID valido", &idPublicacion, 3, 0, MAX_NUM)==0 &&
					publicacion_findByID(listPublicacion, idPublicacion, lenPublicacion,&indexPublicacion )== 0 &&
					publicacion_findId_cliente(listPublicacion, lenPublicacion, listCliente, lenCliente, idPublicacion, &idCliente)==0 &&
					cliente_printById(listCliente, lenCliente, idCliente)== 0 &&
					utn_getInt("\nDesea reanudar esta publicacion? 1.Si 2.No.\n", "Error, seleccione una opcion valida." , &flagModificacion, 3, 1, 2)==0)
					{
						if(flagModificacion == 1)
						{
							listPublicacion[indexPublicacion].estado = 1;
							printf("Publicacion reanudada.");
							functionReturn = 0;

						}
						else
						{
							printf("Volviendo al menu.");
						}
					}
				break;

		}

	}
	return functionReturn;
}
//recibe un idPublicacion y devuelve el id del cliente
int publicacion_findId_cliente(Publicacion* listPublicacion, int lenPublicacion, Cliente *listCliente, int len, int idPublicacion, int* pIdCliente)
{
	//validar punteros
	int functionReturn = -1;
	int i;
	for(i=0;i<lenPublicacion; i++)
	{
		if(listPublicacion[i].idPublicacion == idPublicacion)
		{
			*pIdCliente = listPublicacion[i].idCliente;
			functionReturn = 0;
		}
	}
	return functionReturn;
}
/** \brief: Modify an advertisement from the list using their ID
 * \param list  		: current list of advertisements
 * \param len 			: list length
 * \return functionReturn : (-1) if Error [Invalid len or  the list is out of data] - (0) if Ok

int publicacion_modify(Publicacion *list, int len)
{
	int retorno = -1;
	int idBuscar;
	int indiceAModificar;
	Publicacion bufferPublicacion;

	if (list != NULL && len>0 && publicacion_isEmpty(list, len)==0)
	{
		if(utn_getInt("\nIngrese id a modificar",ERROR,&idBuscar, ATTEMPTS,MIN_NUM,MAX_NUM)==0)
		{
			publicacion_findByID(list, idBuscar, len, &indiceAModificar);
			if(indiceAModificar!=-1)
			{
				bufferPublicacion = list[indiceAModificar];
				if(utn_getString("\nIngrese nuevo dato",ERROR, bufferPublicacion.textoAviso, ATTEMPTS, PUBLICACION_LONG)==0)
				{
						list[indiceAModificar] = bufferPublicacion;
						retorno = 0;
				}
			}
			else{printf("\n No existe ese id..");}
		}
	}
	return retorno;
}
*/
/*CALCULAR PUBLIS ACTIVOS
 * param listPublicacion, idCliente, *pCantidadPublicaciones
 * ES STATIC*/
static int publicacion_calculateActiveOnes(Publicacion * listPublicacion, int lenPublicacion, int idCliente, int *pCountPublicaciones)
{
	int functionReturn= -1;
	int countActiveOnes = 0;
	if(listPublicacion != NULL && lenPublicacion > 0 && idCliente> -1 && pCountPublicaciones != NULL)
	{
		for(int i = 0; i< lenPublicacion; i++)
		{
			if(listPublicacion[i].isEmpty == FALSE && listPublicacion[i].estado == 1 && listPublicacion[i].idCliente == idCliente)
			{
				countActiveOnes++;

			}
		}
		*pCountPublicaciones = countActiveOnes;
		functionReturn = 0;
	}
	return functionReturn;
}
/**
 * \brief Function to count how many paused ads have an Advertisement array
 * \param Advertisement *list: Pointer to an Advertisement array
 * \param int len: Length of the array
 * \param int *pCounter: Pointer of the counter
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int publicacion_pausedAdsQty(Publicacion *publicacionList, int len, int *pCounter)
{
	int functionReturn=-1;
	int counter=0;
	if(publicacionList!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(publicacionList[i].estado == 0)
			{
				counter++;
				functionReturn=0;
			}
		}
		*pCounter = counter;
	}
	return functionReturn;
}

int publicacion_printClientActiveOnes(Publicacion * listPublicacion, int lenPublicacion, Cliente* listClient, int lenClient)
{
	int functionReturn= -1;
	int countActiveOnes = 0;
		if(listPublicacion != NULL && lenPublicacion > 0 && listClient != NULL && lenClient > 0)
		{	printf("ID Cliente | Nombre | Apellido | Cuit	| Publicaciones activas");
			for(int i = 0; i< lenClient; i++)
			{
				if(listClient[i].isEmpty == FALSE)
				{
					publicacion_calculateActiveOnes(listPublicacion, lenPublicacion, listClient[i].id, &countActiveOnes);
					printf("\n %-5d | %-5s | %-5s | %-5s | %-5d \n",listClient[i].id, listClient[i].name, listClient[i].lastName, listClient[i].cuit, countActiveOnes);
				}
			}

			functionReturn = 0;
		}
		return functionReturn;
}



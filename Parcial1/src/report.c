/*
 * report.c
 *
 *  Created on: 12 oct. 2020
 *      Author: Cat
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "report.h"
#include "publicacion.h"
#include "cliente.h"

/**
 * \brief Function to get the report menu. Reports: client with more ads, how many paused advertisements are and the sector number with more ads
 * \param Cliente *clientList: Pointer to an Client array
 * \param int clientLen: Client array length
 * \param Publicacion *adList: Pointer to an Advertisement array
 * \param int publicacionLen: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int report_menu(Cliente *clientList, int clientLen, Publicacion *publicacionList, int publicacionLen)
{
	int retornar = -1;
	int option;
	int adsCounter;
	if(clientList!=NULL && clientLen>0 && publicacionList!=NULL && publicacionLen>0 && cliente_isEmpty(clientList, clientLen)== 0 &&
			publicacion_isEmpty(publicacionList, publicacionLen)==0)
	{
		do
		{
			if(utn_getInt("\nElija una opcion: \n1)Cliente con mas avisos\n2)Cantidad de avisos pausados\n3)Rubro con mas avisos\n4)Salir ", "\nERROR! Elija una opcion valida", &option, 2, 1, 4)==0)
			{
				switch(option)
				{
				case 1:
					if(report_clientWithMaxAdQty(clientList, clientLen, publicacionList, publicacionLen)==0)
					{
						retornar=0;
					}
				break;
				case 2:
					if(publicacion_pausedAdsQty(publicacionList, publicacionLen, &adsCounter)==0)
					{
						printf("\nCantidad de avisos pausados: %d\n", adsCounter);
						retornar=0;
					}
					else
					{
						printf("\nNo hay avisos pausados\n");
					}
				break;
				case 3:
					if(report_sectorMaxQtyAds(publicacionList, publicacionLen)==0)
					{
						retornar=0;
					}
					else
					{
						printf("\nNo hay rubros cargados\n");
					}
				break;
				}
			}
		}while(option != 4);
	}
	return retornar;
}


/**
 * \brief Function to count how many ads has a client
 * \param Advertisement *list: Pointer to an Advertisement array
 * \param int len: Length of the array
 * \param int id: receive the ID to be search
 * \param int *pCounter: Pointer of the counter
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int report_adCounterEachClient(Publicacion *publicacionList, int adLen, int id, int *pCounter)
{
	int retornar=-1;
	int counter=0;
	if(publicacionList!=NULL && adLen>0)
	{
		for(int i=0;i<adLen;i++)
		{
			if(publicacionList[i].idCliente == id)
			{
				counter++;
			}
		}
		*pCounter = counter;
		retornar = 0;
	}
	return retornar;
}

/**
 * \brief Function to find the client with more quantity of advertisements
 * \param Cliente *clientList: Pointer to an Client array
 * \param int clientLen: Client array length
 * \param Publicacion *publicacionList: Pointer to an Publicacion array
 * \param int publicacionLen: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int report_clientWithMaxAdQty(Cliente *clientList, int clientLen, Publicacion *publicacionList, int publicacionLen)
{
	int retornar=-1;
	int currentCounter;
	int maxCounter;
	int index;
	Cliente bufferMax;
	if(clientList!=NULL && clientLen>0 && publicacionList!=NULL && publicacionLen>0)
	{
		for(int i=0;i<clientLen;i++)
		{
			report_adCounterEachClient(publicacionList, publicacionLen, clientList[i].id, &currentCounter);
			if(i==0 || currentCounter>maxCounter)
			{
				maxCounter = currentCounter;
				bufferMax = clientList[i];
			}
		}
		if(cliente_findByID(clientList, clientLen, bufferMax.id, &index)==0)
		{
			printf("\nEl cliente con mas avisos es: %s %s, CUIT: %s", clientList[index].name, clientList[index].lastName, clientList[index].cuit);
			retornar = 0;
		}
	}
	return retornar;
}

/**
 * \brief Function to compare sectors counter and find the max
 * \param Advertisement *list: Pointer to an Advertisement array
 * \param int len: Length of the array
 * \return the index or (-1) if something went wrong
 */
int report_sectorMaxQtyAds(Publicacion *list, int len)
{
	int retornar=-1;
	int currentCounter=0;
	int maxCounter;
	Publicacion aux;
if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && report_equalSectorQty(list,len,list[i].rubro, &currentCounter)==0)
			{
				if(i==0 || currentCounter>maxCounter)
				{
					maxCounter = currentCounter;
					aux = list[i];
					retornar=0;
				}
			}
		}
		printf("\nEl rubro con mas avisos es el: %d\n", aux.rubro);
	}
	return retornar;
}

/**
 * \brief Function to count how many times a sector is repeated in the Advertisement array
 * \param Advertisement *list: Pointer to an Advertisement array
 * \param int len: Length of the array
 * \param int sector: receive the sector to be searched
 * \param int *pCounter: pointer of the counter
 * \return the index or (-1) if something went wrong
 */
int report_equalSectorQty(Publicacion *list, int len, int sector, int *pCounter)
{
	int retornar=-1;
	int counter=0;
	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE && list[i].rubro == sector)
			{
				counter++;
				retornar=0;
			}
		}
		*pCounter = counter;
	}
	return retornar;
}


/*
 * report.h
 *
 *  Created on: 12 oct. 2020
 *      Author: 54222
 */

#ifndef REPORT_H_
#define REPORT_H_
#include "cliente.h"
#include "publicacion.h"

int report_menu(Cliente *clientList, int clientLen, Publicacion *publicacionList, int publicacionLen);
int report_adCounterEachClient(Publicacion *adList, int adLen, int id, int *pCounter);
int report_clientWithMaxAdQty(Cliente *clientList, int clientLen, Publicacion *publicacionList, int publicacionLen);
int report_sectorMaxQtyAds(Publicacion *list, int len);
int report_equalSectorQty(Publicacion *list, int len, int sector, int *pCounter);
#endif /* REPORT_H_ */

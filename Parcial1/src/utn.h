/*
 * utn.h
 *
 *  Created on: 10 oct. 2020
 *      Author: Cat
 */

#ifndef UTN_H_
#define UTN_H_
#define ARRAY_SIZE 12 //revisar jiji
int utn_getLetrasYEspacios(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos);
int utn_getString(char mensaje[], char mensajeError[], char pResultado[], int attemps, int limit);
int utn_getInt(char msg[], char msgError[], int *pResult, int attemps, int min, int max);
int utn_getMenu(int *pResult, int attemps, int min, int max);
int utn_getFloat(char msg[], char msgError[], float *pResult, int attemps, int min, int max);
int isAlphaNum(char* pResultado);
int utn_getCuit(char msg[], char msgError[], char pResult[], int attemps);


#endif /* UTN_H_ */

/*
 * utn.c
 *
 *  Created on: 10 oct. 2020
 *      Author: Cat
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define LONG_NOMBRE 50

static int myGets(char cadena[], int longitud);
static int isString(char cadena[]);
static int isInt(char cadena[]);
static int isFloat(char string[]);
static int isStringCuit(char string[]);

/*
*brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo de longitud caracteres.
*param char* cadena Cadena a ser analizada
*param int longitud tamaño maximo de la cadena
*return (0)OK (-1) valor invalido
*/
static int myGets(char cadena[], int longitud)
{
	int retorno=-1;
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n' && cadena[0] != '\n')
		{
		cadena[strlen(cadena)-1] = '\0';
		}
		retorno=0;
	}
	return retorno;
}

static int isString(char string[])
{
	int retorno = 1;
	if(string != NULL && strlen(string) > 0)
	{
		for(int i = 0;string[i] != '\0'; i++)
		{
			if((string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && string[i] != 32)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*
 * isFloat: Verifica si la cadena ingresada es flotante
 * cadena: cadena de caracteres a ser analizada
 * Return: 1 (verdadero) si la cadena es flotante , 0 (falso) si no y -1 en caso de ERROR de parametro
 *
 */
static int isFloat(char string[])
{
	int retorno = 1;
	int i = 0;

	if(string != NULL && strlen(string) > 0)
	{
		if(string[0] == '-')
		{
			i = 1;
		}

		for( ; string[i] != '\0' ; i++)
		{
			if((string[i] > '9' || string[i] < '0') && string[i] != '.')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief convierte la cadena recibida en un número entero.
 * \param puntero con el string validado.
 * \return 0: ok. return -1: fallo.
 */
static int isInt(char string[])
{
	int retorno = 1;
	int i = 0;

	if(string != NULL && strlen(string) > 0)
	{
		if(string[0] == '-')
		{
			i = 1;
		}

		for( ; string[i] != '\0' ; i++)
		{
			if(string[i] > '9' || string[i] < '0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int esLetrasYEspacios(char* cadena, int len);
static int getLetrasYEspacios(char *pResultado, int len);


/*
 * \brief getLetrasYEspacios obtiene una cadena de letras y espacios
 y la copia en *pResultado
 * \param puntero con el string validado.
 * \param longitud del string.
 * \return 0 si ha salido ok. -1 si no.
 */
static int getLetrasYEspacios(char *pResultado, int len)
{
	int retorno=-1;
	char buffer[50];
	if(pResultado != NULL &&
		myGets(buffer, sizeof(buffer))==0 &&
		esLetrasYEspacios(buffer, sizeof(buffer))==1)
	{
		retorno=0;
		strncpy(pResultado, buffer, len);
	}
	return retorno;
}

/*
 * \brief Valida que la cadena recibida está compuesta únicamente por letras o espacios.
 * \param puntero con el string validado.
 * \param longitud del string.
 * \return 1 (verdadero) si solo tiene letras y espacios. 0 (falso) si no.
 */
static int esLetrasYEspacios(char* cadena, int len)
{
	int retorno = 1;
	int i;

	for(i=0 ;  i<len && cadena[i] != '\0'; i++)
	{
		if((cadena[i] < 'A' || cadena[i] > 'Z') &&
			(cadena[i] < 'a' || cadena[i] > 'z') &&
			(cadena[i] != ' ') &&
			(cadena[i] < 'á' || cadena[i] > 'ú') &&
			(cadena[i] != 'é'))
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/*
 * \brief solicita una cadena de valores.
 * \param puntero con la cadena.
 * \param mensaje para solicitar la cadena..
 * \param mensaje de error si no cumple las condiciones preestablecidas.
 * \param cantidad de reintentos para introducir un valor válido.
 * \return 0 si ha salido ok. -1 si no.
 */
int utn_getLetrasYEspacios(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = -1;
	char buffer[4096];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos > 0)
	{
		do{
			printf("%s",mensaje);
			if(getLetrasYEspacios(buffer, len)==0  && strlen(buffer) < len)
			{
				strncpy(pResultado,buffer,len-1);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/*
 * \brief valida que la cadena recibida sea un string valido.
 * \param char*mesaje: Mensaje impreso para obtener una cadena
 * \param char*mensajeError: mensaje impreso para notificar que la cadena no cumple con las condiciones.
 * \param puntero con la cadena validada.
 * \param int reintentos: cantidad de veces que el usuario puede volver a intentar ingresar un valor valido.
 * \param int limite: longitud de la cadena.
 * \return -1: failed  Return 0:Ok.
 */
int utn_getString(char msg[], char msgError[], char pResult[], int attemps, int limit)
{
	int retorno = -1;
	char bufferString[ARRAY_SIZE];

	if(msg != NULL && msgError != NULL && pResult != NULL && attemps >= 0)
	{
		do
		{
			printf("\n%s", msg);
			if(myGets(bufferString, ARRAY_SIZE) == 0 && isString(bufferString) == 1 && strnlen(bufferString, sizeof(bufferString)) < limit)
			{
				retorno = 0;
				strncpy(pResult, bufferString, limit);
				break;
			}
			else
			{
				printf("%s", msgError);
				attemps--;
			}
		}while(attemps >= 0);
	}
	return retorno;
}
/*
 * \brief Solicita el ingreso de un numero entero.
 * \param char*mensaje: pide  un número entero.
 * \param char * mensajeError: mensaje de error en caso de que las condiciones no se cumplan.
 * \param int* pResultado: puntero con el numero adquirido
 * \param int reintentos: veces en las que el usuario podra volver a ingresar un valor valido.
 * \param int maximo: valor maximo a introducir
 * \param int minimo: valor minimo a introducir.
 * \return 0 si ha salido ok. -1 si no.
 */
int utn_getInt(char msg[], char msgError[], int *pResult, int attemps, int min, int max)
{
	int retorno = -1;
	char bufferString[ARRAY_SIZE];
	int bufferInt;

	if(msg != NULL && msgError != NULL && pResult != NULL && attemps >= 0 && min <= max)
	{
		do
		{
			printf("%s", msg);
			if(myGets(bufferString, ARRAY_SIZE) == 0 && isInt(bufferString) == 1)
			{
				bufferInt = atoi(bufferString);
				if(bufferInt >= min && bufferInt<= max)
				{
					*pResult = bufferInt;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s", msgError);
					attemps--;
				}

			}
			else
			{
				printf("%s", msgError);
				attemps--;
			}

		}while(attemps >= 0);
	}
	return retorno;
}
/*
 * brief : Solicita un numero flotante al usuario.
 * pResultado : puntero con el valor validado.
 * mensaje : El mensaje que imprime para pedir un valor.
 * mensajeError: mensaje a imprimir si el rango no es valido.
 * minimo : valor minimo valido
 * maximo : valor maximo valido
 * Reintentos: cantidad de veces que tiene el usuario para ingresar un valor valido
 * Return 0= OK.Return -1: error.
 *
 */
int utn_getFloat(char msg[], char msgError[], float *pResult, int attemps, int min, int max)
{
	int retorno = -1;
	char bufferString[ARRAY_SIZE];
	float bufferFloat;

	if(msg != NULL && msgError != NULL && pResult != NULL && attemps >= 0 && min <= max)
	{
		do
		{
			printf("%s", msg);
			if(myGets(bufferString, ARRAY_SIZE) == 0 && isFloat(bufferString) == 1)
			{
				bufferFloat = atof(bufferString);
				if(bufferFloat >= min && bufferFloat<= max)
				{
					*pResult = bufferFloat;
					retorno = 0;
					break;
				}
				else
				{
					printf("%s", msgError);
					attemps--;
				}

			}
			else
			{
				printf("%s", msgError);
				attemps--;
			}

		}while(attemps >= 0);
	}
	return retorno;
}

/*
 * brief: Obtiene menu y verifica que la opcion ingresada sea correcta.
 *
 * cadena: cadena de caracteres a ser analizada
 * limite: limite de la cadena
 * Return: 1 (verdadero) si la cadena es flotante , 0 (falso) si no y -1 en caso de ERROR de parametro
 *
 */
int utn_getMenu(int *pResult, int attemps, int min, int max)
{
	int retorno = -1;
	char bufferString[ARRAY_SIZE];
	int bufferInt;
	if(pResult != NULL && attemps >= 0 && min <= max)
	{
		do
		{	printf("\nMENU DE OPCIONES:");
			printf("\n 1. ALTA, 2.MODIFICAR, 3.BAJA, 4.PUBLICAR, 5.PAUSAR, 6.REANUDAR, 7.IMPRIMIR, 8.REPORTE, 9.CARGA AUTOMATICA DE DATOS\n");
			if(myGets(bufferString, ARRAY_SIZE) == 0 && isInt(bufferString) == 1)
			{
				bufferInt = atoi(bufferString);
				if(bufferInt >= min && bufferInt<= max)
				{
					*pResult = bufferInt;
					retorno = 0;
					break;
				}
				else
				{
					printf("\nError! elija una opcion valida");
					attemps--;
				}

			}
			else
			{
				printf("Error! elija una opcion valida");
				attemps--;
			}

		}while(attemps >= 0);
	}
	return retorno;
}

int isAlphaNum(char* pResultado){
	int retorno = 1;
	int i;
	if(pResultado != NULL){
		for(i=0;pResultado[i] != '\0';i++){
			if((pResultado[i] != ' ') && (pResultado[i] < 'a' || pResultado[i] > 'z') && (pResultado[i] < 'A' || pResultado[i] > 'Z') && (pResultado[i] < '0' || pResultado[i] > '9')){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int utn_getCuit(char msg[], char msgError[], char pResult[], int attemps)
{
	int retorno = -1;
	int limit = 12;
	char bufferString[ARRAY_SIZE];

	if(msg != NULL && msgError != NULL && pResult != NULL && attemps >= 0)
	{
		do
		{
			printf("\n%s", msg);
			if(myGets(bufferString, ARRAY_SIZE) == 0 && isStringCuit(bufferString) == 1 && strnlen(bufferString, sizeof(bufferString)) < limit)
			{
				retorno = 0;
				strncpy(pResult, bufferString, limit);
				break;
			}
			else
			{
				printf("%s", msgError);
				attemps--;
			}
		}while(attemps >= 0);
	}
	return retorno;
}


static int isStringCuit(char string[])
{
	int retorno = 1;
	if(string != NULL && strlen(string) > 0)
	{
		for(int i = 0;string[i] != '\0'; i++)
		{
			if((string[i] < '0' || string[i] > '9') && (string[i] < 'A' || string[i] > 'Z') && string[i] != 32 )//
			{
				sprintf(string,"%d", i);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}



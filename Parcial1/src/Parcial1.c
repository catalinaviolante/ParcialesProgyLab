/*
 ============================================================================
 Name        : PrimerParcial.c
 Author      : Cat
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "publicacion.h"
#include "cliente.h"
#include "report.h"
#define PUBLICACION_QTY 1000
#define CLIENTE_QTY 100

int main(void) {

	setbuf(stdout, NULL);
	Cliente clienteList[CLIENTE_QTY];
	Publicacion publicacionList[PUBLICACION_QTY];

	cliente_initList(clienteList, CLIENTE_QTY);
	publicacion_initList(publicacionList, PUBLICACION_QTY);

	int option;

	do
	{
		if(utn_getMenu(&option, 3, 0, 10)==0)
		{
			switch(option)
			{
				case 1:
					if(cliente_add(clienteList, CLIENTE_QTY)==0)
					{
						printf("Cliente dado de alta exitosamente!");
					}
					else
					{
						printf("Algo salio mal al dar de alta al cliente.");
					}
					break;
				case 2:
					if(cliente_modify(clienteList, CLIENTE_QTY)== 0)
					{
						printf("El cliente fue modificado con exito!");
					}
					else
					{
						printf("Algo salio mal al intentar modificar al cliente.");
					}
					break;
				case 3:
					if(publicacion_baja(publicacionList, PUBLICACION_QTY, clienteList, CLIENTE_QTY)== 0)
					{
						printf("La baja del cliente fue realizada exitosamente!");
					}
					else
					{
						printf("Ocurrio un error en la baja.");
					}

					break;
				case 4:
					if(publicacion_alta(publicacionList, PUBLICACION_QTY, clienteList, CLIENTE_QTY)==0)
					{
						printf("El alta de la publicacion fue realizada exitosamente.");
					}
					else
					{
						printf("No fue posible realizar el alta de su publicacion.");
					}
					break;
				case 5:
					if(publicacion_changeStatus(publicacionList, PUBLICACION_QTY, clienteList, CLIENTE_QTY,5)== 0)
					{
						printf("La publicacion fue pausada con exito!");
					}
					else
					{
						printf("Algo salio mal al intentar pausar la publicacion.");
					}
					break;
				case 6:
					if(publicacion_changeStatus(publicacionList, PUBLICACION_QTY, clienteList, CLIENTE_QTY,6)== 0)
					{
						printf("La publicacion fue reanudada con exito!");
					}
					else
					{
						printf("Algo fallo al reanudar la publicacion");
					}
					break;
				case 7:
					if(publicacion_printClientActiveOnes(publicacionList, PUBLICACION_QTY, clienteList, CLIENTE_QTY)== 0)
					{
						printf("Fin de la impresion!");
					}
					else
					{
						printf("No se pudo imprimir.");
					}
					break;
				case 8:
					if(report_menu(clienteList, CLIENTE_QTY, publicacionList, PUBLICACION_QTY)==0)
					{
						printf("\nFin del informe\n");
					}
					else
					{
						printf("\nHubo un error al reportar!\n");
					}
					break;
				case 9:
					cliente_automaticCharging(clienteList);
					publicacion_automaticCharging(publicacionList);
					printf("Se ha realizado la carga automatica de datos.");
					break;
			}
		}
	}while(option != 10);




	return EXIT_SUCCESS;
}

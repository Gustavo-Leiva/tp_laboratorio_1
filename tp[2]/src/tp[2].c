/*
 ============================================================================
 Name        : tp[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pasajero.h"
#include "estadoVuelo.h"
#include "tipoPasajero.h"


#define TAMNAME 51
#define TAMLASTNAME 51
#define TAMFLYCODE 10
#define TAM 20
#define TAMEV 6
#define TAMTP 4


#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);

	char salir = 'n';
	    int proximoId = 0001;//suponemos que el ID arranca en el 1000.
	    ePasajero lista[TAM];
	    eEstadoVuelo estadoVuelo[TAMEV]={

	    {  1, "Activo"},
	    {  2, "Cancelado"},
	    {  3, "Cerrado"},
	    {  4, "Demorado"},
	    {  5, "Embarque"},
	    {  6, "Reprogramado"}

	    };


	    eTipoPasajero tipoPasajero[TAMTP]={

	    {  1, "ejecutiva"},
	    {  2, "premium"},
	    {  4, "turista"},
	    {  3, "primera"}
	    };



	     //Banderas
	    //int seIngresoAltaPasajero = 0;


	   //int indice;


	    harcodearPasajeros(lista, TAM, 20, &proximoId);



	    do
	    {

	        switch(menuPasajero())
	        {
	        case 1:
	            if(altaPasajero(lista, TAM, &proximoId))    //Le paso por referencia el ID.
	            {
	                printf("Pasajero cargado con exito!!! \n");

	            }

	            else
	            {
	                printf("no se pudo cargar el Pasajero.");
	            }
	            break;


	        case 2:

	                bajaPasajero(lista, TAM, estadoVuelo, TAMEV, tipoPasajero, TAMTP) ;

	            break;

	        case 3:


	                modificarPasajero(lista,TAM, estadoVuelo, TAMEV, tipoPasajero, TAMTP);



	            break;

	        case 4:
	                ordenarApellidoYTipoPasajeroAsc(lista, TAM, estadoVuelo, TAMEV, tipoPasajero, TAMTP);
	                listarPasajeros(lista, TAM, estadoVuelo, TAMEV, tipoPasajero, TAMTP);
	            break;

	        case 5:


	            listarPasajeros(lista, TAM, estadoVuelo, TAMEV, tipoPasajero, TAMTP);

	            break;




	        case 7:
	            listarPasajeros(lista, TAM,estadoVuelo, TAMEV, tipoPasajero, TAMTP);
	            break;

	        case 8:
	            confirmarSalida (&salir);
	            break;


	        default:
	            printf("opcion invalida \n");
	        }

	        system ("pause");
	    }

	    while(salir != 's');

	return EXIT_SUCCESS;
}

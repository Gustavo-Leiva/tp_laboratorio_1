/*
 * pasajero.h
 *
 *  Created on: 14 may. 2022
 *      Author: Impuestos
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estadoVuelo.h"
#include "tipoPasajero.h"

#ifndef PASAJERO_H_
#define PASAJERO_H_

typedef struct
{

    int id;
    char name [51];
    char lastName [51];
    float price;
    char flycode [10];
    int idTipoPasajero;
    int idEstadoVuelo;
    int isEmpty;


} ePasajero;

#endif /* PASAJERO_H_ */


int menuPasajero();
int menuModificarPasajero();
void confirmarSalida(char* x);
int buscarLibre(ePasajero vec[], int tam, int* pIndex);
int cargarPasajero (ePasajero* pPasajero);
int cargarPasajeros(ePasajero vec[], int tam);//no esta hecha la funcion revisar.
int altaPasajero(ePasajero vec[], int tam, int* pNextId);
//void mostrarPasajero(ePasajero pass, eEstadoVuelo estadoVuelo[], int tamev);
void mostrarPasajero(ePasajero pass, eEstadoVuelo estadoVuelo[], int tamev, eTipoPasajero tipoPasajero[], int tamtp);
int harcodearPasajeros(ePasajero vec[], int tam, int cant, int* pNextId);
int inicializarPasajeros(ePasajero vec[], int tam);
int listarPasajeros (ePasajero vec[], int tam, eEstadoVuelo estadoVuelo[], int tamev, eTipoPasajero tipoPasajero[], int tamtp);
//int listarPasajeros (ePasajero vec[], int tam, eEstadoVuelo estadoVuelo[], int tamev);
//void mostrarPasajeroFila(ePasajero pass, eEstadoVuelo estadoVuelo[], int tamev);
void mostrarPasajeroFila(ePasajero pass, eEstadoVuelo estadoVuelo[], int tamev, eTipoPasajero tipoPasajero[], int tamtp);
int buscarPasajero(ePasajero vec[], int tam, int id, int* pIndex); //busca el empleado que tenga ese id y lo carga en el index
//int bajaPasajero(ePasajero vec[], int tam, eEstadoVuelo estadoVuelo[], int tamev);
int bajaPasajero(ePasajero vec[], int tam, eEstadoVuelo estadoVuelo[], int tamev, eTipoPasajero tipoPasajero[], int tamtp);

//int modificarPasajero(ePasajero vec[], int tam, eEstadoVuelo estadoVuelo[], int tamev);
int modificarPasajero(ePasajero vec[], int tam, eEstadoVuelo estadoVuelo[], int tamev, eTipoPasajero tipoPasajero[], int tamtp);
//int ordenarTipoPasajeroYApellidoAsc(ePasajero vec[], int tam);
int ordenarApellidoYTipoPasajeroAsc(ePasajero vec[], int tam, eEstadoVuelo estadoVuelo[], int tamev,eTipoPasajero tipoPasajero[], int tamtp);
int ordenarCodigoVueloEstadoActivo(ePasajero vec[], int tam);





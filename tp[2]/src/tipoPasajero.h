/*
 * tipoPasajero.h
 *
 *  Created on: 14 may. 2022
 *      Author: Impuestos
 */

#ifndef TIPOPASAJERO_H_
#define TIPOPASAJERO_H_

typedef struct
{
    int id;
    char descripcion[20];


} eTipoPasajero;

#endif /* TIPOPASAJERO_H_ */
int cargarDescripcionTipoPasajero(eTipoPasajero tipoPasajero[], int tam, int id, char desc[]);
int validarTipoPasajero(eTipoPasajero vec[], int tam, int id);
//int buscarTipoPasajero(eTipoPasajero vec[], int tam, int id, int* pIndex);

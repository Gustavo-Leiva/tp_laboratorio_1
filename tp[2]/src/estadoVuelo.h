/*
 * estadoVuelo.h
 *
 *  Created on: 14 may. 2022
 *      Author: Impuestos
 */

#ifndef ESTADOVUELO_H_
#define ESTADOVUELO_H_

typedef struct
{
    int id;
    char descripcion[20];


}eEstadoVuelo;


#endif /* ESTADOVUELO_H_ */
int cargarDescripcionEstadoVuelo(eEstadoVuelo estadoVuelo[], int tam, int id, char desc[]);
int listarEstadoVuelo(eEstadoVuelo estadovuelo[], int tam);
//int buscarSector(eSector vec[], int tam, int id, int* pIndex);
//int validarSector(eSector vec[], int tam, int id);

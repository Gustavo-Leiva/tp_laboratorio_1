/*
 * leiva.c
 *
 *  Created on: 11 abr. 2022
 *      Author: Impuestos
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "leiva.h"

int menu ()
{

    int opcion;

    system("cls");
    printf("Menu de opciones \n\n");
    printf("1. Ingresar kilometros:\n");
    printf("2. Ingresar precio de vuelos: \n");
    printf("3. Calcular todos los costos:\n");
    printf("4. Informar resultados \n");
    printf("5. Carga forzada de datos \n");
    printf("6. Salir \n\n");
    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;


}


//calculo con formas de pago de los vuelos de Aerolineas
float debitoAerolineas (float aerolineas)
{
    float debito;
    debito = aerolineas - (aerolineas* 0.10);
    return debito;

}

float creditoAerolineas (float aerolineas)
{
    float credito;
    credito = aerolineas + (aerolineas *0.25);
    return credito;

}

float pagarConBitcoin (float bitcoin)
{
    float pagarbitcoin;
    pagarbitcoin =bitcoin / 4606954.55;
    return  pagarbitcoin;
}



float pagarConBitcoinCargaForzada (float bitcoin)
{
    float pagarbitcoin;
    pagarbitcoin =bitcoin / 4605153.93; //Dato consultado el 11/04/2022
    return  pagarbitcoin;
}


//calculo con formas de pago de los vuelos de Latam
float debitoLatam (float latam)
{
    float debito;
    debito = latam - (latam* 0.10);
    return debito;

}

float creditoLatam (float latam)
{
    float credito;
    credito = latam + (latam *0.25);
    return credito;


}


//mensaje de salir.
void confirmarSalida(char* x)
{

    printf("confirma Salida?: ");
    fflush(stdin);
    scanf("%c", x);
}


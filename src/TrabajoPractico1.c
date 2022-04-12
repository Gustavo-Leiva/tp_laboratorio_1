/*
 ============================================================================
 Name        : TrabajoPractico1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#include "leiva.h"


//funcion main
int main()

{


	setbuf(stdout,NULL);


//Declaracion de variables
    char salir = 'n';
    float precioAerolineas;
    float precioLatam;
    float resultadoDebitoAerolineas;
    float resultadoCreditoAerolineas;
    float resultadoBitcoinAerolineas;
    float resultadoPrecioUnitarioAerolineas;
    int kilometros;
    float resultadoDebitoLatam;
    float resultadoCreditoLatam;
    float resultadoBitcoinLatam;
    float resultadoPrecioUnitarioLatam;
    float diferenciaPrecios;
    int kilometrosCargaForzada = 7090;
    float precioAerolineasCargaForzada = 162965;
    float precioLatamCargaForzada = 159339;
    float resultadoDebitoAerolineasCargaForzada;
    float resultadoCreditoAerolineasCargaForzada;
    float resultadoDebitoLatamCargaForzada;
    float resultadoCreditoLatamCargaForzada;
    float resultadoPrecioUnitarioAerolineasCargaForzada;
    float resultadoPrecioUnitarioLatamCargaForzada;
    float resultadoBitcoinAerolineasCargaForzada;
    float resultadoBitcoinLatamCargaForzada;
    float diferenciaPreciosCargaForzada;

    //Banderas
    int seIngresoKilometros = 0;
    float seIngresoPrecioAereo = 0;
    float seIngresoCostos =0;





    do
    {

        switch(menu())
        {

        //pido el dato de kilometros
        case 1:
            printf("Ingrese los kilometros: ");
            scanf("%d", &kilometros);
            while(kilometros <0)
            {
                printf("Incorrecto! ingrese los kilometros Positivos: \n");
                scanf("%d", &kilometros);
            }
            printf ("Kms Ingresados %d kms\n", kilometros);
            seIngresoKilometros =1;
            break;



        case 2:
            if(seIngresoKilometros == 1)//si se ingresaron los kilometros pido el precio
            {

                printf("Ingrese el precio de vuelo de Aerolineas: ");//pido el precio del vuelo.
                scanf("%f", &precioAerolineas);//guardo en la memoria el dato
                while(precioAerolineas < 0)//valido que el importe de precio sea un numero positivo
                {
                    printf("Incorrecto! El precio debe ser positivo. Reintente el precio de Aerolineas.: ");
                    scanf("%f", &precioAerolineas);

                }
                printf("Precio de Aerolineas Ingresado es %.2f \n", precioAerolineas);//muestro el precio de aerolineas si es positivo.





                printf("Ingrese el precio de Vuelo de Latam: ");//pido el precio del vuelo.
                scanf ("%f", &precioLatam);//guardo en la memoria el dato
                while(precioLatam < 0)//valido que el importe de precio sea un numero positivo
                {
                    printf("Incorrecto! El precio debe ser positivo. Reintente el precio de Latam.: ");
                    scanf("%f", &precioLatam);

                }

                printf("Precio de Latam Ingresado es %.2f \n", precioLatam);
                seIngresoPrecioAereo = 1;

            }
            else
            {
                printf("Para Ingresar el precio de los vuelos, primero debe ingresar los Kilometros. Ingrese Kilometros. \n\n");
            }

            seIngresoPrecioAereo=1;
            break;

        case 3:
        {
            if(seIngresoPrecioAereo==1)
            {
                printf("si ingreso datos en opcion 1 y opcion 2 presione la opcion 4 para ver los resultados. \n");

            }
            else
            {
                if(seIngresoKilometros==1 )
                {
                    printf("se debe ingresar los precios  de los viajes; \n");
                }
                else
                {
                    printf("para calcular los costos deberiamos ingresar el precio de los Vuelos. Ingrese el precio de los Vuelos\n");
                }
            }


        }

        seIngresoCostos =1;

        break;




        case 4:
            if(seIngresoCostos==1 && seIngresoPrecioAereo==1)
            {

                printf("KMs Ingresados: %d: km \n\n", kilometros);


                //Muestra los resultados de las formas de pago a Aerolineas
                printf("Precio Aerolineas $ %.2f: \n", precioAerolineas);

                resultadoDebitoAerolineas= debitoAerolineas(precioAerolineas);
                printf("a) precio con tarjeta de debito $ %.2f\n", resultadoDebitoAerolineas);

                resultadoCreditoAerolineas = creditoAerolineas(precioAerolineas);
                printf("b) precio con con tarjeta de credito $ %.2f \n", resultadoCreditoAerolineas);


                resultadoBitcoinAerolineas = pagarConBitcoin(precioAerolineas);
                printf("c) precio pagando con bitcoin $ %.8f \n", resultadoBitcoinAerolineas);

                resultadoPrecioUnitarioAerolineas = precioAerolineas/kilometros;
                printf("d) mostrar precio Unitario $ %.2f \n\n", resultadoPrecioUnitarioAerolineas);


                //Muestra las formas de pagos a Latam
                printf("Precio Latam $ %.2f: \n", precioLatam);

                resultadoDebitoLatam= debitoLatam(precioLatam);
                printf("a) precio con tarjeta de debito $ %.2f\n", resultadoDebitoLatam);


                resultadoCreditoLatam = creditoLatam(precioLatam);
                printf("b) precio con con tarjeta de credito $ %.2f \n", resultadoCreditoLatam);

                resultadoBitcoinLatam = pagarConBitcoin(precioLatam);
                printf("c) precio pagando con bitcoin $ %.8f \n", resultadoBitcoinLatam);


                resultadoPrecioUnitarioLatam = precioLatam/kilometros;
                printf("d) mostrar precio Unitario $ %.2f \n\n", resultadoPrecioUnitarioLatam);



                if(precioAerolineas>precioLatam)
                {
                    diferenciaPrecios = precioAerolineas-precioLatam;
                    printf("La diferencia de precio es: $ %.2f", diferenciaPrecios);

                }

                else
                {
                    if(precioLatam > precioAerolineas)
                    {
                        diferenciaPrecios = precioLatam-precioAerolineas;
                        printf("La diferencia de precio es: $ %.2f \n", diferenciaPrecios);
                    }

                    else
                    {
                        printf("La diferencia de precio es: $ %.2f \n", diferenciaPrecios);

                    }

                }


            }

            else
            {
                printf("para mostrar los costos se debe ingresar los kilometros y precios de vuelos \n");
            }

            break;


        case 5:

            printf("Mostrar resultados de carga Forzada\n\n");

            printf("KMs Ingresados: %d km \n\n", kilometrosCargaForzada);

            //Muestra los resultados de las formas de pago a Aerolineas
            printf("Precio Aerolineas: %.2f \n", precioAerolineasCargaForzada);

            resultadoDebitoAerolineasCargaForzada= debitoAerolineas(precioAerolineasCargaForzada);
            printf("a) precio con tarjeta de debito $ %.2f\n", resultadoDebitoAerolineasCargaForzada);

            resultadoCreditoAerolineasCargaForzada = creditoAerolineas(precioAerolineasCargaForzada);
            printf("b) precio con con tarjeta de credito $ %.2f \n", resultadoCreditoAerolineasCargaForzada);

            resultadoBitcoinAerolineasCargaForzada = pagarConBitcoinCargaForzada(precioAerolineasCargaForzada);
            printf("c) precio pagando con bitcoin $ %.8f \n", resultadoBitcoinAerolineasCargaForzada);


            resultadoPrecioUnitarioAerolineasCargaForzada = precioAerolineasCargaForzada/kilometros;
            printf("d) mostrar precio Unitario $ %.2f \n\n", resultadoPrecioUnitarioAerolineasCargaForzada);








            //Muestra las formas de pagos a Latam
            printf("Precio Latam: %.2f \n", precioLatamCargaForzada);

            resultadoDebitoLatamCargaForzada= debitoLatam(precioLatamCargaForzada);
            printf("a) precio con tarjeta de debito $ %.2f\n", resultadoDebitoLatamCargaForzada);


            resultadoCreditoLatamCargaForzada = creditoLatam(precioLatamCargaForzada);
            printf("b) precio con con tarjeta de credito $ %.2f \n", resultadoCreditoLatamCargaForzada);

            resultadoBitcoinLatamCargaForzada = pagarConBitcoinCargaForzada(precioLatamCargaForzada);
            printf("c) precio pagando con bitcoin $ %.8f \n", resultadoBitcoinLatamCargaForzada);

            resultadoPrecioUnitarioLatamCargaForzada = precioLatamCargaForzada/kilometros;
            printf("d) mostrar precio Unitario $ %.2f \n\n", resultadoPrecioUnitarioLatamCargaForzada);


            if(precioAerolineasCargaForzada>precioLatamCargaForzada)
            {
                diferenciaPreciosCargaForzada = precioAerolineasCargaForzada-precioLatamCargaForzada;
                printf("La diferencia de precio es: $ %.2f \n", diferenciaPreciosCargaForzada);

            }

            else
            {
                if(precioLatamCargaForzada > precioAerolineasCargaForzada)
                {
                    diferenciaPreciosCargaForzada = precioLatamCargaForzada-precioAerolineasCargaForzada;
                    printf("La diferencia de precio es: $ %.2f", diferenciaPreciosCargaForzada);
                }

                else
                {
                    printf("La diferencia de precio es: $ %.2f", diferenciaPreciosCargaForzada);

                }

            }


            break;

        case 6:
            confirmarSalida (&salir);
            break;


        default:
            printf("opcion invalida \n");


        }

        system("pause");

    }
    while(salir != 's');





    return EXIT_SUCCESS;
}



/*
 * pasajero.c
 *
 *  Created on: 14 may. 2022
 *      Author: Impuestos
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pasajero.h"
#include "estadoVuelo.h"
#include "tipoPasajero.h"



#define TAM 20
#define TAMNAME 51
#define TAMLASTNAME 51
#define TAMFLYCODE 10
#define TAMEV 6
#define TAMTP 4



int menuPasajero()
{
    int opcion;

    system ("cls");
    printf("************ABM Pasajeros**********\n");
    printf("----------------------------------- \n");
    printf("1.Alta Pasajeros.\n");
    printf("2.Baja Pasajeros.\n");
    printf("3.Modificacion Pasajeros.\n");
    printf("4.Listar Pasajeros por Apellido y Tipo.\n");
    printf("5.Listar Codigo de Vuelo y Estado Activo.\n");
    printf("7.Listar Pasajeros.\n");
    printf("8.Salir.\n\n");
    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}


/** \brief guarda la opcion recibida y confirma la salida del menu seleccionado
 *
 * \param  recibe un puntero
  * \return el cierre de las opciones del menu de pasajeros.
 *
 */

void confirmarSalida(char* x)
{
    printf("confirma Salida?: ");
    fflush(stdin);
    scanf("%c", x);
}







/** \brief verificar si en el arrya de pasajero esta libre
 *
 * \param busca espacio en el vector de estructuras de pasajeros
 * \param es el tamaño del array
 * \param es el puntero donde localiza indice del array
 * \return si hay espacio guarda la posicion en el array.
 *
 */
int buscarLibre(ePasajero vec[], int tam, int* pIndex)
{
    int todoOk =0;

    if( vec!= NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1; //pIndex es la direccion de memoria con el * (que es la indireccion de memoria accedo al campo para escribirla).
        for (int i = 0; i < tam; i++) //recorro el array
        {
            if( vec[i].isEmpty)  //pregunto si vec esta vacio
            {

                *pIndex = i; //que guarde la primera linea libre en la estructura.
                break;
            }

        }
        todoOk = 1;

    }

    return todoOk;
}



int cargarPasajero(ePasajero* pPasajero)
{
    int todoOk = 0;
    char auxCad1[TAMNAME];
    char auxCad2[TAMLASTNAME];
    char auxCad3[TAMFLYCODE];
    ePasajero nuevoPasajero;

    if(pPasajero!= NULL)

    {

        printf("ingrese id: ");
        scanf("%d", &pPasajero ->id); //como tengo la direccion de memoria uso la flecha.


        printf("ingrese nombre: ");//ingreso el nombre
        fflush(stdin);
        gets(auxCad1);

        while(strlen(auxCad1) > TAMNAME) //valido el nombre
        {

            printf("nombre demasiado largo. Reingrese nombre:");
            fflush(stdin);
            gets(auxCad1);
        }

        strcpy(pPasajero->name, auxCad1); //copia el dato de la variable auxiliar en el campo de la estructura.


        printf("ingrese apellido: "); //ingreso el apellido
        fflush(stdin);
        gets(auxCad2);

        while(strlen(auxCad2) > TAMLASTNAME) //valido el apellido
        {

            printf("apellido demasiado largo. Reingrese nombre:");
            fflush(stdin);
            gets(auxCad2);
        }

        strcpy(pPasajero->lastName, auxCad2); //copia el dato de la variable auxiliar en el campo de la estructura.


        printf("ingrese precio de vuelo: "); //pido el importe del vuelo.
        scanf("%f", &pPasajero ->price);
        while(pPasajero->price <= 0) // valido que ingrese un valor mayor cero
        {
            printf("Error!!! Debe ingresar un numero positivo. Reintente.");
            printf("ingrese precio de vuelo: ");
            scanf("%f", &pPasajero ->price);
        }

        printf("ingrese codigo de vuelo: ");
        fflush(stdin);
        gets(auxCad3);

        while(strlen(auxCad3) > TAMFLYCODE) //valido el apellido
        {

            printf("codigo de vuelo demasiado largo. Reingrese codigo:");
            fflush(stdin);
            gets(auxCad3);
        }


        strcpy(pPasajero->flycode, auxCad3);


        printf("ingrese tipo de pasajero: ");
        scanf("%d", &pPasajero ->idTipoPasajero);


        printf("ingrese estado de vuelo: ");
//        scanf("%d", &pPasajero ->statusFlight);
        scanf("%d", &pPasajero->idEstadoVuelo);

        todoOk = 1;
    }

    return todoOk;


}




/** \brief carga los pasajeros.
 *
 * \param
 * \param
 * \return
 *
 */

int cargarPasajeros(ePasajero vec[], int tam)
{
    int todoOk = 0;


    if(vec != NULL && tam > 0)
    {

        for (int i = 0; i < tam ; i++)
        {

            cargarPasajero(&vec[i]);
        }


        todoOk = 1;
    }

    return todoOk;


}





/** \brief procesa el alta de empleados.
 *
 * \param pasa los elementos de la estructura
 * \param  pasa el tamaño, la cantidad de elemntos.
 * \return devuelve el alta del pasajero.
 *
 */

int altaPasajero(ePasajero vec[], int tam, int* pNextId)
{
    int todoOk = 0;
    int indice;
    ePasajero nuevoPasajero;
//    char auxCad1[TAMNAME];
//    char auxCad2[TAMLASTNAME];
//    char auxCad3[TAMFLYCODE];


    if(vec != NULL && pNextId != NULL && tam >0)
    {

        system ("cls");
        printf("    *******Alta Pasajeros******\n\n");

        buscarLibre (vec, tam, &indice);

        if(indice == -1)
        {
            printf("no hay lugar en el sistema\n");
        }


        else
        {

            //revisar esta mal debe cargarse !!!!!!!
            nuevoPasajero.id= *pNextId;

            printf("ingrese nombre: ");
            fflush(stdin);
            gets(nuevoPasajero.name);

            printf("ingrese apellido: ");
            fflush(stdin);
            gets(nuevoPasajero.lastName);

            printf("ingrese precio de vuelo: ");
            scanf("%f", &nuevoPasajero.price);
            while(&nuevoPasajero.price < 0)
            {
                 printf("ingrese precio de vuelo: ");
                 scanf("%f", &nuevoPasajero.price);
            }

            printf("ingrese codigo de vuelo: ");
            scanf("%s", &nuevoPasajero.flycode);


            printf("ingrese tipo pasajero:\n");
            printf("------------------------\n");
            printf("*****Tipos de Pasajero***\n");
            printf("------------------------\n");
            printf("codigo       Descripcion\n");
            printf("  1.          ejecutiva\n");
            printf("  2.          premium\n");
            printf("  3.          primera'\n");
            printf("  4.          turista:\n");
            printf("ingrese opcion: ");

            scanf("%d", &nuevoPasajero.idTipoPasajero);


//             while( !validarTipoPasajero(tipoPasajero,tamtp, idTipoPasajero) )
//            {
//                printf("Id invalido. Reingrese id Tipo Pasajero: ");
//                scanf("%d", &idTipoPasajero);
//            }


            printf("ingrese estado de vuelo:\n");
            printf("------------------------\n");
            printf("*****Tipos de Estado*****\n");
            printf("------------------------\n");
            printf("codigo       Descripcion\n");
            printf("  1.          Activo\n");
            printf("  2.          Cancelado\n");
            printf("  3.          Cerrado'\n");
            printf("  4.          Demorado\n");
            printf("  5.          Embarque\n");
            printf("  6.          Reprogramado\n");
            printf("ingrese opcion: ");

            scanf("%d", &nuevoPasajero.idEstadoVuelo);


            nuevoPasajero.isEmpty = 0;//lo inyecto en la lista de empleados.

            vec [indice] = nuevoPasajero; //aca se copia el alta del pasajero en la nueva posicion.

            (*pNextId)++; //incremento el Id

            todoOk = 1; //va a ser uno cuando haya podido cargar un nuevo empleado.
        }

    }

    return todoOk;
}


void mostrarPasajero(ePasajero pass, eEstadoVuelo estadoVuelo[], int tamev, eTipoPasajero tipoPasajero[], int tamtp) //aca lo estoy pasand por valor

{
    printf("ID: %d\n", pass.id);
    printf("nombre: %s\n", pass.name);
    printf("apellido: %s\n", pass.lastName);
    printf("precio: %.2f\n", pass.price);
    printf("codigo de vuelo: %s\n", pass.flycode);
    printf("Tipo de Pasajero: %d\n", pass.idTipoPasajero);
//    printf("Estado de vuelo: %d\n", pass.statusFlight);
    printf("Estado de vuelo: %d\n", pass.idEstadoVuelo);

}





void mostrarPasajeroFila(ePasajero pass, eEstadoVuelo estadoVuelo[], int tamev, eTipoPasajero tipoPasajero[], int tamtp) //aca lo estoy pasand por valro
{

 char descripcion [20];
 char descripcionTP [20];
 cargarDescripcionEstadoVuelo(estadoVuelo, tamev, pass.idEstadoVuelo, descripcion);
 cargarDescripcionTipoPasajero(tipoPasajero,tamtp,pass.idTipoPasajero, descripcionTP);


    printf("   %4d   %10s   %10s  %7.2f     %6s    %10s   %10s\n",
           pass.id,
           pass.name,
           pass.lastName,
           pass.price,
           pass.flycode,
           descripcionTP,
           //pass.typePassenger,
           //pass.statusFlight
           //pass.idEstadoVuelo
           descripcion
          );

}





/** \brief filtra las opciones que tiene para mostrar
 *
 * \param recibe un vector de pasajeros
 * \param recibe un tamaño
 * \return si tiene datos devuelve el valor sino devuelve un mensaje que no hay datos para mostrar.
 *
 */

int listarPasajeros (ePasajero vec[], int tam, eEstadoVuelo estadoVuelo[], int tamev, eTipoPasajero tipoPasajero[], int tamtp)
{
    int todoOk = 0;
    int flag= 1; //vale 1 cuando no haya mostrado empeeados

    if(vec != NULL && tam >0)

    {
        //system ("cls");
        printf("         ***Listado de Pasajeros****\n");
        printf("   id          Nombre   Apellido  Precio   codigo de vuelo    Tipo    Estado\n");
        printf("---------------------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++ )
        {
            //si no esta vacia en el indice i, entonces lo muestro.
            if( !vec[i].isEmpty) //seria, si no esta vacia en el indice vec entonces la muestro. con esto muestro aquellos empleados que no estan vacios.
            {
                mostrarPasajeroFila(vec[i], estadoVuelo, tamev, tipoPasajero, tamtp);
                flag = 0;
            }
        }

        if (flag) //aca entro cuando no hay empleados para mostrar.
        {
            printf("no hay pasajeros en el sistema.\n");
        }

        todoOk = 1;
    }

    return todoOk;
}




int harcodearPasajeros(ePasajero vec[], int tam, int cant, int* pNextId)
{
    int todoOk = 0;
    ePasajero pasajero [10] =
    {

        {0, "Juan", "Lopez", 1200.45, "asdfg",1,2, 0},
        {0, "Miguel", "Medina", 1800.12, "bsdfg", 3,2,0},
        {0, "Juana", "Gonzalez", 1500.35, "ytdfg", 2,3,0},
        {0, "Andrea", "Giacomino", 1000.25, "grdfg", 4,1,0},
        {0, "Juliana", "Guada", 1100.10, "judfg", 4,5,0},
        {0, "Martin", "Lopez", 1000.00, "mndfg", 1,6,0},
        {0, "Dario", "Macedonio", 3000.15, "podfg", 2,4,0},
        {0, "Alicia", "Benitez", 1100.45, "cddfg", 3,4,0},
        {0, "Javier", "Gonzalez", 1400.45, "fddfg", 4,1,0},
        {0, "Leonardo", "Medina", 1900.45, "iudfg", 1,1,0}

    };

    if(vec != NULL && pNextId != NULL && tam>0 && tam <= 20 && cant  <= tam)
    {

        for (int i = 0; i < cant; i++)
        {
            vec[i] = pasajero[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }

        todoOk = 1;
    }

    return todoOk;

}

/** \brief esta funcion lo que hace es borrar los elementos en memoria asi que cuando filtremos los datos a mostrar no tire basura.
 *
 * \param recibe un vector de pasajeros
 * \param recibe un tamaño
 * \return devuelve lista vacias.
 *
 */
int inicializarPasajeros(ePasajero vec[], int tam)
{

    int todoOk = 0;
    if(vec != NULL && tam >0)

    {

        for(int i = 0; i < tam; i++ )
        {
            vec[i].isEmpty = 1;//decimos que todas las estructuras estan vacias

        }

        todoOk = 1;
    }

    return todoOk;




}


int buscarPasajero(ePasajero vec[], int tam, int id, int* pIndex)
{

    int todoOk =0;

    if( vec!= NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1; //pIndex es la direccion de memoria con el * (que es la indireccion de memoria accedo al campo para escribirla).
        for (int i = 0; i < tam; i++) //recorro el array
        {
            if( !vec[i].isEmpty && vec[i].id == id)  //pregunto si vec esta vacio
            {

                *pIndex = i; //que guarde la primera linea libre en la estructura.
                break;
            }

        }
        todoOk = 1;


    }

    return todoOk;
}





int bajaPasajero(ePasajero vec[], int tam, eEstadoVuelo estadoVuelo[], int tamev, eTipoPasajero tipoPasajero[], int tamtp)
{

    int todoOk =0;
    int indice;
    int id;
    char confirma;

    if( vec!= NULL && tam > 0)
    {

        listarPasajeros(vec, tam, estadoVuelo, tamev, tipoPasajero, tamtp);
        printf("ingrese id: ");
        scanf("%d", &id);

        if(buscarPasajero(vec, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe el pasajero con id: %d en el sistema\n", id);
            }



            else
            {

                mostrarPasajero(vec[indice], estadoVuelo, tamev, tipoPasajero, tamtp);
                printf("confirma baja? ");
                fflush(stdin);
                scanf("%c", &confirma);

                if (confirma == 's' || confirma == 'S')
                {

                    vec[indice].isEmpty = 1;
                    printf("Baja exitosa!!!");

                }
                else
                {
                    printf("Baja cancelada por el usuario.\n");
                }

            }


            todoOk = 1;

        }
    }

    return todoOk;
}











int menuModificarPasajero()
{
    int opcion;


    printf("************Campo a modificar**********\n");
    printf("----------------------------------- \n");
    printf("1.Nombre.\n");
    printf("2.Apellido.\n");
    printf("3.Precio.\n");
    printf("4.Codigo de vuelo.\n");
    printf("5.Tipo de Pasajero.\n");
    printf("6.Estado de Vuelo.\n");
    printf("7.Salir.\n\n");
    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}


int modificarPasajero(ePasajero vec[], int tam, eEstadoVuelo estadoVuelo[], int tamev, eTipoPasajero tipoPasajero[], int tamtp)
{

    int todoOk =0;
    int indice;
    int id;
    char confirma;
    char salir = 'n';
    char auxCad[51];
    float precio;
    char codigoVuelo;




    if( vec!= NULL && tam > 0)
    {

        listarPasajeros (vec, tam, estadoVuelo, tamev, tipoPasajero, tamtp);
        printf("ingrese id: ");
        scanf("%d", &id);

        if(buscarPasajero(vec, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe el pasajero con id: %d en el sistema\n", id);
            }



            else
            {

                //mostrarPasajero(vec[indice] estadoVuelo, tamev);


                switch(menuModificarPasajero())
                {


                case 1:
                    printf("Ingrese nuevo nombre: ");//ingreso el nombre
                    fflush(stdin);
                    gets(auxCad);

                    while(strlen(auxCad) > TAMNAME) //valido el nombre
                    {

                        printf("nombre demasiado largo. Reingrese nombre:");
                        fflush(stdin);
                        gets(auxCad);
                    }

                    printf("confirma modificacion? ");
                    fflush(stdin);
                    scanf("%c", &confirma);

                    if (confirma == 's' || confirma == 'S')
                    {
//
                        strcpy(vec[indice].name, auxCad); //copia el dato de la variable auxiliar en el campo de la estructura.
                        printf("Modificacion exitosa!!!");

                    }
                    else
                    {
                        printf("Modificacion cancelada por el usuario.\n");
                    }


                    break;

                case 2:

                    printf("Ingrese Nuevo apellido: "); //ingreso el apellido
                    fflush(stdin);
                    gets(auxCad);

                    while(strlen(auxCad) > TAMLASTNAME) //valido el apellido
                    {

                        printf("apellido demasiado largo. Reingrese apellido:");
                        fflush(stdin);
                        gets(auxCad);
                    }

                    printf("confirma modificacion? ");
                    fflush(stdin);
                    scanf("%c", &confirma);

                    if (confirma == 's' || confirma == 'S')
                    {
//
                        strcpy(vec[indice].lastName, auxCad); //copia el dato de la variable auxiliar en el campo de la estructura.
                        printf("Modificacion exitosa!!!");

                    }
                    else
                    {
                        printf("Modificacion cancelada por el usuario.\n");
                    }


                    break;

                case 3:

                    printf("Ingrese nuevo precio de vuelo: "); //pido el importe del vuelo.
                    scanf("%f", &precio);
                    while(precio <= 0) // valido que ingrese un valor mayor cero
                    {
                        printf("Error!!! Debe ingresar un numero positivo. Reintente.");
                        scanf("%f", &precio);
                    }

                    printf("confirma modificacion? ");
                    fflush(stdin);
                    scanf("%c", &confirma);

                    if (confirma == 's' || confirma == 'S')
                    {

                        vec[indice].price = precio; //copia el dato de la variable auxiliar en el campo de la estructura.
                        printf("Modificacion exitosa!!!");

                    }
                    else
                    {
                        printf("Modificacion cancelada por el usuario.\n");
                    }

                    break;



                case 4:
                    printf("Ingrese nuevo codigo de vuelo: ");
                    fflush(stdin);
                    gets(codigoVuelo);

                    while(strlen(codigoVuelo) > TAMFLYCODE)
                    {

                        printf("codigo de vuelo demasiado largo. Reingrese codigo:");
                        fflush(stdin);
                        gets(codigoVuelo);
                    }


                    printf("confirma modificacion? ");
                    fflush(stdin);
                    scanf("%c", &confirma);

                    if (confirma == 's' || confirma == 'S')
                    {
//
                        strcpy(vec[indice].flycode, codigoVuelo); //copia el dato de la variable auxiliar en el campo de la estructura.
                        printf("Modificacion exitosa!!!");

                    }
                    else
                    {
                        printf("Modificacion cancelada por el usuario.\n");
                    }


                    break;

                case 5:

                    printf("Ingrese nuevo tipo de pasajero: ");
                    scanf("%d", &tipoPasajero);

                    while(tipoPasajero <= 0) // valido que ingrese un valor mayor cero
                    {
                        printf("Error!!! Debe ingresar un numero positivo. Reintente.");
                        scanf("%d", &tipoPasajero);
                    }


                    printf("confirma modificacion? ");
                    fflush(stdin);
                    scanf("%c", &confirma);


                    if (confirma == 's' || confirma == 'S')
                    {
//
                        vec[indice].idTipoPasajero= tipoPasajero; //copia el dato de la variable auxiliar en el campo de la estructura.
                        printf("Modificacion exitosa!!!");

                    }
                    else
                    {
                        printf("Modificacion cancelada por el usuario.\n");
                    }

                    break;



                case 7:
                    confirmarSalida (&salir);
                    break;


                default:
                    printf("opcion invalida \n");


                }




            }

            todoOk = 1;
        }


    }
    return todoOk;

}

int ordenarApellidoYTipoPasajeroAsc(ePasajero vec[], int tam, eEstadoVuelo estadoVuelo[], int tamev, eTipoPasajero tipoPasajero[], int tamtp)
{
    int todoOk = 0;
    ePasajero auxPasajero;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {

                if((strcmp(vec[i].lastName, vec[j].lastName)>0)
                        ||(strcmp(vec[i].lastName, vec[j].lastName)== 0 && vec[i].id<vec[j].id))

               {
                    auxPasajero = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPasajero;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}



//int ordenarCodigoVueloEstadoActivo(ePasajero vec[], int tam)
//{
//    int todoOk = 0;
//    ePasajero auxcodigoVuelo;
//    eEstadoVuelo activo;
//
//    if( vec != NULL && tam > 0)
//    {
//        system("cls");
//        printf("   *** Informe codigos de vuelos por Estado Activo ***\n");
//        printf("---------------------------------------------------------------\n\n");
//
//       if(activo == 1)
//       {
//           for(int i=0; i < tam - 1; i++)
//        {
//            for(int j= i+1; j < tam; j++)
//            {
//
//                if (strcmp(vec[i].flycode, vec[j].flycode) > 0 )
//                {
//                    auxcodigoVuelo = vec[i];
//                    vec[i] = vec[j];
//                    vec[j] = auxcodigoVuelo;
//                }
//            }
//        }
//
//       }
//
//
//
//        todoOk = 1;
//    }
//    return todoOk;
//
//}


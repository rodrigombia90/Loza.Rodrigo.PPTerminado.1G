#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "trabajo.h"
#include "servicio.h"
#include "input.h"

/** \brief inicializa el vector de tabajos para poder cargarlo
 *
 * \param trabajos[] eTrabajo estructura trabajo
 * \param tam_t int tamaño del vector
 * \return int retorna 0 si pudo inicializar 1 si no pudo
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tam_t)
{
    int error = 1;
    if (trabajos!=NULL && tam_t > 0)
    {
        for(int i=0; i<tam_t; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}


/** \brief busca en el vector, lugar libre para cargar trabajos nuevos
 *
 * \param trabajos[] eTrabajo estructura trabajo
 * \param tam_t int tamaño del vector
 * \return int devuelve el primer indice en el que encuentra lugar, -1 si no hay lugar
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[], int tam_t)
{
    int indice = -1;
    for(int i = 0; i < tam_t; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


/** \brief busca trabajo en el vector segun un id que recibe
 *
 * \param trabajos[] eTrabajo estructura trabajo
 * \param tam_t int tamaño del vector
 * \param id int id que usa para buscar en el vector
 * \return int devuleve el indice en el que esta el trabajo a buscar si existe, si no lo encuentra devuelve -1
 *
 */
int buscarTrabajoXId(eTrabajo trabajos[],int tam_t,int id)
{
    int retorno=-1;

    if(trabajos!=NULL&&tam_t>0)
    {
        for(int i=0; i<tam_t; i++)
        {
            if(trabajos[i].id==id&&trabajos[i].isEmpty==0)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}


/** \brief Se fija que se hayan cargado trabajos
 *
 * \param trabajos[] eTrabajo estructura trabajo
 * \param tam_t int tamaño del vector
 * \return int devuelve 0 si se cargo algun trabajo, 1 si no se cargo ninguno
 *
 */
int buscarTrabajo(eTrabajo trabajos[], int tam_t)
{
    int error = 1;
    for(int i = 0; i < tam_t; i++)
    {
        if(trabajos[i].isEmpty == 0)
        {
            error = 0;
            break;
        }
    }
    return error;
}

/** \brief da de alta nuevo trabajo
 *
 * \param mascotas[] eMascota estructura de mascota
 * \param tam_m int tamaño del vector
 * \param idTrabajo int id para asignarle al trabajo que se da de alta
 * \param tipos[] eTipo estructura de tipo
 * \param tam_t int tamaño del vector
 * \param color[] eColor estrutura de color
 * \param tam_c int tamaño del vector
 * \param servicios[] eServicio estructura de servicio
 * \param tam_s int tamaño del vector
 * \param trabajos[] eTrabajo estructura de trabajo
 * \param tam_tra int tamaño del vector
 * \param clientes[] eCliente estructura cliente
 * \param tam_cli int tamaño del vector
 * \return int devuelve 0 si se dio correctamente de alta, -1 si no se puede dar de alta
 *
 */
int altaTrabajo(eMascota mascotas[],int tam_m,int idTrabajo,eTipo tipos[],int tam_t,eColor color[],int tam_c, eServicio servicios[],int tam_s, eTrabajo trabajos[],int tam_tra,eCliente clientes[],int tam_cli)
{
    int error=-1;
    int indiceTrabajo;
    eTrabajo nuevoTrabajo;

    if(trabajos != NULL && tam_t>0)
    {
        system("cls");
        indiceTrabajo=buscarLibreTrabajo(trabajos,tam_tra);
        if(indiceTrabajo==-1)
        {
            printf("No hay lugar para trabajos");
        }
        else
        {
            nuevoTrabajo.idMascota=getIdMascota(mascotas,tam_m,color,tam_c,tipos,tam_t,clientes,tam_cli);
            nuevoTrabajo.idServicio=getIdServicio(servicios,tam_s);
            system("cls");
            printf("ingrese la fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d/",&nuevoTrabajo.fecha.dia,&nuevoTrabajo.fecha.mes,&nuevoTrabajo.fecha.anio);
            while(validarFecha(nuevoTrabajo.fecha.dia,nuevoTrabajo.fecha.mes,nuevoTrabajo.fecha.anio)!=0)
            {
                printf("Error, ingrese la fecha valida: dd/mm/aaaa");
                scanf("%d/%d/%d/",&nuevoTrabajo.fecha.dia,&nuevoTrabajo.fecha.mes,&nuevoTrabajo.fecha.anio);
            }
            nuevoTrabajo.isEmpty=0;
            nuevoTrabajo.id=idTrabajo;
            trabajos[indiceTrabajo]=nuevoTrabajo;
        }
        error=0;
    }
    return error;
}


/** \brief muestra los trabajos que se cargaron
 *
 * \param trabajos[] eTrabajo estructura trabajo
 * \param tam_t int tamaño del vector
 * \param servicios[] eServicio estructura servicio
 * \param tam_s int tamaño del vector
 * \param mascotas[] eMascota estructura mascota
 * \param tam_m int tamaño del vector
 * \param cliente[] eCliente estructura cliente
 * \param tam_cli int tamaño del vector
 * \return int devuelve 0 si pudo mostrar, 1 si no pudo
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tam_t, eServicio servicios[], int tam_s,eMascota mascotas[], int tam_m,eCliente cliente[],int tam_cli)
{
    int error = 1;

    if( trabajos != NULL && tam_t > 0)
    {

        if(buscarTrabajo(trabajos,tam_m)==1)
        {
            system("cls");
            printf("\n\n  ACTUALMENTE, NO HAY trabajos\n\n");
        }
        else
        {
            system("cls");
            printf("------------------------LISTADO DE TRABAJOS--------------------------------------\n");
            printf("---------------------------------------------------------------------------------\n");
            printf("-----ID         NOMBRE            SERVICIO           Cliente            FECHA----\n");
            printf("---------------------------------------------------------------------------------\n");

            for(int i=0; i<tam_t; i++)
            {
                if(trabajos[i].isEmpty == 0)
                {
                    mostrarTrabajo(trabajos[i], servicios, tam_s,mascotas,tam_m,cliente,tam_cli);

                }
            }
            printf("---------------------------------------------------------------------------------\n");
        }
        printf("\n\n\n\n\n\n");

        error = 0;

    }

    return error;
}


/** \brief muestra 1 trabajo
 *
 * \param trabajo eTrabajo estructura trabajo
 * \param servicios[] eServicio estructura servicio
 * \param tam_s int tamnaño del vector
 * \param mascotas[] eMascota estructura mascota
 * \param tam_m int tamaño del vector
 * \param cliente[] eCliente estructura cliente
 * \param tam_cli int tamaño del vector
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tam_s,eMascota mascotas[], int tam_m,eCliente cliente[],int tam_cli)
{
    char descripcionServ[20];
    char nombreMascota[20];
    char nombreCliente[20];

    if(obtenerDescripcionServicio(servicios,tam_s,trabajo.idServicio,descripcionServ)==0 &&
            obtenerNombreMascota(mascotas,tam_m,trabajo.idMascota,nombreMascota)==0 &&
       obtenerNombreClienteTrabajo(cliente,tam_cli,trabajo.idMascota,nombreCliente,mascotas,tam_m)==0)
    {
        printf("-    %2d        %-10s        %-13s      %-7s         %2d/%0.2d/%4d -\n",
               trabajo.id,
               nombreMascota,
               descripcionServ,
               nombreCliente,
               trabajo.fecha.dia,
               trabajo.fecha.mes,
               trabajo.fecha.anio);
    }
    else
    {
        printf("problema para obtener descripciones");
    }


}


/** \brief lista los trabajos cargados para cada mascota
 *
 * \param mascotas[] eMascota estructura mascota
 * \param tam_m int tamaño del vector
 * \param tipos[] eTipo estructura de tipo
 * \param tam_t int tamaño del vector
 * \param color[] eColor estrutura de color
 * \param tam_c int tamaño del vector
 * \param servicios[] eServicio estructura de servicio
 * \param tam_s int tamaño del vector
 * \param trabajos[] eTrabajo estructura trabajo
 * \param tam_tra int tamaño del vector
 * \param clientes[] eCliente estructura cliente
 * \param tam_cli int tamaño del vector
 * \return int devuelve 0 si pudo listar, 1 si no pudo
 *
 */
int listarTrabajosParaCadaMascota(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra,eServicio servicios[], int tam_s,eCliente clientes[],int tam_cli)
{
    int error=1;
    int auxId;
    int flagTrabajo=-1;
    if(mascotas!=NULL&&trabajos!=NULL&&tam_t>0&&tam_c>0)
    {
        printf("***Trabajos que se le realizaron a una mascota***\n\n");
        auxId=getIdMascota(mascotas,tam_m,colores,tam_c,tipos,tam_t,clientes,tam_cli);
            printf("\n------------------------LISTADO DE TRABAJOS--------------------------------------\n");
            printf("---------------------------------------------------------------------------------\n");
            printf("-----ID         NOMBRE            SERVICIO           Cliente            FECHA----\n");
            printf("---------------------------------------------------------------------------------\n");
        for(int i=0; i<tam_m; i++)
        {
            if(trabajos[i].idMascota==auxId && trabajos[i].isEmpty==0)
            {
                mostrarTrabajo(trabajos[i],servicios,tam_s,mascotas,tam_m,clientes,tam_cli);
                flagTrabajo=1;
            }
            if(!flagTrabajo)
            {
                printf("No se le realizaron trabajos a esa mascota\n");
                break;
            }
        }
        error=0;
    }
    printf("\n\n");
    return error;
}




/** \brief lista el dinero invertido en una mascota
 *
 * \param mascotas[] eMascota estructura mascota
 * \param tam_m int tamaño del vector
 * \param tipos[] eTipo estructura de tipo
 * \param tam_t int tamaño del vector
 * \param color[] eColor estrutura de color
 * \param tam_c int tamaño del vector
 * \param servicios[] eServicio estructura de servicio
 * \param tam_s int tamaño del vector
 * \param trabajos[] eTrabajo estructura trabajo
 * \param tam_tra int tamaño del vector
 * \param clientes[] eCliente estructura cliente
 * \param tam_cli int tamaño del vector
 * \return int devuelve 1 si pudo listar, 0 si no pudo
 *
 */
int listarDineroInvertidoPorMascota(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra,eServicio servicios[], int tam_s, eCliente clientes[], int tam_cli)
{
    int error=0;
    float precioTotal=0;
    int auxId;
    char auxNombre[10];
    if(mascotas!=NULL&&trabajos!=NULL&&tam_t>0&&tam_c>0)
    {
        system("cls");
        printf("***Dinero invertido en una mascota***\n\n");
        auxId=getIdMascota(mascotas,tam_m,colores,tam_c,tipos,tam_t,clientes,tam_cli);
        for(int i=0; i<tam_m; i++)
        {
            if(trabajos[i].isEmpty==0 && trabajos[i].idMascota==auxId)
            {
                for(int s=0; s<tam_s; s++)
                {
                    if(servicios[s].id==trabajos[i].idServicio)
                    {
                        precioTotal+=servicios[s].precio;
                        error=1;
                    }
                }
            }
        }
        obtenerNombreMascota(mascotas,tam_m,auxId,auxNombre);
        printf("El dinero invertido en %s es:$ %.2f\n",auxNombre,precioTotal);

    }
    return error;
}


/** \brief lista los trabajos realizados en una fecha especifica
 *
 * \param mascotas[] eMascota estructura mascota
 * \param tam_m int tamaño del vector
 * \param tipos[] eTipo estructura de tipo
 * \param tam_t int tamaño del vector
 * \param color[] eColor estrutura de color
 * \param tam_c int tamaño del vector
 * \param servicios[] eServicio estructura de servicio
 * \param tam_s int tamaño del vector
 * \param trabajos[] eTrabajo estructura trabajo
 * \param tam_tra int tamaño del vector
 * \param clientes[] eCliente estructura cliente
 * \param tam_cli int tamaño del vector
 * \return int devuelve 1 si pudo listar, 0 si no pudo
 *
 */
int listarTrabajosRealizadosEnUnaFecha(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra,eServicio servicios[], int tam_s,eCliente clientes[],int tam_cli)
{
    int error=0;
    eTrabajo auxTrabajo;
    int flagTrabajo=0;
    if(mascotas!=NULL&&trabajos!=NULL&&tam_t>0&&tam_c>0)
    {
        system("cls");
        printf("ingrese la fecha dd/mm/aaaa");
        scanf("%d/%d/%d/",&auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);
        while(validarFecha(auxTrabajo.fecha.dia,auxTrabajo.fecha.mes,auxTrabajo.fecha.anio)!=0)
        {
            printf("Error, ingrese la fecha valida: dd/mm/aaaa");
            scanf("%d/%d/%d/",&auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);
        }
            printf("\n------------------------LISTADO DE TRABAJOS--------------------------------------\n");
            printf("---------------------------------------------------------------------------------\n");
            printf("-----ID         NOMBRE            SERVICIO           Cliente            FECHA----\n");
            printf("---------------------------------------------------------------------------------\n");

        for(int i=0;i<tam_tra;i++)
        {
            if(trabajos[i].fecha.anio==auxTrabajo.fecha.anio && trabajos[i].fecha.dia==auxTrabajo.fecha.dia && trabajos[i].fecha.mes==auxTrabajo.fecha.mes)
            {
                mostrarTrabajo(trabajos[i],servicios,tam_s,mascotas,tam_m,clientes,tam_cli);
                flagTrabajo=1;
            }
            if(!flagTrabajo)
            {
                printf("No se le realizaron trabajos en esa fecha\n");
                break;
            }
        }
        error=1;
    }

    return error;
}


/** \brief lista los trabajos segun un servicio especifico
 *
 * \param mascotas[] eMascota estructura mascota
 * \param tam_m int tamaño del vector
 * \param tipos[] eTipo estructura de tipo
 * \param tam_t int tamaño del vector
 * \param color[] eColor estrutura de color
 * \param tam_c int tamaño del vector
 * \param servicios[] eServicio estructura de servicio
 * \param tam_s int tamaño del vector
 * \param trabajos[] eTrabajo estructura trabajo
 * \param tam_tra int tamaño del vector
 * \param clientes[] eCliente estructura cliente
 * \param tam_cli int tamaño del vector
 * \return int devuelve 0 si pudo listar, 1 si no pudo
 *
 */
int listarTrabajosXservicio(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra,eServicio servicios[], int tam_s,eCliente clientes[],int tam_cli)
{
    int error=1;
    int auxIdServicio;
    int flag=0;

    if(trabajos!=NULL&&tam_tra>0&&servicios!=NULL&&tam_s>0&&mascotas!=NULL&&tam_m>0)
    {
        system("cls");
        printf("***Listar por servicio***\n\n");
        auxIdServicio=getIdServicio(servicios,tam_s);
        printf("\n------------------------LISTADO DE TRABAJOS--------------------------------------\n");
        printf("---------------------------------------------------------------------------------\n");
        printf("-----ID         NOMBRE            SERVICIO           Cliente            FECHA----\n");
        printf("---------------------------------------------------------------------------------\n");
        for(int i=0;i<tam_tra;i++)
        {
            if(trabajos[i].idServicio==auxIdServicio&&trabajos[i].isEmpty==0)
            {
                mostrarTrabajo(trabajos[i],servicios,tam_s,mascotas,tam_m,clientes,tam_cli);
                flag=1;
            }
        }
        if(!flag)
        {
            printf("No hay trabajos que hayan requerido este servicio\n\n");
        }
        printf("---------------------------------------------------------------------------------\n");
        printf("\n\n");

        error=0;
    }
    return error;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "servicio.h"

/** \brief muestra un servicio
 *
 * \param unServicio eServicio estructura servicio
 * \return void
 *
 */
void mostrarServicio(eServicio unServicio)
{
    printf("- %d   %-13s   %d  -\n",unServicio.id,unServicio.descripcion,unServicio.precio);
}

/** \brief lista los servicios cargados
 *
 * \param servicios[] eServicio estructura sevicios
 * \param tam_s int tamaño del vector
 * \return int devuelve 0 si pudo listar, 1 si no pudo
 *
 */
int mostrarServicios(eServicio servicios[], int tam_s)
{
    int error = 1;

    if(servicios!= NULL && tam_s > 0)
    {
        system("cls");
        printf("-----LISTADO DE SERVICIOS-------\n");
        printf("--------------------------------\n");
        printf("--ID      Servicio      Precio--\n");
        printf("--------------------------------\n");
        for(int i=0; i<tam_s; i++)
        {
                mostrarServicio(servicios[i]);

        }
        printf("--------------------------------\n");
        printf("\n");

        error = 0;
    }
    return error;
}

/** \brief busca un servicio en la lista
 *
 * \param servicios[] eServicio estructura servicio
 * \param tam_s int tamaño del vector
 * \param idServicio int id del servicio a buscar
 * \return int devuelve el indice del servicio a buscar
 *
 */
int buscarServicios(eServicio servicios[],int tam_s,int idServicio)
{
    int indice=-1;

    for(int i=0;i<tam_s;i++)
    {
        if(servicios[i].id==idServicio)
        {
            indice=i;
            break;
        }
    }
        return indice;
}

/** \brief obtiene el nombre del servicio
 *
 * \param servicios[] eServicio estructura servicio
 * \param tam_s int tamaño del vector
 * \param idServicio int id del servicio a buscar
 * \param nombreServicio[] char nombre del servicio
 * \return int devuelve 0 si consigue el nombre, 1 si no pudo
 *
 */
int obtenerDescripcionServicio(eServicio servicios[], int tam_s, int idServicio, char nombreServicio[])
{
    int error = 1;
    if(servicios != NULL && tam_s > 0 && nombreServicio != NULL)
    {

        for (int i = 0; i<tam_s ; i++)
        {
            if(servicios[i].id == idServicio)
            {
                strcpy(nombreServicio,servicios[i].descripcion);
                error = 0;
                break;
            }
        }
    }

    return error;

}

/** \brief obtiene el precio del servicio
 *
 * \param servicios[] eServicio estructura servicio
 * \param tam_s int tamaño del vector
 * \param idServicio int id del servicio a buscar
 * \param precio char precio del servicio
 * \return int devuelve 0 si consigue el nombre, 1 si no pudo
 *
 */
int obtenerPrecioServicio(eServicio servicios[], int tam_s, int idServicio, char precio)
{
    int error = 1;
    if(servicios != NULL && tam_s > 0 && precio >0)
    {

        for (int i = 0; i<tam_s ; i++)
        {
            if(servicios[i].id == idServicio)
            {
                precio=servicios[i].precio;
                error = 0;
                break;
            }
        }
    }

    return error;

}

/** \brief consigue el id del serivicio validado
 *
 * \param servicios[] eServicio estructura servicio
 * \param tam_s int tamaño del vector
 * \return int devuelve el id del servicio
 *
 */
int getIdServicio(eServicio servicios[],int tam_s)
{
    int auxId;
    mostrarServicios(servicios,tam_s);
    auxId=getIntNew("Ingrese id","Error, ingrese id valido");
    while(buscarServicios(servicios,tam_s,auxId)==-1)
    {
        auxId=getIntNew("Ingrese id valido","Error, ingrese id valido");
    }

    return auxId;
}

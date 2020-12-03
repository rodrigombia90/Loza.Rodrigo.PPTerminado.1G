#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "mascotas.h"

/** \brief muestra un cliente
 *
 * \param unCliente eCliente
 * \return void
 *
 */
void mostrarCliente(eCliente unCliente)
{
    printf("- %-4d   %-12s    %-4c  -\n",unCliente.id,unCliente.nombre,unCliente.sexo);
}

/** \brief consigue id del cliente validado
 *
 * \param clientes[] eCliente estructura cliente
 * \param tam_cli int tamaño del vector
 * \return int devuelve el id del cliente que encuentra
 *
 */
int getIdCliente(eCliente clientes[],int tam_cli)
{
    int auxId;
    mostrarClientes(clientes,tam_cli);
    auxId=getIntNew("Ingrese id","Error, ingrese id valido");
    while(buscarCliente(clientes,tam_cli,auxId)==-1)
    {
        auxId=getIntNew("Ingrese id valido","Error, ingrese id valido");
    }

    return auxId;
}

/** \brief muestra un cliente
 *
 * \param clientes[] eCliente estructura cliente
 * \param tam_cli int tamaño del cliente
 * \return int devuelve 0 si puede mostrar, 1 si no pudo
 *
 */
int mostrarClientes(eCliente clientes[], int tam_cli)
{
    int error = 1;

    if(clientes!= NULL && tam_cli > 0)
    {

        system("cls");
        printf("-----LISTADO DE CLIENTES--------\n");
        printf("--------------------------------\n");
        printf("--ID      Nombre      Sexo--\n");
        printf("--------------------------------\n");
        for(int i=0; i<tam_cli; i++)
        {
            if(clientes[i].id!=0)
            {
                mostrarCliente(clientes[i]);
            }
        }
        printf("--------------------------------\n");
        printf("\n");

        error = 0;
    }
    return error;
}

/** \brief obtiene el nombre de un cliente
 *
 * \param clientes[] eCliente estructura cliente
 * \param tam_cli int tamaño del vector
 * \param idCliente int id del cliente a buscar
 * \param nombreCliente[] char nombre del cliente
 * \return int devuelve 0 si pudo conseguir, 1 si no pudo
 *
 */
int obtenerNombreCliente(eCliente clientes[], int tam_cli, int idCliente, char nombreCliente[])
{
    int error = 1;
    if(clientes != NULL && tam_cli > 0 && nombreCliente != NULL)
    {
        for (int i = 0; i<tam_cli ; i++)
        {
            if(clientes[i].id == idCliente)
            {
                strcpy(nombreCliente,clientes[i].nombre);
                error = 0;
                break;
            }
        }
    }
    return error;
}

/** \brief obtiene el nombre del cliente en el trabajo
 *
 * \param clientes[] eCliente estructura cliente
 * \param tam_cli int tamaño del vector
 * \param idMascotas int id de la mascota a buscar
 * \param nombreCliente[] char nombre del cliente que tiene la mascota
 * \param mascotas[] eMascota estructura mascota
 * \param tam_m int tamaño del vector
 * \return int devuelve 0 si pudo conseguir, 1 si no pudo
 *
 */
int obtenerNombreClienteTrabajo(eCliente clientes[], int tam_cli, int idMascotas, char nombreCliente[],eMascota mascotas[],int tam_m)
{
    int error = 1;
    char nombre[10];
    if(clientes != NULL && tam_cli > 0 && nombreCliente != NULL)
    {
        for (int i = 0; i<tam_m ; i++)
        {
            obtenerNombreCliente(clientes,tam_cli,mascotas[i].idCliente,nombre);
            if(mascotas[i].id == idMascotas)
            {
                strcpy(nombreCliente,nombre);
                error = 0;
                break;
            }
        }
    }
    return error;
}

/** \brief busca un cliente
 *
 * \param clientes[] eCliente estructura cliente
 * \param tam_cli int tamaño del vector
 * \param idCliente int id del cliente a buscar
 * \return int devuelve el lugar donde esta el cliente
 *
 */
int buscarCliente(eCliente clientes[],int tam_cli,int idCliente)
{
    int indice=-1;

    for(int i=0; i<tam_cli; i++)
    {
        if(clientes[i].id==idCliente)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

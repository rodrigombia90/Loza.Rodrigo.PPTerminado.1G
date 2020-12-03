#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

/** \brief muestra un tipo
 *
 * \param unTipo eTipo estructura tipo
 * \return void
 *
 */
void mostrarTipo(eTipo unTipo)
{
    printf("- %d     %-8s -\n",unTipo.id,unTipo.descripcion);
}

/** \brief muestra los tipos
 *
 * \param tipos[] eTipo estructura tipo
 * \param tam_t int tamaño del vector
 * \return int 0 si pudo mostrar, 1 si no pudo
 *
 */
int mostrarTipos(eTipo tipos[], int tam_t)
{
    int error = 1;

    if(tipos!= NULL && tam_t > 0)
    {
        system("cls");
        printf("--------TIPOS--------\n");
        printf("---------------------\n");
        printf("-- ID     Especie  --\n");
        printf("---------------------\n");
        for(int i=0; i<tam_t; i++)
        {
                mostrarTipo(tipos[i]);

        }
        printf("---------------------\n");
        printf("\n");

        error = 0;
    }
    return error;
}

/** \brief muestra los tipos sin un espacio para que quede mejor graficamente en menu modificar
 *
 * \param tipos[] eTipo estructura tipo
 * \param tam_t int tamaño del vector
 * \return int 0 si pudo mostrar, 1 si no pudo
 *
 */
int mostrarTiposModificar(eTipo tipos[], int tam_t)
{
    int error = 1;

    if(tipos!= NULL && tam_t > 0)
    {
        printf(" ID     Especie     \n");
        printf("-------------------\n\n");
        for(int i=0; i<tam_t; i++)
        {
                mostrarTipo(tipos[i]);

        }
        printf("\n");

        error = 0;
    }
    return error;
}

/** \brief obtiene el nombre del tipo
 *
 * \param tipos[] eTipo
 * \param tam_t int
 * \param idTipo int
 * \param descripcionTipo[] char
 * \return int
 *
 */
int obtenerDescripcionTipo(eTipo tipos[], int tam_t, int idTipo, char descripcionTipo[])
{
    int error = 1;
    if(tipos != NULL && tam_t > 0 && descripcionTipo != NULL)
    {
        for (int i = 0; i<tam_t ; i++)
        {
            if(tipos[i].id == idTipo)
            {
                strcpy(descripcionTipo,tipos[i].descripcion);
                error = 0;
                break;
            }
        }
    }
    return error;
}

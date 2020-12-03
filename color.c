#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"


/** \brief muestra los color
 *
 * \param color[] eColor estructura color
 * \param tam_c int tamaño del vector
 * \return int devuelve 0 si pudo mostrar, 1 si no pudo
 *
 */
int mostrarColores(eColor color[], int tam_c)
{
    int error = 1;
    if(color!= NULL && tam_c > 0)
    {
        system("cls");
        printf("-------COLORES------\n");
        printf("--------------------\n");
        printf("-- ID      Color  --\n");
        printf("--------------------\n");
        for(int i=0; i<tam_c; i++)
        {
            mostrarColor(color[i]);
        }
        printf("--------------------\n");
        error = 0;
    }
    return error;
}

/** \brief muestra un color
 *
 * \param unColor eColor estructura color
 * \return void
 *
 */
void mostrarColor(eColor unColor)
{
    printf("- %d     %-7s -\n",unColor.id,unColor.nombreColor);
}


/** \brief obtiene el nombre del color
 *
 * \param estructura color
 * \param tamaño del vector
 * \param id del color a buscar
 * \param nombre del color
 * \return 0 si pudo encontrar, 1 si no pudo
 */

int obtenerDescripcionColor(eColor colores[],int tam_c,int idColor,char nombreColor[])
{
    int error = 1;
    if(colores != NULL && tam_c > 0 && nombreColor != NULL)
    {
        for (int i = 0; i<tam_c ; i++)
        {
            if(colores[i].id == idColor)
            {
                strcpy(nombreColor,colores[i].nombreColor);
                error = 0;
                break;
            }
        }
    }
    return error;
}

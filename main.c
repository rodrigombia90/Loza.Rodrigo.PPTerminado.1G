#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascotas.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

#define TAM_M 10
#define TAM_T 5
#define TAM_C 5
#define TAM_S 3
#define TAM_TRA 20
#define TAM_CLI 10

char menuOpciones();
int listarInformes(eMascota mascotas[], int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra, eServicio servicios[], int tam_s, eCliente clientes[],int tam_cli);
int main()
{
    eMascota mascotas[TAM_M];
    eTipo datosTipo [10]=
    {
        {1000,"AVE"},
        {1001,"PERRO"},
        {1002,"GATO"},
        {1003,"ROEDOR"},
        {1004,"PEZ"},
    };
    eColor datosColor [10]=
    {
        {5000,"NEGRO"},
        {5001,"BLANCO"},
        {5002,"GRIS"},
        {5003,"ROJO"},
        {5004,"AZUL"},
    };
     eCliente datosCliente [15]=
    {
        {10,"ARAGORN",'m'},
        {11,"ARWEN",'f'},
        {12,"GANDALF",'m'},
        {13,"LUKE",'m'},
        {14,"LEIA",'f'},
        {15,"INDIANA",'m'},
        {16,"BRANCA",'f'},
        {17,"LEGOLAS",'m'},
        {18,"ISINDUR",'m'},
        {19,"THEODEN",'f'},
        {20,"SIDHARTA",'f'},
    };
    eServicio datosServicio [10]=
    {
        {20000,"CORTE",250},
        {20001,"DESPARACITADO",300},
        {20002,"CASTRADO",400},
    };
    char seguir = 's';
    char confirma;
    int idMascota=1;
    int idTrabajo=100;
    eTrabajo trabajos [TAM_TRA];
    inicializarMascotas(mascotas,TAM_M);
    inicializarTrabajos(trabajos,TAM_TRA);
    idMascota += harcodearMascotas(mascotas,TAM_M,5);
    idTrabajo += harcodearTrabajos(trabajos,TAM_TRA,5);

    do
    {
        system("cls");
        switch(menuOpciones())
        {
        case 'a':
            altaMascota(mascotas,TAM_M,idMascota,datosTipo,TAM_T,datosColor,TAM_C,datosCliente,TAM_CLI);
            break;
        case 'b':
            modificarMascota(mascotas,TAM_M,datosTipo,TAM_T,datosColor,TAM_C,datosCliente,TAM_CLI);
            break;
        case 'c':
            bajaMascota(mascotas,TAM_M,datosTipo,TAM_T,datosColor,TAM_C,datosCliente,TAM_CLI);
            break;
        case 'd':
            system("cls");
            ordenarMascotas(mascotas,TAM_M,datosTipo,TAM_T);
            mostrarMascotas(mascotas,TAM_M,datosTipo,TAM_T,datosColor,TAM_C,datosCliente,TAM_CLI);
            break;
        case 'e':
            mostrarTipos(datosTipo,TAM_T);
            break;
        case 'f':
            mostrarColores(datosColor,TAM_C);
            break;
        case 'g':
            mostrarServicios(datosServicio,TAM_S);
            break;
        case 'h':
            altaTrabajo(mascotas,TAM_M,idTrabajo,datosTipo,TAM_T,datosColor,TAM_C,datosServicio,TAM_S,trabajos,TAM_TRA,datosCliente,TAM_CLI);
            idTrabajo++;
            break;
        case 'i':
            mostrarTrabajos(trabajos,TAM_TRA,datosServicio,TAM_S,mascotas,TAM_M,datosCliente,TAM_CLI);
            break;
        case 'j':
            listarInformes(mascotas,TAM_M,datosTipo,TAM_T,datosColor,TAM_C,trabajos,TAM_TRA,datosServicio,TAM_S,datosCliente,TAM_CLI);
            break;
        case 'z':
            printf("Confirma salida? Ingrese s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("Opcion invalida!!!\n");
        }
        system("pause");
    }
    while( seguir == 's');

    return 0;
}

char menuOpciones()
{
    char opcion;
    printf("*** Bienvenido a la Veterinaria***\n\n");
    printf("A_ Alta de Mascota\n");
    printf("B_ Modificar Mascota\n");
    printf("C_ Baja Mascota\n");
    printf("D_ Listar Mascotas\n");
    printf("E_ Listar Tipos\n");
    printf("F_ Listar Colores\n");
    printf("G_ Listar Servicios\n");
    printf("H_ Alta Trabajo\n");
    printf("I_ Listar Trabajos\n");
    printf("J_ Listar Informes\n");
    printf("Z_ Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;
}


int listarInformes(eMascota mascotas[], int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra, eServicio servicios[], int tam_s, eCliente clientes[],int tam_cli)
{
    int error=1;
    char confirma;
    if(mascotas != NULL && tam_m > 0)
    {
        system("cls");
        printf("    ***Informes***\n\n");
        printf("A_ Listar mascotas por color\n");
        printf("B_ Listar mascotas de un tipo\n");
        printf("C_ Listar la mascota de menor edad\n");
        printf("D_ Listar macotas separadas por tipo\n");
        printf("E_ Contar mascotas por tipo o color\n");
        printf("F_ Listar colores con mas cantidad de mascotas\n");
        printf("G_ Listar trabajos que se le hicieron a una mascota\n");
        printf("H_ Listar dinero invertido en una mascota\n");
        printf("I_ Listar trabajos por serivio\n");
        printf("J_ Listar trabajos hechos en una fecha\n");
        printf("k_ Volver al menu principal\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%c", &confirma);
        confirma = tolower(confirma);
        system("cls");
        switch(confirma)
        {
        case 'a':
            listarMascotasXColor(mascotas,tam_m,colores,tam_c,tipos,tam_t,clientes,tam_cli);
            break;
        case 'b':
            listarMascotasXTipo(mascotas,tam_m,colores,tam_c,tipos,tam_t,clientes,tam_cli);
            break;
        case 'c':
            listarMascotaMasJoven(mascotas,tam_m,colores,tam_c,tipos,tam_t,clientes,tam_cli);
            break;
        case 'd':
            listarTodasLasMascotasXtipo(mascotas,tam_m,tipos,tam_t,colores,tam_c,clientes,tam_cli);
            break;
        case 'e':
            contarMascotasXTipoYColor(mascotas,tam_m,tipos,tam_t,colores,tam_c);
            break;
        case 'f':
            coloresConMasMascotas(mascotas,tam_m,colores,tam_c);
            break;
        case 'g':
            listarTrabajosParaCadaMascota(mascotas,tam_m,tipos,tam_t,colores,tam_c,trabajos,tam_tra,servicios,tam_s,clientes,tam_cli);
            break;
        case 'h':
            listarDineroInvertidoPorMascota(mascotas,tam_m,tipos,tam_t,colores,tam_c,trabajos,tam_tra,servicios,tam_s,clientes,tam_cli);
            break;
        case 'i':
            listarTrabajosXservicio(mascotas,tam_m,tipos,tam_t,colores,tam_c,trabajos,tam_tra,servicios,tam_s,clientes,tam_cli);
            break;
        case 'j':
            listarTrabajosRealizadosEnUnaFecha(mascotas,tam_m,tipos,tam_t,colores,tam_c,trabajos,tam_tra,servicios,tam_s,clientes,tam_cli);
            break;
        case 'k':
            break;
        default:
            printf("Opcion invalida!!!\n");
        }
    }
    return error;
}


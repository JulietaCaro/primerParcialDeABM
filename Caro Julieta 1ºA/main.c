#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define AUTOR_CANT 10
#define LIBRO_CANT 10
#define SOCIO_CANT 5
#include "empleado.h"
#include "input.h"
int main()
{
    char seguir;
    char confirmacion;
    //seguir = 'n';
//    contadorLegajo = 0;

    eAutores listaAutores[AUTOR_CANT]=
     {{1, "Caro", "Julieta"}, {2, "Guido", "Estela"},{3, "Arevalo", "Belen"},{4, "Gomez", "Ignacio"},{5, "Bueno", "Oriana"},
     {5, "Perez", "Juan"}, {6, "Gomez", "Maria"}, {7, "Alvarez", "Pedro"}, {8, "Petagna", "Florencia"}, {9, "Gonzalez", "Micaela"}, {10, "Diaz", "Paz"}};

    eLibros listaLibros[LIBRO_CANT]=
    {{1, "Amar"}, {2, "Vivir libre"}, {3, "Vacaciones"}, {4, "Matematica avanzada"},
    {5, "Sherlock Holmes"},{6, "Cronicas de Argentina"}, {7, "Aguafuertes portenas"},
     {8, "Programacion para inexpertos"}, {9, "Pare de sufrir"}, {10, "Fin"}};

     eSocios listaSocio[SOCIO_CANT];

     inicializarSocios(listaSocio, SOCIO_CANT);

     while(confirmacion!='s')
 {
     switch(menu())
     {
        case 1:
            altaSocio(listaSocio, SOCIO_CANT);
            system("pause");
        break;

        case 2:
            modificarSocio(listaSocio, SOCIO_CANT);
            system("pause");
        break;

        case 3:
            bajaSocio (listaSocio, SOCIO_CANT);
            system("pause");
        break;

        case 4:
            listarSocios(listaSocio, SOCIO_CANT);
            system("pause");
        break;

        case 5:
            listarLibros(listaLibros, LIBRO_CANT);
            system("pause");
        break;

        case 6:
            listarAutores(listaAutores, AUTOR_CANT);
            system("pause");
        break;
        default:
            printf("Opcion invalida");

    }
 }
 return 0;
}

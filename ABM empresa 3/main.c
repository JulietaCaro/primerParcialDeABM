#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define EMP_CANT 10
#define SECT_CANT 5
#define MENU_CANT 5
#define ALMUER_CANT 200
#include "empleado.h"
#include "input.h"

int main()
{
  char seguir;
  char confirmacion;
  //int altaEmpleadoBandera;
  int contadorLegajo;
 // int altaAlmuerzoBandera;
  int contadorAlmuerzo;
seguir = 'n';
contadorLegajo = 0;
//altaAlmuerzoBandera = 0;
//altaEmpleadoBandera=0;

  eEmpleados listaEmp[EMP_CANT];/*=
  {{1, "Caro", "Julieta", 'f', 1500, {6, 12, 2000}, 4, 1},
  {2, "Guido", "Estela", 'f', 2000, {21, 06, 2005}, 2, 1},
  {3, "Arevalo", "Belen", 'f', 2500, {8, 5, 2001}, 3, 1},
  {4, "Gomez", "Ignacio", 'm', 500, {17, 12, 2010}, 1, 1},
  {5, "Bueno", "Oriana", 'f', 3500, {22, 2, 2009}, 5, 1}};*/

  eSectores sectores[]=
  {
    {1, "Sistemas"},
    {2, "Finanzas"},
    {3, "RRHH"},
    {4, "Prestaciones"},
    {5, "Asuntos juridicos"}
};

  eMenues menues[MENU_CANT]={{1, "Lentejas", 150}, {2, "Tarta de acelga", 70}, {3, "Sopa", 100}, {4, "Hamburguesa de quinoa", 90}, {5, "Fideos", 120}};

  eAlmuerzos almuerzo[ALMUER_CANT]; //={{1, 1, 1, 29, 4, 2019, 1}, {2, 3, 2, 29, 4, 2019, 2}};

  inicializarEmpleados(listaEmp, EMP_CANT);
  //inicializarAlmuerzos(almuezos, ALMUER_CANT);

while(confirmacion!='s')
 {
     switch(menu())
     {
        case 1:
            altaEmpleado(listaEmp, EMP_CANT, sectores, SECT_CANT, almuerzo);
            system("pause");
        break;

        case 2:
            bajaEmpleado(listaEmp, EMP_CANT);
            system("pause");
        break;

        case 3:
            modificarEmpleado(listaEmp, EMP_CANT, sectores, SECT_CANT);
            system("pause");
        break;

        case 4:
            printf("Listado de los empleados ordenados alfabeticamente");
            ordenarEmpleadosAlfabeticamente(listaEmp, EMP_CANT);
            mostrarEmpleados(sectores, SECT_CANT, listaEmp, EMP_CANT);
            system("pause");
        break;

        case 5:
            printf("Alta almuerzo\n");
            altaAlmuerzo(listaEmp, EMP_CANT, menues, MENU_CANT, almuerzo);

            /*if(altaAlmuerzoBandera==1)
            {
                contadorAlmuerzo++;
            }
            system("pause");*/
        break;

        case 6:
            printf("Mostrar los almuerzos");
            mostrarAlmuerzos(almuerzo, ALMUER_CANT);
            system("pause");
        break;


        case 7:
            printf("Mostrar todos los almuerzos de un empleado");
            int i;
            int auxiliarLegajo;

            getInt(&auxiliarLegajo, "Ingrese el legajo del empleado a mostrar", "\nLegajo inexistente",1, 10);
            i=buscarEmpleado(listaEmp, EMP_CANT, auxiliarLegajo);

            if(listaEmp[i].isEmpty!=1)
            {
                printf("\nLegajo no encontrado");
            }

            mostrarAlmuerzoDeEmpleado(listaEmp, i, sectores, SECT_CANT, almuerzo, ALMUER_CANT);
        break;

        case 8:
            printf("\n¿Desea salir del programa?s/n: ");
            fflush(stdin);
            scanf("%s", &confirmacion);

            if(tolower(confirmacion) == 's')
            {
                printf("Cerrando el programa");
                //seguir='n';
            }
        break;

        default:
            printf("\nError, su opcion no es correcta");
            system("break");
     }
 }
// while(seguir=='s');

 return 0;
 }

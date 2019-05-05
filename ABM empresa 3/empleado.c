#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "empleado.h"
#include "input.h"

int menu()
{
    int opcion;

    printf("\n1. Alta empleado");
    printf("\n2. Baja empleado");
    printf("\n3. Modificar empleado");
    printf("\n4. Mostrar empleados alfabeticamente");
    printf("\n5. Alta almuerzo");
    printf("\n6. Mostrar almuerzos de un empleado");
    printf("\n7. Salir del programa");

    fflush(stdin);
    printf("\n¿Que opcion desea realizar?: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarEmpleados(eEmpleados empleados[], int tamEmpleados)
{
    int i;
    for(i=0; i<tamEmpleados; i++)
    {
        empleados[i].isEmpty=0;
    }
}

void inicializarAlmuerzos (eAlmuerzos almuerzos[], int tamAlmuerzos)
{
    int i;
    for(i=0; i<tamAlmuerzos; i++)
    {
        almuerzos[i].isEmpty=0;
    }
}

int buscarLibre (eEmpleados empleados[], int tamEmpleados)
{
    //int i;
    //i=-1;
    int libre;

    for(int i=0; i<tamEmpleados; i++)
    {
        if(empleados[i].isEmpty==0)
        {
            libre=i;
            break;
        }
    }
    return libre;
}

int buscarEmpleado (eEmpleados empleados [], int tamEmpleados, int legajo)
{
    int indiceLegajo;
    indiceLegajo=-1;

    for(int i=0; i<tamEmpleados; i++)
    {
        if(empleados[i].isEmpty==1 && empleados[i].legajo==legajo)
        {
            indiceLegajo=i;
            break;
        }
    }
    return indiceLegajo;
}

void altaEmpleado(eEmpleados empleados[], int tamEmpleados, eSectores sectores[], int tamSectores, eAlmuerzos almuerzos[])
{
    int indice;
    int legajo;
    int esta;

    indice=buscarLibre(empleados, tamEmpleados);

    if(indice==-1)
    {
        printf("\nNo hay lugar en el sistema");
    }
    else
    {
        printf("Ingrese el legajo del empleado: ");
        scanf("%d", &legajo);

        esta=buscarEmpleado(empleados, tamEmpleados, legajo);

        if(esta!=-1)
        {
            printf("\Existe un empleado con el legajo %d en el sistema", legajo);
        }
        else
        {
            empleados[indice].legajo= legajo;

            getString(empleados[indice].apellido, "Ingrese el apellido del empleado: ", "El apellido excede el largo", 2, 51);
            getString(empleados[indice].nombre, "Ingrese el nombre del empleado: ", "El nombre excede el largo", 2, 51);
            getCharSexo(&empleados[indice].sexo, "Ingrese el sexo del empleado: ", "Debe ser m o f");
            getFloat(&empleados[indice].sueldo, "Ingrese el sueldo del empleado: ", "Debe ser mayor a cero", 1, 1000000);
            getInt(&empleados[indice].fechaDeIngreso.dia, "Ingrese el dia de la fecha de ingreso", "No existe ese dia", 1, 31);
            getInt(&empleados[indice].fechaDeIngreso.mes, "Ingrese el mes de ingreso", "No existe ese mes", 1, 12);
            getInt(&empleados[indice].fechaDeIngreso.anio, "Ingrese el anio de ingeso", "Anio incorrecto", 1950, 2019);
            printf("\nSECTORES");
            printf("\n1. Sistemas");
            printf("\n2. Finanzas");
            printf("\n3. RRHH");
            printf("\n4. Prestaciones");
            printf("\n5. Asuntos juridicos");
            getInt(&empleados[indice].idSector, "Ingese el numero del sector del empleado", "Numero inexistente", 1, 5);
            empleados[indice].isEmpty=1;

            printf("\nSe ha realizado correctamente el alta");
        }
    }
}

void bajaEmpleado (eEmpleados empleados[], int tamEmpleados)
{
    int legajo;
    int confirmacion;

    printf("\nIngrese el legajo del empleado a bajar: ");
    scanf("%d", &legajo);

    for(int i=0; i<tamEmpleados; i++)
    {
        if(legajo==empleados[i].legajo)
        {
            printf("\n¿Desea dar de baja? s/n");
            confirmacion=getche();

            if(tolower(confirmacion)=='s')
            {
                printf("\nSe ha realizado correctamente la baja");
                empleados[i].isEmpty=0;
                break;
            }
            else
            {
                printf("\nBaja cancelada");
                break;
            }
        }
        else
        {
            printf("\nNo existe ese legajo");
        }
    }
}

int obtenerSector (eSectores sectores[], int tamSector, int idSector, char descripcion[])
{
    int todoOk;
    todoOk=0;

    for(int i=0; i<tamSector; i++)
    {
        if(idSector== sectores[i].id)
        {
            strcpy(descripcion, sectores[i].descripcion);
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

void mostrarEmpleado(eSectores sectores[], int tamSectores, eEmpleados empleados)
{
    char nombreSector[20];
   // int consiguioNombre;

    obtenerSector(sectores, tamSectores, empleados.idSector, nombreSector);

    printf("  %d   %s   %s   %c   %f   %d   %d   %d   %d", empleados.legajo, empleados.apellido, empleados.nombre, empleados.sexo, empleados.sueldo, empleados.fechaDeIngreso.dia, empleados.fechaDeIngreso.mes, empleados.fechaDeIngreso.anio);
}

void mostrarEmpleados (eEmpleados empleados[], int tamEmpleados, eSectores sectores[], int tamSectores)
{
    int contador;
    contador = 0;

    printf(" Legajo    Nombre    Sexo    Sueldo    Sector\n\n");
    for(int i=0; i<tamEmpleados; i++)
    {
       if(empleados[i].isEmpty==1)
       {
            mostrarEmpleado(sectores, tamSectores, empleados[i]);
            //contador++;
       }
    }

   /* if(contador == 0)
    {
        printf("\nNo hay empleados para mostrar");
    }*/
}

void modificarEmpleado (eEmpleados empleados[], int tamEmpleados, eSectores sectores[], int tamSectores)
{
    int opcion;
    int indice;
    int legajo;

    printf("\n1. Apellido");
    printf("\n2. Nombre");
    printf("\n3. Sexo");
    printf("\n4. Sueldo");
    printf("\n5. Fecha de ingreso");
    printf("\n6. Sector");
    printf("\n7. Salir");
    printf("\nElija la opcion a cambiar: ");
    scanf("%d", &opcion);

    printf("\nIngrese el legajo del empleado a modificar");
    scanf("%d", &legajo);

    indice=buscarEmpleado(empleados, tamEmpleados, legajo);

    if(indice==-1)
    {
        printf("\nNo existe un empleado con ese legajo");
    }

    else
    {
        switch(opcion)
    {
        case 1:
            getString(empleados[indice].apellido, "Ingrese el apellido: ", "El apellido excede el limite", 2, 51);
        break;

        case 2:
            getString(empleados[indice].nombre, "Ingrese el nombre: ", "El nombre excede el limite", 1, 51);
        break;

        case 3:
            getCharSexo(&empleados[indice].sexo, "Ingrese el sexo: ", "Error, debe ingresar f o m");
        break;

        case 4:
            getFloat(&empleados[indice].sueldo, "Ingrese el sueldo: ", "El sueldo debe ser mayor a cero", 1, 1000000);
        break;

        case 5:
            getInt(&empleados[indice].fechaDeIngreso.dia, "Ingrese el dia de ingreso: ", "Dia incorrecto", 1, 31);
            getInt(&empleados[indice].fechaDeIngreso.mes, "Ingrese el mes de ingreso: ", "Mes incorrecto", 1, 12);
            getInt(&empleados[indice].fechaDeIngreso.anio, "Ingrese el anio de ingreso", "Anio incorrecto", 1950, 2019);
        break;

        case 6:
            printf("\nSECTORES");
            printf("\n1. Sistemas");
            printf("\n2. Finanzas");
            printf("\n3. RRHH");
            printf("\n4. Prestaciones");
            printf("\n5. Asuntos juridicos");
            getInt(&empleados[indice].idSector, "Ingrese el numero del sector", "No existe ese sector", 1, 5);
        break;

        case 7:
        break;

        default:
            printf("\nOpcion incorrecta");
        }

     printf("\nSe ha modificado correctamente");
     }
}

void ordenarEmpleadosAlfabeticamente(eEmpleados empleados[], int tamEmpleados)
{
    eEmpleados auxiliar;

    for(int i=0; i<tamEmpleados-1; i++)
    {
        for(int j=i+1; j<tamEmpleados; j++)
        {
            if(strcmp(empleados[i].apellido, empleados[j].apellido)>0)
            {
                auxiliar= empleados[i];
                empleados[i]=empleados[j];
                empleados[j]=auxiliar;
            }
        }
    }
    printf("\nOrdenamiento de empleados correctamente");
}
void altaAlmuerzo(eEmpleados empleados[], int tamEmpleados, eMenues menues[], int tamMenues, eAlmuerzos almuerzos[])
{
    int legajo;
    int indice;
   // char salir;

    printf("Ingrese el legajo del empleado: ");
    scanf("%d", &legajo);

    indice=buscarEmpleado(empleados, tamEmpleados, legajo);

    if(indice==-1)
    {
        printf("El legajo no pertenece a ningun empleado");
    }
    else
    {
        getInt(&almuerzos[indice].fechaDeAlmuerzo.dia,"Ingrese el dia: ", "No existe ese dia", 1, 31);
        getInt(&almuerzos[indice].fechaDeAlmuerzo.mes, "Ingrese el mes: ", "No existe ese mes", 1, 12);

        printf("**MENU**");
        printf("\n1.Lentejas");
        printf("\n2.Tarta de acelga");
        printf("\n3.Sopa");
        printf("\n4.Hamburguesa de quinoa");
        printf("\n5.Fideos");

        getInt(&almuerzos[indice].idMenu, "Ingrese el numero del menu: ", "No existe ese menu", 1, 5);
        printf("Alta del almuerzo correctamente");
    }

}

void mostrarAlmuerzo(eAlmuerzos almuerzos[], int i)
{
    printf("\n%d  %d  %d  %d  %d  %d", almuerzos[i].id, almuerzos[i].idMenu, almuerzos[i].legajoEmpleado, almuerzos[i].fechaDeAlmuerzo.dia, almuerzos[i].fechaDeAlmuerzo.mes, almuerzos[i].fechaDeAlmuerzo.anio);
}

void mostrarAlmuerzos(eAlmuerzos almuerzos[], int tamAlmuerzos)
{
   int acumulador;
   acumulador = 0;
   printf("\n  ID  LEGAJO  APELLIDO  NOMBRE  MENU  FECHA\n");

   for(int i = 0; i<tamAlmuerzos; i++)
   {
       if(almuerzos[i].isEmpty==1)
       {
           mostrarAlmuerzo(almuerzos, i);
           acumulador++;
       }
   }

   if(acumulador==0)
   {
       printf("\nNo hay almuerzos para mostrar");
   }
}

void mostrarAlmuerzoDeEmpleado(eEmpleados empleados[], int i, eSectores sectores[], int tamSectores, eAlmuerzos almuerzos[], int tamAlmuerzos)
{
    int contador;
    int auxiliar;
    int indice;

    contador=0;

    getInt(&auxiliar, "Ingrese el legajo del empleado", "No existe ese legajo", 1, 10);
    indice=buscarEmpleado(empleados, i, auxiliar);
    if(empleados[i].isEmpty!=1)
    {
        printf("\nNo existe un empleado con ese legajo");
    }
    else
    {
        for(int i=0; i<tamAlmuerzos; i++)
        {
            if(almuerzos[i].isEmpty == 1 && empleados[i].legajo ==auxiliar)
            {
                mostrarAlmuerzo(almuerzos, i);
                contador++;
            }
        }
    }

}


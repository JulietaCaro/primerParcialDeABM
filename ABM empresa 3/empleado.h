#ifndef empleado_h_incluida
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char apellido[51];
    char nombre[51];
    char sexo;
    float sueldo;
    eFecha fechaDeIngreso;
    int idSector;
    int isEmpty;
}eEmpleados;

typedef struct
{
    int id;
    char descripcion [20];
}eSectores;

typedef struct
{
    int id;
    int idMenu;
    int legajoEmpleado;
    eFecha fechaDeAlmuerzo;
    int isEmpty;
}eAlmuerzos;

typedef struct
{
    int id;
    char descripcion[51];
    float importe;
}eMenues;

int menu();

void inicializarEmpleados(eEmpleados empleados[], int tamEmpleados);

void inicializarAlmuerzos(eAlmuerzos almuerzos[], int tamAlmuezos);

int buscarLibre(eEmpleados empleados[], int tamEmpleados);

int buscarEmpleado(eEmpleados[], int tamEmpleados, int legajo);

void altaEmpleado(eEmpleados empleados[], int tamEmpleados, eSectores sectores[], int tamSectores, eAlmuerzos almuerzos[]);

void bajaEmpleado(eEmpleados empleados[], int tamEmpleados);

int obtenerSector(eSectores sectores[], int tamSector, int idSector, char descripcion[]);

void mostrarEmpleado(eSectores sectores[], int tamSectores, eEmpleados empleados);

void mostrarEmpleados(eEmpleados empleados[], int tamEmpleados, eSectores sectores[], int tamSectores);

void modificarEmpleado(eEmpleados empleados[], int tamEmpleados, eSectores sectores[], int tamSectores);

void ordenarEmpleadosAlfabeticamente(eEmpleados empleados[], int tamEmpleados);

void altaAlmuerzo(eEmpleados empleados[], int tamEmpleados, eMenues menues[], int tamMenues, eAlmuerzos almuerzos[]);

//void mostrarAlmuerzo(eAlmuerzos almuerzos[], int i);

void mostrarAlmuerzos(eAlmuerzos almuerzos[], int tamAlmuezos);

void mostrarAlmuerzoDeEmpleado(eEmpleados empleados[], int i, eSectores sectores[], int tamSectores, eAlmuerzos almuerzos [], int tamAlmuerzos);

#endif // empleado_h_incluida


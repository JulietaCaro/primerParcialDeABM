
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
    printf("***MENU DE OPCIONES***");
    printf("\n1. Alta del socio");
    printf("\n2. Modificar socio");
    printf("\n3. Baja del socio");
    printf("\n4. Listar socios");
    printf("\n5. Listar libros");
    printf("\n6. Listar autores");
    printf("\n7. Prestamos");
    printf("\n8. Salir del programa");

    fflush(stdin);
    printf("\n�Que opcion desea realizar?: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarSocios(eSocios socios[], int tamSocios)
{
    int i;
    for(i=0; i<tamSocios; i++)
    {
        socios[i].isEmpty=0;
    }
}

int buscarLibre (eSocios socios[], int tamSocios)
{
    //int i;
    //i=-1;
    int libre;

    for(int i=0; i<tamSocios; i++)
    {
        if(socios[i].isEmpty==0)
        {
            libre=i;
            break;
        }
    }
    return libre;
}

int buscarSocio (eSocios socios [], int tamSocios, int codigo)
{
    int indiceCodigo;
    indiceCodigo=-1;

    for(int i=0; i<tamSocios; i++)
    {
        if(socios[i].isEmpty==1 && socios[i].codigoDeSocio==codigo)
        {
            indiceCodigo=i;
            break;
        }
    }
    return indiceCodigo;
}

void altaSocio(eSocios socios[], int tamSocios)
{
    int indice;
    int codigo;
    int esta;

    indice=buscarLibre(socios, tamSocios);

    if(indice==-1)
    {
        printf("\nNo hay lugar en el sistema");
    }
    else
    {
        printf("Ingrese el codigo del socio: ");
        scanf("%d", &codigo);

        esta=buscarSocio(socios, tamSocios, codigo);

        if(esta!=-1)
        {
            printf("\Existe un socio con el codigo %d en el sistema", codigo);
        }
        else
        {
            socios[indice].codigoDeSocio= codigo;

            getString(socios[indice].apellidoDelSocio, "Ingrese el apellido del socio: ", "El apellido excede el largo", 2, 31);
            getString(socios[indice].nombreDelSocio, "Ingrese el nombre del socio: ", "El nombre excede el largo", 2, 31);
            getCharSexo(&socios[indice].sexo, "Ingrese el sexo del socio: ", "Debe ser M o F");
            getString(socios[indice].numeroTelefono, "Ingrese el telefono del socio: ", "Reingrese", 1, 16);
            getInt(&socios[indice].fechaDeAsociado.dia, "Ingrese el dia de la fecha de asocio", "No existe ese dia", 1, 31);
            getInt(&socios[indice].fechaDeAsociado.mes, "Ingrese el mes de asocio", "No existe ese mes", 1, 12);
            getInt(&socios[indice].fechaDeAsociado.anio, "Ingrese el anio de asocio", "Anio incorrecto", 1950, 2019);
            getString(socios[indice].email, "Ingrese el email", "Supero el maximo", 1, 31);
            socios[indice].isEmpty=1;

            printf("\nSe ha realizado correctamente el alta");
        }
    }
}

void modificarSocio (eSocios socios[], int tamSocios)
{
    int opcion;
    int indice;
    int codigo;

    printf("\n1. Apellido");
    printf("\n2. Nombre");
    printf("\n3. Sexo");
    printf("\n4. Numero de telefono");
    printf("\n5. Fecha de ingreso");
    printf("\n6. Email");
    printf("\n7. Salir");
    printf("\n\nElija la opcion a cambiar: ");
    scanf("%d", &opcion);

    printf("\nIngrese el codigo del socio a modificar");
    scanf("%d", &codigo);

    indice=buscarSocio(socios, tamSocios, codigo);

     if(indice==-1)
    {
        printf("\nNo existe un socio con el codigo %d", codigo);
    }
    else
    {
        switch(opcion)
        {
             case 1:
            getString(socios[indice].apellidoDelSocio, "Ingrese el apellido: ", "El apellido excede el limite", 2, 31);
        break;

        case 2:
            getString(socios[indice].nombreDelSocio, "Ingrese el nombre: ", "El nombre excede el limite", 1, 31);
        break;

        case 3:
            getCharSexo(&socios[indice].sexo, "Ingrese el sexo: ", "Error, debe ingresar F o M");
        break;

        case 4:
            getString(socios[indice].numeroTelefono, "Ingrese el telefono del socio: ", "Reingrese", 1, 16);

        break;

        case 5:
            getInt(&socios[indice].fechaDeAsociado.dia, "Ingrese el dia de asocio: ", "Dia incorrecto", 1, 31);
            getInt(&socios[indice].fechaDeAsociado.mes, "Ingrese el mes de asocio: ", "Mes incorrecto", 1, 12);
            getInt(&socios[indice].fechaDeAsociado.anio, "Ingrese el anio de asocio", "Anio incorrecto", 1950, 2019);
        break;

        case 6:
            getString(socios[indice].email, "Ingrese el email", "Supero el maximo", 1, 31);
        break;

        case 7:
        break;

        default:
            printf("Opcion incorrecta");
        }
        printf("Se ha realizado correctamente la modificacion");
    }
}

void bajaSocio (eSocios socios[], int tamSocios)
{
    int codigo;
    int confirmacion;

    printf("\nIngrese el codigo del socio a bajar: ");
    scanf("%d", &codigo);

    for(int i=0; i<tamSocios; i++)
    {
        if(codigo==socios[i].codigoDeSocio)
        {
            printf("\n�Desea dar de baja? s/n");
            confirmacion=getche();

            if(tolower(confirmacion)=='s')
            {
                printf("\nSe ha realizado correctamente la baja");
                socios[i].isEmpty=0;
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
            printf("\nNo existe ese codigo");
        }
    }
}

void listarSocio(eSocios socios[], int i)
{

    printf("APELLIDO   NOMBRE   SEXO   TELEFONO   DIA ASOCIO   MES ASOCIO   ANIO ASOCIO   EMAIL");
    printf("%10s   %10s   %c   %20s   %d   %d   %d   %20s", socios[i].apellidoDelSocio, socios[i].nombreDelSocio, socios[i].sexo, socios[i].fechaDeAsociado.dia, socios[i].fechaDeAsociado.mes, socios[i].fechaDeAsociado.anio, socios[i].email);

}

void listarSocios (eSocios socios[], int tamSocios)
{
    int contador;
    contador = 0;

    printf(" CODIGO    NOMBRE    SEXO   TELEFONO   DIA ASOCIO   MES ASOCIO   ANIO ASOCIO    EMAIL\n\n");
    for(int i=0; i<tamSocios; i++)
    {
       listarSocio(socios, i);
       contador++;
    }
    if(contador==0)
    {
        printf("\nNo hay socios para mostrar");
    }
}

void listarLibro(eLibros libros[], int i)
{
    printf("%d   %s   %s", libros[i].codigoDeLibro, libros[i].tituloDelLibro, libros[i].nombreDelAutor);
}

void listarLibros(eLibros libros[], int tamLibros)
{
    int acumulador;
    acumulador=0;
    printf("CODIGO   TITULO   AUTOR");

    for(int i=0; i<tamLibros; i++)
    {
        listarLibro(libros, i);
        acumulador++;
    }
    if(acumulador==0)
    {
        printf("No hay libros para mostrar");
    }
}

void listarAutor(eAutores autores[], int i)
{
    printf("%d   %s   %s", autores[i].codigoDeAutor, autores[i].apellidoDelAutor, autores[i].nombreDelAutor);
}

void listarAutores(eAutores autores[], int tamAutores)
{
    int acumulador=0;
    printf("\n CODIGO   APELLIDO   NOMBRE");
    for(int i=0; i<tamAutores; i++)
    {
        listarAutor(autores, i);
        acumulador++;
    }
    if(acumulador==0)
    {
        printf("No hay autores para mostrar");
    }
}

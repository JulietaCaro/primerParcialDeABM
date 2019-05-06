#ifndef empleado_h

//#endif // empleado_h
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
    int codigoDeAutor;
    char apellidoDelAutor [31];
    char nombreDelAutor [31];
}eAutores;

typedef struct
{
    int codigoDeLibro;
    char tituloDelLibro [51];
    eAutores nombreDelAutor;
}eLibros;

typedef struct
{
    int codigoDeSocio;
    char apellidoDelSocio [31];
    char nombreDelSocio [31];
    char sexo;
    char numeroTelefono[16];
    eFecha fechaDeAsociado;
    char email[31];
    int isEmpty;
}eSocios;


void inicializarSocios(eSocios socios[], int tamSocios);
int buscarLibre (eSocios[], int tamSocios);
int buscarSocio (eSocios socios [], int tamSocios, int codigo);
void altaSocio(eSocios socios[], int tamSocios);
void modificarSocio (eSocios socios[], int tamSocios);
void bajaSocio (eSocios socios[], int i);
void listarSocio(eSocios socios[], int tamSocios);
void listarSocios (eSocios socios[], int tamSocios);
void listarLibro(eLibros libros[], int i);
void listarLibros(eLibros libros[], int tamLibros);
void listarAutor(eAutores autores[], int i);
void listarAutores(eAutores autores[], int tamAutores);
#endif // empleado_h

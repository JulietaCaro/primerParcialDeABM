#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(int* input, char mensaje[], char eMensaje[], int minimo, int maximo)
{
    int todoBien;
    int valor;
    todoBien=-1;

    printf("\n%s", mensaje);
    scanf("%d", &valor);

    while(valor<minimo || valor>maximo)
    {
        printf(eMensaje);
        scanf("%d", &valor);
    }
    *input=valor;
    todoBien=0;

    return todoBien;
}

int getFloat (float* input, char mensaje[], char eMensaje[], int minimo, int maximo)
{
    int todoBien = -1;
    float valor;

    printf("\n%s", mensaje);
    scanf("%f", &valor);

    while(valor<minimo || valor>maximo)
    {
        printf(eMensaje);
        scanf("%f", &valor);
    }
    *input=valor;
    todoBien=0;

    return todoBien;
}

int getChar(char* input, char mensaje[], char eMensaje[], char minimo, char maximo)
{
    int todoBien;
    todoBien=-1;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", input);

    while(*input>minimo || *input>maximo)
    {
        printf(eMensaje);
        fflush(stdin);
        scanf("%c",input);
    }
    todoBien=0;

    return todoBien;
}

int getString(char* input, char mensaje[], char eMensaje[], int minimo, int maximo)
{
    int todoBien;
    todoBien=-1;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", input);

    while(strlen(input)>maximo || strlen(input)<minimo)
    {
        printf(eMensaje);
        fflush(stdin);
        scanf("%s", input);
    }
    todoBien=0;

    return todoBien;
}

int getCharSexo(char* input, char mensaje[], char eMensaje[])
{
    char valor;
    int todoBien;
    todoBien=-1;

    printf(mensaje);
    fflush(stdin);
    scanf("%c", &valor);
    valor==toupper(valor);

    while(valor!= 'F' && valor!= 'M')
    {
        printf(eMensaje);
        fflush(stdin);
        scanf("%c", &valor);
        valor=toupper(valor);
    }
    *input=valor;
    todoBien=0;

    return todoBien;
}


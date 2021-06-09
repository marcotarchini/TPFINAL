#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Pila.h"
#include <windows.h>
#include "gotoxy.h"

int main()
{
   int ctr='s';
    int opcion=0;

    do
    {

        system("cls");
        printf("\nTrabajo Practico Final Laboratorio 1");
        printf("\nSistema de Clientes y Consumos");
        printf("\nGRUPO IGLAMA");
        printf("\nDominguez - Ortenzi - Tarchini\n");
        system("pause");
        system("cls");

        printf("\nCLIENTE: Opcion 1");
        printf("\nCONSUMOS: Opcion 2\n");


        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {


        case 1:
        {
            system("cls");
            printf("\nOPCIONES DE CLIENTE");
            printf("\nAlta de cliente: Opcion 3");
            printf("\nBaja de cliente: Opcion 4");
            printf("\n de cliente: Opcion 4");
            printf("\n de cliente: Opcion 5");
            getch();
            break;
        }
        case 2:
        {
            printf("\nOPCIONES DE CONSUMO");
            printf("\nAlta de consumo: Opcion 6");
            printf("\nBaja de consumo: Opcion 7");
            printf("\n de consumo: Opcion 8");
            printf("\n de consumo: Opcion 9");
            getch();
            break;
        }
        case 3:
        {

            printf("");
            getch();
            break;
        }
        case 4:
        {

            printf("");
            getch();
            break;
        }
        case 5:
        {

            printf("");
            getch();
            break;
        }
        case 6:
        {

            printf("");
            getch();
            break;
        }
        case 0:
        {
            ctr='n';
            break;
        }
        }
        printf("\nDesea probar otro punto? S/N \n");
        fflush(stdin);
        ctr=getch();

    }
    while(ctr=='s');

    return 0;
}


void cargaArchivoClientes(char archivo[]){
    char opcion = 0;
    stCliente a;

    FILE *pArchiClientes = fopen(archivo,"ab");
    if(pArchiClientes != NULL){
        do{
            printf("\n ID:..........: %d", a.id);
            printf("\n Numero de Cliente:..........: ");
            scanf("%d", &a.nroCliente);
            printf("\n Ingrese los siguientes datos: ");
            printf("\n Nombre:...........: ");
            scanf("%s", &a.nombre);
            printf(" Apellido:..............: ");
            scanf("%s", &a.apellido);
            fflush(stdin);
            printf(" DNI:..............: ");
            scanf("%d", &a.dni);
            fflush(stdin);
            printf(" Direccion de correo:.........: ");/// comprobar si esta escribiendo una direccion de correo
            scanf("%s", a.email);
            fflush(stdin);
            printf(" Domicilio:...........: "); ///Que pasa con los numeros????
            scanf("%s", a.domicilio);
            printf(" Movil:..............: ");/// No se a que se refiere con Movil, y es caracter
            scanf("%s", &a.movil);
            fflush(stdin);
            a.id++;

            fwrite(&a, sizeof(stCliente), 1, pArchiClientes);

            printf("\n ESC para salir - cualquier tecla para continuar");
            opcion=getch();
            system("cls");
        }
        while(opcion!=27);

        fclose(pArchiClientes);
    }else{
        printf("\n ERROR DE APERTURA DE ARCHIVO ");
    }
}

void muestraArchivoClientes(char archivo[]){
    stCliente a;
    FILE *pArchiClientes = fopen(archivo, "rb");

    if(pArchiClientes != NULL){
        while(fread(&a, sizeof(stCliente), 1, pArchiClientes) > 0){
            muestraUnCliente(a);
        }
        fclose(pArchiClientes);
    }else{
        printf("\n ERROR DE APERTURA DE ARCHIVO ");
    }
}

void muestraUnCliente(stCliente a){
    printf("\n ID:..........: %d", a.id);
    printf("\n Numero de Cliente:..........: %d", a.nroCliente);
    printf("\n Nombre:..........: %s", a.nombre);
    printf("\n Apellido:........: %s", a.apellido);
    printf("\n DNI:.............: %d", a.dni);
    printf("\n Direccion de correo:..........: %s", a.email);
    printf("\n Domicilio:..........: %s", a.domicilio);
    printf("\n Movil:..........: %s", a.movil);
    printf("\n Estado:..........: %d", a.baja);
    printf("\n--------------------------------------");
}

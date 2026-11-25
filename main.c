#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

#define MAX_CMD 256
#define MAX_TITLE 512

static int showMenu(void){
    char buf[32];
    int choice = 0;

    printf("Menu Base de Datos: ");
    printf("1. Use\n");
    printf("2. Insert\n");
    printf("3. Print\n");
    printf("4. Exit\n");
    printf("Elige una opcion (1-4): ");

    if(fgets(buf, sizeof(buf), stdin) == NULL){
        return 4;
    }

    choice = atoi(buf);
    return choice;
}

int main(void){
    char tableName[MAX_CMD] = "";
    char indexName[MAX_CMD] = "";
    bool tableSelected = false;
    int choice = 0;

    do{
        choice = showMenu;
        
        switch(choice){
            case 1: {

            }
            case 2: {

            }
            case 3: {

            }
            case 4: {
                printf("Saliendo del programa\n");
                break;
            }
            default: 
                printf("Opcion no valida. Intentalo de nuevo. \n");
                break;
        }
    }while (choice!=4);

    return 0;
}

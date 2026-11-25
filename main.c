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
    char titleBuf[MAX_TITLE];
    char buf[MAX_CMD];
    Book book;
    bool tableSelected = false;
    int choice = 0;
    int level = 10;
    int i;

    do{
        choice = showMenu();
        
        switch(choice){
            case 1: {
                printf("Introduce el nombre de la tabla: ");
                if(fgets(buf, sizeof(buf), stdin) != NULL){
                    buf[strcspn(buf, "\n")] = '\0';
                    if(strlen(buf) < 4){
                        fprintf(stderr, "Error, nombre de fichero inválido \n");
                        break;
                    }
                    if(createTable(buf)){
                        strcpy(tableName, buf);
                        replaceExtensionByIdx(tableName, indexName);
                        tableSelected = true;
                        printf("Tabla '%s' e indice '%s' listos.\n", tableName, indexName);
                    }else{
                        fprintf(stderr, "Error al abrir o crear la tabla '%s'.\n", buf);
                    }
                }
                break;
            }
            case 2: {
                if(!tableSelected){
                    fprintf(stderr, "Error, debes seleccionar una tabla primero con 'use'.\n");
                    break;
                }

                printf("Introduce la clave primaria (4 caracteres): ");
                if(fgets(buf, sizeof(buf), stdin) == NULL){
                    break;
                }
                buf[strcspn(buf, "\n")] = '\0';
                if(strlen(buf) != PK_SIZE){
                    fprintf(stderr, "Error, la clave debe tener exactamente %d caracteres. \n", PK_SIZE);
                    break;
                }
                
                printf("Introduce el titulo del libro: ");
                if(fgets(titleBuf, sizeof(titleBuf), stdin) == NULL){
                    break;
                }

                titleBuf[strcspn(titleBuf, "\n")] = '\0';
                if(strlen(titleBuf) == 0){
                    fprintf(stderr, "Error, el titulo del libro no puede estar vacio. \n");
                    break;
                }

                memcpy(book.book_id, buf, PK_SIZE);
                book.title_len = strlen(titleBuf);
                book.title= titleBuf;

                if(addTableEntry(&book, tableName, indexName)){
                    printf("Libro '");
                    for(i=0; i <PK_SIZE; i++){
                        printf("%c", book.book_id[i]);
                    }
                    printf("' insertado correctamente. \n");
                }else{
                    fprintf(stderr, "Error al insertar el libro.\n");
                }
                break;

            }
            case 3: {
                if(!tableSelected){
                    fprintf(stderr, "Error, debes seleccionar una tabla primero con 'use'.\n");
                    break;
                }

                printf("Introduce la profundidad maxima a imprimir: ");
                if(fgets(buf, sizeof(buf), stdin) != NULL){
                    level = atoi(buf);
                    if(level <0){
                        level = 0;
                    }
                }
                printf("Arbol de Indices (%s) \n", indexName);
                printTree((size_t)level, indexName);
                break;

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

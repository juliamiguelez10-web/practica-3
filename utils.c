#include "utils.h"


void replaceExtensionByIdx(const char * fileName, char * indexName){

}

bool createTable(const char * tableName){
    FILE *f = NULL;
    int u = NO_DELETED_REGISTERS; /*vale -1*/
    char *indexName = NULL;

    /* Miramos si el .dat ya existe */
    f = fopen(tableName, "rb");
    if(f != NULL){
        fclose(f);
    }
    else{
        /* Si no existe, lo creamos nuevo en binario */
        f= fopen(tableName, "wb+");
        if(f == NULL){
            return false;
        }
        fwrite(&u, sizeof(int), 1, f);
        fclose(f);
    }

    indexName = (char *) malloc(strleb(tableName) +1);
    if(indexName == NULL){
        return false;
    }




    
}

bool createIndex(const char * indexName){
    FILE *f = NULL;

    int u = NO_DELETED_REGISTERS;

    /* Comprobamos si ya existe intentando abrirlo para lectura binaria */
    f = fopen(indexName, "rb");
    if(f != NULL){
        fclose(f);
        return true;
    }

    /* Si no existe, lo creamos nuevo en binario */
    f = fopen(indexName, "wb+");
    if(f == NULL){
        return false;
    }

    /* Escribimos la cabecera: root = -1 y deleted = -1 */
    fwrite(&u, sizeof(int), 1, f);
    fwrite(&u, sizeof(int), 1, f);

    fclose(f);
    return true;
}

bool findKey(const char * book_id, const char * indexName, int * nodeIDOrDataOffset){
    FILE *f = NULL;
    f= fopen(indexName, "rb");
    if(f == NULL){
        return false;
    }




    fclose(f);
    return false;
}

bool addTableEntry(Book * book, const char * tableName, const char * indexName){

}

bool addIndexEntry(char * book_id, int bookOffset, const char * indexName){

}

void printTree(size_t level, const char * indexName){
    FILE *f = NULL;
    int root = -1;

    f = fopen(indexName, "rb");

    if(f == NULL){
        return;
    }

    if();

    fclose(f);
}




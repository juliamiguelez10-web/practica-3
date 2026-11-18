#include "utils.h"


void replaceExtensionByIdx(const char * fileName, char * indexName){

}

bool createTable(const char * tableName){
    FILE *f = NULL;

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
        fwrite();
        fclose(f);
    }


    
}

bool createIndex(const char * indexName){
    FILE *f = NULL;

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

    fwrite();
    fwrite();

    fclose(f);
    return true;
}

bool findKey(const char * book_id, const char * indexName, int * nodeIDOrDataOffset){

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




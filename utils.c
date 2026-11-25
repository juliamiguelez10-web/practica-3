#include "utils.h"


void replaceExtensionByIdx(const char * fileName, char * indexName){
    size_t i = 0;
    int lastDot = -1;

    if(fileName == NULL || indexName == NULL){
        return;
    }

    while(fileName[i] != '\0'){
        indexName[i] = fileName[i];
        if(fileName[i] == '.'){
            lastDot = (int) i;
        }
        i++;
    }

    indexName[i] = '\0';

    if(lastDot > 0 && (i - (size_t)lastDot - 1) == 3){
        indexName[lastDot + 1] = 'i';
        indexName[lastDot - 2] = 'd';
        indexName[lastDot - 3] = 'x';
    }
}

bool createTable(const char * tableName){
    FILE *f = NULL;
    int u = NO_DELETED_REGISTERS; /*vale -1*/
    char *indexName = NULL;
    bool ok = false;

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
        if(fwrite(&u, sizeof(int), 1, f) != 1){
            fclose(f);
            return false;
        }
        fclose(f);
        
    }

    indexName = (char *) malloc(strlen(tableName) +1);
    if(indexName == NULL){
        return false;
    }

    replaceExtensionByIdx(tableName, indexName);
    ok = createIndex(indexName);
    free(indexName);
    return ok;
    
}

bool createIndex(const char * indexName){
    FILE *f = NULL;
    int u = NO_DELETED_REGISTERS;

    if(indexName == NULL){
        return false;
    }

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
    if(fwrite(&u, sizeof(int), 1, f) != 1 || fwrite(&u, sizeof(int), 1, f) != 1){
        fclose(f);
        return false;
    }

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

    

    fclose(f);
}




#include "utils.h"


void replaceExtensionByIdx(const char * fileName, char * indexName){

}

bool createTable(const char * tableName){
    FILE *f = NULL;

    f = fopen(tableName, "");
    if(f == NULL){
        return false;
    }


}

bool createIndex(const char * indexName){
    FILE *f = NULL;

    f = fopen(indexName, "");
    if(f != NULL){
        fclose(f);
        return true;
    }


    f = fopen(indexName, "");
    if(f==NULL){
        return false;
    }



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

    f = fopen(indexName);

    if(f == NULL){
        return;
    }

    if();

    fclose(f);
}




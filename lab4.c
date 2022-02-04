#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Error!\n");
        return -1;
    }
    
    FILE *file1 = fopen(argv[1], "a+");
    FILE *file2 = fopen(argv[2], "r");

    if (file1 == NULL){
        printf("%s has problem\n", argv[1]);
        return -1;
    }

    if (file2 == NULL){
        printf("%s has problem\n", argv[2]);
        return -1;
    }
    if(strcmp(argv[1], argv[2]) == 0){
        printf("Two files should be different\n");
        return -1;
    }

    else{
        char copy;
        while ((copy = fgetc(file2)) != EOF){
            fputc(copy, file1);
        }

        fclose(file1);
        fclose(file2);

        file1 = NULL;
        file2 = NULL;

        return 0;
    
    }
}
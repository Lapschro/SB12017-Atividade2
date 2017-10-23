#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/Interpret.h"

int main(int argc, char** argv){
    char entrada[256];

    if(argc < 2){
        printf("Insira a expressao a ser calculada: ");
        scanf("%[^\n]", entrada);
    }else
       strcpy(entrada,argv[1]);

    printf("%s = %lld\n\n", entrada, Interpret(entrada));
    return 0;
}

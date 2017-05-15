#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/Interpret.h"

int main(int argc, char** argv){
    char entrada[256];
	strcpy(entrada, "");
    if(argc < 2){
        printf("Insira a expressao a ser calculada: ");
        scanf("%[^\n]", entrada);
    }else{
       for(int i = 1; i < argc; i++){
		   strcat(entrada,argv[i]);
	   }
	}
    printf("%s = %lld\n\n", entrada, Interpret(entrada));
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char string[100], vogais[] = {'a', 'e', 'i', 'o', 'u'};
    int cont = 0, i, k;
    FILE *arquivo;

    arquivo = fopen("ex7.txt", "r");

    while (fgets(string, 100, arquivo) != NULL){
           for (i = 0; i < strlen(string); i++){
                for (k = 0; k < 5; k++){
                    if (string[i] == vogais[k]){
                        cont++;
                    }
                }
           }
    }

   printf("\nNumero de caracteres do arquivo que sao vogais: %d", cont);

    fclose(arquivo);

    return 0;
}

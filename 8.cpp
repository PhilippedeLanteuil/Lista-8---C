#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char conteudo[100];
    int cont = 0;
    FILE *arquivo;

    arquivo = fopen("ex8.txt", "r");

    while(fgets(conteudo, 100, arquivo) != NULL){
            cont++;
    }

    fclose(arquivo);

    printf("O arquivo possui %d linhas.\n", cont);

    return 0;
}

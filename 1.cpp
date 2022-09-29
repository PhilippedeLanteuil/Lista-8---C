#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char arquivo1[31], arquivo2[31], texto[101];

    FILE *arquivo;
    FILE *arq1;
    FILE *arq2;

    printf("Insira o nome do primeiro arquivo: ");
    gets(arquivo1);

    printf("Insira o nome do segundo arquivo: ");
    gets(arquivo2);

    arquivo = fopen("ex1c.txt", "w");

    if (arquivo == NULL){
        printf("Erro ao abrir/criar o arquivo!");
        exit(1);
    }

    arq1 = fopen(arquivo1, "r");

    if (arq1 == NULL){
        printf("Erro ao abrir/criar o arquivo!");
        exit(1);
    }

    while (fgets(texto, 101, arq1) != NULL){
        fprintf(arquivo, "%s", texto);
    }

    fclose(arq1);

    arq2 = fopen(arquivo2, "r");

    if (arq2 == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    fprintf(arquivo, "%s", "\n");

    while (fgets(texto, 101, arq2) != NULL){
        fprintf(arquivo, "%s", texto);
    }

    fclose(arq2);
    fclose(arquivo);

    return 0;
}

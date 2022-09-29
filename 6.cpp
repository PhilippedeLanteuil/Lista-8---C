#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char titulo[21], string[21];
    int idade, resultado, x, y, z;

    FILE *arquivo;

    printf("Insira o titulo do arquivo: ");
    gets(titulo);

    strcat(titulo, ".txt");

    arquivo = fopen(titulo, "w");

    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    fprintf(arquivo, "%d %d %d", 15, 25, 35);

    fclose(arquivo);

    arquivo = fopen(titulo, "r");

    fscanf(arquivo, "%d %d %d", &x, &y, &z);

    printf("\n%d %d %d", x, y, z);

    fclose(arquivo);

    return 0;
}


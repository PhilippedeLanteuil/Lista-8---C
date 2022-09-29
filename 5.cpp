#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char titulo[21], texto[101];
    int resultado;

    printf("Insira o titulo do arquivo: ");
    gets(titulo);

    printf("Escreva um texto para ser adicionado no arquivo: ");
    gets(texto);

    FILE *arquivo;

    strcat(titulo, ".txt");

    arquivo = fopen(titulo, "w");

    if (arquivo == NULL){
        printf("Erro ao abrir/criar o arquivo: ");
        exit(1);
    }

    resultado = fputs(texto, arquivo);

    if (resultado == EOF){
        printf("Erro ao gravar o texto!");
        exit(1);
    }

    printf("Texto gravado com sucesso!\n");

    fclose(arquivo);

    return 0;
}

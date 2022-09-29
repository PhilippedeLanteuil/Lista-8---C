#include <stdio.h>
#include <string.h>

struct Pessoa{
    int dia, mes, ano, idade;
    char nome[31];
};

int main(){

    int cont = 0, dia, mes, ano, dia_atual, mes_atual, ano_atual, i, idade_i;
    char texto[101], nome[31];
    FILE *arquivo;

    arquivo = fopen("arq4.txt", "r");

    if (arquivo == NULL){
        printf("Erro ao abrir");
        return 0;
    }

    ano_atual = 2022;
    mes_atual = 8;
    dia_atual = 14;

    while (fgets(texto, 101, arquivo) != NULL){
        cont++;
    }

    struct Pessoa p[cont];

    fclose(arquivo);

    arquivo = fopen("arq4.txt", "r");

    if (arquivo == NULL){
        printf("Erro ao abrir");
        return 0;
    }

    for (i = 0; i < cont; i++){
        fscanf(arquivo, "%s %d %d %d", &nome, &dia, &mes, &ano);

        strcpy(p[i].nome, nome);
        p[i].dia = dia;
        p[i].mes = mes;
        p[i].ano = ano;

        idade_i = ano_atual - p[i].ano;

        if (mes_atual == p[i].mes){
            if (dia_atual < p[i].dia){
                p[i].idade = idade_i - 1;
            }
            else{
                p[i].idade = idade_i;
            }
        }
        else if (mes_atual < p[i].mes){
            p[i].idade = idade_i - 1;
        }

        else{
            p[i].idade = idade_i;
        }

        if (idade_i > p[i].idade){
            printf("\n%s tera %d anos nesse ano.\n", p[i].nome, idade_i);
        }
        else if(idade_i == p[i].idade){
            printf("\n%s tem %d nesse ano.\n", p[i].nome, idade_i);
        }
    }

    fclose(arquivo);

    return 0;


}


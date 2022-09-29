#include <stdio.h>
#include <string.h>

struct Matriz{
    int lin, col;
};

int main(){

    int linha, coluna, quantidade, i, j, k, l, c, achei = 0;
    FILE *arquivo;

    arquivo = fopen("ex2.txt", "r");

    fscanf(arquivo, "%d %d %d", &linha, &coluna, &quantidade);

    int matriz[linha][coluna];
    struct Matriz m[quantidade];

    for (i = 0; i < quantidade; i++){
       fscanf(arquivo, "%d %d", &l, &c);

       m[i].lin = l;
       m[i].col = c;

    }

    for (i = 0; i < linha; i++){
        for (j = 0; j < coluna; j++){

            for (k = 0; k < quantidade; k++){

                if ((i == m[k].lin) && (j == m[k].col)){
                    achei = 1;
                }
            }

            if (achei == 1){
                matriz[i][j] = 0;
            }
            else{
                matriz[i][j] = 1;
            }

            achei = 0;
        }
    }

     for (i = 0; i < linha; i++){
        for (j = 0; j < coluna; j++){
            printf(" %d ", matriz[i][j]);
        }
        printf("\n");
    }

    fclose(arquivo);


    return 0;
}

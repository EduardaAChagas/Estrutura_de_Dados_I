#include <stdio.h>
#include <stdlib.h>

/*
3.	Faça um algoritmo para:
a.	Receber uma Matriz armazenada em um vetor e:
i.	Retornar:
0 – Se for um Matriz Quadrada;
1 – Se for uma Matriz simétrica;
2 – Se for Matriz Diagonal;
3 – Se é Matriz Assimétrica;
        int TipodeMatriz(int *va, int n, int m)
                      
*/


int tipodeMatriz(int *va, int n, int m){
    if (n == m){ // teste matriz quadrada
        for (int i = 0; i < n; i++){ // teste matriz simetrica - precisa ser uma matriz quadrada
            for (int j = 0; j < n; j++){
                if (va[i * n + j] != va[j * n + i]){

                    //Se nao for simetrica vai verificar se é assimetrica
                    float *vTransposta;
                    vTransposta = (float *)malloc(sizeof(float) * n * m);
                    float *vOposta;
                    vOposta = (float *)malloc(sizeof(float) * n * m);

                    //Matriz inversa va para comparar com a transposta e verificar se é assimetrica
                    if (vOposta != NULL && vTransposta != NULL){
                        for (int i = 0; i < (n * m); i++){
                            vOposta[i] = (va[i] * -1); //Matriz oposta
                        };

                        for (int i = 0; i < n; i++){
                            for (int j = 0; j < m; j++){
                                vTransposta[j * n + i] = va[i * m + j]; //Matriz transposta
                            };
                        };

                        int contElemento = 0; //armazenara o total de igualdades encontradas na matriz, deve ser igual a n*m
                        for (int i = 0; i < (n * m) ; i++){
                            if (vTransposta[i] == vOposta[i]){
                                contElemento++;
                            };
                        };

                        free(vOposta);
                        free(vTransposta);

                        if (contElemento == (n * m)){ // contador deve ser igual ao tamanho total da matriz para que tudo seja igual e ela seja assimetrica
                            return 3;
                        };
                    };
                    return 0;
                };
            };
        };
        return 1;
    };
}
int main(){
    int tamVet, linha, coluna;
    printf("Qual o tamanho do vetor?\n");
    scanf("%d",&tamVet);
    int *vetor;
    int *matriz;
    matriz = (int*)malloc(sizeof(int)*tamVet);
    vetor = (int*)malloc(sizeof(int)*tamVet);
    if (vetor!=NULL && matriz!=NULL){
        for (int i=0;i<tamVet;i++){
            printf("Insira um elemento na matriz: \n");
            scanf("%d",&vetor[i]);
        }
        matriz=vetor;
    }

    printf("%d",tipodeMatriz(matriz, linha, coluna));

    return 0;
}
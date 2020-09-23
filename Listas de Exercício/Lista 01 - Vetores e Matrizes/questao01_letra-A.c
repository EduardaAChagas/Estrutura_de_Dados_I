//1 QUESTAO - Faça um algoritmo que recebe um vetor de n números reais e uma matriz mxp de números reais, e imprime em quais posições da matriz 
//(linha e coluna) o valor é igual a um dos valores do vetor (informe também a posição do vetor).
//a)Considere a matriz alocada como vetor de vetores (matriz 2D)
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    float **mat, *vet;
    int linha, coluna;
    printf("Insira o tamanho do vetor: \n");
    scanf("%d",&n);
    printf("Insira a quantidade de linhas e colunas da matriz: \n");
    printf("Linhas: ");
    scanf("%d",&linha);
    printf("\nColunas: ");
    scanf("%d",&coluna);
    //ler os elementos do vetor
    vet = (float*)malloc(sizeof(float)*n);
    if (vet != NULL){
        for (int i=0;i<n;i++){
        printf("Insira um elemento do vetor: \n");
        scanf("%f",&vet[i]);
        }
    }
    

	// alocando o vetor de ponteiros (linhas da matriz)
	mat = (float**)malloc(sizeof(float*)*linha);
    if (mat != NULL){
        // alocando cada uma das linhas da matriz
        int i;
        for(i = 0; i < linha; i++){
            mat[i] = (float*)malloc(coluna * sizeof(float));
            if (mat[i] == NULL){
                break;
            }
    }
    //ler os elementos da matriz
    for (int i=0;i<linha;i++){
        for (int j=0;j<coluna;j++){
            printf("\nInsira um elemento na matriz: \n");
            scanf("%e",&mat[i][j]);
        }
    }
    }
    printf("********************************************\n");
    printf("\tMATRIZ\n");
    //printar matriz 
    for(int i=0;i<linha;i++)
	{
		for(int j = 0; j < coluna; j++)
			printf("%0.0f\t", mat[i][j]);
		printf("\n");
	}
    printf("********************************************\n");
    printf("\tVETOR\n");
	//print do vetor
    for (int i=0;i<n;i++){
        printf("%0.0f\t",vet[i]);
    }
// Faça um algoritmo que recebe um vetor de n números reais e uma matriz mxp de números reais, e imprime em quais posições da matriz 
//(linha e coluna) o valor é igual a um dos valores do vetor (informe também a posição do vetor).
    int CmpVectorMatrix ( int n, int m, int p, float *vet, float **mat){
        for (int i=0;i<n;i++){
            //comparar v[i] com todos os elementos da matriz ma[j][k]
            for (int j=0;j<m;j++){
                for (int k=0;k<p;k++){
                    if(vet[i]==mat[j][k]){
                        printf("\nO Elemento %0.0f esta na posicao %d do vetor e na posicao mat[%d][%d] da matriz\n",vet[i],i+1,j+1,k+1);
                    }
                }
            }
        }
        return 0;
    }
    CmpVectorMatrix(n,linha,coluna,vet,mat);
    return 0;
}
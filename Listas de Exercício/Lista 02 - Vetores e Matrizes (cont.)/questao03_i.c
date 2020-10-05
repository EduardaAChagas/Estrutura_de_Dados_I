/*A lista de exercício deve ser respondida manuscrita em papel e escaneada (fotografada), gerando um único arquivo pdf.  

3.	Faça um algoritmo para receber uma Matriz armazenada em um vetor e:
i.	Retornar:
    0 – Se for um Matriz Quadrada;
    1 – Se for uma Matriz simétrica;
    2 – Se for Matriz Diagonal;
    3 – Se é Matriz Assimétrica;
                        int TipodeMatriz(int *va, int n, int m)


ii.	Retornar um vetor com a transposta da Matriz
int *transposta(int *va, int n, int m)


iii.	Retornar um vetor com os elementos da linha l da matriz a
int * linhadaMatriz(int *va, int n, int m, int l)


v.	Retornar Um vetor com os elementos da coluna “p” da matriz
 int * colunadaMatriz(int *va, int n, int m, int p)


vi.	Retornar Um vetor com os elementos da diagonal principal da matriz
 int * diagonaldaMatriz(int *va, int n, int m)
 */


#include <stdio.h>
#include <stdlib.h>

int main(){
    //ii.	Retornar um vetor com a transposta da Matriz
    //int *transposta(int *va, int n, int m)
    int* Transposta(int n, int m, int *va){
        int *vtransp;
        if(va!=NULL){
            vtransp = (int*)malloc(sizeof(int)*n*m);
            if(vtransp!=NULL){
                for(int i=0; i<n; i++){
                    for(int j=0; j<m; j++){
                        vtransp[m*i+j]=va[m*j+i];
                    }
                }
                return vtransp;	
            }
            free(vtransp);	
        }
        return NULL;
    }

//  iii. Retornar um vetor com os elementos da linha l da matriz a
//  int * linhadaMatriz(int *va, int n, int m, int l)
    int *linhadaMatriz(int n,int m,int *va, int l){//RETORNA A LINHA K
        int *vetor = (int*)malloc(sizeof(int)*m);
        if(va!=NULL && l<n && l>=0){
            for(int i=0;i<m;i++){
                vetor[i] = va[l][i];
            }
        }
        return vetor;
    }


//	Retornar Um vetor com os elementos da coluna “p” da matriz
//  int * colunadaMatriz(int *va, int n, int m, int p)

    int *colunadaMatriz(int n,int m, int *va, int p){//RETORNA A COLUNA K
        int *vetorcoluna = (int*)malloc(sizeof(int)*n);
        if(va!=NULL && p<m&& p>=0 && (vetorcoluna != NULL)){
            for(int i=0;i<n;i++){
                vetorcoluna[i] = va[i][p];
            }
        }
        return vetorcoluna;
    }



//  vi.	Retornar Um vetor com os elementos da diagonal principal da matriz
//  int * diagonaldaMatriz(int *va, int n, int m)
    int *diagonaldaMatriz(int n,int m, int *va){
        numdiagonais = n;
        if(numdiagonais>m){
            numdiagonais=m;
        }
        int *vetordiagonais = (int*)malloc(sizeof(int)*numdiagonais);
        if(vetordiagonais != NULL){
            int s=0;            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i==j){
                        vetordiagonais[s]=va[i][j];
                        s++;

                    }
                }
            }
        }
        return vetordiagonais;
    }



    return 0;
}
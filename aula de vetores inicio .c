#include<stdio.h>
int main(){
    //  vetor é  um um conjunto de variavel do mesmo tipo 
    // sintaxe TIPO_DO_VETOR NOME_DO_VETOR [QUANTIDADE DE POSIÇOES];
    int vetor [5]={1,2,3,4,5};
    float vetor1[2];
    char vetor2[3]={'a','A','N'};
    // acesar o vetor começa a contar do 0 no caso um vetor c/ 3 fica 0,1,2;

 int numero [5]={23,44,55,12,-5};
 //para alterar o valor de uma posição do vetor 
numero[2]=67;
 //printf("%d",numero[2]);
 printf("digite um numero\n");
 scanf("%d",&numero[2]);
  printf("posição2 %d",numero[2]);
    
    return 0;
}

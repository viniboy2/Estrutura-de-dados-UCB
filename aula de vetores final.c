#include<stdio.h>
#include<stdlib.h>
int main(){
int numero[5];
for(int i=0;i<5;i++){
    printf("digite o numero\n");
    scanf("%d",&numero[i]);
}
for(int i=0; i<5; i++){

    printf("posicao %d o numero e %d\n",i,numero[i]);
}

    return 0;
}
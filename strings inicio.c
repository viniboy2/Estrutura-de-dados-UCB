#include<stdio.h>
#include<stdlib.h>
int main (){
  //como iremos fazer isso char_nome_da__string[quantidade de posiçoes]="frase que vc quer colocar";
  char teste [100];//{'c','a','v','a','l','o'}
   //sempre colocar um espaço de sobra pois ele sempre vai ser utilizado pelo /0 e isso pode ser manipulado 
   //para auxiliar
   scanf("%s",teste);// esse scanf tem um problema no primeiro espaço ele para de ler 
   printf("%s\n",teste);
 
  return 0;
}
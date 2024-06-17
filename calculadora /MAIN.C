
#include <stdio.h>
#include <string.h>
#include "calculadora.h"
#define TAMANHO_MAXIMO 100
#define OPERADORES "+-*/^"
void testarExpressao(char *posFix) {

Expressao expr;
strcpy(expr.posFixa, posFix);
expr.Valor = getValor(expr.posFixa);
strcpy(expr.inFixa, getFormaInFixa(expr.posFixa));
printf("Expressao PosFixa: %s\n", expr.posFixa);
printf("Expressao Infixa: %s\n", expr.inFixa);
printf("Valor: %.2f\n\n", expr.Valor);
}
int main() {
char *testes[] = {
"3 4 + 5 *",
"7 2 * 4 +",
"8 5 2 4 + * +",
"6 2 / 3 + 4 *",
"9 5 2 8 * 4 + * +",
"2 3 + log 5 /",
"10 log 3 ^ 2 +",
"45 60 + 30 cos *",
"0.5 45 sen 2 ^ +"
};
int numeroDeTestes = sizeof(testes) / sizeof(testes[0]);
for (int i = 0; i < numeroDeTestes; i++) {
testarExpressao(testes[i]);
}
return 0;
}
int main() {
char posFixa[] = "53 23 + 8 2 - *";
// Convertendo para a forma infixa
char *inFixa = getFormaInFixa(posFixa);
// Calculando o valor da expressão
float valor = getValor(posFixa);
return 0;
}

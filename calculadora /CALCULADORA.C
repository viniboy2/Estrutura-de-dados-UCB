#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include "calculadora.h"

#define MAXIMO_TAMANHO 512
#define OPERADORES "+-*/^"

typedef struct {
    int topo;
    char *items[MAXIMO_TAMANHO];
} Pilha;

void InicializacaoPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int pilhaCheia(Pilha *pilha) {
    return pilha->topo == MAXIMO_TAMANHO - 1;
}
// Função para empilhar elementoos na pilha
void empilhar(Pilha *pilha, char *objeto) {
    if (pilhaCheia(pilha)) {
        printf("A Pilha está cheia\n");
        exit(1);
    }
    pilha->items[++(pilha->topo)] = strdup(objeto);
}

// Função para desempilharr elementoos da pilha
char *desempilhar(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha está vazia.\n");
        exit(1);
    }
    return pilha->items[(pilha->topo)--];
}
bool Validar_Operador(char operador) {
    return strchr(OPERADORES, operador) != NULL;
}
bool Validar_Funcao(char *funcao) {
    return (strcmp(funcao, "sen") == 0 || strcmp(funcao, "cos") == 0 ||strcmp(funcao, "tan") == 0 || strcmp(funcao, "log") == 0);
}
// Função para avaliar uma expressão pós-fixa
float validarPosfixa(char *expressao) {
    Pilha pilha;
    InicializacaoPilha(&pilha);
    char *token = strtok(expressao, " "); // Dividir a expressão em tokens separadianoos por espaço

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // Se o token for um número, empilhá-lo
            empilhar(&pilha, token);
        } else if (Validar_Operador(token[0]) && strlen(token) == 1){
            // Se o token for um operador
            float operador2 = atof(desempilhar(&pilha));
            float operador1 = atof(desempilhar(&pilha));
            float resultado;

            switch (token[0]) {
                case '+':
                    resultado = operador1 + operador2;
                    break;
                case '-':
                    resultado = operador1 - operador2;
                    break;
                case '*':
                    resultado = operador1 * operador2;
                    break;
                case '/':
                    resultado = operador1 / operador2;
                    break;
                case '^':
                    resultado = powf(operador1, operador2);
                    break;
                
                default:
                     resultado = 0.0;
                     break;
            }
            char resultadoDaString[32];
            snprintf(resultadoDaString, sizeof(resultadoDaString), "%f", resultado);
            empilhar(&pilha, resultadoDaString);
        } else if (Validar_Funcao(token)) {
            float valor = atof(desempilhar(&pilha));
            float resultado;
            float radiano = valor * (3.141592 / 180);
            if (strcmp(token, "sen") == 0) {
                resultado = sinf(radiano);
            } else if (strcmp(token, "cos") == 0) {
                resultado = cosf(radiano);
            } else if (strcmp(token, "tan") == 0) {
                resultado = tanf(radiano);
            } else if (strcmp(token, "log") == 0) {
                resultado = log10f(valor);
            } else {
                resultado = 0.0;
            }
            char resultadoDaString[32];
            snprintf(resultadoDaString, sizeof(resultadoDaString), "%f", resultado);
            empilhar(&pilha, resultadoDaString);
        }
        token = strtok(NULL, " ");
    }
    return atof(desempilhar(&pilha));
}

// Função para obter a forma in-fixa de uma expressão
char *getFormaInFixa(char *Str) {
    static char infixa[512];
    Pilha pilha;
    InicializacaoPilha(&pilha);

    char *token = strtok(Str, " ");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            empilhar(&pilha, token);
        } else if (Validar_Operador(token[0]) && strlen(token) == 1) {
            char *valor2 = desempilhar(&pilha);
            char *valor1 = desempilhar(&pilha);
            char expr[512];
            snprintf(expr, sizeof(expr), "(%s %c %s)", valor1, token[0], valor2);
            empilhar(&pilha, expr);
            free(valor1);
            free(valor2);
        } else if (Validar_Funcao(token)) {
            char *valor1 = desempilhar(&pilha);
            char expr[512];
            snprintf(expr, sizeof(expr), "%s(%s)", token, valor1);
            empilhar(&pilha, expr);
            free(valor1);
        }
        token = strtok(NULL, " ");
    }
    strcpy(infixa, desempilhar(&pilha));
    return infixa;
}

// Função para calcular o valor de uma expressão pós-fixa
float getValor(char *Str) {
    char posfixada[512];
    strcpy(posfixada, Str);  
    return validarPosfixa(posfixada);
}



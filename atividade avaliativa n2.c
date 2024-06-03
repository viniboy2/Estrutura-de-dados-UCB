#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cidades.h"

// Função para inicializar a estrutura Estrada a partir do arquivo
Estrada *getEstrada(const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        return NULL;
    }

    Estrada *estrada = (Estrada *)malloc(sizeof(Estrada));
    if (!estrada) {
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d", &estrada->T);
    fscanf(file, "%d", &estrada->N);

    if (estrada->T < 3 || estrada->T > 1000000 || estrada->N < 2 || estrada->N > 10000) {
        fclose(file);
        free(estrada);
        return NULL;
    }

    estrada->C = (Cidade *)malloc(estrada->N * sizeof(Cidade));
    if (!estrada->C) {
        fclose(file);
        free(estrada);
        return NULL;
    }

    for (int i = 0; i < estrada->N; i++) {
        fscanf(file, "%d", &estrada->C[i].Posicao);
        fscanf(file, "%s", estrada->C[i].Nome);
        if (estrada->C[i].Posicao <= 0 || estrada->C[i].Posicao >= estrada->T) {
            fclose(file);
            free(estrada->C);
            free(estrada);
            return NULL;
        }
    }

    fclose(file);
    return estrada;
}

// Função para calcular a menor vizinhança entre as cidades
double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) {
        return -1.0;
    }

    double menorVizinhanca = (double)estrada->T;

    for (int i = 0; i < estrada->N; i++) {
        double vizinhancaAtual;
        if (i == 0) {
            vizinhancaAtual = (estrada->C[i + 1].Posicao - estrada->C[i].Posicao) / 2.0;
        } else if (i == estrada->N - 1) {
            vizinhancaAtual = (estrada->C[i].Posicao - estrada->C[i - 1].Posicao) / 2.0;
        } else {
            vizinhancaAtual = (estrada->C[i + 1].Posicao - estrada->C[i - 1].Posicao) / 2.0;
        }
        if (vizinhancaAtual < menorVizinhanca) {
            menorVizinhanca = vizinhancaAtual;
        }
    }

    free(estrada->C);
    free(estrada);
    return menorVizinhanca;
}

// Função para retornar o nome da cidade com a menor vizinhança
char *cidadeMenorVizinhanca(const char *nomeArquivo) {
    Estrada *estrada = getEstrada(nomeArquivo);
    if (!estrada) {
        return NULL;
    }

    double menorVizinhanca = (double)estrada->T;
    char *cidade = NULL;

    for (int i = 0; i < estrada->N; i++) {
        double vizinhancaAtual;
        if (i == 0) {
            vizinhancaAtual = (estrada->C[i + 1].Posicao - estrada->C[i].Posicao) / 2.0;
        } else if (i == estrada->N - 1) {
            vizinhancaAtual = (estrada->C[i].Posicao - estrada->C[i - 1].Posicao) / 2.0;
        } else {
            vizinhancaAtual = (estrada->C[i + 1].Posicao - estrada->C[i - 1].Posicao) / 2.0;
        }
        if (vizinhancaAtual < menorVizinhanca) {
            menorVizinhanca = vizinhancaAtual;
            cidade = estrada->C[i].Nome;
        }
    }

    char *resultado = (char *)malloc(256 * sizeof(char));
    if (cidade) {
        strcpy(resultado, cidade);
    }

    free(estrada->C);
    free(estrada);
    return resultado;
}

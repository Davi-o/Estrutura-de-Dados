#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

void exibirDadosAluno(struct Aluno aluno);
void calcularMedia(struct Aluno *aluno);
void gerarConceito(struct Aluno *aluno);

void main(){
    struct Aluno aluno;
    int ra;
    double nota;
    char nome[50];
    char disciplina[50];

    printf("RA: ");
    scanf("%d", &ra);
    fflush(stdin);
    printf("\nNome: ");
    scanf("%s", &nome);
    fflush(stdin);
    printf("\nDisciplina: ");
    scanf("%s", &disciplina);
    fflush(stdin);

    // TODO resolver esta leitura
    for (int i = 0; i < sizeof(aluno.notas)/sizeof(aluno.notas[0]); ++i) {
        printf("Nota %d: ", i+1);
        scanf("%Le", &nota);
        aluno.notas[i] = nota;
        nota = 0;
    }

    aluno.registroDeAluno = ra;

    strcpy(aluno.nome, nome);
    strcpy(aluno.disciplina, disciplina);

    calcularMedia(&aluno);
    gerarConceito(&aluno);
    exibirDadosAluno(aluno);

}

void exibirDadosAluno(struct Aluno aluno){
    printf("\nRa: %d", aluno.registroDeAluno);
    printf("\nNome: %s ", aluno.nome);
    printf("\nDisciplina: %s ", aluno.disciplina);
    printf("\nNotas: N1 = %d, N2 = %d, N3 = %d ", aluno.notas[0],aluno.notas[1], aluno.notas[2]);
    printf("\nMedia: %f ", aluno.media);
    printf("\nConceito: %c ", aluno.conceito);
}

void calcularMedia(struct Aluno *aluno){
    double total = 0;
    int numeroDeNotas = 0;

    while (numeroDeNotas < sizeof(aluno->notas)/sizeof(aluno->notas[0])) {
        total += aluno->notas[numeroDeNotas];
        numeroDeNotas++;
    }

    aluno->media = total/numeroDeNotas;
}

void gerarConceito(struct Aluno *aluno){
    if(aluno->media < 6.5){
        aluno->conceito = 'C';
    }

    if(aluno->media < 8.5){
        aluno->conceito ='B';
    }
    
    aluno->conceito = 'A';
}
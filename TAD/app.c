#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

void main(){
    struct Aluno aluno;
    
    aluno.registroDeAluno = 123;
    strcpy(aluno.nome, "Jonathan");
    strcpy(aluno.disciplina, "Matematica");
    aluno.notas[0] = 8;
    aluno.notas[1] = 8;
    aluno.notas[2] = 10;

    calcularMedia(&aluno);
    gerarConceito(&aluno);
    exibirDadosAluno(aluno);

}

void exibirDadosAluno(struct Aluno aluno){
    printf("Ra: %d", aluno.registroDeAluno);
    printf("\nNome: %s ", aluno.nome);
    printf("\nDisciplina: %s ", aluno.disciplina);
    printf("\nNotas: N1 = %d, N2 = %d, N3 = %d ", aluno.notas[0],aluno.notas[1], aluno.notas[2]);
    printf("\nMedia: %f ", aluno.media);
    printf("\nConceito: %c ", aluno.conceito);
};

void calcularMedia(struct Aluno *aluno){
    double total = 0;
    int numeroDeNotas = 0;

    while (numeroDeNotas < sizeof(aluno->notas)/sizeof(aluno->notas[0])) {
        total += aluno->notas[numeroDeNotas];
        numeroDeNotas++;
    }

    aluno->media = total/numeroDeNotas;
};

void gerarConceito(struct Aluno *aluno){
    if(aluno->media < 6.5){
        aluno->conceito = 'C';
    }

    if(aluno->media < 8.5){
        aluno->conceito ='B';
    }
    
    aluno->conceito = 'A';
}
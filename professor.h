//
// Created by joaooctf on 22/02/19.
//

#ifndef PARADIGMAS_PROFESSOR_H
#define PARADIGMAS_PROFESSOR_H

//Struct de um Professor
typedef struct {
    char nome[100];
    int ra;
    int vinculado;
} Professor;

//Struct Lista de Professor
typedef struct {
    Professor professor;
    struct ProfessorList *next;
} ProfessorList;

// Cria Lista de professoress
void criarListaDeProfessores(ProfessorList **pList);

// Insere um professor no final na lista de professoress
void inserirProfessor(ProfessorList *list, Professor professor);

// Retorna uma struct de um professor populada
Professor populateProfessor(char *nome, int ra);

// Printa todos os professoress da lista de professoress
void printarProfessores(ProfessorList *list);

// Pede um professor e o insere na lista de professoress
void cadastrarProfessor(ProfessorList *list);

void printaProfessor(ProfessorList *list, int ra);

Professor *buscaProfessor(ProfessorList *professor, int raProfessor);

#endif //PARADIGMAS_PROFESSOR_H

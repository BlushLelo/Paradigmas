//
// Created by joaooctf on 22/02/19.
//

#ifndef PARADIGMAS_PROFESSOR_H
#define PARADIGMAS_PROFESSOR_H

//Struct de um Professor
typedef struct {
    char *nome;
    int ra;
} Professor;

//Struct Lista de Professor
typedef struct {
    Professor professor;
    struct AlunoList *next;
} ProfessorList;

// Cria Lista de professoress
void criarListaDeProfessores(ProfessorList **pList);

// Insere um professor no final na lista de professoress
void inserirProfessor(ProfessorList *list, Professor professor);

// Retorna uma struct de um professor populada
Professor populateProfessor(char *nome, int ra);

// Printa todos os professoress da lista de professoress
void printaProfessores(ProfessorList *list);

// Pede um professor e o insere na lista de professoress
void cadastrarProfessor(ProfessorList *list);

void printaProfessor(ProfessorList *list, int ra);

#endif //PARADIGMAS_PROFESSOR_H

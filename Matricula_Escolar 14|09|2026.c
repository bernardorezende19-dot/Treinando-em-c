#include <stdio.h>

typedef struct{
    int matricula;
    char nome[50];
    float nota;
}Aluno;
int main()
{
    Aluno aluno;
    printf("Digite a matricula:");
    scanf("%d",&aluno.matricula);
    printf("Digite o nome:");
    scanf(" %49[^\n]", aluno.nome);
    printf("Digite a nota:");
    scanf("%f", &aluno.nota);
    printf("\n=== DADOS DO ALUNO ===\n");
    printf("Matricula: %\n",aluno.matricula);
    printf("Nome:%s\n", aluno.nome);
    printf("Nota: %.2f\n", aluno.nota);

    return 0;
}

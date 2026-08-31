#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[50];
    float nota;
} Aluno;

// Cadastrar aluno no arquivo
void cadastrarAluno() {
    FILE *arquivo;
    Aluno aluno;

    arquivo = fopen("alunos.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    printf("\nDigite a matricula: ");
    scanf("%d", &aluno.matricula);
    getchar();

    printf("Digite o nome: ");
    scanf("%[^\n]", aluno.nome);

    printf("Digite a nota: ");
    scanf("%f", &aluno.nota);

    fprintf(arquivo, "%d;%s;%.2f\n",
            aluno.matricula,
            aluno.nome,
            aluno.nota);

    fclose(arquivo);

    printf("\nAluno cadastrado com sucesso!\n");
}

// Listar alunos
void listarAlunos() {
    FILE *arquivo;
    Aluno aluno;

    arquivo = fopen("alunos.txt", "r");

    if (arquivo == NULL) {
        printf("\nArquivo ainda nao existe!\n");
        return;
    }

    printf("\n===== LISTA DE ALUNOS =====\n");

    while (fscanf(arquivo, "%d;%49[^;];%f\n",
                  &aluno.matricula,
                  aluno.nome,
                  &aluno.nota) == 3) {

        printf("\nMatricula: %d\n", aluno.matricula);
        printf("Nome: %s\n", aluno.nome);
        printf("Nota: %.2f\n", aluno.nota);
        printf("------------------\n");
    }

    fclose(arquivo);
}

// Pesquisar aluno
void pesquisarAluno() {
    FILE *arquivo;
    Aluno aluno;
    int matriculaPesquisa;
    int encontrado = 0;

    arquivo = fopen("alunos.txt", "r");

    if (arquivo == NULL) {
        printf("\nArquivo ainda nao existe!\n");
        return;
    }

    printf("\nDigite a matricula que deseja pesquisar: ");
    scanf("%d", &matriculaPesquisa);

    while (fscanf(arquivo, "%d;%49[^;];%f\n",
                  &aluno.matricula,
                  aluno.nome,
                  &aluno.nota) == 3) {

        if (aluno.matricula == matriculaPesquisa) {
            printf("\nAluno encontrado!\n");
            printf("Matricula: %d\n", aluno.matricula);
            printf("Nome: %s\n", aluno.nome);
            printf("Nota: %.2f\n", aluno.nota);

            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("\nAluno nao encontrado!\n");
    }

    fclose(arquivo);
}

int main() {
    int opcao;

    do {
        printf("\n==================================");
        printf("\n       SISTEMA DE ALUNOS");
        printf("\n==================================");
        printf("\n1 - Cadastro aluno");
        printf("\n2 - Listar alunos");
        printf("\n3 - Pesquisar aluno");
        printf("\n0 - Sair");
        printf("\n\nEscolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;

            case 2:
                listarAlunos();
                break;

            case 3:
                pesquisarAluno();
                break;

            case 0:
                printf("\nPrograma encerrado!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

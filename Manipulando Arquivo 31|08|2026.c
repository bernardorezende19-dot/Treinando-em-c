#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char texto[200];
    int opcao;

    do {
        printf("\n=======================\n");
        printf("    MENU DO ARQUIVO\n");
        printf("=======================\n");
        printf("1 - Escrever novo conteudo\n");
        printf("2 - Visualizar conteudo\n");
        printf("3 - Alterar todo o conteudo\n");
        printf("4 - Adicionar nova linha\n");
        printf("0 - Sair\n");
        printf("=======================\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        getchar();

        switch (opcao) {

            case 1:
                arquivo = fopen("mensagem.txt", "w");

                if (arquivo == NULL) {
                    printf("\nErro ao criar o arquivo!\n");
                    break;
                }

                printf("\nDigite o conteudo: ");
                fgets(texto, sizeof(texto), stdin);

                fprintf(arquivo, "%s", texto);
                fclose(arquivo);

                printf("\nArquivo salvo com sucesso!\n");
                printf("Arquivo: mensagem.txt\n");
                printf("Local: mesma pasta onde o programa esta sendo executado.\n");

                break;

            case 2:
                arquivo = fopen("mensagem.txt", "r");

                if (arquivo == NULL) {
                    printf("\nArquivo ainda nao existe!\n");
                    break;
                }

                printf("\n----- CONTEUDO DO ARQUIVO -----\n\n");

                while (fgets(texto, sizeof(texto), arquivo) != NULL) {
                    printf("%s", texto);
                }

                fclose(arquivo);

                printf("\n-------------------------------\n");

                break;

            case 3:
                arquivo = fopen("mensagem.txt", "w");

                if (arquivo == NULL) {
                    printf("\nErro ao abrir o arquivo!\n");
                    break;
                }

                printf("\nDigite o novo conteudo: ");
                fgets(texto, sizeof(texto), stdin);

                fprintf(arquivo, "%s", texto);

                fclose(arquivo);

                printf("\nConteudo alterado com sucesso!\n");
                printf("Arquivo salvo: mensagem.txt\n");

                break;

            case 4:
                arquivo = fopen("mensagem.txt", "a");

                if (arquivo == NULL) {
                    printf("\nErro ao abrir o arquivo!\n");
                    break;
                }

                printf("\nDigite a nova mensagem: ");
                fgets(texto, sizeof(texto), stdin);

                fprintf(arquivo, "%s", texto);

                fclose(arquivo);

                printf("\nNova linha adicionada com sucesso!\n");

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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    int numeroSecreto;
    int palpite;
    int tentativas = 0;
    int pontos = 100;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Gera um número secreto entre 1 e 100
    numeroSecreto = rand() % 100 + 1;

    printf("===============================================\n");
    printf("        GAME DE ADIVINHAÇÃO\n");
    printf("===============================================\n");

    printf("Estou pensando em um número entre 1 e 100.\n");
    printf("Tente adivinhar qual é!\n\n");

    do{
        printf("Digite o seu palpite: ");
        scanf("%d", &palpite);

        tentativas++;

        if(palpite < numeroSecreto) {
            printf("Muinto baixo! Tente um número maior.\n");
            pontos -= 10;
        }
        else if(palpite > numeroSecreto) {
            printf("Muito alto! Tente um número menor.\n");
            pontos -= 10;
        }
        else {
            printf("\n===============================================\n");
            printf("PARABÉNS!VOCÊ ACERTOU!\n");
            printf("=================================================\n");

            printf("Número secreto:%d\n", numeroSecreto);
            printf("Tentativas:%d\n", tentativas);

            if(pontos < 0) {
                pontos = 0;
            }
            printf("Pontuação: %d pontos\n", pontos);
        }

        printf("\n");
    }while(palpite != numeroSecreto);

    return 0;
}
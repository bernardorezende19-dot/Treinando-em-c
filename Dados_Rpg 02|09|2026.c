#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int d4;
    int d6;
    int d8;
    int d10;
    int d12;
    int d20;
    int d100;

    int quantidade;
    int bonus;
    int opcao;
    int soma;

    srand(time(NULL));

    do{

        printf("===============================================\n");
        printf("              GIRADA INSANA\n");
        printf("===============================================\n");
        printf("1 - d4\n");
        printf("2 - d6\n");
        printf("3 - d8\n");
        printf("4 - d10\n");
        printf("5 - d12\n");
        printf("6 - d20\n");
        printf("7 - d100\n");
        printf("0 - Sair\n");
        printf("=======================\n");

        printf("Escolha qual dado vc quer girar: ");
        scanf("%d", &opcao);

        if(opcao == 0){
            printf("Saindo do programa...\n");
            break;
        }

        printf("Quantos vc quer girar: ");
        scanf("%d", &quantidade);

        if(quantidade <= 0){
            printf("Quantidade invalida!\n");
            continue;
        }

        printf("Qual o bonus: ");
        scanf("%d", &bonus);

        soma = 0;

        switch(opcao){

            case 1:

                for(int i = 0; i < quantidade; i++){

                    d4 = rand() % 4 + 1;

                    printf("d4: %d\n", d4);

                    soma += d4;
                }

                break;


            case 2:

                for(int i = 0; i < quantidade; i++){

                    d6 = rand() % 6 + 1;

                    printf("d6: %d\n", d6);

                    soma += d6;
                }

                break;


            case 3:

                for(int i = 0; i < quantidade; i++){

                    d8 = rand() % 8 + 1;

                    printf("d8: %d\n", d8);

                    soma += d8;
                }

                break;


            case 4:

                for(int i = 0; i < quantidade; i++){

                    d10 = rand() % 10 + 1;

                    printf("d10: %d\n", d10);

                    soma += d10;
                }

                break;


            case 5:

                for(int i = 0; i < quantidade; i++){

                    d12 = rand() % 12 + 1;

                    printf("d12: %d\n", d12);

                    soma += d12;
                }

                break;


            case 6:

                for(int i = 0; i < quantidade; i++){

                    d20 = rand() % 20 + 1;

                    printf("d20: %d\n", d20);

                    soma += d20;
                }

                break;


            case 7:

                for(int i = 0; i < quantidade; i++){

                    d100 = rand() % 100 + 1;

                    printf("d100: %d\n", d100);

                    soma += d100;
                }

                break;


            default:

                printf("Opcao invalida!\n");
                continue;
        }

        soma += bonus;

        printf("\n=======================\n");
        printf("Soma dos dados: %d\n", soma - bonus);
        printf("Bonus: %d\n", bonus);
        printf("Resultado final: %d\n", soma);
        printf("=======================\n");

    }while(opcao != 0);

    return 0;
}

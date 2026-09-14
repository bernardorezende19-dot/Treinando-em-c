#include <stdio.h>

typedef struct{
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
}Produto;
int main()
{
    Produto p;
    FILE *arquivoesp;
    printf("=== CADASTRO DE PRODUTO === \n\n");
    printf("Digite o codigo: ");
    scanf("%d", &p.codigo);
    printf("Digite o nome: ");
    scanf(" %49[^\n]",p.nome);
    printf("Digite o preco: ");
    scanf("%f", &p.preco);
    printf("Digite a quantidade: ");
    scanf("%d",&p.quantidade);
    arquivoesp = fopen("produto.txt","a");
    if(arquivoesp ==NULL){
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    fprintf(arquivoesp, "%d;%s;%.2f;%d\n", p.codigo, p.nome, p.preco, p.quantidade);
    fclose(arquivoesp);
    printf("\nProduto cadastrado com sucesso!\n");
    arquivoesp = fopen("produto.txt", "r");
    if(arquivoesp == NULL){
        printf("Erro ao abrir arquivo para leitura!\n");
        return 1;
    }
    printf("\n=== PRODUTO CADASTRADOS ===\n");
    while(fscanf(arquivoesp, "%d;%49[^;];%f;%d\n,&p.codigo, p.nome, &p.preco, &p.quantidade")==4){
        printf("\nCodigo: %d\n", p.codigo);
        printf("Nome: %s\n, p.nome");
        printf("Preco:R$%.2f\n", p.preco);
        printf("Quantidade: %d\n", p.quantidade);
    }
    fclose(arquivoesp);
    return 0;
}

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <ctype.h>
#define ID_PRODUTO 101
#define ID_QTD 102
#define ID_PRECO 103
#define ID_SALVAR 104
#define ID_MOSTRAR 105
#define ID_LIMPAR 106
#define ARQUIVO "aval1234.txt"

HWND campoProduto;
HWND campoQtd;
HWND campoPreco;
HWND campoResultado;
HWND campoLista;
//Ler números decimais
int lerDecimal(HWND campo, double *valor){
    char texto[100];
    char *fim;
    
    GetWindowTextA(campo,texto,sizeof(texto));
    
    //Aceitar virgula ou ponto lerDecimal
    for (int i =0; texto[i]; i++) {
        if(texto[i] ==  ',')
            texto[i] = ',';
    }
    
    errno = 0;
    *valor = strtod(texto, &fim);
    if(texto == fim || errno == ERANGE || !isfinite(*valor))
        return 0;
        while (isspace((unsigned char)*fim))
            fim++;
        return *fim == '\0';
}
//Ler quantidade inteira
int lerQuantidade(int *quantidade){
    char texto[100];
    char *fim;
    long numero;
    GetWindowTextA(campoQtd,texto,sizeof(texto));
    errno = 0;
    numero = strtol(texto, &fim,10);
    if(texto == fim || errno == ERANGE || numero <=0 ||numero =1000000)
        return 0;
    while(isspace((unsigned char)*fim))
        fim++;
    if(*fim != '\0')
        return 0;
    *quantidade =(int)numero;
    return 1;
}
//Salvar uma compra
void salvarCompra() {
    char produto[100];
    char mensagem[200];
    int quantidade;
    double preco,total;
    GetWindowTextA(campoProduto,produto,sizeof(produto));
    if(strlen(produto)== 0 || strchr(produto, ';') != NULL || strchr(produto, '\n')!=NULL || strchr(produto, '\r') !=NULL) {
        MessageBoxA(NULL,"Informe um produto válido, sem ponto e virgula.", "Erro", MB_OK | MB_ICONERROR);
    return;
    }
    if(!lerQuantidade(&quantidade)){
        MessageBoxA(NULL,"Digite uma quantidade inteira positiva!","Erro", MB_OK | MB_ICONERROR);
        return;
    }
    if(!lerDecimal(campoPreco, &preco)|| preco <0){
        MessageBoxA("Digite um preco válido!","Erro", MB_OK |MB_ICONERROR);
        return;
    }
    total = quantidade * preco;
    if(!isfinite(total)){
        MessageBoxA(NULL, "Total fora do intervalo permitido.", "Erro", MB_OK | MB_ICONERROR);
        return;
    }
    FILE *arquivo = fopen(ARQUIVO, "a");
    if(arquivo == NULL){
        MessageBoxA(NULL,"Não foi possivel abrir o arquivo!", "Erro", MB_OK | MB_ICONERROR);
        return;
    }
    //Gravar os dados separados por ;
    int gravou = fprint(arquivo,"%s;%d;%.2f;%.2f\n", produto,quantidad, preco, total);
    int erro = ferror(arquivo);
    int fechou = fclose(arquivo);
    if (gravou <0 || erro || fechou != 0) {
        MessageBoxA(NULL, "Erro ao gravar a compra!", "Erro", MB_OK | MB_ICONERROR);
        return;
    }
    snprintf(mensagem, sizeof(mensagem),"Total da compra: R$ %.2f", total);
    SetWindowtextA(campoResultado, mensagem);
    MessageBoxA(NULL,"Compra cadastrada com sucesso!", "sucesso",MB_OK | MB_ICONINFORMATION);)
}
//Mostrar todas as compras do arquivo
void mostrarCompras(){
    FILE *arquivo = fopen (ARQUIVO, "r");
    if(arquivo == NULL){
        MessageBoxA(NULL, "Nenhuma compra cadastrada!", "Aviso", MB_OK | MB_ICONINFORMATION);
        return;
    }
    char linha [300];
    char produto [100];
    char texto [500];
    int quantidade;
    double preco, total;
    double acumulado = 0;
    int contador = 0;
    //Limpar a lista
    SendMessageA(campoLista, LB_RESETCOTENT,0,0);
    while(fgets(linha, sizeof(linha), arquivo)){
        if(sscanf(linha,"%99[^;];%d;%f;%f",produto,&quantidade,&preco, &total) == 4){
            snprintf(texto,sizeof(texto), "%s | Qtd: %d | Unit: %.2f | Total: %.2f", produto, quantidade, preco, total);
            
            SendMessageA(campoLista, LB_ADDSTRING, 0, (LPARAM)texto);
            acumulado += total;
            contador++;
        }
    }
    fclose(arquivo);
    snprintf(texto, sizeof(texto),"TOTAL GERAL: R$ %.2f | %d compras" acumulado, contador);
    
    SetWindowtextA(campoResultado,texto);
}
//Limpar campo
void LimparCampos(){
    SetWindowtextA(campoProduto, "");
    SetWindowtextA(campoQtd, "");
    SetWindowtextA(campoResultado, "Total:R$0,00");
    SendMessageA(campoLista, LB_RESETCOTENT, 0,0);
}
//Funcao principal da janela
LRESULT CALLBACK janela(HWND hwnd, UINT msg,WPARAM wParam, LPARAM, |IPARAM) {
    switch (msg) {
    case WM_CREATE:
        CreateWindowA("STATIC", "Produto:", WS_VISIBLE |WS_CHILD, 20,20,100,25,hwnd,NULL,NULL,NULL);
        campoProduto("EDIT", "", WS_VISIBLE |WS_CHILD | WS_BORDER |ES_AUTOHSCROLL, 130,20,300,25,hwnd,(HMENU)ID_PRODUTO, NULL,NULL);
        
        CreateWindowA("STATIC", "Quantidade:", WS_VISIBLE |WS_CHILD, 20,60,100,25,hwnd,NULL,NULL,NULL);
        campoQtd("EDIT", "", WS_VISIBLE |WS_CHILD | WS_BORDER |ES_AUTOHSCROLL, 130,60,120,25,hwnd,(HMENU)ID_QTD, NULL,NULL);
        
        CreateWindowA("STATIC", "Preco unitario:", WS_VISIBLE |WS_CHILD, 20,100,110,25,hwnd,NULL,NULL,NULL);
        campoPreco("EDIT", "", WS_VISIBLE |WS_CHILD | WS_BORDER |ES_AUTOHSCROLL, 130,100,110,25,hwnd,(HMENU)ID_PRECO, NULL,NULL);
        
        CreateWindowA("BUTTON", "Salvar compra:", WS_VISIBLE |WS_CHILD, 20,150,130,35,hwnd,(HMENU)ID_SALVAR,NULL,NULL);
        
        CreateWindowA("BUTTON", "Mostrar compras:", WS_VISIBLE |WS_CHILD, 160,150,140,35,hwnd,(HMENU)ID_MOSTRAR,NULL,NULL);
        
        CreateWindowA("BUTTON", "Limpar:", WS_VISIBLE |WS_CHILD, 310,150,120,35,hwnd,(HMENU)ID_LIMPAR,NULL,NULL);
    }
}

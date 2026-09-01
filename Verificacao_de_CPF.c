#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarCPF(char cpf[]){
    int numeros[11];
    int j = 0;
    
    //Extrai apenas os números do CPF 
    for(int i = 0; cpf[i] != '\0'; i++){
        if (isdigit(cpf[i])){
            numeros[j] = cpf[i] - '0';
            j++;
        }
    }
    //CPF precisa ter 11 números
    if (j!=11){
        return 0;
    }
    //Verificar se todos os números são iguais
    int todosIguais =1;
    
    for (int i =1; i < 11; i++){
        if (numeros[i] != numeros [0]) {
            todosIguais = 0;
            break;
        } 
    }
    if(todosIguais){
        return 0;
    }
    //----------------------------
    //Calcule o primeiro dígito
    //----------------------------
    int soma = 0;
    int peso = 10;
    
    for (int i =0; i <9;i++){
        soma += numeros [i] * peso;
        peso--;
    }
    
    int resto =soma %11;
    int digito1;
    
    if(resto < 2){
    digito1 = 0;
    }else {
        digito1 = 11 - resto;
    }
    
    //Verifica primeiro dígito
    if (digito1 != numeros[9]){
        return 0;
    }
    
    //----------------------------
    //Calcule o segundo dígito
    //----------------------------
    soma = 0;
    peso = 11;
    
    for (int i =0;i < 10; i++){
        soma += numeros[i] * peso;
        peso--;
    }
    
    resto = soma %11;
    
    int digito2;
    
    if (resto<2) {
        digito2 = 0;
    }else {
        digito2 = 11 - resto;
    }
    
    //verificar o segundo dígito 
    if (digito2 != numeros[10]){
        return 0;
    }
    
    return 1;
}

int main() {
    char cpf [20];
    
    printf("=== VALIDADOR DE CPF ===|n\n");
    
    printf("Digite o CPF:");
    fgets(cpf,sizeof(cpf),stdin);
    
    if (validarCPF(cpf)){
        printf("\nCPF VALIDO!\n");
    }else{
        printf("\nCPF INVALIDO!\n");
    }
    
    return 0;
}

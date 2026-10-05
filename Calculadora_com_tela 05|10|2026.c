#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Identificadores dos campos */
#define ID_NUMERO1 101
#define ID_NUMERO2 102

/* Identificadores dos botoes */
#define ID_SOMAR 201
#define ID_SUBTRAIR 202
#define ID_MULTIPLICAR 203
#define ID_DIVIDIR 204
#define ID_LIMPAR 205
#define ID_SAIR 206

/* Campos da interface */
HWND campoNumero1;
HWND campoNumero2;

/* FUNCAO PARA LIMPAR OS CAMPOS */
void limparCampos() {
    SetWindowText(campoNumero1, "");
    SetWindowText(campoNumero2, "");
    SetFocus(campoNumero1);
}

/* FUNCAO PARA SOMAR */
void somar(HWND janela) {
    char texto1[30], texto2[30], mensagem[100];
    float numero1, numero2, resultado;

    /* Pegando os valores digitados */
    GetWindowText(campoNumero1, texto1, sizeof(texto1));
    GetWindowText(campoNumero2, texto2, sizeof(texto2));

    /* Verificando campos vazios */
    if (strlen(texto1) == 0 || strlen(texto2) == 0) {
        MessageBox(janela, "Preencha os dois numeros!", "Aviso",
        MB_OK | MB_ICONWARNING);
        return;
    }

    /* Convertendo texto para numero */
    numero1 = atof(texto1);
    numero2 = atof(texto2);

    /* Realizando a soma */
    resultado = numero1 + numero2;

    /* Exibindo o resultado */
    sprintf(mensagem, "Resultado: %.2f", resultado);
    MessageBox(janela, mensagem, "Soma", MB_OK |
    MB_ICONINFORMATION);
}

/* FUNCAO PARA SUBTRAIR */
void subtrair(HWND janela) {
    char texto1[30], texto2[30], mensagem[100];
    float numero1, numero2, resultado;

    /* Pegando os valores digitados */
    GetWindowText(campoNumero1, texto1, sizeof(texto1));
    GetWindowText(campoNumero2, texto2, sizeof(texto2));

    /* Verificando campos vazios */
    if (strlen(texto1) == 0 || strlen(texto2) == 0) {
        MessageBox(janela, "Preencha os dois numeros!", "Aviso",
        MB_OK | MB_ICONWARNING);
        return;
    }

    /* Convertendo texto para numero */
    numero1 = atof(texto1);
    numero2 = atof(texto2);

    /* Realizando a subtracao */
    resultado = numero1 - numero2;

    /* Exibindo o resultado */
    sprintf(mensagem, "Resultado: %.2f", resultado);
    MessageBox(janela, mensagem, "Subtracao", MB_OK |
    MB_ICONINFORMATION);
}

/* FUNCAO PARA MULTIPLICAR */
void multiplicar(HWND janela) {
    char texto1[30], texto2[30], mensagem[100];
    float numero1, numero2, resultado;

    /* Pegando os valores digitados */
    GetWindowText(campoNumero1, texto1, sizeof(texto1));
    GetWindowText(campoNumero2, texto2, sizeof(texto2));

    /* Verificando campos vazios */
    if (strlen(texto1) == 0 || strlen(texto2) == 0) {
        MessageBox(janela, "Preencha os dois numeros!", "Aviso",
        MB_OK | MB_ICONWARNING);
        return;
    }

    /* Convertendo texto para numero */
    numero1 = atof(texto1);
    numero2 = atof(texto2);

    /* Realizando a multiplicacao */
    resultado = numero1 * numero2;

    /* Exibindo o resultado */
    sprintf(mensagem, "Resultado: %.2f", resultado);
    MessageBox(janela, mensagem, "Multiplicacao", MB_OK |
    MB_ICONINFORMATION);
}

/* FUNCAO PARA DIVIDIR */
void dividir(HWND janela) {
    char texto1[30], texto2[30], mensagem[100];
    float numero1, numero2, resultado;

    /* Pegando os valores digitados */
    GetWindowText(campoNumero1, texto1, sizeof(texto1));
    GetWindowText(campoNumero2, texto2, sizeof(texto2));

    /* Verificando campos vazios */
    if (strlen(texto1) == 0 || strlen(texto2) == 0) {
        MessageBox(janela, "Preencha os dois numeros!", "Aviso",
        MB_OK | MB_ICONWARNING);
        return;
    }

    /* Convertendo texto para numero */
    numero1 = atof(texto1);
    numero2 = atof(texto2);

    /* Verificando divisao por zero */
    if (numero2 == 0) {
        MessageBox(janela, "Nao e possivel dividir por zero!",
        "Erro", MB_OK | MB_ICONERROR);
        return;
    }

    /* Realizando a divisao */
    resultado = numero1 / numero2;

    /* Exibindo o resultado */
    sprintf(mensagem, "Resultado: %.2f", resultado);

    MessageBox(janela, mensagem, "Divisao", MB_OK |
    MB_ICONINFORMATION);
}
/* FUNÇÃO QUE CONTROLA A JANELA */
LRESULT CALLBACK WindowProcedure(HWND janela, UINT
mensagem, WPARAM wParam, LPARAM lParam)
{
    switch (mensagem)
    {
        case WM_CREATE:

            CreateWindow("STATIC", "CALCULADORA", WS_VISIBLE |
            WS_CHILD, 115, 20, 200, 30, janela, NULL, NULL, NULL);

            CreateWindow("STATIC", "Numero 1", WS_VISIBLE |
            WS_CHILD, 30, 70, 100, 25, janela, NULL, NULL, NULL);

            campoNumero1 = CreateWindow("EDIT", "", WS_VISIBLE |
            WS_CHILD | WS_BORDER | ES_NUMBER, 130, 70, 220, 25,
            janela, (HMENU) ID_NUMERO1, NULL, NULL);

            CreateWindow("STATIC", "Numero 2", WS_VISIBLE |
            WS_CHILD, 30, 110, 100, 25, janela, NULL, NULL, NULL);

            campoNumero2 = CreateWindow("EDIT", "", WS_VISIBLE |
            WS_CHILD | WS_BORDER | ES_NUMBER, 130, 110, 220, 25,
            janela, (HMENU) ID_NUMERO2, NULL, NULL);

            /* BOTÕES DAS OPERAÇÕES */

            CreateWindow("BUTTON", "Somar", WS_VISIBLE |
            WS_CHILD | BS_PUSHBUTTON, 30, 165, 90, 35, janela,
            (HMENU) ID_SOMAR, NULL, NULL);

            CreateWindow("BUTTON", "Subtrair", WS_VISIBLE |
            WS_CHILD | BS_PUSHBUTTON, 130, 165, 90, 35, janela,
            (HMENU) ID_SUBTRAIR, NULL, NULL);

            CreateWindow("BUTTON", "Multiplicar", WS_VISIBLE |
            WS_CHILD | BS_PUSHBUTTON, 230, 165, 90, 35, janela,
            (HMENU) ID_MULTIPLICAR, NULL, NULL);

            CreateWindow("BUTTON", "Dividir", WS_VISIBLE |
            WS_CHILD | BS_PUSHBUTTON, 330, 165, 90, 35, janela,
            (HMENU) ID_DIVIDIR, NULL, NULL);

            CreateWindow("BUTTON", "Limpar", WS_VISIBLE |
            WS_CHILD | BS_PUSHBUTTON, 110, 220, 100, 35, janela,
            (HMENU) ID_LIMPAR, NULL, NULL);

            CreateWindow("BUTTON", "Sair", WS_VISIBLE |
            WS_CHILD | BS_PUSHBUTTON, 230, 220, 100, 35, janela,
            (HMENU) ID_SAIR, NULL, NULL);

            break;


        /* EVENTOS DOS BOTOES */

        case WM_COMMAND:

            switch (LOWORD(wParam))
            {
                case ID_SOMAR:
                    somar(janela);
                    break;

                case ID_SUBTRAIR:
                    subtrair(janela);
                    break;

                case ID_MULTIPLICAR:
                    multiplicar(janela);
                    break;

                case ID_DIVIDIR:
                    dividir(janela);
                    break;

                case ID_LIMPAR:
                    limparCampos();
                    break;

                case ID_SAIR:
                    DestroyWindow(janela);
                    break;
            }

            break;


        /* FECHAR JANELA */

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(janela, mensagem,
            wParam, lParam);
    }

    return 0;
}


/* FUNÇÃO PRINCIPAL */

int WINAPI WinMain(HINSTANCE hInstancia,
HINSTANCE hInstanciaAnterior, LPSTR argumentos,
int exibirJanela)
{
    WNDCLASS wc = {0};

    /* Configurando a janela */

    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstancia;
    wc.lpszClassName = "Calculadora";
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);


    /* Registrando a janela */

    if (!RegisterClass(&wc))
    {
        MessageBox(NULL, "Erro ao registrar a janela!",
        "Erro", MB_OK);
        return 0;
    }


    /* Criando a janela principal */

    HWND janela = CreateWindow(
        "Calculadora",
        "Calculadora",
        WS_OVERLAPPED | WS_CAPTION |
        WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 470, 350,
        NULL, NULL, hInstancia, NULL
    );


    if (janela == NULL)
    {
        MessageBox(NULL, "Erro ao criar a janela!",
        "Erro", MB_OK);
        return 0;
    }


    /* Exibindo a janela */

    ShowWindow(janela, exibirJanela);
    UpdateWindow(janela);


    /* Loop principal */

    MSG mensagem;

    while (GetMessage(&mensagem, NULL, 0, 0))
    {
        TranslateMessage(&mensagem);
        DispatchMessage(&mensagem);
    }

    return 0;
}

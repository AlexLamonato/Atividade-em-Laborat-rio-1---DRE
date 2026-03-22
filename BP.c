#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

typedef struct{
    char N[36];
    float Valor;
    int T;
}Dados;

int Maior_0(int V);
void Titulo1();
void Titulo2();
void Titulo3();
void Circulante(int X, Dados B[X]);
void Nao_Circulante(int X, Dados B[X]);

// NOVO
void Mostrar_DRE(int R, Dados Receita[R], int D, Dados Despesa[D]);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int QA, QP, QV, QR, QD;
    int i, j;

    float SA = 0, SP = 0, Soma_PL = 0;

    // =========================
    // BALANÇO PATRIMONIAL
    // =========================

    do
    {
        printf("=======================\n");
        printf("  BALANCO PATRIMONIAL\n");
        printf("=======================\n\n");

        printf("- Quantidade de ativos: ");
        scanf("%d", &QA);

        printf("- Quantidade de passivos: ");
        scanf("%d", &QP);

        printf("- Quantidade de PL: ");
        scanf("%d", &QV);

    }while((QA < 1) || (QP < 1) || (QV < 1));

    Dados A[QA], P[QP], PL[QV];

    system("cls");

    Titulo1();

    for(i = 0; i < QA; i++)
    {
        printf("Nome: ");
        scanf(" %[^\n]s", A[i].N);

        printf("Valor(R$): ");
        scanf("%f", &A[i].Valor);

        printf("Tipo (1 circulante / 2 nao): ");
        scanf("%d", &A[i].T);

        SA += A[i].Valor;
        system("cls");
    }

    Titulo2();

    for(i = 0; i < QP; i++)
    {
        printf("Nome: ");
        scanf(" %[^\n]s", P[i].N);

        printf("Valor(R$): ");
        scanf("%f", &P[i].Valor);

        printf("Tipo (1 circulante / 2 nao): ");
        scanf("%d", &P[i].T);

        SP += P[i].Valor;
    }

    Titulo3();

    for(i = 0; i < QV; i++)
    {
        printf("Nome: ");
        scanf(" %[^\n]s", PL[i].N);

        printf("Valor(R$): ");
        scanf("%f", &PL[i].Valor);

        Soma_PL += PL[i].Valor;
    }

    system("cls");

    printf("=========== RESULTADO BP ===========\n\n");

    printf("Total Ativos: %.2f\n", SA);
    printf("Total Passivos: %.2f\n", SP);
    printf("Total PL: %.2f\n", Soma_PL);

    printf("\nBP = %.2f\n\n", SA - (SP + Soma_PL));

    // =========================
    // DRE
    // =========================

    printf("=========== DRE ===========\n\n");

    printf("- Quantidade de receitas: ");
    scanf("%d", &QR);

    printf("- Quantidade de despesas: ");
    scanf("%d", &QD);

    Dados Receita[QR], Despesa[QD];

    system("cls");

    printf("=== RECEITAS ===\n");

    for(i = 0; i < QR; i++)
    {
        printf("Nome: ");
        scanf(" %[^\n]s", Receita[i].N);

        printf("Valor: ");
        scanf("%f", &Receita[i].Valor);
    }

    printf("\n=== DESPESAS ===\n");

    for(i = 0; i < QD; i++)
    {
        printf("Nome: ");
        scanf(" %[^\n]s", Despesa[i].N);

        printf("Valor: ");
        scanf("%f", &Despesa[i].Valor);
    }

    system("cls");

    Mostrar_DRE(QR, Receita, QD, Despesa);

    return 0;
}

// =========================
// FUNÇÕES
// =========================

void Mostrar_DRE(int R, Dados Receita[R], int D, Dados Despesa[D])
{
    int i;
    float SR = 0, SD = 0;

    printf("=======================\n");
    printf("          DRE          \n");
    printf("=======================\n\n");

    printf("Receitas:\n");
    for(i = 0; i < R; i++)
    {
        printf("- %s: %.2f\n", Receita[i].N, Receita[i].Valor);
        SR += Receita[i].Valor;
    }

    printf("\nTotal receitas: %.2f\n\n", SR);

    printf("Despesas:\n");
    for(i = 0; i < D; i++)
    {
        printf("- %s: %.2f\n", Despesa[i].N, Despesa[i].Valor);
        SD += Despesa[i].Valor;
    }

    printf("\nTotal despesas: %.2f\n\n", SD);

    float Resultado = SR - SD;

    printf("-----------------------\n");
    printf("Resultado: %.2f\n", Resultado);

    if(Resultado > 0)
        printf("Lucro\n");
    else if(Resultado < 0)
        printf("Prejuizo\n");
    else
        printf("Empate\n");

    printf("-----------------------\n");
}

int Maior_0(int V)
{
    if(V < 1)
        return 0;
    return 1;
}

void Titulo1()
{
    printf("=== ATIVOS ===\n\n");
}

void Titulo2()
{
    printf("=== PASSIVOS ===\n\n");
}

void Titulo3()
{
    printf("=== PATRIMONIO LIQUIDO ===\n\n");
}

void Circulante(int X, Dados B[X])
{
    int i;
    for(i = 0; i < X; i++)
        if(B[i].T == 1)
            printf("- %s: %.2f\n", B[i].N, B[i].Valor);
}

void Nao_Circulante(int X, Dados B[X])
{
    int i;
    for(i = 0; i < X; i++)
        if(B[i].T == 2)
            printf("- %s: %.2f\n", B[i].N, B[i].Valor);
}
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

typedef struct
{
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

int main()
{
   setlocale(LC_ALL, "Portuguese");

   int QA, QP, QV, i, j;
   float SA = 0, SP = 0, Soma_Patrimonio_Liquido = 0;

   do
   {
     printf("=======================\n");
     printf("  BALANÇO PATRIMONIAL  : Ativos e Passivos\n");
     printf("=======================\n\n");

     printf("- Quantidade de ativos: ");
     scanf("%d", &QA);

     if(Maior_0(QA) == 1)
     {
       printf("- Quantidade de passivos: ");
       scanf("%d", &QP);

       if(Maior_0(QP) == 1)
       {
         printf("- Quantidade de valores do PL: ");
         scanf("%d", &QV);

         Maior_0(QV);
       }
     }
   }while((QA < 1) || (QP < 1) || (QV < 1));

   Dados A[QA], P[QP], Patrimonio_liquido[QV];

   system("cls");

   Titulo1();

   for(i = 0; i < QA; i++)
   {
      printf("Nome: ");
      scanf(" %[^\n]s", A[i].N);
      printf("Valor(R$): ");
      scanf("%f", &A[i].Valor);

      if(A[i].Valor <= 0)
      {
        printf("\n*Por favor, insira um valor maior que 0*\n\n\n");

        system("pause");
        system("cls");

        Titulo1();

        if(i > 0)
        {

          for(j = 0; j < i; j++)
          {
             printf("Nome: %s\n", A[j].N);
             printf("Valor(R$): %.2f\n", A[j].Valor);
             printf("Tipo (1 -> circulante / 2 -> não circulante): %d\n\n", A[j].T);
          }
        }

        i--;
      }
      else
      {
        printf("Tipo (1 -> circulante / 2 -> não circulante): ");
        scanf("%d", &A[i].T);
        printf("\n");

        if((A[i].T != 1) && (A[i].T != 2))
        {
          printf("*Está opção não existe, por favor escolha novamente*\n\n\n");

          system("pause");
          system("cls");

          Titulo1();

          if(i > 0)
          {

            for(j = 0; j < i; j++)
            {
               printf("Nome: %s\n", A[j].N);
               printf("Valor(R$): %.2f\n", A[j].Valor);
               printf("Tipo (1 -> circulante / 2 -> não circulante): %d\n\n", A[j].T);
            }
          }

          i--;
        }
        else
        {
          SA = SA + A[i].Valor;
        }
      }
   }

   system("cls");

   Titulo2();

   for(i = 0; i < QP; i++)
   {
      printf("Nome: ");
      scanf(" %[^\n]s", P[i].N);
      printf("Valor(R$): ");
      scanf("%f", &P[i].Valor);

      if(P[i].Valor <= 0)
      {
        printf("\n*Por favor, insira um valor maior que 0*\n\n\n");

        system("pause");
        system("cls");

        Titulo2();

        if(i > 0)
        {

          for(j = 0; j < i; j++)
          {
             printf("Nome: %s\n", P[j].N);
             printf("Valor(R$): %.2f\n", P[j].Valor);
             printf("Tipo (1 -> circulante / 2 -> não circulante): %d\n\n", P[j].T);
          }
        }

        i--;
      }
      else
      {
        printf("Tipo (1 -> circulante / 2 -> não circulante): ");
        scanf("%d", &P[i].T);
        printf("\n");

        if((P[i].T != 1) && (P[i].T != 2))
        {
          printf("*Está opção não existe, por favor escolha novamente*\n\n\n");

          system("pause");
          system("cls");

          Titulo2();

          if(i > 0)
          {

            for(j = 0; j < i; j++)
            {
               printf("Nome: %s\n", P[j].N);
               printf("Valor(R$): %.2f\n", P[j].Valor);
               printf("Tipo (1 -> circulante / 2 -> não circulante): %d\n\n", P[j].T);
            }
          }

          i--;
        }
        else
        {
          SP = SP + P[i].Valor;
        }
      }
   }

   system("cls");

   Titulo3();

   for(i = 0; i < QV; i++)
   {
      printf("Nome: ");
      scanf(" %[^\n]s", Patrimonio_liquido[i].N);
      printf("Valor(R$): ");
      scanf("%f", &Patrimonio_liquido[i].Valor);

      if(Patrimonio_liquido[i].Valor <= 0)
      {
        printf("\n*Por favor, insira um valor maior que 0*\n\n\n");

        system("pause");
        system("cls");

        Titulo3();

        if(i > 0)
        {

          for(j = 0; j < i; j++)
          {
             printf("Nome: %s\n", Patrimonio_liquido[j].N);
             printf("Valor(R$): %.2f\n\n", Patrimonio_liquido[j].Valor);
          }
        }

        i--;
      }
      else
      {
        Soma_Patrimonio_Liquido = Soma_Patrimonio_Liquido + Patrimonio_liquido[i].Valor;

        printf("\n");
      }
   }

   system("cls");

   printf("=======================\n");
   printf("  BALANÇO PATRIMONIAL  : Resultados\n");
   printf("=======================\n\n");

   printf("-------------------------------\n");
   printf("*ATIVOS*\n");
   printf("-------------------------------\n");
   printf("Circulantes:\n");

   Circulante(QA, A);

   printf("\nNão circulantes:\n");

   Nao_Circulante(QA, A);

   printf("\nTotal: %.2f\n", SA);

   printf("-------------------------------\n");

   printf("-------------------------------\n");
   printf("*PASSIVOS + PL*\n");
   printf("-------------------------------\n");
   printf("Passivos circulantes:\n");

   Circulante(QP, P);

   printf("\nPassivos não circulantes:\n");

   Nao_Circulante(QP, P);

   printf("\nPatrimônio líquido:\n");

   for(i = 0; i < QV; i++)
   {
      printf("- %s: %.2f\n", Patrimonio_liquido[i].N, Patrimonio_liquido[i].Valor);
   }

   printf("\nTotal passivos: %.2f\n", SP);
   printf("\nTotal PL: %.2f\n", Soma_Patrimonio_Liquido);
   printf("\nPassivos + PL: %.2f\n", SP + Soma_Patrimonio_Liquido);
   printf("-------------------------------\n");
   printf("\nBP = %.2f\n\n", SA - (SP + Soma_Patrimonio_Liquido));
   printf("-------------------------------\n");

   return 0;
}

int Maior_0(int V)
{
    if(V < 1)
    {
      printf("\n*Por favor, insira um valor maior que 0*\n\n\n");

      system("pause");
      system("cls");

      return 0;
    }

    return 1;
}

void Titulo1()
{
    printf("=======================\n");
    printf("  BALANÇO PATRIMONIAL  : Dados dos ativos\n");
    printf("=======================\n\n");
}

void Titulo2()
{
    printf("=======================\n");
    printf("  BALANÇO PATRIMONIAL  : Dados dos passivos\n");
    printf("=======================\n\n");
}

void Titulo3()
{
    printf("=======================\n");
    printf("  BALANÇO PATRIMONIAL  : Dados do patrimônio líquido\n");
    printf("=======================\n\n");
}

void Circulante(int X, Dados B[X])
{
    int i;

    for(i = 0; i < X; i++)
    {
       if(B[i].T == 1)
       {
         printf("- %s: %.2f\n", B[i].N, B[i].Valor);
       }
    }
}

void Nao_Circulante(int X, Dados B[X])
{
    int i;

    for(i = 0; i < X; i++)
    {
       if(B[i].T == 2)
       {
         printf("- %s: %.2f\n", B[i].N, B[i].Valor);
       }
    }
}

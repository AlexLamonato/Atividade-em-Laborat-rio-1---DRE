#include <stdio.h>
#include <locale.h>

int main() {
    // Configura acentuação para Português
    setlocale(LC_ALL, "Portuguese");

    float rob, vendas_canc, descontos, rol, cmv, lucro_bruto;
    float desp_vendas, desp_adm, lucro_op, desp_fin, lucro_antes_ir, ir, total;

    printf("--- Input de Dados para DRE ---\n");

    // Loop para entrada de dados (11 etapas do processo)
    for (int i = 1; i <= 11; i++) {
        switch (i) {
            case 1: printf("Receita Operacional Bruta: "); scanf("%f", &rob); break;
            case 2: printf("\t(-) Vendas Canceladas: "); scanf("%f", &vendas_canc); break;
            case 3: printf("\t(-) Descontos: "); scanf("%f", &descontos); break;
            case 4: printf("(=) Receita Operacional Líquida: %f\n", rol=(rob - (vendas_canc + descontos)) ); break;
            case 5: printf("\t(-) CMV: "); scanf("%f", &cmv); break;
            case 6: printf("(=) Lucro Bruto: %f\n", lucro_bruto=( rol - cmv) ); break;
            case 7: printf("\t(-) Despesas de Vendas: "); scanf("%f", &desp_vendas); break;
            case 8: printf("\t(-) Despesas Administrativas: "); scanf("%f", &desp_adm); break;
            case 9: printf("(=) Lucro Operacional: %f\n", lucro_op=(lucro_bruto - (desp_vendas + desp_adm))); break;
            case 10: printf("\t(-) Despesas Financeiras: "); scanf("%f", &desp_fin); break;
            case 11: printf("\t(-) IR: "); scanf("%f", &ir); break;
        }
    }

    // Cálculos intermediários (conforme a lógica da imagem)
    lucro_antes_ir = lucro_op - desp_fin;
    total = lucro_antes_ir - ir;

    // Exibição formatada com \t (Tabulação)
    printf("\n\n========================================\n");
    printf("      RESULTADO FINAL DA DRE\n");
    printf("========================================\n");
    
    printf("(=)Receita Operacional Bruta \t%f\n", rob);
    printf("\t(-)Vendas Canceladas \t%f\n", vendas_canc);
    printf("\t(-)Descontos \t\t%f\n", descontos);
    
    printf("(=)Receita Operacional Liquida \t%f\n", rol);
    printf("\t(-)CMV \t\t\t%f\n", cmv);
    
    printf("(=)Lucro Bruto \t\t\t%f\n", lucro_bruto);
    printf("\t(-)Despesas de Vendas \t%f\n", desp_vendas);
    printf("\t(-)Despesas Administrativas %f\n", desp_adm);
    
    printf("(=)Lucro Operacional \t\t%f\n", lucro_op);
    printf("\t(-)Despesas Financeiras %f\n", desp_fin);
    
    printf("(=)Lucro Liquido antes do IR \t%f\n", lucro_antes_ir);
    printf("\t(-)IR \t\t\t%f\n", ir);
    
    printf("(=)TOTAL \t\t\t%f\n", total);
    printf("----------------------------------------\n");

    return 0;
}
import locale

# Configura a localidade para formatar números e acentos (opcional)
try:
    locale.setlocale(locale.LC_ALL, 'pt_BR.UTF-8')
except:
    pass

def executar_dre():
    opcao = 1
    while opcao == 1:
        print("--- Input de Dados para DRE ---")

        # Inicialização das variáveis
        rob = vendas_canc = descontos = rol = cmv = 0.0
        lucro_bruto = desp_vendas = desp_adm = lucro_op = 0.0
        desp_fin = ir = 0.0

        # Loop para entrada de dados (11 etapas do processo)
        for i in range(1, 12):
            if i == 1:
                rob = float(input("Receita Operacional Bruta: "))
            elif i == 2:
                vendas_canc = float(input("\t(-) Vendas Canceladas: "))
            elif i == 3:
                descontos = float(input("\t(-) Descontos: "))
            elif i == 4:
                rol = rob - (vendas_canc + descontos)
                print(f"(=) Receita Operacional Líquida: {rol:f}")
            elif i == 5:
                cmv = float(input("\t(-) CMV: "))
            elif i == 6:
                lucro_bruto = rol - cmv
                print(f"(=) Lucro Bruto: {lucro_bruto:f}")
            elif i == 7:
                desp_vendas = float(input("\t(-) Despesas de Vendas: "))
            elif i == 8:
                desp_adm = float(input("\t(-) Despesas Administrativas: "))
            elif i == 9:
                lucro_op = lucro_bruto - (desp_vendas + desp_adm)
                print(f"(=) Lucro Operacional: {lucro_op:f}")
            elif i == 10:
                desp_fin = float(input("\t(-) Despesas Financeiras: "))
            elif i == 11:
                ir = float(input("\t(-) IR: "))

        # Cálculos finais
        lucro_antes_ir = lucro_op - desp_fin
        total = lucro_antes_ir - ir

        # Exibição formatada
        print("\n\n========================================")
        print("      RESULTADO FINAL DA DRE")
        print("========================================")

        print(f"(=)Receita Operacional Bruta \t{rob:f}")
        print(f"\t(-)Vendas Canceladas \t{vendas_canc:f}")
        print(f"\t(-)Descontos \t\t{descontos:f}")

        print(f"(=)Receita Operacional Liquida \t{rol:f}")
        print(f"\t(-)CMV \t\t\t{cmv:f}")

        print(f"(=)Lucro Bruto \t\t\t{lucro_bruto:f}")
        print(f"\t(-)Despesas de Vendas \t{desp_vendas:f}")
        print(f"\t(-)Despesas Administrativas \t{desp_adm:f}")

        print(f"(=)Lucro Operacional \t\t{lucro_op:f}")
        print(f"\t(-)Despesas Financeiras \t{desp_fin:f}")

        print(f"(=)Lucro Liquido antes do IR \t{lucro_antes_ir:f}")
        print(f"\t(-)IR \t\t\t\t{ir:f}")

        print(f"(=)TOTAL \t\t\t{total:f}")
        print("----------------------------------------")
        opcao = int(input("Deseja realizar o processo novamente? (1 = s / 0 = n ): "))
        
if __name__ == "__main__":
    executar_dre()
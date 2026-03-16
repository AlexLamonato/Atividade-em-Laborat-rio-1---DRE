import os
from time import sleep

def limpar_tela():
    os.system('cls' if os.name == 'nt' else 'clear')

def obter_float(prompt):
    while True:
        try:
            v = float(input(prompt))
            if v < 0: raise ValueError
            return v
        except ValueError:
            print("Entrada inválida! Digite um número positivo.")

def coletar_dados(titulo, categorias=True):
    itens = []
    limpar_tela()
    print(f"--- {titulo} ---")
    qtd = int(obter_float(f"Quantidade de itens para {titulo}: "))
    
    # Mapeamento para os índices
    print("\nTags especiais: [1]Estoque [2]Contas a Receber [3]Disponibilidade [4]Fornecedores [0]Nenhum")
    
    for i in range(qtd):
        nome = input(f"\nNome do item {i+1}: ")
        valor = obter_float(f"Valor (R$): ")
        tipo = int(obter_float("Tipo (1-Circulante, 2-Não Circulante): ")) if categorias else 0
        tag = int(obter_float("Tag especial (0-4): "))
        itens.append({'nome': nome, 'valor': valor, 'tipo': tipo, 'tag': tag})
    return itens

def executar_dre():
    d = {}
    print("\n" + "="*20)
    print("   PASSO 1: DRE")
    print("="*20)
    
    # Receitas
    d['rob'] = obter_float("Receita Bruta (Vendas + Serviços): ")
    d['desc'] = obter_float("(-) Desconto sobre Vendas/Abatimentos: ")
    d['rol'] = d['rob'] - d['desc']
    print(f"  > Receita Líquida: R$ {d['rol']:.2f}")

    # Custos (Separados conforme solicitado)
    d['cmv'] = obter_float("(-) CMV (Custo de Mercadorias Vendidas): ")
    d['csp'] = obter_float("(-) CSP (Custo de Serviços Prestados): ")
    d['lucro_bruto'] = d['rol'] - (d['cmv'] + d['csp'])
    print(f"  > Lucro Bruto: R$ {d['lucro_bruto']:.2f}")

    # Despesas e Outros Resultados
    d['desp_op'] = obter_float("(-) Despesas Operacionais (Adm/Vendas/Salários): ")
    d['lucro_op'] = d['lucro_bruto'] - d['desp_op']
    print(f"  > Lucro Operacional: R$ {d['lucro_op']:.2f}")

    d['res_fin'] = obter_float("(+) Resultado Financeiro Líquido: ")
    d['outras_rec'] = obter_float("(+) Outras Receitas (Ex: Venda Imobilizado): ")
    
    # Cálculo Final
    d['lucro_liquido'] = d['lucro_op'] + d['res_fin'] + d['outras_rec']
    
    # Dado necessário para o cálculo do PMP (Prazo Médio de Pagamento)
    d['compras'] = obter_float("Total de Compras de Estoque no período: ")
    
    print("\n" + "-"*30)
    print(f"LUCRO LÍQUIDO FINAL: R$ {d['lucro_liquido']:.2f}")
    print("-"*30)
    
    return d

def calcular_indicadores(dre, ativos, passivos, pl_total):
    # Extração de valores pelas Tags
    extrair = lambda lista, tag: sum(item['valor'] for item in lista if item.get('tag') == tag)
    
    estoque = extrair(ativos, 1)
    receber = extrair(ativos, 2)
    disponiv = extrair(ativos, 3)
    forneced = extrair(passivos, 4)
    
    ac = sum(i['valor'] for i in ativos if i['tipo'] == 1)
    pc = sum(i['valor'] for i in passivos if i['tipo'] == 1)
    at = sum(i['valor'] for i in ativos)
    pt = sum(i['valor'] for i in passivos)

    # Dicionário de resultados
    res = {}
    try:
        # Liquidez
        res['ILC'] = ac / pc
        res['ILS'] = (ac - estoque) / pc
        res['ILI'] = disponiv / pc
        # Atividade (Ano 360 dias)
        res['Giro Estoque'] = dre['cmv'] / estoque if estoque > 0 else 0
        res['PMR'] = (receber * 360) / dre['rol']
        res['PMP'] = (forneced * 360) / dre['compras']
        res['Giro Ativo'] = dre['rol'] / at
        # Endividamento e Rentabilidade
        res['Endiv. Geral'] = (pt / at) * 100
        res['M. Bruta'] = (dre['lucro_bruto'] / dre['rol']) * 100
        res['M. Operacional'] = (dre['lucro_op'] / dre['rol']) * 100
        res['M. Líquida'] = (dre['lucro_liquido'] / dre['rol']) * 100
    except ZeroDivisionError:
        pass
    return res

def main():
    dados_dre = executar_dre()
    input("\nDRE Concluída. Pressione Enter para o Balanço...")
    
    ativos = coletar_dados("ATIVOS")
    passivos = coletar_dados("PASSIVOS")
    
    itens_pl = coletar_dados("PATRIMÔNIO LÍQUIDO", categorias=False)
    # --- CORREÇÃO AQUI: Somar os valores das listas ---
    total_ativos = sum(item['valor'] for item in ativos)
    total_passivos = sum(item['valor'] for item in passivos)
    pl_total = sum(item['valor'] for item in itens_pl) + dados_dre['lucro_liquido']
    
    # Agora o cálculo funciona pois estamos usando os totais numéricos
    diferenca = total_ativos - (total_passivos + pl_total)
    print("\n", 45*'=')
    print("BALANÇO PATRIMONIAL")
    print(45*'=')
    print(f"Total Ativos: R$ {total_ativos:.2f}")
    print(f"Total Passivo + PL: R$ {total_passivos + pl_total:.2f}")
    print(f"Diferença Balanço: R$ {diferenca:.2f}")
    if (diferenca > 0): print("Ativos maior que passivos.")
    if (diferenca < 0): print("Passivos maior que ativos.")
    if (diferenca == 0): print("Balanço patrimonial equilibrado.")
    input("\nBP Concluído. Pressione Enter para o Indicadores...")

    ind = calcular_indicadores(dados_dre, ativos, passivos, pl_total)
    
    limpar_tela()
    print("="*45)
    print(f"{'RELATÓRIO DE INDICADORES':^45}")
    print("="*45)
    
    secoes = {
        "LIQUIDEZ": ["ILC", "ILS", "ILI"],
        "ATIVIDADE": ["Giro Estoque", "PMR", "PMP", "Giro Ativo"],
        "RENTABILIDADE": ["M. Bruta", "M. Operacional", "M. Líquida", "Endiv. Geral"]
    }

    for secao, chaves in secoes.items():
        print(f"\n> {secao}")
        for c in chaves:
            sufixo = "%" if "%" in c or "M." in c or "Endiv" in c else ""
            print(f"  {c:<18}: {ind.get(c, 0):>10.2f}{sufixo}")
    
    print("\n" + "="*45)

if __name__ == "__main__":
    main()
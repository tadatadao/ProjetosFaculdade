#Marcos Tadao Shoji RA:2374200
#AT02
import struct
import sys

# Tamanho fixo dos campos no registro
TAM_TITULO = 50
TAM_PRODUTORA = 40
TAM_GENERO = 25
TAM_PLATAFORMA = 15
TAM_ANO = 4
TAM_CLASSIFICACAO = 12
TAM_PRECO = 7
TAM_TIPO_MIDIA = 8
TAM_TAMANHO = 7

# Estrutura do registro
REGISTRO_FORMATO = f'!{TAM_TITULO}s{TAM_PRODUTORA}s{TAM_GENERO}s{TAM_PLATAFORMA}s{TAM_ANO}s{TAM_CLASSIFICACAO}s{TAM_PRECO}s{TAM_TIPO_MIDIA}s{TAM_TAMANHO}s'

# Tamanho do cabeçalho
TAM_CABECALHO = 6

def adicionaRegistro(arq, game):
    """
    Adiciona um novo registro ao arquivo.
    """
    # Converte o game para a representação binária
    registro_binario = struct.pack(REGISTRO_FORMATO, *game)

    # Move o cursor para o final do arquivo
    arq.seek(0, 2)

    # Escreve o registro no arquivo
    arq.write(registro_binario)

def procuraRegistro(arq, chave):
    """
    Procura um registro no arquivo com base na chave canônica (título + ano).
    Retorna None se não encontrar.
    """
    arq.seek(TAM_CABECALHO)

    while True:
        registro_binario = arq.read(struct.calcsize(REGISTRO_FORMATO))

        if not registro_binario:
            break

        # Desempacota o registro
        registro = struct.unpack(REGISTRO_FORMATO, registro_binario)

        # Gera a chave canônica para comparação
        chave_registro = registro[0].decode().strip() + registro[4].decode().strip()

        if chave == chave_registro:
            return registro

    return None

def removeRegistro(arq, chave):
    """
    Remove um registro do arquivo com base na chave canônica (título + ano).
    Marca o registro como removido (*).
    """
    arq.seek(TAM_CABECALHO)

    while True:
        posicao_atual = arq.tell()
        registro_binario = arq.read(struct.calcsize(REGISTRO_FORMATO))

        if not registro_binario:
            break

        registro = struct.unpack(REGISTRO_FORMATO, registro_binario)
        chave_registro = registro[0].decode().strip() + registro[4].decode().strip()

        if chave == chave_registro:
            arq.seek(posicao_atual)
            arq.write(b'*' + registro_binario[1:])
            break

def storageCompaction(arq):
    """
    Compacta o arquivo removendo registros marcados como removidos (*).
    Atualiza a Pilha de Disponibilidade (Avail List).
    """
    arq.seek(TAM_CABECALHO)
    novo_arquivo = open("temporario.txt", "wb")  # Use 'wb' para modo binário

    while True:
        posicao_atual = arq.tell()
        registro_binario = arq.read(struct.calcsize(REGISTRO_FORMATO))

        if not registro_binario:
            break

        if registro_binario[0] != b'*':
            novo_arquivo.write(registro_binario)
        else:
            # Atualiza a Pilha de Disponibilidade
            novo_arquivo.write(struct.pack('!I', posicao_atual) + registro_binario[1:])

    # Atualiza o cabeçalho com o novo tamanho
    novo_tamanho = novo_arquivo.tell()
    arq.seek(0)
    arq.write(struct.pack('!I', novo_tamanho))

    # Fecha os arquivos
    novo_arquivo.close()

def main():
    if len(sys.argv) != 5:
        print("Uso: python3 nome_do_programa.py [arquivo de entrada] [arquivo de operações] [arquivo de saída temporário] [arquivo de saída final]")
        sys.exit(1)

    # Abre os arquivos e captura possíveis exceções
    try:
        with open(sys.argv[1], 'rb') as arquivo_entrada, open(sys.argv[2], 'r') as arquivo_operacoes, \
             open(sys.argv[3], 'wb') as arquivo_saida_temporario, open(sys.argv[4], 'w') as arquivo_saida_final:
            #fica um errinho aqui nao faco ideia doque fazer mas tentei aplicar logica de tratamento de excessoes por bloco try catch fica aqui o codigo
            # Realize as operações necessárias aqui
            for linha in arquivo_operacoes:
                operacao, *parametros = linha.strip().split()

                if operacao == 'insercao':
                    # Implemente a lógica de inserção
                    _, registro_id, *novo_registro = parametros
                    novo_registro = novo_registro.split('|')  # ajuste conforme o formato real
                    adicionaRegistro(arquivo_saida_temporario, novo_registro)
                elif operacao == 'remocao':
                    # Implemente a lógica de remoção
                    _, chave_remocao = parametros
                    removeRegistro(arquivo_saida_temporario, chave_remocao)
                else:
                    print(f"Operação desconhecida: {operacao}")

            # Executa o storage compaction
            storageCompaction(arquivo_saida_temporario)

            # Copia o conteúdo do arquivo temporário para o arquivo final
            arquivo_saida_final.write(arquivo_saida_temporario.read())

    except FileNotFoundError:
        print("Erro: Arquivo não encontrado.")
        sys.exit(1)

    except IOError:
        print("Erro: Problema na leitura ou escrita dos arquivos.")
        sys.exit(1)

    except Exception as e:
        print(f"Erro desconhecido: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()

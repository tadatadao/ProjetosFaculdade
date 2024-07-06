class Game:
    def __init__(self, nome="", produtora="", genero="", plataforma="", ano="", classificacao="", preco="", midia="", tamanho=""):
        self.nome = nome
        self.produtora = produtora
        self.genero = genero
        self.plataforma = plataforma
        self.ano = ano
        self.classificacao = classificacao
        self.preco = preco
        self.midia = midia
        self.tamanho = tamanho

    def to_string(self):
        return f"{self.nome}:{self.produtora}:{self.genero}:{self.plataforma}:{self.ano}:{self.classificacao}:{self.preco}:{self.midia}:{self.tamanho}"

class Index:
    def __init__(self):
        self.indices = {}

    def adicionar_indice(self, chave, posicao):
        self.indices[chave] = posicao

    def remover_indice(self, chave):
        if chave in self.indices:
            del self.indices[chave]

    def obter_posicao(self, chave):
        return self.indices.get(chave)

def escrever_registro_bytes_tamanho(arquivo, jogo):
    with open(arquivo, 'a') as file:
        posicao = file.tell()
        file.write(f"{len(jogo.to_string())}:{jogo.to_string()}\n")
    return posicao

def ler_registro_bytes_tamanho(arquivo, posicao):
    with open(arquivo, 'r') as file:
        file.seek(posicao)
        linha = file.readline()
        partes = linha.strip().split(':')
        tamanho_nome = int(partes[0])
        nome = partes[1][:tamanho_nome]
        partes = partes[1][tamanho_nome:].split(':')
        tamanho_produtora = int(partes[0])
        produtora = partes[1][:tamanho_produtora]
        # Resto das partes e atribuições de campos aqui...
        genero = partes[2]
        plataforma = partes[3]
        ano = partes[4]
        classificacao = partes[5]
        preco = partes[6]
        midia = partes[7]
        tamanho = partes[8]

        jogo = Game(nome, produtora, genero, plataforma, ano, classificacao, preco, midia, tamanho)
    return jogo

# Exemplo de uso
if __name__ == "__main__":
    arquivo = 'arquivo.txt'
    indice = Index()

    # Exemplo de adição de um registro com chave
    novo_jogo = Game("Novo Jogo", "Produtora", "Gênero", "Plataforma", "Ano", "Classificação", "Preço", "Mídia", "Tamanho")
    posicao = escrever_registro_bytes_tamanho(arquivo, novo_jogo)
    indice.adicionar_indice(novo_jogo.nome, posicao)

    # Exemplo de consulta por chave
    chave = "Novo Jogo"
    posicao = indice.obter_posicao(chave)
    if posicao is not None:
        jogo = ler_registro_bytes_tamanho(arquivo, posicao)
        print(f"Nome: {jogo.nome}, Produtora: {jogo.produtora}")

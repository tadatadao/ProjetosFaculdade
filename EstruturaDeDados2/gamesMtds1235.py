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

    # Métodos getters e setters para cada atributo

    def to_string(self):
        return f"{len(self.nome)}:{self.nome}|{len(self.produtora)}:{self.produtora}|{len(self.genero)}:{self.genero}|{len(self.plataforma)}:{self.plataforma}|{len(self.ano)}:{self.ano}|{len(self.classificacao)}:{self.classificacao}|{len(self.preco)}:{self.preco}|{len(self.midia)}:{self.midia}|{len(self.tamanho)}:{self.tamanho}"

    # Para ler registros do arquivo usando delimitadores:
    @staticmethod
    def ler_registros_delimitadores(arquivo):
        registros = []
        with open(arquivo, 'r') as file:
            for line in file:
                dados = line.strip().split('|')
                jogo = Game(*dados)
                registros.append(jogo)
        return registros

    # Para escrever um registro no arquivo usando delimitadores:
    @staticmethod
    def ler_registros_bytes_tamanho(arquivo):
        registros = []
        with open(arquivo, 'r') as file:
            for line in file:
                partes = line.strip().split(':')
                tamanho_nome = int(partes[0])
                nome = partes[1][:tamanho_nome]
                partes = partes[1][tamanho_nome:].split(':')
                tamanho_produtora = int(partes[0])
                produtora = partes[1][:tamanho_produtora]
                partes = partes[1][tamanho_produtora:].split(':')
                genero = partes[1]
                partes = partes[2].split(':')
                plataforma = partes[1]
                partes = partes[2].split(':')
                ano = partes[1]
                partes = partes[3].split(':')
                classificacao = partes[1]
                partes = partes[4].split(':')
                preco = partes[1]
                partes = partes[5].split(':')
                midia = partes[1]
                partes = partes[6].split(':')
                tamanho = partes[1]
    
                jogo = Game(nome, produtora, genero, plataforma, ano, classificacao, preco, midia, tamanho)
                registros.append(jogo)
        return registros

    # Para escrever um registro no arquivo usando tamanho de bytes:
    @staticmethod
    def escrever_registro_bytes_tamanho(arquivo, jogo):
        with open(arquivo, 'a') as file:
            file.write(jogo.to_string() + '\n')

def main():
    arquivo_delimitadores = 'arquivo_delimitadores.txt'
    arquivo_bytes_tamanho = 'arquivo_bytes_tamanho.txt'

    # Exemplo de uso do método 1: tamanhos fixos de registros
    jogo1 = Game("Nome1", "Produtora1", "Genero1", "Plataforma1", "Ano1", "Classificacao1", "Preco1", "Midia1", "Tamanho1")
    Game.escrever_registro_bytes_tamanho(arquivo_bytes_tamanho, jogo1)
    registros1 = Game.ler_registros_bytes_tamanho(arquivo_bytes_tamanho)
    for jogo in registros1:
        print(jogo.nome, jogo.produtora)  # Exemplo de impressão dos registros

    # Exemplo de uso do método 2: quantidade definida de campos (usando delimitadores)
    jogo2 = Game("Nome2", "Produtora2", "Genero2", "Plataforma2", "Ano2", "Classificacao2", "Preco2", "Midia2", "Tamanho2")
    Game.escrever_registro_delimitadores(arquivo_delimitadores, jogo2)
    registros2 = Game.ler_registros_delimitadores(arquivo_delimitadores)
    for jogo in registros2:
        print(jogo.nome, jogo.produtora)  # Exemplo de impressão dos registros

if __name__ == "__main__":
    main()

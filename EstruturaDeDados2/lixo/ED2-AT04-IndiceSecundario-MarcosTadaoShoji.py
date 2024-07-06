#Marcos Tadao Shoji; RA:2374200
import sys
import os.path

class Music:
    def __init__(self, id, name, album, album_id, artists, artists_ids, track_number, disc_number, explicit,
                 danceability_percent, energy_percent, key, loudness, mode, speechiness_percent,
                 acousticness_percent, instrumentalness_percent, liveness_percent, valence_percent,
                 tempo, duration_ms, time_signature, year, release_date):
        self.id = id
        self.name = name
        self.album = album
        self.album_id = album_id
        self.artists = artists
        self.artists_ids = artists_ids
        self.track_number = track_number
        self.disc_number = disc_number
        self.explicit = explicit
        self.danceability_percent = danceability_percent
        self.energy_percent = energy_percent
        self.key = key
        self.loudness = loudness
        self.mode = mode
        self.speechiness_percent = speechiness_percent
        self.acousticness_percent = acousticness_percent
        self.instrumentalness_percent = instrumentalness_percent
        self.liveness_percent = liveness_percent
        self.valence_percent = valence_percent
        self.tempo = tempo
        self.duration_ms = duration_ms
        self.time_signature = time_signature
        self.year = year
        self.release_date = release_date

# Funcao para criar indices secundarios com base em um campo especifico
def create_secondary_index(data, field):
    secondary_index = {}
    for music in data:
        key = getattr(music, field)
        if key not in secondary_index:
            secondary_index[key] = []
        secondary_index[key].append(music)
    return secondary_index

# Funcao para realizar a busca por um campo especifico em um indice secundario
def search_by_secondary_index(secondary_index, value):
    return secondary_index.get(value, [])

# Funcao para realizar a busca por um campo especifico
def search_by_field(data, field, value):
    return [music for music in data if getattr(music, field) == value]

# Funcao para converter uma string em um objeto Music
def read_string_to_music_object(mystring):
    music = Music()
    mystring = mystring.split(',')

    music.id = mystring[0]
    music.name = mystring[1]
    music.album = mystring[2]
    music.album_id = mystring[3]
    music.artists = mystring[4]
    music.artists_ids = mystring[5]
    music.track_number = int(mystring[6])
    music.disc_number = int(mystring[7])
    music.explicit = mystring[8] == 'True'
    music.danceability_percent = float(mystring[9])
    music.energy_percent = float(mystring[10])
    music.key = int(mystring[11])
    music.loudness = float(mystring[12])
    music.mode = mystring[13]
    music.speechiness_percent = float(mystring[14])
    music.acousticness_percent = float(mystring[15])
    music.instrumentalness_percent = float(mystring[16])
    music.liveness_percent = float(mystring[17])
    music.valence_percent = float(mystring[18])
    music.tempo = int(mystring[19])
    music.duration_ms = int(mystring[20])
    music.time_signature = int(mystring[21])
    music.year = int(mystring[22])
    music.release_date = mystring[23]

    return music

# Funcao para gerar chaves pimarias e RRNs a partir do arquivo de entrada
def generate_primary_keys(inputfile):
    tabelaDeIndices1 = []
    chavesCanonicasPrimarias = []
    rrns = []
    rrn = 0

    for line in inputfile.readlines()[1:]:
        rrn += 1
        registro = line.split(',')
        chaveprimaria = registro[2] + registro[4]
        chaveprimaria = chaveprimaria.upper().replace(' ', '')
        chavesCanonicasPrimarias.append(chaveprimaria)
        rrns.append(rrn)

    tabelaDeIndices1 = list(zip(rrns, chavesCanonicasPrimarias))
    return tabelaDeIndices1

# Funcao para gerar chaves secundarias e RRNs a partir do arquivo de entrada e de ordens
def generate_secondary_keys(primary_keys, ordersfile, inputfile):
    orderedField = ordersfile.readline().strip().upper()
    orderedSecondaryKey = ordersfile.readline().strip().upper()

    valid_fields = ['ANO', 'TEMPO', 'TITULO', 'ARTISTA', 'GENERO', 'IDIOMA',
                    'DANCEABILITY', 'ENERGY', 'KEY', 'LOUDNESS', 'MODE',
                    'SPEECHINESS', 'ACOUSTICNESS', 'INSTRUMENTALNESS', 'LIVENESS',
                    'VALENCE', 'TEMPO', 'DURATION_MS', 'TIME_SIGNATURE', 'YEAR', 'RELEASE_DATE']

    if orderedField not in valid_fields:
        raise ValueError("Entrada de chave secundária inválida. Reveja o arquivo!")

    # Correção para o nome do campo
    if orderedField == 'ARTISTA':
        orderedField = 'ARTISTS'

    inputfile.seek(0)
    tabelaIndices2 = []
    chavesCanonicasSecundarias = []
    
    campo = valid_fields.index(orderedField)
    
    for line in inputfile.readlines()[1:]:
        registro = line.split(',')
        secondaryKey = registro[campo]
        secondaryKey = secondaryKey.upper()
        chavesCanonicasSecundarias.append(secondaryKey)
    
    tabelaIndices2 = list(zip(chavesCanonicasSecundarias, [key[1] for key in primary_keys], [key[0] for key in primary_keys]))
    return tabelaIndices2, orderedSecondaryKey

# Funcao para realizar a busca de musicas com base em chaves secundariass
def search_musics(secondary_keys, ordered_secondary_key):
    rrnsList = []

    for item in secondary_keys:
        for i in range(len(item[0])):
            rrnsList.append(item[1] + ' ' + item[0][i] + ' ' + str(item[2][i]))

    rrnsList.sort()
    results = []

    for item in rrnsList:
        rrn = int(item.split(' ')[2])
        line = read_line_by_rrn('musicas.csv', rrn)
        results.append(line)

    return results

# Funcao para ler uma linha de um arquivo com base no RRN
def read_line_by_rrn(filename, rrn):
    with open(filename, 'r', encoding='utf-8') as file:
        for i, line in enumerate(file, start=1):
            if i == rrn:
                return line

# Funcao principal do programa
def main():
    # Verificando se o número correto de argumentos foi fornecido
    if len(sys.argv) != 4:
        print("Numero incorreto de argumentos. Use: python3 main.py <inputfile> <outputfile> <ordersfile>")
        sys.exit(1)

    # Obtendo nomes de arquivo dos argumentos de linha de comando
    input_filename = sys.argv[1]
    output_filename = sys.argv[2]
    orders_filename = sys.argv[3]

    # Verificando se os arquivos de entrada e ordens existem
    if not os.path.isfile(input_filename):
        print("Arquivo de entrada nao encontrado.")
        sys.exit(1)

    if not os.path.isfile(orders_filename):
        print("Arquivo de ordens não encontrado.")
        sys.exit(1)

    # Abrindo o arquivo de entrada
    with open(input_filename, 'r', encoding='utf-8') as input_file:
        # Gerando chaves pimarias e RRNs
        primary_keys = generate_primary_keys(input_file)

        # Abrindo o arquivo de ordens
        with open(orders_filename, 'r', encoding='utf-8') as orders_file:
            # Gerando chaves secundariass e obtendo a chave secundarias ordenada
            secondary_keys, ordered_secondary_key = generate_secondary_keys(primary_keys, orders_file, input_file)

            # Abrindo o arquivo de saida
            with open(output_filename, 'w', encoding='utf-8') as output_file:
                # Realizando a busca de musicas com base em chaves secundariass e escrevendo no arquivo de saida
                results = search_musics(secondary_keys, ordered_secondary_key)

                for result in results:
                    output_file.write(result)

# Executar a Funcao principal se este script for o programa principal
if __name__ == "__main__":
    main()

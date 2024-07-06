import csv
import sys
import re

class Music:
    def __init__(self, id, name, album, album_id, artists, artist_ids, track_number, disc_number, explicit, 
                 danceability, energy, key, loudness, mode, speechiness, acousticness, instrumentalness,
                 liveness, valence, tempo, duration_ms, time_signature, year, release_date):
        self.id = id
        self.name = name
        self.album = album
        self.album_id = album_id
        self.artists = artists
        self.artist_ids = artist_ids
        self.track_number = track_number
        self.disc_number = disc_number
        self.explicit = explicit
        self.danceability = danceability
        self.energy = energy
        self.key = key
        self.loudness = loudness
        self.mode = mode
        self.speechiness = speechiness
        self.acousticness = acousticness
        self.instrumentalness = instrumentalness
        self.liveness = liveness
        self.valence = valence
        self.tempo = tempo
        self.duration_ms = duration_ms
        self.time_signature = time_signature
        self.year = year
        self.release_date = release_date

class Index:
    def __init__(self, attribute):
        self.attribute = attribute
        self.index = {}

    def add_entry(self, key, value):
        if key not in self.index:
            self.index[key] = []
        self.index[key].append(value)

def read_music_data(filename):
    music_list = []
    try:
        with open(filename, 'r', encoding='utf-8') as file:
            reader = csv.DictReader(file)
            for row in reader:
                music = Music(**row)
                music_list.append(music)
    except Exception as e:
        print(f"Erro ao ler o arquivo {filename}: {e}")
        sys.exit(1)
    return music_list

def create_secondary_index(music_list, attribute):
    index = Index(attribute)
    for music in music_list:
        key = getattr(music, attribute)
        index.add_entry(key, music)
    return index

def query_index(index, value):
    matching_music = []

    # Verificar se o valor é uma faixa (intervalo)
    if "-" in value:
        start, end = map(float, value.split("-"))
        for key, music_list in index.index.items():
            key_float = float(key)
            if start <= key_float <= end:
                matching_music.extend(music_list)
    else:
        # Tratamento para case sensitive
        value_lower = value.lower()

        for key, music_list in index.index.items():
            key_lower = key.lower()

            # Consulta por valor específico
            if re.search(re.escape(value_lower), key_lower):
                matching_music.extend(music_list)

    return matching_music

def process_query(music_list, queries, output_file):
    with open(output_file, 'w', encoding='utf-8') as output:
        if not queries:
            print("Erro: O arquivo de consulta está vazio.")
            sys.exit(1)

        for query_type, query_value in queries.items():
            try:
                index = create_secondary_index(music_list, query_type)
                result = query_index(index, query_value)

                output.write(f"Query Type: {query_type}\n")
                output.write(f"Query Value: {query_value}\n")
                if result:
                    for music in result:
                        output.write(f"{music.name} - {music.artists}, {music.year}\n")
                else:
                    output.write("Nada foi Encontrado!\n")
                output.write("\n")
            except KeyError as e:
                print(f"Erro: Tipo de índice inválido na consulta: {e}")
                sys.exit(1)

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python3 script.py [data_file] [query_file] [output_file]")
        sys.exit(1)

    data_file = sys.argv[1]
    query_file = sys.argv[2]
    output_file = sys.argv[3]

    music_list = read_music_data(data_file)

    # Read queries from file
    queries = {}
    with open(query_file, 'r', encoding='utf-8') as query_file:
        lines = query_file.readlines()
        for i in range(0, len(lines), 2):
            query_type = lines[i].strip()
            query_value = lines[i + 1].strip()
            queries[query_type] = query_value

    process_query(music_list, queries, output_file)
    print("Consulta concluída com sucesso.")

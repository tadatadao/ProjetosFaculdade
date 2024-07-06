#Marcos Tadao Shoji RA:2374200
def Quicksort(array, inicio, fim, op, cont):
    if inicio < fim:
        pivo = particiona(array, inicio, fim, op, cont)
        Quicksort(array, inicio, pivo - 1, op, cont)
        Quicksort(array, pivo + 1, fim, op, cont)

def particiona(array, inicio, fim, op, cont):
    pivo = array[inicio]
    esquerda = inicio + 1
    direita = fim
    aux = False

    if op == '1':  # Ordem crescente
        while not aux:
            while esquerda <= direita and array[esquerda] <= pivo:
                esquerda += 1
            while array[direita] >= pivo and direita >= esquerda:
                direita -= 1
            if direita < esquerda:
                aux = True
            else:
                array[esquerda], array[direita] = array[direita], array[esquerda]
                cont[0] += 1
        array[inicio], array[direita] = array[direita], array[inicio]
        cont[0] += 1
        return direita

    if op == '2':  # Ordem decrescente
        while not aux:
            while esquerda <= direita and array[esquerda] >= pivo:
                esquerda += 1
            while array[direita] <= pivo and direita >= esquerda:
                direita -= 1
            if direita < esquerda:
                aux = True
            else:
                array[esquerda], array[direita] = array[direita], array[esquerda]
                cont[0] += 1
        array[inicio], array[direita] = array[direita], array[inicio]
        cont[0] += 1
        return direita

# Vetor fornecido
vetor = [-5, -30, 15, 36, -12, -23, -33, -15, 18, 19, 0, -70, -60, -18, 14]

# Solicita a ordem ao usuário
ordem = input("Digite 1 para ordenação crescente ou 2 para ordenação decrescente: ")

# Exemplo de uso do algoritmo de ordenação
cont = [0]
if ordem == '1':
    Quicksort(vetor, 0, len(vetor) - 1, '1', cont)  # Ordenação crescente
    print("Vetor ordenado em ordem crescente:", vetor)
elif ordem == '2':
    Quicksort(vetor, 0, len(vetor) - 1, '2', cont)  # Ordenação decrescente
    print("Vetor ordenado em ordem decrescente:", vetor)
else:
    print("Escolha inválida. Digite 1 para ordenação crescente ou 2 para ordenação decrescente.")

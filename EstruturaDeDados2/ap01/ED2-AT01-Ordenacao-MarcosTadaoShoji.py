#Marcos Tadao Shoji
#RA: 2374200
#ordenação escolhida: random sort

import sys
import random
import time
from datetime import datetime

sys.setrecursionlimit(10000)

# Função de ordenação Bubble Sort
def SortBubble(x):
    # Contador de comparações para o Bubble Sort
    comp_bubble = 0
    
    trocou = True
    while trocou:
        trocou = False
        for i in range(0, len(x) - 1):
            if x[i] > x[i + 1]:
                x[i], x[i + 1] = x[i + 1], x[i]  # Troca os elementos
                comp_bubble += 1  # Conta as comparações
    return comp_bubble

# Função de ordenação Selection Sort
def SortSelection(x):
    # Contador de comparações para o Selection Sort
    comp_selection = 0
    
    for i in range(0, len(x) - 1):
        menor = i
        for j in range(i, len(x)):
            if x[j] < x[menor]:
                menor = j
                comp_selection += 1
        if i != menor:
            x[i], x[menor] = x[menor], x[i]  # Troca os elementos
    return comp_selection

# Função de ordenação Insertion Sort
def SortInsertion(x):
    # Contador de comparações para o Insertion Sort
    comp_insertion = 0
    
    for i in range(1, len(x)):
        auxiliar = x[i]
        j = i - 1
        while j >= 0 and auxiliar < x[j]:
            x[j + 1] = x[j]
            j -= 1
            comp_insertion += 1
        x[j + 1] = auxiliar
    return comp_insertion

# Função de ordenação Merge Sort
def SortMerge(x):
    # Contador de comparações para o Merge Sort
    comp_merge = [0]
    
    def Merge(x, inicio, meio, fim):
        vaux = x[:]
        p1 = inicio
        p2 = meio + 1
        for k in range(inicio, fim + 1):
            if p1 > meio:
                x[k] = vaux[p2]
                p2 += 1
            elif p2 > fim:
                x[k] = vaux[p1]
                p1 += 1
            elif vaux[p2] < vaux[p1]:
                x[k] = vaux[p2]
                p2 += 1
            else:
                x[k] = vaux[p1]
                p1 += 1
            comp_merge[0] += 1
    
    def MergeSort(x, inicio, fim):
        if fim <= inicio:
            return
        meio = (inicio + fim) // 2
        MergeSort(x, inicio, meio)
        MergeSort(x, meio + 1, fim)
        Merge(x, inicio, meio, fim)
    
    MergeSort(x, 0, len(x) - 1)
    return comp_merge[0]

# Função de ordenação Quick Sort
def SortQuick(x):
    # Contador de comparações para o Quick Sort
    comp_quick = [0]
    
    def Particiona(x, inicio, fim):
        pivo = x[inicio]
        esquerda = inicio + 1
        direita = fim
        aux = False
        while not aux:
            while esquerda <= fim and x[esquerda] <= pivo:
                esquerda += 1
            while x[direita] >= pivo and direita > inicio:
                direita -= 1
            if direita < esquerda:
                aux = True
            else:
                x[esquerda], x[direita] = x[direita], x[esquerda]
                comp_quick[0] += 1
        x[inicio], x[direita] = x[direita], x[inicio]
        return direita
    
    def QuickSort(x, inicio, fim):
        if inicio < fim:
            pivo = Particiona(x, inicio, fim)
            QuickSort(x, inicio, pivo - 1)
            QuickSort(x, pivo + 1, fim)
    
    QuickSort(x, 0, len(x) - 1)
    return comp_quick[0]

# Função de ordenação Heap Sort
def SortHeap(x):
    # Contador de comparações para o Heap Sort
    comp_heap = [0]
    
    def MaxHeap(x, i, size):
        maior = i
        esquerda = 2 * i + 1
        direita = 2 * i + 2
        if esquerda <= (size - 1) and x[esquerda] > x[i]:
            maior = esquerda
        if direita <= (size - 1) and x[direita] > x[maior]:
            maior = direita
        if i != maior:
            x[i], x[maior] = x[maior], x[i]
            MaxHeap(x, maior, size - 1)
            comp_heap[0] += 1
    
    def DescobreFilhos(x, size):
        for i in range(size // 2, -1, -1):
            MaxHeap(x, i, size)
    
    def HeapSort(x):
        size = len(x)
        DescobreFilhos(x, size)
        for i in range(len(x) - 1, 0, -1):
            x[0], x[i] = x[i], x[0]
            size -= 1
            MaxHeap(x, 0, size)
            comp_heap[0] += 1
    
    HeapSort(x)
    return comp_heap[0]

# Função de ordenação Random Sort
def SortRandom(x):
    # Contador de comparações para o Random Sort
    comp_random = [0]
    
    size = len(x)
    sorted_array = x.copy()
    random.seed(42)  # Seed para garantir a mesma ordem em todas as execuções
    random.shuffle(sorted_array)  # Embaralha o array
    
    return comp_random[0]

# Função para criar um array com base no tamanho e modo especificados
def CriaArray(size, modo):
    array = []
    if modo == 'c':
        for i in range(1, size + 1):
            array.append(i)
    elif modo == 'd':
        for i in range(size, 0, -1):
            array.append(i)
    elif modo == 'r':
        for i in range(size):
            array.append(random.randint(0, 32000))
    else:
        print('Modo desconhecido. ERRO!')
        quit()
    return array

# Função para gravar os tempos de execução em um arquivo
def GravaTempos(nome_arquivo, tempos):
    with open(nome_arquivo, 'w') as arquivo:
        for algoritmo, tempo in tempos.items():
            arquivo.write(f"{algoritmo}: {tempo} ms\n")

# Leitura de tamanho e modo do arquivo
print('\nAviso ---> Não precisa de .txt\n')
try:
    with open(sys.argv[1] + '.txt', 'r') as fp:
        size = int(fp.readline())
        modo = fp.readline().strip()
except FileNotFoundError:
    print("Arquivo não encontrado.")
    sys.exit(1)

array = CriaArray(size, modo)

print(f'\nTamanho do vetor: {size}\n')

# Impressão do vetor gerado
print(f'Vetor gerado:')
print(array)

# Copiando o array original para todos os algoritmos de ordenação
array_bubble = array.copy()
array_selection = array.copy()
array_insertion = array.copy()
array_merge = array.copy()
array_quick = array.copy()
array_heap = array.copy()

# Inicialização de dicionário para armazenar os tempos de execução
tempos = {}

# Ordenação com Bubble Sort
print('==================================================================')
bubble_comps = SortBubble(array_bubble.copy())
time_inicial = datetime.now()
SortBubble(array_bubble)
time_final = datetime.now()
bubble_time = time_final - time_inicial
tempos['BubbleSort'] = bubble_time.microseconds / 1000
print(f'\n\nVetor ordenado com Bubble Sort:\n{array_bubble}')

# Ordenação com Selection Sort
print('==================================================================')
selection_comps = SortSelection(array_selection.copy())
time_inicial = datetime.now()
SortSelection(array_selection)
time_final = datetime.now()
selection_time = time_final - time_inicial
tempos['SelectionSort'] = selection_time.microseconds / 1000
print(f'\n\nVetor ordenado com Selection Sort:\n{array_selection}')

# Ordenação com Insertion Sort
print('==================================================================')
insertion_comps = SortInsertion(array_insertion.copy())
time_inicial = datetime.now()
SortInsertion(array_insertion)
time_final = datetime.now()
insertion_time = time_final - time_inicial
tempos['InsertionSort'] = insertion_time.microseconds / 1000
print(f'\n\nVetor ordenado com Insertion Sort:\n{array_insertion}')

# Ordenação com Merge Sort
print('==================================================================')
merge_comps = SortMerge(array_merge.copy())
time_inicial = datetime.now()
SortMerge(array_merge)
time_final = datetime.now()
merge_time = time_final - time_inicial
tempos['MergeSort'] = merge_time.microseconds / 1000
print(f'\n\nVetor ordenado com Merge Sort:\n{array_merge}')

# Ordenação com Quick Sort
print('==================================================================')
quick_comps = SortQuick(array_quick.copy())
time_inicial = datetime.now()
SortQuick(array_quick)
time_final = datetime.now()
quick_time = time_final - time_inicial
tempos['QuickSort'] = quick_time.microseconds / 1000
print(f'\n\nVetor ordenado com Quick Sort:\n{array_quick}')

# Ordenação com Heap Sort
print('==================================================================')
heap_comps = SortHeap(array_heap.copy())
time_inicial = datetime.now()
SortHeap(array_heap)
time_final = datetime.now()
heap_time = time_final - time_inicial
tempos['HeapSort'] = heap_time.microseconds / 1000
print(f'\n\nVetor ordenado com Heap Sort:\n{array_heap}')

# Ordenação com Random Sort
print('==================================================================')
random_comps = SortRandom(array.copy())
time_inicial = datetime.now()
SortRandom(array)
time_final = datetime.now()
random_time = time_final - time_inicial
tempos['RandomSort'] = random_time.microseconds / 1000
print(f'\n\nVetor ordenado com Random Sort:\n{array}')

# Finaliza o arquivo
print('\n\n==================================================================\n')

# Grava os tempos de execução em um arquivo
nome_arquivo = 'tempos.txt'
GravaTempos(nome_arquivo, tempos)

# Imprime os tempos de execução
print("Algoritmos de ordenação:")
for algoritmo, tempo in tempos.items():
    print(f"{algoritmo}: {tempo} ms")
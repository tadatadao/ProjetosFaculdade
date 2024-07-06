#Marcos Tadao Shoji RA:2374200
def MergeSort(V, inicio, fim, op, cont):
    if fim <= inicio:
        return V
    else:
        meio = (inicio + fim) // 2
        MergeSort(V, inicio, meio, op, cont)
        MergeSort(V, meio+1, fim, op, cont)
        Merge(V, inicio, meio, fim, op, cont)

def Merge(V, inicio, meio, fim, op, cont):
    vaux = V[:]
    p1 = inicio
    p2 = meio + 1
    if (op == 'c'):  # Ordem crescente
        for k in range(inicio, fim + 1):
            if p1 > meio:
                V[k] = vaux[p2]
                p2 += 1
            elif p2 > fim:
                V[k] = vaux[p1]
                p1 += 1
            elif vaux[p2] < vaux[p1]:
                V[k] = vaux[p2]
                p2 += 1
            else:
                V[k] = vaux[p1]
                p1 += 1
                cont[0] += 1
    elif (op == 'd'):  # Ordem decrescente
        for k in range(inicio, fim + 1):
            if p1 > meio:
                V[k] = vaux[p2]
                p2 += 1
            elif p2 > fim:
                V[k] = vaux[p1]
                p1 += 1
            elif vaux[p2] > vaux[p1]:
                V[k] = vaux[p2]
                p2 += 1
            else:
                V[k] = vaux[p1]
                p1 += 1
                cont[0] += 1

# Vetor fornecido
vetor = [-5, -30, 15, 36, -12, -23, -33, -15, 18, 19, 0, -70, -60, -18, 14]

# Exemplo de uso do algoritmo de ordenação
cont = [0]
MergeSort(vetor, 0, len(vetor) - 1, 'c', cont)  # Ordenação crescente
print("Vetor ordenado em ordem crescente:", vetor)

cont = [0]
MergeSort(vetor, 0, len(vetor) - 1, 'd', cont)  # Ordenação decrescente
print("Vetor ordenado em ordem decrescente:", vetor)
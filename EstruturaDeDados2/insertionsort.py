#Marcos Tadao Shoji RA: 2374200
def insertion_sort(vetor, opcao):
  """
  Ordena um vetor em ordem crescente ou decrescente, de acordo com a opção

  Args:
    vetor: Um vetor de números
    opcao: 1 para ordem crescente, -1 para ordem decrescente

  Returns:
    Um vetor ordenado
  """

  if opcao == 1:
    for i in range(1, len(vetor)):
      auxiliar = vetor[i]
      j = i - 1
      while j >= 0 and auxiliar < vetor[j]:
        vetor[j+1] = vetor[j]
        j -= 1
      vetor[j+1] = auxiliar
  else:
    for i in range(1, len(vetor)):
      auxiliar = vetor[i]
      j = i - 1
      while j >= 0 and auxiliar > vetor[j]:
        vetor[j+1] = vetor[j]
        j -= 1
      vetor[j+1] = auxiliar

vetor = [-5, -30, 15, 36, -12, -23, -33, -15, 18, 19, 0, -70, -60, -18, 14]
opcao = int(input("Digite a opção: "))
while opcao < -1 or opcao > 1 or opcao == 0:
  opcao = int(input("Digite a opção: "))

insertion_sort(vetor, opcao)
print(vetor)
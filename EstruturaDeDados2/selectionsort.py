#Marcos Tadao Shoji RA:2374200
def my_sort(array):
  option = input("Escolha a opção: 1 para ordem crescente ou 2 para ordem decrescente: ")
  option = int(option)
  if option == 1:
    # Ordena em ordem crescente
    array = sorted(array)
  elif option == 2:
    # Ordena em ordem decrescente
    array = sorted(array, reverse=True)
  else:
    raise ValueError("Opção inválida")
  print(array)

array = [-5, -30, 15, 36, -12, -23, -33, -15, 18, 19, 0, -70, -60, -18, 14]

my_sort(array)
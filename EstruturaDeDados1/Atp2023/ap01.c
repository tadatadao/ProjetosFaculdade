/**
 * @file ap01.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief trabalho AP (Atividade Prática) para disciplina Estrutura de Dados 1
 * @version 0.1
 * @date 2023-11-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
   char Nome[100];
   char Nascimento[20];
   char EnderecoRua[100];
   int EnderecoNumero;
   float Salario;
   struct Employee *next;
   struct Employee *prev;
};

/*
Estrutura do nó da árvore AVL, pesquisei varios maneiras de implentar a arvore reaproveitando a memoria da lista
Achei alguns artigos sobre coalescencia e tentei implementar, devido a alta quantidade de erros e as especificações do
trabalho, toda a parte foi removida para executar o código
*/ 
struct TreeNode
{
   struct Employee *employee;
   struct TreeNode *left;
   struct TreeNode *right;
   int height;
};

// Protótipos de funções
struct Employee *ler_arquivo_csv(const char *nome_arquivo);
void pesquisar_por_intervalo_salarial(struct Employee *lista_funcionarios, float valormin, float valormax);
void exibir_lista_ordenada(struct Employee *lista_funcionarios);
void exibir_lista_ordenada_inversa(struct Employee *lista_funcionarios);
void liberar_lista(struct Employee *lista_funcionarios);

int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      fprintf(stderr, "Uso: %s <caminho_do_arquivo_csv>\n", argv[0]);
      return EXIT_FAILURE;
   }

   const char *nome_arquivo = argv[1]; //"Dados_Funcionarios.csv";
   struct Employee *lista_funcionarios = ler_arquivo_csv(nome_arquivo);

   if (lista_funcionarios == NULL)
   {
      fprintf(stderr, "Erro ao ler o arquivo CSV.\n");
      return EXIT_FAILURE;
   }

   while (1)
   {
      printf("\nEscolha uma opção:\n");
      printf("1. Pesquisar funcionários por intervalo salarial\n");
      printf("2. Exibir lista de funcionários ordenados por nome de A-Z\n");
      printf("3. Exibir lista de funcionários ordenados por nome de Z-A\n");
      printf("4. Sair\n");

      int opcao;
      scanf("%d", &opcao);

      switch (opcao)
      {
      case 1:
      {
         printf("Digite o valor mínimo do intervalo salarial: ");
         float valormin;
         scanf("%f", &valormin);

         printf("Digite o valor máximo do intervalo salarial: ");
         float valormax;
         scanf("%f", &valormax);

         if (valormin >= valormax)
         {
            printf("Intervalo salarial inválido.\n");
            return EXIT_FAILURE;
         }

         pesquisar_por_intervalo_salarial(lista_funcionarios, valormin, valormax);
         break;
      }

      case 2:
         exibir_lista_ordenada(lista_funcionarios);
         break;

      case 3:
         exibir_lista_ordenada_inversa(lista_funcionarios);
         break;

      case 4:
         printf("Saindo do programa. Até mais!\n");
         liberar_lista(lista_funcionarios);
         return 0;

      default:
         printf("Opção inválida. Por favor, escolha uma opção válida.\n");
      }
   }
   return 0;
}

void exibir_arvore(struct TreeNode *raiz)
{
   if (raiz == NULL)
   {
      return;
   }

   exibir_arvore(raiz->left);
   printf("%s\n", raiz->employee->Nome);
   exibir_arvore(raiz->right);

   return 0;
}

struct Employee *ler_arquivo_csv(const char *nome_arquivo)
{
   struct Employee *lista_funcionarios = NULL;
   FILE *arquivo_csv = fopen(nome_arquivo, "r");

   if (arquivo_csv == NULL)
   {
      perror("Erro ao abrir o arquivo");
      exit(EXIT_FAILURE);
   }

   char linha[500];
   fgets(linha, sizeof(linha), arquivo_csv); // Ignorar a primeira linha (cabeçalho)

   while (fgets(linha, sizeof(linha), arquivo_csv) != NULL)
   {
      struct Employee *funcionario = (struct Employee *)malloc(sizeof(struct Employee));

      char salario_str[20]; // Definindo salario_str

      sscanf(linha, "%99[^,],%10[^,],%99[^,],%d,\"R$ %[^,]", funcionario->Nome, funcionario->Nascimento,
             funcionario->EnderecoRua, &funcionario->EnderecoNumero, salario_str);

      // Remover pontos do valor do salário
      char *ptr = salario_str;
      while (*ptr)
      {
         if (*ptr == '.')
         {
            memmove(ptr, ptr + 1, strlen(ptr));
         }
         else
         {
            ptr++;
         }
      }

      // Converter a string do salário para float
      sscanf(salario_str, "%f", &funcionario->Salario);

      funcionario->next = NULL;
      funcionario->prev = NULL;

      // Inserir na lista ordenada por nome
      if (lista_funcionarios == NULL || strcmp(funcionario->Nome, lista_funcionarios->Nome) < 0)
      {
         funcionario->next = lista_funcionarios;
         if (lista_funcionarios != NULL)
         {
            lista_funcionarios->prev = funcionario;
         }
         lista_funcionarios = funcionario;
      }
      else
      {
         struct Employee *atual = lista_funcionarios;
         while (atual->next != NULL && strcmp(funcionario->Nome, atual->next->Nome) > 0)
         {
            atual = atual->next;
         }
         funcionario->next = atual->next;
         funcionario->prev = atual;
         if (atual->next != NULL)
         {
            atual->next->prev = funcionario;
         }
         atual->next = funcionario;
      }
   }

   fclose(arquivo_csv);
   return lista_funcionarios;
}

void pesquisar_por_intervalo_salarial(struct Employee *lista_funcionarios, float valormin, float valormax)
{
   struct Employee *atual = lista_funcionarios;

   printf("Funcionários no intervalo salarial de %.2f a %.2f:\n", valormin, valormax);
   while (atual != NULL)
   {
      if (atual->Salario >= valormin && atual->Salario <= valormax)
      {
         printf("Nome: %s, Endereço: %s %d, Salário: R$ %.2f\n", atual->Nome, atual->EnderecoRua,
                atual->EnderecoNumero, atual->Salario);
      }
      atual = atual->next;
   }
}

void exibir_lista_ordenada(struct Employee *lista_funcionarios)
{
   struct Employee *atual = lista_funcionarios;

   printf("Lista de funcionários ordenados por nome:\n");
   while (atual != NULL)
   {
      printf("Nome: %s, Endereço: %s %d, Salário: %.2f\n", atual->Nome, atual->EnderecoRua,
             atual->EnderecoNumero, atual->Salario);
      atual = atual->next;
   }
}

void exibir_lista_ordenada_inversa(struct Employee *lista_funcionarios)
{
   struct Employee *atual = lista_funcionarios;

   // Avança até o final da lista
   while (atual != NULL && atual->next != NULL)
   {
      atual = atual->next;
   }

   // Agora, 'atual' aponta para o último elemento da lista
   printf("Lista de funcionários ordenados por nome de Z-A:\n");

   // Percorre a lista de trás para frente e imprime os elementos
   while (atual != NULL)
   {
      printf("Nome: %s, Endereço: %s %d, Salário: %.2f\n", atual->Nome, atual->EnderecoRua,
             atual->EnderecoNumero, atual->Salario);
      atual = atual->prev;
   }
}

void liberar_lista(struct Employee *lista_funcionarios)
{
   while (lista_funcionarios != NULL)
   {
      struct Employee *next = lista_funcionarios->next;
      free(lista_funcionarios);
      lista_funcionarios = next;
   }
}

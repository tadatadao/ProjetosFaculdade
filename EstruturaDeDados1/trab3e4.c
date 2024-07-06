//Marcos Tadao Shoji RA:2374200 trabalho 3 e 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char dataNascimento[11];
    char condicaoSaude[10];
} Cliente;

typedef struct Node {
    Cliente cliente;
    struct Node* ant;
    struct Node* prox;
} Node;

typedef struct {
    Node* inicio;
    Node* fim;
} ListaDuplamenteEncadeada;

// Função para criar uma nova lista vazia
ListaDuplamenteEncadeada* criarLista() {
    ListaDuplamenteEncadeada* lista = (ListaDuplamenteEncadeada*)malloc(sizeof(ListaDuplamenteEncadeada));
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

// Função para verificar se a lista está vazia
int listaVazia(ListaDuplamenteEncadeada* lista) {
    return lista->inicio == NULL;
}

// Função para inserir um cliente na lista em ordem alfabética
void inserirNaLista(ListaDuplamenteEncadeada* lista, Cliente cliente) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->cliente = cliente;
    novoNode->ant = NULL;
    novoNode->prox = NULL;

    if (listaVazia(lista)) {
        lista->inicio = novoNode;
        lista->fim = novoNode;
    } else {
        Node* atual = lista->inicio;
        while (atual != NULL && strcmp(cliente.nome, atual->cliente.nome) > 0) {
            atual = atual->prox;
        }

        if (atual == NULL) {
            novoNode->ant = lista->fim;
            lista->fim->prox = novoNode;
            lista->fim = novoNode;
        } else if (atual == lista->inicio) {
            novoNode->prox = lista->inicio;
            lista->inicio->ant = novoNode;
            lista->inicio = novoNode;
        } else {
            novoNode->ant = atual->ant;
            novoNode->prox = atual;
            atual->ant->prox = novoNode;
            atual->ant = novoNode;
        }
    }
}

// Função para ler os dados dos clientes do arquivo CSV
void lerDadosClientes(ListaDuplamenteEncadeada* lista) {
    FILE* arquivo;
    arquivo = fopen("DadosClientes.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    char linha[100];
    fgets(linha, sizeof(linha), arquivo);  // Ignora a primeira linha do arquivo

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nome[100];
        char dataNascimento[11];
        char condicaoSaude[10];
        sscanf(linha, "%[^,],%[^,],%s", nome, dataNascimento, condicaoSaude);

        Cliente cliente;
        strcpy(cliente.nome, nome);
        strcpy(cliente.dataNascimento, dataNascimento);
        strcpy(cliente.condicaoSaude, condicaoSaude);

        inserirNaLista(lista, cliente);
    }

    fclose(arquivo);
}

// Função para imprimir a lista de clientes
void imprimirLista(ListaDuplamenteEncadeada* lista) {
    Node* atual = lista->inicio;
    while (atual != NULL) {
        printf("Nome: %s\n", atual->cliente.nome);
        printf("Data de Nascimento: %s\n", atual->cliente.dataNascimento);
        printf("Condição de Saúde: %s\n", atual->cliente.condicaoSaude);
        printf("--------------------\n");
        atual = atual->prox;
    }
}

// Função para realizar um novo cadastro
void realizarCadastro(ListaDuplamenteEncadeada* lista) {
    Cliente novoCliente;

    printf("Digite o nome do cliente: ");
    fgets(novoCliente.nome, sizeof(novoCliente.nome), stdin);
    novoCliente.nome[strcspn(novoCliente.nome, "\n")] = '\0';

    printf("Digite a data de nascimento do cliente (formato: dd/mm/aaaa): ");
    fgets(novoCliente.dataNascimento, sizeof(novoCliente.dataNascimento), stdin);
    novoCliente.dataNascimento[strcspn(novoCliente.dataNascimento, "\n")] = '\0';

    printf("Digite a condição de saúde do cliente: ");
    fgets(novoCliente.condicaoSaude, sizeof(novoCliente.condicaoSaude), stdin);
    novoCliente.condicaoSaude[strcspn(novoCliente.condicaoSaude, "\n")] = '\0';

    inserirNaLista(lista, novoCliente);

    printf("Cadastro realizado com sucesso!\n");
}

// Função para buscar o cadastro de um cliente pelo nome
void buscarCadastro(ListaDuplamenteEncadeada* lista) {
    char nomeBusca[100];
    printf("Digite o nome do cliente que deseja buscar: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    Node* atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->cliente.nome, nomeBusca) == 0) {
            printf("Nome: %s\n", atual->cliente.nome);
            printf("Data de Nascimento: %s\n", atual->cliente.dataNascimento);
            printf("Condição de Saúde: %s\n", atual->cliente.condicaoSaude);
            return;
        }
        atual = atual->prox;
    }

    printf("Cliente não encontrado.\n");
}

// Função para alterar os dados do cadastro de um cliente
void alterarCadastro(ListaDuplamenteEncadeada* lista) {
    char nomeBusca[100];
    printf("Digite o nome do cliente que deseja alterar o cadastro: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    Node* atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->cliente.nome, nomeBusca) == 0) {
            Cliente novoCliente;

            printf("Digite o novo nome do cliente: ");
            fgets(novoCliente.nome, sizeof(novoCliente.nome), stdin);
            novoCliente.nome[strcspn(novoCliente.nome, "\n")] = '\0';

            printf("Digite a nova data de nascimento do cliente (formato: dd/mm/aaaa): ");
            fgets(novoCliente.dataNascimento, sizeof(novoCliente.dataNascimento), stdin);
            novoCliente.dataNascimento[strcspn(novoCliente.dataNascimento, "\n")] = '\0';

            printf("Digite a nova condição de saúde do cliente: ");
            fgets(novoCliente.condicaoSaude, sizeof(novoCliente.condicaoSaude), stdin);
            novoCliente.condicaoSaude[strcspn(novoCliente.condicaoSaude, "\n")] = '\0';

            atual->cliente = novoCliente;

            printf("Cadastro alterado com sucesso!\n");
            return;
        }
        atual = atual->prox;
    }

    printf("Cliente não encontrado.\n");
}

// Função para ler os nomes dos clientes na fila de espera a partir do arquivo "DadosChegada.txt"
void lerFilaEspera(ListaDuplamenteEncadeada* lista) {
    FILE* arquivo;
    arquivo = fopen("DadosChegada.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    char nome[100];
    while (fgets(nome, sizeof(nome), arquivo) != NULL) {
        nome[strcspn(nome, "\n")] = '\0';
        Cliente cliente;
        strcpy(cliente.nome, nome);
        inserirNaLista(lista, cliente);
    }

    fclose(arquivo);
}

// Função para verificar se um cliente está na fila de espera
int clienteNaFila(ListaDuplamenteEncadeada* lista, char* nome) {
    Node* atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->cliente.nome, nome) == 0) {
            return 1;  // Cliente encontrado na fila
        }
        atual = atual->prox;
    }
    return 0;  // Cliente não encontrado na fila
}

// Função para remover um cliente da fila de espera
void removerDaFila(ListaDuplamenteEncadeada* lista, char* nome) {
    Node* atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->cliente.nome, nome) == 0) {
            if (atual == lista->inicio && atual == lista->fim) {
                lista->inicio = NULL;
                lista->fim = NULL;
            } else if (atual == lista->inicio) {
                lista->inicio = atual->prox;
                atual->prox->ant = NULL;
            } else if (atual == lista->fim) {
                lista->fim = atual->ant;
                atual->ant->prox = NULL;
            } else {
                atual->ant->prox = atual->prox;
                atual->prox->ant = atual->ant;
            }
            free(atual);
            return;
        }
        atual = atual->prox;
    }
}

// Função para verificar se o restaurante está lotado
int restauranteLotado(ListaDuplamenteEncadeada* lista) {
    int count = 0;
    Node* atual = lista->inicio;
    while (atual != NULL) {
        count++;
        if (count > 15) {
            return 1;  // Restaurante lotado
        }
        atual = atual->prox;
    }
    return 0;  // Restaurante não lotado
}

// Função para simular a entrada dos clientes no restaurante
void entrarNoRestaurante(ListaDuplamenteEncadeada* lista) {
    Node* atual = lista->inicio;
    int count = 0;
    while (atual != NULL && count < 15) {
        printf("Cliente: %s - Entrou no restaurante\n", atual->cliente.nome);
        count++;
        Node* proximo = atual->prox;
        removerDaFila(lista, atual->cliente.nome);
        free(atual);
        atual = proximo;
    }
}

void restaurante(ListaDuplamenteEncadeada* lista) {
    if (restauranteLotado(lista)) {
        printf("Restaurante lotado. Não é possível receber mais clientes no momento.\n");
        return;
    }

    entrarNoRestaurante(lista);

    while (!listaVazia(lista)) {
        char opcao;
        printf("Todos os clientes do restaurante já foram atendidos. Deseja liberar mais clientes da fila de espera? (S/N): ");
        scanf(" %c", &opcao);
        getchar();  // Limpar o buffer do teclado

        if (opcao == 'S' || opcao == 's') {
            entrarNoRestaurante(lista);
        } else if (opcao == 'N' || opcao == 'n') {
            break;
        } else {
            printf("Opção inválida. Por favor, tente novamente.\n");
        }
    }

    printf("Restaurante fechado. Todos os clientes foram atendidos.\n");
}
void montarFilaEspera(ListaDuplamenteEncadeada* filaEspera, ListaDuplamenteEncadeada* filaD, ListaDuplamenteEncadeada* filaH, ListaDuplamenteEncadeada* filaN) {
    lerFilaEspera(filaEspera);

    Node* atual = filaEspera->inicio;
    while (atual != NULL) {
        if (strcmp(atual->cliente.condicaoSaude, "D") == 0) {
            inserirNaLista(filaD, atual->cliente);
        } else if (strcmp(atual->cliente.condicaoSaude, "H") == 0) {
            inserirNaLista(filaH, atual->cliente);
        } else if (strcmp(atual->cliente.condicaoSaude, "N") == 0) {
            inserirNaLista(filaN, atual->cliente);
        }
        atual = atual->prox;
    }
}

void proximosAoBuffet(ListaDuplamenteEncadeada* filaEspera, ListaDuplamenteEncadeada* filaD, ListaDuplamenteEncadeada* filaH, ListaDuplamenteEncadeada* filaN) {
    int countD = 0, countH = 0, countN = 0;

    while (!listaVazia(filaEspera) && (countD < 15 || countH < 15 || countN < 15)) {
        Node* atual = filaEspera->inicio;

        if (strcmp(atual->cliente.condicaoSaude, "D") == 0 && countD < 15) {
            inserirNaLista(filaD, atual->cliente);
            countD++;
        } else if (strcmp(atual->cliente.condicaoSaude, "H") == 0 && countH < 15) {
            inserirNaLista(filaH, atual->cliente);
            countH++;
        } else if (strcmp(atual->cliente.condicaoSaude, "N") == 0 && countN < 15) {
            inserirNaLista(filaN, atual->cliente);
            countN++;
        }

        Node* proximo = atual->prox;
        removerDaFila(filaEspera, atual->cliente.nome);
        free(atual);

        if (proximo == NULL) {
            break;
        }
    }
}

void sairDoRestaurante(ListaDuplamenteEncadeada* filaD, ListaDuplamenteEncadeada* filaH, ListaDuplamenteEncadeada* filaN) {
    Node* atual = filaD->inicio;
    while (atual != NULL) {
        printf("Cliente: %s - Saiu do restaurante\n", atual->cliente.nome);
        Node* proximo = atual->prox;
        removerDaFila(filaD, atual->cliente.nome);
        free(atual);
        atual = proximo;
    }

    atual = filaH->inicio;
    while (atual != NULL) {
        printf("Cliente: %s - Saiu do restaurante\n", atual->cliente.nome);
        Node* proximo = atual->prox;
        removerDaFila(filaH, atual->cliente.nome);
        free(atual);
        atual = proximo;
    }
    atual = filaN->inicio;
    while (atual != NULL) {
        printf("Cliente: %s - Saiu do restaurante\n", atual->cliente.nome);
        Node* proximo = atual->prox;
        removerDaFila(filaN, atual->cliente.nome);
        free(atual);
        atual = proximo;
    }
}

void imprimirFilas(ListaDuplamenteEncadeada* filaD, ListaDuplamenteEncadeada* filaH, ListaDuplamenteEncadeada* filaN, ListaDuplamenteEncadeada* filaEspera) {
    printf("Fila D:\n");
    imprimirLista(filaD);
    printf("Fila H:\n");
    imprimirLista(filaH);

    printf("Fila N:\n");
    imprimirLista(filaN);

    printf("Fila de Espera:\n");
    imprimirLista(filaEspera);
}

void gerar_relatorio(int dia, int mes, int ano, int total_atendimentos, int pessoas_hipertensas, int pessoas_diabeticas, int pessoas_saudaveis) {
    // Calcular os valores e custos com base nas informações fornecidas
    int valor_hipertensos = pessoas_hipertensas * 50;
    int valor_diabeticos = pessoas_diabeticas * 55;
    int valor_saudaveis = pessoas_saudaveis * 40;
    int custo_hipertensos = pessoas_hipertensas * 30;
    int custo_diabeticos = pessoas_diabeticas * 35;
    int custo_saudaveis = pessoas_saudaveis * 25;
    int valortotaldasvendas = valor_hipertensos + valor_diabeticos + valor_saudaveis;
    int despesas_totais = custo_hipertensos + custo_diabeticos + custo_saudaveis;
    int lucro = valortotaldasvendas - despesas_totais;

    // Gerar o nome do arquivo
    char nome_arquivo[50];
    sprintf(nome_arquivo, "Relatorio %d %d %d.txt", dia, mes, ano);

    // Abrir o arquivo para escrita
    FILE *arquivo;
    arquivo = fopen(nome_arquivo, "w");

    // Escrever o conteúdo no arquivo
    fprintf(arquivo, "Relatório do dia %d/%d/%d\n\n", dia, mes, ano);
    fprintf(arquivo, "Total de atendimentos do dia: %d\n", total_atendimentos);
    fprintf(arquivo, "Hipertensos: %d\n", pessoas_hipertensas);
    fprintf(arquivo, "Diabéticos: %d\n", pessoas_diabeticas);
    fprintf(arquivo, "Saudáveis: %d\n\n", pessoas_saudaveis);
    fprintf(arquivo, "Total de entrada (R$): %d\n", valortotaldasvendas);
    fprintf(arquivo, "Total de custos de despesas (R$): %d\n", despesas_totais);
    fprintf(arquivo, "Lucro (R$): %d\n", lucro);

    // Fechar o arquivo
    fclose(arquivo);

    printf("O arquivo %s foi gerado com sucesso!\n", nome_arquivo);
}

void liberarMemoria(ListaDuplamenteEncadeada* filaD, ListaDuplamenteEncadeada* filaH, ListaDuplamenteEncadeada* filaN, ListaDuplamenteEncadeada* filaEspera) {
    Node* atual = filaD->inicio;
    while (atual != NULL) {
        Node* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(filaD);
    atual = filaH->inicio;
    while (atual != NULL) {
        Node* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(filaH);

    atual = filaN->inicio;
    while (atual != NULL) {
        Node* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(filaN);

    atual = filaEspera->inicio;
    while (atual != NULL) {
        Node* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(filaEspera);
}

int main() {
    int opcao;

    ListaDuplamenteEncadeada* filaD = criarLista();
    ListaDuplamenteEncadeada* filaH = criarLista();
    ListaDuplamenteEncadeada* filaN = criarLista();
    ListaDuplamenteEncadeada* filaEspera = criarLista();
    lerDadosClientes(filaD);
    lerDadosClientes(filaH);
    lerDadosClientes(filaN);
    lerFilaEspera(filaEspera);

    do {
        printf("=== Sistema de Controle de Filas ===\n");
        printf("1. Montar fila de espera\n");
        printf("2. Próximos a irem ao buffet\n");
        printf("3. Sair do restaurante\n");
        printf("4. Imprimir fila D\n");
        printf("5. Imprimir fila H\n");
        printf("6. Imprimir fila N\n");
        printf("7. Imprimir fila de Espera\n");
        printf("8. Imprimir todas as filas\n");
        printf("9. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);
        getchar();  // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                montarFilaEspera(filaD, filaH, filaN, filaEspera);
                break;
            case 2:
                proximosAoBuffet(filaEspera, filaD, filaH, filaN);
                break;
            case 3:
                sairDoRestaurante(filaD, filaH, filaN);
                break;
            case 4:
                printf("Fila D:\n");
                imprimirLista(filaD);
                break;
            case 5:
                printf("Fila H:\n");
                imprimirLista(filaH);
                break;
            case 6:
                printf("Fila N:\n");
                imprimirLista(filaN);
                break;
            case 7:
                printf("Fila de Espera:\n");
                imprimirLista(filaEspera);
                break;
            case 8:
                printf("Todas as filas:\n");
                imprimirFilas(filaD, filaH, filaN, filaEspera);
                break;
            case 9:
                liberarMemoria(filaD, filaH, filaN, filaEspera);
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 9);

    // Solicitar que o usuário digite o dia, mês e ano
    int dia, mes, ano;
    printf("Digite o dia: ");
    scanf("%d", &dia);
    printf("Digite o mês: ");
    scanf("%d", &mes);
    printf("Digite o ano: ");
    scanf("%d", &ano);

    // Solicitar as informações para o relatório
    int total_atendimentos, pessoas_hipertensas, pessoas_diabeticas, pessoas_saudaveis;
    printf("Digite o total de atendimentos do dia: ");
    scanf("%d", &total_atendimentos);
    printf("Digite o número de pessoas hipertensas atendidas: ");
    scanf("%d", &pessoas_hipertensas);
    printf("Digite o número de pessoas diabéticas atendidas: ");
    scanf("%d", &pessoas_diabeticas);
    printf("Digite o número de pessoas saudáveis atendidas: ");
    scanf("%d", &pessoas_saudaveis);

    // Chamar a função para gerar o relatório
    gerar_relatorio(dia, mes, ano, total_atendimentos, pessoas_hipertensas, pessoas_diabeticas, pessoas_saudaveis);


    return 0;
}

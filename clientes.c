#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100

// Estrutura para armazenar informações do cliente
typedef struct {
    char nome[50];
    char telefone[15];
} Cliente;

int main() {
    Cliente clientes[MAX_CLIENTES];
    int totalClientes = 0;
    int opcao;

    do {
        printf("\n--- Menu de Clientes ---\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Listar Clientes\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        if (opcao == 1) {
            if (totalClientes < MAX_CLIENTES) {
                printf("Nome do Cliente: ");
                fgets(clientes[totalClientes].nome, 50, stdin);
                strtok(clientes[totalClientes].nome, "\n");

                printf("Telefone do Cliente: ");
                fgets(clientes[totalClientes].telefone, 15, stdin);
                strtok(clientes[totalClientes].telefone, "\n");

                totalClientes++;
                printf("Cliente cadastrado com sucesso!\n");
            } else {
                printf("Limite de clientes atingido.\n");
            }
        } else if (opcao == 2) {
            if (totalClientes == 0) {
                printf("Nenhum cliente cadastrado.\n");
            } else {
                printf("\n--- Lista de Clientes ---\n");
                for (int i = 0; i < totalClientes; i++) {
                    printf("Cliente %d\n", i + 1);
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Telefone: %s\n", clientes[i].telefone);
                    printf("-----------------------\n");
                }
            }
        } else if (opcao != 0) {
            printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    printf("Saindo do sistema...\n");
    return 0;
}

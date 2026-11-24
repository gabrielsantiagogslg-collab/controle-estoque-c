
#include <stdio.h>

#define MAX 10

int main() {
    char nomes[MAX][50];
    int quantidades[MAX];
    float precos[MAX];
    int total = 0;
    int opcao, i, codigo;

    do {
        printf("\n=== CONTROLE DE ESTOQUE ===\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Atualizar estoque\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");
            return 1;
        }

        switch (opcao) {
            case 1:
                if (total >= MAX) {
                    printf("Estoque cheio!\n");
                    break;
                }

                printf("Nome do produto: ");
                scanf(" %49[^\n]", nomes[total]);

                printf("Preco: ");
                if (scanf("%f", &precos[total]) != 1 ||
                    precos[total] < 0) {
                    printf("Preco invalido.\n");
                    return 1;
                }

                printf("Quantidade: ");
                if (scanf("%d", &quantidades[total]) != 1 ||
                    quantidades[total] < 0) {
                    printf("Quantidade invalida.\n");
                    return 1;
                }

                total++;
                printf("Produto cadastrado!\n");
                break;

            case 2:
                if (total == 0) {
                    printf("Nenhum produto cadastrado.\n");
                } else {
                    printf("\n--- PRODUTOS ---\n");

                    for (i = 0; i < total; i++) {
                        printf("%d - %s | R$ %.2f | Qtd: %d\n",
                               i + 1, nomes[i],
                               precos[i], quantidades[i]);
                    }
                }
                break;

            case 3:
                if (total == 0) {
                    printf("Nenhum produto cadastrado.\n");
                    break;
                }

                printf("Digite o numero do produto (1 a %d): ",
                       total);

                if (scanf("%d", &codigo) != 1) {
                    printf("Entrada invalida.\n");
                    return 1;
                }

                if (codigo < 1 || codigo > total) {
                    printf("Produto inexistente.\n");
                    break;
                }

                printf("Nova quantidade: ");
                if (scanf("%d", &quantidades[codigo - 1]) != 1 ||
                    quantidades[codigo - 1] < 0) {
                    printf("Quantidade invalida.\n");
                    return 1;
                }

                printf("Estoque atualizado!\n");
                break;

            case 0:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}

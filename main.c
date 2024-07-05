#include <stdio.h>
#include <string.h>

typedef struct
{
    char Nome[50];
    float Preco;
    int Quantidade;
} Produto;

typedef struct
{
    int Id;
    Produto Produtos[99];
    float Total;
} Pedido;

int main()
{
    int status = 1, id = 0, c = 0;
    Pedido pedidos[99];

    while (status)
    {
        printf("\e[1;1H\e[2J");
        // Usado para Limpar a Tela.
        printf("[1] - Cadastrar Novo Produto \n[2] - Listar Produtos\n[3] - Sair");
        printf("\nEscolha uma opção: ");
        int opcao;
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\e[1;1H\e[2J");

            pedidos[id].Id = id + 1;
            printf("\nID do Pedido: %d", id + 1);

            float total = 0;

            for (int i = 0; i < 99; i++)
            {
                while ((c = getchar()) != '\n' && c != EOF)
                    ;

                printf("\nDigite o nome do produto: ");
                char nome[50];
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;

                printf("\nDigite o preço do produto: ");
                float preco;
                scanf("%f", &preco);

                printf("\nDigite a quantidade do produto: ");
                int quantidade;
                scanf("%d", &quantidade);

                Produto produto = {.Preco = preco, .Quantidade = quantidade};
                strcpy(produto.Nome, nome);

                pedidos[id].Produtos[i] = produto;

                total += preco * quantidade;

                printf("\nDeseja adicionar outro produto? [s/n] ");
                char novoProduto;
                scanf(" %c", &novoProduto);

                if (novoProduto != 's')
                {
                    break;
                }
            }
            pedidos[id].Total = total;
            id++;
            break;
        case 2:
            printf("\e[1;1H\e[2J");
            for (int i = 0; i < id; i++)
            {
                printf("\nID do Pedido: %d", i + 1);

                for (int j = 0; j < 99; j++)
                {
                    if (pedidos[i].Produtos[j].Quantidade == 0)
                    {
                        break;
                    }

                    printf("\nProduto #%d", j + 1);
                    printf("\nNome do Produto: %s", pedidos[i].Produtos[j].Nome);
                    printf("\nPreço do Produto: %f", pedidos[i].Produtos[j].Preco);
                    printf("\nQuantidade do Produto: %d", pedidos[i].Produtos[j].Quantidade);
                }
                printf("\nTotal: %f", pedidos[i].Total);
            }
            printf("\nPressione qualquer tecla para continuar...");
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            getchar();
            break;
        case 3:
            status = 0;
            break;
        }
    }
    return 0;
}

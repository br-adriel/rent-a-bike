#include <stdio.h>
#include "alugueis.h"
#include "clientes.h"
#include "bicicletas.h"

void telaInicial(void);
void telaSobre(void);


int main(void) {
    telaInicial();
    return 0;
}

void telaInicial(void) {
    int opcao = 0;
    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Página inicial\n");
        printf("--------------------------------------------------\n");
        printf("\n[1] Gerenciar aluguéis\n");
        printf("[2] Gerenciar clientes\n");
        printf("[3] Gerenciar bicicletas\n");
        printf("[4] Alterar preço da hora\n");
        printf("[5] Relatório de lucros\n\n");
        printf("[6] Sobre\n");
        printf("[7] Encerrar\n");
        printf(">> ");
        scanf("%1d", &opcao);
        limparBuffer();
        printf("\n");

        switch (opcao) {
            case 1:
                telaGerenciarAlugueis();
                break;
            case 2:
                telaGerenciarClientes();
                break;
            case 3:
                telaGerenciarBicicletas();
                break;
            case 4:
                telaAlterarPreco();
                break;
            case 5:
                telaRelatorioLucros();
                break;
            case 6:
                telaSobre();
                break;
            case 7:
                break;
            default:
                msgInvalido();
        }
    } while (opcao != 7);
}

void telaAlterarPreco(void) {
    int opcao = 2;
    float novoPreco = 0.00;

    do {
        printf("\n//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Alterar preço da hora\n");
        printf("--------------------------------------------------\n\n");

        if (opcao == 2) {
            printf("/!/ Lembre-se de usar . ao invés de ,\n");
            printf("Preço atual: R$ 3.25\n");
            printf("Novo preço: ");
            scanf("%f", &novoPreco);
            limparBuffer();
        }

        printf("\n\nO novo preço será R$ %.2f, deseja salvar?\n");
        printf("[1] Sim\n[2] Não, alterar novamente\n[3] Cancelar\n");
        printf(">> ");
        scanf("%1d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                printf("= = = = = = = = =");
                printf("Novo preço salvo!");
                printf("= = = = = = = = =");
                break;
            case 2:
            case 3:
                break;
            default:
                msgInvalido();
        }
    } while (opcao != 1 && opcao != 3);
}

void telaSobre(void) {
    int opcao = 0;

    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Sobre\n");
        printf("--------------------------------------------------\n\n");
        printf("Versão: 0.5.6\n");
        printf("Última atualização: 22/11/2021\n");
        printf("Desenvolvido por Adriel Faria dos Santos\n");
        printf("\n--------------------------------------------------\n");
        printf("\n");
        printf("[1] Voltar\n");
        printf(">> ");
        scanf("%1d", &opcao);
        limparBuffer();
        printf("\n");

        switch (opcao) {
            case 1:
                break;
            default:
                msgInvalido();
        }
    } while (opcao != 1);
}

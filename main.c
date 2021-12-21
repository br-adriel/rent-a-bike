#include <stdio.h>
#include "telasAluguel.h"
#include "telasCliente.h"
#include "telasBicicleta.h"
#include "utils.h"

void telaInicial(void);
void telaSobre(void);

int main(void)
{
    telaInicial();
    return 0;
}

void telaInicial(void)
{
    int opcao = 0;
    do
    {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Página inicial\n");
        printf("--------------------------------------------------\n");
        printf("\n[1] Gerenciar aluguéis\n");
        printf("[2] Gerenciar clientes\n");
        printf("[3] Gerenciar bicicletas\n\n");
        printf("[4] Sobre\n");
        printf("[5] Encerrar\n");
        printf(">> ");
        scanf("%1d", &opcao);
        limparBuffer();
        printf("\n");

        switch (opcao)
        {
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
            telaSobre();
            break;
        case 5:
            break;
        default:
            msgInvalido();
        }
    } while (opcao != 5);
}

void telaSobre(void)
{
    int opcao = 0;

    do
    {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Sobre\n");
        printf("--------------------------------------------------\n\n");
        printf("Versão: 0.8.22\n");
        printf("Última atualização: 21/12/2021\n");
        printf("Desenvolvido por Adriel Faria dos Santos\n");
        printf("\n--------------------------------------------------\n");
        printf("\n");
        printf("[1] Voltar\n");
        printf(">> ");
        scanf("%1d", &opcao);
        limparBuffer();
        printf("\n");

        switch (opcao)
        {
        case 1:
            break;
        default:
            msgInvalido();
        }
    } while (opcao != 1);
}

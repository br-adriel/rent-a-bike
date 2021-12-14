#include <stdio.h>
#include "utils.h"
#include "telasBicicleta.h"
#include <limits.h>
#include "validadores.h"
#include "Bicicleta.h"

void telaGerenciarBicicletas(void)
{
    int opcao = 0;
    char codigo[6] = "";

    do
    {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Gerenciar bicicletas\n");
        printf("--------------------------------------------------\n");
        printf("\n[1] Nova bicicleta\n");
        printf("[2] Buscar bicicleta\n");
        printf("[3] Ver bicicleta\n");
        printf("\n[4] Voltar\n");
        printf(">> ");
        scanf("%1d", &opcao);
        limparBuffer();
        printf("\n");

        switch (opcao)
        {
        case 1:
            telaNovaBicicleta();
            break;
        case 2:
            telaBuscarBicicleta();
            break;
        case 3:
            printf("\nDigite o codigo da bicicleta: ");
            scanf("%s", codigo);
            limparBuffer();

            telaVerBicicleta(codigo);
            break;
        case 4:
            break;
        default:
            msgInvalido();
        }
    } while (opcao != 4);
}

void telaNovaBicicleta(void)
{
    int opcao = 2;
    char codigo[PATH_MAX] = "";
    char cor[PATH_MAX] = "";
    char categoria[PATH_MAX] = "";
    int disponivel = -1;
    int inputValido = 0;

    do
    {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Nova bicicleta\n");
        printf("--------------------------------------------------\n");
        if (opcao == 2)
        {
            do
            {
                printf("\nCódigo: ");
                scanf("%s", codigo);
                limparBuffer();

                inputValido = validaCodigo(codigo, 6);
            } while (!inputValido);
            do
            {
                printf("\nCor: ");
                scanf("%s", cor);
                limparBuffer();

                inputValido = validaPalavra(cor, 20);
            } while (!inputValido);

            do
            {
                printf("\nCategoria/tipo: ");
                scanf("%s", categoria);
                limparBuffer();

                inputValido = validaPalavra(categoria, 20);
            } while (!inputValido);

            do
            {
                printf("\nDisponível para aluguél? [0] NÃO [1] SIM\n>> ");
                scanf("%d", &disponivel);
                limparBuffer();

                inputValido = validaDisponivel(disponivel);
            } while (!inputValido);

            printf("\n\n--------------------------------------------------\n");
        }
        printf("\nCódigo: %s\n", codigo);
        printf("Cor: %s\n", cor);
        printf("Categoria/tipo: %s\n", categoria);
        printf("Disponível para aluguél: ");
        disponivel ? printf("SIM") : printf("NÃO");
        printf("\n\n--------------------------------------------------\n\n");
        printf("Salvar registro?");
        printf("\n[1] Sim\n[2] Não, preencher novamente\n[3] Cancelar");
        printf("\n>> ");
        scanf("%1d", &opcao);
        limparBuffer();
        printf("\n");

        switch (opcao)
        {
        case 1:
            if (gravarBicicleta(novaBicicleta(codigo, cor, categoria, disponivel)) == 1)
            {
                msgRegistroSalvo();
            }
            else
            {
                printf("/!/ Já existe uma bicicleta com esse código\n\n");
            }
            break;
        }
    } while (opcao == 2);
}

void telaBuscarBicicleta(void)
{
    int opcao = 0;
    char codigo[PATH_MAX] = "";
    char cor[PATH_MAX] = "";
    int inputValido = 0;

    do
    {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Buscar bicicleta\n");
        printf("--------------------------------------------------\n");
        do
        {
            printf("\nCor: ");
            scanf("%15s", cor);
            limparBuffer();

            inputValido = validaPalavra(cor, 20);
            printf("\n");
        } while (!inputValido);

        // faz a busca
        printf("\n--------------------------------------------------\n");
        printf("\nResultados:\n");
        printf("Código | Cor       | Ativa\n");
        printf("000000 | Amarela   | Sim\n");
        printf("000001 | Amarela   | Não\n");
        printf("\n");
        printf("[1] Ver bicicleta\n");
        printf("[2] Cancelar\n");
        printf(">> ");
        scanf("%1d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
            do
            {
                printf("\nDigite o codigo da bicicleta: ");
                scanf("%s", codigo);
                limparBuffer();

                inputValido = validaCodigo(codigo, 6);
            } while (!inputValido);

            telaVerBicicleta(codigo);
            break;
        case 2:
            break;
        default:
            msgInvalido();
        }
    } while (opcao != 2);
}

void telaVerBicicleta(char codigo[])
{
    int opcao = 3;
    Bicicleta *bicicleta;

    do
    {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Ver bicicleta\n");
        printf("\n--------------------------------------------------\n\n");
        if (bicicletaExiste(codigo) == -1)
        {
            printf("\n/!/ A bicicleta não existe\n\n");
        }
        else
        {
            bicicleta = verBicicleta(codigo);
            printf("Código: %s\n", bicicleta->codigo);
            printf("Dispónível para aluguél: ");
            bicicleta->disponivel ? printf("SIM\n") : printf("NÃO\n");
            printf("Cor: %s\n", bicicleta->cor);
            printf("Categoria/tipo: %s\n", bicicleta->categoria);
            printf("\n--------------------------------------------------\n");
            printf("\n");
            printf("[1] Editar\n");
            printf("[2] Apagar\n");
            printf("\n[3] Voltar\n");
            printf(">> ");
            scanf("%1d", &opcao);
            limparBuffer();
            printf("\n");
        }
        switch (opcao)
        {
        case 1:
            telaEditarBicicleta(codigo);
            break;
        case 2:
            telaExcluirBicicleta(codigo);
            opcao = 3;
            break;
        case 3:
            break;
        default:
            msgInvalido();
        }
    } while (opcao != 3);
}

void telaEditarBicicleta(char codigo[])
{
    int opcao = 2;

    char cor[PATH_MAX] = "";
    char categoria[PATH_MAX] = "";
    int disponivel = -1;
    int inputvalido = 0;
    Bicicleta *bicicleta = verBicicleta(codigo);

    do
    {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Editar bicicleta");
        if (opcao == 2)
        {
            printf("\n--------------------------------------------------\n");
            do
            {
                printf("\nCor [%s]: ", bicicleta->cor);
                scanf("%s", cor);
                limparBuffer();

                inputvalido = validaPalavra(cor, 20);
            } while (!inputvalido);

            do
            {
                printf("\nCategoria/tipo [%s]: ", bicicleta->categoria);
                scanf("%s", categoria);
                limparBuffer();

                inputvalido = validaPalavra(categoria, 20);
            } while (!inputvalido);

            do
            {
                printf("\nDisponível para aluguél [");
                bicicleta->disponivel ? printf("SIM") : printf("NÃO");
                printf("]:\n");
                printf("[0] NÃO [1] SIM\n>> ");
                scanf("%d", &disponivel);
                limparBuffer();

                inputvalido = validaDisponivel(disponivel);
            } while (!inputvalido);
        }
        printf("\n\n--------------------------------------------------\n\n");
        printf("Código: %s\n", codigo);
        printf("Cor: %s\n", cor);
        printf("Categoria/tipo: %s\n", categoria);
        printf("Disponível para aluguél: ");
        disponivel ? printf("SIM") : printf("NÃO");
        printf("\n--------------------------------------------------\n\n");
        printf("Atualizar?");
        printf("\n[1] Sim\n[2] Não, preencher novamente\n[3] Cancelar");
        printf("\n>> ");
        scanf("%1d", &opcao);
        limparBuffer();
        printf("\n");

        switch (opcao)
        {
        case 1:
            if (atualizarBicicleta(codigo, cor, categoria, disponivel))
            {
                msgRegistroSalvo();
            }
            else
            {
                printf("/!/ Um erro ocorreu.");
            }
            break;
        case 2:
        case 3:
            break;
        default:
            msgInvalido();
            break;
        }
    } while (opcao != 1 && opcao != 3);
}

void telaExcluirBicicleta(char codigo[])
{
    int opcao = 0;

    do
    {
        printf("\n");
        printf("Excluir bicicleta %s?", codigo);
        printf("\n[1] Sim\n[2] Não");
        printf("\n>> ");
        scanf("%1d", &opcao);
        limparBuffer();
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("\n= = = = = = = = = =");
            printf("\nBicicleta excluída!");
            printf("\n= = = = = = = = = =\n\n");
            break;
        case 2:
            break;
        default:
            msgInvalido();
        }
    } while (opcao != 1 && opcao != 2);
}

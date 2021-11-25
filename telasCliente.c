#include <stdio.h>
#include "utils.h"
#include "telasCliente.h"
#include "validadores.h"
#include <limits.h>

void telaGerenciarClientes(void)
{
    int opcao = 0;
    char email[PATH_MAX] = "";
    int inputValido = 0;

    do
    {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Gerenciar clientes\n");
        printf("--------------------------------------------------\n");
        printf("\n[1] Novo cliente\n");
        printf("[2] Buscar cliente\n");
        printf("[3] Ver cliente\n");
        printf("\n[4] Voltar\n");
        printf(">> ");
        scanf("%1d", &opcao);
        limparBuffer();
        printf("\n");

        switch (opcao)
        {
        case 1:
            telaNovoCliente();
            break;
        case 2:
            telaBuscarCliente();
            break;
        case 3:
            do
            {
                printf("\nDigite o email do cliente: ");
                scanf("%s", email);
                limparBuffer();

                inputValido = validaEmail(email);
                printf("\n");
            } while (!inputValido);

            telaVerCliente(email);
            break;
        case 4:
            break;
        default:
            msgInvalido();
        }
    } while (opcao != 4);
}

void telaNovoCliente(void)
{
    int opcao = 2;
    char email[PATH_MAX] = "";
    char nome[PATH_MAX] = "";
    char sobrenome[PATH_MAX] = "";
    int inputValido = 0;

    do
    {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Novo cliente\n");
        printf("--------------------------------------------------\n");
        if (opcao == 2)
        {
            do
            {
                printf("\nEmail: ");
                scanf("%s", email);
                limparBuffer();

                inputValido = validaEmail(email);
                printf("\n");
            } while (!inputValido);

            do
            {
                printf("\nNome: ");
                scanf("%s", nome);
                limparBuffer();

                inputValido = validaNome(nome);
                printf("\n");
            } while (!inputValido);

            do
            {
                printf("\nSobrenome: ");
                scanf("%s", sobrenome);
                limparBuffer();

                inputValido = validaNome(sobrenome);
                printf("\n");
            } while (!inputValido);

            printf("\n--------------------------------------------------\n");
        }
        printf("\nEmail: %s\n", email);
        printf("Nome: %s\n", nome);
        printf("Sobrenome: %s", sobrenome);
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
            printf("\n= = = = = = = =");
            printf("\nRegistro salvo!");
            printf("\n= = = = = = = =\n\n");
            break;
        }
    } while (opcao == 2);
}

void telaBuscarCliente(void)
{
    int opcao = 0;
    char nome[PATH_MAX] = "";
    char email[PATH_MAX] = "";
    int inputValido = 0;

    do
    {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Buscar cliente\n");
        printf("--------------------------------------------------\n");
        do
        {
            printf("\nNome do cliente ");
            scanf("%s", nome);
            limparBuffer();

            inputValido = validaNome(nome);
            printf("\n");
        } while (!inputValido);

        // faz a busca
        printf("\n--------------------------------------------------\n");
        printf("\nResultados:\n");
        printf("Email do cliente   | Nome     | Sobrenome\n");
        printf("fulano@email.com   | Fulano   | Silva\n");
        printf("f.santos@email.com | Fulano   | Santos\n");
        printf("\n");
        printf("[1] Ver cliente\n");
        printf("[2] Cancelar\n");
        printf(">> ");
        scanf("%1d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
            do
            {
                printf("\nDigite o email do cliente: ");
                scanf("%s", email);
                limparBuffer();

                inputValido = validaEmail(email);
                printf("\n");
            } while (!inputValido);
            telaVerCliente(email);
            break;
        case 2:
            break;
        default:
            msgInvalido();
        }
    } while (opcao != 2);
}

void telaVerCliente(char email[])
{
    int opcao = 3;
    do
    {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Ver cliente");
        printf("\n--------------------------------------------------\n");
        printf("Nome: Fulano\n");
        printf("Sobrenome: Silva\n");
        printf("Email: %s", email);
        printf("\n--------------------------------------------------\n");
        printf("\n");
        printf("[1] Editar\n");
        printf("[2] Apagar\n");
        printf("\n[3] Voltar\n");
        printf(">> ");
        scanf("%1d", &opcao);
        limparBuffer();
        printf("\n");

        switch (opcao)
        {
        case 1:
            telaEditarCliente(email);
            break;
        case 2:
            telaExcluirCliente(email);
            opcao = 3;
            break;
        case 3:
            break;
        default:
            msgInvalido();
        }
    } while (opcao != 3);
}

void telaEditarCliente(char email[])
{
    int opcao = 2;

    char novoEmail[PATH_MAX] = "";
    char nome[PATH_MAX] = "";
    char sobrenome[PATH_MAX] = "";
    int inputValido = 0;

    do
    {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Editar cliente");
        if (opcao == 2)
        {
            printf("\n--------------------------------------------------\n");
            do
            {
                printf("\nEmail [fulano@email.com]: ");
                scanf("%s", novoEmail);
                limparBuffer();

                inputValido = validaEmail(email);
                printf("\n");
            } while (!inputValido);

            do
            {
                printf("\nNome do cliente [Fulano]: ");
                scanf("%s", nome);
                limparBuffer();

                inputValido = validaNome(nome);
                printf("\n");
            } while (!inputValido);

            do
            {
                printf("\nSobrenome do cliente [Silva]: ");
                scanf("%s", sobrenome);
                limparBuffer();

                inputValido = validaNome(sobrenome);
                printf("\n");
            } while (!inputValido);
        }
        printf("\n\n--------------------------------------------------\n\n");
        printf("Email: %s\n", email);
        printf("Nome: %s\n", nome);
        printf("Sobrenome: %s\n", sobrenome);
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
            // Salva mudanças
            printf("\n= = = = = = = = = =");
            printf("\nAlterações salvas!");
            printf("\n= = = = = = = = = =\n\n");
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

void telaExcluirCliente(char email[])
{
    int opcao = 0;

    do
    {
        printf("\n");
        printf("Excluir cliente %s?", email);
        printf("\n[1] Sim\n[2] Não");
        printf("\n>> ");
        scanf("%1d", &opcao);
        limparBuffer();
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("\n= = = = = = = = = =");
            printf("\nCliente excluído!");
            printf("\n= = = = = = = = = =\n\n");
            break;
        case 2:
            break;
        default:
            msgInvalido();
        }
    } while (opcao != 1 && opcao != 2);
}

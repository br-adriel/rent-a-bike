#include <stdio.h>
#include "utils.h"
#include "telasCliente.h"


void telaGerenciarClientes(void) {
    int opcao = 0;
    char email[71] = "";

    do {
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

        switch (opcao) {
            case 1:
                telaNovoCliente();
                break;
            case 2:
                telaBuscarCliente();
                break;
            case 3:
                printf("\nDigite o email do cliente: ");
                scanf("%70s", email);
                limparBuffer();

                telaVerCliente(email);
                break;
            case 4:
                break;
            default:
                msgInvalido();
        }
    } while (opcao != 4);
}

void telaNovoCliente(void) {
    int opcao = 2;
    char email[71] = "";
    char nome[21] = "";
    char sobrenome[21] = "";

    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Novo cliente\n");
        printf("--------------------------------------------------\n");
        if (opcao == 2) {
            printf("\nEmail: ");
            scanf("%70s", email);
            limparBuffer();

            printf("\nNome: ");
            scanf("%20s", nome);
            limparBuffer();

            printf("\nSobrenome: ");
            scanf("%20s", sobrenome);
            limparBuffer();

            printf("\n\n--------------------------------------------------\n");
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

        
        switch (opcao) {
            case 1:
                printf("\n= = = = = = = =");
                printf("\nRegistro salvo!");
                printf("\n= = = = = = = =\n\n");
                break;
        }
    } while (opcao == 2);
}

void telaBuscarCliente(void) {
    int opcao = 0;
    char nome[21] = "";
    char email[71] = "";

    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Buscar cliente\n");
        printf("--------------------------------------------------\n");
        printf("\nNome do cliente ");
        scanf("%20s", nome);
        limparBuffer();

        printf("\n");
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

        switch (opcao) {
            case 1:
                printf("\nDigite o email do cliente: ");
                scanf("%70s", email);
                limparBuffer();

                telaVerCliente(email);
                break;
            case 2:
                break;
            default:
                msgInvalido();
        }
    } while (opcao != 2);
}

void telaVerCliente(char email[]) {
    int opcao = 3;
    do {
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
 
        switch (opcao) {
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

void telaEditarCliente(char email[]) {
    int opcao = 2;

    char novoEmail[71] = "";
    char nome[21] = "";
    char sobrenome[21] = "";

    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Editar cliente");
        if (opcao == 2) {
            printf("\n--------------------------------------------------\n");
            printf("\nEmail [fulano@email.com]: ");
            scanf("%70s", novoEmail);
            limparBuffer();

            printf("\nNome do cliente [Fulano]: ");
            scanf("%20s", nome);
            limparBuffer();

            printf("\nSobrenome do cliente [Silva]: ");
            scanf("%20s", sobrenome);
            limparBuffer();
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

        switch (opcao) {
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

void telaExcluirCliente(char email[]) {
    int opcao = 0;

    do {
        printf("\n");
        printf("Excluir cliente %s?", email);
        printf("\n[1] Sim\n[2] Não");
        printf("\n>> ");
        scanf("%1d", &opcao);
        limparBuffer();
        printf("\n");

        switch (opcao) {
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

#include <stdio.h>


void telaInicial(void);

void msgInvalido(void);

// CRUD de Emprestimo
void telaGerenciarEmprestimos(void);
void telaNovoEmprestimo(void);
// void listarEmprestimos(void);
void telaVerEmprestimo(void);
// void telaAtualizarEmprestimo(void);
// void telaExcluirEmprestimo(void);

void telaAlterarPrecos(void);
void telaExtrato(void);
void telaSobre(void);


int main(void) {
    telaInicial();
    return 0;
}

void telaInicial(void) {
    char escolha;

    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Página inicial\n");
    printf("--------------------------------------------------\n");
    printf("\n[1] Gerenciar empréstimos\n");
    printf("[2] Alterar tabela de preços\n");
    printf("[3] Extrato\n\n");
    printf("[s] Sobre\n");
    printf("[e] Encerrar\n");
    printf(">> ");
    scanf(" %c", &escolha);
    printf("\n");

    switch (escolha) {
        case '1':
            telaGerenciarEmprestimos();
            break;
        case '2':
            telaAlterarPrecos();
            break;
        case '3':
            telaExtrato();
            break;
        case 'e':
        case 'E':
            break;
        case 's':
        case 'S':
            telaSobre();
            break;
        default:
            msgInvalido();
            telaInicial();
    }
}

void msgInvalido(void) {
    printf("\n///////////////////////\n");
    printf("// Escolha inválida! //\n");
    printf("///////////////////////\n\n");
}

// Telas referentes ao módulo empréstimo
void telaGerenciarEmprestimos(void) {
    char escolha;

    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Gerenciar empréstimos\n");
    printf("--------------------------------------------------\n");
    printf("\n[1] Novo empréstimo\n");
    printf("[2] Listar empréstimos\n");
    printf("\n[v] Voltar\n");
    printf("[e] Encerrar\n");
    printf(">> ");
    scanf(" %c", &escolha);
    printf("\n");

    switch (escolha) {
        case '1':
            telaNovoEmprestimo();
            break;
        case '2':
            // telaListarEmprestimos();
            break;
        case 'e':
        case 'E':
            break;
        case 'v':
        case 'V':
            telaInicial();
            break;
        default:
            msgInvalido();
            telaGerenciarEmprestimos();
    }
}

void telaNovoEmprestimo(void) {
    char escolha;

    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Nova locação\n");
    printf("--------------------------------------------------\n\n");

    /* Formulario de nova locação */
    printf("\n\n\n");

    printf("\n--------------------------------------------------\n");
    printf("\n");
    printf("[v] Voltar\n");
    printf("[e] Encerrar\n");
    printf(">> ");
    scanf(" %c", &escolha);
    printf("\n");

    switch (escolha) {
        case 'e':
        case 'E':
            break;
        case 'v':
        case 'V':
            telaGerenciarEmprestimos();
            break;
        default:
            msgInvalido();
            telaNovoEmprestimo();
    }
}

void telaVerEmprestimo(void) {
    char escolha;

    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Ver locações\n");
    printf("--------------------------------------------------\n\n");

    /* Perguntar ao usuário o intervalo de datas das locações */
    printf("\n\n\n");

    printf("\n--------------------------------------------------\n");
    printf("\n");
    printf("[v] Voltar\n");
    printf("[e] Encerrar\n");
    printf(">> ");
    scanf(" %c", &escolha);
    printf("\n");

    switch (escolha) {
        case 'e':
        case 'E':
            break;
        case 'v':
        case 'V':
            telaInicial();
            break;
        default:
            msgInvalido();
            telaVerEmprestimo();
    }
}

void telaAlterarPrecos(void) {
    char escolha;

    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Alterar tabela de preços\n");
    printf("--------------------------------------------------\n\n");

    /* Mostrar tabela e atual e perguntar novos valores */
    printf("\n\n\n");

    printf("\n--------------------------------------------------\n");
    printf("\n");
    printf("[v] Voltar\n");
    printf("[e] Encerrar\n");
    printf(">> ");
    scanf(" %c", &escolha);
    printf("\n");

    switch (escolha) {
        case 'e':
        case 'E':
            break;
        case 'v':
        case 'V':
            telaInicial();
            break;
        default:
            msgInvalido();
            telaAlterarPrecos();
    }
}

void telaExtrato(void) {
    char escolha;

    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Extrato\n");
    printf("--------------------------------------------------\n\n");

    /* Perguntar período a ser considerado */
    /* Exibir o extrato do período determinado */
    /* Perguntar se quer exportar para arquivo */
    printf("\n\n\n");

    printf("\n--------------------------------------------------\n");
    printf("\n");
    printf("[v] Voltar\n");
    printf("[e] Encerrar\n");
    printf(">> ");
    scanf(" %c", &escolha);
    printf("\n");

    switch (escolha) {
        case 'e':
        case 'E':
            break;
        case 'v':
        case 'V':
            telaInicial();
            break;
        default:
            msgInvalido();
            telaExtrato();
    }
}

void telaSobre(void) {
    char escolha;

    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Sobre\n");
    printf("--------------------------------------------------\n\n");
    printf("Versão: 0.1\n");
    printf("Última atualização: 21/10/2021\n");
    printf("Desenvolvido por Adriel Faria dos Santos\n");
    printf("\n--------------------------------------------------\n");
    printf("\n");
    printf("[v] Voltar\n");
    printf("[e] Encerrar\n");
    printf(">> ");
    scanf(" %c", &escolha);
    printf("\n");

    switch (escolha) {
        case 'e':
        case 'E':
            break;
        case 'v':
        case 'V':
            telaInicial();
            break;
        default:
            msgInvalido();
            telaSobre();
    }
}

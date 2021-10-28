#include <stdio.h>


void telaInicial(void);

void msgInvalido(void);

// CRUD de Emprestimo
void telaGerenciarEmprestimos(void);
void telaNovoEmprestimo(void);
void telaListarEmprestimos(void);
void telaVerEmprestimo(char[]);
void telaEditarEmprestimo(char[]);
void telaExcluirEmprestimo(char[]);

void telaBuscarEmprestimo(void);
void telaRelatorioLucros(void);

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
    printf("[3] Relatório de lucros\n\n");
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
            telaRelatorioLucros();
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
    printf("[3] Buscar empréstimo\n");
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
            telaListarEmprestimos();
            break;
        case '3':
            telaBuscarEmprestimo();
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
    char escolha = ' ';

    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Novo empréstimo\n");
        printf("--------------------------------------------------\n");
        printf("\nCódigo da bicicleta: ");
        printf("\nHoras em uso: ");
        printf("\nMinutos em uso: ");
        printf("\nEmail do cliente: ");
        printf("\n\n--------------------------------------------------\n\n");
        printf("Cliente: fulano@email.com\n");
        printf("Tempo em uso: 1h 15min\n");
        printf("Preço: R$ 32.21\n");
        printf("Data de emissão: 31/12/9999");
        printf("\n\n--------------------------------------------------\n\n");
        printf("Salvar registro?");
        printf("\n[1] Sim\n[2] Não, preencher novamente\n[3] Cancelar");
        printf("\n>> ");
        scanf(" %c", &escolha);
        printf("\n");

    } while (escolha != '1' && escolha != '3');

    switch (escolha) {
        case '1':
            printf("\n= = = = = = = =");
            printf("\nRegistro salvo!");
            printf("\n= = = = = = = =\n\n");
            break;
    }
    telaGerenciarEmprestimos();
}

void telaListarEmprestimos(void) {
    char escolha = ' ';
    do {
        char codigo[6] = "------";
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Listar empréstimos\n");
        printf("--------------------------------------------------\n\n");
        printf("Código | Cliente          | Preco    | Data\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("\n--------------------------------------------------\n");
        printf("[1] Visualizar empréstimo\n");
        printf("[v] voltar\n");
        printf(">> ");
        scanf(" %c", &escolha);
        printf("\n");

        switch (escolha) {
            case '1':
                printf("Digite o código do empréstimo: ");
                scanf("%s", codigo);
                printf("\n");
                telaVerEmprestimo(codigo);
                break;
            case 'v':
            case 'V':
                break;
            default:
                msgInvalido();
        }
    } while (escolha != 'v' && escolha != 'v');
    telaGerenciarEmprestimos();
}

void telaVerEmprestimo(char codigo[]) {
    char escolha = ' ';
    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Empréstimo #%s\n", codigo);
        printf("--------------------------------------------------\n");
        printf("-- Cliente ---------------------------------------\n");
        printf("Nome: Fulano Sicrano\n");
        printf("Email: fulano@email.com\n");
        printf("-- Bicicleta -------------------------------------\n");
        printf("Código: 123456\n");
        printf("Cor: Azul\n");
        printf("Situação: Em manutenção\n");
        printf("-- Empréstimo ------------------------------------\n");
        printf("Tempo em uso: 1h 15min\n");
        printf("Preço: R$ 32.21\n");
        printf("Data de emissão: 31/12/9999");
        printf("\n--------------------------------------------------\n");
        printf("\n");
        printf("[1] Editar\n");
        printf("[2] Apagar\n");
        printf("[v] Voltar\n");
        printf(">> ");
        scanf(" %c", &escolha);
        printf("\n");

        switch (escolha) {
            case '1':
                telaEditarEmprestimo(codigo);
                break;
            case '2':
                telaExcluirEmprestimo(codigo);
                break;
            case 'v':
            case 'V':
                break;
            default:
                msgInvalido();
        }
    } while (escolha != 'v' && escolha != 'V');
}

void telaEditarEmprestimo(char codigo[]) {
    char escolha = '2';
    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Editar empréstimo #%s", codigo);
        if (escolha == '2') {
            printf("\n--------------------------------------------------\n");
            printf("\nCódigo da bicicleta [123456]: ");
            printf("\nHoras em uso [1]: ");
            printf("\nMinutos em uso [30]: ");
            printf("\nEmail do cliente [fulano@email.com]: ");
        }
        printf("\n\n--------------------------------------------------\n\n");
        printf("Código da bicicleta: 134567\n");
        printf("Horas em uso: 1\n");
        printf("Minutos em uso: 15");
        printf("Email do cliente: fulano2@email.com\n");
        printf("\n--------------------------------------------------\n\n");
        printf("Atualizar?");
        printf("\n[1] Sim\n[2] Não, preencher novamente\n[3] Cancelar");
        printf("\n>> ");
        scanf(" %c", &escolha);
        printf("\n");
    } while (escolha != '1' && escolha != '3');

    switch (escolha) {
    case '1':
        // Salva mudanças
        break;
    case '3':
        break;
    default:
        msgInvalido();
        break;
    }
}

void telaExcluirEmprestimo(char codigo[]) {
    char escolha = ' ';

    printf("\n");
    printf("Excluir empréstimo #%s?", codigo);
    printf("\n[1] Sim\n[2] Não");
    printf("\n>> ");
    // scanf(" %c", &escolha);
    printf("\n");
}

void telaBuscarEmprestimo() {
    char escolha = ' ';

    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Buscar empréstimo\n");
    printf("--------------------------------------------------\n");
    printf("\nData do empréstimo ");
    printf("\nDia: ");
    printf("\nMês: ");
    printf("\nAno: ");
    printf("\n");
    printf("\n--------------------------------------------------\n");
    printf("\nResultados:\n");
    printf("Código | Email do cliente | Preço    | Data\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
    printf("\n");
    printf("[1] Ver emprestimo\n");
    printf(">> ");
    scanf(" %c", &escolha);
    if (escolha == '1') {
        printf("\n Digite o código do empréstimo: ");
        // char codigo[6];
        // scanf para pegar o codigo
        // telaVerEmprestimo(codigo);
    }
}

void telaRelatorioLucros(void) {
    char escolha;

    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Relatório de lucros\n");
    printf("--------------------------------------------------\n");
    printf("\n[1] Diário\n");
    printf("[2] Semanal\n");
    printf("[3] Mensal\n");
    printf("\n[4] Voltar\n");
    printf(">> ");
    scanf(" %c", &escolha);
    printf("\n");
    printf("\nGerando relatório...\n");

    if (escolha == '4') {
        telaInicial();
    } else {
        printf("\n-- Relatório 12/02/2020 ---------------------------\n");
        printf("Empréstimos: 230\n");
        printf("Lucro total: R$ 250.32\n");
        printf("\n-- Detalhamento -----------------------------------\n");
        printf("Código | Cliente          | Preco    | Data\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("000000 | fulano@email.com | R$ 23.19 | 31/12/9999\n");
        printf("\n");
        printf("Exportar?\n");
        printf("[1] Sim\n[2] Não\n");
        printf(">> ");
        // scanf
        // if para saber se deve exportar
            // mostra a msg "exportando..."

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

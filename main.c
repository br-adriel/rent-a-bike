#include <stdio.h>


void telaInicial(void);

void msgInvalido(void);

// CRUD de Aluguel
void telaGerenciarAlugueis(void);
void telaNovoAluguel(void);
void telaListarAlugueis(void);
void telaVerAluguel(char[]);
void telaEditarAluguel(char[]);
void telaExcluirAluguel(char[]);

void telaBuscarAluguel(void);
void telaRelatorioLucros(void);

void telaAlterarPrecos(void);
void telaSobre(void);


int main(void) {
    telaInicial();
    msgInvalido();
    telaGerenciarAlugueis();
    telaNovoAluguel();
    telaListarAlugueis();
    telaVerAluguel("123456");
    telaEditarAluguel("123456");
    telaExcluirAluguel("123456");
    telaBuscarAluguel();
    telaRelatorioLucros();
    telaAlterarPrecos();
    telaSobre();
    return 0;
}

void telaInicial(void) {
    int opcao = 0;
    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Página inicial\n");
        printf("--------------------------------------------------\n");
        printf("\n[1] Gerenciar aluguéis\n");
        printf("[2] Alterar preço da hora\n");
        printf("[3] Relatório de lucros\n\n");
        printf("[4] Sobre\n");
        printf("[5] Encerrar\n");
        printf(">> ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                telaGerenciarAlugueis();
                break;
            case 2:
                telaAlterarPrecos();
                break;
            case 3:
                telaRelatorioLucros();
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

void msgInvalido(void) {
    printf("\n///////////////////////\n");
    printf("// Escolha inválida! //\n");
    printf("///////////////////////\n\n");
}

// Telas referentes ao módulo aluguél
void telaGerenciarAlugueis(void) {
    // char escolha;

    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Gerenciar aluguéis\n");
    printf("--------------------------------------------------\n");
    printf("\n[1] Novo aluguél\n");
    printf("[2] Listar aluguéis\n");
    printf("[3] Buscar aluguél\n");
    printf("\n[4] Voltar\n");
    printf(">> ");
    // scanf(" %c", &escolha);
    printf("\n");

    /* 
    switch (escolha) {
        case '1':
            telaNovoAluguel();
            break;
        case '2':
            telaListarAlugueis();
            break;
        case '3':
            telaBuscarAluguel();
            break;
        case '4':
            telaInicial();
            break;
        default:
            msgInvalido();
            telaGerenciarAlugueis();
    }
    */
}

void telaNovoAluguel(void) {
    // char escolha = ' ';

    // do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Novo aluguél\n");
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
        // scanf(" %c", &escolha);
        printf("\n");

    // } while (escolha != '1' && escolha != '3');

    /*
    switch (escolha) {
        case '1':
            printf("\n= = = = = = = =");
            printf("\nRegistro salvo!");
            printf("\n= = = = = = = =\n\n");
            break;
    }
    telaGerenciarAlugueis();
    */
}

void telaListarAlugueis(void) {
    // char escolha = ' ';
    // do {
        // char codigo[6] = "------";
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Listar aluguéis\n");
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
        printf("[1] Visualizar aluguél\n");
        printf("\n[2] voltar\n");
        printf(">> ");
        // scanf(" %c", &escolha);
        printf("\n");

        /*
        switch (escolha) {
            case '1':
                printf("Digite o código do aluguél: ");
                scanf("%s", codigo);
                printf("\n");
                telaVerAluguel(codigo);
                break;
            case '2':
                break;
            default:
                msgInvalido();
        }
    } while (escolha != '2');
    telaGerenciarAlugueis();
    */
}

void telaVerAluguel(char codigo[]) {
    // char escolha = ' ';
    // do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - aluguél #%s\n", codigo);
        printf("--------------------------------------------------\n");
        printf("-- Cliente ---------------------------------------\n");
        printf("Nome: Fulano Sicrano\n");
        printf("Email: fulano@email.com\n");
        printf("-- Bicicleta -------------------------------------\n");
        printf("Código: 123456\n");
        printf("Cor: Azul\n");
        printf("Situação: Em manutenção\n");
        printf("-- aluguél ------------------------------------\n");
        printf("Tempo em uso: 1h 15min\n");
        printf("Preço: R$ 32.21\n");
        printf("Data de emissão: 31/12/9999");
        printf("\n--------------------------------------------------\n");
        printf("\n");
        printf("[1] Editar\n");
        printf("[2] Apagar\n");
        printf("\n[3] Voltar\n");
        printf(">> ");
        // scanf(" %c", &escolha);
        printf("\n");

        /*
        switch (escolha) {
            case '1':
                telaEditarAluguel(codigo);
                break;
            case '2':
                telaExcluirAluguel(codigo);
                break;
            case '3':
                break;
            default:
                msgInvalido();
        }
    } while (escolha != '3');
    */
}

void telaEditarAluguel(char codigo[]) {
    // char escolha = '2';
    // do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Editar aluguél #%s", codigo);
        // if (escolha == '2') {
            printf("\n--------------------------------------------------\n");
            printf("\nCódigo da bicicleta [123456]: ");
            printf("\nHoras em uso [1]: ");
            printf("\nMinutos em uso [30]: ");
            printf("\nEmail do cliente [fulano@email.com]: ");
        // }
        printf("\n\n--------------------------------------------------\n\n");
        printf("Código da bicicleta: 134567\n");
        printf("Horas em uso: 1\n");
        printf("Minutos em uso: 15");
        printf("Email do cliente: fulano2@email.com\n");
        printf("\n--------------------------------------------------\n\n");
        printf("Atualizar?");
        printf("\n[1] Sim\n[2] Não, preencher novamente\n[3] Cancelar");
        printf("\n>> ");
        // scanf(" %c", &escolha);
        printf("\n");
    /* } while (escolha != '1' && escolha != '3');

    switch (escolha) {
    case '1':
        // Salva mudanças
        break;
    case '3':
        break;
    default:
        msgInvalido();
        break;
    } */
}

void telaExcluirAluguel(char codigo[]) {
    // char escolha = ' ';

    printf("\n");
    printf("Excluir aluguél #%s?", codigo);
    printf("\n[1] Sim\n[2] Não");
    printf("\n>> ");
    // scanf(" %c", &escolha);
    printf("\n");
}

void telaBuscarAluguel() {
    // char escolha = ' ';

    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Buscar aluguél\n");
    printf("--------------------------------------------------\n");
    printf("\nData do aluguél ");
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
    printf("[1] Ver Aluguel\n");
    printf(">> ");
    /* scanf(" %c", &escolha);
    if (escolha == '1') {
        printf("\n Digite o código do aluguél: ");
        // char codigo[6];
        // scanf para pegar o codigo
        // telaVerAluguel(codigo);
    } */
}

void telaRelatorioLucros(void) {
    // char escolha;

    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Relatório de lucros\n");
    printf("--------------------------------------------------\n");
    printf("\n[1] Diário\n");
    printf("[2] Semanal\n");
    printf("[3] Mensal\n");
    printf("\n[4] Voltar\n");
    printf(">> ");
    // scanf(" %c", &escolha);
    printf("\n");
    printf("\nGerando relatório...\n");

    /* if (escolha == '4') {
        telaInicial();
    } else { */
        printf("\n-- Relatório 12/02/2020 ---------------------------\n");
        printf("aluguéis: 230\n");
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

    // }
}


void telaAlterarPrecos(void) {
    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Alterar preço da hora\n");
    printf("--------------------------------------------------\n\n");

    printf("/!/ Lembre-se de usar . ao invés de ,\n");
    printf("Preço atual: R$ 3.25\n");
    printf("Novo preço: ");
    // scanf para captar novo preco
    printf("\n\nO novo preço será R$ 0.00, deseja salvar?\n");
    printf("[1] Sim\n[2] Não\n");
    printf(">> ");
    // scan para captar resposta
    // if para salvar se a escolha foi sim
        // printf exibindo preco salvo

    // telaInicial();
}

void telaSobre(void) {
    // char escolha;

    printf("//////////////////////////////////////////////////\n");
    printf("RENT A BIKE - Sobre\n");
    printf("--------------------------------------------------\n\n");
    printf("Versão: 0.2.2\n");
    printf("Última atualização: 04/11/2021\n");
    printf("Desenvolvido por Adriel Faria dos Santos\n");
    printf("\n--------------------------------------------------\n");
    printf("\n");
    printf("[1] Voltar\n");
    printf(">> ");
    // scanf(" %c", &escolha);
    printf("\n");

    /*
    switch (escolha) {
        case '1':
            telaInicial();
            break;
        default:
            msgInvalido();
            telaSobre();
    } */
}

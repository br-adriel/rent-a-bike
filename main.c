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

void telaAlterarPreco(void);
void telaSobre(void);


int main(void) {
    telaInicial();
    return 0;
}

void limparBuffer() {
    // código extraído de 
    // cprogressivo.net/2012/12/Buffer--o-que-e-como-limpar-e-as-funcoes-fflush-e-fpurge.html
    __fpurge(stdin); // linux
    // fflush(stdin); // windows
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
                telaAlterarPreco();
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
    int opcao = 0;

    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Gerenciar aluguéis\n");
        printf("--------------------------------------------------\n");
        printf("\n[1] Novo aluguél\n");
        printf("[2] Listar aluguéis\n");
        printf("[3] Buscar aluguél\n");
        printf("\n[4] Voltar\n");
        printf(">> ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                telaNovoAluguel();
                break;
            case 2:
                telaListarAlugueis();
                break;
            case 3:
                telaBuscarAluguel();
                break;
            case 4:
                break;
            default:
                msgInvalido();
                telaGerenciarAlugueis();
        }
    } while (opcao != 4);
}

void telaNovoAluguel(void) {
    int opcao = 2;
    char codBicicleta[6] = "";
    int horasUso = 0;
    int minutosUso = 0;
    char emailCliente[70] = "";

    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Novo aluguél\n");
        printf("--------------------------------------------------\n");
        if (opcao == 2) {
            printf("\nCódigo da bicicleta: ");
            scanf("%s", codBicicleta);
            printf("\nHoras em uso: ");
            scanf("%d", &horasUso);
            printf("\nMinutos em uso: ");
            scanf("%d", &minutosUso);
            printf("\nEmail do cliente: ");
            scanf("%s", emailCliente);
            printf("\n\n--------------------------------------------------\n");
        }
        printf("\nCliente: %s\n", emailCliente);
        printf("Tempo em uso: %dh %dmin\n", horasUso, minutosUso);
        printf("Preço: R$ 32.21\n");
        printf("Data de emissão: 31/12/9999");
        printf("\n\n--------------------------------------------------\n\n");
        printf("Salvar registro?");
        printf("\n[1] Sim\n[2] Não, preencher novamente\n[3] Cancelar");
        printf("\n>> ");
        scanf("%d", &opcao);
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

void telaListarAlugueis(void) {
    int opcao = 2;
    char codigo[6] = "";
    do {
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
        scanf("%d", &opcao);
        printf("\n");

        
        switch (opcao) {
            case 1:
                printf("Digite o código do aluguél: ");
                scanf("%s", codigo);
                printf("\n");
                telaVerAluguel(codigo);
                break;
            case 2:
                break;
            default:
                msgInvalido();
        }
    } while (opcao != 2);
}

void telaVerAluguel(char codigo[]) {
    int opcao = 3;
    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Aluguél #%s\n", codigo);
        printf("--------------------------------------------------\n");
        printf("-- Cliente ---------------------------------------\n");
        printf("Nome: Fulano Sicrano\n");
        printf("Email: fulano@email.com\n");
        printf("-- Bicicleta -------------------------------------\n");
        printf("Código: 123456\n");
        printf("Cor: Azul\n");
        printf("Situação: Em manutenção\n");
        printf("-- Aluguél ------------------------------------\n");
        printf("Tempo em uso: 1h 15min\n");
        printf("Preço: R$ 32.21\n");
        printf("Data de emissão: 31/12/9999");
        printf("\n--------------------------------------------------\n");
        printf("\n");
        printf("[1] Editar\n");
        printf("[2] Apagar\n");
        printf("\n[3] Voltar\n");
        printf(">> ");
        scanf("%d", &opcao);
        printf("\n");

        
        switch (opcao) {
            case 1:
                telaEditarAluguel(codigo);
                break;
            case 2:
                telaExcluirAluguel(codigo);
                break;
            case 3:
                break;
            default:
                msgInvalido();
        }
    } while (opcao != 3);
}

void telaEditarAluguel(char codigo[]) {
    int opcao = 2;

    char codBicicleta[6] = "";
    int horasUso = 0;
    int minutosUso = 0;
    char emailCliente[70] = "";

    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Editar aluguél #%s", codigo);
        if (opcao == 2) {
            printf("\n--------------------------------------------------\n");
            printf("\nCódigo da bicicleta [123456]: ");
            scanf("%s", codBicicleta);
            printf("\nHoras em uso [1]: ");
            scanf("%d", &horasUso);
            printf("\nMinutos em uso [30]: ");
            scanf("%d", &minutosUso);
            printf("\nEmail do cliente [fulano@email.com]: ");
            scanf("%s", emailCliente);
        }
        printf("\n\n--------------------------------------------------\n\n");
        printf("Código da bicicleta: %s\n", codBicicleta);
        printf("Horas em uso: %d\n", horasUso);
        printf("Minutos em uso: %d", minutosUso);
        printf("Email do cliente: %s\n", emailCliente);
        printf("\n--------------------------------------------------\n\n");
        printf("Atualizar?");
        printf("\n[1] Sim\n[2] Não, preencher novamente\n[3] Cancelar");
        printf("\n>> ");
        scanf("%d", &opcao);
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

void telaExcluirAluguel(char codigo[]) {
    int opcao = 0;

    do {
        printf("\n");
        printf("Excluir aluguél #%s?", codigo);
        printf("\n[1] Sim\n[2] Não");
        printf("\n>> ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                printf("\n= = = = = = = = = =");
                printf("\nAluguél #%s excluído!", codigo);
                printf("\n= = = = = = = = = =\n\n");
                break;
            case 2:
                break;
            default:
                msgInvalido();
        }
    } while (opcao != 1 && opcao != 2);
}


void telaBuscarAluguel() {
    int opcao = 0;
    int dia = 0;
    int mes = 0;
    int ano = 0;

    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Buscar aluguél\n");
        printf("--------------------------------------------------\n");
        printf("\nData do aluguél ");
        printf("\nDia: ");
        scanf("%d", &dia);
        printf("\nMês: ");
        scanf("%d", &mes);
        printf("\nAno: ");
        scanf("%d", &ano);
        printf("\n");
        // faz a busca
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
        printf("[2] Cancelar\n");
        printf(">> ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o código do aluguél: ");
                char codigo[6];
                scanf("%s", codigo);
                telaVerAluguel(codigo);
                break;
            case 2:
                break;
            default:
                msgInvalido();
        }
    } while (opcao != 1);
}

void telaRelatorioLucros(void) {
    int opcao = 0;

    do {
        if (opcao == 0) {
            printf("//////////////////////////////////////////////////\n");
            printf("RENT A BIKE - Relatório de lucros\n");
            printf("--------------------------------------------------\n");
            printf("\n[1] Diário\n");
            printf("[2] Semanal\n");
            printf("[3] Mensal\n");
            printf("\n[4] Voltar\n");
            printf(">> ");
            scanf("%d", &opcao);
            printf("\n");
            printf("\nGerando relatório...\n");
        }

        printf("\n-- Relatório 12/02/2020 ---------------------------\n");
        printf("Aluguéis: 230\n");
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
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n= = = = = = = = = = = = = = = = = = = = = = = = =");
                printf("\nExportado para o arquivo \"Extrato-2021-11-05.txt");
                printf("\n= = = = = = = = = = = = = = = = = = = = = = = = =\n");
                break;
            case 2:
                break;
            default:
                msgInvalido();
        }
    } while (opcao != 1 && opcao != 2);
}

void telaAlterarPreco(void) {
    int opcao = 2;
    float novoPreco = 0.00;

    do {
        printf("//////////////////////////////////////////////////\n");
        printf("RENT A BIKE - Alterar preço da hora\n");
        printf("--------------------------------------------------\n\n");

        if (opcao == 2) {
            printf("/!/ Lembre-se de usar . ao invés de ,\n");
            printf("Preço atual: R$ 3.25\n");
            printf("Novo preço: ");
            scanf("%.2f", &novoPreco);
        }

        printf("\n\nO novo preço será R$ %.2f, deseja salvar?\n");
        printf("[1] Sim\n[2] Não, alterar novamente\n[3] Cancelar\n");
        printf(">> ");
        scanf("%d", &opcao);

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
        printf("Versão: 0.2.14\n");
        printf("Última atualização: 05/11/2021\n");
        printf("Desenvolvido por Adriel Faria dos Santos\n");
        printf("\n--------------------------------------------------\n");
        printf("\n");
        printf("[1] Voltar\n");
        printf(">> ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                break;
            default:
                msgInvalido();
        }
    } while (opcao != 1);
}

# Rent a Bike 🚴

Sistema para gerenciamento de aluguéis de bicicletas.

<img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="Embolema C" title="Desenvolvido com C">

## Cenário de aplicabilidade

O software pretende atender ao cenário no qual uma companhia de aluguéis
de bicicletas deseja, a partir de um pequeno sistema, registrar as informações
referentes às suas bicicletas, clientes, e aluguéis realizados. Além disso,
a partir dessas informações o software é capaz de calcular o valor de cada
aluguél automaticamente e também gerar um relatório com informações das ultimas
movimentacões realizadas.

## Módulos do projeto

O sistema é dividido em três módulos principais (Aluguéis, Clientes e Bicicletas)
e dois módulos de funcionalidades genéricas (Validadores e Utils).

#### Aluguéis

- Dados:
  - Email do cliente
  - Código da bicicleta
  - Data/hora de retirada da bicicleta
  - Data/hora de retorno da bicicleta
  - Preço do aluguél
  - Situação do aluguél
- Funcionalidades:
  - CRUD
  - Pesquisa de aluguéis
  - Relatório de atividade

#### Clientes

- Dados:
  - Nome
  - Sobrenome
  - Email
  - Telefone
- Funcionalidades:
  - CRUD
  - Pesquisa de clientes

#### Bicicletas

- Dados:
  - Código
  - Disponibilidade
  - Cor
  - Categoria/tipo
- Funcionalidades:
  - CRUD
  - Pesquisa de bicicletas

## Execução

### Linux

```
gcc -c -Wall *.c
gcc -o rentabike *.o
./rentabike
```

# Rent a Bike 🚴

Sistema para gerenciamento de aluguéis de bicicletas.

<img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="Embolema C" title="Desenvolvido com C">

## Cenário previsto de aplicação

O software a ser desenvolvido pretende atender um cenário imaginário no qual uma companhia de aluguéis
de bicicletas deseja, a partir de um pequeno sistema, registrar as informações referentes às suas bicicletas,
seus clientes, e os aluguéis realizados, bem como, a partir dessas informações, o software ser capaz de
calcular o valor de cada empréstimo automaticamente e também um relatório de lucros.

## Módulos do projeto

O sistema será dividido em três módulos

#### Aluguéis

- Dados: Email do cliente, data, horas em uso, minutos em uso, preço
- Funcionalidades: CRUD, pesquisa por data, relatório de lucros

#### Clientes

- Dados: Nome, sobrenome, email
- Funcionalidades: CRUD, pesquisa por nome

#### Bicicletas

- Dados: Código, ativa, cor
- Funcionalidades: CRUD, pesquisa por cor

## Execução

### Linux

```
gcc -c -Wall *.c
gcc -o rentabike *.o
./rentabike
```

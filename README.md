Tarefas a fazer até o dia 7 (entrega):

- Criar as funções do CARTAS.c
- Criar a linguagem do TSTCARTAS.c
- Incrementar a massa de testes do TesteLista.script
- Criar a massa de testes do TesteCartas.script

Projeto:

- CARTAS.c - Implementação do módulo CARTAS
- CARTAS.h - Definição do módulo CARTAS
- MESA.c - Implementação do módulo MESA
- MESA.h - Definição do módulo MESA
- LISTA.c - Implementação do módulo LISTA
- LISTA.h - Definição do módulo LISTA
- INTERFACE.c - Implementação do módulo INTERFACE
- INTERFACE.h - Definição do módulo INTERFACE

Para testes:

- TSTLIS.c - Implementação do teste do módulo LISTA
- TesteLista.script - Massa de testes para testes do módulo LISTA
- TSTCARTAS.c - Implementação do teste do módulo CARTAS
- TesteCartas.script - Massa de testes para testes do módulo CARTAS
- TSTMESA.c - Implementação do teste do módulo MESA
- TesteMesa.script - Massa de testes para testes do módulo MESA
- TSTINTERFACE.c - Implementação do teste do módulo INTERFACE
- TesteInterface.script - Massa de testes para testes do módulo INTERFACE
- GENERICO.h - Módulo de suporte para testes (deve ser incluído nos módulos de teste e não deve ser alterado)
- LERPARM.h - Módulo de suporte para testes (deve ser incluído nos módulos de teste e não deve ser alterado)
- TST_ESPC.h - Módulo de suporte para testes (deve ser incluído nos módulos de teste e não deve ser alterado)

Passo-a-passo T2:

1. Estude as regras do jogo de truco e crie um documento que contenha a Especificação de
Requisitos de TODO O TRABALHO DO PERÍODO. Mesmo que no trabalho 2 não seja
objetivo completar a implementação do jogo como um todo, a especificação deverá nortear
todo o projeto. (DONE)

2. Crie a arquitetura do programa, apresentando um diagrama contendo a definição de todos os
módulos (e respectivas interfaces) necessários para a implementação do jogo de truco.
Novamente, isto se refere a TODO O TRABALHO DO PERÍODO. Este diagrama apresentará
cada módulo necessário, suas interfaces, seus interrelacionamentos, e as funções
disponibilizadas em cada interface. Adicione este diagrama ao documento, elaborado no item
1, criando assim uma boa especificação de programa que documente o trabalho que o grupo
terá ao longo do período. (DONE)

3. Elabore o modelo estrutural do trabalho. É importante que haja apenas UMA estrutura para
cada jogo. Esta será uma lista de listas. Cada nó da lista principal apontará para a cabeça de
uma lista com as cartas do jogador 1, outro para a lista com as cartas do jogador 2, etc..., outro
apontará para a lista de cartas descartadas na mesa, e assim por diante. Esta estrutura será
especificada no trabalho 2, porém implementada no trabalho3. (DONE)

4. Elabore e teste separadamente o módulo de embaralhamento. Este módulo deverá receber
uma sequência representando baralho ordenado e retornar esta sequência embaralhada.
Deverá ser criado um projeto separado apenas para este teste. Elabore o script para testar
este módulo completamente.

5. Para os testes, deve-se seguir uma linguagem de script definida pelo grupo. Além disso,
incorpore, de forma rigorosa, implementação de assertivas nas funções dos módulos.
Observação importante: Não se preocupem ainda em implementar a lista de listas (estrutura
principal). Esta só será implementada no trabalho 4. No entanto, esta será ESPECIFICADA no
documento do trabalho 2 conforme já definimos neste enunciado.

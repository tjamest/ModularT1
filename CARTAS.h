#if ! defined( CARTAS_ )
#define CARTAS_
/***************************************************************************
*
*  $MCD Módulo de definição: CAR  Cartas
*
*  Arquivo gerado:              CARTAS.h
*  Letras identificadoras:      CAR
*
*  Nome da base de software:    Truco
*  Arquivo da base de software:
*
*  Projeto: INF 1301 Jogo de Truco
*  Gestor:
*  Autores: gsc, jvr, tgf
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       gsc   19/abr/2018 início desenvolvimento
*
*  $ED Descrição do módulo
*     Cria um baralho (lista) de 40 cartas (sem os 8, 9, 10 e coringa);
*     Embaralha essas 40 cartas;
*     Cria as mãos dos jogadores (lista de 3 elementos, que são 3 cartas);
*     Cria uma lista que armazena as cartas apostadas na mesa e a manilha;
*     Destrói esse baralho.
***************************************************************************/

#include "LISTA.h"

#if defined( CARTAS_OWN )
   #define CARTAS_EXT
#else
   #define CARTAS_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma carta */

typedef struct Carta * CAR_tpCarta

/***********************************************************************
*
*  $TC Tipo de dados: BAR Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções de carta
*
***********************************************************************/

typedef enum { //não tenho certeza se essas condições de retorno devem existir

  CAR_CondRetOK,                 /* Concluiu corretamente */
  CAR_CondRetNaoCriouBaralho,    /* Não criou a lista "baralho" de 40 cartas */
  CAR_CondRetNaoCriouMaoJogador, /* Não criou as listas "mão jogador" */
  CAR_CondRetNaoCriouMesa,       /* Não criou a lista "mesa" */
  CAR_CondRetNaoDestruiuBaralho, /* Não destruiu o baralho no fim da partida */
  CAR_CondRetFaltouMemoria       /* Faltou memoria */ 
  
  /* OBS:.Já sabemos se faltou memória ou não já que estamos utilizando o
  módulo lista, e quando nós tentassemos criar um baralho adicionando cartas
  para a lista ia retornar a condição de falta de memória */

  } CAR_tpCondRet;

/***********************************************************************
*
*  $TC Tipo de dados: CAR tpValor
*
*
*  $ED Descrição do tipo
*     Domínio dos possíveis valores de uma carta.
*
***********************************************************************/
typedef enum {

  _4,               /* 0  */
  _5,               /* 1  */
  _6,               /* 2  */
  _7,               /* 3  */
  _Q,               /* 4  */
  _J,               /* 5  */
  _K,               /* 6  */
  _A,               /* 7  */
  _2,               /* 8  */
  _3,               /* 9  */
  _Manilha          /* 10 */
  
   } CAR_tpValor ;

/***********************************************************************
*
*  $TC Tipo de dados: BAR tpNaipe
*
*
*  $ED Descrição do tipo
*     Dominio dos possiveis naipes de uma carta.
*
***********************************************************************/
typedef enum {

  Ouros,          /*0*/
  Espadas,        /*1*/
  Copas,          /*2*/
  Paus            /*3*/

   } CAR_tpNaipe ;

/***********************************************************************
*
*  $FC Função: CAR  &Criar Baralho
*
*  $ED Descrição da função
*   Cria um baralho (lista) de 40 cartas sem os 8, 9, 10 e coringas.
*
*  $EP Parâmetros
*     pBaralho: uma estrutura LIS_tppLista com uma cabeça vazia para poder preencher
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para o início do baralho.
*     Este ponteiro será utilizado pelas funções que manipulem este baralho.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
*     Assertivas de entrada:
*     - O endereço de ponteiro para a carta deve ser válido
*     - O valor deve estar dentro do intervalo definido (0 a 10)
*     - O naipe deve ser válido
*     Assertivas de saída:
*     - O espaço de memória para o baralho foi alocado com sucesso e seus valores definidos corretamente
*     
*
***********************************************************************/

BAR_tpCondRet BAR_CriarBaralho(LIS_tppLista pBaralho);

/**********************************************************************
*
*  $FC Função: CAR  &Embaralhar Baralho
*
*  $ED Descrição da função
*   Recebe uma lista (baralho) e reordena a ordem de seus elementos para uma ordem aleatória.
*
*  $EP Parâmetros
*     pBaralho: uma estrutura LIS_tppLista apontando para a cabeça com o baralho.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para o início do baralho.
*     Este ponteiro será utilizado pelas funções que manipulem este baralho.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados incorretos, 
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
*     Assertivas de entrada:
*     - O endereço de ponteiro para o baralho deve conter elementos preenchidos com cartas.
*     - O endereço de ponteiro para a carta deve ser válido.

*     Assertivas de saída:
*     - A ordem das cartas do baralho tem de estar diferentes da ordem de antes de entrar na função.
*     - As cartas devem ser reordenadas de maneira aleatória.
*
*
***********************************************************************/

BAR_tppBaralho EmbaralharBaralho(LIS_tppLista pBaralho);

/**********************************************************************
*
*  $FC Função: CAR  &Destruir Baralho
*
*  $ED Descrição da função
*     Destrói a lista baralho fornecida.
*     O parâmetro ponteiro para a lista não é modificado.
*     Se ocorrer algum erro durante a destruição, a lista resultará
*     estruturalmente incorreta.
*     OBS. não existe previsão para possíveis falhas de execução.
*
*  $FV Valor retornado
*     LIS_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

void CAR_DestruirBaralho(LIS_tppLista pBaralho);

#undef CARTAS_EXT

/************** Fim do módulo de definição: CAR  Cartas **************/

#else
#endif

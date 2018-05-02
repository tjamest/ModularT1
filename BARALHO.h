#if ! defined( BARALHO_ )
#define BARALHO_
/***************************************************************************
*
*  $MCD Módulo de definição: BAR  Baralho
*
*  Arquivo gerado:              BARALHO.h
*  Letras identificadoras:      BAR
*
*  Nome da base de software:    Truco
*  Arquivo da base de software:
*
*  Projeto: INF 1301 Jogo de Truco
*  Gestor:
*  Autores: gsc, jvr, tgf
*
*  $HA Histórico de evolução:
*     Versão      Autor         Data            Observações
*     2       gsc, jvr, tgf   31/abr/2018     criação da função CriarBaralho
*     1            gsc        19/abr/2018     início desenvolvimento
*
*  $ED Descrição do módulo
*     Cria um baralho (lista) de 40 (ou vamos fazer com 52?) cartas (sem os 8,
*     9, 10 e coringa) pegando elementos previamente embaralhados em um vetor;
*     Cria as mãos dos jogadores (lista de 3 elementos, que são 3 cartas);
*     Cria uma lista que armazena as cartas apostadas na mesa e a manilha;
*     Destrói esse baralho.
***************************************************************************/

#include "LISTA.h"

#if defined( BARALHO_OWN )
   #define BARALHO_EXT
#else
   #define BARALHO_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma carta */

typedef struct BAR_tagCarta * BAR_tppCarta

/***********************************************************************
*
*  $TC Tipo de dados: BAR Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções de carta.
*
***********************************************************************/

typedef enum { //não tenho certeza se algumas dessas condições de retorno devem existir

  BAR_CondRetOK,                 /* 0 = Concluiu corretamente */
  BAR_CondRetNaoCriouBaralho,    /* 1 = Não criou a lista "baralho" de 40 cartas */
  BAR_CondRetNaoCriouMaoJogador, /* 2 = Não criou as listas "mão jogador" */
  BAR_CondRetNaoCriouMesa,       /* 3 = Não criou a lista "mesa" */
  BAR_CondRetNaoDestruiuBaralho, /* 4 = Não destruiu o baralho no fim da partida */
  BAR_CondRetFaltouMemoria       /* 5 = Faltou memoria */ 
  
  /* OBS:.Já sabemos se faltou memória ou não já que estamos utilizando o
  módulo lista, e quando nós tentassemos criar um baralho adicionando cartas
  para a lista ia retornar a condição de falta de memória */

  } BAR_tpCondRet;

/***********************************************************************
*
*  $TC Tipo de dados: BAR tpValorCarta
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
  
   } BAR_tpValorCarta ;

/***********************************************************************
*
*  $TC Tipo de dados: BAR tpNaipeCarta
*
*
*  $ED Descrição do tipo
*     Dominio dos possiveis naipes de uma carta.
*
***********************************************************************/
typedef enum {

  Ouros,          /* 0 */
  Espadas,        /* 1 */
  Copas,          /* 2 */
  Paus            /* 3 */

   } BAR_tpNaipeCarta ;

/***********************************************************************
*
*  $TC Tipo de dados: BAR tpCarta
*
*
*  $ED Descrição do tipo
*     Estrutura de uma carta, que tem um valor e um naipe.
*
***********************************************************************/
   typedef struct BAR_tagCarta {

     BAR_tpValorCarta valor ; /* 4, 5, 6, 7, Q, J, K, A, 2, 3,
                              ManilhaOuros, ManilhaEspadas, 
                              ManilhaCopas, ManilhaPaus */

     BAR_tpNaipeCarta naipe ; /* Ouros, Espadas, Copas, Paus */

   } BAR_tpCarta;

/***********************************************************************
*
*  $FC Função: BAR  &Criar Baralho
*
*  $ED Descrição da função
*     Cria um baralho (tpLista) de 40 elementos (tpCarta) sem os 8, 9, 10
*     e coringas.
*     Pega 40 elementos (tipo Carta) de um vetor aleatoriamente ordenado
*     e coloca em uma lista.
*
*  $EP Parâmetros
*     pVetorEmbaralhado: ponteiro pra um vetor de tipo Carta
*
*  $FV Valor retornado
*     Se executar corretamente retorna o ponteiro para o início do baralho
*     (ponteiro para o tipo lista). Este ponteiro será utilizado pelas
*     funções que manipulem este baralho.
*
*     Se ocorrer algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
*     Assertivas de entrada:
*     - pVetorEmbaralhado != NULL
*     Assertivas de saída:
*     - pBaralho != NULL
*     
*
***********************************************************************/

LIS_tppLista BAR_CriarBaralho(BAR_tppCarta pVetorEmbaralhado);

/**********************************************************************
*
*  $FC Função: BAR  &Criar Embaralhar Vetor
*
*  $ED Descrição da função
*   Cria e reordena aleatóriamente um vetor de 52 elementos do tipo Carta.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro pro primeiro elemento do vetor.
*     Este ponteiro será utilizado pela função CriarBaralho.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados incorretos, 
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
*     Assertivas de saída:
*     - O ponteiro pro tpCarta retornado não pode ser NULL.
*
*
***********************************************************************/

BAR_tpCarta CriarEmbaralharVetor();

/**********************************************************************
*
*  $FC Função: BAR  &Destruir Baralho
*
*  $ED Descrição da função
*     Destrói a lista baralho fornecida.
*     O parâmetro ponteiro para a lista não é modificado.
*     Se ocorrer algum erro durante a destruição, a lista resultará
*     estruturalmente incorreta.
*     OBS. não existe previsão para possíveis falhas de execução.
*
*  $FV Valor retornado
*     BAR_tpCondRet    - BAR_CondRetNaoDestruiuBaralho
*     BAR_tpCondRet    - BAR_CondRetOK
*
***********************************************************************/

BAR_tpCondRet BAR_DestruirBaralho(LIS_tppLista pBaralho);

#undef BARALHO_EXT

/************** Fim do módulo de definição: BAR  Baralho **************/

#else
#endif

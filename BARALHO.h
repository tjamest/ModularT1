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
*     Versão  Autor    Data     Observações
*     1       gsc   19/abr/2018 início desenvolvimento
*
*  $ED Descrição do módulo
*     Cria um baralho de 40 cartas (sem os 8, 9, 10 e coringa).
*     Embaralha essas 40 cartas.
*     Destrói esse baralho.
***************************************************************************/

#if defined( BARALHO_OWN )
   #define BARALHO_EXT
#else
   #define BARALHO_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma carta */

typedef struct Carta * BAR_tpCarta

/***********************************************************************
*
*  $TC Tipo de dados: BAR Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções de carta
*
***********************************************************************/

typedef enum {

  BAR_CondRetOK,              /* Concluiu corretamente */

  BAR_CondRetFaltouMemoria,   /* Faltou memoria */ /*OBS:.Já sabemos se faltou memória ou não já que estamos utilizando o
módulo lista, e quando nós tentassemos criar um baralho adicionando cartas para a lista ia retornar a condição de falta
de memória*/
  } BAR_tpCondRet;

/***********************************************************************
*
*  $TC Tipo de dados: BAR tpValor
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
  
   } BAR_tpValor ;

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

  Ouros,
  Espadas,
  Copas,
  Paus

   } BAR_tpNaipe ;

/***********************************************************************
*
*  $FC Função: LIS  &Criar Baralho
*
*  $ED Descrição da função
*   Cria um baralho (lista) de 40 cartas sem os 8, 9, 10 e coringas.
*
*  $EP Parâmetros
*     *pBaralho: Ponteiro para o início da lista (baralho)
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
BAR_tpCondRet BAR_CriarBaralho(Ponteiro que recebe o endereço do baralho criado);
BAR_tppBaralho BAR_EmbaralhaBaralho(Endereço para cabeça da lista que contem o baralho);

#else
#endif

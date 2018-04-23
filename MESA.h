#if ! defined( MESA_ )
#define MESA_
/***************************************************************************
*
*  $MCD Módulo de definição: MES  MESA
*
*  Arquivo gerado:              MESA.h
*  Letras identificadoras:      MES
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
*     .
***************************************************************************/

#if defined( MESA_OWN )
   #define MESA_EXT
#else
   #define MESA_EXT extern
#endif

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma lista */

typedef struct LIS_tagLista * LIS_tppLista ; // <- não editei, original do LISTA.h

/***********************************************************************
*
*  $TC Tipo de dados: MES Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da mesa
*
***********************************************************************/

   typedef enum {

         MES_CondRetOK ,
               /* Concluiu corretamente */

         MES_CondRetNaoDefiniuVira ,
               /* A mesa não definiu a vira */

         MES_CondRetNaoDistribuiuMaos ,
               /* A mesa não distribuiu as mãos */

         MES_CondRetNaoDefiniuQuemComeca ,
               /* A mesa não definiu quem começa */
      
         MES_CondRetNaoAtualizouPontuacaoRodada ,
               /* A mesa não atualizou a pontuação da rodada */
      
         MES_CondRetNaoChecouPontuacaoRodada ,
               /* A mesa não checou a pontuação da rodada */
      
         MES_CondRetNaoAtualizouPontuacaoPartida ,
               /* A mesa não atualizou a pontuação da partida */
      
         MES_CondRetNaoChecouPontuacaoPartida ,
               /* A mesa não checou a pontuação da partida */
      
         MES_CondRetNaoAtualizouCartasMesa ,
               /* A mesa não atualizou as cartas da mesa */
      
         MES_CondRetNaoAtualizouValorRodada
               /* A mesa não atualizou o valor da rodada */

} MES_tpCondRet ;

/***********************************************************************
*
*  $FC Função: MES  &Definir vira
*
*  $ED Descrição da função
*     Define qual carta será a vira e, consequentemente,
*     define também a manilha.
*
*  $EP Parâmetros
*     pUltimoElem  - ponteiro para o último elemento da
*                    lista "mesa", que será a carta "vira".
*                    //ou armazena a carta "manilha"? pra usar pra comparações no código
*
*  $FV Valor retornado
*     MES_CondRetOK
*     MES_CondRetNaoDefiniuVira
*
***********************************************************************/

   void MES_DefinirVira( LIS_tppLista pUltimoElemMesa ) ;

/***********************************************************************
*
*  $FC Função: MES  &Distribuir mãos
*
*  $ED Descrição da função
*     Preenche as listas de mãos de jogadores
*     retirando cartas aleatórias da lista "baralho".
*
*  $EP Parâmetros
*     pBaralho  - ponteiro para a lista de listas que contém
*                 a lista "baralho" onde estará armazenada o 
*                 baralho com 40 cartas embaralhadas.
*
*  $FV Valor retornado
*     MES_CondRetOK
*     MES_CondRetNaoDistribuiuMaos
*
***********************************************************************/

void MES_DistribuirMaos( LIS_tppLista pBaralho ) ;

/***********************************************************************
*
*  $FC Função: MES  &Definir quem começa
*
*  $ED Descrição da função
*     Define qual jogador começará a rodada.
*
*  $EP Parâmetros
*     //não faço ideia
*
*  $FV Valor retornado
*     MES_CondRetOK
*     MES_CondRetNaoDefiniuQuemComeca
*
***********************************************************************/

void MES_DefinirQuemComeca(  ) ;

/***********************************************************************
*
*  $FC Função: MES  &Atualizar pontuação rodada
*
*  $ED Descrição da função
*     Atualiza o placar da rodada em execução.
*
*  $EP Parâmetros
*     //não faço ideia
*
*  $FV Valor retornado
*     MES_CondRetOK
*     MES_CondRetNaoAtualizouPontuacaoRodada
*
***********************************************************************/

void MES_AtualizarPontuacaoRodada(  ) ;

/***********************************************************************
*
*  $FC Função: MES  &Checar pontuação rodada
*
*  $ED Descrição da função
*     Checa a pontuação da rodada para saber 
*     se a rodada terminou.
*
*  $EP Parâmetros
*     //não faço ideia
*
*  $FV Valor retornado
*     MES_CondRetOK
*     MES_CondRetNaoChecouPontuacaoRodada
*
***********************************************************************/

void MES_ChecarPontuacaoRodada(  ) ;

/***********************************************************************
*
*  $FC Função: MES  &Atualizar pontuação partida
*
*  $ED Descrição da função
*     Atualiza o placar da partida.
*
*  $EP Parâmetros
*     //não faço ideia
*
*  $FV Valor retornado
*     MES_CondRetOK
*     MES_CondRetNaoAtualizouPontuacaoPartida
*
***********************************************************************/

void MES_AtualizarPontuacaoPartida(  ) ;

/***********************************************************************
*
*  $FC Função: MES  &Checar pontuação partida
*
*  $ED Descrição da função
*     Checa a pontuação da partida para saber 
*     se a partida terminou.
*
*  $EP Parâmetros
*     //não faço ideia
*
*  $FV Valor retornado
*     MES_CondRetOK
*     MES_CondRetNaoChecouPontuacaoPartida
*
***********************************************************************/

void MES_ChecarPontuacaoPartida(  ) ;

/***********************************************************************
*
*  $FC Função: MES  &Atualizar cartas mesa
*
*  $ED Descrição da função
*     Atualiza a lista "mesa" incluindo nela 
*     as cartas que os jogadores apostarem.
*
*  $EP Parâmetros
*     pBaralho  - ponteiro para a lista de listas que contém
*                 a lista "mesa" onde será armazenada as 
*                 cartas apostadas pelos jogadores.
*
*  $FV Valor retornado
*     MES_CondRetOK
*     MES_CondRetNaoAtualizouCartasMesa
*
***********************************************************************/

void MES_AtualizarCartasMesa( LIS_tppLista pBaralho ) ;

/***********************************************************************
*
*  $FC Função: MES  &Atualizar valor rodada
*
*  $ED Descrição da função
*     Atualiza o valor da rodada em execução. 
*
*  $EP Parâmetros
*     //não faço ideia
*
*  $FV Valor retornado
*     MES_CondRetOK
*     MES_CondRetNaoAtualizouValorRodada
*
***********************************************************************/

void MES_AtualizarValorRodada(  ) ;

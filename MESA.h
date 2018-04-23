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
*     pBaralho  - ponteiro para a lista de listas que contém
*                 a lista "mesa" onde estará armazenada (no 
*                 último elemento da lista) a carta "vira". //ou armazena a carta "manilha"? pra usar pra comparações no código
*
*  $FV Valor retornado
*     MES_CondRetOK
*     MES_CondRetNaoDefiniuVira
*
***********************************************************************/

   void MES_DefinirVira( LIS_tppLista pBaralho ) ;

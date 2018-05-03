/***************************************************************************
*  $MCI Módulo de implementação: TBAR Teste baralho
*
*  Arquivo gerado:              TestBAR.c
*  Letras identificadoras:      TBAR
*
*  Nome da base de software:    Jogo de Truco
*
*  Projeto: Jogo de Truco
*  Gestor:  LES/DI/PUC-Rio
*  Autores: gsc, jvr, tgf
*
*  $HA Histórico de evolução:
*     Versão      Autor       Data        Observações
*     2            gsc     03/mai/2018    feito resettteste e criarbaralho
*     1            gsc     30/abr/2018    início desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Baralho.h"
#include    "Lista.h"

//comandos do TestBAR.c
static const char RESET_BARALHO_CMD             [ ] = "=resetteste" ;
static const char CRIAR_BARALHO_CMD             [ ] = "=criarbaralho"     ;
static const char CRIAR_EMBARALHAR_VETOR_CMD    [ ] = "=criarembaralharvetor"  ;
static const char DESTRUIR_BARALHO_CMD          [ ] = "=destruirbaralho"  ;
static const char DESTRUIR_CARTA_CMD            [ ] = "=destruircarta"  ;

#define FALSE 0
#define TRUE  1

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_BARALHO   10
#define DIM_VALOR        100

//na função strcmp: 0 = equal

LIS_tppLista   vtBaralhos[ DIM_VT_BARALHO ] ;

/*********** PROTÓTIPOS DAS FUNÇÕES ENCAPSULADAS NO MÓDULO ************/

   static void DestruirValor( void * pValor ) ;

   static int ValidarInxLista( int inxLista , int Modo ) ;

/************  CÓDIGO DAS FUNÇÕES EXPORTADAS PELO MÓDULO  *************/

/***********************************************************************
*
*  $FC Função: TBAR &Efetuar comando
*
*  $ED Descrição da função
*     Podem ser criados até 10 baralhos guardados em um vetor, 
*     identificados pelos índices 0 a 10
*
*     Comandos disponíveis:
*
*     =resetteste
*           - anula o vetor de baralho e provoca vazamento de memória.
*
*     =criarbaralho                 inxBaralho
*           - cria um 1 a 10 baralhos que serão armazenados em vtBaralhos[].
*             o ponteiro para essas listas é armazenado nos
*             elementos do vtBaralhos[].
*
*     =criarembaralharvetor
*           - cria um vetor com 40 elementos tpCarta e reorganiza aleatoriamente
*
*     =destruirbaralho              inxBaralho
*           - destrói um baralho (libera um ponteiro pra um tpLista)
*
*     =destruircarta                inxBaralho 
*           - destrói uma carta (libera um ponteiro pra um tpCarta)
*
*     =inselemapos                  inxBaralho  string  CondRetEsp
*     =obtervalorelem               inxBaralho  string  CondretPonteiro
*     =excluirelem                  inxBaralho  CondRetEsp
*     =irinicio                     inxBaralho
*     =irfinal                      inxBaralho
*     =avancarelem                  inxBaralho  numElem CondRetEsp
*
*  $FV Valor retornado
*
*     Comando de teste executou corretamente:
*     TST_tpCondRet    - TST_CondRetOK
*
*     Comando de teste encontrou uma ou mais falhas:
*     TST_tpCondRet    - TST_CondRetErro
*
*     Comando de teste está com a sintaxe em erro:
*     TST_tpCondRet    - TST_CondRetParm
*
*     Comando de teste não se destina ao presente interpretador:
*     TST_tpCondRet    - TST_CondRetNaoExecutou
*
*     Comando de teste não é conhecido:
*     TST_tpCondRet    - TST_CondRetNaoConhec
*
*     Comando de teste não implementado:
*     TST_tpCondRet    - TST_CondRetNaoImplementado
*
*     Faltou memória para executar o comando:
*     TST_tpCondRet    - TST_CondRetMemoria
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int inxBaralho  = -1 ,
          numLidos   = -1 ,
          CondRetEsp = -1  ;

      TST_tpCondRet CondRet ;

      char   StringDado[  DIM_VALOR ] ;
      char * pDado ;

      int ValEsp = -1 ;

      int i ;

      int numElem = -1 ;

      StringDado[ 0 ] = 0 ;

      
      /* RESET TEST */
         
         //se o comando for "resettest":
         if ( strcmp( ComandoTeste , RESET_BARALHO_CMD ) == 0 )
         {
            //preenche o vetor baralho com Null
            for( i = 0 ; i < DIM_VT_BARALHO ; i++ )
            {
               vtBaralhos[ i ] = NULL ;
            } /* for */

            return TST_CondRetOK ;

         } /* fim ativa: Efetuar reset de teste de baralho */

      
      /* CRIAR BARALHO */

         //se o comando for "criarbaralho"
         else if ( strcmp( ComandoTeste , CRIAR_BARALHO_CMD ) == 0 )
         {

            //conta quantos parametros foram declarados
            numLidos = LER_LerParametros( "i" , &inxBaralho ) ;

            //se for diferente de 1 retorna erro de declaração de parametro
            if ( (numLidos != 1) || (! ValidarInxBaralho( inxBaralho , VAZIO )) )
            {
               return TST_CondRetParm ;
            } /* fim if */

            //se for = 1 cria o vetor baralho
            vtBaralhos[ inxBaralho ] = LIS_CriarLista( DestruirValor ) ;

            //retorna TST_CondRetOk ou TST_CondRetErro
            //1 = checa se é ponteiro nulo e 0 = checa se é ponteiro não nulo
            return TST_CompararPonteiroNulo( 1 , vtBaralhos[ inxBaralho ] ,
               "Erro em ponteiro de novo baralho."  ) ;

         } /* fim ativa: Testar CriarBaralho */

      
      /* ESVAZIAR BARALHO */

         //se o comando for "esvaziarbaralho":
         else if ( strcmp( ComandoTeste , DESTRUIR_BARALHO_CMD ) == 0 )
         {

            //conta quantos parametros foram declarados
            numLidos = LER_LerParametros( "i" , &inxVetor ) ;

            //se for diferente de 1 retorna erro de declaração de parametro
            if ( ( numLidos != 1 ) || ( ! ValidarInxBaralho( inxBaralho , NAO_VAZIO )))
            {
               return TST_CondRetParm ;
            } /* fim if */

            LIS_EsvaziarLista( vtBaralhos[ inxBaralho ] ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar Esvaziar baralho */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TBAR &Efetuar comando */


/**************  CÓDIGO DAS FUNÇÕES ENCAPSULADAS NO MÓDULO  ***********/

/***********************************************************************
*
*  $FC Função: TBAR - Destruir valor
*
***********************************************************************/

   void DestruirValor( void * pValor )
   {
      
      free( pValor ) ;
      
   } /* Fim função: TBAR - Destruir valor */


/***********************************************************************
*
*  $FC Função: TBAR - Validar indice de baralho
*
***********************************************************************/

   int ValidarInxBaralho( int inxBaralho , int Modo )
   {

      //checa se o índice declarado tá entre 0 e 9
      if ( ( inxLista <  0 ) || ( inxLista >= DIM_VT_BARALHO ) )
      {
         return FALSE ;
      } /* fim if */
         
      //checa se o Modo é 
      if ( Modo == VAZIO )
      {
         if ( vtBaralhos[ inxBaralho ] != 0 )
         {
            return FALSE ;
         } /* fim if */
      } else
      {
         if ( vtBaralhos[ inxBaralho ] == 0 )
         {
            return FALSE ;
         } /* fim if */
      } /* fim if */
         
      return TRUE ;

   } /* Fim função: TBAR - Validar indice de baralho */

/********** Fim do módulo de implementação: TBAR Teste baralho **********/


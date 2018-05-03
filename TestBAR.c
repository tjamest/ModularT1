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
*     2            gsc     03/mai/2018    início criarbaralho
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
static const char CRIAR_CARTA_CMD               [ ] = "=criarcarta"     ;
static const char CRIAR_MAO_CMD                 [ ] = "=criarmao"     ;
static const char CRIAR_MESA_CMD                [ ] = "=criarmesa"     ;
static const char DESTRUIR_BARALHO_CMD          [ ] = "=destruirbaralho"  ;
static const char DESTRUIR_CARTA_CMD            [ ] = "=destruircarta"  ;
static const char CRIAR_EMBARALHAR_VETOR_CMD    [ ] = "=criarembaralharvetor"  ;

#define FALSE 0
#define TRUE  1

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_BARALHO   10
#define DIM_VALOR        100

//na função strcmp: 0 = equal

LIS_tppLista   vtBaralhos[ DIM_VT_BARALHO ] ;

/*********** PROTÓTIPOS DAS FUNÇÕES ENCAPSULADAS NO MÓDULO ************/

   static BAR_tppCarta CriarEmbaralharVetor(  ) ;

   static void DestruirValor( void * pValor ) ;

   static int ValidarInxBaralho( int inxBaralho ) ;

/************  CÓDIGO DAS FUNÇÕES EXPORTADAS PELO MÓDULO  *************/

/***********************************************************************
*
*  $FC Função: TBAR &Efetuar comando
*
*  $ED Descrição da função
*     Podem ser criados até 10 baralhos guardados em um vetor, 
*     identificados pelos índices 0 a 9
*
*     Comandos disponíveis:
*
*     =resetteste
*           - anula o vetor de baralho e provoca vazamento de memória.
*     =criarbaralho                 <inxBaralho>  <CondRetEsp>
*           - cria um 1 a 10 baralhos que serão armazenados em vtBaralhos[].
*             o ponteiro para essas listas é armazenado nos
*             elementos do vtBaralhos[].
*     =criarcarta                   <inxBaralho>  <int>  <int>  <CondRetEsp>
*           - insere uma carta em um baralho após o elemento corrente.
*     =criarembaralharvetor         <CondRetEsp>
*           - cria um vetor com 40 elementos tpCarta e reorganiza aleatoriamente
*     =destruirbaralho              <inxBaralho>
*           - destrói um baralho (libera um ponteiro pra um tpLista)
*     =destruircarta                <inxBaralho>  
*           - destrói o elemento corrente do baralho (libera um ponteiro pra um tpCarta)
*     =iriniciobaralho              <inxBaralho>  <CondRetEsp>
*     =irfinalbaralho               <inxBaralho>  <CondRetEsp>
*     =avancarelembaralho           <inxBaralho>  <CondRetEsp>
*
*  $FV Valor retornado
*
*     0 Comando de teste executou corretamente:
*     TST_tpCondRet    - TST_CondRetOK
*
*     1 Comando de teste encontrou uma ou mais falhas:
*     TST_tpCondRet    - TST_CondRetErro
*
*     2 Comando de teste está com a sintaxe em erro:
*     TST_tpCondRet    - TST_CondRetParm
*
*     3 Comando de teste não se destina ao presente interpretador:
*     TST_tpCondRet    - TST_CondRetNaoExecutou
*
*     4 Comando de teste não é conhecido:
*     TST_tpCondRet    - TST_CondRetNaoConhec
*
*     5 Comando de teste não implementado:
*     TST_tpCondRet    - TST_CondRetNaoImplementado
*
*     6 Faltou memória para executar o comando:
*     TST_tpCondRet    - TST_CondRetMemoria
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      /* VARIÁVEIS USADAS POR TODOS COMANDOS */
      
      int inxBaralho  = -1 ,
          numLidos   = -1 ,
          CondRetEsp = -1 ,
          valorCarta = -1 ,
          naipeCarta = -1 ;
      
      int i ;

      TST_tpCondRet CondRet ;
      
      LIS_tppLista vtBaralhos[] ; //vtBaralhos armazena ponteiros pro tpLista
      
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
            numLidos = LER_LerParametros( "ii", &inxBaralho, &CondRetEsp ) ;

            //se for diferente de 2 retorna erro de declaração de parametro
            if ( (numLidos != 2) || validarInxBaralho ( inxBaralho ) == 0)
            {
               return TST_CondRetParm ;
            } /* fim if */

            //criarlista retorna ponteiro pra tpLista
            vtBaralhos[ inxBaralho ] = LIS_CriarLista( DestruirValor ) ;

            //retorna TST_CondRetErro se os dois ponteiros forem diferentes
            //retorna TST_CondRetOK se os dois ponteiros forem iguais
            //0 = ponteiro Null
            //1 = ponteiro não-Null
            return TST_CompararPonteiroNulo( 1 , vtBaralhos[ inxBaralho ] ,
               "Erro em ponteiro de novo baralho."  ) ;

         } /* fim ativa: Testar CriarBaralho */
      
      
     /* CRIAR CARTA */

         //se o comando for "criarcarta"
         else if ( strcmp( ComandoTeste , CRIAR_CARTA_CMD ) == 0 )
         {

            //conta quantos parametros foram declarados
            numLidos = LER_LerParametros( "iiii" , &inxBaralho, &valorCarta,
                                         &naipeCarta, &CondRetEsp ) ;

            //se for diferente de 4 retorna erro de declaração de parametro
            if ( (numLidos != 4) || validarInxBaralho ( inxBaralho ) == 0 )
            {
               return TST_CondRetParm ;
            } /* fim if */

            //adiciona uma carta no baralho
            CondRet = LIS_tpCondRet LIS_InserirElementoApos( LIS_tppLista pLista, void * pValor )

         } /* fim ativa: Testar CriarBaralho */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TBAR &Efetuar comando */


/**************  CÓDIGO DAS FUNÇÕES ENCAPSULADAS NO MÓDULO  ***********/

/***********************************************************************
*
*  $FC Função: TBAR - Criar embaralhar vetor
*
***********************************************************************/

   BAR_tppCarta CriarEmbaralharVetor(  )
   {
      
      BAR_tppCarta pVetorEmbaralhado ;
      
   /* carta 4 de ouros */
	   pVetorEmbaralhado[0].valor = 0 ;
	   pVetorEmbaralhado[0].naipe = 0 ; 

	/* carta 4 de espadas */
	   pVetorEmbaralhado[1].valor = 0 ;
	   pVetorEmbaralhado[1].naipe = 1 ; 

	/* carta 4 de copas */
	   pVetorEmbaralhado[2].valor = 0 ;
	   pVetorEmbaralhado[2].naipe = 2 ; 

	/* carta 4 de paus */
	   pVetorEmbaralhado[3].valor = 0 ;
	   pVetorEmbaralhado[3].naipe = 3 ; 

	/* carta 5 de ouros */
	   pVetorEmbaralhado[4].valor = 1 ;
   	pVetorEmbaralhado[4].naipe = 0 ; 

	/* carta 5 de espadas */
	   pVetorEmbaralhado[5].valor = 1 ;
	   pVetorEmbaralhado[5].naipe = 1 ; 

	/* carta 5 de copas */
	   pVetorEmbaralhado[6].valor = 1 ;
	   pVetorEmbaralhado[6].naipe = 2 ; 

	/* carta 5 de paus */
	   pVetorEmbaralhado[7].valor = 1 ;
	   pVetorEmbaralhado[7].naipe = 3 ;

	/* carta 6 de ouros */
	   pVetorEmbaralhado[8].valor = 2 ;
	   pVetorEmbaralhado[8].naipe = 0 ; 

	/* carta 6 de espadas */
	   pVetorEmbaralhado[9].valor = 2 ;
	   pVetorEmbaralhado[9].naipe = 1 ; 

	/* carta 6 de copas */
   	pVetorEmbaralhado[10].valor = 2 ;
	   pVetorEmbaralhado[10].naipe = 2 ; 

	/* carta 6 de paus */
	   pVetorEmbaralhado[11].valor = 2 ;
	   pVetorEmbaralhado[11].naipe = 3 ; 

	/* carta 7 de ouros */
	   pVetorEmbaralhado[12].valor = 3 ;
   	pVetorEmbaralhado[12].naipe = 0 ; 

	/* carta 7 de espadas */
   	pVetorEmbaralhado[13].valor = 3 ;
   	pVetorEmbaralhado[13].naipe = 1 ; 

	/* carta 7 de copas */
   	pVetorEmbaralhado[14].valor = 3 ;
   	pVetorEmbaralhado[14].naipe = 2 ; 

	/* carta 7 de paus */
	   pVetorEmbaralhado[15].valor = 3 ;
	   pVetorEmbaralhado[15].naipe = 3 ; 

	/* carta Q de ouros */
	   pVetorEmbaralhado[16].valor = 4 ;
	   pVetorEmbaralhado[16].naipe = 0 ; 

	/* carta Q de espadas */
	   pVetorEmbaralhado[17].valor = 4 ;
   	pVetorEmbaralhado[17].naipe = 1 ; 

	/* carta Q de copas */
	   pVetorEmbaralhado[18].valor = 4 ;
	   pVetorEmbaralhado[18].naipe = 2 ; 

	/* carta Q de paus */
	   pVetorEmbaralhado[19].valor = 4 ;
	   pVetorEmbaralhado[19].naipe = 3 ; 

	/* carta J de ouros */
	   pVetorEmbaralhado[20].valor = 5 ;
	   pVetorEmbaralhado[20].naipe = 0 ; 

	/* carta J de espadas */
	   pVetorEmbaralhado[21].valor = 5 ;
	   pVetorEmbaralhado[21].naipe = 1 ; 

	/* carta J de copas */
	   pVetorEmbaralhado[22].valor = 5 ;
	   pVetorEmbaralhado[22].naipe = 2 ; 

	/* carta J de paus */
	   pVetorEmbaralhado[23].valor = 5 ;
	   pVetorEmbaralhado[23].naipe = 3 ;

	/* carta K de ouros */
	   pVetorEmbaralhado[24].valor = 6 ;
	   pVetorEmbaralhado[24].naipe = 0 ; 

	/* carta K de espadas */
	   pVetorEmbaralhado[25].valor = 6 ;
	   pVetorEmbaralhado[25].naipe = 1 ; 

	/* carta K de copas */
	   pVetorEmbaralhado[26].valor = 6 ;
	   pVetorEmbaralhado[26].naipe = 2 ; 

	/* carta K de paus */
	   pVetorEmbaralhado[27].valor = 6 ;
	   pVetorEmbaralhado[27].naipe = 3 ; 

	/* carta A de ouros */
	   pVetorEmbaralhado[28].valor = 7 ;
	   pVetorEmbaralhado[28].naipe = 0 ; 

	/* carta A de espadas */
	   pVetorEmbaralhado[29].valor = 7 ;
	   pVetorEmbaralhado[29].naipe = 1 ; 

	/* carta A de copas */
   	pVetorEmbaralhado[30].valor = 7 ;
	   pVetorEmbaralhado[30].naipe = 2 ; 

	/* carta A de paus */
	   pVetorEmbaralhado[31].valor = 7 ;
	     pVetorEmbaralhado[31].naipe = 3 ; 

	/* carta 2 de ouros */
	   pVetorEmbaralhado[32].valor = 8 ;
	   pVetorEmbaralhado[32].naipe = 0 ; 

	/* carta 2 de espadas */
	   pVetorEmbaralhado[33].valor = 8 ;
	   pVetorEmbaralhado[33].naipe = 1 ; 

	/* carta 2 de copas */
	   pVetorEmbaralhado[34].valor = 8 ;
	   pVetorEmbaralhado[34].naipe = 2 ; 

	/* carta 2 de paus */
   	pVetorEmbaralhado[35].valor = 8 ;
	   pVetorEmbaralhado[35].naipe = 3 ; 

	/* carta 3 de ouros */
	   pVetorEmbaralhado[36].valor = 9 ;
	   pVetorEmbaralhado[36].naipe = 0 ; 

	/* carta 3 de espadas */
	   pVetorEmbaralhado[37].valor = 9 ;
	   pVetorEmbaralhado[37].naipe = 1 ; 

	/* carta 3 de copas */
	   pVetorEmbaralhado[38].valor = 9 ;
	   pVetorEmbaralhado[38].naipe = 2 ; 

	/* carta 3 de paus */
	   pVetorEmbaralhado[39].valor = 9 ;
	   pVetorEmbaralhado[39].naipe = 3 ;
	
   /* reorganização aleatória do vetor */
	   for (iSort = 0; iSort < 40; iSort++) {
		   srand( (unsigned)time(NULL) );
		   r = rand() % 40;
		   temp.valor = pVetorEmbaralhado[iSort].valor;
		   temp.naipe = pVetorEmbaralhado[iSort].naipe;
		   pVetorEmbaralhado[iSort].valor = pVetorEmbaralhado[r].valor;
		   pVetorEmbaralhado[iSort].naipe = pVetorEmbaralhado[r].naipe;
		   pVetorEmbaralhado[r].valor = temp.valor;
		   pVetorEmbaralhado[r].naipe = temp.naipe;
	   } /* fim for */

   return pVetorEmbaralhado ;
      
   } /* Fim função: TBAR - Criar embaralhar vetor */


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

   int ValidarInxBaralho( int inxBaralho )
   {

      //checa se o índice declarado tá entre 0 e 9
      if ( ( inxBaralho <  0 ) || ( inxBaralho >= DIM_VT_BARALHO ) )
      {
         return FALSE ;
      } /* fim if */
         
      return TRUE ;

   } /* Fim função: TBAR - Validar indice de baralho */

/********** Fim do módulo de implementação: TBAR Teste baralho **********/


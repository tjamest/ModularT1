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
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Baralho.h"
#include    "Lista.h"

static const char RESET_BARALHO_CMD             [ ] = "=resetteste" ;
static const char CRIAR_BARALHO_CMD             [ ] = "=criarbaralho" ;
static const char CRIAR_CARTA_CMD               [ ] = "=criarcarta" ;
static const char DESTRUIR_BARALHO_CMD          [ ] = "=destruirbaralho" ;
static const char DESTRUIR_CARTA_CMD            [ ] = "=destruircarta" ;
static const char CRIAR_EMBARALHAR_VETOR_CMD    [ ] = "=criarembaralharvetor" ;

#define FALSE 0
#define TRUE  1

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_BARALHO   10
#define DIM_VALOR        100

//armazena ponteiros pro tipo lista
LIS_tppLista vtBaralhos[ DIM_VT_BARALHO ] ;

/************* PROTÓTIPOS DAS FUNÇÕES ENCAPSULADAS NO MÓDULO **************/
   static void DestruirValor( void * pValor ) ;
   static int ValidarInxBaralho( int inxBaralho ) ;
   

/**************  CÓDIGO DAS FUNÇÕES EXPORTADAS PELO MÓDULO  ***************/

/***************************************************************************
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
*     =criarcarta                   <inxBaralho>  <string>  <string>  <CondRetEsp>
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
***************************************************************************/

TST_tpCondRet TST_EfetuarComando( char * ComandoTeste ){

	//VARIÁVEIS USADAS POR TODOS COMANDOS
      
    int inxBaralho = -1 ,
        numLidos   = -1 ,
        CondRetEsp = -1 ,
		i ;

	char * valorCarta;
	char * naipeCarta;

	//RESET TEST
	//se o comando for "resettest":
	if ( strcmp( ComandoTeste , RESET_BARALHO_CMD ) == 0 ){
		//preenche o vetor baralho com Null
		for( i = 0 ; i < DIM_VT_BARALHO ; i++ ){
               vtBaralhos[ i ] = NULL ;
		}
		return TST_CondRetOK ;
	} //fim ativa: Efetuar reset de teste de baralho


	//CRIAR BARALHO
	//se o comando for "criarbaralho"
	else if ( strcmp( ComandoTeste , CRIAR_BARALHO_CMD ) == 0 ){

		//conta quantos parametros foram declarados
		numLidos = LER_LerParametros( "ii", &inxBaralho, &CondRetEsp ) ;

		//se for diferente de 2 retorna erro de declaração de parametro
		if ( (numLidos != 2) || ValidarInxBaralho ( inxBaralho ) == 0){
			return TST_CondRetParm ;
		}

		//criarlista retorna ponteiro pra tpLista
		vtBaralhos[ inxBaralho ] = LIS_CriarLista( DestruirValor ) ;

		//retorna TST_CondRetErro se os dois ponteiros forem diferentes
		//retorna TST_CondRetOK se os dois ponteiros forem iguais
		//0 = ponteiro Null		//1 = ponteiro não-Null
        return TST_CompararPonteiroNulo( 1 , vtBaralhos[ inxBaralho ] ,
							       "Erro em ponteiro de novo baralho."  ) ;

         } //fim ativa: Testar CriarBaralho
      
      
	//CRIAR CARTA
	//se o comando for "criarcarta"
	else if ( strcmp( ComandoTeste , CRIAR_CARTA_CMD ) == 0 ){

		//conta quantos parametros foram declarados
		numLidos = LER_LerParametros( "issi" , &inxBaralho, valorCarta,
                                         naipeCarta, &CondRetEsp ) ;

		//se for diferente de 4 retorna erro de declaração de parametro
        if ( (numLidos != 4) || ValidarInxBaralho ( inxBaralho ) == 0 ){
			return TST_CondRetParm ;
		}

		BAR_tpValorCarta *ValorCarta = &valorCarta;

		//adiciona uma ponteiro pra tpCarta no pValor do elemento da lista
		vtBaralhos[inxBaralho] = BAR_CriarCarta(valorCarta, naipeCarta ) ;

		//adiciona uma carta no baralho
		return TST_CondRetOK ;

	} //fim ativa: Testar CriarCarta

      return TST_CondRetNaoConhec ;

} /**************** Fim função: TBAR &Efetuar comando *******************/


/***************  CÓDIGO DAS FUNÇÕES ENCAPSULADAS NO MÓDULO  **************/

/***************************************************************************
*  $FC Função: TBAR - Validar indice de baralho
***************************************************************************/

   int ValidarInxBaralho( int inxBaralho )
   {

      //checa se o índice declarado tá entre 0 e 9
      if ( ( inxBaralho <  0 ) || ( inxBaralho >= DIM_VT_BARALHO ) )
      {
         return FALSE ;
      }
         
      return TRUE ;

   } /************ Fim função: TBAR &Validar indice baralho ***************/

/********* FIM DO MÓDULO DE IMPLEMENTAÇÃO: TBAR Teste Baralho *************/

/***************************************************************************
*  $MCI Módulo de implementação: BAR  Baralho
*
*  Arquivo gerado:              BARALHO.c
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
***************************************************************************/

#include   <stdio.h>
#include   <stdlib.h>
#include   <string.h>
#include   <malloc.h>
#include   <time.h>

#define BARALHO_OWN
#include "BARALHO.h"
#include "LISTA.h"

#undef BARALHO_OWN

/***** PROTÓTIPOS DAS FUNÇÕES ENCAPSULADAS NO MÓDULO **********************/

static BAR_tppCarta CriarEmbaralharVetor ();

/*****  CÓDIGO DAS FUNÇÕES EXPORTADAS PELO MÓDULO  ************************/

/***************************************************************************
*
*  Função: BAR  &Criar baralho
*
***************************************************************************/

LIS_tppLista BAR_CriarBaralho(BAR_tppCarta pVetorEmbaralhado) {

	//ponteiro pra um tipo cabeca lista
	LIS_tppLista pBaralho = (LIS_tppLista*)(malloc(sizeof(LIS_tppLista))) ;
	//é um ponteiro pra cabeça da lista baralho
	//é o *pValor do primeiro elemento da lista superior
	
	//CriarLista recebe um ponteiro pra função void que aceita void como parametro
	//LIS_tppLista LIS_CriarLista(void ( * ExcluirValor ) ( void * pDado ) )
	
	pBaralho = LIS_CriarLista ( &(pValor), BAR_DestruirCarta );
	
	for (i = 0; i < 40; i++) {
		BAR_tppCarta pValor;
		pValor.valor = pVetorEmbaralhado[i].valor;
		pValor.naipe = pVetorEmbaralhado[i].naipe;
  	LIS_tpCondRet LIS_InserirElementoApos(LIS_tppLista pBaralho , void * pValor ) ;
	} /* fim for */
	
	printf("pValor.valor = %i", pValor.valor); 
	printf("pValor.naipe = %i", pValor.naipe); 
	
  return pBaralho ;
   
} /* Fim função: BAR &Criar baralho ***************************************/


/***************************************************************************
*
*  Função: BAR  &Destruir baralho
*
***************************************************************************/

BAR_tpCondRet BAR_DestruirBaralho(LIS_tppLista pBaralho) {
   return 0;
} /* Fim função: BAR &Destruir baralho ************************************/


/***************************************************************************
*
*  Função: BAR  &Destruir carta
*
***************************************************************************/

BAR_tpCondRet BAR_DestruirCarta(LIS_tppCarta pCarta) {
   return 0;
} /* Fim função: BAR &Destruir baralho ************************************/


/*****  CÓDIGO DAS FUNÇÕES ENCAPSULADAS NO MÓDULO  ************************/

/***************************************************************************
*
*  $FC Função: BAR Criar Vetor Auxiliar Embaralha
*
*  $ED Descrição da função
*     Cria um vetor de 40 elementos tpCarta e insere
*     na lista "baralho" de forma aleatória.
*
*  $FV Valor retornado
*     BAR_tppLista pBaralho: retorna um ponteiro pra um tpLista
*
****************************************************************************/

BAR_tppCarta CriarVetorAuxEmbaralha() {
   
	BAR_tppCarta VetorAux[40] ;
	
	/* carta 4 de ouros */
	VetorAux[0].valor = _4 ;
	VetorAux[0].naipe = Ouros ; 

	/* carta 4 de espadas */
	VetorAux[1].valor = _4 ;
	VetorAux[1].naipe = Espadas ; 

	/* carta 4 de copas */
	VetorAux[2].valor = _4 ;
	VetorAux[2].naipe = Copas ; 

	/* carta 4 de paus */
	VetorAux[3].valor = _4 ;
	VetorAux[3].naipe = Paus ; 

	/* carta 5 de ouros */
	VetorAux[4].valor = _5 ;
	VetorAux[4].naipe = Ouros ; 

	/* carta 5 de espadas */
	VetorAux[5].valor = _5 ;
	VetorAux[5].naipe = Espadas ; 

	/* carta 5 de copas */
	VetorAux[6].valor = _5 ;
	VetorAux[6].naipe = Copas ; 

	/* carta 5 de paus */
	VetorAux[7].valor = _5 ;
	VetorAux[7].naipe = Paus ;

	/* carta 6 de ouros */
	VetorAux[8].valor = _6 ;
	VetorAux[8].naipe = Ouros ; 

	/* carta 6 de espadas */
	VetorAux[9].valor = _6 ;
	VetorAux[9].naipe = Espadas ; 

	/* carta 6 de copas */
	VetorAux[10].valor = _6 ;
	VetorAux[10].naipe = Copas ; 

	/* carta 6 de paus */
	VetorAux[11].valor = _6 ;
	VetorAux[11].naipe = Paus ; 

	/* carta 7 de ouros */
	VetorAux[12].valor = _7 ;
	VetorAux[12].naipe = Ouros ; 

	/* carta 7 de espadas */
	VetorAux[13].valor = _7 ;
	VetorAux[13].naipe = Espadas ; 

	/* carta 7 de copas */
	VetorAux[14].valor = _7 ;
	VetorAux[14].naipe = Copas ; 

	/* carta 7 de paus */
	VetorAux[15].valor = _7 ;
	VetorAux[15].naipe = Paus ; 

	/* carta Q de ouros */
	VetorAux[16].valor = _Q ;
	VetorAux[16].naipe = Paus ; 

	/* carta Q de espadas */
	VetorAux[17].valor = _Q ;
	VetorAux[17].naipe = Espadas ; 

	/* carta Q de copas */
	VetorAux[18].valor = _Q ;
	VetorAux[18].naipe = Copas ; 

	/* carta Q de paus */
	VetorAux[19].valor = _Q ;
	VetorAux[19].naipe = Paus ; 

	/* carta J de ouros */
	VetorAux[20].valor = _J ;
	VetorAux[20].naipe = Ouros ; 

	/* carta J de espadas */
	VetorAux[21].valor = _J ;
	VetorAux[21].naipe = Espadas ; 

	/* carta J de copas */
	VetorAux[22].valor = _J ;
	VetorAux[22].naipe = Copas ; 

	/* carta J de paus */
	VetorAux[23].valor = _J ;
	VetorAux[23].naipe = Paus ;

	/* carta K de ouros */
	VetorAux[24].valor = _K ;
	VetorAux[24].naipe = Ouros ; 

	/* carta K de espadas */
	VetorAux[25].valor = _K ;
	VetorAux[25].naipe = Espadas ; 

	/* carta K de copas */
	VetorAux[26].valor = _K ;
	VetorAux[26].naipe = Copas ; 

	/* carta K de paus */
	VetorAux[27].valor = _K ;
	VetorAux[27].naipe = Paus ; 

	/* carta A de ouros */
	VetorAux[28].valor = _A ;
	VetorAux[28].naipe = Ouros ; 

	/* carta A de espadas */
	VetorAux[29].valor = _A ;
	VetorAux[29].naipe = Espadas ; 

	/* carta A de copas */
	VetorAux[30].valor = _A ;
	VetorAux[30].naipe = Copas ; 

	/* carta A de paus */
	VetorAux[31].valor = _A ;
	VetorAux[31].naipe = Paus ; 

	/* carta 2 de ouros */
	VetorAux[32].valor = _2 ;
	VetorAux[32].naipe = Ouros ; 

	/* carta 2 de espadas */
	VetorAux[33].valor = _2 ;
	VetorAux[33].naipe = Espadas ; 

	/* carta 2 de copas */
	VetorAux[34].valor = _2 ;
	VetorAux[34].naipe = Copas ; 

	/* carta 2 de paus */
	VetorAux[35].valor = _2 ;
	VetorAux[35].naipe = Paus ; 

	/* carta 3 de ouros */
	VetorAux[36].valor = _3 ;
	VetorAux[36].naipe = Ouros ; 

	/* carta 3 de espadas */
	VetorAux[37].valor = _3 ;
	VetorAux[37].naipe = Espadas ; 

	/* carta 3 de copas */
	VetorAux[38].valor = _3 ;
	VetorAux[38].naipe = Copas ; 

	/* carta 3 de paus */
	VetorAux[39].valor = _3 ;
	VetorAux[39].naipe = Paus ;
	
	srand (time(NULL));
	
  	for (int i = 0 ; i < tam ; tam--) {
		BAR_tpCarta carta;	//carta não é um ponteiro pro tipo carta? não deveria ser BAR_tppCarta?
		LIS_tpCondRet condRetLista;

		int random = rand()%tam;

		carta = aux[random];
		
		condRetLista = LIS_InserirElementoApos (pBaralho, carta);

		aux[random] = aux[tam-1];
  	} /* fim for */

return pBaralho ;
   
} /* Fim função: BAR &Criar vetor auxiliar embaralhar **********************/

/************ Fim do módulo de implementação: BAR   Baralho ****************/

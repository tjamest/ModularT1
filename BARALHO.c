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
*  $FC Função: BAR Criar Embaralhar Vetor
*
*  $ED Descrição da função
*     Cria e reordena aleatóriamente um
*     vetor de 40 elementos do tipo Carta.
*
*  $FV Valor retornado
*     BAR_tppCarta pVetorEmbaralhado: retorna um ponteiro pra um vetor de tpCarta
*
****************************************************************************/

BAR_tppCarta CriarVetorAuxEmbaralha() {
   
	BAR_tppCarta VetorAux[40] ;
	
	/* carta 4 de ouros */
	VetorAux[0].valor = 0 ;
	VetorAux[0].naipe = 0 ; 

	/* carta 4 de espadas */
	VetorAux[1].valor = 0 ;
	VetorAux[1].naipe = 1 ; 

	/* carta 4 de copas */
	VetorAux[2].valor = 0 ;
	VetorAux[2].naipe = 2 ; 

	/* carta 4 de paus */
	VetorAux[3].valor = 0 ;
	VetorAux[3].naipe = 3 ; 

	/* carta 5 de ouros */
	VetorAux[4].valor = 1 ;
	VetorAux[4].naipe = 0 ; 

	/* carta 5 de espadas */
	VetorAux[5].valor = 1 ;
	VetorAux[5].naipe = 1 ; 

	/* carta 5 de copas */
	VetorAux[6].valor = 1 ;
	VetorAux[6].naipe = 2 ; 

	/* carta 5 de paus */
	VetorAux[7].valor = 1 ;
	VetorAux[7].naipe = 3 ;

	/* carta 6 de ouros */
	VetorAux[8].valor = 2 ;
	VetorAux[8].naipe = 0 ; 

	/* carta 6 de espadas */
	VetorAux[9].valor = 2 ;
	VetorAux[9].naipe = 1 ; 

	/* carta 6 de copas */
	VetorAux[10].valor = 2 ;
	VetorAux[10].naipe = 2 ; 

	/* carta 6 de paus */
	VetorAux[11].valor = 2 ;
	VetorAux[11].naipe = 3 ; 

	/* carta 7 de ouros */
	VetorAux[12].valor = 3 ;
	VetorAux[12].naipe = 0 ; 

	/* carta 7 de espadas */
	VetorAux[13].valor = 3 ;
	VetorAux[13].naipe = 1 ; 

	/* carta 7 de copas */
	VetorAux[14].valor = 3 ;
	VetorAux[14].naipe = 2 ; 

	/* carta 7 de paus */
	VetorAux[15].valor = 3 ;
	VetorAux[15].naipe = 3 ; 

	/* carta Q de ouros */
	VetorAux[16].valor = 4 ;
	VetorAux[16].naipe = 0 ; 

	/* carta Q de espadas */
	VetorAux[17].valor = 4 ;
	VetorAux[17].naipe = 1 ; 

	/* carta Q de copas */
	VetorAux[18].valor = 4 ;
	VetorAux[18].naipe = 2 ; 

	/* carta Q de paus */
	VetorAux[19].valor = 4 ;
	VetorAux[19].naipe = 3 ; 

	/* carta J de ouros */
	VetorAux[20].valor = 5 ;
	VetorAux[20].naipe = 0 ; 

	/* carta J de espadas */
	VetorAux[21].valor = 5 ;
	VetorAux[21].naipe = 1 ; 

	/* carta J de copas */
	VetorAux[22].valor = 5 ;
	VetorAux[22].naipe = 2 ; 

	/* carta J de paus */
	VetorAux[23].valor = 5 ;
	VetorAux[23].naipe = 3 ;

	/* carta K de ouros */
	VetorAux[24].valor = 6 ;
	VetorAux[24].naipe = 0 ; 

	/* carta K de espadas */
	VetorAux[25].valor = 6 ;
	VetorAux[25].naipe = 1 ; 

	/* carta K de copas */
	VetorAux[26].valor = 6 ;
	VetorAux[26].naipe = 2 ; 

	/* carta K de paus */
	VetorAux[27].valor = 6 ;
	VetorAux[27].naipe = 3 ; 

	/* carta A de ouros */
	VetorAux[28].valor = 7 ;
	VetorAux[28].naipe = 0 ; 

	/* carta A de espadas */
	VetorAux[29].valor = 7 ;
	VetorAux[29].naipe = 1 ; 

	/* carta A de copas */
	VetorAux[30].valor = 7 ;
	VetorAux[30].naipe = 2 ; 

	/* carta A de paus */
	VetorAux[31].valor = 7 ;
	VetorAux[31].naipe = 3 ; 

	/* carta 2 de ouros */
	VetorAux[32].valor = 8 ;
	VetorAux[32].naipe = 0 ; 

	/* carta 2 de espadas */
	VetorAux[33].valor = 8 ;
	VetorAux[33].naipe = 1 ; 

	/* carta 2 de copas */
	VetorAux[34].valor = 8 ;
	VetorAux[34].naipe = 2 ; 

	/* carta 2 de paus */
	VetorAux[35].valor = 8 ;
	VetorAux[35].naipe = 3 ; 

	/* carta 3 de ouros */
	VetorAux[36].valor = 9 ;
	VetorAux[36].naipe = 0 ; 

	/* carta 3 de espadas */
	VetorAux[37].valor = 9 ;
	VetorAux[37].naipe = 1 ; 

	/* carta 3 de copas */
	VetorAux[38].valor = 9 ;
	VetorAux[38].naipe = 2 ; 

	/* carta 3 de paus */
	VetorAux[39].valor = 9 ;
	VetorAux[39].naipe = 3 ;
	
	for (cont = 0; cont < 40; cont++) { 
		srand( (unsigned)time(NULL) );
		r = rand() % 40;
		temp.valor = pVetorEmbaralhado[contcont].valor;
		temp.naipe = pVetorEmbaralhado[cont].naipe;
		pVetorEmbaralhado[cont].valor = pVetorEmbaralhado[r].valor;
		pVetorEmbaralhado[cont].naipe = pVetorEmbaralhado[r].naipe;
		pVetorEmbaralhado[r].valor = temp.valor;
		pVetorEmbaralhado[r].naipe = temp.naipe;
	}
	
	/* assertiva de saída: o vetor deve estar organizado aleatoriamente */
	/*for (i = 0; i<40; i++) {
		printf("\n\npVetorEmbaralhado[%i].valor = %i\n", i, pVetorEmbaralhado[i].valor) ; 
		printf("pVetorEmbaralhado[%i].naipe = %i\n", i, pVetorEmbaralhado[i].naipe) ;
	}*/

return pVetorEmbaralhado ;
   
} /* Fim função: BAR &Criar embaralhar vetor *******************************/


/************ Fim do módulo de implementação: BAR   Baralho ****************/

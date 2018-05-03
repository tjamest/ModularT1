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
   
	BAR_tppCarta pVetorEmbaralhado[40] ;
	
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

	for (i=0; i<40; i++) { /*oque está acontecendo nesse for ?
	, por que vc ta atribuindo o valor para algo dentro do printf?!?!?!?!?!? isso vai printar a linha de comnado*/
		printf("pVetorEmbaralhado[%i].valor = %i\n", (i+1), pVetorEmbaralhado[i].valor);
		printf("pVetorEmbaralhado[%i].naipe = %i\n\n", (i+1), pVetorEmbaralhado[i].naipe);
	}
	
	for ( = 0; iSort < 40; iSort++) { // oque é esse isort? por que tem um nada RECEBENDO O VALOR 0 ????
		srand( (unsigned)time(NULL) );
		r = rand() % 40;
		temp.valor = pVetorEmbaralhado[iSort].valor;
		temp.naipe = pVetorEmbaralhado[iSort].naipe;
		pVetorEmbaralhado[iSort].valor = pVetorEmbaralhado[r].valor;
		pVetorEmbaralhado[iSort].naipe = pVetorEmbaralhado[r].naipe;
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

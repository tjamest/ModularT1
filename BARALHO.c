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

static BAR_tppCarta CriarVetorAux ();

/*****  CÓDIGO DAS FUNÇÕES EXPORTADAS PELO MÓDULO  ************************/

/***************************************************************************
*
*  Função: BAR  &Criar baralho
*
***************************************************************************/

LIS_tppLista BAR_CriarBaralho() {

	//aloca memória pro ponteiro que aponta pra cabeca
	//do baralho (um ponteiro pro tipo lista)
	LIS_tppLista pCabecaBaralho = (LIS_tppLista*)(malloc(sizeof(LIS_tppLista))) ;
	
	//usa o LIS_CriarLista que retorna um ponteiro pra uma lista criada
	//(um ponteiro pra um tipo lista, que é um tipo cabeça de lista)
	pCabecaBaralho = LIS_CriarLista (( * ExcluirValor ) ( void * pDado )) ;
	//não sei o que botar no ExcluirValor nem no pDado
	
	//cria um vetor de 40 elementos tipo carta
	BAR_tppCarta pVetorAux[40] = CriarVetorAux ();
	
	//cria uma variável que armazena a condição de
	//retorno de funções de manipulação da lista
	LIS_tpCondRet condRetLista;
	
	//cria uma variável que armazena o ponteiro pro tipo carta
	BAR_tppCarta pCarta;
	
	srand (time(NULL));
	
	/* solução de vcs */
	//insere 40 elementos no pCabecaBaralho e o valor de
	//cada elemento será um ponteiro pra um tipo Carta
  	for (int i = 0 ; i < 40 ; i++) {
		
		//gera um valor int aleatório entre 0 e 39
		int random = rand()%40;
		
		//pCarta recebe um ponteiro aleatório pra um tipo carta
		pCarta = pVetorAux[random];
		
		//é inserido um elemento na lista Baralho e 
		//seu valor é um ponteiro pra um tipo Carta
		condRetLista = LIS_InserirElementoApos (pCabecaBaralho, pCarta);
		
		//nao entendi
		pVetorAux[random] = pVetorAux[39];	
  	} /* fim for */
	
	/* https://www.clubedohardware.com.br/forums/topic/957532-resolvido-embaralhar-vetor/ */
	/* https://www.cprogressivo.net/2013/03/Como-gerar-numeros-aleatorios-em-C-com-a-rand-srand-e-seed.html */
	/* https://forum.imasters.com.br/topic/312920-código-gerando-numeros-aleatorios-sem-repeti%C3%A7%C3%A3o/ */
	for (int i = 0; i < 40 i++){
		
		/* parte que copiei do site */
		//gera um número aleatorio entre 0 e 39
		int random = rand() % 40 ;

		//um ponteiro pra um tipo Carta recebe um ponteiro pra um tipo Carta
		BAR_tppCarta pCarta = pVetorAux[i] ;
		
		//o ponteiro pra um tipo Carta usado anteriormente recebe agora
		//um ponteiro pra um tipo Carta escolhido aleatoriamente
		vet[i] = pVetorAux[random] ;
		
		//o ponteiro pra um tipo Carta aleatório
		//recebe o ponteiro pra um tipo Carta inicial
		pVetorAux[random] = pCarta ;
		
		//conclusao: as cartas trocaram de lugar no vetor auxiliar
		//ja testei ontem com uma main simples e tinha funcionado
		
		/* minha parte */
		//pCarta recebe um ponteiro pra um tipo Carta do vetor embaralhado
		pCarta = pVetorAux[i];
		
		//é inserido um elemento na lista Baralho e 
		//seu valor é um ponteiro pra um tipo Carta
		condRetLista = LIS_InserirElementoApos (pCabecaBaralho, pCarta);
	}
	
  return pCabecaBaralho ;
   
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

BAR_tppCarta CriarVetorAux() {
   
	BAR_tppCarta pVetorAux[40] ;
	
	/* carta 4 de ouros */
	pVetorAux[0].valor = _4 ;
	pVetorAux[0].naipe = Ouros ; 

	/* carta 4 de espadas */
	pVetorAux[1].valor = _4 ;
	pVetorAux[1].naipe = Espadas ; 

	/* carta 4 de copas */
	pVetorAux[2].valor = _4 ;
	pVetorAux[2].naipe = Copas ; 

	/* carta 4 de paus */
	pVetorAux[3].valor = _4 ;
	pVetorAux[3].naipe = Paus ; 

	/* carta 5 de ouros */
	pVetorAux[4].valor = _5 ;
	pVetorAux[4].naipe = Ouros ; 

	/* carta 5 de espadas */
	pVetorAux[5].valor = _5 ;
	pVetorAux[5].naipe = Espadas ; 

	/* carta 5 de copas */
	pVetorAux[6].valor = _5 ;
	pVetorAux[6].naipe = Copas ; 

	/* carta 5 de paus */
	pVetorAux[7].valor = _5 ;
	pVetorAux[7].naipe = Paus ;

	/* carta 6 de ouros */
	pVetorAux[8].valor = _6 ;
	pVetorAux[8].naipe = Ouros ; 

	/* carta 6 de espadas */
	pVetorAux[9].valor = _6 ;
	pVetorAux[9].naipe = Espadas ;

	/* carta 6 de copas */
	pVetorAux[10].valor = _6 ;
	pVetorAux[10].naipe = Copas ; 

	/* carta 6 de paus */
	pVetorAux[11].valor = _6 ;
	pVetorAux[11].naipe = Paus ; 

	/* carta 7 de ouros */
	pVetorAux[12].valor = _7 ;
	pVetorAux[12].naipe = Ouros ; 

	/* carta 7 de espadas */
	pVetorAux[13].valor = _7 ;
	pVetorAux[13].naipe = Espadas ; 

	/* carta 7 de copas */
	pVetorAux[14].valor = _7 ;
	pVetorAux[14].naipe = Copas ; 

	/* carta 7 de paus */
	pVetorAux[15].valor = _7 ;
	pVetorAux[15].naipe = Paus ; 

	/* carta Q de ouros */
	pVetorAux[16].valor = _Q ;
	pVetorAux[16].naipe = Paus ; 

	/* carta Q de espadas */
	pVetorAux[17].valor = _Q ;
	pVetorAux[17].naipe = Espadas ; 

	/* carta Q de copas */
	pVetorAux[18].valor = _Q ;
	pVetorAux[18].naipe = Copas ; 

	/* carta Q de paus */
	pVetorAux[19].valor = _Q ;
	pVetorAux[19].naipe = Paus ; 

	/* carta J de ouros */
	pVetorAux[20].valor = _J ;
	pVetorAux[20].naipe = Ouros ; 

	/* carta J de espadas */
	pVetorAux[21].valor = _J ;
	pVetorAux[21].naipe = Espadas ; 

	/* carta J de copas */
	pVetorAux[22].valor = _J ;
	pVetorAux[22].naipe = Copas ; 

	/* carta J de paus */
	pVetorAux[23].valor = _J ;
	pVetorAux[23].naipe = Paus ;

	/* carta K de ouros */
	pVetorAux[24].valor = _K ;
	pVetorAux[24].naipe = Ouros ; 

	/* carta K de espadas */
	pVetorAux[25].valor = _K ;
	pVetorAux[25].naipe = Espadas ; 

	/* carta K de copas */
	pVetorAux[26].valor = _K ;
	pVetorAux[26].naipe = Copas ; 

	/* carta K de paus */
	pVetorAux[27].valor = _K ;
	pVetorAux[27].naipe = Paus ; 

	/* carta A de ouros */
	pVetorAux[28].valor = _A ;
	pVetorAux[28].naipe = Ouros ; 

	/* carta A de espadas */
	pVetorAux[29].valor = _A ;
	pVetorAux[29].naipe = Espadas ; 

	/* carta A de copas */
	pVetorAux[30].valor = _A ;
	pVetorAux[30].naipe = Copas ; 

	/* carta A de paus */
	pVetorAux[31].valor = _A ;
	pVetorAux[31].naipe = Paus ; 

	/* carta 2 de ouros */
	pVetorAux[32].valor = _2 ;
	pVetorAux[32].naipe = Ouros ; 

	/* carta 2 de espadas */
	pVetorAux[33].valor = _2 ;
	pVetorAux[33].naipe = Espadas ; 

	/* carta 2 de copas */
	pVetorAux[34].valor = _2 ;
	pVetorAux[34].naipe = Copas ; 

	/* carta 2 de paus */
	pVetorAux[35].valor = _2 ;
	pVetorAux[35].naipe = Paus ; 

	/* carta 3 de ouros */
	pVetorAux[36].valor = _3 ;
	pVetorAux[36].naipe = Ouros ; 

	/* carta 3 de espadas */
	pVetorAux[37].valor = _3 ;
	pVetorAux[37].naipe = Espadas ; 

	/* carta 3 de copas */
	pVetorAux[38].valor = _3 ;
	pVetorAux[38].naipe = Copas ; 

	/* carta 3 de paus */
	pVetorAux[39].valor = _3 ;
	pVetorAux[39].naipe = Paus ;

return pVetorAux[40] ;
   
} /* Fim função: BAR &Criar vetor auxiliar *********************************/

/************ Fim do módulo de implementação: BAR   Baralho ****************/

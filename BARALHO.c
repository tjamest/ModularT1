/***************************************************************************
*  $MCI Módulo de implementação: BAR  Baralho
*
*  Arquivo gerado:              BARALHO.c
*  Letras identificadoras:      BAR
*
*  Projeto: INF 1301 Jogo de Truco
*  Autores: gsc, jvr, tgf
*
*  $HA Histórico de evolução:
*  Versão  	Autor    	Data    	Observações
*     1     gsc, jvr, tgf    19/abr/2018    início desenvolvimento
***************************************************************************/

#include   <stdio.h>
#include   <stdlib.h> 
#include   <string.h>
#include   <malloc.h>
#include   <time.h>

#define BARALHO_OWN
#include "LISTA.h"

#undef BARALHO_OWN


/************ PROTÓTIPOS DAS FUNÇÕES ENCAPSULADAS NO MÓDULO ***************/
//static BAR_tppCarta CriarVetorAux ();
BAR_tppCarta CriarCarta (BAR_tpValorCarta valor, BAR_tpNaipeCarta naipe);


/***********  CÓDIGO DAS FUNÇÕES EXPORTADAS PELO MÓDULO  ******************/

/***************************************************************************
*  Função: BAR  &Criar baralho
***************************************************************************/
LIS_tppLista BAR_CriarBaralho() {

	//aloca memória pro ponteiro que aponta pra cabeca
	//do baralho (um ponteiro pro tipo lista)
	LIS_tppLista pCabecaBaralho = (LIS_tppLista*)(malloc(sizeof(LIS_tppLista))) ;
	
	//usa o LIS_CriarLista que retorna um ponteiro pra uma lista criada
	//(um ponteiro pra um tipo lista, que é um tipo cabeça de lista)
	pCabecaBaralho = LIS_CriarLista (NULL) ;
	//não sei o que botar no pDado
	
	//cria um vetor de 40 elementos que são ponteiros pra tpCarta
	BAR_tppCarta VetorAux[40] ;
	
	//declara uma variável que armazena a condição de
	//retorno de funções de manipulação da lista
	LIS_tpCondRet condRetLista;
	
	//declara uma variável que armazena o ponteiro
	//pro tpCarta que é o elemento do vetor
	BAR_tppCarta pCarta;
	
	//criando o vetor baralho ordenado
	pCarta=CriarCarta(_6,Ouros);
	VetorAux[0] = pCarta;
	
	pCarta=CriarCarta(_7,Ouros);
	VetorAux[1] = pCarta;
	
	pCarta=CriarCarta(_Q,Ouros);
	VetorAux[2] = pCarta;
	
	pCarta=CriarCarta(_J,Ouros);
	VetorAux[3] = pCarta;
	
	pCarta=CriarCarta(_K,Ouros);
	VetorAux[4] = pCarta;
	
	pCarta=CriarCarta(_A,Ouros);
	VetorAux[5] = pCarta;
	
	pCarta=CriarCarta(_2,Ouros);
	VetorAux[6] = pCarta;
	
	pCarta=CriarCarta(_3,Ouros);
	VetorAux[7] = pCarta;
	
	//checando se o vetor está preenchido
	printf("VetorAux[1]: Valor: %d / Naipe: %d)",VetorAux[0].valor,VetorAux[0].naipe);
	printf("VetorAux[2]: Valor: %d / Naipe: %d)",VetorAux[1].valor,VetorAux[1].naipe);
	printf("VetorAux[3]: Valor: %d / Naipe: %d)",VetorAux[2].valor,VetorAux[2].naipe);
	
	//função suporte da rand que faz gerar números diferentes sempre
	srand ((unsigned)time(NULL));
	
	// solução de vcs
	//insere 40 elementos no pCabecaBaralho e o valor de
	//cada elemento será um ponteiro pra um tipo Carta
/*  	for (int i = 0 ; i < 40 ; i++) {
		
		//gera um valor int aleatório entre 0 e 39
		int random = rand()%40;
		
		//Carta recebe um tipo ponteiro pro tipo carta
		pCarta = VetorAux[random];
		
		//é inserido um elemento na lista Baralho 
		//e seu valor é um ponteiro pro tipo Carta
		condRetLista = LIS_InserirElementoApos (pCabecaBaralho, pCarta);
		
		//nao entendi
		VetorAux[random] = VetorAux[39];
		
  	} //fim for
	// fim solução de vcs
*/	
	// minha solução
	// parte que copiei do site (embaralhador de vetor)
	// (só renomeei variaveis e alterei tipos)
	for (int i = 0; i < 40; i++){
		
		BAR_tppCarta pCartaAux;
		
		//gera um número aleatorio entre 0 e 39
		int random = rand() % 40 ;

		//um ponteiro pra um tipo Carta recebe um ponteiro pra um tipo Carta
		pCartaAux = VetorAux[i] ;
		
		//o ponteiro pra um tipo Carta usado anteriormente recebe agora
		//um ponteiro pra um tipo Carta escolhido aleatoriamente
		VetorAux[i] = VetorAux[random] ;
		
		//o ponteiro pra um tipo Carta aleatório
		//recebe o ponteiro pra um tipo Carta inicial
		VetorAux[random] = pCartaAux ;
		
	} //fim for
	
	// minha parte
	//preenche um por um usando o vetor embaralhado
	for (int i = 0; i < 40 i++){
		
		//pCarta recebe um ponteiro pra um tipo Carta do vetor embaralhado
		pCarta = VetorAux[i] ;
		
		//é inserido um elemento na lista Baralho e 
		//seu valor é um ponteiro pra um tipo Carta
		condRetLista = LIS_InserirElementoApos (pCabecaBaralho, pCarta) ;
		
	} //fim for
	// fim minha solução
	
  return pCabecaBaralho ;
   
} /***************** Fim função: BAR &Criar baralho ***********************/


/***************************************************************************
*  Função: BAR  &Criar mao
***************************************************************************/
/* IMPLEMENTAR APENAS PARA O T4
LIS_tppLista BAR_CriarMao(LIS_tppLista pCabecaBaralho) {

	//aloca memória pro ponteiro que aponta pra
	//cabeca da mao (um ponteiro pro tipo lista)
	LIS_tppLista pCabecaMao = (LIS_tppLista*)(malloc(sizeof(LIS_tppLista))) ;
	
	//usa o LIS_CriarLista que retorna um ponteiro pra uma lista criada
	//(um ponteiro pra um tipo lista, que é um tipo cabeça de lista)
	pCabecaMao = LIS_CriarLista (( * ExcluirValor ) ( void * pDado )) ;
	//não sei o que botar no pDado
	
	//declara uma variável que armazena a condição de
	//retorno de funções de manipulação da lista
	LIS_tpCondRet condRetLista ;
	
	//declara uma variável que armazena o ponteiro pro tipo carta
	BAR_tppCarta pCarta ;
	
	//insere a ultima carta da lista baralho na
	//lista mao depois a exclui da lista baralho
	for (i = 0; i < 3; i++) {
	
		//vai pro final da lista baralho (ElemCorr = ponteiro pra tpCarta)
		IrFinalLista(pCabecaBaralho) ;
		
		//pCarta recebe o ponteiro pro tpCarta
		pCarta = pCabecaBaralho->pElemCorr->pValor ; //não tenho certeza disso
	
		//cria um elemento na lista mao que tem pValor = ponteiro pro tpCarta
		condRetLista = LIS_InserirElementoApos (pCabecaMao, pCarta) ;
	
		//atualiza o fim da lista na cabeça do baralho
		pCabecaBaralho->pFimLista = pCabecaBaralho->pElemCorr->pAnt

		//o elemento corrente (o último) da lista baralho é excluido
		condRetLista = LIS_ExcluirElemento( pCabecaBaralho ) ;
	
	} //fim for
	
  return pCabecaMao ;
   
} /******************* Fim função: BAR &Criar mao *************************/


/***************************************************************************
*  Função: BAR  &Criar mesa
***************************************************************************/
/* IMPLEMENTAR APENAS PARA O T4
LIS_tppLista BAR_CriarMesa(LIS_tppLista pCabecaBaralho) {

	//aloca memória pro ponteiro que aponta pra
	//cabeca da mao (um ponteiro pro tipo lista)
	LIS_tppLista pCabecaMesa = (LIS_tppLista*)(malloc(sizeof(LIS_tppLista))) ;
	
	//usa o LIS_CriarLista que retorna um ponteiro pra uma lista criada
	//(um ponteiro pra um tipo lista, que é um tipo cabeça de lista)
	pCabecaMesa = LIS_CriarLista (( * ExcluirValor ) ( void * pDado )) ;
	//não sei o que botar no pDado
	
	//declara uma variável que armazena a condição de
	//retorno de funções de manipulação da lista
	LIS_tpCondRet condRetLista ;
	
	//declara uma variável que armazena o ponteiro pro tipo carta
	BAR_tppCarta pCarta ;
	
	//insere a 3 elementos com pValor = Null na lista mesa
	for (i = 0; i < 3; i++) {
	
		//cria um elemento na lista mao que tem pValor = Null
		condRetLista = LIS_InserirElementoApos (pCabecaMesa, NULL) ;
	
		//atualiza o fim da lista na cabeça do baralho
		pCabecaBaralho->pFimLista = pCabecaBaralho->pElemCorr->pAnt

		//o elemento corrente (o último) da lista baralho é excluido
		condRetLista = LIS_ExcluirElemento( pCabecaBaralho ) ;
		
	} //fim for
	
	/* armazenando a vira no quarto elemento da lista mesa */
/*
	//vai pro final da lista baralho (ElemCorr = ponteiro pra tpCarta)
	IrFinalLista(pCabecaBaralho) ;
	
	//pCarta recebe o ponteiro pro tpCarta
	pCarta = pCabecaBaralho->pElemCorr->pValor ; //não tenho certeza disso
	
	//cria um elemento na lista mao que tem pValor = ponteiro pro tpCarta
	condRetLista = LIS_InserirElementoApos (pCabecaMesa, pCarta) ;
	
	//atualiza o fim da lista na cabeça do baralho
	pCabecaBaralho->pFimLista = pCabecaBaralho->pElemCorr->pAnt

	//o elemento corrente (o último) da lista baralho é excluido
	condRetLista = LIS_ExcluirElemento( pCabecaBaralho ) ;
	
  return pCabecaMesa ;

} /********************* Fim função: BAR &Criar mesa ***********************/


/***************************************************************************
*  Função: BAR  &Destruir baralho
***************************************************************************/
void BAR_DestruirBaralho(LIS_tppLista pCabecaBaralho) {
	
	//destruição do ponteiro pro tipo lista
	free(pCabecaBaralho) ;	
	
} /************* Fim função: BAR &Destruir baralho ************************/


/***************************************************************************
*  Função: BAR  &Destruir carta
***************************************************************************/
void BAR_DestruirCarta(BAR_tppCarta pCarta) {
	
	//destruição do ponteiro pro tipo carta
	free(pCarta) ;
	
} /************ Fim função: BAR &Destruir carta ****************************/


/***********  CÓDIGO DAS FUNÇÕES ENCAPSULADAS NO MÓDULO  *******************/

/****************************************************************************
*  $FC Função: BAR Criar Vetor Auxiliar
****************************************************************************/
/*
BAR_tppCarta CriarVetorAux() {
   
	BAR_tppCarta VetorAux[40] ;
		
	// carta 4 de ouros
	VetorAux[0].valor = _4 ;
	VetorAux[0].naipe = Ouros ; 

	// carta 4 de espadas
	VetorAux[1].valor = _4 ;
	VetorAux[1].naipe = Espadas ; 

	// carta 4 de copas
	VetorAux[2].valor = _4 ;
	VetorAux[2].naipe = Copas ; 

	// carta 4 de paus
	VetorAux[3].valor = _4 ;
	VetorAux[3].naipe = Paus ; 

	// carta 5 de ouros
	VetorAux[4].valor = _5 ;
	VetorAux[4].naipe = Ouros ; 

	// carta 5 de espadas
	VetorAux[5].valor = _5 ;
	VetorAux[5].naipe = Espadas ; 

	// carta 5 de copas
	VetorAux[6].valor = _5 ;
	VetorAux[6].naipe = Copas ; 

	// carta 5 de paus
	VetorAux[7].valor = _5 ;
	VetorAux[7].naipe = Paus ;

	// carta 6 de ouros
	VetorAux[8].valor = _6 ;
	VetorAux[8].naipe = Ouros ; 

	// carta 6 de espadas
	VetorAux[9].valor = _6 ;
	VetorAux[9].naipe = Espadas ;

	// carta 6 de copas
	VetorAux[10].valor = _6 ;
	VetorAux[10].naipe = Copas ; 

	// carta 6 de paus
	VetorAux[11].valor = _6 ;
	VetorAux[11].naipe = Paus ; 

	// carta 7 de ouros
	VetorAux[12].valor = _7 ;
	VetorAux[12].naipe = Ouros ; 

	// carta 7 de espadas
	VetorAux[13].valor = _7 ;
	VetorAux[13].naipe = Espadas ; 

	// carta 7 de copas
	VetorAux[14].valor = _7 ;
	VetorAux[14].naipe = Copas ; 

	// carta 7 de paus
	VetorAux[15].valor = _7 ;
	VetorAux[15].naipe = Paus ; 

	// carta Q de ouros
	VetorAux[16].valor = _Q ;
	VetorAux[16].naipe = Paus ; 

	// carta Q de espadas
	VetorAux[17].valor = _Q ;
	VetorAux[17].naipe = Espadas ; 

	// carta Q de copas
	VetorAux[18].valor = _Q ;
	VetorAux[18].naipe = Copas ; 

	// carta Q de paus
	VetorAux[19].valor = _Q ;
	VetorAux[19].naipe = Paus ; 

	// carta J de ouros
	VetorAux[20].valor = _J ;
	VetorAux[20].naipe = Ouros ; 

	// carta J de espadas
	VetorAux[21].valor = _J ;
	VetorAux[21].naipe = Espadas ; 

	// carta J de copas
	VetorAux[22].valor = _J ;
	VetorAux[22].naipe = Copas ; 

	// carta J de paus
	VetorAux[23].valor = _J ;
	VetorAux[23].naipe = Paus ;

	// carta K de ouros
	VetorAux[24].valor = _K ;
	VetorAux[24].naipe = Ouros ; 

	// carta K de espadas
	VetorAux[25].valor = _K ;
	VetorAux[25].naipe = Espadas ; 

	// carta K de copas
	VetorAux[26].valor = _K ;
	VetorAux[26].naipe = Copas ; 

	// carta K de paus
	VetorAux[27].valor = _K ;
	VetorAux[27].naipe = Paus ; 

	// carta A de ouros
	VetorAux[28].valor = _A ;
	VetorAux[28].naipe = Ouros ; 

	// carta A de espadas
	VetorAux[29].valor = _A ;
	VetorAux[29].naipe = Espadas ; 

	// carta A de copas
	VetorAux[30].valor = _A ;
	VetorAux[30].naipe = Copas ; 

	// carta A de paus
	VetorAux[31].valor = _A ;
	VetorAux[31].naipe = Paus ; 

	// carta 2 de ouros
	VetorAux[32].valor = _2 ;
	VetorAux[32].naipe = Ouros ; 

	// carta 2 de espadas
	VetorAux[33].valor = _2 ;
	VetorAux[33].naipe = Espadas ;
	
	// carta 2 de copas
	VetorAux[34].valor = _2 ;
	VetorAux[34].naipe = Copas ; 

	// carta 2 de paus
	VetorAux[35].valor = _2 ;
	VetorAux[35].naipe = Paus ; 

	// carta 3 de ouros
	VetorAux[36].valor = _3 ;
	VetorAux[36].naipe = Ouros ; 

	// carta 3 de espadas
	VetorAux[37].valor = _3 ;
	VetorAux[37].naipe = Espadas ; 

	// carta 3 de copas
	VetorAux[38].valor = _3 ;
	VetorAux[38].naipe = Copas ; 

	// carta 3 de paus
	VetorAux[39].valor = _3 ;
	VetorAux[39].naipe = Paus ;

return *VetorAux ;
   
} /************** Fim função: BAR &Criar vetor auxiliar ********************/

/****************************************************************************
*  $FC Função: BAR  &Criar Carta
****************************************************************************/
BAR_tppCarta CriarCarta (BAR_tpValorCarta valor, BAR_tpNaipeCarta naipe) {

	//declara um ponteiro pra um tipo carta com valor null
	BAR_tpCarta * pCarta = NULL;
	
	//aloca memoria pra esse ponteiro do tamanho do tipo carta
	pCarta = (BAR_tpCarta*) malloc(sizeof(BAR_tpCarta)) ;
	
	//assertiva
	if (pCarta == NULL) {
		return NULL ;
	}
	
	//atribui valor e naipe a um tipo carta
	pCarta->valor = valor ;
	pCarta->naipe = naipe ;
	
	//retorna um ponteiro pra um tipo carta
	return pCarta ;
	
} /******************** Fim função: BAR &Criar Carta ***********************/

/************ FIM DO MÓDULO DE IMPLEMENTAÇÃO: BAR Baralho ******************/

/* Links Interessantes */
// https://www.clubedohardware.com.br/forums/topic/957532-resolvido-embaralhar-vetor/
// https://www.cprogressivo.net/2013/03/Como-gerar-numeros-aleatorios-em-C-com-a-rand-srand-e-seed.html
// https://forum.imasters.com.br/topic/312920-código-gerando-numeros-aleatorios-sem-repetição/

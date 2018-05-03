/***************************************************************************
*  $MCI Módulo de implementação: CAR  Cartas
*
*  Arquivo gerado:              CARTAS.c
*  Letras identificadoras:      CAR
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

#define CARTAS_OWN
#include "CARTAS.h"
#include "LISTA.h"

#undef CARTAS_OWN

/***********************************************************************
*
*  $TC Tipo de dados: CAR Carta do Baralho
*
*
***********************************************************************/

   typedef struct Carta {

         CAR_tpValor	valor ; /* 4, 5, 6, 7, Q, J, K, A, 2, 3,
                              ManilhaOuros, ManilhaEspadas, 
                              ManilhaCopas, ManilhaPaus */

         CAR_tpNaipe	naipe ; /* Ouros, Espadas, Copas, Paus */

   } CAR_tpCarta;

/***** Protótipos das funções encapsuladas no módulo *****/

static CAR_tppBaralho EmbaralharBaralho (LIS_tppLista pBaralho);

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: BAR  &Criar baralho embaralhado
   
   Dúvidas durante a elaboração:
   
1) Se a LIS_CriarLista retorna um tipo "ponteiro pro tipo lista" (LIS_tppLista),
por que a BAR_CriarBaralho retorna uma condição de retorno (BAR_tpCondRet) e não
um "ponteiro pra um tipo lista"?

Assertivas de saida:
Um ponteiro de estrutura tppLista, que possui 40 elementos com estrutura de Tpp

*
***************************************************************************/



LIS_tppLista BAR_CriarBaralho(void) {
   LIS_tppLista pBaralho;
   BAR_tpCarta aux[40];
   int tam = 40;
   
   pBaralho = LIS_CriarLista(NULL);
   
   srand (time(NULL));
   for (int i = 0 ; i < tam ; tam--) {
		BAR_tpCarta carta;
		LIS_tpCondRet condRetLista;

		int random = rand()%tam;

		carta = aux[random];
		if(LIS_QtdElem(pBaralho) <3){
			condRetLista = LIS_InserirElementoApos (pBaralho, carta);
			switch(condRetLista){
			case LIS_CondRetOK:
				printf("ok criado baralho\n ");
				break;
			case LIS_CondRetNaoEncontrou:
				printf("Ponteiro,nao encontrado criar baralho\n");
				break;
			case LIS_CondRetListaVazia:
				printf("A lista esta vazia criar baralho\n");
				break;
			default
				printf("fudeu muito");
			}
		}
		else{
			condRetLista = LIS_AvancarElementoCorrente(pBaralho,1);
			switch(condRetLista){
			case LIS_CondRetOK:
				printf("ok criado baralho\n ");
				break;
			case LIS_CondRetNaoEncontrou:
				printf("Ponteiro,nao encontrado criar baralho\n");
				break;
			case LIS_CondRetListaVazia:
				printf("A lista esta vazia criar baralho\n");
				break;
			default
				printf("fudeu muito");
			}
			condRetLista = LIS_InserirElementoApos (pBaralho, carta);
			switch(condRetLista){
			case LIS_CondRetOK:
				printf("ok criado baralho\n ");
				break;
			case LIS_CondRetNaoEncontrou:
				printf("Ponteiro,nao encontrado criar baralho\n");
				break;
			case LIS_CondRetListaVazia:
				printf("A lista esta vazia criar baralho\n");
				break;
			default
				printf("fudeu muito");
			}

		}

			
		
			
		condRetLista = LIS_InserirElementoApos (pBaralho, carta);

		aux[random] = aux[tam-1];
	}
   
   return pBaralho; 
   
} /* Fim função: BAR &Criar baralho embaralhado

/***************************************************************************
*
*  Função: BAR  &Destruir baralho
***************************************************************************/

void BAR_DestruirBaralho(LIS_tppLista pBaralho) {
	LIS_tpCondRet condRetLista
	
	condRetLista = LIS_DestruirLista (pBaralho);
	
	if (condRetLista != LIS_CondRetOK)
		return BAR_CondRetNaoDestruiuBaralho;
} /* Fim função: BAR &Destruir baralho

/***************************************************************************
*
*  Função: BAR  &Adiciona carta
***************************************************************************/
BAR_tpCarta BAR_AdicionaCarta(BAR_tpValorCarta valor, BAR_tpNaipeCarta naipe) {
	BAR_tpCarta carta;
	
	carta.valor = valor;
	carta.naipe = naipe;
	
	return carta;
}
/* Fim função: BAR &Adiciona carta


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: LIS  -Liberar elemento da lista
*
*  $ED Descrição da função
*     Recebe uma lista (baralho) e reordena a ordem de seus elementos
*     para uma ordem aleatória.
*
***********************************************************************/


} /* Fim função: CAR &Embaralhar baralho


/************ Fim do módulo de implementação: CAR   Cartas ************/

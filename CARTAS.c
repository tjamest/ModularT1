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

#define CARTAS_OWN
#include "CARTAS.h"
#undef CARTAS_OWN

/***********************************************************************
*
*  $TC Tipo de dados: CAR Carta do Baralho
*
*
***********************************************************************/

   typedef struct Carta {

         CAR_ValorCarta	/* Valores: 4, 5, 6, 7, Q, J, K, A, 2, 3, ManilhaOuros, ManilhaEspadas, ManilhaCopas, ManilhaPaus */

         CAR_NaipeCarta	/* Naipes: Ouros, Espadas, Copas, Paus */

   } CAR_tppCarta;

/***** Protótipos das funções encapsuladas no módulo *****/

static CAR_tppBaralho EmbaralharBaralho (LIS_tppLista pBaralho);

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: CAR  &Criar baralho
***************************************************************************/

CAR_tpCondRet CAR_CriarBaralho(LIS_tpLista * pBaralho) {
   
   *pBaralho = (CAR_tppCarta*) malloc (sizeof(CAR_tppCarta)); //aloca espaço do tamanho de uma struct Carta
   
   if (*pBaralho == NULL)
      return CAR_CondRetFaltouMemoria ;
   
   pBaralho = LIS_CriarLista ( &((*pBaralho)->pElemCorr), CAR_DestruirBaralho ) ;
   
   return pBaralho ;
   
} /* Fim função: CAR &Criar baralho

/***************************************************************************
*
*  Função: CAR  &Destruir baralho
***************************************************************************/

void CAR_DestruirBaralho(LIS_tppLista pBaralho) {
   
} /* Fim função: CAR &Destruir baralho


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

CAR_tppBaralho EmbaralharBaralho(LIS_tppLista pBaralho) {
   
} /* Fim função: CAR &Embaralhar baralho


/************ Fim do módulo de implementação: CAR   Cartas ************/

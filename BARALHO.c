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

LIS_tppLista BAR_CriarBaralho(LIS_tppLista pBaralho) {
   
   return pBaralho ;
   
} /* Fim função: BAR &Criar baralho ***************************************/

/***************************************************************************
*
*  Função: BAR  &Destruir baralho
*
***************************************************************************/

BAR_tpCondRet BAR_DestruirBaralho(LIS_tppLista pBaralho) {
   
} /* Fim função: BAR &Destruir baralho ************************************/


/*****  CÓDIGO DAS FUNÇÕES ENCAPSULADAS NO MÓDULO  ************************/

/***************************************************************************
*
*  $FC Função: BAR Criar Embaralhar Vetor
*
*  $ED Descrição da função
*     Cria e reordena aleatóriamente um
*     vetor de 52 elementos do tipo Carta.
*
****************************************************************************/

BAR_tpCarta CriarEmbaralharVetor() {
   
   tpCarta pVetorEmbaralhado[52] ;
   int iElem, iValor, iNaipe, iSort;
	
   for (iElem=0; iElem<52; iElem++) {
	   
      for (iValor=0; iValor<13; iValor++) { 
      pVetorEmbaralhado[iElem].valor = iValor ;   
	      
         for (iNaipe=0; iNaipe<4; iNaipe++) {
            pVetorEmbaralhado[iElem].naipe = iNaipe ;
		 
	 } /* fim for naipe */
      } /* fim for valor */	   
   } /* fim for elem */

   for (iSort = 0; iSort < 52; iSort++) {
      int r = rand() % 52;
      BAR_tpCarta temp = pVetorEmbaralhado[i];
      pVetorEmbaralhado[i] = pVetorEmbaralhado[r];
      pVetorEmbaralhado[r] = temp;
   }

   return pVetorEmbaralhado ;
   
} /* Fim função: BAR &Criar embaralhar vetor *******************************/


/************ Fim do módulo de implementação: BAR   Baralho ****************/

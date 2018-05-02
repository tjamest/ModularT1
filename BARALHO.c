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

BAR_tpCarta CriarEmbaralharVetor() { //ta errada pode desconsiderar tudo abaixo
   
   tpCarta pVetorEmbaralhado[40] ;
   
   for (int i = 0; i < 10; i++)
	{
      srand((unsigned)time(NULL)) ;
      
      //atribuindo valor
		int r = rand() % 10 ;   //sorteia um numero de 0 a 9
		pVetorEmbaralhado[i]->valor = r ;
      
      //atribuindo naipe
      r = rand() % 100 ;      //sorteia um numero de 0 a 99
      
      if (r >= 0 && r < 24) {
         pVetorEmbaralhado[i]->naipe = 0 ;
      }
      else if (r >= 24 && r < 49) {
         pVetorEmbaralhado[i]->naipe = 1 ;
      }
      else if (r >= 49 && r < 74) {
         pVetorEmbaralhado[i]->naipe = 2 ;
      }
      else {
         pVetorEmbaralhado[i]->naipe = 3 ;
      }

   return pVetorEmbaralhado ;
   
} /* Fim função: BAR &Criar embaralhar vetor *******************************/


/************ Fim do módulo de implementação: BAR   Baralho ****************/

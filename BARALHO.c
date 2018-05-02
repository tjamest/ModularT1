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

#define BARALHO_OWN
#include "BARALHO.h"
#include "LISTA.h"

#undef BARALHO_OWN

/***** Protótipos das funções encapsuladas no módulo **********************/

static BAR_tppCarta CriarEmbaralharVetor ();

/*****  Código das funções exportadas pelo módulo  ************************/

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


/*****  Código das funções encapsuladas no módulo  ************************/


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
   
} /* Fim função: BAR &Criar embaralhar vetor *******************************/


/************ Fim do módulo de implementação: BAR   Baralho ****************/

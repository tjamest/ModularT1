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

/***********************************************************************
*
*  $TC Tipo de dados: BAR Carta do Baralho
*
*
***********************************************************************/

   typedef struct Carta {

         int valor ; /* 4, 5, 6, 7, Q, J, K, A, 2, 3,
                              ManilhaOuros, ManilhaEspadas, 
                              ManilhaCopas, ManilhaPaus */

         int naipe ; /* Ouros, Espadas, Copas, Paus */

   } BAR_tpCarta;

/***** Protótipos das funções encapsuladas no módulo *****/

static BAR_tppBaralho EmbaralharBaralho (LIS_tppLista pBaralho);

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: BAR  &Criar baralho
   
   Dúvidas durante a elaboração:
   
1) Se a LIS_CriarLista retorna um tipo "ponteiro pro tipo lista" (LIS_tppLista),
por que a BAR_CriarBaralho retorna uma condição de retorno (BAR_tpCondRet) e não
um "ponteiro pra um tipo lista"?

2) A função BAR_CriarBaralho recebe um "ponteiro pro tipo lista", mas isso pode ser
declarado como (LIS_tpLista * pBaralho) ou (LIS_tppLista pBaralho), qual o correto?
*
***************************************************************************/

//LIS_tppLista BAR_CriarBaralho(LIS_tpLista * pBaralho) { //dúvida 1
//LIS_tppLista BAR_CriarBaralho(LIS_tppLista pBaralho) { //dúvida 2

LIS_tppLista BAR_CriarBaralho(LIS_tppLista pBaralho) {
   
   pBaralho = (BAR_tppCarta*) malloc (sizeof(BAR_tppCarta)); //aloca espaço do tamanho de uma struct Carta
   
   if (pBaralho == NULL)
      return BAR_CondRetFaltouMemoria ;
   
   pBaralho = LIS_CriarLista ( &(*pBaralho), BAR_DestruirBaralho ) ; //ou eh " *pBaralho = " ?
   
   return pBaralho ; //ou eh " *pBaralho " ?
   
} /* Fim função: BAR &Criar baralho

/***************************************************************************
*
*  Função: BAR  &Destruir baralho
***************************************************************************/

void BAR_DestruirBaralho(LIS_tppLista pBaralho) {
   
} /* Fim função: BAR &Destruir baralho


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

BAR_tppBaralho EmbaralharBaralho(LIS_tppLista pBaralho) {
   
} /* Fim função: BAR &Embaralhar baralho


/************ Fim do módulo de implementação: BAR   Baralho ************/

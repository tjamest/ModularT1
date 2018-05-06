/***************************************************************************
*  $MCI Módulo de implementação: MES  Mesa
*
*  Arquivo gerado:              MESA.c
*  Letras identificadoras:      MES
*
*  Nome da base de software:    Truco
*  Arquivo da base de software: 
*
*  Projeto: INF 1301 - Jogo de Truco
*  Autores: gsc, jvr, tgf
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1       avs   23/abr/2018 início desenvolvimento
*
***************************************************************************/

#include   <stdio.h>

#define MESA_OWN
#include "BARALHO.h"
#include "LISTA.h"
#undef MESA_OWN

/***** Protótipos das funções encapsuladas no módulo *****/

/*   static void LiberarElemento( LIS_tppLista   pLista ,
                                tpElemLista  * pElem   ) ;

   static tpElemLista * CriarElemento( LIS_tppLista pLista ,
                                       void *       pValor  ) ;

static void LimparCabeca( LIS_tppLista pLista ) ;       */

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: MES  &Definir vira
****************************************************************************/

   void MES_DefinirVira( LIS_tppLista pUltimoElemMesa ) 
   {
      pUltimoElemMesa->pValor->Valor = //uma carta aleatória do baralho que não
      pUltimoElemMesa->pValor->Naipe = //esteja nas mãos dos jogadores
                                       //tenho qse ctz q essa declaração ta errada
        
      if ( (pUltimoElemMesa->pValor->Valor && pUltimoElemMesa->pValor->Naipe) == /*carta da mão de algum jogador */) 
      {
                 
        
      } /* fim if */
   }/* Fim função: MES &Definir vira */


/***************************************************************************
*  Função: MES  &Criar mao
***************************************************************************/
/* IMPLEMENTAR APENAS PARA O T4
LIS_tppLista MES_CriarMao(LIS_tppLista pCabecaBaralho) {
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
*  Função: MES  &Criar mesa
***************************************************************************/
/* IMPLEMENTAR APENAS PARA O T4
LIS_tppLista MES_CriarMesa(LIS_tppLista pCabecaBaralho) {
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



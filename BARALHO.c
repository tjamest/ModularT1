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
#undef BARALHO_OWN

/***********************************************************************
*
*  $TC Tipo de dados: BAR Carta do Baralho
*
*
***********************************************************************/

   typedef struct Carta {

         BAR_ValorCarta	/* Valores: 4, 5, 6, 7, Q, J, K, A, 2, 3, ManilhaOuros, ManilhaEspadas, ManilhaCopas, ManilhaPaus */

         BAR_NaipeCarta	/* Naipes: Ouros, Espadas, Copas, Paus */

} BAR_tppCarta;

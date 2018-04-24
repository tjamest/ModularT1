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

         BAR_ValorCarta	/* Valores: 4, 5, 6, 7, Q, J, K, A, 2, 3, ManilhaOuros, ManilhaEspadas, ManilhaCopas, ManilhaPaus */

         BAR_NaipeCarta	/* Naipes: Ouros, Espadas, Copas, Paus */

} BAR_tppCarta;

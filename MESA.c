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
     
   } /* Fim função: MES &Definir vira

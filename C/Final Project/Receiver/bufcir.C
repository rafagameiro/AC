/************************************************
 *  bufcir.c
 *
 *  Implementacao de um buffer circular
 *  Interface definida em bufcir.h
 *
 *  (c) 2001 DI-FCT/UNL - Vitor Duarte
 *  ASC I - Lic. Eng. Informatica
 *
 *  rev.: Nov/Dez 2002 - VD
 *  rev.: May 2017 - VD
 ************************************************/

/* se compilado com DEBUG definido sao verificadas assercoes
 * na entrada das operacoes bufPut e bufGet
 */
#define DEBUG

#include "bufcir.h"

#ifndef DEBUG
  #define NDEBUG
#endif

#include <assert.h>


#define BUFSZ  64
/* dimensao do buffer dada por BUFSZ */

BYTE theBuf[BUFSZ];
int put=0, get=0, num=0;


void bufPut( BYTE e )
{
  assert( num<BUFSZ );

  theBuf[put] = e;
  put = (put+1)%BUFSZ;
  num += 1;
}


BYTE bufGet( void )
{
    BYTE c;

    assert( num>0 );

    num -= 1;
    c = theBuf[get];
    get = (get+1)%BUFSZ;
    return c;
}


int bufEmpty( void )
{ return num==0; }


int bufFull( void )
{ return num==BUFSZ; }

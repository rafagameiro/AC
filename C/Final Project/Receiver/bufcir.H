/************************************************
 *  bufcir.h
 *
 *  Interface para um buffer circular
 *  Implementacao em bufcir.c
 *
 *  (c) 2001 DI-FCT/UNL - Vitor Duarte
 *  ASC I - Lic. Eng. Informatica
 *
 *  rev.: Nov. 2002 - VD
 *  rev.: May 2017 - VD
 ************************************************/

/* cada elemento no buffer do tipo BYTE */

typedef unsigned char BYTE;

/* bufPut - poe elemento no buffer (este nao pode estar cheio)
 * bufGet - tira o proximo elemento do buffer (este nao pode estar vazio)
 * bufEmpty - devolve !=0 se buffer vazio
 * bufFull - devolve !=0 se buffer cheio
 */

extern void bufPut( BYTE e );

extern BYTE bufGet( void );

extern int bufEmpty( void );

extern int bufFull( void );

#include <stdio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "bufcir.h"

int counter = 0;
void interrupt(*oldisr)();  /* it will contain the old interruptions of CPU*/

/*
  receives a character from the serial gateway;
*/
unsigned char receiveSerial(){

 unsigned char c;
 char sign = inportb(0x3FD);

 while(!(sign & 1)){
  sign = inportb(0x3FD);
 }

 c = inportb(0x3F8);

 return c;


}

/*
 Sends a byte through the serial gateway;
*/
void sendSerial(unsigned char byte){

  unsigned char sign = inportb(0x3FD);
  sign = sign>>5;
  while(!(sign & 1)){
   sign = inportb(0x3FD);
   sign = sign>>5;
  }

  outportb(0x3F8,byte);

  delay(50);
}

/*
  receives the sent file's content through the serial gateway, and
  it writes the content into the typed file;

  if during the process of transfer, an '\n' is pressed, it will
  print a message with the current number received bytes and
  how far it is from being completed the transfer's process
*/
void getFile(int size, char *filename){
 FILE* file;
 char rec;

 file = fopen(filename,"wb");
 while(counter < size){
  if(kbhit() != 0){
     if(getchar() == '\n'){
      printf("%d sent out of %d\n",counter,size);
     }
  }
  if(!bufEmpty()){
    rec = bufGet();
    fputc(rec,file);
  }
 }
 printf("End of transfer\n");
 fclose(file);
}

/*
  It our personalised interruption;

  when it's activated, it will copy the character, that
  is currently in the serial gateway, to the buffer
  It will increments the counter, telling that
  one of the characters from the file's sent has arrived
*/
void interrupt my_isr(){
 char ch = inportb(0x3F8);
  bufPut(ch);
  counter++;
 outportb(0x20,0x20);
}

/*
  It will put the interruptions of CPU into oldisr, and
  replace with our personalised interrupt;
  Also, it will set some specific bytes at 1's or 0's,
  in some specific registers, MCR, IER and PIC
*/
void initIsr(){
 unsigned char MCR;
 unsigned char IER;
 unsigned char PIC;
 oldisr = getvect(12);
 setvect(12,my_isr);
 MCR = inportb(0x3FC);
 MCR = (MCR | 8);
 outportb(0x3FC,MCR);
 IER = inportb(0x3F9);
 IER = (IER | 1);
 outportb(0x3F9,IER);
 disable();
 PIC = inportb(0x21);
 PIC = (PIC & ~16);
 outportb(0X21,PIC);
 enable();
}

/*
  it will put the changed bits of the registers,
  into its original value
  Also, the oldisr, that now contains the old interrupt of CPU, will
  replace our personalised interrupt
  This way, the system will turn back to normal;
*/
void finishIsr(){
 unsigned char MCR;
 unsigned char IER;
 unsigned char PIC;
 MCR = inportb(0x3FC);
 MCR = (MCR & 247);
 outportb(0x3FC,MCR);
 IER = inportb(0x3F9);
 IER = (IER & 254);
 outportb(0x3F9,IER);
 disable();
 PIC = inportb(0x21);
 PIC = (PIC | 16);
 outportb(0x21,PIC);
 enable();
 setvect(12,oldisr);
}

int main(int argc, char *argv[]){

char *filename = argv[1];    /* contains the name of the file you want */
unsigned char send[20];      /* it will contain the message to be sent to the sender program*/
unsigned char request[50];   /* it will have message sent by the sender program*/
char *answer = "receive";    /* contains the string "receive"*/
char *value;                 /* it will have the size of the file the program will receive*/
unsigned char f;             /* temporarily contains a character send by the sender, through the serial gateway*/
int i = 0;                   /* it will be used to define the beginning and end of the loops*/
int num;                     /* it will contain the size of the file the program will receive*/

	f = receiveSerial();
     while(f != 'z'){
	request[i++] = f;
	f = receiveSerial();
     }
request[i] = '\0';

     while(*answer != '\0'){
       sendSerial( *answer++ );
     }

     for(i = 4;i < strlen(request);i++){
	sendSerial(request[i]);
     }
     sendSerial('z');

     value = (char*)malloc(strlen(request)-4);
     for(i = 5;i<strlen(request);i++){
       value[i-5] = request[i];
     }
num = atoi(value);
     free(value);

initIsr();
getFile(num,filename);
finishIsr();
return 0;
}
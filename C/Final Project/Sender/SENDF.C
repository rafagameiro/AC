#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>

/*
 Send a byte through the serial gateway;
*/
void sendSerial(char byte){

 char sign = inportb(0x3FD);
 sign = sign>>5;

 while ( !(sign & 1)){
    sign = inportb(0x3FD);
    sign = sign>>5;
 }
  outportb(0x3F8,byte);
  delay(50);
}

/*
 Receives a serial from the serial gateway;
*/
unsigned char receiveSerial(void){

 unsigned char c;
 char sign = inportb(0x3FD);

 while(!(sign & 1)){
   sign = inportb(0x3FD);
 }

 c = inportb(0x3F8);

 return c;
}

/*
  Compares the number of bytes,the file has and
  it was sent through the serial gateway, with
  the number of bytes the program got from the
  serial gateway;

  If the number of bytes is the same, then it will
  return 1(sucess), otherwise it will return 0(unsucess);
*/
int compSend(char *received, int num){
   int i;
   int j = 0;
   int val;
   char valChar[10];

   for(i = 8; i < strlen(received);i++){
     valChar[j++] = received[i];
   }
   val = atoi(valChar);
   if(val == num){
    return 1;
   }else{
    return 0;
   }
}

/*
  Sends the file's content through the serial gateway;
*/
void sendFile(char *filename, int bytes){
  FILE *file;
  char *send = (char*) malloc(11);
  int totalSent = 0;
  int sent = 0;
  int i;
  file = fopen(filename,"rb");
  while(totalSent < bytes){
    i = 0;
    sent = fread(send,1,10,file);
    send[sent+1] = '\0';
    while(i < sent){
       sendSerial(send[i++]);
    }
    totalSent += sent;
  }
  fclose(file);
  free(send);
}

int main(int argc, char *argv[]) {

  char *filename = argv[1]; /* contains the name of the file you want to send*/
  char *received;           /* contains the answer sent from the receiver*/
  char *sendMSG = "send ";  /* contains the string "send"*/
  char *conf;               /* it has the size of the file*/
  char lastConf;            /* it will has the character the serial gateway, will receive*/
  long numOfBytes;          /* has the number of bytes, the file has*/
  int i = 0;                /* it will be used to send and receive the strings*/

  struct stat info;
  stat(filename, &info);
  numOfBytes = info.st_size;
  conf = malloc(numOfBytes+1);
  sprintf(conf,"%d",numOfBytes);

  while(*sendMSG != '\0'){
    sendSerial(*sendMSG++);
  }
  while(conf[i] != '\0'){
   sendSerial(conf[i++]);
   }
  sendSerial('z');

  sleep(2);

  i = 0;
  received = malloc(numOfBytes+8);
 lastConf = receiveSerial();
  while(lastConf != 'z'){
     received[i++] = lastConf;
     lastConf = receiveSerial();
  }
  received[i] = '\0';

 if(compSend(received,numOfBytes)){
   sendFile(filename,numOfBytes);
 }

 return 0;
}

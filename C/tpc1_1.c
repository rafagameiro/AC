#include <stdio.h>
#include <string.h>
#define MAXC 32
char expoente[9];
char mantissa[24];

void escreve_IEEE_strings(char sinal, char* expoente, char* mantissa, float valor){

printf("sinal: %c\n", sinal);
printf("expoente: %s\n", expoente);
printf("mantissa: %s\n", mantissa);
printf("valor: %.10f\n", valor);
}

char* getExp(char* array){
int i;
for(i=1;i<9;i++){
    expoente[i - 1] = array[i];
    }
}

char* getMan(char* array){
int i;
for(i = 9; i < strlen(array);i++){
     mantissa[i- 9] = array[i];
    }
}

float getVal(char sinal, char* expoente, char* mantissa){
int sign, i, j;
float value;
if(sinal == '0'){
    sign = 1;
}else{
    sign = -1;
}
int exp = 0;
for(i = 0;i < 9;i++){
    if(expoente[i] == '1'){
        exp += 1<<(7-i);
    }
}
exp = exp - 127;

float man = 0;
for(j = 0;j < 24;j++){
    if(mantissa[j] == '1'){
        man += (1.0/(1<<(j+1)));
    }
}
man = 1 + man;
if(exp<0){
     value = (float) (sign * man * (1.0/(1<<exp)));
}else{
    value = (float) (sign * man * (1<<exp));
}
}

int main(){

char ins[MAXC];

scanf("%s", ins);

char sign = ins[0];
getExp(ins);
getMan(ins);

float value = getVal(sign, expoente, mantissa);

escreve_IEEE_strings(sign,expoente,mantissa,value);

return 0;
}

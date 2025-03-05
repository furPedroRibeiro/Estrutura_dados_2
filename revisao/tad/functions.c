//Implementação das funções descritas no arquivo functions.h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void myhelloWorld(){
  puts("Hello World!!");
}

void myFor(int init, int number_repeat){
  // number_repeat = init+number_repeat; Essa operação deve ser feita para passar o parametro number_repeat para a função
  if(init<number_repeat){
    printf("\nNumber: %i", init);
    myFor(init+1, number_repeat);
    if(init == number_repeat-1){
      puts("");
    }
    printf("\nNumber: %i", init);
  } else{}
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(){
  // puts("--------- Revisando como se implementa um TAD, junto com essa revisao, usarei funcoes recursivas e algumas estruturas de dados ---------");

  myhelloWorld();

  int init, number_repeat;
  int *pinit = &init;

  puts("");
  puts("Digite em que valor comeca a repeticao: ");
  scanf("%i", &init);
  printf("\nPonteiro de init: %p", &init);
  printf("\nValor de init: %i", init);
  *pinit = 10;
  printf("\nValor de init pos mudanca: %i", init);

  puts("\n\nDigite quantas repeticoes deve haver: ");
  scanf("%i", &number_repeat);

  // number_repeat = init+number_repeat; Essa operação deve ser feita para passar o segundo parametro da função myFor()

  number_repeat = init+number_repeat;
  myFor(init, number_repeat);

  return 0;
}
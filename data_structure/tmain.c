#include <stdio.h>
#include <stdlib.h>

#include "single_loop_linkedlist.h"

int main(int argc, char const *argv[]) {
  int data[10] = {95,96,97,98,99,100};
  linklist loopLA = crearray(data, 5);
  printf("loopLA: ");
  printSingleLoopLinkedList(loopLA);

  linklist loopLB = crearray(data, 5);
  printf("loopLB: ");
  printSingleLoopLinkedList(loopLB);

  concat(&loopLA, loopLB);
  printf("loopLA After: ");
  printSingleLoopLinkedList(loopLA);

  // printf("loopLB: ");
  // printSingleLoopLinkedList(loopLB);


  jose(17, 1, 3);
  return 0;
}

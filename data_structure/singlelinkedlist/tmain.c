#include <stdio.h>
#include <stdlib.h>

#include "single_linkedlist.h"

int main(int argc, char const *argv[]) {
	T data = 97;
	linklist A = initLinkedListT(&data,5);
  printf("LinkedList A: \n");
	printSingleLinkedList(A, 1);

	//printf("%d\n", data);
	// int len = length(A);
	// printf("len(A): %d\n", len);

  // insertAtPost(A, 2, 98);
  // printf("After insert:\n");
  // printSingleLinkedList(A, 1);
  //
  // delxy(A);
  // printf("LinkedList deduplicated A: \n");
	// printSingleLinkedList(A, 1);

  // T dataB = 65;
  // linklist B = initLinkedListT(&dataB, 5);
  // printf("LinkedList B: \n");
	// printSingleLinkedList(B, 0);
  // linklist C = mergeList(A, B);
  // printf("LinkedList C: \n");
  // printSingleLinkedList(C, 0);

  T dataB = 99;
  linklist B = initLinkedListT(&dataB, 2);
  printf("LinkedList B: \n");
	printSingleLinkedList(B, 1);

	concat(A, B);
	printf("LinkedList A: \n");
	printSingleLinkedList(A, 1);
	
	selectSortLinkedList(A);
	printf("After sorted A: \n");
	printSingleLinkedList(A, 1);

	// int pos = strpos(A, 2, B);
  // printf("pos=%d\n", pos);

  // inverse2(A);
  // printSingleLinkedList(A, 1);
  // sort(A);
  // printSingleLinkedList(A, 1);

  // data = getPos(A, 2);
  // printf("data=%c\n", data);

  // printf("After delete:\n");
  // delx(A,1);
  // printSingleLinkedList(A, 1);

  // node* node_x = locate(A, 1, 90);
  // if(node_x){
  //   printf("%c\n", node_x->data);
  // }else{
  //   printf("Not found !\n");
  // }

  // int pos_x = locate2(A, 1, 99);
  // if(pos_x){
  //   printf("pos=%d\n", pos_x);
  // }else{
  //   printf("Not found !\n");
  // }


	return 0;
}

#include "single_loop_linkedlist.h"

/*
单循环链表的应用
*/

linklist initBlankLinkedList()
{
    linklist A;
    A.head = mal; // 创建一个head节点
    A.head->next = NULL;
    A.head->data = -1;
    return A;
}

//1 由数组a用尾插法生成单循环链表(h指向表尾)
linklist crearray(T *a, int n)
{
  linklist A = initBlankLinkedList();
  node *r = A.head;
  while(n--){
    r = r->next = mal;
    r->data = *a++;
  }
  r->next = A.head;
  A.head = r;
  return A;
}

//2 输出单循环链表
void printSingleLoopLinkedList(linklist A)
{
  node *p = A.head->next;
  do{
    printf("%d ",(p=p->next)->data);
  }while(p != A.head);
  printf("\n");
}

//3 单循环链表A, B, 将表B连接在表A之后, 保留B表
void concat(linklist *A,linklist B)
{
  node *r = A->head, *p = B.head->next;
  A->head = r->next;

  while((p=p->next) != B.head->next){
    r->next = mal;
    r = r->next;
    r->data = p->data;
  }
  r->next = A->head;
  A->head = r;
}

//4 约瑟夫算法: N个人围成一个圈，从B号开始报数，报数为M的人出局
void jose(int n, int b, int m)
{
  node *r=NULL, *p=NULL;
  int i;
  //n个人围成一个圈
  p = r = mal;
  r->data = 1;
  for(i = 2; i <= n; i++){
    r = r->next = mal;
    r->data = i;
  }
  r->next = p;

  while(--b){
    r = r->next;
  }
  while(n--){
    for(i=1; i < m; i++)r=r->next;
    p = r->next;
    printf("%d ",p->data);
    r->next = p->next;
    free(p);
  }
  printf("\n");
}

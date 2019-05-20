#include <stdio.h>
#include <stdlib.h>

typedef int T;
typedef struct node{
    T data;
    struct node *next;
}node;
typedef struct {
    node* head; //指向head节点
}linklist;

// C++用法
//#define mal new node
//#define free(p) delete p
#define mal (node *)malloc(sizeof(node))

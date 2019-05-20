#include "single_linkedlist.h"

//1. init a blank linked list
linklist initBlankLinkedList()
{
    linklist A;
    A.head = mal; // 创建一个head节点
    A.head->next=0;
    return A;
}

//2. init linkedlist with inserting header(reverse order)
linklist initLinkedListH(T* a, int n)
{
    linklist A = initBlankLinkedList();
    node* r;
    while(n--){
        r=mal;
        r->data=*a;
        *a = *a + 1;
        r->next=A.head->next;
        A.head->next=r;
    }
    return A;
}

//3. init linkedlist with inserting tail(ordering)
linklist initLinkedListT(T* a,int n)
{
    linklist A = initBlankLinkedList();
    node*r = A.head;
    while(n--){
        r=r->next=mal;
        r->data=*a;
        *a = *a + 1;
    }
    r->next=0;
    return A;
}

//4. print linklist
void printSingleLinkedList(linklist A,int f)
{
    node *p=A.head;
    p=p->next;
    while(p){
      if(p->next){
        printf(f?"%c -> ":"%d ",p->data);
      }else{
        printf(f?"%c":"%d ",p->data);
      }
      p = p->next;
    }
    printf("\n");
}

//5. count length of linklist
int length(linklist A)
{
    if(A.head == NULL) return 0;
    node* p = A.head;
    int n = 0;
    p = p->next;
    while(p){
      n++;
      p = p->next;
    }
    return n;
}

//6. get data at index pos
T getPos(linklist A, int pos)
{
    node *p = A.head;
    if(p->next == 0){
        printf("linklist is NULL\n");
        return -1;
    }
    while (pos--){
        p = p->next;
    }
    return p->data;
}

//7. 在pos位置插入元素data
void insertAtPost(linklist A, int pos, T data)
{
    if(A.head->next == 0){
        printf("A is null linklist!\n");
        return;
    }
    if(pos < 1 || pos > length(A)){
        printf("pos is invalid !\n");
        return;
    }
    node *p = A.head;
    while(--pos){
        p = p->next;
    }
    node *r = mal;
    r->data = data;
    r->next = p->next;
    p->next = r;
}

//8. 删除位置pos的元素
void delx(linklist A,int pos)
{
  node *p=A.head, *r;
  while(--pos)p=p->next;
  r=p->next;
  p->next=r->next;
  free(r);
}

//9. 从pos位起查找元素x,返回节点地址
node* locate(linklist A,int pos,T x)
{
  node *p=A.head;
  while(--pos)p=p->next;
  do{
    p = p -> next;
  }while(p && p->data != x);
  return p;
}
//9. 从pos位起查找元素x,返回序号
int locate2(linklist A,int pos,T x)
{
  node *p=A.head;
  int n=pos;
  while(--n)p=p->next;
  p=p->next;
  while(p && p->data != x){
    pos++;
    p=p->next;
  }
  return p>0 ? pos:0;
}

//10. 就地逆置非空表中元素
void inverse(linklist A)
{
  node*p=A.head->next, *q;
  q = p->next;
  while(q){
    p->next=q->next;
    q->next=A.head->next;
    A.head->next=q;
    q = p->next;
  }
}
//10.5 就地逆置表中元素
void inverse2(linklist A)
{
  node*s=A.head->next,*r;
  for(A.head->next=0;s;){
    r=s;
    s=s->next;
    r->next=A.head->next;
    A.head->next=r;
  }
}

//11 就地生成升序表
void sort(linklist A)
{
  node*s,*r,*p,*q;
  for(s=A.head->next,A.head->next=0;s;){
    r=s;
    s=s->next;
    p=A.head;
    do{
      q=p;
      p=q->next;
    }while(p && r->data>p->data);
    q->next=r;
    r->next=p;
  }
}

//12 归并两个升序表，生成一个降序表
linklist mergeList(linklist A, linklist B)
{
  linklist C = initBlankLinkedList();
  node*p=A.head->next,*q=B.head->next,*r;
  while(p && q){
    r=mal;
    if(p->data<q->data){
      r->data=p->data;
      p=p->next;
    }else {
      r->data=q->data;
      q=q->next;
    }
    r->next=C.head->next;
    C.head->next=r;
  }

  while(p){
    r=mal;
    r->data=p->data;
    p=p->next;
    r->next=C.head->next;
    C.head->next=r;
  }

  while(q){
    r=mal;
    r->data=q->data;
    q=q->next;
    r->next=C.head->next;
    C.head->next=r;
  }
  return C;
}

// 13 删除表中重复结点，保留一个
void delxy(linklist A)
{
  node*s=A.head->next,*p=A.head,*r;
  p->next=0;
  while(s){
    r=s;
    s=s->next;
    if(locate(A,1,r->data)==0){
      r->next=p->next;
      p->next=r;
      p=p->next;
    }
  }
}

//14 朴素的模式匹配，A是主串，B是匹配串，从指定位置开始匹配
int strpos(linklist A, int pos, linklist B)
{
  node*p=A.head,*q=B.head,*r=A.head;
  int n=pos;
  while(--n){
    p=p->next;
    r=p;
  }
  while(1){
    while((q=q->next) && (p=p->next) && (p->data==q->data));
    if(p==0)return 0;
    if(q==0)return pos;
    r=r->next;
    p=r;
    q=B.head;
    pos++;
  }
}

//15 链表A，B，将表B连接在表A之后，并保留表B
void concat(linklist A, linklist B)
{
  node *r = A.head, *p = B.head;
  while(r->next)r=r->next;
  while((p=p->next)){
    r->next = mal;
    r = r->next;
    r->data = p->data;
  }
  r->next = 0;
}

//16 单链表上选择排序
void selectSortLinkedList(linklist A)
{
  node *p,*q,*r;
  T t;
  for(q=p=A.head->next; p->next; q=p=p->next){
    for(r=p->next; r; r=r->next){
      if(r->data < q->data)q=r;
    }
    t = p->data;
    p->data = q->data;
    q->data = t;
  }
}

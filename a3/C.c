#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
  unsigned int key;
  struct node *next;
  struct node *prev;
};

typedef struct node * NodePointer;

NodePointer nil;

NodePointer listSearch(int key){
  /* your code */
  NodePointer x;
 
  for(x=nil->next; x!=nil && x->key!=key ; x = x->next);
  
  return x;

}

void init(){
  nil = malloc(sizeof(struct node));
  nil->next = nil;
  nil->prev = nil;
}

void printList(){
  NodePointer cur = nil->next;
  int isf = 1;
  while(1){
    if ( cur == nil ) break;
    if ( isf == 0)  printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
    isf = 0;
  }
  printf("\n");
}
void deleteNode(NodePointer x){
   if ( x == nil ) return;
  NodePointer p = x->prev,n = x->next;
  p->next=x->next;
  n->prev=x->prev;

  free(x);
}

void deleteFirst(){
  NodePointer x = nil->next;
 
  deleteNode(x);
}

void deleteLast(){
  
  NodePointer last=nil->prev;
 
  deleteNode(last);
}



void insert(int key){
  NodePointer x;
  x = malloc(sizeof(struct node));
  x->key = key;
  // your code /
  x->next = nil->next;
  nil->next->prev= x;
  nil->next = x;
  x->prev = nil;
  
}

int main(){
  int key, n, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;
  scanf("%d", &n);
  init();
  
  for ( i = 0; i < n; i++ ){
    scanf("%s%d", com, &key);
    if ( com[0] == 'i' ) {insert(key); np++; size++;}
    else if ( com[0] == 'd' ) {
      if (strlen(com) > 6){
	if ( com[6] == 'F' ) deleteFirst();
	else if ( com[6] == 'L' ) deleteLast();
      } else {
deleteNode(listSearch(key)); nd++; 
      }
      size--;
    }
  }

  printList();
  return 0;
}
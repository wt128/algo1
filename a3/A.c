#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(int);
int pop();

int top=0,a[100];

int main(){
  int x,m,n;
  char s[100];

  while( scanf("%s", s) != EOF ){
    if ( s[0] == '+' ){
       m = pop();
       n= pop();
        push(n+m);
    } else if ( s[0] == '-' ){
     m = pop();
     n= pop();
    push(n-m);
    } else if ( s[0] == '*' ){
        m = pop();
       n= pop();
        push(n*m);
    } else {
      x = atoi(s);
      push(x);
    }
  }
  printf("%d\n",a[top]);
  return 0;
}


void push(int x){
    if(top==100){
        fprintf(stderr,"Overflow!");
        exit(2);
    }
    top++;
    a[top]=x;
    
}

int pop(){
    if(top==0){
        fprintf(stderr,"Underflow!");
        exit(3);
    } 
    top--;
    return a[top+1];
    
}





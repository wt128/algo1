#include <stdio.h>
#include <stdlib.h>
#define LEN 100005

typedef struct pp{
  char name[100];
  int t;
}P;

P Q[LEN+1];
int head=0, tail=0, n;

void enqueue(P x){
    if(head==(tail+1)%LEN){
      fprintf(stderr,"Overflow");
      exit(3);
    }
    Q[tail] = x;
    
    if(tail+1==LEN) tail=0;
    else tail++;
    
    
}

P dequeue(){
    P x=Q[head];
    if(tail==head){
        fprintf(stderr,"UnderFlow!");
        exit(2);
    }
    
    if(head+1==LEN) head=0;
    else head++;
    return x;
}


int main(){
  int elaps = 0, c=0;
  int i, q;
  P u;
  scanf("%d %d", &n, &q);

  for ( i = 1; i <= n; i++){
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].t);

  }
  for(i=1;i<=n;i++)
      enqueue(Q[i]);
     
while (c!=n){
 u = dequeue();
 
  if(q >= u.t){
    elaps=u.t + elaps;
    printf("%s %d\n",u.name,elaps);
    c++;
  
  }
  else{
    elaps += q;
    u.t -= q;
    enqueue(u);
  }

}

  return 0;
}
 
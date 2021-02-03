#include <stdio.h>

#define T 1
#define F -1
#define N 8
int mas[8][8];
int ya[N],ta[N];
int left[2*N],right[2*N];

void mapping(){
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(mas[i][j]!=0){
                if(ya[i]!=j) return;
            }

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(ya[i]==j) printf("Q");
            else printf(".");
        }
        printf("\n");
    }
}
void Checking(int x){
    if(x==N){
        mapping();
        return;
    }
    
    for(int i=0;i<N;i++){
        if(T==ta[i] || T==left[x+i] || T==right[x-i+N-1])
            continue;
        ya[x] = i;
        ta[i] = left[x+i] = right[x-i+N-1] = T;
        Checking(x+1);
        ya[x] = ta[i] = F;
        left[x+i] = right[x-i+N-1] = F;
    }
    }

int main(){
    int k,x,y,i=0,j;
 
    for(;i<N;i++){
        ya[i]=F;
        ta[i]=F;
    }

    for(i=0;i<2*N-1;i++){
        left[i]=F;
        right[i]=F;
    }

    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            mas[i][j]=0;
    scanf("%d",&k);

    for(i=0;i<k;i++){
        scanf("%d%d",&x,&y);
        mas[x][y]=1;
    }
Checking(0);
return 0;
}
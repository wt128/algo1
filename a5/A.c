#include <stdio.h>

int combi(int, int);

int a[20],n;

int main(){
    int i,m,b[200];
    
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(i=0;i<m;i++) scanf("%d",&b[i]);
    for(i=0;i<m;i++){
        if(combi(0,b[i]) == 1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

int combi(int i,int x){
    if(x==0) return 1;
    if(i>=n) return 0;
    if(combi(i+1,x) == 1 || combi(i+1,x-a[i])==1) 
        return 1;
}
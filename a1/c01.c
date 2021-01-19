#include <stdio.h>
#include <math.h>

int prime(int);
int main(){
    int i,n,j=0,ct=0,fl;
    
    int b[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    
    for(i=0;i<n;i++)
         if(prime(b[i])==1) ct++;
    printf("%d\n",ct);
    return 0;
}


int prime(int a){
    int j;
    if(a==2) return 1;
    if(a<2 || a % 2==0 || a >= 100000000) return 0;
        for(j=3;j<=sqrt((double)a);j+=2){
        if(a % j == 0){
            return 0;
        }
    }
    return 1;
}


 
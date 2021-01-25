#include <stdio.h>

int main(){
    int n,i,m,j,b;
    int a[101][101],k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j] = 0;
    for(i=0;i<n;i++){
        scanf("%d%d",&m,&k);
        for(j=1;j<=k;j++){
            scanf("%d",&b);
            a[m][b]=1;
            }

    }
            
            
    
    for(i=1;i<=n;i++){
     for(j=1;j<=n;j++){
         if(j>1) printf(" ");
         if(a[i][j]==0) printf("0");
         else    printf("1");
     }
     printf("\n");}
     
     return 0;
}
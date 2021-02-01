#include <stdio.h>

int main(){
    int i,j,n,sum=0,u=-1;
    int a[100][100],d[100],pi[100],l;
    char color[100];

    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            scanf(" %d",&l);
            if(l==-1) a[i][j]=2001;
            else a[i][j]=l;
        }
        for(i=0;i<n;i++){
            d[i] = 2001;
            pi[i] = -1;
            color[i] = 'w';
        }
   d[0] = 0;
    while (1)
    {
        int min = 2001;
        u=-1;
        for(i=0;i<n;i++)
            if(color[i]!='b' && d[i]<min){
            min = d[i];
            u = i;
            }
        if(u==-1)   break;

        color[u]='b';

        for(j=0;j<n;j++)
            if(color[j]!='b' && a[u][j]!=2001)
                if(a[u][j] < d[j]){
                    d[j] = a[u][j];
                    pi[j] = u;
                    color[j] = 'g';
                }
    }
    for(i=0;i<n;i++)
        if(pi[i]!=-1) sum += a[i][pi[i]];
    
    printf("%d\n",sum);
   
    
    return 0;
}
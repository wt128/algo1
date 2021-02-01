#include <stdio.h>
#define N 100
#define INF 100080
int n,d[N],edge[N][N];
char color[N];

void dij(){
    int i,u;
    
     while (1)
    {
        int min = INF;
        u = -1;
        for(i=0;i<n;i++)
            if(color[i]!='b' && d[i]<min){
            min = d[i];
            u = i;
            }
        if(u == -1)  break;
        color[u]='b';

        for(i=0;i<n;i++)
            if(color[i]!='b' && edge[u][i]!=INF)
                if(edge[u][i] + d[u] < d[i]){
                    d[i] = edge[u][i] + d[u];
                    
                    color[i] = 'g';
                }
    }

}
int main(){
    int i,j,k,l,m,q;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        d[i] = INF;
        color[i] = 'w';
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            edge[i][j]=INF;

    for(i=0;i<n;i++){
        scanf("%d%d",&k,&m);
        for(j=0;j<m;j++){
            scanf("%d%d",&l,&q);
            edge[k][l] = q;
        }
    }
    d[0]=0;
    color[0] = 'g';
    dij();
    for(i=0;i<n;i++){
        printf("%d ",i);
        if(d[i]!=INF) printf("%d",d[i]);
        else printf("-1");
        printf("\n");
    }
    return 0;
}
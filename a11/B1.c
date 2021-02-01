#include <stdio.h>


int n,a[100][100],ct;
int d[100],f[100];
char color[100];

void dfs(int s){
    int i;
    color[s]='G';
    ct++;
    d[s]= ct;
    
    for(i=0;i<n;i++){
        if(a[s][i]==0) continue;
        if(color[i]=='W') dfs(i);

    }
    color[s]='B';
    ct++;
    f[s]=ct;
}

int main(){
    int i,j,k,m,s;
    scanf("%d",&n);

    
    for(i=0;i<n;i++){
        scanf("%d%d",&k,&m);
        k-=1;
       for(j=0;j<m;j++){
           scanf("%d",&s);
           s-=1;
           a[k][s]=1;
       }
    }
    
    for(i=0;i<n;i++) color[i]='W';
    for(i=0;i<n;i++) 
        if(color[i]=='W') dfs(i);
    for(i=0;i<n;i++)
        printf("%d %d %d\n",i+1,d[i],f[i]);
    return 0;
        
        
}
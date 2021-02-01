#include <stdio.h>

int n,a[100][100],ct;
int u,t;
int nx[100],d[100],f[100],sp[100];
char color[100];
//white2
//black3

int next(int u){
    int i=nx[u];
    for(;i<n;i++){
        nx[u] = i+1;
        if(a[u][i]!=0) return i;
    }
    return -1;
}

void stack(int in){
    sp[ct] = in;
    ct++;
}

int pop(){
    if(ct>0) ct--;
    return sp[ct];
    
}

void dfs(int u){
    int v,i;
    for(i=0;i<n;i++) nx[i]=0;
    stack(u);
    color[u] = 'G';
    d[u]=++t;
    
    while (ct>=0)
    {
        int r = pop();
        v = next(r);
        if(v != EOF){
            if(color[v] == 'W'){
                color[v] = 'G';
                d[v] = ++t;
                stack(v);
            }
            else{
                pop();
                color[r] = 'B';
                f[r]=++t;
            }
        }
    }
}

void init(){
    for(int i=0;i<n;i++){
        color[i]='W';
        nx[i]=0;
    }
    t=0;

    for(int j=0;j<n;j++)
        if(color[j]=='W') dfs(j);
   
}


int main(){
    int i,j,k,m,s;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]=0;
    for(i=0;i<n;i++){
        scanf("%d%d",&k,&m);
        k-=1;
       for(j=0;j<m;j++){
           scanf("%d",&s);
           s-=1;
           a[k][s]=1;
       }
    }
    init();
    for(i=0;i<n;i++)
        printf("%d %d %d\n",i+1,d[i],f[i]);
    return 0;
        
        
}
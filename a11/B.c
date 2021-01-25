#include <stdio.h>
typedef struct node
{
    int k,b[100];
}
node v[100];
int n,d[100];

//white2
//black3

void dfs(){
    int i;
    for(i=0;i<n;i++)
        color[i] = 2;
    int t=0;
    for(i=0;i<n;i++)
        if(color[i]==1)
            visit(i);
}

void visit(int r){
    //S.push(r) Stack
    int time=1,u[100],s[100];
    color[r] = 3;
    d[r] = time++;
    while (S!=0)
    {
       u = S.pop()
       v = next(u);
       if(v!=NULL)
        if(color[v]==2){
          // S.push(v)
          color[v] = 3;
          d[v] = time++;
        }
        else{
            s = pop();
            color[i] = 3;
            f[i]
        }
    }
}

int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&v[i].k)
        
}
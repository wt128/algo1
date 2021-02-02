#include <stdio.h>
#define M 100050
typedef struct 
{
    int p,l,r;
}tree;

tree t[M];
int D[M];

void depth(int node,int d){
    
    D[node] = d;
    if(t[node].r != -1) depth(t[node].r,d);
    if(t[node].l != -1) depth(t[node].l,d+1);
}


int main(){
	int i,j,n,m,v,c;
    int left,r;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        t[i].l=-1;t[i].r=-1;t[i].p=-1;
    }
    for(i=0;i<n;i++){
        scanf("%d%d",&v,&m);

        for(j=0;j<m;j++){
            scanf("%d",&c);
            if(j==0) t[v].l = c;
            else t[left].r = c;
            left = c;
            t[c].p = v;
            
        }
    }
    for(i=0;i<n;i++)
       if(t[i].p == -1) r = i;
    
    depth(r,0);

    for(i=0;i<n;i++){

        printf("node %d: parent = %d, depth = %d, ",i,t[i].p,D[i]);
        if(t[i].p == -1) printf("root, ");
        else if(t[i].l == -1) printf("leaf, ");
        else printf("internal node, ");
        printf("[");
        
        for(j=0, c = t[i].l; c != -1; j++, c = t[c].r ){
            if(j>0) printf(", ");
            printf("%d",c);
        }
       printf("]\n");
    }
    

	return 0;
}

#include <stdio.h>
#define M 10008
typedef struct 
{
    int p,l,r;
}tree;

tree t[M];
int dd[M],hh[M];


int height(int x){
  int a=0,b=0;
    if(t[x].l!=-1)
       a = height(t[x].l) + 1;
    if(t[x].r!=-1)
       b = height(t[x].r) + 1;
   
    /*if(b<a) hh[x]=a;
    else hh[x] = b;*/
    return hh[x]=(a>b ? a : b);
}

void depth(int node,int d){

    if(node == -1) return ;
     dd[node] = d;
    depth(t[node].r,d+1);
    depth(t[node].l,d+1);
}



int main(){
	int i,j,n,m,v,c,spc;
    int left,r,suc;
    scanf("%d",&n);
    for(i=0;i<n;i++){
         t[i].l=-1;t[i].r=-1; t[i].p=-1;
    }

    for(i=0;i<n;i++){
        scanf("%d%d%d",&v,&m,&c);
        t[v].l = m;
        t[v].r = c;
        if(m != -1) t[m].p = v;
        if(c != -1) t[c].p = v;
            
        }
    
    for(i=0;i<n;i++)
       if(t[i].p == -1) r = i;
    
    depth(r,0);
    height(r);
    
    for(i=0;i<n;i++){
        suc=0;
        printf("node %d: parent = %d, ",i,t[i].p);
        
        if(t[i].p == -1 ) spc=-1;
        else if(t[t[i].p].r != i && t[t[i].p].r != -1) spc=t[t[i].p].r;
        else if(t[t[i].p].l != i && t[t[i].p].l != -1 ) spc=t[t[i].p].l;
        else spc=-1;

        printf("sibling = %d, ",spc);
        
        if(t[i].r!=-1)suc+=1; if(t[i].l!=-1)suc+=1;
       
       printf("degree = %d, depth = %d, height = %d,",suc,dd[i],hh[i]);

       if(t[i].p == -1) printf(" root\n");
       else if(t[i].l == -1 && t[i].r == -1) printf(" leaf\n");
       else printf(" internal node\n");
    }
    

	return 0;
}


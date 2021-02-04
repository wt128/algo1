#include <stdio.h>

typedef struct 
{
    int l,r,p;
}T;

T tree[25];

void pre(int);
void in(int);
void post(int);

int main(){
    int i,n,x,y,z,root;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        tree[i].p = -1;
    
    for(i=0;i<n;i++){
        scanf("%d%d%d",&x,&y,&z);
        
        tree[x].l = y;
        tree[x].r = z;
        if(y!=-1) tree[y].p=x;
        if(z!=-1) tree[z].p=x;
    }
    for(i=0;i<n;i++)
        if(tree[i].p==-1) root = i;
    printf("Preorder\n");
    pre(root);
    printf("\n");
    printf("Inorder\n");
    in(root);
    printf("\n");
    printf("Postorder\n");
    post(root);
    printf("\n");
    return 0;
     
}

void pre(int i){
    if(i==-1) return;
    
    printf(" %d",i);
    pre(tree[i].l);
    pre(tree[i].r);

}

void in(int i){
    if(i==-1) return;
    in(tree[i].l);
    printf(" %d",i);
    in(tree[i].r);

}

void post(int i){
    if(i==-1) return;
    post(tree[i].l);
    post(tree[i].r);
    printf(" %d",i);
}
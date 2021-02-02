#include <stdio.h>

typedef struct 
{
    char moji;
    int num;
}tru;

tru a[100000];
tru b[100000];
tru L[50001],R[50001];
int partion(int,int);
void quick(int ,int);
void merge(int,int,int);
void sort(int,int);

int main(){
    int i,n,flag=1;
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf(" %c%d",&a[i].moji,&a[i].num);

    for(i=0;i<n;i++)
        b[i]=a[i];

    sort(0,n);
    quick(0,n-1);
    
    for(i=0; i<n ;i++)
         if(a[i].moji != b[i].moji) flag=0;
    if(flag==1) printf("Stable\n");
    else printf("Not stable\n");
    
    for(i=0;i<n;i++)
        printf("%c %d\n",a[i].moji,a[i].num);
    
    
    return 0;
}

int partion(int r,int x){
    int i = r-1,j;
    tru tmp,y=a[x];

    for(j=r;j<x;j++)
        if(a[j].num <= y.num){
        i++;
        tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
        }
    
    tmp=a[i+1];
    a[i+1]=a[x];
    a[x]=tmp;
    
    return i+1;
}

void quick(int l,int r){
    if(l < r){
        int p = partion(l,r);
        quick(l,p-1);
        quick(p+1,r);
    }
}

void merge(int l,int m, int r){
    int n1,n2,i,k,j=0;

    n1 = m - l ;
    n2 = r - m ;  
    for(i=0;i<n1;i++)
        L[i] = b[l+i];
    L[n1].num=1000000001;
    
    for(i=0;i<n2;i++)
        R[i] = b[m+i];
    R[n2].num=1000000001;
    i=0;

    for(k=l;k<r;k++){
        
        if(L[i].num <= R[j].num)
            b[k] = L[i++];
        else
            b[k] = R[j++];
    }
}

void sort(int l, int r){
    int mid;
    if(l+1<r){
        mid = (l+r) / 2;
        sort(l,mid);
        sort(mid,r);
        merge(l,mid,r);      
    }
  
}

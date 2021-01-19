#include <stdio.h>
#include <stdlib.h>
#define M 500000

int L[M/2+2],R[M/2+2];
int ct;
void merge(int a[],int n,int l,int m,int r){
    int n1=m-l;
    int n2 = r-m;
    int i,j=0;
    for(i=0;i<n1;i++) L[i] = a[i+l];
    for(i=0;i<n2;i++) R[i] = a[i+m];
    L[n1]=R[n2]=1000000;
    
    for(int k = l,i=0;k<r;k++){
        ct++;
        if(L[i] <= R[j])
            a[k] = L[i++];
        else
            a[k] = R[j++];
    }
}

void mergesort(int a[],int n,int l,int r){
    if(l+1<r){
        int m=(l+r)/2;
        mergesort(a,n,l,m);
        mergesort(a,n,m,r);
        merge(a,n,l,m,r);
    }
  
    }
    

int main(){
    int a[M],n,i;
    ct=0;
    scanf("%d",&n);
    
    for ( i = 0; i <n; i++)
        scanf("%d",&a[i]);
     mergesort(a,n,0,n);
    for(i=0;i<n;i++){
        if(i==0) printf("%d",a[i]);
        else printf(" %d",a[i]);
    } 
    printf("\n%d\n",ct);
    return 0;
}
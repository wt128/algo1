#include <stdio.h>
#include <stdlib.h>

int L[500000/2+2]; int R[500000/2+2];

int merge(int,int,int);
int sort(int,int);
 int a[500000];
int main(){
    int i,n,res;
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    res = sort(0,n);
    for(i=0;i<n;i++){
        if(i==0) printf("%d",a[i]);
        else printf(" %d",a[i]);
    }
    printf("\n%d\n",res);
    return 0;
}

int merge(int l,int m, int r){
    int n1,n2,i,k,j=0;
    //int* L; int* R;
    static int ct=0;
    n1 = m - l ;
    n2 = r - m ;
  
    
    for(i=0;i<n1;i++)
        L[i] = a[l+i];
    L[n1]=1000000001;
    
    for(i=0;i<n2;i++)
        R[i] = a[m+i];
    R[n2]=1000000001;
    i=0;

    for(k=l;k<r;k++){
        ct++;
        if(L[i] <= R[j]){

            a[k] = L[i++];
            
        }
        else{
            a[k] = R[j++];
            
        }
    } 
    return ct;
}
 


int sort(int l, int r){
    int mid;
    int ct;
    if(l+1<r){
        mid = (l+r) / 2;
        sort(l,mid);
        sort(mid,r);
        ct=merge(l,mid,r);
        
    }
    return ct;
}

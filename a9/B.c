#include <stdio.h>
#define M 500000

int a[M],n;

void maxh(int i){
    int l=2*i;
    int r=2*i+1,largest;
    if(l<=n && a[l]>a[i]) largest=l;
    else largest = i;
    if(r<=n && a[r] > a[largest]) largest = r;

    if(largest != i){
        int tmp=a[i];
        a[i]=a[largest];
        a[largest]=tmp;
        maxh(largest);
    }
}

int main(){
   scanf("%d",&n);
   for(int i=1;i<=n;i++) scanf("%d",a+i);
    
   for(int i=n/2;i>=1;i--)
        maxh(i);
    
    for(int i=1;i<=n;i++){
        
        printf(" %d",a[i]);
    }
    printf("\n");
    return 0;
}
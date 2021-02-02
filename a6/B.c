#include <stdio.h>

int main(){
    int i,n,a[100000],x,r,j,tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    
    r = n-1;
    x = a[r];
    i = -1;
    for(j=0;j<r;j++)
        if(a[j] <= x){
        i++;
        tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
        }
    
    tmp=a[i+1];
    a[i+1]=a[r];
    a[r]=tmp;
    r=i+1;
    for(i=0;i<n;i++){
        if(i==0) printf("%d",a[i]);
        else if(i==r) printf(" [%d]",a[i]);
        else printf(" %d",a[i]);    
    }
    printf("\n");
    return 0;
}

#include <stdio.h>

int main(){
    int i,n;
    int a[251];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++){
        printf("node %d: ",i);
        printf("key = %d, ",a[i]);
        if(i>1) printf("parent key = %d, ",a[i/2]);   
        if(2*i<=n) printf("left key = %d, ",a[2*i]);
        if(2*i+1<=n) printf("right key = %d,",a[2*i + 1]);
        printf("\n");
    }
 return 0;
}
// i=1では左右だけ決める
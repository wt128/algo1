#include <stdio.h>

int a[44];
int func(int n){
    a[0] = 1;
    a[1] = 2;
    for(int i=2;i<n;i++)
        a[i]=a[i-1]+a[i-2];
    return a[n-1];
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",func(n));
    return 0;
}
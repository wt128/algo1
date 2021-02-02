#include <stdio.h>

int a[100000],n;
int binary(int);

int main(){
    int i,b[50000],m,ct=0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
   
    for(i=0;i<m;i++) scanf("%d",&b[i]);
    
    for(i=0;i<m;i++)
        if(binary(b[i]) == 1) ct++;
    
  
    printf("%d\n",ct);
    return 0;
}

int binary(int target){
    int l=0,r;
    int inter;
    r=n;
    while (l<r)
    {
        inter = (l+r) / 2;
        if(target > a[inter]) l = inter+1;
        else if(target == a[inter]) return 1;
        else if(target < a[inter]) r = inter;
    }
    return 0;
    
} 

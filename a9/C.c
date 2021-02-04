#include <stdio.h>

int a[2000001],h;


void maxh(int i){
    int l=2*i;
    int r=2*i+1,largest;
    if(l<=h && a[l]>a[i]) largest=l;
    else largest = i;
    if(r<=h && a[r] > a[largest]) largest = r;

    if(largest != i){
        int tmp=a[i];
        a[i]=a[largest];
        a[largest]=tmp;
        maxh(largest);
    }
}

int ex(){
    int max;
    if(h < 1) return -1;
    max = a[1];
    a[1] = a[h--];
    maxh(1);
    return max;
}

void inck(int i,int k){
    int t;
    if(k < a[i]) return;
    a[i] = k;
    while (i > 1 && a[i / 2] < a[i])
    {
        t = a[i];
        a[i] = a[i/2];
        a[i / 2] = t;
        i = i /2;
    }
    
}

void insert(int k){
    h++;
    a[h] = -1;
    inck(h,k);
}

int main(){
    int k;
    char c[10];

    while (1)
    {
        scanf("%s",c);
        if(c[0]=='e' && c[1]=='n') break;
        if(c[0]=='i'){
            scanf("%d",&k);
            insert(k);
        }
        else printf("%d\n",ex());
    }
    
    return 0;
}
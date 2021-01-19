#include <stdio.h>
typedef struct
{
    char suit,value;
    /* data */
}card;

void bubble(int n,card a[])
{
for(int i=0;i<n;i++)
    for(int j=n-1;j>=i+1;j--){
        if(a[j].value < a[j-1].value){
            card t=a[j];
            a[j]=a[j-1];
            a[j-1]=t;
        }
        
    }
    /* data */
}

void selec(int n,card a[]){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(a[j].value < a[min].value) min=j;

        }
        card t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
}

int main(){
    card s[100],b[100];
    int i;
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf(" %c%c",&b[i].suit,&b[i].value);
    for(i=0;i<n;i++) {
         printf("%c%c\n",b[i].suit,b[i].value);
        s[i]=b[i];
    }

    for(i=0;i<n;i++){
        printf("%c%c\n",s[i].suit,s[i].value);
    }
    bubble(n,b);
    selec(n,s);

    for(i=0;i<n;i++){
        if(i>0) printf(" ");
        printf("%c%c",b[i].suit,b[i].value);
    }
    
     for(i=0;i<n;i++){
        if(i>0) printf(" ");
        printf("%c%c",s[i].suit,s[i].value);
    }
    printf("\n");
    return 0;
}
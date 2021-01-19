#include <stdio.h>

typedef struct{
    char n;
    char h;
}C;

//int stable(C,int);
void selection(C []);
void bubble(C []);
int m;

int main(){
    C b[36],s[36];
    int i,j;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        
        scanf(" %c%c",&b[i].n,&b[i].h);
        
    }
    for(i=0;i<m;i++) s[i]=b[i];

    bubble(b);
    selection(s);

    
    for(i=0;i<m;i++){
        if(i==0) printf("%c%c",b[i].n,b[i].h);
        else printf(" %c%c",b[i].n,b[i].h);
    }
    printf("\nStable\n");
    
 for(i=0;i<m;i++){
        if(i==0) printf("%c%c",s[i].n,s[i].h);
        else printf(" %c%c",s[i].n,s[i].h);
    }
    printf("\n");


    for(i=0; i<m && s[i].n == b[i].n ;i++);
    if(i==m) printf("Stable\n");
    else printf("Not stable\n");
    
    return 0;


}


void selection(C a[]){
    int i,j,min;
    C tmp;
    for(i=0;i<m;i++){
        min=i;
        for(j=i;j<m;j++)
            if(a[j].h < a[min].h)
                min=j;
    
    tmp=a[i];
    a[i]=a[min];
    a[min]=tmp;      
    }
}

void bubble(C a[]){
    int i,j;
    C tmp;
    for(i=0;i<m;i++)
        for(j=m-1;j>=i+1;j--)
            if(a[j].h < a[j-1].h){
                tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
            }
}

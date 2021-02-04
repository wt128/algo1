#include <stdio.h>
#include <string.h>

#define N 1000

int lcs(char *a, char *b){
    int c[N+1][N+1];
    int m = strlen(a),n=strlen(b);
    int max = 0;
    a = ' ' + a;
    b = ' ' + b;
    for(int i=0;i<=m;i++) c[i][0] = 0;
    for(int j=1;j<=n;j++) c[0][j] = 0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            if(a[i]==b[j])
                c[i][j] = c[i-1][j-1] + 1;
            else{
                if(c[i-1][j] < c[i][j-1]) c[i][j] = c[i][j-1];
                else c[i][j] = c[i-1][j];
            }
            if(max<c[i][j]) max = c[i][j];
            
        }

return max;
}

int main(){
    char *x,*y;
    int n,j;
    scanf("%d",&n);
    for(j=0;j<n;j++){
        scanf("%s %s",x,y);
        printf("%d\n",lcs(x,y));
    }
    return 0;
}
#include <stdio.h>

int p[100];
int maxchain(int);

int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d%d",&p[i-1],&p[i]);
    printf("%d\n",maxchain(n));
    return 0;
}

int maxchain(int n){
    int m[100][100],l,k,j,q,i;
    for(int i=1;i<=n;i++)
        m[i][i]=0;
    for(l=2;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            m[i][j]=1000000000;
            for(k=i;k<=j-1;k++){
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if(m[i][j]>q) m[i][j] = q;
            }
        }
    }
        return m[1][n];
}

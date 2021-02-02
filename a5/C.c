#include <stdio.h>
#include <math.h>

typedef struct  {
    double x,y;
}XY;

double rad60 = 60 * M_PI / 180.0;
int koch(int,XY,XY);

int main(){
    int n;
    XY p1={0,0},p2={100,0};

    
    scanf("%d",&n);
    printf("%.8f %.8f\n",p1.x,p1.y);
    if(koch(n,p1,p2)==0)
        printf("%.8f %.8f\n",p2.x,p2.y);

    return 0;
}

int koch(int n,XY p1,XY p2){
    XY s,t,u;

    if(n==0)
        return 0;
    s.x = (p1.x*2 + p2.x) / 3;
    s.y = (p1.y*2 + p2.y) / 3;
    t.x = (p1.x + 2*p2.x) / 3;
    t.y = (p1.y + 2*p2.y) / 3;
    u.x = (t.x - s.x)* cos(rad60) - (t.y - s.y) * sin(rad60) + s.x;
    u.y = (t.x - s.x)* sin(rad60) + (t.y - s.y) * cos(rad60) + s.y;
    koch(n-1,p1,s);
    printf("%.8f %.8f\n",s.x,s.y);
    koch(n-1,s,u);
    printf("%.8f %.8f\n",u.x,u.y);
    koch(n-1,u,t);
    printf("%.8f %.8f\n",t.x,t.y);
    koch(n-1,t,p2);
    
}

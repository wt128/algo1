#include <stdio.h>
#include <string.h>

#define M 1000000/* your task*/
#define L 14

char H[M][L]; /* Hash Table */
int n;
int getChar(char ch){
  if ( ch == 'A') return 1;
  else if ( ch == 'C') return 2;
  else if ( ch == 'G') return 3;
  else if ( ch == 'T') return 4;
}

/* convert a string into an integer value */
long long getKey(char str[]){
  long long sum = 0, p = 1, i;
  for ( i = 0; i < strlen(str); i++ ){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key){ return key % M/* task*/; }
int h2(int key){ return 1 + key % (M-1) /* your task */; }

int find(char str[]){
    long long k;
    int i=0,j;
    k = getKey(str);
    while (1)
    {
         j=(h1(k) + i*h2(k)) % M;
         if(strcmp(H[j],str)==0) return 1;
         else if (strlen(H[j])==0) return 0;
         i++;
    }
    return 0;/* your task */
}

int insert(char str[]){
int i=0,j;
    /* your task */
    long long k= getKey(str);
    
   while (1)
   {
       j=(h1(k) + i*h2(k)) % M;
       if(strcmp(H[j],str)==0) return 1;
       else if(strlen(H[j])==0){
           strcpy(H[j],str);
           return 0;
       }
       i++;
}
return 0;
}

int main(){
    int i,  h;
    char str[L], com[9];
    for ( i = 0; i < M; i++ ) H[i][0] = '\0';
    
    scanf("%d", &n);
    
    for ( i = 0; i < n; i++ ){
	scanf("%s %s", com, str);
    
	if ( com[0] == 'i' ){
	    insert(str);
	} else {
	    if (find(str)){
		printf("yes\n");
	    } else {
		printf("no\n");
	    }
	}
    }

    return 0;
}



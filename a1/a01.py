def insert(a,n):
    for i in range(1,n):
        key=a[i]
        j=i-1
        print(*a)
        while j>=0 and key < a[j]:
            a[j+1]=a[j]
            j-=1
         
        a[j+1]=key
        #print(*a)

n=int(input())
a = list(map(int,input().split()))

insert(a,n)

print(*a)

        
    





    


    

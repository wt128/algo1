def select(a,n):
    ct=0
    for i in range(0,n-1):
        min=i
        for j in range(i,n):
            if a[min]>a[j]:
                min=j
                 
        if i!=min:
            ct+=1    
        a[i],a[min]=a[min],a[i]
          
    print(*a)
    print(ct)

n=int(input())
a=list(map(int,input().split()))

select(a,n)
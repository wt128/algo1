def bubble(a,n):
    ct=0
    flag=1
    u=0
    while flag==1:
        flag=0
        for j in range(n-1,u,-1):
            if a[j-1]>a[j]:
                a[j-1],a[j]=a[j],a[j-1]
                ct+=1
                flag=1
        u+=1  
    print(*a)
    print(ct)

n = int(input())
b = list(map(int,input().split()))
bubble(b,n)
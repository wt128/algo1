n = int(input())

a = [int(input()) for i in range(n)]

ct=0
for i in range(n):
    flag=0
    for j in range(2,a[i]-1):
        if a[i]==2:
            break
        if a[i] % j == 0:
            flag=1
    if(flag==0):
        ct+=1

print(ct)


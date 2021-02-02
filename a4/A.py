n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))
c = 0
for j in range(m):
    key = b[j]
    for i in range(n):
        if key == a[i]:
            break
    if i != n-1:
        c+=1
print(c)
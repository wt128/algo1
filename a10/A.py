def func(n):
    if n == 1 or n==0:
        return 1
    else:
        return func(n-1) + func(n-2)


n = int(input())
f = []
f.append = 1
f.append = 2
for i in range(3,n):
    f[i]=f[i-1]+f[i-2]
print(f[n])


    
n = int(input())
def solve(i,m):
    if m == 0:
        return 1
    if i >=n:
        return 0
    if solve(i+1,m-a[i]) or solve(i+1,m) == 1:
        return 1
    

a = list(map(int,input().split()))
ub = int(input())
b = list(map(int,input().split()))

for j in range(ub):
    if solve(0,b[j]) == 1:
        print("yes")
    else:
        print("no")
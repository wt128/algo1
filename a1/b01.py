def gcd(x,y):

    if y == 0:
        return x
    else:
        return gcd(y, x % y)

a,b=map(int,input().split())
if a > b:
    a,b=b,a
print(gcd(a,b))
        
    





    
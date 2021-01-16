def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)

n = int(input())
a = [int(x) for x in input().split()]
g = a[0]
for x in range(1,n):
    g = gcd(g, a[x])
temp = 0
for x in range(n):
    for y in range(n):
        g1 = gcd(a[x], a[y])
        if(g1 != g):
            temp += 1
ans = temp // n
if(ans == 0):
    print(-1)
else:
    print(ans)
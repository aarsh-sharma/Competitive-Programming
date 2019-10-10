n, k = [int(x) for x in input().split()]
ans = 999999999

for x in range(1, k):
    if(n%x == 0):
        rem = x
        div = n // x
        temp = k*div + rem
        if(temp < ans):
            ans = temp

print(ans)
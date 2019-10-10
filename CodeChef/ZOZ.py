t = int(input())
while t:
    t -= 1
    n, k = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    sum = 0
    ans = 0
    for x in range(n):
        sum += a[x]
    for x in range(n):
        if((a[x]+k)>(sum-a[x])):
            ans += 1
    print(ans)

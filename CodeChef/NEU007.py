t = int(input())
while t:
    t -= 1
    n = int(input())
    a = [int(x) for x in input().split()]
    a.sort()
    for x in range(n-1,0,-1):
        a[x] = a[x] - a[x-1]
    a[0] = 1000000000
    a.sort()
    print(a[0])

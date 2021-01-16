n = int(input())
ans = 0
for x in range(n):
    l, m = [int(x) for x in input().split()]
    if(l + m > ans):
        ans = l + m
print(ans)
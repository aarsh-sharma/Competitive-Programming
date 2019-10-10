n = int(input())
ans = 0
for x in range(n):
    a, b, c = [int(x) for x in input().split()]
    if(a + b + c >= 2):
        ans += 1
print(ans)
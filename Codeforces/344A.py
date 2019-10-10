n = int(input())
a = [None]*n
ans = 1
for x in range(n):
    a[x] = list(input())
for x in range(n-1):
    if(a[x][1] == a[x+1][0]):
        ans += 1
print(ans)
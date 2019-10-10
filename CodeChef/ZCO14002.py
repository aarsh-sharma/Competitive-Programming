n = int(input())
a = [int(x) for x in input().split()]
ans = [None]*n
ans[0] = a[0]
ans[1] = a[1]
ans[2] = a[2]
for x in range(3, n):
	ans[x] = min(ans[x-1], ans[x-2], ans[x-3]) + a[x]
print(min(ans[n-1], ans[n-2], ans[n-3]))
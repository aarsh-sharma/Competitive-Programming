n = int(input())
a = [None]*n
for x in range(n):
	a[x] = int(input())
ans = 0
a.sort(reverse=True)
for x in range(1,n+1):
	temp = a[x-1] * x
	if(temp >= ans):
		ans = temp
print(ans)
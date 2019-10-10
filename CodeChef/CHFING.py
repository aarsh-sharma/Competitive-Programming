t = int(input())
mod = 10**9 + 7
while (t):
	t -= 1
	num, k = [int(x) for x in input().split()]
	ans = k-1
	l = k-num
	a = l%(num-1)
	d = num-1
	n = (l-a)//d + 1
	ans += (n*(a+l))//2
	if (n >= k):
		ans = k-1
	print(ans%mod)

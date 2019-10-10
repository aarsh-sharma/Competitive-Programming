n, q = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
c = [0]*n
c[0] = a[0]
for x in range(1,n):
	c[x] = c[x-1] + a[x]
sum1 = 0
for x in range(q):
	flag = 0
	sum1 += b[x]
	for y in range(n):
		if(sum1<c[y]):
			print(n-y)
			flag = 1
			break
	if(flag == 0):
		sum1 = 0
		print(n)

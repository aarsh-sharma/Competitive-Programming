n, m = [int(x) for x in input().split()]
a = 0
b = []
for x in range(n):
	temp1, temp2 = [int(x) for x in input().split()]
	a += temp1
	b.append(temp1 - temp2)
b.sort(reverse=True)
if(a <= m):
	print(0)
	exit(0)
for x in range(n):
	a -= b[x]
	if(a <= m):
		print(x+1)
		exit(0)
print(-1)
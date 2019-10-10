n, m = [int(x) for x in input().split()]
a = []
for x in range(1, m+1):
	a.append(x)
for x in range(n):
	l, r = [int(x) for x in input().split()]
	for y in range(l, r+1):
		if(y in a):
			a.pop(a.index(y))
print(len(a))
for x in range(len(a)):
	print(a[x], end=" ")

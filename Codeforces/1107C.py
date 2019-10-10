n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
s = input()
dmg = 0
x = 0
while (x < n):
	# print('x is', x)
	idx = x
	for y in range(x+1, n):
		if(s[x] == s[y]):
			idx = y
		else:
			break
	if (x == idx):
		dmg += a[x]
		# print(a[x], 1)
		x += 1
	else:
		b = a[x:idx+1]
		b.sort(reverse=True)
		# print(b)
		for y in range(min(len(b), k)):
			dmg += b[y]
			# print(b[y], 2)
		x = idx + 1
print(dmg)
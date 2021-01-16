n, m = [int(x) for x in input().split()]
s = input()
t = input()
idx = 0
ans = 0
if(m < n - 1):
	print('NO')
	exit(0)
if not '*' in s:
	if(s == t):
		print('YES')
	else:
		print('NO')
	exit(0)
for x in range(n):
	if(s[x] == '*'):
		idx = x
		break
lol = m - (n - idx) + 1
if(s[:idx] == t[:idx] and s[idx+1:] == t[lol:]):
	print('YES')
else:
	print('NO')

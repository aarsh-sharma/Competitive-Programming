n = int(input())
s = list(input())
t = list(input())
s1 = s.copy()
t1 = t.copy()
s1.sort()
t1.sort()
if(s1 != t1):
	print(-1)
	exit(0)
ans = []
for x in range(len(t)):
	if(t[x] == s[x]):
		continue
	flag = 0
	for y in range(x+1, len(t)):
		if(s[y] == t[x]):
			flag = 1
			for z in range(y, x, -1):
				ans.append(z)
				temp = s[z]
				s[z] = s[z-1]
				s[z-1] = temp
				# print(s)
			break
	if (flag == 0):
		print(-1)
		exit(0)
print(len(ans))
for x in range(len(ans)):
	print(ans[x], end=' ')
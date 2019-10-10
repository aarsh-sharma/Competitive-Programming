n, k = [int(x) for x in input().split()]
s = list(input())
s.sort()
# print(s)
ans = ord(s[0]) - ord('a') + 1
j = i = 0
temp = 1
while(temp<k and i < n-1):
	diff = ord(s[i+1]) - ord(s[j])
	if(diff > 1):
		temp += 1
		ans += ord(s[i+1]) - ord('a') + 1
		j = i+1
	i += 1
# print(temp, ans)
if(temp == k):
	print(ans)
else:
	print(-1)
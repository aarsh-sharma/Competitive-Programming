t = int(input())
while t:
	t -= 1
	n = int(input())
	s = input()
	if(len(s) == 2):
		if(s[0] >= s[1]):
			print('NO')
		else:
			print('YES')
			print(2)
			print(s[0], s[1])
	else:
		print('YES')
		print(2)
		print(s[0], s[1:])
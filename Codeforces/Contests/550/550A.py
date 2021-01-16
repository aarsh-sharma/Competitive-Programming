s = input()
length = len(s)
flag = 0

for x in range(length - 1):
	if (flag == 0):
		if (s[x:x+2] == 'AB'):
			flag = 1
	elif (flag == 1):
		flag += 1			
	else:
		if (s[x:x+2] == 'BA'):
			print('YES')
			exit()

flag = 0

for x in range(length - 1):
	if (flag == 0):
		if (s[x:x+2] == 'BA'):
			flag = 1
	elif (flag == 1):
		flag += 1			
	else:
		if (s[x:x+2] == 'AB'):
			print('YES')
			exit()

print('NO')
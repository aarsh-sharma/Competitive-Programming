t = int(input())
while t:
	t -= 1
	b_num = o_num = same = 0
	a = list(input())
	b = list(input())
	for x in range(3):
		flag = 0
		if(a[x] == 'b' or b[x] == 'b'):
			b_num += 1
			flag += 1
		if(a[x] == 'o' or b[x] == 'o'):
			o_num += 1
			flag += 1
		if(flag == 2):
			same += 1
		# print(b_num, o_num, same)
	if(o_num and b_num):
		if(b_num >= 2):
			if(b_num + o_num - same == 3):
				print('yes')
			else:
				print('no')
		else:
			print('no')
	else:
		print('no')
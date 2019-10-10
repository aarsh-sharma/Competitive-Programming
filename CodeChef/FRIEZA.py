t = int(input())
while t:
	t -= 1
	s = input()
	r = ""
	count1 = 0
	count2 = 0
	flag = 0
	for x in s:
		if x in 'frieza':
			count1 += 1
			if flag != 0 and count2 != 0:
				count2 = str(count2)
				r = r + count2
				count2 = 0
		else:
			count2 += 1
			if flag != 0 and count1 != 0:
				count1 = str(count1)
				r = r + count1
				count1 = 0
		flag = 1
	if(count1 != 0):
		count1 = str(count1)
		r = r + count1
	elif(count2 != 0):
		count2 = str(count2)
		r = r + count2
	print(r)
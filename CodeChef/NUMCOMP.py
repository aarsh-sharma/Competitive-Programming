t = int(input())
while t:
	t -= 1
	a, b, n = [int(x) for x in input().split()]
	if(a>=0 and b>= 0):
		if(a>b):
			print(1)
		elif(b>a):
			print(2)
		else:
			print(0)
	else:
		if(n%2 == 0):
			if(abs(a)>abs(b)):
				print(1)
			elif(abs(a)<abs(b)):
				print(2)
			else:
				print(0)
		else:
			if(a>b):
				print(1)
			elif(b>a):
				print(2)
			else:
				print(0)
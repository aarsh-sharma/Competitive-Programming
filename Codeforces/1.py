n = int(input())
a = [int(x) for x in input()]
flag = 0
if(n == 1):
	if(a[0] == 1):
		print("Yes")
		flag = 1
	else:
		print("No")
		flag = 1
for x in range(n-1):
	if(a[x] == a[x+1]):
		print("No")
		flag = 1
		break
if(flag == 0):
	print("Yes")
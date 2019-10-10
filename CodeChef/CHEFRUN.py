t = int(input())
while t:
	t -= 1
	x1, x2, x3, v1, v2 = [int(x) for x in input().split()]
	len1 = abs(x3 - x1)
	len2 = abs(x3 - x2)
	if((len1/v1) < (len2/v2)):
		print("Chef")
	elif((len1/v1) > (len2/v2)):
		print("Kefa")
	else:
		print("Draw")
t = int(input())
while (t):
	t -= 1
	n = int(input())
	k = int(input())
	rem = k%n
	if (n%2):
		print(min(rem, n-rem)*2)
	else:
		if (rem == n//2):
			print(rem*2 - 1)
		else:
			print(min(rem, n-rem)*2)

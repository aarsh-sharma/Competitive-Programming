t = int(input())
while t:
	t-=1
	n, m = [int(x) for x in input().split()]
	rem = n % m
	if(rem % 2 == 0):
		print("EVEN")
	else:
		print("ODD")
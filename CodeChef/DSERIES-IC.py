q = int(input())
while q:
	q -= 1
	n, m = [int(x) for x in input().split()]
	sum1 = 0
	for x in range(1, n+1):
		temp = 1
		for y in range(1, m+1):
			temp = ((temp%1000000007) * ((x + y)%1000000007))%1000000007
			# print(temp)
		print(temp)
		sum1 = ((sum1%1000000007) + (temp%1000000007))%1000000007
		# sum1 += temp
		# print(sum1)
	print(sum1)
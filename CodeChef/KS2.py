def sumDigit(n):
	s = 0
	while (n > 0):
		s += n % 10
		n = n//10
	return s


t = int(input())

while(t):
	t -= 1
	n = int(input())
	n *= 10
	while (sumDigit(n) % 10 != 0):
		n += 1
	print(n)

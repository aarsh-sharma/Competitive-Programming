def countBits(n):
    count = 0
    while n:
        count += 1
        n >>= 1
    return count


t = int(input())
while t:
	t -= 1
	a, b = [int(x) for x in input().split()]
	bits = max(countBits(a), countBits(b))
	times = 0
	maxm = (a^b)
	for i in range(bits):
		bb = b%2
		b >>= 1
		if (bb):
			b = b + (1 << (bits-1))
		if ((a^b) > maxm):
			maxm = (a^b)
			times = i+1

	print(times, maxm)

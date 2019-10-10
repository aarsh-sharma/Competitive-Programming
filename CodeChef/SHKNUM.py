t = int(input())
num = []
for x in range(35):
	temp = 2**x
	num.append(temp)
	if(temp > 1000000000):
		# print(temp)
		break
# print(num)
l = len(num)
sums = []
for x in range(l):
	for y in range(x+1,l):
		if(x != y):
			sums += [num[x] + num[y]]
sums.sort()
# print(sums)
l = len(sums)
while t:
	diff = 1000000000
	t -= 1
	n = int(input())
	for x in range(l):
		if(abs(sums[x] - n) < diff):
			diff = abs(sums[x] - n)
		if(abs(sums[x+1] - n) > diff):
			break
	print(diff)
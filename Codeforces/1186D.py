from sys import stdin, stdout

n = int(input())
negitives = []
positives = []
for i in range(2):
	negitives.append([])
	positives.append([])
sums = 0
answer = [0]*n
for i in range(n):
	x = [float(x) for x in input().split()][0]
	# print(x)
	if x < 0:
		if abs(int(x) - x) >= 10**-6:
			negitives[1].append((i, x))
			sums += int(x)
			answer[i] = int(x)
		else:
			negitives[0].append((i, x))
			sums += int(x)
			answer[i] = int(x)
	if x > 0:
		if abs(int(x) - x) >= 10**-6:
			positives[1].append((i, x))
			sums += int(x)
			answer[i] = int(x)
		else:
			positives[0].append((i, x))
			sums += int(x)
			answer[i] = int(x)
if sums > 0:
	for i in range(sums):
		answer[negitives[1][i][0]] -= 1
elif sums < 0:
	for i in range(abs(sums)):
		answer[positives[1][i][0]] += 1
for i in range(n):
	print (answer[i])

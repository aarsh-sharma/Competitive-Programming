n = int(input())
lead = leadt = winner = score1 = score2 = 0
for n in range(n):
	a, b = [int(x) for x in input().split()]
	score1 += a
	score2 += b
	lead = abs(score1 - score2)
	if(lead > leadt):
		leadt = lead
		if(score1 > score2):
			winner = 1
		else:
			winner = 2
print(winner, leadt)
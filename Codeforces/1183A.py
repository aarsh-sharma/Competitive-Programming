n = int(input())
while True:
	s = str(n)
	sm = 0
	for x in s:
		sm += ord(x) - ord('0')
	if (sm%4 == 0):
		print(n)
		exit(0)
	n += 1
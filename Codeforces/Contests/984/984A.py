n = int(input())
a = [int(x) for x in input().split()]
a.sort()
temp = int(n/2)
if(n%2 == 0):
	print(a[temp - 1])
else:
	print(a[temp])
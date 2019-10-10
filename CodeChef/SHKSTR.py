# incomplete solution
n = int(input())
a = [None]*n
for x in range(n):
    a[x] = input()
q = int(input())
while q:
   	q -= 1
   	r, p = input().split()
   	r = int(r)
   	maxmlength = 0
   	currstring = ""
   	tempstring = "zzzzzzzzzzz"
   	for x in range(r):
   		if(a[x]<tempstring):
   			tempstring = a[x]
   	# print(a[:r])
   	for x in range(r):
   		temp = 0
   		for y in range(min(len(a[x]),len(p))):
   			if(a[x][y] == p[y]):
   				temp += 1
   			else:
   				break
   		if(temp > maxmlength):
   			maxmlength = temp
   			currstring = a[x]
   		elif(temp == maxmlength):
   			if(a[x]<currstring):
   				currstring = a[x]
   	if(len(currstring) == 0):
   		print(tempstring)
   	else:
   		print(currstring)
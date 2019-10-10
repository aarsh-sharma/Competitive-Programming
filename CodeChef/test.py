from sys import stdin,stdout
I = lambda : map(int,stdin.readline().split())

def sumPairs(arr, n): 
    sum = 0
    for i in range(n - 1, -1, -1): 
        sum += i*arr[i] - (n-1-i) * arr[i] 
    return sum
  
def zs(a,n):
	tmp = 0
	mp = {0:[0]}
	ans = 0
	flag = 1
	for i in range(n):
		tmp = tmp^a[i]
		if tmp in mp.keys():
			mp[tmp].append(i+1)
			l = len(mp[tmp])
			pr = mp[tmp][l-1] - mp[tmp][l-2] - 1
			# print tmp,": ",mp[tmp][l-1],mp[tmp][l-2],pr
			ans += pr
			# print mp
			# mp[tmp][l-1] = -1 * pr + (mp[tmp][0])
			# print ans
		else:
			mp[tmp] = [i+1]
	return mp
t = input()
for _ in range(t):
	n = input()
	arr = I()
	z = zs(arr, n)
	ans = 0
	for x in z.keys():
		# print x
		l = len(z[x])
		ans+= sumPairs(z[x],l) - (l*(l-1)/2)
		# arr = z[x]
		# ln = len(arr)
		# for i in range(ln):
		# 	for j in range(i+1,ln):
		# 		# print z[x][i],z[x][j], 	 
		# 		ans+=max(0,z[x][j]-z[x][i]-1)
	print ans

n = input()
n = list(n)
l = len(n)
ans = -1
for x in range(l):
  ans += 2**x
if l == 1:
  ans = 0

for x in range(l):
  if (n[x] == '4'):
    n[x] = '0'
  else:
    n[x] = '1'

n = ''.join(n)
# print(n)
num = int(n, 2)
# print(ans, num)
ans += num+1
print(ans)
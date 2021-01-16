t = int(input())
a = list(bin(t)[2:])
ans = []
n = len(a)

flag = 0
for x in range(n-1, 0, -1):
  if (a[x] != a[x-1]):
    ans.append(n - x)

# if (n > 1):
#   if (a[0] != a[1]):
#     ans.append(0)

s = 1
if (a[n-1] == '1'):
  s = 0

ans.append(n)
# print(ans)
# print(a)

ans.sort(reverse=True)

if (len(ans) == 0):
  print(0)
else:
  print(2*len(ans) - s)
  for x in ans:
    print(x, end=' ')

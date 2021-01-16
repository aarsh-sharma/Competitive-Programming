n = int(input())
s = input()
first = [None]*(n-1)
# print(len(s))
for i in range(n-1):
  if (s[i+1] == '0'):
    first[i] = -1
    continue
  if (n%2 == 1):
    if i < n//2:
      first[i] = int(s[i+1])
    else:
      first[i] = int(s[i])
  else:
    if (i == n//2):
      first[i] = max(int(s[i]), int(s[i+1]))
    elif i < n//2:
      first[i] = int(s[i+1])
    else:
      first[i] = int(s[i])

midl = midr = 0
if (n%2 == 1):
  midl = (n-1)//2 - 1;
  midr = midl+1
else:
  midl = midr = n//2 - 1

point1 = point2 = flag = 0
# print(midl, midr)

while (True):
  if (first[midl] == -1 and first[midr] == -1):
    if (midl != 0):
      midl -= 1;
    if (midr < n-1):
      midr += 1;
    continue;
  if (first[midl] == -1):
    point1 = midr
    break
  elif (first[midr] == -1):
    point1 = midl
    break

  flag = 1
  point1 = midl
  point2 = midr
  break

# print(midl, midr, point1, point2, first[midl], first[midr], flag)

ans = 0
if (flag == 0):
  ans = int(s[:point1+1]) + int(s[point1+1:])
else:
  ans1 = int(s[:point1+1]) + int(s[point1+1:])
  ans2 = int(s[:point2+1]) + int(s[point2+1:])
  ans = min(ans1, ans2)

print(ans)

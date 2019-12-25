from math import *

q = int(input())
while (q):
  q -= 1
  n = int(input())
  nn = n
  pows = [0]*40
  while (n > 0):
    t = int(log(n, 3))
    if pows[t]:
      t = pows.index(0, t, 40)
      for i in range(t):
        pows[i] = 0
      pows[t] = 1
      n -= (3**t)
    else:
      pows[t] = 1
      n -= 3**t

  ans = 0
  # ans2 = 0
  flag = 0;
  for i in range(40):
    if (pows[i]):
      ans += 3**i
  print(ans)
mod = 10**9 + 7

n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

a.sort()
muls = [a[0]+1, a[k-1]+1]
print(a)

for x in range(1, k):
  diff = a[x] - a[x-1] - 1
  if (diff == 0):
    continue
  muls.append(pow(2, diff-1))
  muls.append(diff+1)
  print(diff, pow(2, diff-1))

ans = 1
for x in muls:
  ans *= x

print(ans%mod)
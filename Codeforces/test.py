# Enter your code here. Read input from STDIN. Print output to STDOUT

n = int(input())
s = input()
d = {}
l = {}
f = {}
for i in range(n):
  if s[i] in d:
    d[s[i]] += 1
    l[s[i]] = i
    # d[s[i]] %= 2
  else:
    d[s[i]] = 1
    f[s[i]] = i
    l[s[i]] = i
cnt = 0

a = []
st, mnl = 0, 10**10
c = [0]*n
cnt = 0
for i in range(n):
  if d[s[i]]%2 == 1:
    cnt += 1
    mnl = min(l[s[i]], mnl)
    st = min(max(st, f[s[i]]), mnl)
    a.append(f[s[i]])
    a.append(l[s[i]])
    d[s[i]] = 0
  c[i] = cnt
# print c
a.sort()
ans = 10**9
# print a,cnt,st
if cnt == 1:
  ans = 0
else:
  for i in a:
    if c[i] == cnt:
      ans = i - st
      break
print(ans)

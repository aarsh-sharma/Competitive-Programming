a = input()
b = input()
a = a.lower()
b = b.lower()
n = len(a)
flag = 0
for x in range(n):
    if(a[x] < b[x]):
        flag = -1
        break
    if(b[x] < a[x]):
        flag = 1
        break
print(flag)
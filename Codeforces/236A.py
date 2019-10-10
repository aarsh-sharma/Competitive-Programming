a = input()
n = len(a)
idx = 0
num = [0]*26
for x in range(n):
    num[ord(a[x]) - ord('a')] = 1
num.sort(reverse = True)
for x in range(26):
    if(num[x] == 0):
        idx = x
        break
if(idx % 2 == 0):
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")

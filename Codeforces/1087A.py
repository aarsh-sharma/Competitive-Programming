s = input()
ans = ''
length = len(s)
mid = int(length/2)
if(length % 2 == 0):
    for x in range(mid):
        ans += s[mid - x - 1]
        ans += s[mid + x]
else:
    ans = s[mid]
    for x in range(1, mid+1):
        ans += s[mid + x]
        ans += s[mid - x]
print(ans)

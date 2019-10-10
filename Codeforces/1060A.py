n = int(input())
a = input()
eight = 0
for el in a:
    if(el == '8'):
        eight += 1
ans = min(n//11, eight)
print(ans)

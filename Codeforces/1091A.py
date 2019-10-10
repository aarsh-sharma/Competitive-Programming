y, b, r = [int(x) for x in input().split()]
y += 1
r -= 1
m = min(y, b, r)
print(3*m)

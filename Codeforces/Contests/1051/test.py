l, r = [int(x) for x in input().split()]
print("YES")
for x in range(l, r+1, 2):
    print(x, x+1)
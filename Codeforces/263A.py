a = [None]*5
idx = 0
for x in range(5):
    a[x] = [int(x) for x in input().split()]
for x in range(5):
    for y in range(5):
        if(a[x][y] == 1):
            idx = abs(x - 2) + abs(y - 2)
            break
print(idx)
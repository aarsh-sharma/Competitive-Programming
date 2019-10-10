a = input()
# a = list(a)
a = [int(x) for x in list(a)]
ans = 0
borrow = 0
while a:
    if(len(a) == 1):
        ans += a[0]
        del a[0]
        break
    for el in a:
        if(el == 0):
            del a[0]
        else:
            break
    if(len(a) == 0):
        break
    if(a[len(a) - 1] != 9):
        ans += a[len(a) - 1] + 10
        borrow = 1
    else:
        ans += 9
    del a[len(a) - 1]
    for x in range(len(a) - 1, -1, -1):
        if(a[x] != 0):
            a[x] -= borrow
            borrow = 0
            break
        elif(borrow):
            a[x] = 9
print(ans)

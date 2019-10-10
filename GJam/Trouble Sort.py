def trouble(a):
    flag = 0
    while(flag == 0):
        flag = 1
        for x in range(len(a) - 2):
            if(a[x] > a[x+2]):
                temp = a[x]
                a[x] = a[x+2]
                a[x+2] = temp
                flag = 0
    return a

t = int(input())
ll = 1
while ll <= t:
    ll += 1
    n = int(input())
    a = [int(x) for x in input().split()]
    new = trouble(a)
    # print(new)
    lol = 0
    for x in range(n-1):
        if(a[x] > a[x+1]):
            lol = 1
            print("Case #", ll-1, ": ", x, sep="")
            break
    if(lol == 0):
        print("Case #", ll-1, ": OK", sep="")

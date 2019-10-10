def strength(y):
    ans = 0
    power = 1
    for x in range(len(y)):
        if(y[x] == "C"):
            power *= 2
        else:
            ans += power
    return ans

def dom(y):
    y.sort(reverse=True)
    if(strength(y) > d):
        print("Case #", lol-1, ": IMPOSSIBLE", sep="")
        return True
    return False

t = int(input())
lol = 1
while lol <= t:
    lol +=1
    d, a = [x for x in input().split()]
    d = int(d)
    a = list(a)
    length = len(a)
    total = 0
    flag = 0
    # b = a
    # b.sort(reverse=True)
    # print(a)
    # if(strength(b) > d):
    #     print("Case #", lol-1, ": IMPOSSIBLE", sep="")
    #     continue
    if(dom(a)):
        # print("Case #", lol-1, ": IMPOSSIBLE", sep="")
        continue
    print(a)
    while(strength(a) > d):
        flag = 1
        for x in range(length - 1, 0,-1):
            if(a[x] == "S" and a[x-1] == "C"):
                temp = a[x]
                a[x] = a[x-1]
                a[x-1] = temp
                total +=1
                break
    if(total == 0 and flag == 1):
        print("Case #", lol-1, ": IMPOSSIBLE", sep="")
    else:
        print("Case #", lol-1, ": ", total, sep="")

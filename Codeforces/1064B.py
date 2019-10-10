t = int(input())
while t:
    t -= 1
    n = int(input())
    n = bin(n)[2:]
    n = n[::-1]
    ans = 1
    length = len(n)
    for x in range(length):
        if(n[x] == '1'):
            ans *= 2
    print(ans)
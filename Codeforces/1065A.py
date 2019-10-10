t = int(input())
while t:
    t -= 1
    s, a, b, c = [int(x) for x in input().split()]
    tot = s // c
    ans = tot + (tot//a)*b
    print(ans)
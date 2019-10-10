t = int(input())
while t:
    t -= 1
    a, b, c = [int(x) for x in input().split()]
    mid = (a + c) / 2
    # print("mid is", mid)
    if((a + c) % 2 == 0):
        print(int(abs(mid - b)))
    else:
        print(int(abs(mid - b) + 1))

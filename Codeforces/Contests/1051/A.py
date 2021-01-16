n = int(input())
while(n):
    n -= 1
    s = input()
    u = l = d = 0
    length = len(s)
    for x in range(length):
        asc = ord(s[x])
        if(asc >= 97 and asc <= 122):
            l += 1
        elif(asc >= 65 and asc <= 90):
            u += 1
        elif(asc >= 48 and asc <= 57):
            d += 1
    # print(l, u, d)
    if(l == 0 and u == 0 and d != 0):
        print('a' + 'A' + s[2:])
    elif(l != 0 and u == 0 and d == 0):
        print('0' + 'A' + s[2:])
    elif(l == 0 and u != 0 and d == 0):
        print('a' + '0' + s[2:])
    elif(l != 0 and u != 0 and d == 0):
        if(l == 1):
            if(ord(s[0]) >= 97 and ord(s[0]) <= 122):
                print(s[0] + '0' + s[2:])
            else:
                print('0' + s[1:])
        elif(u == 1):
            if(ord(s[0]) >= 65 and ord(s[0]) <= 90):
                print(s[0] + '0' + s[2:])
            else:
                print('0' + s[1:])
        else:
            print('0' + s[1:])
    elif(l != 0 and u == 0 and d != 0):
        if(l == 1):
            if(ord(s[0]) >= 97 and ord(s[0]) <= 122):
                print(s[0] + 'A' + s[2:])
            else:
                print('A' + s[1:])
        elif(d == 1):
            if(ord(s[0]) >= 48 and ord(s[0]) <= 57):
                print(s[0] + 'A' + s[2:])
            else:
                print('A' + s[1:])
        else:
            print('A' + s[1:])
    elif(l == 0 and u != 0 and d != 0):
        if(u == 1):
            if(ord(s[0]) >= 65 and ord(s[0]) <= 90):
                print(s[0] + 'a' + s[2:])
            else:
                print('a' + s[1:])
        elif(d == 1):
            if(ord(s[0]) >= 48 and ord(s[0]) <= 57):
                print(s[0] + 'a' + s[2:])
            else:
                print('a' + s[1:])
        else:
            print('a' + s[1:])
    else:
        print(s)
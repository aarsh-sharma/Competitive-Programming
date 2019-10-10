n = int(input())
rem = n % 3
div = n//3
if(rem == 0):
    if(div % 3 == 0):
        print(div - 1, div - 1, div + 2)
    else:
        print(div, div, div)
elif(rem == 1):
    if(div % 3 == 0):
        print(div - 1, div + 1, div + 1)
    else:
        if(div % 3 == 1):
            print(div + 1, div, div)
        elif(div % 3 == 2):
            print(div, div - 1, div + 2)
elif(rem == 2):
    if(div % 3 == 0):
        print(div - 1, div + 1, div + 2)
    else:
        if(div % 3 == 1):
            print(div, div + 1, div + 1)
        elif(div % 3 == 2):
            print(div + 2, div, div)
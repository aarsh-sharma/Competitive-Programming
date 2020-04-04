def homework(n, a):

    m = {}
    for i in range(n):
        m[a[i]] = i 
        
    arrs = sorted(a)
    ret = 0
    
    for i in range(len(a)):
        if a[i] != arrs[i]:
            ret +=1
            
            idx = m[arrs[i]]
            m[a[i]] = m[arrs[i]]
            a[i], a[idx] = arrs[i], a[i]
    return ret


n = int(input())
a = [int(x) for x in input().split()]

forw = homework(n, a)
backw = homework(n, list(reversed(a)))
print(min(forw, backw))
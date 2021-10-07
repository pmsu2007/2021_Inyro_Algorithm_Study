#n,k = map(int,input().split(" "))
import time
for i in range(10):
    n,k = 87131894654684612351987,722
    startT = time.time()
    endNum = 0
    time.sleep(1)
    '''
    while True:
        endNum = endNum + n%k
        i = n//k
        if i == 0:
            endNum = endNum - 1
            break
        elif i == 1: 
            endNum = endNum + 1
            break
        elif i == k:
            endNum = endNum + 2
            break
        else:
            endNum = endNum + 1
            n = n//k

    '''
    endNum = 0
    while True:
        target = (n//k) * k
        endNum += (n-target)
        n = target
        if n< k: break
        endNum +=1
        n //= k
    endNum += (n -1)
    


    endT = time.time()
    print("Time = ",endT-startT)
    #print(endNum)

'''
request = list(map(int,input().split(' ')))
print(request)
numArr = []
for i in range(request[0]):
    numArr.append(list(map(int,input().split(' '))))
'''
request = [2, 4]
numArr = [[7,3,1,8], [3,3,3,4]]

endArr = []
for i in range(request[0]):
    min = numArr[i][0]
    for j in numArr[i]:
        if min>j: min = j
    endArr.append(min)

endArr.sort()
print(endArr[-1])

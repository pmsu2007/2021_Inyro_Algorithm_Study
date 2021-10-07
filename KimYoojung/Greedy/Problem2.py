#입력 받기
# input1 = input()
# input2 = input()
input1 = "5 7 2"
input2 = "3 4 3 4 3"
#문자열을 분할하기
arr1 = input1.split(" ")
arr2 = input2.split(" ")
#문자열 배열을 int로 바꾸기
request = []
numArr = []
for i in arr1:
    request.append(int(i))
for j in arr2:
    numArr.append(int(j))

numArr.sort()
endNum = 0
endSignal = 0
def sortPlus():
    global endNum, endSignal
    for i in range(request[2]):
        endNum = endNum + numArr[-1]
        endSignal = endSignal + 1
        if endSignal == request[1]: return endNum
    if numArr[-2] == numArr[-1]:
        for i in range(request[2]):
            endNum = endNum + numArr[-1]
            endSignal = endSignal + 1
            if endSignal == request[1]: return endNum
    else:
        endNum = endNum + numArr[-2]
        endSignal = endSignal + 1
        if endSignal == request[1]: return endNum
    sortPlus()
    
sortPlus()
print(endNum)



'''
endNum = 0 #마지막 답을 저장하는 변수
endSignal = 0

max = 0
maxIdx = -1

def plus():
    global max, maxIdx, endNum, endSignal   

    for idx in range(request[0]):
        if numArr[idx] > max: 
            max = numArr[idx]
            maxIdx = idx

    for k in range(request[2]):
        endNum = endNum + max
        endSignal = endSignal + 1
        if endSignal == request[1]: return endNum

    if maxIdx == request[0] - 1: 
        max = 0
        maxIdx = -1

    plus()

plus()
print(endNum)
'''


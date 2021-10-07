ipt = input()
ipt = list(ipt)
endNum = 0
while True:
    chk = int(ipt[0])
    arr0 = []
    arr1 = []
    str0, end0, str1, end1 = 0,0,0,0
    for i in range(len(ipt)):
        if ipt[i] == "0":
            if chk == 0:
                end0 = i
            else:
                chk = 0
                arr1.append((str1, end1))
                str0 = end1+1
                end0 = str0
                str1, end1 = 0, 0
        if ipt[i] == "1":
            if chk == 1:
                end1 = i
            else:
                chk = 1
                arr0.append((str0, end0))
                str1 = end0+1
                end1 = str1
                str0, end0 = 0, 0
        if i == len(ipt)-1:
            if chk == 0:  arr0.append((str0, end0))
            else: arr1.append((str1, end1))

    if len(arr0) + len(arr1) == 1: break

    chg = arr0
    if len(arr0) > len(arr1):
        chg = arr1
    number = chg[0][1] - chg[0][0]
    startIdx = chg[0][0]
    endIdx = chg[0][1]
    for i in chg:
        if number < i[1]- i[0]: startIdx, endIdx = i[0], i[1]
    
    #print('debug', arr0, arr1, ipt, chg)

    for i in range(startIdx,endIdx+1):
        #print(i, type(ipt[i]), int(ipt[i]))
        if ipt[i] == "0": ipt[i] = "1"
        else: ipt[i] = "0"
    
    endNum +=1

print(endNum)
#print('debug', arr0, arr1, ipt)

















#1. 0,1 를 두 그룹으로 나누는 것이 어려움
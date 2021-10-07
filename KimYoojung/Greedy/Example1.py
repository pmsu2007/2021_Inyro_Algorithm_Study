inM = int(input("거스름돈을 입력하시오"))
coinArr = [500, 100, 50, 10]
resultArr = []
def doit():
    nowIn = inM
    for i in coinArr: 
        nowCoin = nowIn // i
        resultArr.append(nowCoin)
        nowIn = nowIn - nowCoin * i

doit()
print(resultArr)

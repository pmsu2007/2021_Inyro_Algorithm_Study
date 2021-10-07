'''
mapx, mapy = map(int,input().split(" ")) #문법 버그 1개
x,y,lo = map(int,input().split(" ")) 
gameMap = []
for i in range(mapy):
    gameMap.append(list(map(int,input().split(" "))))
'''
mapx, mapy = 4,4
x,y,lo = 1,1,0
gameMap = [[1, 1, 1, 1], [1, 0, 0, 1], [1, 1, 0, 1], [1, 1, 1, 1]]




chkList = [(-1,0),(0,-1),(1,0),(0,1)]

def check(op = 0):
    global x,y,lo
    if 0 <= x + chkList[(lo + op)%4][0] <= mapx - 1 and 0 <= y + chkList[(lo + op)%4][1] <= mapy - 1: # 논리 오류 1개(번위가 1~4가 아닌 0~3)
        if gameMap[y + chkList[(lo + op)%4][1]][x + chkList[(lo + op)%4][0]] == 1: return False
        else: return True
    else: return False


print("Debug",gameMap)
print("Debug",x,y,lo)
endNum = 1
check4 = 0
while True:
    print("Debug",check4, x, y, lo)
    if check():
        check4 = 0
        endNum +=1
        gameMap[y][x] = 1 # 논리 오류 1개(방문함을 표시하는 1은 좌표 바꾸기 전에 미리 설정해야 한다.)
        x += chkList[lo][0]
        y += chkList[lo][1]
        lo = (lo+3) % 4
    else:
        check4 += 1
        lo = (lo+3) % 4

    if check4 == 4:
        if check(-1):
            x += chkList[(lo - 1)%4][0]
            y += chkList[(lo - 1)%4][1]
        else: break

print(endNum)
print("Debug",check4, x, y, lo)


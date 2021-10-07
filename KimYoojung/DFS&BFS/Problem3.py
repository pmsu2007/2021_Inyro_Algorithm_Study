'''
n,m = map(int , input().split(" "))
tool = []
for i in range(n):
    tool.append(list(map(int, input())))
print(tool)
input()
'''
# 입력 예제
'''
tool = [
    [0,0,1,1,0],
    [0,0,0,1,1],
    [1,1,1,1,1],
    [0,0,0,0,0]
]
(n, m)= (4,5)
'''
# '''
n,m = 15,14
tool = [
    [0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0], 
    [1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0], 
    [1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0], 
    [1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0], 
    [1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], 
    [1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0], 
    [1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1], 
    [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1], 
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1], 
    [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0], 
    [0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0], 
    [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0], 
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1], 
    [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1], 
    [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1]
]
# '''

from collections import deque

# 범위 안에 있는 지 체크
def checkOut(x, y):
    global n, m
    if 0<= x < n and 0<= y < m : return True
    else: return False 

# 상하좌우에 구멍 있는지, 있으면 방문함을 표시*하고 큐에 추가 *표시: 0->2
def check0(graph, x ,y, queue):
    global n, m
    if checkOut(x-1,y) and graph[x-1][y] == 0:#상
        graph[x-1][y] = 2 #방문함을 표시
        queue.append((x-1,y)) #큐에 추가
    if checkOut(x+1,y) and graph[x+1][y] == 0:#하
        graph[x+1][y] = 2
        queue.append((x+1,y))
    if checkOut(x,y-1) and graph[x][y-1] == 0: #좌
        graph[x][y-1] = 2
        queue.append((x,y-1))
    if checkOut(x,y+1) and graph[x][y+1] == 0: #우
        graph[x][y+1] = 2
        queue.append((x,y+1))

iceCream = 0 #아이스크림 수(bfs실행할 때마다 +1)

def bfsq1(graph, startx,starty):
    global iceCream
    iceCream += 1
    queue = deque() #큐 생성
    queue.append((startx,starty)) #첫 구멍 위치 표시
    graph[startx][starty] = 2 #방문함을 표시
    #  bfs
    while queue: #갈 곳이 없어질 때까지
        newx, newy = queue.popleft() #갈 곳을 선택함
        check0(graph, newx, newy, queue) # 상하좌우 체크 & 갈 수 있는 곳을 큐에 추가
        # print("debug: queue=", queue)

for i in range(n):
    for j in range(m):
        if tool[i][j] == 0: bfsq1(tool, i, j)

print(iceCream)


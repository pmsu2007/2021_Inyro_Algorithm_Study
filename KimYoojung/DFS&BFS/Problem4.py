n, m = 5,6
gameMap = [
    [1,0,1,0,1,0],
    [1,1,1,1,1,1],
    [0,0,0,0,0,1],
    [1,1,1,1,1,1],
    [1,1,1,1,1,1]
]

solution = []
def gameDfs(graph,x,y,steps):
    global solution
    print(x,y,steps)
    steps +=1
    if x>=n or x<0 or y>=m or y<0:
        print("outside")
        return 0
    if graph[x][y] == 2 or graph[x][y] == 0 :
        print("did") 
        return 0
    if x==n-1 and y==m-1: 
        print("where is my return??????????????????????")
        print("steps=", steps)
        solution.append(steps)
        return steps

    graph[x][y] = 2
    print("2")
    # step = []
    # step.append((x,y))
    gameDfs(graph,x-1, y,steps)
    gameDfs(graph,x+1, y,steps)
    gameDfs(graph,x, y-1,steps)
    gameDfs(graph,x, y+1,steps)

# solution = []
solution.append(gameDfs(gameMap, 0,0,0))
print(solution)


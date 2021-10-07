n, m = 4,6
farm = [
    [1,-1,0,0,0,0],
    [0,-1,0,0,0,0],
    [0,0,0,0,-1,0],
    [0,0,0,0,-1,1]
]

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def checkGood(farm,x,y):
    for i in range(4):
        newx,newy = x+dx[i], y+dy[i]
        if 
        if farm[newx][newy]] == 1:
            return True

def grow(farm):
    for i in range(n):
        for j in range(m):
            if farm[i][j] == 0 and checkGood(i,j):
                farm[i][j] = 1
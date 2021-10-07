n = int(input())
cmd = input().split(" ")

x,y =1,1 

def check(plusx, plusy):
    global x,y
    if 0< x+plusx <= n and 0< y + plusy <= n:
        x+=plusx
        y+=plusy
    print(x,y)

for i in cmd:
    if i == "L":    check(0,-1)
    elif i == "R":  check(0,1)
    elif i == "U":  check(-1,0)
    elif i == "D":  check(1,0)

print(x,y)
request = input()
x = request[0]
y = int(request[1])

def check(plusx, plusy):
    global x,y
    if ord('a') <= ord(x) + plusx <= ord("h") and 0 < y+ plusy < 9:
        return True
    else: return False

endNum = 0
if check(-2,0): #L
    if check(-2,-1): endNum +=1
    if check(-2,1): endNum +=1
if check(2,0): #R
    if check(2,-1): endNum +=1
    if check(2,1): endNum +=1
if check(0,-2): #U
    if check(-1,-2): endNum +=1
    if check(1,-2): endNum +=1
if check(0,2): #D
    if check(-1,2): endNum +=1
    if check(1,2): endNum +=1

print(endNum)
 
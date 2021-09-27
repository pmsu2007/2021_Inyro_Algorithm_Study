# 왕실의 나이트
current = input()
column = int(ord(current[0])) - int(ord('a'))+1
row = int(current[1])

dirs = [(2, -1), (-2, +1), (2,1), (-2,-1), (-1,2), (1, 2), (1,-2), (-1, 2)]

move = 0

for dir in dirs:
    c_column = column + dir[0]
    c_row = row + dir[1]

    if c_column >= 1 and c_column <= 8 and c_row >= 1 and c_row <= 8:
        move += 1

print(move)


# 숫자 카드 게임

n, m = map(int, input().split())
temp = []

for i in range(n):
    cards = list(map(int, input().split()))  # 한 행씩 입력받고
    cards.sort()    # 각 행을 오름차순으로 sorting
    temp.append(cards[0])   # 해당 행의 가장 작은수를 temp 배열에 추가한다
    MAX = max(temp)

print(MAX)

""" 
3 3
3 1 2
4 1 4
2 2 2 
"""
""" 
2 4
7 3 1 8
3 3 3 4
"""
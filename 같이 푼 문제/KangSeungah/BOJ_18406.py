# 럭키 스트레이트
# https://www.acmicpc.net/problem/18406

n = input()
length = len(n)

# 앞부분 저장할 배열
firsthalf = []
# 뒷부분 저장할 배열
secondhalf = []

# 앞부분 숫자 반영
for i in range(0, length//2):
    firsthalf.append(n[i])
    # 문자 -> 정수
    firsthalf = [int (i) for i in firsthalf]

# 뒷부분 숫자 반영
for k in range(length//2, length):
    secondhalf.append(n[k])
    # 문자 -> 정수
    secondhalf = [int (i) for i in secondhalf]

# sum 함수 이용, 앞 뒤가 합이 같으면 luck 아니면 ready
if sum(secondhalf) == sum(firsthalf):
    print("LUCKY")
else:
    print("READY")




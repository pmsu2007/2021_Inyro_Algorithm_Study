# 뒤집기
# https://www.acmicpc.net/problem/1439
# 바뀐 횟수가 짝수면 0집합과 1집합의 수가 하나 차이 남, 홀수면 같음
# 즉, count가 짝수면 count를 2로 나눈 값이 최종 값, 홀수면 count를 2로 나눈 값에 +1을 한 값이 최종 값

s = input()
length = len(s)
count = 0

# 0->1 or 1->0 바뀌는 횟수를 count에 저장
for i in range(length-1):
    if s[i] != s[i+1]:
        count += 1


if count % 2 == 0:
    count //= 2
    print(count)
else:
    count //= 2
    print(count + 1)





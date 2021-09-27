# 큰 수의 법칙

n, m, k = map(int, input().split())
number = list(map(int, input().split()))

number.sort()  # 가장 큰 번호가 뒤로 오도록 sort 후 number 배열에 반환
first = number[n-1]
second = number[n-2]

sum = 0

while True:
    if m == 0:  # 더하는 횟수가 0일 때 or 더이상 더하지 않아도 될 때
        break

    for i in range(k): # 연속해서 k번 초과로 같은 숫자를 더하지 않도록 제한
        if m == 0:  # 더하는 횟수를 초과하지 않도록 제한
            break
        sum += first
        m -= 1  # 한번 실행할 때마다 더하는 횟수를 차감

    sum += second   # 가장 큰 수를 k번 만큼 더해주고 반복문 빠져나와 두번째로 큰 수를 sum 에 더해준다.
    m -= 1  # 마찬가지로 한번 실행할 때마다 더하는 횟수를 차감

print(sum)  # 출력 결과







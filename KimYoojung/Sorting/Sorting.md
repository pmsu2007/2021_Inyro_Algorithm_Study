# 정렬 알고리즘

### 정렬: 데이터를 특정한 기준에 따라서 순서대로 나열하는 것

프로그램에서 데이터를 가공할 때 대부분 정렬해서 사용한다. 그래서 정렬 알고리즘은 매우 중요하다

여기서 설명할 정렬 알고리즘은 

1. 선택 정렬
2. 삽입 정렬
3. 퀵 정렬
4. 계수 정렬

정렬에서 가장 중요하는 것이 바로 **효율성**이다. 그래서 코테에서 문제의 조건(시간, 공간 복잡도)을 보고 적절한 정렬 알고리즘을 선택해야 한다. 뿐만 아니라, 면접에서도 자주 물어보는 것이라 잘 기억해두길

----



## 선택 정렬

가장 쉽고 직관적인 알고리즘으로 한 마디로 설명하면:

> 가장 작은 숫자를 왼쪽으로 보내기

자세한 설명이 생략해도 되지 않을까 라는 생각

그럼 바로 코드로 ㄱㄱ(Python)

### 코드

```python
array = [7,5,9,0,3,1,6,2,4,8]

for i in range(len(array)): # 

​	min_index = i # 가장 작은 원소의 인덱스

​	for j in range(i+1,len(array)): # 현재 배열 중에 가장 작은 원소를 선택하는 For문

​		if array[min_index] > arr[j]

​	array[i], array[min_index] = array[min_index], array[i]

print(array)
```



주의!! 파이썬에서 스와프(Swap) 문이 은근 쉬움. 원래 C언어의  스와프는 아래와 같다

```c
int temp = a;

a = b;

b = temp;
```



### 선택 정렬의 시간 복잡도

선택 정렬은 N-1번의 작은 수를 찾아서 맨 앞으로 보내야 한다.(첫번째 For문)

그리고 작은 수를 찾을 때 마다  N + (N-1) + (N-2) + ... + 2로 볼 수 있어서 선택 정렬의 시간 복잡도는 

> N * (N+1) /2

이고, O(n^2)이다. 

> 간단하게 생각한다면: For문이 2번 돌렸기 때문에 N^2인걸로 생각하면 쉽다.

### 사용 환경

사실 매우 비효율적인 것이라 잘 사용하지 않지만

**특정한 리스트에서 가장 작은 데이터를 찾은 일이 코테에서 잦으므로 선택 정렬 소스 코드는 잘 외워야 된다.**

----

## 삽입 정렬

삽입 정렬도 직관적인 알고리즘이다. 삽입 정렬은 선택 정렬에 비해 구현 난이도가 조금 높지만, 그에 비해 더 효율적인 것이 특징이죠

특히 삽입 정렬은 **데이터가 거의 정렬되어 있을 때** 사용하는 정렬 알고리즘이고, 모든 원소를 하나하나씩 비교할 필요가 없기 때문이다.

### 원리

삽입 정렬은 한 마디로

> 데이터를 적절한 위치에 삽입한다

또한 그 앞까지의 데이터가 이미 정렬되어 있다고 가정한다.

삽입 정렬은 두 번째 데이터부터 시작한다. 두 번째 데이터가 앞과 비교하면서 자리를 점점 움직이는 방법으로 정렬한다. 자신보다 작은 값을 만날 때까지 움직이다.

### 코드

코드는 아래와 같다

```python
array = [7,5,9,0,3,1,6,2,4,8]

for i in range(1,len(array)):

​	for j in range(i,0,-1):

​		if aray[j] < array[j -1]:

​			array[j],array[j-1] = array[j-1], array[j]

​		else: break
```



### 삽입 정렬의 시간 복잡도

삽입 정렬의 시간 복잡도도 O(n^2)이다. 직관적으로 설명하면 For문이 두 개이기 때문이다. 최선의 경우 O(n)(모두 정렬되어 있을 때이다)

### 사용 조건

데이터가 거의 정렬되어 있을 때 사용하는 것이 가장 효율적이다. 이 때 퀵 정렬보다 더 강력할 수 있다는 사실!

----



## 퀵 정렬

이 알고리즘 중에 가장 많이 사용되는 알고리즘이다

한 마디로 한다면

> 기준인 데이터(피벗Pivot)를 선정해, 작은 값과 큰 값으로 나눈다

퀵 정렬에서 가장 대표적인 방식은 **호어 분할**이다

이 방법의 특징이 바로 **첫 번째 데이터를 피벗으로 설정**하는 것이다

### 퀵 정렬(호어 분할)의 원리

1. 먼저 첫 번째 데이터를 피벗으로 설정한다
2. 두 번째 데이터부터 출발해 피벗보다 큰 값을 찾는다
3. 끝부분에서 출발해 피벗보다 작은 값을 찾는다
4. 두 값이 같은 것이면 6번으로 
5. 모두 찾았으면 위치를 서로 바꾸고 2번으로 돌아간다(엄밀히 말하면 또다시 두 번째부터 찾는 것이 아니라 전에 멈췄던 것에서부터 하면 된다.).
6. 피벗과 두 값이 같은 위치와 데이터 바꾼다.
7. 나눠진 왼쪽 배열과 오른쪽 배열을 각각 1번으로 돌아거 실행한다(배열의 길이가 1이면 실행 종료)

### 코드 

코드는 ...나중에 업로드

### 퀵 정렬의 시간 복잡도

평균적으로 O(n*logn)이다. 지관적으로 이해하자면, 데이터를 한 번 나눠지면 처리할 양이 log급으로 떨어지기 때문이다(8->4->2->1)

최악의 경우O(n^2)(데이터가 정렬되어 있으면 매우 느리게 작동한다)



## 계수 정렬

매우 특별한 정렬 알고리즘, 조건도 까다롭다

1. 모든 데이터가 양의 정수
2. 정수의 범위가 있아야 한다(무한대로 커지면 안됨)**(대부분 정수의 범위가 백만을 넘지 않을 때 효과적이다)**

계수 정렬에서 가장 큰 특징이 바로 ***배열의 모든 범위를 담을 수 있는 크기의 리스트를 생성하는 것***이다

그리고 계수 정렬은 **비교기반**의 정렬이 아니다.

### 원리

모든 범위의 리스트을 만들고, 해당 숫자가 나오면 ARRAY[해당 숫자]에 +1를 한다

마지막에 순서대로 출력하면 끝

### 코드 

코드는 ....나중에

### 시간 복잡도

데이터의 개수 = N, 데이트 중 최대값의 크기가 K이라고 할 때 O(N+K)이다. 

### 공간 복잠도

하지만, 이 정렬에서 공간 복잡도를 빼놓을 수 없죠. 공간 복잡도도 O(N+K)이다. 










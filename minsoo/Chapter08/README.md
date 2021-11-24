### 동적 계획법 (Dynamic Programming) 

하나의 문제는 단 한번만 풀도록 매번 저장하는 알고리즘. 다시 그 문제를 요구할 때는 기존에 저장해 두었던 값을 가져온다. 분할 정복처럼 여러개의 하위 문제들로 나누어  먼저 처리해야할 때 사용할 수 있다.

- 분할 정복 (Divide and Conquer) 과 차이점

동적 계획법과 분할 정복은 비슷하지만 결정적인 차이점이 있다. 바로 **작은 문제가 중복이 일어나는지 안일어나는지** 의 차이점이다. 즉, 동적 계획법은 **작은 부분문제들이 반복되는 것(답이 바뀌지 않음)**을 이용해 풀어나가는 방법이다.

- 방법

모든 작은 문제들을 한번만 풀어서, 다시 동일한 문제를 풀 일이 없도록 보관용 테이블을 만들어 결과값을 저장한다. 다시 큰 문제를 풀어나갈 때 똑같은 작은 문제가 나타나면 앞서 메모한 작은 문제의 결과값을 이용한다.

- 메모이제이션 (Memoization)

한번 계산한 작은 문제를 메모리 공간에 저장해놓고 다시 사용하는 것을 의미한다.   

- 피보나치 순열 (`다음 수열` = `이전 단계 수열` + `두 단계 전 수열`)

**재귀 함수**로 풀게되면 점화식을 이용하는 것 보다 간단하게 풀 수 있지만 값이 증가함에 따라 호출되는 함수의 수가 기하수급적으로 증가하기 때문에 일정 수 이상의 순열을 구하기 어렵다. 시간 복잡도로는 O(2^n^)으로 표현할 수 있다.

```C++
int fibo(int x) {
    if (x == 1 || x == 2)
        return 1;
    return fibo(x - 1) + fibo(x - 2);
}
```

![헝.. | 코드잇](https://codeit-images.s3.ap-northeast-2.amazonaws.com/images/60386c77d72e7911e351e6d8/9ed9e9ddd2b5cc0453ab51b3052f1e799fe2f33c60d877f2de75ac213796584f87f1e490829f655561986fcf4f68a8bae9fa20726b416f1b2980379032f30b3a6612e0aeb0b67b6a7227b10ba731521427e3ad10b1e1178c045de5c00c10165814b12373a24d7aede8b78275.png?1616596984429)

1. 큰 문제를 작은 문제로 나눌 수 있다.

   `fib(5)`를 구하기 위해서 `fib(4)`, `fib(3)`이 필요하고, `fib(4)`를 구하기 위해서는 `fib(3)`, `fib(2)`가 필요하다. 따라서, `fib(5)`와 `fib(4)`를 구하기 위해서 `fib(3)`이 필요함을 알 수 있다. 즉, 작은 문제가 반복되는 구조이다.

2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다.

   피보나치 수열은 첫 번째 두 번째 수열은 각각 1로 고정되어 있다. 세 번째 수열은 언제나 결과가 2이고, 네 번째 수열도 마찬가지로 값이 항상 동일하다.

분할 정복으로 문제를 풀었을 경우 시간복잡도는 `O(2^N)`이 되나, 동적 계획법을 사용하면 시간복잡도는 `O(N)`으로 줄어든다.

- 첫 번째 방법 (**Top - Down**) 

**재귀 함수**를 이용해 소스코드를 작성할 경우

```c++
int save[100];
int DP(int x)
{
	if (x==1) return 1;
    if (x==2) return 1;
    if (save[x] != 0) return save[x];
    return save[x] = DP(x - 1) + DP(x - 2);
}
```

큰 문제를 해결하기 위해 작은 문제를 호출하는 탑다운 방식

- 두 번째 방법 (**Bottom - UP**)

**반복문**을 이용해 소스코드를 작성하는 경우

```c++
int save[100];
int DP(int x)
{
	save[0] = 0; save[1] = 1;
    for (int i = 2; i <= x; i++)
        save[i] = save[i-1] + save[i-2];
    return save[x];
}
```

작은 문제부터 해결하여 큰 문제를 해결하는 바텀업 방식

가능하면 탑다운 방식보다는 바텀업 방식으로 구현하는 것이 좋다. 재귀 함수의 스택 크기가 한정되어 있을 수 있기 때문이다.
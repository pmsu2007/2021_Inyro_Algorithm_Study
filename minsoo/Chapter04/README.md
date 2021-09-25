## 구현

머리속에 있는 알고리즘을 소스코드로 바꾸는 과정

### 구현하기 어려운 문제 

1. 간단한 알고리즘이지만, 코드가 지나칠 만큼 길어지는 문제
2. 특정 소수점 자리까지 출력하는 문제
3. 문자열 파싱 문제

→ 프로그래밍 언어 문법과 관련 라이브러리 숙지가 중요

### 구현의 유형

- 완전 탐색 (Brute Force)

  가능한 모든 경우의 수를 빠짐없이 다 탐색하는 해결 방법

  ### 예제

  시각

  > 정수 N이 입력되면 00시 00분 00초부터 N시 59분 59초까지의 모든 시각 중에서 3이 하나라도 포함되는 모든 경우의 수를 구하는 프로그램을 작성하시오.

  ``` c++
  #include <iostream>
  
  using namespace std;
  
  int check[15] = { 3, 13, 23, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 43, 53 };
  int checkHour[3] = { 3, 13, 23 };
  
  int main()
  {
  	int N;
  	cin >> N;
  
  	int count = 0;
  	
  	for (int hour = 0; hour <= N; hour++)
  	{
  		for (int min = 0; min < 60; min++)
  		{
  			for (int sec = 0; sec < 60; sec++)
  			{
  				if (hour % 10 == 3 || min/10 == 3 || min % 10 == 3 || sec /10 == 3 || sec % 10 == 3)
  				count++;
  			}
  		}
  	}
  	cout << count;
  }
  
  ```

  

- 시뮬레이션 (Simulation)

  문제에서 제시한 알고리즘을 한 단계씩 차례대로 직접 수행
  
  ### 예제
  
  상하좌우
  
  > 여행가 A는 N * N 크기의 정사각형 공간 위에 서 있다. 이 공간은 1 * 1 크기의 정사각형으로 나누어져 있다. 가장 왼쪽 위 좌표는 (1, 1)이며, 가장 오른쪽 아래 좌표는 (N, N)에 해당한다. 여행가 A는 상, 하, 좌, 우 방향으로 이동할 수 있으며, 시작 좌표는 항상 (1, 1)이다. 
  >
  > 계획서에는 하나의 줄에 띄어쓰기를 기준으로 하여 L, R, U, D 중 하나의 문자가 반복적으로 적혀있다. 각 문자의 의미는 다음과 같다
  >
  > L : 왼쪽으로 한 칸 이동
  >
  > R : 오른쪽으로 한 칸 이동
  >
  > U : 위로 한 칸 이동
  >
  > D : 아래로 한 칸 이동
  >
  > 이때 여행가 A가 N * N 크기의 정사각형 공간을 벗어나는 움직임은 무시된다

```c++
#include <iostream>

using namespace std;

int main()
{
	int size;
	cin >> size;
	cin.ignore(); // size 입력시 '\n'을 버퍼에서 지우는 역할

	int x = 1, y = 1;

	for (int i = 0; ; i++)
	{
		char input;
		cin.get(input); 

		if (input == '\n')
			break;
		else if (input == 'R')
		{
			if (y >= 1 && y < size)
				y++;
		}
		else if (input == 'L')
		{
			if (y > 1 && y <= size)
				y--;
		}
		else if (input == 'U')
		{
			if (x > 1 && x <= size)
				x--;
		}
		else if (input == 'D')
		{
			if (x >= 1 && x < size)
				x++;
		}
	}

	cout << x << " " << y;
	return 0;
}
```


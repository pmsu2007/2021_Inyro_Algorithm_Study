/*
이코테
효율적인 화폐 구성
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define INF 10001

int money[101];
int memo[10001];

int N, M;

void DP()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int value = money[i];
			if (j % value == 0) // 배수 사용
			{
				memo[j] = min(memo[j], j / value);
			}
			else if (j > value) 
			{
				memo[j] = min(memo[j], memo[j - value] + 1);
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	
	for (int i = 0; i < N; i++)
	{
		cin >> money[i];

	}

	for (int i = 1; i <= M; i++) // 최솟값을 구해야 하므로 INF로 DP테이블 초기화
	{
		memo[i] = INF;
	}

	DP();

	if (memo[M] == INF)
		cout << -1 << '\n';
	else
		cout << memo[M] << '\n';
}

/*
2 15
2
3

3 4
3
5
7
*/
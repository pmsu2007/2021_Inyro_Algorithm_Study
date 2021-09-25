/*
이코테
큰 수의 법칙
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, K;
	cin >> N >> M >> K;

	int array[10001];

	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
	}

	sort(array, array + N, greater<>()); // 내림차순 정렬 O(NlogN)

	int ans = 0;
	int count = 0;

	// array[0] 가장 큰 수
	// array[1] 두 번째로 큰 수

	for (int i = 0; i < M; i++)
	{
		if (array[0] == array[1])
		{
			ans = array[0] * M;
			break;
		}
		else if (count < K)
		{
			ans += array[0];
			count++;
		}
		else
		{
			ans += array[1];
			count = 0;
		}
	}

	cout << ans;
}


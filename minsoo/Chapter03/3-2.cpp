/*
������
ū ���� ��Ģ
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

	sort(array, array + N, greater<>()); // �������� ���� O(NlogN)

	int ans = 0;
	int count = 0;

	// array[0] ���� ū ��
	// array[1] �� ��°�� ū ��

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


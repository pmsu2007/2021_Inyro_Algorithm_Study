/*
������
���� ����
*/

#include <iostream>
#include <algorithm>
using namespace std;

int storage[100];
int memo[100];

void DP(int size)
{
	memo[0] = storage[0];
	memo[1] = max(storage[0],storage[1]);

	for (int i = 2; i < size; i++)
	{
		memo[i] = storage[i] + *max_element(memo, (memo + i - 1)); // �� �ּҴ� ���Ե��� ������ ����
	}
	// i ��° ������ �ִ�� �� �� �ִ� �ķ��� ��
}


int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> storage[i];
	}

	DP(N);
	cout << *max_element(memo, memo + N);
}

/*
4
1 3 1 5
*/
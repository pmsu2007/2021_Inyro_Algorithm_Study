/*
������
�� �迭�� ���� ��ü
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> A;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		A.push_back(input);
	}
	vector <int> B;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		B.push_back(input);
	}

	sort(A.begin(), A.end()); // ��������
	sort(B.begin(), B.end(), greater<int>()); // ��������

	for (int i = 0; i < K; i++)
	{
		if (A[i] < B[i])
		{
			swap(A[i], B[i]);
		}
	}

	int sum = 0;
	for (int i : A)
		sum += i;

	cout << sum;
}




/*
�迭 A�� ��������
�迭 B�� ��������

�� �ε��� ���� ���ؼ� B�� A���� ũ�� ��ü

*/
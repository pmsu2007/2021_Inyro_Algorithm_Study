/*
이코테
두 배열의 원소 교체
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

	sort(A.begin(), A.end()); // 오름차순
	sort(B.begin(), B.end(), greater<int>()); // 내림차순

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
배열 A는 오름차순
배열 B는 내림차순

각 인덱스 별로 비교해서 B가 A보다 크면 교체

*/
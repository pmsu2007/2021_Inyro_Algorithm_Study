/*
이코테
부품 찾기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binarySearch(vector<int>& arr, int key, int start, int end)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (arr[mid] == key)
		{
			cout << "yes ";
			return ;
		}
		else if (arr[mid] > key)
			end = mid - 1;
		else
			start = mid + 1;
	}
	cout << "no ";
}

int main()
{
	int N, M;

	cin >> N;
	vector<int> id(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> id[i];
	}

	sort(id.begin(), id.end());

	cin >> M;
	
	for (int i = 0; i < M; i++)
	{
		int key;
		cin >> key;
		binarySearch(id, key, 0, N);
	}

	return 0;
}
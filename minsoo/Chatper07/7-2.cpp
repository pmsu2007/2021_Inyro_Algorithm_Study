/*
ÀÌÄÚÅ×
¶±ººÀÌ ¶± ¸¸µé±â
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int findHeight(vector<int>& arr, int size, int target, int end) {
	int start = 0;
	
	while (start <= end)
	{
		int sum = 0;
		int mid = (start + end) / 2;

		for (int i = 0; i < size; i++)
		{
			if (arr[i] > mid)
			{
				sum += arr[i] - mid;
			}
		}

		if (sum == target)
			return mid;
		else if (sum > target)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return 0;
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int maxLength = *max_element(arr.begin(), arr.end());

	cout << findHeight(arr, N, M, maxLength);

}

/*
¼øÂ÷ Å½»ö : 10¾ï 
*/
/*
������
������ �Ʒ���
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> array;

	while (n--)
	{
		int input;
		cin >> input;
		array.push_back(input);
	}

	sort(array.begin(), array.end(), greater<int>());

	for (auto i : array)
		cout << i << " ";

	return 0;
}
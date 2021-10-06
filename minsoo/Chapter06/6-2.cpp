/*
이코테
성적이 낮은 순서로 학생 출력하기
*/

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<string, int>> studentList;

	while (n--)
	{
		string name;
		int score;

		pair<string, int> student;
		cin >> name >> score;

		student = { name, score };
		studentList.push_back(student);
	}

	sort(studentList.begin(), studentList.end(),compare);

	for (int i = 0; i < studentList.size(); i++)
	{
		cout << studentList[i].first << " ";
	}

	return 0;
}
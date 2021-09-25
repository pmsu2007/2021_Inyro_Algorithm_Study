/*
백준
럭키 스트레이트 18406번
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	string num = to_string(N); // int -> string

	int digit = num.length();

	int i;
	int front = 0;
	int back = 0;

	for (i = 0; i < digit / 2; i++)
	{
		front += num[i];
	}
	for (int j = i; j < digit ; j++)
	{
		back += num[j];
	}

	if (front == back)
		cout << "LUCKY";
	else
		cout << "READY";

	return 0;
}


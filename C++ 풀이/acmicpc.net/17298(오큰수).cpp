#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i;
	stack<int> NGE;

	cin >> n;
	int* Num = new int[n];
	int* prgNum = new int[n];

	for (i = 0; i < n; i++)
	{
		cin >> Num[i];
		prgNum[i] = -1;
	}

	for (i = n - 1; i >= 0; i--)
	{
		//cin >> Num[i]; -> 앞으로는 입력 따로 받아라 좀.

		while (!NGE.empty() && (NGE.top() <= Num[i])) { // *젤 아랫줄 참고
			NGE.pop();
		}

		if (!NGE.empty()) {
			prgNum[i] = NGE.top();
		}

		NGE.push(Num[i]);
	}

	for (i = 0; i < n; i++)
	{
		cout << prgNum[i] << ' ';
	}

	delete[] Num;
	delete[] prgNum;

}

// 3 5 8 7 일 경우는 5 8 -1 -1
// 3 5 7 7 일 경우 5 7 -1 -1로 나와야함
//// (NGE.top() < Num[i]) -> 요렇게 하면 5 7 7 -1로 출력됨으로 잘못됨.
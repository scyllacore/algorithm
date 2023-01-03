#include <iostream>
#include <stack>

using namespace std;


int numCnt[1000001] = { 0 }; // 배열 크기가 커지면 전역변수로 선언한다.

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i;

	cin >> n;

	int* num = new int[n + 1];
	int* NGF = new int[n + 1];
	stack<int> st;


	for (i = 1; i <= n; i++) {
		cin >> num[i];
		numCnt[num[i]]++;
		NGF[i] = -1;
	}

	for (i = n; i >= 1; i--) {

		while (!st.empty() && numCnt[num[i]] >= numCnt[st.top()]) {
			st.pop();
		}

		if (!st.empty())
		{
			NGF[i] = st.top();
		}

		st.push(num[i]);

	}

	for (i = 1; i <= n; i++)
	{
		cout << NGF[i] << ' ';
	}

	delete[] num;
	delete[] NGF;


}

//변수이름 잘못 사용한 것 같아서 바꿈
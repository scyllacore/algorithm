#include <iostream>
#include <queue>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k, i;
	queue<int> josephus;

	cin >> n >> k;

	cout << '<';

	for (i = 1; i <= n; i++)
	{
		josephus.push(i);
	}

	for (; !josephus.empty();)
	{
		for (i = 0; i < k - 1; i++)
		{
			josephus.push(josephus.front());
			josephus.pop();
		}

		if (josephus.size() != 1) {
			cout << josephus.front() << ", ";
		}
		else {
			cout << josephus.front() << '>';

		}
		josephus.pop();
	}


	return 0;

}

//1 2 3 4 5 6 7
//4 5 6 7 1 2
//7 1 2 4 5
//4 5 7 1
//1 4 5
//1 4
//4
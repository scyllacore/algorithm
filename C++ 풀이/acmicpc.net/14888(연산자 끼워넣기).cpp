#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define RANGE (int)1e9

int n, maxN = -RANGE, minN = RANGE;
int cal[4];
vector<int> numArr;

void dfs(int k, int resultSum)
{
	if (n <= k)
	{
		maxN = max(maxN, resultSum);
		minN = min(minN, resultSum);

		return;
	}

	if (cal[0] > 0)
	{
		cal[0]--;
		dfs(k + 1, resultSum + numArr[k]);
		cal[0]++;
	}
	if (cal[1] > 0)
	{
		cal[1]--;
		dfs(k + 1, resultSum - numArr[k]);
		cal[1]++;
	}
	if (cal[2] > 0)
	{
		cal[2]--;
		dfs(k + 1, resultSum * numArr[k]);
		cal[2]++;
	}
	if (cal[3] > 0)
	{
		cal[3]--;
		dfs(k + 1, resultSum / numArr[k]);
		cal[3]++;
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int i, tmp;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> tmp;
		numArr.push_back(tmp);
	}

	for (i = 0; i < 4; i++)
	{
		cin >> cal[i];
	}

	dfs(1, numArr[0]);

	cout << maxN << '\n';
	cout << minN;

	return 0;
}
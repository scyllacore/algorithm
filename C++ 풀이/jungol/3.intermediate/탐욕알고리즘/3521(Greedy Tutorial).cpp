#include <iostream>

using namespace std;

int main() {

	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

	int BWcnt[5]; //Balance weight
	int i, j, N, allCnt = 0, weight = 16;

	for (i = 0; i < 5; i++)
	{
		cin >> BWcnt[i];
	}

	cin >> N;

	int nWeight = N;

	for (i = 4; i >= 0; i--)
	{

		for (j = 1; j <= BWcnt[i]; j++)
		{
			if (nWeight == j * weight)
			{
				allCnt += j;
				cout << allCnt;
				return 0;
			}
			else if (nWeight < j * weight)
			{
				allCnt += j - 1;
				nWeight -= ((j - 1) * weight);
				break;
			}
		}
		if (BWcnt[i] == j - 1) { // nWeight > j * weight 일 때
			allCnt += j - 1;
			nWeight -= ((j - 1) * weight);
		}

		weight /= 2;
	}

	cout << "impossible";

	return 0;

}
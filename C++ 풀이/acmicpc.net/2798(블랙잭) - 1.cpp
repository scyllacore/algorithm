#include <iostream>
#include <vector>

using namespace std;

int sum, n;
vector<int> result;

int card[3];

void cardSearch(int top,int arr[],int cnt)
{
	int i;

	if (cnt == 3)
	{
		result.push_back(card[0] + card[1] + card[2]);
		return;
	}

	for (i = top; i < n; i++)
	{
		card[cnt] = arr[i];
		cardSearch(i + 1, arr, cnt + 1);
	}

}




int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int i;

	cin >> n >> sum;

	int* arr = new int[n];

	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cardSearch(0, arr, 0);
	

	for (; sum >= 10; sum--) {

		for (i = 0; i < result.size(); i++)
		{
			if (sum == result[i]) {
				cout << sum;
				return 0;
			}
		}

	}

}
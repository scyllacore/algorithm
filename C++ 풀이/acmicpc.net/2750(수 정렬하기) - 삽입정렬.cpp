#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i,j;

	cin >> n;

	int* arr = new int[n];

	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (i = 1; i < n; i++)
	{
		int data = arr[i];
		int index = i;

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] < data)
			{
				break;
			}
			arr[index--] = arr[j];
		}

		arr[index] = data;

	}

	for (i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}



}
#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, i, maxScore = 0;
	double sum = 0, avg;

	cin >> n;

	double* arr = new double[n];

	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (maxScore < arr[i]) {
			maxScore = arr[i];
		}
	}


	for (i = 0; i < n; i++)
	{
		arr[i] = arr[i] / maxScore * 100;
		sum += arr[i];
	}

	avg = sum / n;

	cout << avg;

	delete[] arr;

	return 0;

}
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;



int main()
{
	int n, i, j, result = 0;

	scanf("%d", &n);

	int* arr = new int[n] {0};

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	//1
	for (i = 0; i < n; i++)
	{
		result += arr[i];
	}

	int ans = round((double)result / n);

	printf("%d\n",ans);

	//2

	printf("%d\n", arr[n / 2]);

	//3

	int cnt[8001] = { 0 };
	int max = -1, idx = 0;
	vector<int> maxV;

	for (i = 0; i < n; i++)
	{
		cnt[arr[i] + 4000]++;
	}

	for (i = 0; i < 8001; i++)
	{
		if (cnt[i] > max)
		{
			max = cnt[i];
		}
	}

	int flag = 0;

	for (i = 0; i < 8001; i++)
	{
		if (cnt[i] == max)
		{
			maxV.push_back(i - 4000);
			flag++;
		}
	}

	//printf("*%d*\n", flag);

	if (flag == 1)
	{
		printf("%d\n", maxV[0]);
	}
	else if (flag > 1)
	{
		printf("%d\n", maxV[1]);
	}





	//4

	printf("%d", arr[n - 1] - arr[0]);


}

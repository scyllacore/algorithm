#include <iostream>

using namespace std;

int main()
{
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

	int n, i, j;
	unsigned long long cowSum=0;
	cin >> n;

	int cowArr[80000]={0};
	int height, top = 0;


	for (i = 0; i < n; i++)
	{
		cin >> height;

		while (top>0 && cowArr[top-1] <= height)
		{
			top--;
		}

		cowSum += top;
		cowArr[top++] = height;

	}

	cout << cowSum;

}

//소의 시점으로 머리를 보는 것이 아닌 , 그 소의 머리를 몇 마리가 볼 수 있는지 따진다.
#include <iostream>
#define N 500000

using namespace std;

struct transTwStack {
	int height, idx;
}transTwStack[N + 10];

int main()
{
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

	int transTower[N + 10]={0}, n, i, top = 0;
	int height;

	cin >> n;

	for (i = 1; i <= n; i++)
	{
		cin >> height;

		while (top > 0 && transTwStack[top - 1].height < height)
		{
			top--;
		}

		if(top>0)
		transTower[i] = transTwStack[top-1].idx;
		

		transTwStack[top].height = height;
		transTwStack[top++].idx = i;
	}

	for (i = 1; i <= n; i++)
	{
		cout << transTower[i] << ' ';
	}

}
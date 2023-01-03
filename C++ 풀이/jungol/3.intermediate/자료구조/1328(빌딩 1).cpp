#include <iostream>
#define MAX_N 100000 

using namespace std;

struct building {
	int height, idx;
}building[MAX_N];

int main()
{
	//cin.tie(NULL);
	//ios::sync_with_stdio(false);

	int buildingArr[MAX_N+10]={0};

	int n,height,i,j,top=0,  cnt = 0;
	cin >> n;

	for (i = 1; i <= n; i++)
	{
		cin >> height;


		while (top > 0 && building[top - 1].height < height)
		{
			top--;
			buildingArr[building[top].idx] = i;
		}

		building[top].height = height;
		building[top++].idx = i;



	}


	for (i = 1; i <= n; i++)
	{
		printf("%d\n", buildingArr[i]);
	}


}


//stack STL 써서 다시 풀이 할 것
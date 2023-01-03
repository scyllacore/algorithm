#include <iostream>
#include <memory.h>

using namespace std;

typedef struct people {
	int weight;
	int height;
	int rank;
}People;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n,i,j;

	cin >> n;

	People* p = new People[n];
	memset(p, 0, sizeof(People) * n);

	for (i = 0; i < n; i++)
	{
		cin >> p[i].weight >> p[i].height;
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (p[i].weight < p[j].weight && p[i].height < p[j].height)
			{
				p[i].rank++;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		cout << p[i].rank+1 << ' ';
	}



}
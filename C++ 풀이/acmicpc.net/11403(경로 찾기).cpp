#include <iostream>
#define MAX 100

using namespace std;

int n;
int graph[MAX][MAX];



void floyd(void)
{
	int i, j, k;

	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (graph[i][k] && graph[k][j])
					graph[i][j] = 1;
			}
		}
	}
}



int main(void) {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> n;

	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}


	floyd();

	for ( i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) {

			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;

}
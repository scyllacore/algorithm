#include <iostream>
#define N 100000

using namespace std;

int main() {

	//cin.tie(NULL);
	//ios::sync_with_stdio(false)

	int squareStack[N + 10];
	int i, j, n, top = 0;
	long long max = -1, width = 0;
	
	cin >> n;

	int* histogram = new int[n + 1]{ 0, };

	for (i = 0; i < n; i++) {
		cin >> histogram[i];
	}


	for (i = 0; i < n + 1; i++)
	{
		while (top > 0 && histogram[squareStack[top-1]] > histogram[i]) {
			j = squareStack[(top--)-1];

			if (top > 0)
			{
				width = i - squareStack[top-1]-1; // pop의 특성을 제대로 고려 못하여 [top]이라고 씀
			}
			else
			{
				width = i;
			}

			max = max < (histogram[j] * width) ? (histogram[j] * width) : max;
		//	cout << max << ' ';
		}
		squareStack[top++] = i;
		
	}

	cout << max;

	delete[] histogram;



}
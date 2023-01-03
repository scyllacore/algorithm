#include <stdio.h>
#include <stdbool.h>

int N;
int num[101];
int limit = 0;
bool used[101];

bool find(int ref, int idx) {
	if (limit > N) return false;
	if (ref == num[idx]) return true;
	else {
		++limit;
		return find(ref, num[idx]);
	}
}


int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
	}

	int i, sum = 0;

	for (i = 1; i <= N; i++)
		used[i] = false;

	for (i = 1; i <= N; i++) {
		limit = 0;
		if (find(i, i) == true) {
			used[i] = true;
			sum++;
		}
	}

	printf("%d\n", sum);
	for (i = 1; i <= N; i++)
		if (used[i] == true) printf("%d\n", i);

	return 0;

}
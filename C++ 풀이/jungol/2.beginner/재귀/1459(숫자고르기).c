#include <stdio.h>
#include <stdbool.h>

int N;
int num[101];
int limit = 0;
int cnt[101];
bool used[101];


bool find(int ref, int idx) {
	if (limit > N) return false;
	if (ref == num[idx]) return true;
	else {
		++limit;
		find(ref, num[idx]);
	}
}



void search(int ref, int idx) {
	used[idx] = true;
	if (ref == num[idx]) cnt[ref]++;
	else {
		cnt[ref]++;
		search(ref, num[idx]);
	}
}



int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
	}

	//printf("\nThe number of intergers: %d\n", N);
	//for (int i = 0; i < N; i++) printf("Value: %d\n", num[i]);

	int sum = 0;
	for (int k = 1; k <= N; k++) used[k] = false;
	for (int i = 1; i <= N; i++) {
		limit = 0;
		if (used[i] == true) continue;
		if (find(i, i) == true) {
			search(i, i);
			sum += cnt[i];
		}
	}

	printf("\nThe number of integers picekd up: %d\n", sum);
	for (int j = 1; j <= N; j++)
		if (used[j] == true) printf("Value: %d\n", j);

	return 0;

}
#include <stdio.h>

int n;

typedef struct grade {
	char name[10];
	int sub[3];
	int sum;
}Grade;


void swap(Grade* swap1, Grade* swap2)
{
	Grade copy;
	copy = *swap1;
	*swap1 = *swap2;
	*swap2 = copy;

}

void print(Grade* arr)
{
	int i, j;
	int sum = 0;

	for (i = 0; i < n; i++) {
		arr[i].sum = 0;
		for (j = 0; j < 3; j++) {
			arr[i].sum += arr[i].sub[j];
		}
	}

	for (i = 0; i < n; i++) {
		printf("%s ", arr[i].name);
		for (j = 0; j < 3; j++) {
			printf("%d ", arr[i].sub[j]);
		}
		printf("%d", arr[i].sum);
		printf("\n");
	}
}




void sort(Grade* arr)
{
	int i, j, k;
	int sum_i, sum_j;

	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {

			sum_i = 0, sum_j = 0;

			for (k = 0; k < 3; k++)
			{
				sum_i += arr[i].sub[k];
				sum_j += arr[j].sub[k];
			}


			if(sum_i<sum_j)
			{
				swap(&arr[i], &arr[j]);
			}
		}
	}
	print(arr);
}


int main()
{
	int i, j;
	scanf("%d", &n);
	Grade* p = (Grade*)malloc(sizeof(Grade) * n);

	for (i = 0; i < n; i++) {
		scanf(" %s", p[i].name);
		for (j = 0; j < 3; j++) {
			scanf("%d", &p[i].sub[j]);
		}
	}

	sort(p);

	return 0;
}
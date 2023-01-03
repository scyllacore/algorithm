# include <stdio.h>

typedef struct Person
{
	char name[21];
	int score;
	int rank;
}Person;

void swap(Person* swap1, Person* swap2)
{
	Person copy;
	copy = *swap1;
	*swap1 = *swap2;
	*swap2 = copy;

}

void print(Person* a)
{
	int i;
	printf("Name Score Rank\n");

	for (i = 0; i < 10; i++)
	{
		fprintf(stdout, "%4s %5d %4d\n", a[i].name, a[i].score, a[i].rank);
	}
}

void rank(Person* a) {
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (a[i].score < a[j].score)
			{
				a[i].rank++;
			}
		}
	}

	print(a);
}

void rank2(Person* a)
{
	int i, j, cnt = 0;;
	for (i = 0; i < 9; i++)
		for (j = i + 1; j < 10; j++)
			if (a[i].score < a[j].score)
				swap(&a[i], &a[j]);

	for (i = 1; i < 10; i++)
	{
		a[i].rank = i+1;

		if(a[i].score == a[i - 1].score)
		{
			a[i].rank = (a[i - 1].rank);
		}

	}


	print(a);
}




int main()
{
	Person p[10],p2[10];
	int i, j;

	for (i = 0; i < 10; i++)
	{
		fscanf(stdin, "%s %d", p[i].name, &p[i].score);
		p[i].rank = 1;
	}

	memcpy(&p2, &p, sizeof(Person)*10);

	rank(p);
	printf("\n");
	rank2(p2);

	return 0;
}
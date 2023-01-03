#include <stdio.h>
#include <conio.h>

typedef struct file_rw
{
	FILE* read;
	FILE* write;
}file;

file fp;

typedef struct Person
{
	char name[21];
	int score;
	int rank;
}Person;

int file_open()
{
	fp.read = fopen("input628.txt", "rt");
	fp.write = fopen("output628.txt", "wt");

	if (fp.read == NULL) {
		printf("파일열기 실패\n");
		return 0;
	}
	else {
		printf("파일열기 성공\n");
		return 1;
	}

}



void swap(Person* swap1, Person* swap2)
{
	Person copy;
	copy = *swap1;
	*swap1 = *swap2;
	*swap2 = copy;

}

void print(Person* p)
{
	int i;
	fprintf(fp.write,"Name Score Rank\n");

	for (i = 0; i < 10; i++)
	{
		fprintf(fp.write, "%4s %5d %4d\n", p[i].name, p[i].score, p[i].rank);
	}

	fprintf(fp.write, "\n");
}

void rank(Person* p) {
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (p[i].score < p[j].score)
			{
				p[i].rank++;
			}
		}
	}

	print(p);
}

void rank2(Person* p)
{
	int i, j, cnt = 0;;
	for (i = 0; i < 9; i++)
		for (j = i + 1; j < 10; j++)
			if (p[i].score < p[j].score)
				swap(&p[i], &p[j]);

	for (i = 1; i < 10; i++)
	{
		p[i].rank = i + 1;

		if (p[i].score == p[i - 1].score)
		{
			p[i].rank = (p[i - 1].rank);
		}

	}


	print(p);
}




int main()
{
	if (file_open() == 0) {
		_getche();
		return -1;
	}

	Person p1[10], p2[10];
	int i, j;

	for (i = 0; i < 10; i++)
	{
		fscanf(fp.read, "%s %d", p1[i].name, &p1[i].score);
		p1[i].rank = 1;
	}

	memcpy(&p2, &p1, sizeof(Person) * 10);

	rank(p1);
	rank2(p2);


	_fcloseall();
	_getche();

	return 0;
}
#include <stdio.h>
#include <stdlib.h>


struct Data
{
	int value;
	struct Data* next; // 자신과 똑같은 형태의 구조체만을 가르킬 수 있다.

}head;


int stackCount;

int input(int data)
{
	//1.new data allocate
	struct Data* newData;

	//printf("%d\n", sizeof(newData->next));

	if ((newData = malloc(sizeof(struct Data))) == NULL)
	{
		return 0;
	}

	//2.데이터 입력
	newData->value = data;

	//3.head의 next를 new Data의 next로 연결
	newData->next = head.next;

	//4.head의 next로 new Data 연결
	head.next = newData;

	//5.stack count 증가
	stackCount++;
}

void out()
{

	if (stackCount == 0)
	{
		printf("empty\n");
		return;
	}

	struct Data* popData = head.next;
	printf("%d\n", head.next->value);

	//1.head의 next를 popData의 next로 연결.
	head.next = popData->next;
	//2. stack Count --;
	free(popData);
	stackCount--;


}

void getCount()
{
	printf("%d\n", stackCount);
}


int main()
{
	int N = 0;
	int value;
	char cmd;

	stackCount = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf(" %c", &cmd);

		switch (cmd)
		{

		case 'i':
			scanf(" %d", &value);
			input(value);
			break;

		case 'o':
			out();
			break;

		case 'c':
			getCount();
			break;
		}
	}
	return 0;
}

//https://ledgku.tistory.com/85?category=891589
//자기참조구조체
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct equipment {
	char wear[21];
	char type[21];
	int typeIdx;
}Equip;


int wearCheck(Equip* equipNum, int wearN) {

	if (wearN == 0)
	{
		return 0;
	}


	int arr[101] = { 0,1 };
	int i, j, cnt = 2, flag, sum = 1;

	equipNum[1].typeIdx = 1;



	for (i = 2; i <= wearN; i++)
	{
		flag = 0;
		for (j = i - 1; j >= 1; j--)
		{
			if (strcmp(equipNum[i].type, equipNum[j].type) == 0)
			{
				equipNum[i].typeIdx = equipNum[j].typeIdx;
				arr[equipNum[i].typeIdx]++;
				flag = 1;
				break;
			}

		}
		if (flag != 1) {
			equipNum[i].typeIdx = cnt++;
			arr[equipNum[i].typeIdx]++;
		}

	}

	for (i = 1; i < cnt; i++)
	{
		arr[i]++;
		sum *= arr[i];
	}

	return sum - 1;

}

int main()
{
	int n, i, j, wearN;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &wearN);



		Equip* equipNum = malloc(sizeof(Equip) * (wearN + 1));

		for (j = 1; j <= wearN; j++)
		{
			scanf(" %s %s", equipNum[j].wear, equipNum[j].type);

		}

		printf("%d\n", wearCheck(equipNum, wearN));
		
		free(equipNum);

	}

}
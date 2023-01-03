#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int Element;

typedef struct DNode
{
	Element Data;
	struct DNode* PrevNode;
	struct DNode* NextNode;
} DNode;

/*  노드 생성 */
DNode* DLL_CreateNode(Element NewData)
{
	DNode* NewNode = (DNode*)malloc(sizeof(DNode));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

/*  노드 소멸 */
void DLL_DestroyNode(DNode* Node)
{
	free(Node);
}

/*  노드 추가 */
void DLL_AppendNode(DNode** Head, DNode* NewNode)
{
	/*  헤드 노드가 NULL이라면 새로운 노드가 Head */
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		/*  테일을 찾아 NewNode를 연결한다. */
		DNode* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail; /*  기존의 테일을 새로운 테일의 PrevNode가 가리킨다. */
	}
}

/*  노드 삽입 */
void DLL_InsertAfter(DNode* Current, DNode* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}

/*  노드 제거 */
void DLL_RemoveNode(DNode** Head, DNode* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
		if ((*Head) != NULL)
			(*Head)->PrevNode = NULL;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		DNode* Temp = Remove;

		if (Remove->PrevNode != NULL)
			Remove->PrevNode->NextNode = Temp->NextNode;

		if (Remove->NextNode != NULL)
			Remove->NextNode->PrevNode = Temp->PrevNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

/*  노드 탐색 */
DNode* DLL_GetNodeAt(DNode* Head, int Location)
{
	DNode* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

/*  노드 수 세기 */
int DLL_GetNodeCount(DNode* Head)
{
	unsigned int  Count = 0;
	DNode *Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

void PrintNode(DNode* _Node)
{
	if (_Node->PrevNode == NULL)
		printf("Prev: NULL");
	else
		printf("Prev: %d", _Node->PrevNode->Data);

	printf(" Current: %d ", _Node->Data);

	if (_Node->NextNode == NULL)
		printf("Next: NULL\n");
	else
		printf("Next: %d\n", _Node->NextNode->Data);
}

void DLL_Insertion_Sort(DNode **phead)
{
	DNode *head = *phead; // 리스트의 시작점을 저장한다.

	// 탐색을 위한 포인터, 계속해서 바뀔 예정이며 첫 탐색 대상은 당연히 head노드다.
	DNode *search = head;

	// 탐색 대상의 다음 노드를 가리키는 포인터, 사실상 이 포인터가 진정한 기준점이다.
	// 일반 삽입정렬 알고리즘에서도 두 개씩 비교를하는데, 우측 대상을 기준으로 비교를 했으니 논리는 동일하다.
	DNode *next = search->NextNode;

	// 우리가 일반 삽입정렬 알고리즘에서 봤듯이, 정렬이 안되어 있다면 적당한 위치를 찾게 되는데
	// 적당한 위치를 찾는 건 데이터 집합의 0번째 요소부터 비교했었다.
	// 따라서 head부터 현재노드까지 탐색을 담당해줄 포인터가 필요한데, 그것을 find로 설정했다.
	DNode *find = head; // 두 번째 while문에서 쓰일 예정이다.

	Element e1, e2; // 비교를 위한 변수, e2는 기준점으로 쓰일 것이다.
	// e2는 일반 삽입정렬 알고리즘의 value와 같은 역할을 한다. 기준점인 next노드의 값을 가질 예정이다.

	// 더블링크드리스트의 경우 배열처럼 크기를 한 번에 알아낼 수 없으므로
	// 헤드포인터를 계속해서 넘겨줌으로써 NULL에 도달할 때까지 반복해서 비교해야 한다.
	while (next) // 기준노드인 next가 NULL이 될 때까지 반복한다.
	{
		e1 = search->Data; // 탐색 대상의 데이터를 e1에 저장
		e2 = next->Data; // 탐색 다음 대상의 데이터를 e2에 저장, 사실상의 기준데이터

		if (e1 <= e2) // 정렬이 되어 있는 상황
		{
			search = next; // 탐색노드를 다음으로 이동
			next = next->NextNode; // 마찬가지로 다음 노드로 이동해준다.
			continue; // 아래의 실행문들을 실행하지 않고 다시 while문으로 올라간다.
		}

		// 이하의 진행은 정렬이 안되어 있는 상태일 때 진행된다.
		// 현재 빼낼 노드는 next다. 빼져있는 상황을 상정하기 위한 작업이 아래 작업이다.

		// next의 전 노드인 search와 next의 다음 노드를 연결해준다.
		search->NextNode = next->NextNode;

		// next의 다음 노드가 만약 NULL이 아니라면 그 다음노드의 전 노드를 search로 설정해준다.
		if (next->NextNode != NULL)
			next->NextNode->PrevNode = search;
		// 이로써 중간에 있는 next가 쏙 빠져있다고 생각할 수 있다. 더블링크드리스트의 삭제연산과 동일하다.

		// 어디에 위치시키는 게 좋을지를 정하는 과정이다.
		// 빼낸 값을 헤드노드부터 쭈욱 비교하기 시작한다.
		while (find != search->NextNode) // 탐색 대상의 노드까지 처음부터 탐색한다.
		{
			// find != next 가 안되는 이유는, 이미 위에서 next를 분리해내는 작업을 했기 때문이다.
			// 여기서의 next는 이미 빼져 있는 노드여서 search의 다음 노드를 가리키는 의미를 상실한다.
			// 따라서 while문의 조건을 find != search->NextNode 로 해주는 것이 맞다.

			// 현재 비교 주체인 next의 데이터와 비교하기 위해 find의 데이터를 추출한다.
			e1 = find->Data;

			// 적절한 위치(find)를 발견, find의 좌측에 위치하게끔 포인터를 조작한다.
			if (e1 > e2)
			{
				//next: 현재 빼낸 노드, 적절한 위치에 삽입을 해줘야한다.
				next->NextNode = find;  // find의 좌측에 위치하게끔 포인터를 조작한다.
				next->PrevNode = find->PrevNode;

				// 만약 find의 전 노드가 존재한다면 그 전노드의 다음 노드를 next로 설정해준다.
				if (find->PrevNode != NULL)
					find->PrevNode->NextNode = next;
				// find의 전 노드를 next로 설정해줌으로써 next를 find 좌측에 위치시키는 작업을 끝냈다.
				find->PrevNode = next;

				// 만약 next가 위치한 곳이 새로운 head일 경우 새로운 head로 갱신해줘야 한다.
				if (find == head) // 만약 find가 이전의 헤드노드 였다면
					// 탐색 대상이되는 next가 새로운 헤드노드로 등극한다.
					head = next;

				// 옮기는 작업을 완료했으므로
				// 다음 탐색을 위해 find를 다시 헤드노드를 가리키게 만들어준다.
				find = head;
				break;
			}
			// 적절한 위치를 찾지 못했으므로 find를 다음 노드로 이동한다.
			// 삽입정렬의 비교시 첫 데이터부터 비교하던 것과 같은 이치다. 첫데이터를 비교했다면 다음으로 이동해 비교한다.
			find = find->NextNode;
		}
		// 탐색 대상인 노드를 새롭게 갱신해준다. next는 이제 다시 search의 다음 노드로서의 의미를 지닌다.
		next = search->NextNode;
	}
	// 최종적으로 이 알고리즘이 시행됐을 때 head값은 처음의 head값과 많이 달라져있을 것이다.
	// 따라서 List의 본래 헤드를(*phead) 변경된 head값을 가지게끔 만들어준다.
	*phead = head;
}

int main(void)
{
	int   i = 0;
	int   Count = 0;
	int rNum = 0;
	DNode* List = NULL;
	DNode* NewNode = NULL;
	DNode* Current = NULL;

	/*  노드 5개 추가 */
	srand(time(NULL));

	for (i = 0; i < 5; i++) { // 랜덤으로 생성된 값을 갖는 노드를 5개 생성한다.
		rNum = (double)rand() / (double)RAND_MAX * 50;
		NewNode = DLL_CreateNode(i + rNum);
		DLL_AppendNode(&List, NewNode);
	}

	/*  리스트 출력 */
	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	// 삽입 정렬 시행
	DLL_Insertion_Sort(&List);
	printf("\n\n정렬된 결과를 출력합니다.\n");

	/*  리스트 출력 */
	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	/*  모든 노드를 메모리에서 제거     */
	printf("\nDestroying List...\n");

	Count = DLL_GetNodeCount(List);

	for (i = 0; i < Count; i++)
	{
		Current = DLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}

	return 0;
}

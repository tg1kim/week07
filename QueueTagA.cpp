#include <stdio.h>

#define N 	10
#pragma warning(disable: 4326 4996 6031)

typedef int Item;

typedef struct {
	Item items[N];
	int nFront;
	int nRear;
	int isFull;
}	Queue, *QueuePtr;

void main()
{
	int  IsEmptyQueue(QueuePtr pQueue);
	int  IsFullQueue(QueuePtr pQueue);
	int  AddQueue(QueuePtr pQueue, Item nItem);
	int  DeleteQueue(QueuePtr pQueue, Item *pItem);
	void PrintQueue(QueuePtr pQueue);
	int  Error(const char *sMsg);

	/** Create Queue **/
	Queue aQueue;
	aQueue.nFront = aQueue.nRear = aQueue.isFull = 0;

	while (1) {
		int value;
		printf("-2:Exit -1:Delete, 0~:Add ? ");
		scanf("%d", &value);
		if (value < -1)
			break;
		else if (value == -1) {
			if (DeleteQueue(&aQueue, &value) == false)
				Error("empty");
			else
				printf("%d is deleted\n", value);
		}
		else {
			if (AddQueue(&aQueue, value) == false)
				Error("full");
			else
				printf("%d is inserted\n", value);
		}
		PrintQueue(&aQueue);
	}
}

int IsEmptyQueue(QueuePtr pQueue)
{	// ť�� ��������� ���� T/F�� ��ȯ�Ѵ�.
	return pQueue->nFront == pQueue->nRear && pQueue->isFull == false;
}

int IsFullQueue(QueuePtr pQueue)
{	// ť�� ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return pQueue->nRear == pQueue->nFront && pQueue->isFull;
}

int AddQueue(QueuePtr pQueue, Item nItem)
{	// ť�� nItem�� �߰��ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsFullQueue(pQueue))
		return false;
	pQueue->items[pQueue->nRear = (pQueue->nRear + 1) % N] = nItem;	// rear�� �����Ͽ� ����
	pQueue->isFull = true;
	return true;
}

int DeleteQueue(QueuePtr pQueue, Item *pItem)
{	// ť���� �����Ͽ� pItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	if (IsEmptyQueue(pQueue))
		return false;
	*pItem = pQueue->items[pQueue->nFront = (pQueue->nFront + 1) % N];	// front�� �����Ͽ� �޾Ƴ�
	pQueue->isFull = false;
	return true;
}

void PrintQueue(QueuePtr pQueue)
{
	int nCtr = (pQueue->nRear - pQueue->nFront + N) % N;
	nCtr += IsFullQueue(pQueue) * N;
	for (int i = 1; i <= nCtr; i++)
		printf("--%d-", (pQueue->nFront + i) % N);
	printf("--\n");
	for (int i = 1; i <= nCtr; i++)
		printf("%3d ", pQueue->items[(pQueue->nFront + i) % N]);
	printf("\n");
	for (int i = 1; i <= nCtr; i++)
		printf("----");
	printf("--\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Queue is %s. *****\n", sMsg);
	return -1;
}
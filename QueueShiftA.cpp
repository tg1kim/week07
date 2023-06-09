#include <stdio.h>

#define N 10
#pragma warning(disable: 4326 4996 6031)

typedef int Item;

typedef struct {
	Item items[N];
	int nFront;
	int nRear;
}	Queue, *QueuePtr;

void main()
{
	int  IsEmptyQueue(QueuePtr pQueue);
	int  IsFullQueue(QueuePtr pQueue);
	int  AddQueue(QueuePtr pQueue, Item nItem);
	int  DeleteQueue(QueuePtr pQueue, Item& anItem);
	void PrintQueue(QueuePtr pQueue);
	int  Error(const char *sMsg);

	/** Create Queue **/
	Queue aQueue;
	aQueue.nFront = aQueue.nRear = -1;
	while (1) {
		int value;
		printf("-2:Exit -1:Delete, 0~:Add ? ");
		scanf("%d", &value);
		if (value < -1)
			break;
		if (value == -1) {
			if (DeleteQueue(&aQueue, value) == false)
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
{	// 큐가 비었는지에 따라 T/F를 반환한다.
	return pQueue->nFront == pQueue->nRear;
}

int IsFullQueue(QueuePtr pQueue)
{	// 큐가 가득 찼는지에 따라 T/F를 반환한다.
	int  CanShift(QueuePtr pQueue);
	return pQueue->nRear == N - 1 && CanShift(pQueue) == false;
}

int CanShift(QueuePtr pQueue)
{	// 빈 공간이 있으면 데이터를 이동시키는데 큐의 가득 여부에 따라 T/F를 반환한다.
	if (pQueue->nFront == -1)
		return false;
	for (int i = 0, j = pQueue->nFront + 1; j <= pQueue->nRear; i++, j++)
		pQueue->items[i] = pQueue->items[j];
	pQueue->nRear -= pQueue->nFront + 1;
	pQueue->nFront = -1;
	return true;
}

int AddQueue(QueuePtr pQueue, Item nItem)
{	// 큐에 nItem을 추가하는데 승패에 따라 T/F를 반환한다.
	if (IsFullQueue(pQueue))
		return false;
	pQueue->items[++pQueue->nRear] = nItem;		// rear를 증가하여 삽입
	return true;
}

int DeleteQueue(QueuePtr pQueue, Item& nItem)
{	// 큐에서 삭제하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
	if (IsEmptyQueue(pQueue))
		return false;
	nItem = pQueue->items[++pQueue->nFront];	// front를 증가하여 받아냄
	if (IsEmptyQueue(pQueue))
		pQueue->nFront = pQueue->nRear = -1;
	return true;
}

void PrintQueue(QueuePtr pQueue)
{
	for (int i = pQueue->nFront + 1; i <= pQueue->nRear; i++)
		printf("--%d-", i);
	printf("--\n");
	for (int i = pQueue->nFront + 1; i <= pQueue->nRear; i++)
		printf("%3d ", pQueue->items[i]);
	printf("\n");
	for (int i = pQueue->nFront + 1; i <= pQueue->nRear; i++)
		printf("----");
	printf("--\n\n");
}

int Error(const char *sMsg)
{
	printf("***** Queue is %s. *****\n", sMsg);
	return -1;
}

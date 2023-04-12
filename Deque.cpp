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
	int  JumpInQueue(QueuePtr pQueue, Item nItem);
	int  DeleteQueue(QueuePtr pQueue, Item& nItem);
	int  MagnanimousQueue(QueuePtr pQueue, Item& nItem);
	void PrintQueue(QueuePtr pQueue);
	int  Error(const char *sMsg);

	/** Create Queue **/
	Queue aQueue;
	aQueue.nFront = aQueue.nRear = 0;

	while (1) {
		int value;
		printf("-3:��, -2:�纸, -1:����, 0~999:����, *:��ġ�� ? ");
		scanf("%d", &value);
		if (value < -2)
			break;
		else if (value == -2) {
			if (MagnanimousQueue(&aQueue, value) == false)
				Error("empty");
			else
				printf("%d is deleted(�纸)\n", value);
		}
		else if (value == -1) {
			if (DeleteQueue(&aQueue, value) == false)
				Error("empty");
			else
				printf("%d is deleted(����)\n", value);
		}
		else if (value < 1000) {
			if (AddQueue(&aQueue, value) == false)
				Error("full");
			else
				printf("%d is inserted(����)\n", value);
		}
		else {
			if (JumpInQueue(&aQueue, value %= 1000) == false)
				Error("full");
			else
				printf("%d is inserted(��ġ��)\n", value);
		}
		PrintQueue(&aQueue);
	}
}

int IsEmptyQueue(QueuePtr pQueue)
{	// ť�� ��������� ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int IsFullQueue(QueuePtr pQueue)
{	// ť�� ���� á������ ���� T/F�� ��ȯ�Ѵ�.
	return true;
}

int AddQueue(QueuePtr pQueue, Item nItem)
{	// ť�� nItem�� �߰��ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	// rear�� �����Ͽ� ����
	return true;
}

int JumpInQueue(QueuePtr pQueue, Item nItem)
{	// ť�� nItem�� �ճ��� ��ġ���ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	// front�� item�� �ְ� ����
	return true;
}

int DeleteQueue(QueuePtr pQueue, Item& nItem)
{	// ť���� �����Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	// front�� �����Ͽ� �޾Ƴ�
	return true;
}

int MagnanimousQueue(QueuePtr pQueue, Item& nItem)
{	// ť���� �ڳ��� �����Ͽ� nItem�� �����ϴµ� ���п� ���� T/F�� ��ȯ�Ѵ�.
	// rear�� item�� �޾Ƴ��� ����
	return true;
}

void PrintQueue(QueuePtr pQueue)
{
	int nCtr = (pQueue->nRear - pQueue->nFront + N) % N;
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

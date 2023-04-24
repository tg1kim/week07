#include <stdio.h>

#define N 10
#pragma warning(disable: 4326 4996 6031)

typedef int Item;

void main()
{
	int  IsEmptyStack(int nTop);
	int  IsFullStack(int nTop);
	int  Push(Item items[], int& nTop, Item nItem);
	int  Pop(Item items[], int& nTop, Item & nItem);
	void PrintStack(Item items[], int nTop);
	int  Error(const char* sMsg);

	/** Create Stack **/
	Item items[N];
	int nTop;

	nTop = -1;
	while (1) {
		Item value;
		printf("-2:Exit -1:Pop, *:Push ? ");
		scanf("%d", &value);
		if (value < -1)
			break;
		if (value == -1) {
			if (Pop(items, nTop, value) == false)
				Error("empty");
			else
				printf("%d is deleted\n", value);
		}
		else {
			if (Push(items, nTop, value) == false)
				Error("full");
			else
				printf("%d is inserted\n", value);
		}
		PrintStack(items, nTop);
	}
}

int IsEmptyStack(int nTop)
{	// 스택이 비었는지에 따라 T/F를 반환한다.
	return nTop == -1;
}

int IsFullStack(int nTop)
{	// 스택이 가득 찼는지에 따라 T/F를 반환한다.
	return nTop == N - 1;
}

int Push(Item items[], int& nTop, Item nItem)
{	// 스택에 nItem을 push하는데 승패에 따라 T/F를 반환한다.
	// top을 증가하여 삽입
	if (IsFullStack(nTop))
		return false;
	items[++nTop] = nItem;
	return true;
}

int Pop(Item items[], int& nTop, Item& nItem)
{	// 스택에서 pop하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
	// 받아내고 top을 감소
	if (IsEmptyStack(nTop))
		return false;
	nItem = items[nTop--];
	return true;
}

void PrintStack(Item items[], int nTop)
{
	printf("|    |\n");
	for (int i = nTop; i >= 0; i--)
		printf("|%3d |\n", items[i]);
	printf("+----+\n\n");
}

int Error(const char* sMsg)
{
	printf("***** Stack is %s. *****\n", sMsg);
	return false;
}

#include <iostream>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x): label(x), next(NULL), random(NULL) { }
};

RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == NULL) return NULL;
	RandomListNode *pNode = pHead;
	RandomListNode *pCloneHead = new RandomListNode(pNode->label);
	RandomListNode *pCloneNode = pCloneHead;
	while (pNode != NULL)
	{
		RandomListNode *pClonedTail = new RandomListNode(pNode->label);
		pClonedTail->next = pNode->next;
		pNode->next = pClonedTail;
		pNode = pClonedTail->next;
	}
	pNode = pHead;
	while (pNode != NULL)
	{
		pCloneNode = pNode->next;
		pCloneNode->random = pNode->random->next;
		pNode = pNode->next->next;
		pCloneNode = pCloneNode->next;
	}
	pNode = pHead;
	while (pNode != NULL)
	{
		pNode->next = pNode->next->next;
		pNode = pNode->next;
	}
	return pCloneHead;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
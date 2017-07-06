#include <vector>
#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
{
	ListNode *pTmp1 = pHead1;
	ListNode *pTmp2 = pHead2;
	int length1 = 0, length2 = 0;
	while(pTmp1 != NULL)
	{
		length1++;
		pTmp1 = pTmp1->next;
	}
	while(pTmp2 != NULL)
	{
		length2++;
		pTmp2 = pTmp2->next;
	}
	if (pTmp1 > pTmp2)
	{
		int tmp = length1-length2;
		for (int i = 0; i < tmp; i++)
			pTmp1 = pTmp1->next;
		tmp = length1-tmp;
		while(tmp--)
			if (pTmp1->val == pTmp2->val)
				return pTmp1;
			else { pTmp1 = pTmp1->next; pTmp2 = pTmp2->next; }
	}
	else
	{
		int tmp = length2-length1;
		for (int i = 0; i < tmp; i++)
			pTmp2 = pTmp2->next;
		tmp = length2-tmp;
		while(tmp--)
			if (pTmp1->val == pTmp2->val)
				return pTmp1;
			else { pTmp1 = pTmp1->next; pTmp2 = pTmp2->next; }
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
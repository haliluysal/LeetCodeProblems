// ConsoleApplication1.cpp: Konsol uygulamasının giriş noktasını tanımlar.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

/**
* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	ListNode* generateLinkedList(int value, ListNode *head, ListNode *curr)
	{
		ListNode *temp = new ListNode(value); // (dummy + elde);
		if (head != NULL)
		{
			curr = head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}
		else
		{
			head = temp;
			curr = temp;
		}
		return head;
	}

	ListNode* updateList(ListNode *currL1, ListNode *currL2, ListNode *head, ListNode *curr, int &elde)
	{
		
		int sum = 0;
		int val1 = 0;
		int val2 = 0;
		int dummy = 0;

		if (currL1 != NULL)
			val1 = currL1->val;

		if (currL2 != NULL)
			val2 = currL2->val;

		sum = val1 + val2 + elde;
		dummy = sum % 10;

		head = generateLinkedList(dummy, head, curr);

		if (sum > 9)
		{
			elde = 1;
		}
		else
		{
			elde = 0;
		}

		return head;
	}

	ListNode* checkElde(ListNode *head, ListNode* curr, int elde)
	{
		if (elde == 1)
		{
			head = generateLinkedList((elde), head, curr);
		}
		return head;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		int elde = 0;
		ListNode *head = NULL;
		ListNode *curr = NULL;
		ListNode *currL1 = l1;
		ListNode *currL2 = l2;

		while (currL1 != NULL || currL2 != NULL)
		{
			head = updateList(currL1, currL2, head, curr, elde);
			if (currL1 != NULL)
				currL1 = currL1->next;
			if (currL2 != NULL)
				currL2 = currL2->next;
		}
		head = checkElde(head, curr, elde);
		return head;
	}
};


int main()
{
	Solution s;
	int val;
	ListNode *l1 = NULL;
	ListNode *currL1 = NULL;
	ListNode *l2 = NULL;
	ListNode *currL2 = NULL;

	for (size_t ii = 0; ii < 2; ii++)
	{
		cin >> val;
		l1 = s.generateLinkedList(val, l1, currL1);
	}
	for (size_t ii = 0; ii < 1; ii++)
	{
		cin >> val;
		l2 = s.generateLinkedList(val, l2, currL2);
	}

	ListNode *head = s.addTwoNumbers(l1, l2);

    return 0;
}


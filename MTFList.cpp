#include "MTFList.h"

bool MTFList::contains(int anEntry) {
	if (size == 0) 
        return false;

	Node *preNode = head, *node = head->next;
	while (node != NULL) {
		++traverseCount;
		if (anEntry == node->data) {
			preNode->next = node->next;
			node->next = head->next;
			head->next = node;
			return true;
		} else {
			preNode = node;
			node = node->next;
		}
	}
	return false;
}
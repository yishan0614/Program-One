#pragma once

#include <cstddef>
#include "IList.h"

#pragma once
typedef struct Node {
	Node() : data(0), next(NULL) {}

	int data;
	Node *next;
} 
Node;

class LinkedList : public IList {
public :
	LinkedList() : head(new Node()), size(0) {}

	virtual int getCurrentSize() const;

	virtual bool isEmpty() const;

	virtual bool add(int newEntry);

	virtual bool remove(int anEntry);

	virtual void clear();

	virtual bool contains(int anEntry);

protected:
	Node *head;
	int size;
};

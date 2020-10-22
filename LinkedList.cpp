#include "LinkedList.h"

int LinkedList::getCurrentSize() const {
	return size;
}

bool LinkedList::isEmpty() const {
	return size == 0;
}

bool LinkedList::add(int newEntry) {
	Node *node = new Node();
	node->data = newEntry;
	if (node == NULL) {
		return false;
	} else {
		node->next = head->next;
		head->next = node;
		++size;
		return true;
	}
}

bool LinkedList::remove(int anEntry){
    if (head -> data == anEntry){//first node delete
        Node* temp  = head;
        head = head -> next;
        delete temp;
        temp = nullptr;
        return true;
    }if (head -> next){//list has more than 1 node
        Node* lead = head -> next;
        Node* current = head;
        while (lead -> next){
            if(lead -> data == anEntry){
                current -> next = lead -> next;
                Node* temp = lead;
                lead = lead -> next;
                delete temp;
                temp = nullptr;
                if(lead -> next){
                    lead = lead -> next;
                    current = current -> next;
                }
            }else{
                lead = lead -> next;
                current = current -> next;
             }
        }
        if (lead -> data == anEntry){//now lead is the last node
        
            current -> next = nullptr;
            delete lead;
            lead = nullptr;
        }
    }
    return true;
}

//clear
void LinkedList::clear(){
    Node* iterator = head;
    
    while (iterator != 0){
        head = iterator->next;
        delete iterator;
        iterator = head;
    }
}// end clear

//contains
bool LinkedList::contains(int anEntry) {
	if (size == 0) 
           return false;
	
  Node *node = head->next;
	while (node != NULL) {
		++traverseCount;
		if (anEntry == node->data) 
                   return true;
		else node = node->next;
	}
	return false;
}

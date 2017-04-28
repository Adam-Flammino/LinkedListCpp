// pc2.cpp : Defines the entry point for the console application.
// Adam Flammino sdev-340 4/17
// Creates a linked list, searches for value and returns position on list if one exists

#include "stdafx.h"
#include <iostream>

void printIsMember(double x, bool flag);
void printSearch(double x, int pos);

class LinkedList {
	struct ListNode {
		double value;
		ListNode *next;
	public:
		ListNode(double x, ListNode *nextp = NULL) {
			value = x;
			next = nextp;
		}
	};
	ListNode *head;
public:
	// Constructor
	LinkedList() {
		head = NULL;
	}
	// Add to end of list
	void add(double x) {
		if (head == NULL) {
			head = new ListNode(x);
		}
		else {
			ListNode *last = head;
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = new ListNode(x);
		}
	};

	// Check if a value is on the list
	bool isMember(double x) {
		ListNode *nodePtr = head;
		while (nodePtr) {
			if (x == nodePtr->value) {
				return true;
			}
			nodePtr = nodePtr->next;
		}
		return false;
	}

	// Check if a value is on the list, return its position if it is
	int search(double x) {
		ListNode *nodePtr = head;
		int i = 0;
		while (nodePtr) {
			if (x == nodePtr->value) {
				return i;
			}
			i++;
			nodePtr = nodePtr->next;
		}
		return -1;
	}
};




int main()
{
	bool flag;
	int pos;
	double a = 5;
	double b = -1;
	double c = 13.7;
	double d = 3;
	LinkedList linkedlist;
	linkedlist.add(a);
	linkedlist.add(b);
	linkedlist.add(c);
	pos = linkedlist.search(a);
	printSearch(a, pos);
	pos = linkedlist.search(d);
	printSearch(d, pos);
	pos = linkedlist.search(c);
	printSearch(c, pos);
	return 0;
}

//Prints whether a value is flagged
void printIsMember(double x, bool flag) {
	if (flag) {
		std::cout << x << " is a member of the linked list.\n";
	}
	else {
		std::cout << x << " is not a member of the linked list.\n";
	}
}

//Prints position if one exists, says not on list if it isn't
void printSearch(double x, int pos) {
	if (pos == -1) {
		std::cout << x << " is not on the list.\n";
	}
	else {
		std::cout << x << " is on the list in postition " << pos << ".\n";
	}
}

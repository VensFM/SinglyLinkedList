#pragma once

#include <iostream>

class SinglyLinkedList
{
public:
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList& list)noexcept;
	SinglyLinkedList(SinglyLinkedList&& list)noexcept;
	~SinglyLinkedList();

	bool insert(int x);
	bool search(int x)const;
	bool remove(int x);

	void merge(SinglyLinkedList& list);
	void remove(const SinglyLinkedList& list);
	friend SinglyLinkedList getIntersection(const SinglyLinkedList& list1, const SinglyLinkedList& list2);

	SinglyLinkedList& operator = (const SinglyLinkedList& list);
	SinglyLinkedList& operator = (SinglyLinkedList&& list)noexcept;

	friend std::ostream& operator << (std::ostream& out, const SinglyLinkedList& list);
private:
	struct Node
	{
		int item_;
		Node* next_;

		Node(int item, Node* next = nullptr) : item_(item), next_(next) {}
	};

	Node* head_;

	bool insertNode(Node* newNode);
	Node* searchNode(int x)const;
};
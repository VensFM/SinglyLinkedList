#pragma once

#include <iostream>

template <typename T>
class SinglyLinkedList
{
public:
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList& list)noexcept;
	SinglyLinkedList(SinglyLinkedList&& list)noexcept;
	~SinglyLinkedList();

	bool insert(T x);
	bool search(T x)const;
	bool remove(T x);

	void merge(SinglyLinkedList& list);
	void remove(const SinglyLinkedList& list);
	friend SinglyLinkedList getIntersection(const SinglyLinkedList<T>& list1, const SinglyLinkedList<T>& list2)
	{
		SinglyLinkedList<T> res;
		if (list1.head_ == nullptr || list2.head_ == nullptr)
		{
			std::cerr << "\n	One of the lists is empty!!!\n";
			return res;
		}
		SinglyLinkedList<T>::template Node* temp1 = list1.head_;
		while (temp1 != nullptr)
		{
			SinglyLinkedList<T>::template Node* temp2 = list2.head_;
			while (temp2 != nullptr)
			{
				if (temp1->item_ == temp2->item_)
				{
					res.insert(temp1->item_);
					break;
				}
				temp2 = temp2->next_;
			}
			temp1 = temp1->next_;
		}
		return res;
	}

	SinglyLinkedList& operator = (const SinglyLinkedList& list);
	SinglyLinkedList& operator = (SinglyLinkedList&& list)noexcept;

	friend std::ostream& operator << (std::ostream& out, const SinglyLinkedList<T>& list)
	{
		if (list.head_ == nullptr)
		{
			out << "The list is empty";
		}
		SinglyLinkedList<T>::template Node* temp = list.head_;
		while (temp != nullptr)
		{
			out << temp->item_ << " ";
			temp = temp->next_;
		}
		return out;
	}
private:
	struct Node
	{
		T item_;
		Node* next_;

		Node(T item, Node* next = nullptr) : item_(item), next_(next) {}
	};

	Node* head_;

	bool insertNode(Node* newNode);
	Node* searchNode(T x)const;
};
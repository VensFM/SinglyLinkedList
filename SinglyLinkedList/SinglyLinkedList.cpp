#include "SinglyLinkedList.h"


template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	head_ = nullptr;
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& list)noexcept
{
	this->head_ = nullptr;
	Node* next = list.head_;
	while (next != nullptr)
	{
		Node* temp = new Node(next->item_);
		this->insertNode(temp);
		next = next->next_;
	}
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList<T>&& list)noexcept
{
	this->head_ = list.head_;
	list.head_ = nullptr;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	Node* buf = nullptr;
	Node* next = head_;
	while (next != nullptr)
	{
		buf = next;
		next = next->next_;
		delete buf;
	}
}

template <typename T>
bool SinglyLinkedList<T>::insert(T x)
{
	Node* temp = new Node(x);
	if (insertNode(temp))
	{
		return true;
	}
	delete temp;
	return false;
}

template <typename T>
bool SinglyLinkedList<T>::search(T x)const
{
	if (searchNode(x) == nullptr)
	{

		return false;
	}
	return true;
}

template <typename T>
bool SinglyLinkedList<T>::remove(T x)
{
	Node* needToDel = searchNode(x);
	if (needToDel == nullptr)
	{
		return false;
	}
	if (head_->item_ == needToDel->item_)
	{
		Node* buf = head_->next_;
		delete head_;
		head_ = buf;
		return true;
	}
	Node* temp = head_;
	while (temp->next_ != needToDel)
	{
		temp = temp->next_;
	}
	temp->next_ = needToDel->next_;
	delete needToDel;
	return true;
}

template <typename T>
void SinglyLinkedList<T>::merge(SinglyLinkedList<T>& list)
{
	while (list.head_ != nullptr)
	{
		Node* buf = list.head_->next_;
		list.head_->next_ = nullptr;
		if (insertNode(list.head_))
		{
			list.head_ = buf;
			continue;
		}
		delete list.head_;
		list.head_ = buf;
	}
}

template <typename T>
void SinglyLinkedList<T>::remove(const SinglyLinkedList<T>& list)
{
	if (list.head_ == nullptr || head_ == nullptr)
	{
		std::cerr << "\n	One of the lists is empty!!!\n";
		return;
	}
	Node* temp = list.head_;
	while (temp != nullptr)
	{
		this->remove(temp->item_);
		temp = temp->next_;
	}
}

//template <typename T>
//SinglyLinkedList<T> getIntersection(const SinglyLinkedList<T>& list1, const SinglyLinkedList<T>& list2)
//{
//	SinglyLinkedList<T> res;
//	if (list1.head_ == nullptr|| list2.head_ == nullptr)
//	{
//		std::cerr << "\n	One of the lists is empty!!!\n";
//		return res;
//	}
//	SinglyLinkedList<T>::template Node* temp1 = list1.head_;
//	while (temp1 != nullptr)
//	{
//		SinglyLinkedList<T>::template Node* temp2 = list2.head_;
//		while (temp2 != nullptr)
//		{
//			if (temp1->item_ == temp2->item_)
//			{
//				res.insert(temp1->item_);
//				break;
//			}
//			temp2 = temp2->next_;
//		}
//		temp1 = temp1->next_;
//	}
//	return res;
//}


template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator = (const SinglyLinkedList<T>& list)
{
	Node* next = head_;
	if (this->head_ != nullptr)
	{
		Node* buf = nullptr;
		while (next != nullptr)
		{
			buf = next;
			next = next->next_;
			delete buf;
		}
	}
	this->head_ = nullptr;
	next = list.head_;
	while (next != nullptr)
	{
		Node* temp = new Node(next->item_);
		this->insertNode(temp);
		next = next->next_;
	}
	return *this;
}

template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator = (SinglyLinkedList<T>&& list)noexcept
{
	if (this->head_ != list.head_)
	{
		if (this->head_ != nullptr)
		{
			Node* buf = nullptr;
			Node* next = head_;
			while (next != nullptr)
			{
				buf = next;
				next = next->next_;
				delete buf;
			}
		}
		this->head_ = list.head_;
		list.head_ = nullptr;
	}
	return *this;
}

//template <typename T>
//std::ostream& operator<<(std::ostream& out, const SinglyLinkedList<T>& list)
//{
//	if (list.head_ == nullptr)
//	{
//		out << "The list is empty";
//	}
//	SinglyLinkedList<T>::template Node* temp = list.head_;
//	while (temp != nullptr)
//	{
//		out << temp->item_ << " ";
//		temp = temp->next_;
//	}
//	return out;
//}

template <typename T>
bool SinglyLinkedList<T>::insertNode(Node* newNode)
{
	if (newNode == nullptr)
	{
		std::cerr << "	Node is empty!!!";
		return false;
	}
	if (head_ == nullptr)
	{
		head_ = newNode;
		return true;
	}
	if (head_->item_ == newNode->item_)
	{
		return false;
	}
	if (head_->item_ > newNode->item_)
	{
		newNode->next_ = head_;
		head_ = newNode;
		return true;
	}
	Node* temp = head_;
	while (temp->next_ != nullptr)
	{
		if (temp->next_->item_ == newNode->item_)
		{
			return false;
		}
		if (temp->next_->item_ > newNode->item_)
		{
			newNode->next_ = temp->next_;
			temp->next_ = newNode;
			return true;
		}
		temp = temp->next_;
	}
	temp->next_ = newNode;
	return true;
}

template <typename T>
SinglyLinkedList<T>:: template Node* SinglyLinkedList<T>::searchNode(T x)const
{
	Node* temp = head_;
	while (temp != nullptr)
	{
		if (temp->item_ == x)
		{
			return temp;
		}
		if (temp->item_ > x)
		{
			return nullptr;
		}
		temp = temp->next_;
	}
	return nullptr;
}
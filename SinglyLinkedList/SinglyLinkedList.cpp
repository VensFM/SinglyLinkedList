#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
{
	head_ = nullptr;
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& list)noexcept
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

SinglyLinkedList::SinglyLinkedList(SinglyLinkedList&& list)noexcept
{
	this->head_ = list.head_;
	list.head_ = nullptr;
}

SinglyLinkedList::~SinglyLinkedList()
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

bool SinglyLinkedList::insert(int x)
{
	Node* temp = new Node(x);
	if (insertNode(temp))
	{
		return true;
	}
	delete temp;
	return false;
}

bool SinglyLinkedList::search(int x)const
{
	if (searchNode(x) == nullptr)
	{

		return false;
	}
	return true;
}

bool SinglyLinkedList::remove(int x)
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

void SinglyLinkedList::merge(SinglyLinkedList& list)
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

void SinglyLinkedList::remove(const SinglyLinkedList& list)
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

SinglyLinkedList getIntersection(const SinglyLinkedList& list1, const SinglyLinkedList& list2)
{
	SinglyLinkedList res;
	if (list1.head_ == nullptr|| list2.head_ == nullptr)
	{
		std::cerr << "\n	One of the lists is empty!!!\n";
		return res;
	}
	SinglyLinkedList::Node* temp1 = list1.head_;
	while (temp1 != nullptr)
	{
		SinglyLinkedList::Node* temp2 = list2.head_;
		while (temp2 != nullptr)
		{
			if (temp1->item_ == temp2->item_)
			{
				res.insert(temp1->item_);
			}
			temp2 = temp2->next_;
		}
		temp1 = temp1->next_;
	}
	return res;
}


SinglyLinkedList& SinglyLinkedList::operator = (const SinglyLinkedList& list)
{
	Node* buf = nullptr;
	Node* next = head_;
	while (next != nullptr)
	{
		buf = next;
		next = next->next_;
		delete buf;
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

SinglyLinkedList& SinglyLinkedList::operator = (SinglyLinkedList&& list)noexcept
{
	if (this->head_ != list.head_)
	{
		this->head_ = list.head_;
		list.head_ = nullptr;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const SinglyLinkedList& list)
{
	if (list.head_ == nullptr)
	{
		out << "The list is empty";
	}
	SinglyLinkedList::Node* temp = list.head_;
	while (temp != nullptr)
	{
		out << temp->item_ << " ";
		temp = temp->next_;
	}
	return out;
}

bool SinglyLinkedList::insertNode(Node* newNode)
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

SinglyLinkedList::Node* SinglyLinkedList::searchNode(int x)const
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
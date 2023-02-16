#include <iostream>

#include "SinglyLinkedList.h"

void constructorsTest();
void basicMethodTest();
void complexMethodsTest();
void assignmentOperatorTest();

int main()
{
	constructorsTest();
	basicMethodTest();
	complexMethodsTest();
	assignmentOperatorTest();
	return 0;
}

void constructorsTest()
{
	system("cls");
	std::cout << "	Singly linked list: constructors test\n\n";
	SinglyLinkedList list1;
	std::cout << "	Default constructor:\nList1: "<< list1 <<"\n\n\n";
	list1.insert(1);
	list1.insert(2);
	list1.insert(3);
	std::cout << "	Copy constructor:\nBefore:\n List1: " << list1 << "\n List2: Not yet initialized\n\nAfter copy:\n";
	SinglyLinkedList list2(list1);
	std::cout << " List1: " << list1 << "\n List2: " << list2 << "\n\n\n";
	std::cout << "	Move constructor:\nBefore:\n List1: " << list1 << "\n List2: Not yet initialized\n\nAfter move:\n";
	SinglyLinkedList list3(std::move(list1));
	std::cout << " List1: " << list1 << "\n List2: " << list3 << "\n\n";
	system("pause");
	system("cls");
}

void basicMethodTest()
{
	system("cls");
	std::cout << "	Singly linked list: basic method test\n\n";
	SinglyLinkedList list1;
	list1.insert(1);
	list1.insert(2);
	list1.insert(3);
	std::cout << "	Method insert:\nBefore:\n List: " << list1 << "\n\nAfter insert(0):\n";
	list1.insert(0);
	std::cout << " List: " << list1 << "\n\nAfter insert(4):\n";
	list1.insert(4);
	std::cout << " List: " << list1 << "\n\nAfter insert(2):\n";
	list1.insert(2);
	std::cout << " List: " << list1 << "\n\n\n";
	std::cout << "	Method remove:\nBefore:\n List: " << list1 << "\n\nAfter remove(0):\n";
	list1.remove(0);
	std::cout << " List: " << list1 << "\n\nAfter remove(4):\n";
	list1.remove(4);
	std::cout << " List: " << list1 << "\n\nAfter remove(5):\n";
	list1.remove(5);
	std::cout << " List: " << list1 << "\n\n\n";
	std::cout << "	Method search:\nList: " << list1 << "\n Search(0): "<< list1.search(0) <<"\n Search(1): " << list1.search(1) << "\n Search(2): " << list1.search(2) << "\n Search(3): " << list1.search(3) << "\n Search(4): " << list1.search(4) << "\n\n";
	system("pause");
	system("cls");
}

void complexMethodsTest()
{
	system("cls");
	std::cout << "	Singly linked list: complex method test\n\n";
	SinglyLinkedList list1, list2;
	list1.insert(1);
	list1.insert(2);
	list1.insert(3);
	list2.insert(4);
	list2.insert(5);
	list2.insert(6);
	std::cout << "	Method merge:\nBefore:\n List1: " << list1 << "\n List2: " << list2 << "\n\nAfter merge:\n";
	list1.merge(list2);
	std::cout << " List1: " << list1 << "\n List2: " << list2 << "\n\n\n";
	list2.insert(7);
	list2.insert(5);
	list2.insert(6);
	list2.insert(1);
	std::cout << "	Method remove:\nBefore:\n List1: " << list1 << "\n List2: " << list2 << "\n\nAfter remove:\n";
	list1.remove(list2);
	std::cout << " List1: " << list1 << "\n List2: " << list2 << "\n\n\n";
	list2.insert(2);
	list2.insert(3);
	list2.insert(4);
	std::cout << "	Friend function getIntersection:\nBefore:\n List1: " << list1 << "\n List2: " << list2 << "\n\nAfter intersection:\n";
	SinglyLinkedList list3 = getIntersection(list1,list2);
	std::cout << " List3: " << list3 << "\n\n";
	system("pause");
	system("cls");
}

void assignmentOperatorTest()
{
	system("cls");
	std::cout << "	Singly linked list: assignment operator test\n\n";
	SinglyLinkedList list1, list2;
	list1.insert(1);
	list1.insert(2);
	list1.insert(3);
	list2.insert(4);
	list2.insert(5);
	list2.insert(6);
	std::cout << "	Copy assignment:\nBefore:\n List1: " << list1 << "\n List2: " << list2 << "\n\nAfter assignment:\n";
	list1 = list2;
	std::cout << " List1: " << list1 << "\n List2: " << list2 << "\n\n\n";
	list1.insert(1);
	list1.insert(2);
	list1.insert(3);
	std::cout << "	Move assignment:\nBefore:\n List1: " << list1 << "\n List2: " << list2 << "\n\nAfter assignment:\n";
	list1 = std::move(list2);
	std::cout << " List1: " << list1 << "\n List2: " << list2 << "\n\n";
	system("pause");
	system("cls");
}
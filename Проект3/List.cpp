#include "List.h"
#include <iostream>
#include <stdexcept>


using namespace std;

template<typename T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
size_t List<T>::get_size() const
{
	return size;
}
template<typename T>
void List<T>::push_back(T newElem)
{
	if (size == 0) {
		head = new Node(newElem);
		tail = head;
	}
	else {

		tail->next = new Node(newElem);
		tail->next->prev = tail;
		tail = tail->next;
	}
	size++;

}
template<typename T>
void List<T>::push_front(T newElem)
{
	if (size == 0)
		add_first(newElem);
	else
	{
		head->prev = new Node(newElem, head);
		head = head->prev;
	}
	size++;
}
template<typename T>
void List<T>::pop_back()
{
	if (size == 0)
		return;

	Node *prev = tail->prev;

	delete tail;
	if (size == 1)
		head = nullptr;
	else
		prev->next = nullptr;
	tail = prev;
	size--;

	
}
template<typename T>
void List<T>::pop_front()
{
	if (size == 0) return;
	if (size == 1)
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
		return;
	}
	else
	{
		Node *cur = head->next;
		cur->prev = nullptr;
		delete head;
		head = cur;
	}
	size--;
}
template<typename T>
T List<T>::at(size_t index) const
{
	if (index >= size) {
		return -1;
	}
	else {
		size_t count = 0;
		Node * cur = head;
		while (count != index) {
			cur = cur->next;
			count++;
		}
		cout << cur->data;
		return cur->data;
	}
}
template<typename T>
bool List<T>::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}

template<typename T>
void List<T>::set(size_t index, T newElem)
{

	if (index >= size) {
		return;
	}
	else {
		size_t count = 0;
		Node * cur = head;
		while (count != index) {
			cur = cur->next;
			count++;
		}
		cur->data = newElem;

	}
}

template<typename T>
void List<T>::clear()
{
	Node * cur = head;
	while (cur != nullptr)
	{
		Node * next = cur->next;
		delete cur;
		cur = next;
	}
	head = tail = nullptr;
	size = 0;
	
}

template<typename T>
void List<T>::print_to_console(List *list)
{
	Node *cur;
	cur = list->head;
	while (cur != nullptr)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
}

template<typename T>
void List<T>::Delete(size_t index)
{
	if (size == 0 || index > size) throw out_of_range("List is empty");

	Node * cur = head;
	if (index == 0)
	{ 
		pop_front(); 
		return;
	}
	while (index--)
		cur = cur->next;
	if (cur->prev != nullptr)
		cur->prev->next = cur->next;
	if (cur->next != nullptr)
		cur->next->prev = cur->prev;
	delete cur;

	if (size == 1)
		head = tail = nullptr;

	size--;
}

template<typename T>
void List<T>::insert(T newElem, size_t index)
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	else {

		size_t count = 0;
		Node * cur = head;
		if (index == 0)
		{
			push_front(newElem);
		}
		else
		{
			while (count != index - 1) {
				cur = cur->next;
				count++;
			}

			Node *El = new Node(newElem, cur->next, cur);
			cur->next->prev = El;
			cur->next = El;

		}
		size++;
	}
}

template<typename T>
void List<T>::push_front_list(const List & Sec)
{
	Node *cur = Sec.tail;
	while (cur != nullptr) {
		push_front(cur->data);
		cur = cur->prev;
	}
	
}

template<typename T>
size_t List<T>::get_back()
{
	Node *cur = head;
	while (cur->next != nullptr)
	{
		cur = cur->next;
	}
	return cur->data;
}

template<typename T>
size_t List<T>::get_front()
{
	Node *cur = head;
	return cur->data;
}

template<typename T>
void List<T>::add_first(T newElem)
{
	head = new Node(newElem);
	tail = head;
}

template<typename T>
ostream & operator<<(ostream & out, List<T>& list)
{
	Node *cur;
	cur = list->head;
	while (cur != nullptr)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	return out;
}

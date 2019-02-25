#pragma once
#include <iostream>

using namespace std;

template <typename T>
class List
{
public:
	friend ostream& operator<< (ostream &out, List<T> &list)
	{
		//Node *cur;
		auto cur = list.head;
		while (cur != nullptr)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
		return out;
	}
	;
	/*List(List &) = delete;
	List(List &&) = delete;
	List& operator= (List &) = delete;
	List& operator= (List &&) = delete;*/
	

	List();
	~List();

	size_t get_size() const;
	void push_back(T newElem);
	void push_front(T newElem);
	void pop_back();
	void pop_front();
	T at(size_t index) const;
	T get_back();
	T get_front();
	bool isEmpty();
	void set(size_t index, T newElem);
	void clear();
	void print_to_console(List *list);
	void Delete(size_t);
	void insert(T, size_t);
	void push_front_list(const List&);

	//size_t get_back();
	//size_t get_front();

private:
	void add_first(T newElem);

//	template <typename T>
	class Node
	{
	public:
		Node(T data, Node * next = nullptr) {
			this->data = data;
			this->next = next;
		//	this->prev = prev;
		}

		T data;
		Node * next;
		//Node * prev;
	};


	Node * head;
	Node * tail;
	size_t size;
};




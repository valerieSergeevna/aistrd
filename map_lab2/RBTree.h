#pragma once
#include <iostream>

using namespace std;

template <typename T>
class RBTree
{
private:



	class node
	{
	private:
		bool color;
		T key, value;
		node * next_right, *next_left, *parent;
		unsigned int height;
	public:
		node(T key, T data, node * next1 = nullptr, node * next2 = nullptr) {
			this->data = data;
			this->next_left = next1;
			this->next_right = next2;
			this->key = key;
		};


		~node();

	};
public:
	//bool operator> (T value_1, T value_2) { value_1 > value_2 ? true : false; };
	RBTree();
	~RBTree() {
		clear();
	};
	//void Del();
	//mode* remove(int);
	void reset_list();
	unsigned int height_();
	void fixheight();
	int bfactor();
	node *get_ancle(node*);
	node* get_grandparent(node *);
	node* rotate_right(node*);
	node* rotate_left(node*);
	void blance_set_color(node *);
	void insert_case1(node *);
	void insert_case2(node *);
	void insert_case3(node *);
	void insert_case4(node *);
	void insert_case5(node *);
	void insert(T, T);
	void add_first(T, T);
	void remove(T);
	T find(T);
	void clear();
	T get_keys();
	T get_value();

	node * root;
	size_t size;
};


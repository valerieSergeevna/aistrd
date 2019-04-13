#pragma once
#include <iostream>


using namespace std;


template <class item> class stack
{
	item *Stack; int size_;
public:
	stack(int maxt) : Stack(new item[maxt]), size_(0) {};
	~stack();
	bool empty() const { return size_ == 0; }
	int size() const { return size_; }
	void push(item & item) { Stack[size_++] = item; }
	item top() const { return Stack[size_ - 1]; }
	void pop() { if (size_) --size_; }
};



// функция деструктора Стека
template <class item>
stack<item>::~stack()
{
	free(Stack); // удаляем стек
}

template <class item> class queue
{
	item *Queue; int head, tail, size_, Max;
public:
	queue(int maxQ) : head(0), tail(0), Max(maxQ), size_(0), Queue(new item[maxQ + 1]) {}
	~queue();
	bool empty() const { return (head % Max) == tail; }
	int size() const { return size_; }
	void push(item & item) { Queue[tail++] = item; tail %= Max; ++size_; }
	item front() const { return Queue[head % Max]; }
	void pop() { head++; head %= Max; --size_; }
};

template <class item>
queue<item>::~queue()
{
	free(Queue);
}

template <typename T>
class RBTree
{
private:



	class node
	{
	
	public:
		node(T key, T data, node * next1 = nullptr, node * next2 = nullptr, node * next3 = nullptr) {
			this->data = data;
			this->next_left = next1;
			this->next_right = next2;
			this->key = key;
			this -> height = 0;
			this->parent = next3;
			this->color = 1;

		};
		bool color;
		T key, data;
		node * next_right, *next_left, *parent;
		unsigned int height;
		void Del();
		~node();

	};
	
	node * root;
	size_t size;
public:
	RBTree();
	~RBTree();

	//mode* remove(int);
	void reset_list();
	unsigned int height_();
	void fixheight();
	int bfactor();
	node *get_uncle(node*);
	node* get_grandparent(node *);
	node* get_sibling(node *);
	void rotate_right(node*);
	void rotate_left(node*);
	void blance_set_color(node *);
	void insert_case1(node *);
	void insert_case2(node *);
	void insert_case3(node *);
	void insert_case4(node *);
	void insert_case5(node *);

	void delete_case1(node *);
	void delete_case2(node *);
	void delete_case3(node *);
	void delete_case4(node *);
	void delete_case5(node *);
	void delete_case6(node *);
	void delete_one_child(node *);

	void insert(T, T);
	void insert_fix(node*);
	//void add_first(node*);
	void add_first(T, T);
	void remove(T);
	T find(T);

	T get_keys();
	T get_colors();
	T get_value();

	
};


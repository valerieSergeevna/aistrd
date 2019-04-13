#include "RBTree.h"
#include <stdexcept>



template<typename T>
RBTree<T>::RBTree()
{
	reset_list();
	size = 0;
}

template<typename T>
RBTree<T>::~RBTree()
{
	if (root != nullptr)
	{
		root->Del();
		if (root->next_left != nullptr)
			root->next_left = nullptr;
		if (root->next_right != nullptr)
			root->next_right = nullptr;
		root = nullptr;
	}
}

template<typename T>
void RBTree<T>::node::Del()
{
	if (this != nullptr) {
		this->next_left->Del();
		this->next_right->Del();
		free(this);
	}
}


template<typename T>
void RBTree<T>::insert(T key, T value)
{
	/*node *nw = new node(key, value);
	if (size == 0)
	{
		//add_first(key, value);
		insert_fix(nw);
		root = nw;
		root->parent = nullptr;
	}
	else {
		node *current = root;
		//поиск места, куда вставить элемент 
		while (true) {
			if (key <= current->key)//если меньше или равен, то идем по левому поддереву
				if (current->next_left == nullptr) {
					current->next_left = nw;//вставляем элемент
					//current->next_left->parent = current;
					current = current->next_left;
					break;
				}
				else
					current = current->next_left;
			else if (key > current->key)//если меньше или равен, то идем по правому поддереву
				if (current->next_right == nullptr) {
					current->next_right = nw;//вставляем элемент
					//current->next_right->parent = current;
					current = current->next_right;
					break;
				}
				else
					current = current->next_right;
		}
		size++;
		insert_fix(current);
	}
	*/
	node *p, *q;
	node *t = new node(key, value);
	p = root;
	q = nullptr;
	if (root == nullptr)
	{
		root = t;
		t->parent = nullptr;
	}
	else
	{
		while (p != nullptr)
		{
			q = p;
			if (p->key < t->key)
				p = p->next_right;
			else
				p = p->next_left;
		}
		t->parent = q;
		if (q->key < t->key)
			q->next_right = t;
		else
			q->next_left = t;
	}
	insert_fix(t);
}

template<typename T>
void RBTree<T>::insert_fix(node *t)
{
	node *u;
	if (root == t)
	{
		t->color = 0;
		return;
	}
	while (t->parent != nullptr && t->parent->color == 1)
	{
		node *g = t->parent->parent;
		if (g->next_left == t->parent)
		{
			if (g->next_right != nullptr)
			{
				u = g-> next_right;
				if (u->color == 1)
				{
					t->parent->color = 0;
					u->color = 0;
					g->color = 1;
					t = g;
				}
			}
			else
			{
				if (t->parent->next_right == t)
				{
					t = t->parent;
					rotate_left(t);
				}
				t->parent->color = 0;
				g->color = 1;
				rotate_right(g);
			}
		}
		else
		{
			if (g->next_left != nullptr)
			{
				u = g->next_left;
				if (u->color == 1)
				{
					t->parent->color = 0;
					u->color = 0;
					g->color = 1;
					t = g;
				}
			}
			else
			{
				if (t->parent->next_left == t)
				{
					t = t->parent;
					rotate_right(t);
				}
				t->parent->color = 0;
				g->color = 1;
				rotate_left(g);
			}
		}
		root->color = 0;
	}
}

/*template<typename T>
void RBTree<T>::add_first(node *cur)
{

	root = cur;
	cur->parent = nullptr;
	cur->color = 0;
	size++;
}
*/
template<typename T>
void RBTree<T>::add_first(T key, T val)
{

	root = new node(key, val);
	root->parent = nullptr;
	size++;
}
template<typename T>
T RBTree<T>::find(T key)
{
	if (this->root == nullptr)
	{
		throw out_of_range("error");
	}
	stack<node*> s(this->size);  
	s.push(this->root);  
	while (s.empty() == false)
	{
	
		node *temp = s.top();
		s.pop();
		if (temp->key == key)
			return temp->data;

		if (temp->next_right)
			s.push(temp->next_right); // Вставляем в стек правого потомка
		if (temp->next_left)
			s.push(temp->next_left);  // Вставляем в стек левого потомка
	}
}

/*template<typename T>
T RBTree<T>::get_keys()
{
	Iterator &it = create_bft_iterator();
	for (; it != nullptr; it++)
		std::cout << it-- << ' ';
	std::cout << '\n';
}*/

template<typename T>
T RBTree<T>::get_colors()
{
	if (this->root == nullptr)
	{
		throw out_of_range("error");
	}
	stack<node*> s(this->size);  // Создаем стек
	s.push(this->root);  // Вставляем корень в стек
	/* Извлекаем из стека один за другим все элементы.
	   Для каждого извлеченного делаем следующее
	   1) печатаем его
	   2) вставляем в стек правого! потомка
		  (Внимание! стек поменяет порядок выполнения на противоположный!)
	   3) вставляем в стек левого! потомка */
	while (s.empty() == false)
	{
		// Извлекаем вершину стека и печатаем
		node *temp = s.top();
		s.pop();
		cout << temp->color << " ";

		if (temp->next_right)
			s.push(temp->next_right); // Вставляем в стек правого потомка
		if (temp->next_left)
			s.push(temp->next_left);  // Вставляем в стек левого потомка
	}
}

template<typename T>
T RBTree<T>::get_value()
{
	if (this->root == nullptr)
	{
		throw out_of_range("error");
	}
	stack<node*> s(this->size);  // Создаем стек
	s.push(this->root);  // Вставляем корень в стек
	/* Извлекаем из стека один за другим все элементы.
	   Для каждого извлеченного делаем следующее
	   1) печатаем его
	   2) вставляем в стек правого! потомка
		  (Внимание! стек поменяет порядок выполнения на противоположный!)
	   3) вставляем в стек левого! потомка */
	while (s.empty() == false)
	{
		// Извлекаем вершину стека и печатаем
		node *temp = s.top();
		s.pop();
		cout << temp->data << " ";

		if (temp->next_right)
			s.push(temp->next_right); // Вставляем в стек правого потомка
		if (temp->next_left)
			s.push(temp->next_left);  // Вставляем в стек левого потомка
	}
}
template<typename T>
void RBTree<T>::reset_list()
{
	//	cur = nullptr;
	root = nullptr;
}

/*template <typename T>
typename RBTree<T>::node* RBTree<T>::get_uncle(node *cur) {
	node *granny = get_grandparent(cur);
	if (granny == nullptr)
		return nullptr; // No grandparent means no uncle
	if (cur->parent == granny->next_left)
		return granny->next_right;
	else
		return granny->next_left;
}

template <typename T>
typename RBTree<T>::node* RBTree<T>::get_grandparent(node *cur) {
	if ((cur != nullptr) && (cur->parent != nullptr))
		return cur->parent->parent;
	else
		return nullptr;
}

template<typename T>
typename RBTree<T>::node * RBTree<T>::get_sibling(node *current)
{
	if (current == current->parent->next_left)
		return current->parent->next_right;
	else
		return current->parent->next_left;
}
*/
template<typename T>
void RBTree<T>::rotate_right(node *cur)
{
	node *pivot = cur->next_left;

	pivot->parent = cur->parent; /* при этом, возможно, pivot становится корнем дерева */
	if (cur->parent != nullptr) {
		if (cur->parent->next_left == cur)
			cur->parent->next_left = pivot;
		else
			cur->parent->next_right = pivot;
	}

	cur->next_left = pivot->next_right;
	if (pivot->next_right != nullptr)
		pivot->next_right->parent = cur;

	cur->parent = pivot;
	pivot->next_right = cur;
}

template<typename T>
void  RBTree<T>::rotate_left(node *cur)
{
	struct node *pivot = cur->next_right;

	pivot->parent = cur->parent; /* при этом, возможно, pivot становится корнем дерева */
	if (cur->parent != nullptr) {
		if (cur->parent->next_left == cur)
			cur->parent->next_left = pivot;
		else
			cur->parent->next_right = pivot;
	}

	cur->next_right = pivot->next_left;
	if (pivot->next_left != nullptr)
		pivot->next_left->parent = cur;

	cur->parent = pivot;
	pivot->next_left = cur;
}
//из википедии
/*template<typename T>
void RBTree<T>::blance_set_color(node *cur)
{
	insert_case1(cur);
}

template<typename T>
void RBTree<T>::insert_case1(node *cur)
{
	if (cur->parent == nullptr)
		cur->color = 0;
	else
		insert_case2(cur);
}

template<typename T>
void RBTree<T>::insert_case2(node *cur)
{
	if (cur->parent->color == 0)
		return; 
	else
		insert_case3(cur);
}
template<typename T>
void RBTree<T>::insert_case3(node *cur)
{
	node *u = get_uncle(cur), *granny;

	if ((u != nullptr) && (u->color == 1)) {
		// && (n->parent->color == RED) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
		cur->parent->color = 0;
		u->color = 0;
		granny = get_grandparent(cur);
		granny->color = 1;
		insert_case1(granny);
	}
	else {
		insert_case4(cur);
	}
}

template<typename T>
void RBTree<T>::insert_case4(node *cur)
{
	node *granny = get_grandparent(cur);

	if ((cur == cur->parent->next_right) && (cur->parent == granny->next_left)) {
		rotate_left(cur->parent);

		cur = cur->next_left;
	}
	else if ((cur == cur->parent->next_left) && (cur->parent == granny->next_right)) {
		rotate_right(cur->parent);


		cur = cur->next_right;
	}
	insert_case5(cur);
}

template<typename T>
void RBTree<T>::insert_case5(node *cur)
{
	node *granny = get_grandparent(cur);

	cur->parent->color = 0;
	granny->color = 1;
	if ((cur == cur->parent->next_left) && (cur->parent == granny->next_left)) {
		rotate_right(granny);
	}
	else { 
		rotate_left(granny);
	}
}
template<typename T>
void RBTree<T>::delete_case1(node *current)
{
	if (current->parent != nullptr)
		delete_case2(current);
}
template<typename T>
void RBTree<T>::delete_case2(node *current)
{
	node *sibling = get_sibling(current);

	if (sibling->color == 1) {
		current->parent->color = 1;
		sibling->color = 0;
		if (current == current->parent->next_left)
			rotate_left(current->parent);
		else
			rotate_right(current->parent);
	}
	delete_case3(current);
}
template<typename T>
void RBTree<T>::delete_case3(node *current)
{
	node *sibling = get_sibling(current);

	if ((current->parent->color == 0) &&
		(sibling->color == 0) &&
		(sibling->next_left->color == 0) &&
		(sibling->next_right->color == 0)) {
		sibling->color = 1;
		delete_case1(current->parent);
	}
	else
		delete_case4(current);
}
template<typename T>
void RBTree<T>::delete_case4(node *current)
{
	node *sibling = get_sibling(current);

	if ((current->parent->color == 1) &&
		(sibling->color == 0) &&
		(sibling->next_left->color == 0) &&
		(sibling->next_right->color == 0)) {
		sibling->color = 1;
		current->parent->color = 0;
	}
	else
		delete_case5(current);
}
template<typename T>
void RBTree<T>::delete_case5(node *current)
{
	node *sibling = get_sibling(current);

	if (sibling->color == 0) { 
		if ((current == current->parent->next_left) &&
			(sibling->next_right->color == 0) &&
			(sibling->next_left->color == 1)) {
			sibling->color = 1;
			sibling->next_left->color = 0;
			rotate_right(sibling);
		}
		else if ((current == current->parent->next_right) &&
			(sibling->next_left->color == 0) &&
			(sibling->next_right->color == 1)) {
			sibling->color = 1;
			sibling->next_right->color = 0;
			rotate_left(sibling);
		}
	}
	delete_case6(current);
}
template<typename T>
void RBTree<T>::delete_case6(node *current)
{
	node *sibling = get_sibling(current);

	sibling->color = current->parent->color;
	current->parent->color = 0;

	if (current == current->parent->left) {
		sibling->right->color = 0;
		rotate_left(current->parent);
	}
	else {
		sibling->left->color = 0;
		rotate_right(current->parent);
	}
}
template<typename T>
void RBTree<T>::delete_one_child(node *current)
{
	
	 node *child = current->next_right == nullptr ? current->next_left : current->next_right;

	//replace_node(current, child);//////////////тут непонятно
	 current->data = child->data;
	 current->key = child->key;
	if (current->color == 0) {
		if (child->color == 1)
			child->color = 0;
		else
			delete_case1(child);
	}
	free(current);
}
template <typename T>
void RBTree<T>::insert(T key, T value) {
	if (size == 0)
	{
		add_first(key, value);
	}
	else {
		node *current = root;
		//поиск места, куда вставить элемент 
		while (true) {
			if (key <= current->key)//если меньше или равен, то идем по левому поддереву
				if (current->next_left == nullptr) {
					current->next_left = new node(key, value);//вставляем элемент
					current->next_left->parent = current;
					current = current->next_left;
					break;
				}
				else
					current = current->next_left;
			else if (key > current->key)//если меньше или равен, то идем по правому поддереву
				if (current->next_right == nullptr) {
					current->next_right = new node(key, value);//вставляем элемент
					current->next_right->parent = current;
					current =current->next_right ;
					break;
				}
				else
					current = current->next_right;
		}
		size++;
		blance_set_color(current);
	}
	
	
}
*/

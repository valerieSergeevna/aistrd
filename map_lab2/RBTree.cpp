#include "RBTree.h"
#include <stdexcept>



template<typename T>
RBTree<T>::RBTree()
{
	reset_list();
	size = 0;
}


template<typename T>
void RBTree<T>::add_first(T key, T value)
{

	root = new node(key, value);
	root->color = 0;
	size++;
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
T RBTree<T>::get_value()
{
	if (this->root == nullptr)
	{
		throw out_of_range("error");
	}
	stack<node*> s;  // ������� ����
	s.push(this->root);  // ��������� ������ � ����
	/* ��������� �� ����� ���� �� ������ ��� ��������.
	   ��� ������� ������������ ������ ���������
	   1) �������� ���
	   2) ��������� � ���� �������! �������
		  (��������! ���� �������� ������� ���������� �� ���������������!)
	   3) ��������� � ���� ������! ������� */
	while (s.empty() == false)
	{
		// ��������� ������� ����� � ��������
		node *temp = s.top();
		s.pop();
		cout << temp->data << " ";

		if (temp->next_right)
			s.push(temp->next_right); // ��������� � ���� ������� �������
		if (temp->next_left)
			s.push(temp->next_left);  // ��������� � ���� ������ �������
	}
}
template<typename T>
void RBTree<T>::reset_list()
{
	//	cur = nullptr;
	root = nullptr;
}

template <typename T>
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
void RBTree<T>::rotate_right(node *cur)
{
	node *pivot = cur->next_left;

	pivot->parent = cur->parent; /* ��� ����, ��������, pivot ���������� ������ ������ */
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

	pivot->parent = cur->parent; /* ��� ����, ��������, pivot ���������� ������ ������ */
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

template<typename T>
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
		return; /* Tree is still valid */
	else
		insert_case3(cur);
}
template<typename T>
void RBTree<T>::insert_case3(node *cur)
{
	node *u = get_uncle(cur), *granny;

	if ((u != nullptr) && (u->color == 1)) {
		// && (n->parent->color == RED) ������ ������� ����������� � insert_case2, �� ���� �������� ��� �������� �������.
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

		/*
		 * rotate_left ����� ���� �������� ��������� �������, �������� ��� ��� ���� *g =  grandparent(n)
		 *
		 * struct node *saved_p=g->left, *saved_left_n=n->left;
		 * g->left=n;
		 * n->left=saved_p;
		 * saved_p->right=saved_left_n;
		 *
		 */

		cur = cur->next_left;
	}
	else if ((cur == cur->parent->next_left) && (cur->parent == granny->next_right)) {
		rotate_right(cur->parent);

		/*
		 * rotate_right ����� ���� �������� ��������� �������, �������� ��� ��� ���� *g =  grandparent(n)
		 *
		 * struct node *saved_p=g->right, *saved_right_n=n->right;
		 * g->right=n;
		 * n->right=saved_p;
		 * saved_p->left=saved_right_n;
		 *
		 */

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
	else { /* (n == n->parent->right) && (n->parent == g->right) */
		rotate_left(granny);
	}
}
template <typename T>
void RBTree<T>::insert(T key, T value) {
	if (size == 0)
	{
		add_first(key, value);
	}
	else {
		node *current = root;
		//����� �����, ���� �������� ������� 
		while (true) {
			if (key <= current->key)//���� ������ ��� �����, �� ���� �� ������ ���������
				if (current->next_left == nullptr) {
					current->next_left = new node(key, value);//��������� �������

					break;
				}
				else
					current = current->next_left;
			else if (key > current->key)//���� ������ ��� �����, �� ���� �� ������� ���������
				if (current->next_right == nullptr) {
					current->next_right = new node(key, value);//��������� �������

					break;
				}
				else
					current = current->next_right;
		}
		size++;
		blance_set_color(current);
	}


}


#include<iostream>
using namespace std;

struct Node
{
public:
	int data;
	int height;
	Node* LeftChild;
	Node* RightChild;
};
class AVLTREE{

	Node* root;

	Node* insertion(Node *r, int data);
	int height(Node*);
	int diff(Node *ptr);
	Node* LL_Rotation(Node*);
	Node* RR_Rotation(Node*);
	Node* RL_Rotation(Node*);
	Node* LR_Rotation(Node*);
	Node* balance(Node*);
	void inOrder(Node *ptr);
	void preOrder(Node *ptr);
	void postOrder(Node *ptr);
	bool searching(Node*,int);
	
public:
	AVLTREE();
	void insertion(int);
	int max(int,int);
	void inOrder();
	void preOrder();
	void postOrder();
	void searching(int);
};
AVLTREE::AVLTREE(){
	root = nullptr;
}
Node* AVLTREE::insertion(Node *ptr, int value){

	if (ptr == nullptr){

		Node *temp = new Node;
		temp->data = value;
		ptr = temp;
		temp->LeftChild = nullptr;
		temp->RightChild = nullptr;
		ptr->height = 1;
		return temp;
	}
	else{
		if (value < ptr->data){

			ptr->LeftChild = insertion(ptr->LeftChild, value);
		}
		else{

			ptr->RightChild = insertion(ptr->RightChild, value);
		}
	}
	ptr = balance(ptr);
	
	return ptr;
}
void AVLTREE::insertion(int value){

	root = insertion(root, value);
}
int AVLTREE::height(Node* ptr){

	if (ptr->LeftChild && ptr->RightChild){

		if (ptr->LeftChild->height < ptr->RightChild->height){

			return ptr->RightChild->height + 1;
		}
		else{

			return  ptr->LeftChild->height + 1;
		}
	}
	else if (ptr->LeftChild && ptr->RightChild == nullptr){

		return ptr->LeftChild->height + 1;
	}
	else if (ptr->LeftChild == nullptr && ptr->RightChild){

		return ptr->RightChild->height + 1;
	}
	return 0;
}
int AVLTREE::diff(Node *ptr){


	if (ptr->LeftChild && ptr->RightChild){

		return ptr->LeftChild->height - ptr->RightChild->height;
	}
	else if (ptr->LeftChild && ptr->RightChild == nullptr){
		return ptr->LeftChild->height;
	}
	else if (ptr->LeftChild == nullptr && ptr->RightChild){
		return -ptr->RightChild->height;
	}
	
}
Node* AVLTREE::LL_Rotation(Node * ptr){

	Node * temp;
	temp = ptr->LeftChild;
	ptr->LeftChild = temp->RightChild;
	temp->RightChild = ptr;
	return temp;
}
Node* AVLTREE::RR_Rotation(Node * ptr){

	Node * temp;
	temp = ptr->RightChild;
	ptr->RightChild = temp->LeftChild;
	temp->LeftChild = ptr;
	return temp;
}
Node* AVLTREE::RL_Rotation(Node* ptr){

	Node *temp;
	Node *temp2;

	temp = ptr->RightChild;
	temp2 = ptr->RightChild->LeftChild;
	ptr->RightChild = temp2->LeftChild;
	temp->LeftChild = temp2->RightChild;
	temp2->LeftChild = ptr;
	temp2->RightChild = temp;

	return temp2;

}
Node* AVLTREE::LR_Rotation(Node* ptr){

	Node *temp;
	Node *temp2;

	temp = ptr->LeftChild;
	temp2 = ptr->LeftChild->RightChild;
	ptr->LeftChild = temp2->RightChild;
	temp->RightChild = temp2->LeftChild;
	temp2->RightChild = ptr;
	temp2->LeftChild = temp;

	return temp2;
}
Node* AVLTREE::balance(Node *ptr){

	
	ptr->height = height(ptr);
	
	if (diff(ptr) == 2 && diff(ptr->LeftChild) == 1){

		ptr = LL_Rotation(ptr);
	}
	else if (diff(ptr) == -2 && diff(ptr->RightChild) == -1){
		ptr = RR_Rotation(ptr);
	}
	else if (diff(ptr) == -2 && diff(ptr->RightChild) == 1){
		ptr = RL_Rotation(ptr);
	}
	else if (diff(ptr) == 2 && diff(ptr->LeftChild) == -1){
		ptr = LR_Rotation(ptr);
	}

	return ptr;
}
void AVLTREE::preOrder(Node *ptr)
{
	if (ptr == nullptr)
	{
		return;
	}
	cout << ptr->data << " ";
	preOrder(ptr->LeftChild);
	preOrder(ptr->RightChild);
}
void AVLTREE::preOrder()
{
	preOrder(root);
}
void AVLTREE::inOrder(Node *ptr)
{
	if (ptr == nullptr)
	{
		return;
	}
	inOrder(ptr->LeftChild);
	cout << ptr->data << " ";
	inOrder(ptr->RightChild);
}
void AVLTREE::inOrder()
{
	inOrder(root);
}
void AVLTREE::postOrder(Node *ptr)
{
	if (ptr == nullptr)
	{
		return;
	}
	postOrder(ptr->LeftChild);
	postOrder(ptr->RightChild);
	cout << ptr->data << " ";
}
void AVLTREE::postOrder()
{
	postOrder(root);
}
bool AVLTREE::searching(Node *node, int key){

	while (node != nullptr)
	{
		if (key > node->data){

			node = node->RightChild;
		}
		else if (key < node->data){

			node = node->LeftChild;
		}
		else
			return true;
	}
	return false;
}
void AVLTREE::searching(int key){

	searching(root, key);
	if (!searching(root, key)){

		cout << "Value " << key << " Not Found In AVL TREE "<<endl;
	}
	else{

		cout << "Value " << key << " Found In AVL TREE "<<endl;
	}
}

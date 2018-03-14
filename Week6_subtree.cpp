/*
Subtree of Another Tree
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s.
A subtree of s is a tree that consists of a node in s and all of that node's descendants.
*/

#include <bits/stdc++.h>
using namespace std;
struct node {
	int data;
	node *left, *right;
};

bool compare(node *r1, node *r2) {
	if (r1==NULL&&r2==NULL)
		return true;

	if (r1==NULL||r2==NULL)
		return false;

	return (r1->data==r2->data&&compare(r1->left,r2->left)&&compare(r1->right,r2->right));
}

bool isSubtree(node *T, node *S) {
	if (S==NULL) //empty subtree
		return true;
	if (T==NULL) //empty tree
		return false;
	if (compare(T,S))
		return true;

	return isSubtree(T->left,S)||isSubtree(T->right,S);
}

struct node* newNode(int data) {
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

bool t1(){
	//empty trees
	struct node *T=NULL;	
	struct node *S=NULL;
	return isSubtree(T,S);
}

bool t2(){
	//empty subtree
	struct node *T=newNode(1);	
	struct node *S=NULL;
	return isSubtree(T,S);
}

bool t3(){
	//empty tree
	struct node *S=newNode(1);	
	struct node *T=NULL;
	return (!isSubtree(T,S));
}

bool t4(){
	//subtree with single element
	struct node *S=newNode(2);
	//tree
	struct node *T=newNode(1);
	T->left=newNode(2);
	T->right=newNode(3);
	T->left->left=newNode(4);
	T->left->right=newNode(5);
	return (!isSubtree(T,S));
}

bool t5(){
	//tree with single element
	struct node *S=newNode(2);
	//subtree
	struct node *T=newNode(1);
	T->left=newNode(2);
	T->right=newNode(3);
	T->left->left=newNode(4);
	T->left->right=newNode(5);
	return (!isSubtree(S,T));
}

bool t6(){
	//subtree same as tree
	struct node *S=newNode(1);
	S->left=newNode(2);
	S->right=newNode(3);
	S->left->left=newNode(4);
	S->left->right=newNode(5);
	//tree
	struct node *T=newNode(1);
	T->left=newNode(2);
	T->right=newNode(3);
	T->left->left=newNode(4);
	T->left->right=newNode(5);
	return isSubtree(T,S);
}

bool t7(){
	//no subtree match
	struct node *S=newNode(3);
	S->left=newNode(2);
	S->right=newNode(1);
	//tree
	struct node *T=newNode(1);
	T->left=newNode(2);
	T->right=newNode(3);
	T->left->left=newNode(4);
	T->left->right=newNode(5);
	return (!isSubtree(T,S));
}

bool test() {
	return t1()&&t2()&&t3()&&t4()&&t5()&&t6()&&t7();
}

int main() {
	//tree
	struct node *T=newNode(1);
	T->left=newNode(2);
	T->right=newNode(3);
	T->left->left=newNode(4);
	T->left->right=newNode(5);
	
	//subtree
	struct node *S=newNode(2);
	S->right=newNode(5);
	S->left=newNode(4);

	isSubtree(T, S)?printf("True"):printf("False");
//	cout<<test();
	return 0;
}

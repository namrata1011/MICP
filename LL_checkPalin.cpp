//Implement a function to check if a linked list is a palindrome
/*
Steps:
1. Find middle element of linked list
2. Reverse second half of the linked list
3. Compare first and second half. IF they are identical, then it is a palindrome, else not.
*/
#include <bits/stdc++.h>
using namespace std;
 
struct node {
   int data;
   node * next;
};

void insert(node **head,int data) {
   node *temp = new node;
   temp->data=data;
   temp->next= *head;
   *head=temp; 
}

node* middle(node *head) {
   node *ptr1=head;
   node *ptr2=head;
   while(ptr2!=NULL && ptr2->next!=NULL) {
      ptr1=ptr1->next;
      ptr2=ptr2->next->next;   
   }
   return ptr1;
}

void reverse(node **head) {
	//iterative reverse
   node *prev,*curr,*next;
   prev=NULL;
   curr=*head;
   while(curr!=NULL) {
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
   }
   (*head)=prev;
}
 
int compare(node *head1,node *head2) {
   int check;
   while(head1 != head2 && head2 != NULL) {
      if(head1->data == head2->data) {
         check=1;
         head1=head1->next;
         head2=head2->next;
      }
      else {
         check = 0;
         break;
      }
   }
   return check;
}

int palindrome(node *head) {
	if (head==NULL || head->next==NULL) return 1;
   node *mid=middle(head);
   reverse(&mid);
   return (compare(head,mid) == 0) ?0:1;
}

bool t1() {
	node* head= NULL;
	if (palindrome(head)==1) return true;
	return false;
}

bool t2() {
	node* head= NULL;
	insert(&head,1);
	if (palindrome(head)==1) return true;
	return false;
}

bool t3() {
	node* head= NULL;
	insert(&head,1);
	insert(&head,1);
	if (palindrome(head)==1) return true;
	return false;
}

bool t4() {
	node* head= NULL;
	insert(&head,1);
	insert(&head,2);
	if (palindrome(head)==0) return true; 
	return false;
}

bool t5() {
	node* head= NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,1);
  	insert(&head,2);
  	insert(&head,2);
  	insert(&head,1);
	if (palindrome(head)==0) return true; 
	return false;
}

bool test() {
	return(t1()&&t2()&&t3()&&t4()&&t5());
}
 
int main() {
	node* head = NULL;  
	insert(&head,1);
  	insert(&head,2);
  	insert(&head,2);
  	insert(&head,1);
	if (palindrome(head)) 
  		cout<<"It is a palindrome.";
  	else 
  		cout<<"It is not a palindrome.";
//  	cout<<test();
  	return 0;
}

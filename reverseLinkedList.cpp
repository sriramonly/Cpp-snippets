/*
 * =====================================================================================
 *       Filename:  reverseLinkedList.cpp
 *    Description:  reverse a linked list recursively
 *        Version:  1.0
 *        Created:  12/30/2011 01:59:22 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

node * newNode(int data)
{
	node *newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

node * insert(node * &head, int data) //insert data into linked list, into the head of the LL
{
	if(head == NULL)
	{	
		head = newNode(data);
		return head;
	}
	node *temp = newNode(data);
	temp->next = head;
	head = temp;
	return head;
}

void printList(node * head)
{
	if(head == NULL)
		return;
	node * first = head;
	while(first != NULL)
	{
		cout<<first->data<<" ";
		first = first->next;
	}
	cout<<endl;
}
 
void reverse(node * &head)
{
	if(head == NULL)
		return;
	node * first = head;
	node * rest = first->next;
	if(rest == NULL)
		return;
	reverse(rest);
	first->next->next = first;
	first->next = NULL;
	head = rest; //fix the head pointer
}

//from linkedlist.pdf:the best solution
void RecursiveReverse(struct node** headRef) {
	struct node* first;
	struct node* rest;
	if (*headRef == NULL)
		 return; // empty list base case
	first = *headRef; // suppose first = {1, 2, 3}
	rest = first->next; //         rest = {2, 3}
	if (rest == NULL)
		 return; // empty rest base case
	RecursiveReverse(&rest); // Recursively reverse the smaller {2, 3} case
	first->next->next = first; // put the first elem on the end of the list
	first->next = NULL; // (tricky step -- make a drawing)
	*headRef = rest; // fix the head pointer
	cout<<"rest: "<<rest->data<<" " ; //note this line://rest is being passed to head as a reference pointer so its value keeps changing, and when going back withinrecursive calls , its value does not get changed and remains at the tail of the original linked list. !!!!IMPORTANT !!!!!!remember this./
	//NOTE:head and rest are basically pointing to same location because of the rest being passed as reference. So, once rest is at last node, it does not get modified back in while going back in recursive calls.
}

int main()
{
	node * head = NULL;
	insert(head, 6);
	insert(head, 5);
	insert(head, 4);
	insert(head, 3);
	insert(head, 2);
	insert(head, 1);
	printList(head);

	reverse(head);
//	RecursiveReverse(&head);
	printList(head);
	return 0;
}

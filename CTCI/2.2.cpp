/*
 * =====================================================================================
 *       Filename:  2.2.cpp
 *    Description:  problem 2.2
 *        Version:  1.0
 *        Created:  12/28/2011 11:53:12 AM
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

void insert(node * &head, int data) //insert data into linked list, into the head of the LL
{
	if(head == NULL)
	{	
		head = newNode(data);
		return;
	}
	node *temp = newNode(data);
	temp->next = head;
	head = temp;
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
 
int findKthToLast(node *head, int k)
{
	if(head == NULL)
		return -1;
	if(head->next == NULL)
		if(k == 1)
			return head->data;
		else
			return -1; // failure

	node *first = head, *kth = first;
	int cnt = k;
	while(cnt > 0 && kth != NULL)
		kth = kth->next, --cnt;
	if(cnt > 0)  //invalid case
		return -1;//failure
	while(kth != NULL)
		first = first->next, kth = kth->next;
	return first->data;
}

int main()
{
	node * head = NULL;
	insert(head, 9);
	insert(head, 6);
	insert(head, 3);
	insert(head, 4);
	insert(head, 2);
	printList(head);

	cout<<findKthToLast(head,2)<<endl;
	return 0;
}

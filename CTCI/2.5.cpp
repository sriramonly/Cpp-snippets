/*
 * =====================================================================================
 *       Filename:  2.5.cpp
 *    Description:  prblm 2.5
 *        Version:  1.0
 *        Created:  12/28/2011 05:44:05 PM
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

void sum(node *head1, node *head2, node * &head)
{
	node *temp = NULL, *first = head;
	int carry = 0;
	while(head1 != NULL && head2 != NULL)
	{
		int sum = head1->data + head2->data + carry;
		temp = newNode(sum%10);
		if(first == NULL)
			first = temp, head =first;
		else
		{
			first->next = temp;
			first = first->next;
		}
		carry = sum/10;
		head1 = head1->next;
		head2 = head2->next;
	}
	node * t= NULL;
	if(head1 == NULL && head2 != NULL)
	 	t= head2;
	else if(head1 != NULL && head2 == NULL)
		t = head1;
	while(t != NULL)
	{
		int sum = (t->data + carry);
		temp = newNode(sum%10);
		first->next = temp;
		first = first->next;
		carry = sum/10;
		t = t->next;
	}
	if(carry != 0)
	{
		temp = newNode(carry);
		first->next = temp;
		first = first->next;
	}

	first->next = NULL;
}

int main()
{
	node * head1 = NULL;
	insert(head1, 9);
	insert(head1, 9);
	insert(head1, 9);
	insert(head1, 9);
	insert(head1, 9);
	printList(head1);

	node * head2 = NULL;
	insert(head2, 9);
	insert(head2, 9);
	insert(head2, 9);
	insert(head2, 9);
	insert(head2, 9);
	insert(head2, 9);
	printList(head2);

	node *head = NULL;//denotes sumed LL

	sum(head1,head2,head);
	printList(head);

	return 0;
}

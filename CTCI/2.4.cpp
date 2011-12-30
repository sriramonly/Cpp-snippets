/*
 * =====================================================================================
 *       Filename:  2.4.cpp
 *    Description: partition a singly linked list in such a way that all the elements less than x should appear before elements >= x 
 *        Version:  1.0
 *        Created:  12/30/2011 04:08:24 PM
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
 
void insertIntoLessList(node * temp, node * & headLessList)
{
	if(headLessList == NULL)
		headLessList = temp;
	else
		temp->next = headLessList, headLessList = temp;
}
	
void partition(node * & head, int x)
{
	node * first = head, * prev = NULL, *temp;
	node * headLessList = NULL, *headMoreList = NULL;
	while(first != NULL)
	{
		if(first->data < x)
		{
			temp = first->next;
			if(prev != NULL)
				prev->next = first->next;
			else	
				headMoreList = first;
			first->next =NULL;
			insertIntoLessList(first, headLessList);
			first = temp;	
		}
		else
		{
			if(prev == NULL)
				headMoreList = first;
			prev = first, first = first->next;
		}
	}
	if(headLessList != NULL)
		head = headLessList;
	else
		head = headMoreList;
	while(headLessList && headLessList->next != NULL)
		headLessList = headLessList->next;
	if(headLessList)
		headLessList->next = headMoreList;
}


int main()
{
	node * head = NULL;
	insert(head, 9);
	insert(head, 2);
	insert(head, 7);
	insert(head, 18);
	insert(head, 5);
	insert(head, 4);
	insert(head, 12);
	insert(head, 1);
	insert(head, 2);
	insert(head, 3);

	cout<<"Original list: ";
	printList(head);

	partition(head, 9);
	cout<<"List after partitioning: ";
	printList(head);

	return 0;
}

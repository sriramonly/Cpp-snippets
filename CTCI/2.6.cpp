/*
 * =====================================================================================
 *       Filename:  2.6.cpp
 *    Description:  Find the beginning of the loop in a corrupted singly linked list where some node points to an already existing node in list
 *        Version:  1.0
 *        Created:  12/30/2011 02:16:01 PM
 *       Revision:  none
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

node * findBeginningLoop(node * head)
{
	if(head == NULL) 
		return NULL;
	node * slow = head, *fast = head;
	while(slow != NULL && fast != NULL && fast->next != NULL)
	{
		slow = slow->next, fast = fast->next->next;
		if(slow == fast)
			break;
	}
	if(fast == NULL || fast->next == NULL) 
		return NULL; //error: not possible in a LL which has a loop
	slow = head;
	while( slow != fast)
		slow = slow->next, fast = fast->next;
	return slow;
}

int main()
{
	//manually creating a LL with loop 
	node * head = newNode(9);
	head->next = newNode(6);
	head->next->next= newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = head->next->next;

	//will go into infinite loop when printing the LL
	//printList(head);
	
	node *beginLoop = findBeginningLoop(head); 
	if(beginLoop != NULL)
		cout<<beginLoop->data<<endl;
	else 
		cout<<"Loop does not exist"<<endl;

	return 0;
}

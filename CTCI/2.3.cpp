/*
 * =====================================================================================
 *
 *       Filename:  2.3.cpp
 *
 *    Description:  prblm 2.3
 *
 *        Version:  1.0
 *        Created:  12/28/2011 05:02:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 *        Company:  
 *
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
 
void deleteNode(node * del)//pointer to head is not known 
{
	if(del == NULL || del->next == NULL)
	{
		cout<<"cant delete"<<endl;
		return ;//error if del is NULL, not possible to delete if del is the last node *** IMP remember this fact ***
	}
	del->data = del->next->data;
	node * temp = del->next;
	del->next = del->next->next;
	delete temp;
}

int main()
{
	node * head = NULL;
	insert(head, 9);
	insert(head, 6);
	insert(head, 3);
	insert(head, 4);
	node *p = insert(head, 2);
	printList(head);
	deleteNode(p);
	printList(head);



	
	return 0;
}

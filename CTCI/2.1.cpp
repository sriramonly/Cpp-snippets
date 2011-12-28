/*
 * =====================================================================================
 *       Filename:  2.1.cpp
 *    Description:  problem 2.1
 *        Version:  1.0
 *        Created:  12/27/2011 08:47:40 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
#include<unordered_map>
using namespace std ;

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

//involves a bit of tricky coding, take care of 2 diff cases: 1 when u delete the duplicate node, other when u dont delete the next node
void removeDuplicatesUsingHashing(node * head)
{
	if(head == NULL)
		return;
	unordered_map<int,int> mp;
	node *first = head, *second = head->next;
	if(second->next == NULL)
		return ; //only one node
	mp[second->data] = 1;
	while(second != NULL)
	{
		if(mp[second->data] == 0)
			mp[second->data] = 1; 
		else 
		{
			first->next = second->next;
			delete(second);
			second = first->next;
			continue;
		}
		first = first->next;
		if(first) 
			second = first->next;
		else
			second = NULL;
	}
}

void removeDuplicates(node * &head)
{
	if(head == NULL || head->next == NULL)
		return;
	node * first = head;
	while(first->next != NULL)
	{
		node * second = first , * third = second->next;
		while(third != NULL)
		{
			if(third->data == first->data)
			{
				second->next = third->next;
				delete third;
			}	
			second = second->next;
			if(second) 		
				third = second->next;
			else 
				third = NULL;
		}
		first = first->next;
	}
}

int main()
{
	node * head = NULL;
	insert(head, 1);
	insert(head, 4);
	insert(head, 4);
	insert(head, 2);
	insert(head, 1);
	printList(head);
	removeDuplicatesUsingHashing(head);
	printList(head);
	removeDuplicates(head);
	printList(head);
	
	return 0;
}


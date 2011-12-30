/*
 * =====================================================================================
 *
 *       Filename:  2.7.cpp
 *
 *    Description:  checks whether a linked list is a palindrome or not
 *
 *        Version:  1.0
 *        Created:  12/30/2011 01:59:22 PM
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
 

void isPalindrome(node * &head, node *last, bool &ans)
{
	if(head == NULL || last == NULL)
		return;
	isPalindrome(head, last->next, ans);
	if(head->data != last->data) 
	{
		cout<<"setting to false: "<<head->data<<" " <<last->data << endl;
		ans = false;
		return;
	}
	head = head->next;
}


bool isPalindrome(node *head)
{
	bool ans = true;
	isPalindrome(head,head,ans);
	return ans;
}

int main()
{
	node * head = NULL;
	insert(head, 4);
	insert(head, 2);
	insert(head, 6);
	insert(head, 9);
	insert(head, 9);
	insert(head, 6);
	insert(head, 2);
	insert(head, 4);
	printList(head);

	if(isPalindrome(head))
		cout<<"Linked List is a Palindrome"<<endl;
	else	
		cout<<"Linked List is not a Palindrome"<<endl;
	return 0;
}

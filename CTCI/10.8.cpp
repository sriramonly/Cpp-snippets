/*
 * =====================================================================================
 *       Filename:  10.8.cpp
 *    Description:  Indexed BST class
 *        Version:  1.0
 *        Created:  01/02/2012 02:28:55 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
	int leftChild;
};
class IndexedBST
{
	node * root;
	public:
	IndexedBST()
	{
		root = NULL;
	}
	node * newNode(int x)
	{
		node *n = new node;
		n->data = x;
		n->left = NULL;
		n->right = NULL;
		n->leftChild = 0;
		return n;
	}
	void track(int x)
	{
		insert(this->root, x);
	}
	node * insert(node *& root, int x)
	{
		if(root == NULL)
 		{
			root = newNode(x);
			return root;
		}
		if(root->data < x)
			root->right = insert(root->right,x);
		else
		{
			root->leftChild += 1;
			root->left = insert(root->left,x);
		}
		return root;
	}
	int getRankofNumber(int x)
	{
		return getRank(this->root, x);

	}
	int getRank(node * & root, int x)
	{
		int ans = 0;
		if(root == NULL)
			return -1; //failure
		if(root->data == x)
			return root->leftChild;
		else if(root->data < x)
			ans += root->leftChild + 1 + getRank(root->right,x);
		else
			ans += getRank(root->left,x);
		return ans;
	}
};

int main()
{
	IndexedBST idx;
	idx.track(5);
	idx.track(3);
	idx.track(2);
	idx.track(4);
	idx.track(9);
	idx.track(7);
	idx.track(8);
	idx.track(11);
	idx.track(4.5);

	cout<<idx.getRankofNumber(4.5);
	cout<<endl;

	return 0;
}

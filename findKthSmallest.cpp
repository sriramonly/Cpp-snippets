//finding Kth Smallest element in a Binary Search Tree
#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node * insertBST(node *root,int data)
{
	if(root == NULL)
	{
		root = new node;
		root->data = data;
		root->left =  NULL;
		root->right = NULL;
		return root;
	}
	if(data <= root->data) 
		root->left = insertBST(root->left,data);
	else
		root->right = insertBST(root->right,data);
	return root;
}
void inorder(node *root)
{
	if(root == NULL) return ;
	inorder(root->left);
	cout<<root->data<< " " ;
	inorder(root->right);
}


int findKthSmallest(node * root,int &k)
{
	int ans = -1;
	if(root == NULL || k<0) return -1;
	if(k>0)
		ans = findKthSmallest(root->left,k);
	--k;
	if(k==0) ans = root->data;
	if(k>0)
		ans = findKthSmallest(root->right,k);
	return ans;
}


int main()
{
	node *root = NULL;
	root = insertBST(root,5);
	root = insertBST(root,3);
	root = insertBST(root,9);
	root = insertBST(root,7);
	root = insertBST(root,12);
	inorder(root);
	cout<<endl;
	int k = 3;
	cout<<findKthSmallest(root,k);
	return 0 ;
}


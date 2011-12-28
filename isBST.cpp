#include<iostream>
#include<climits>
using namespace std;

struct node
{
	int data;
	node * left;
	node * right;
};

node * newNode(int data)
{
	node * temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node * insert(node * node,int data)
{
	if(node == NULL)
	{
		node = newNode(data);
		return node ;
	}

	if(data <= node->data)
		node->left = insert(node->left,data);
	else
		node->right = insert(node->right,data);
	return node;
}

int minValue(node * root)
{
	if(root == NULL) 
		return -1; // not found
	while(root->left != NULL)
		root = root->left;
	return root->data;
}

int maxValue(node * root)
{
	if(root == NULL) 
		return -1; // not found
	while(root->right != NULL)
		root = root->right;
	return root->data;
}

int isBST(struct node* node) {
	if (node==NULL) return(true);
	// false if the min of the left is > than us
	if (node->left!=NULL && minValue(node->left) > node->data)
		return(false);
	// false if the max of the right is <= than us
	if (node->right!=NULL && maxValue(node->right) <= node->data)
		return(false);
	// false if, recursively, the left or right is not a BST
	if (!isBST(node->left) || !isBST(node->right))
		return(false);
	// passing all that, it's a BST
	return(true);
}

bool isBSTRecur(node *root,int min,int max)
{
	if(root == NULL) return NULL;
	if(min > root->data  || root->data >= max)
		return false;
	return isBSTRecur(root->left, min,root->data) && isBSTRecur(root->right, root->data + 1 , max);
}

bool isBSTOptimal(node * root)
{
	return isBSTRecur(root,INT_MIN,INT_MAX);
}


void findAndReplace(node *root, int oldData,int newData)
{
	if(root == NULL) return;
	if(oldData < root->data)
		findAndReplace(root->left,oldData,newData);
	if(oldData == root->data)
		root->data = newData;
	if(oldData > root->data)
		findAndReplace(root->right,oldData,newData);
}

void inorder(node * node)
{
	if(node == NULL) return;
	inorder(node->left);
	cout<<node->data<<" ";
	inorder(node->right);
}

int main()
{
	node * root = NULL;
	root = insert(root,5);

	root = insert(root,2);
	root = insert(root,3);
	root = insert(root,1);
	root = insert(root,7);
	
	inorder(root);
	cout<<endl;
	cout<<"this tree is a BST or not : "<<isBST(root)<<endl;
	
	findAndReplace(root,3,6);

	inorder(root);
	cout<<endl;
		
	cout<<"this tree is a BST or not : "<<isBST(root)<<endl;

	cout<<"this tree is a BST or not : "<<isBSTOptimal(root);
	
	return 0;
}

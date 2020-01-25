///Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each
///node contains the sum of the left and right subtrees in the original tree. The values of leaf nodes are changed to 0.

// C++ program to convert a tree into its sum tree
#include <iostream>
using namespace std;

/* A tree node structure */
class node
{
	public:
int data;
node *left;
node *right;
};

// Convert a given tree to a tree where
// every node contains sum of values of
// nodes in left and right subtrees in the original tree
int toSumTree(node *Node)
{
	// Base case
	if(Node == NULL)
	return 0;/// sesh leaf e right and left child na thakay 0 return kore value 0 korey dey.

	int old_val = Node->data;

	Node->data = toSumTree(Node->left) + toSumTree(Node->right);

	return Node->data + old_val;
}

// A utility function to print
// inorder traversal of a Binary Tree
void printInorder(node* Node)
{
	if (Node == NULL)
		return;
	printInorder(Node->left);
	cout<<" "<<Node->data;
	printInorder(Node->right);
}

/* Utility function to create a new Binary Tree node */
node* newNode(int data)
{
	node *temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
void add_left(node *parent,node *child)
{
    parent->left=child;
}
void add_right(node *parent,node *child)
{
    parent->right=child;
}
node* tree()
{
    node *ten = newNode(10);
    node *mtwo = newNode(-2);
    add_left(ten,mtwo);
    node *six=newNode(6);
    add_right(ten,six);
    node *eight=newNode(8);
    add_left(mtwo,eight);
    node *mfour= newNode(-4);
    add_right(mtwo,mfour);
    node *seven= newNode(7);
    node *five= newNode(5);
    add_left(six,seven);
    add_right(six,five);

    return ten;
}

/* Driver code */
int main()
{
	node *root = NULL;
	root=tree();
	int x;

	/* Constructing tree given in the above figure */

	toSumTree(root);

	// Print inorder traversal of the converted
	// tree to test result of toSumTree()
	cout<<"Inorder Traversal of the resultant tree is: \n";
	printInorder(root);
	return 0;
}



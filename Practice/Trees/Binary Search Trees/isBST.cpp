#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl    "\n"
//Check if binary tree is BST or not?
class Node
{
public:
	int data;
	Node *left, *right;
};
Node* newNode(int data) {
	Node *node = new Node();
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

// passing min = INT_MIN, and max = INT_MAX.
bool isBST(Node* root, int min, int max) {
	if (!root)
		return true;
	if (root->data < min || root->data > max)
		return false;
	if (isBST(root->left , min, root->data - 1) && isBST(root->right, root->data + 1, max))
		return true;
	return false;
}

// another function -> here taking prev data and comparing while inorder.
// as we know that inorder of the bst is sorted, then checking the previous value with
// the current.
bool isBST2(Node* root, int &prev) {
	if (!root)
		return true;
	if (!isBST2(root->left, prev))
		return false;
	if ( prev > root->data)
		return false;
	prev = root->data;
	return isBST2(root->right, prev)
}

void inorder(Node* root)
{
	if (!root)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
int32_t main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node *root = newNode(4);
	root->left = newNode(2);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(7);

	inorder(root);
	cout << endl;

	cout << isBST(root, INT_MIN, INT_MAX) << endl;
	int mi = INT_MIN;
	cout << isBST2(root, mi);
	return 0;
}
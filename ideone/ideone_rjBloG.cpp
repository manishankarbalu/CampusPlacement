#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// Structure for a binary tree node
struct Node
{
    int key;
    Node *left, *right;
};

// A utility function to create a new node
struct Node* newNode(int key)
{
    struct Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}
void verticalOrder(Node *root)
{
	map<int ,int> m;
	queue<pair<int,struct Node*>> q;
	q.push({0,root});
	while(!q.empty())
	{
		auto p=q.front();
		q.pop();
		m[p.first]+=p.second->key;
		if(p.second->left)q.push({p.first-1,p.second->left});
		if(p.second->right)q.push({p.first+1,p.second->right});
	}
	for(auto it=m.begin();it!=m.end();it++)
	{
		cout<<it->second<<' ';
	}
	m.clear();
}
// Driver program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is \n";
    verticalOrder(root);
    return 0;
}
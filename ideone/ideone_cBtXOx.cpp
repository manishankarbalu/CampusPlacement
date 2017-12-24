    /* Iterative program to print levels line by line */
    #include <iostream>
    #include <queue>
    using namespace std;
     
    // A Binary Tree Node
    struct node
    {
        struct node *left;
        int data;
        struct node *right;
         struct node* nextRight;
    };
       
     
void findNextRight(node* root,int value)
{
	if(!root)
		return;
    queue<node*> q;
    q.push(root);
    node *temp1;
       while (1)
    {node *node;
        // nodeCount (queue size) indicates number of nodes
        // at current lelvel.
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;
 
       
        while (nodeCount > 0)
        {
            node = q.front();
 
            q.pop();
            
           if(node->data == value)
           {
           	 
           	temp1=q.front();
           	
           	if(temp1==NULL)
           	 cout<<"null"<<endl;
           	 else
           	 cout<<temp1->data<<endl;
           }
            
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        
        cout << endl;
    }
}
    // Utility function to create a new tree node
    node* newNode(int data)
    {
        node *temp = new node;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    
     
    // Driver program to test above functions
    int main()
    {
        // Let us create binary tree shown in above diagram
         node *root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(5);
    root->left->left = newNode(8);
    root->left->right = newNode(4);
    
        findNextRight(root, 10);
        findNextRight(root, 2);
        findNextRight(root, 6);
        findNextRight(root, 8);
        findNextRight(root, 4);
        findNextRight(root, 5);
        
       
        return 0;
    }
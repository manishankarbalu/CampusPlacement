//   Binary Tree Snippets

int size(struct node* root)
{
	if(root==NULL)
		 return 0;
	return size(root->left)+1+size(root->right);

}

bool identical(struct node* root1,struct node* root1)
{
	if(root1==NULL && root2==NULL)
		return true;
 if(root1 && root2)
	{return ((root1->data==root2->data)
		        && identical(root1->left,root2->left)
		          && identical(root1->right,root2->right));
    }
    return false
}

int height(struct node* root)
{

	if(root==NULL) return 0;

	int lh = height(root->left);
	int rh = height(root->right);
	if(lh>rh)
		return lh+1;
	else
		return rh+1;
}

//convert a BTree to its Mirror
/*      4
      / \
     2   5
    / \
   1   3
 
 is changed to...
       4
      / \
     5   2
        / \
       3   1     */

void mirror(struct node* root)
{
   if(root==NULL)
   	 return;
   
   mirror(root->left);
   mirror(root->right);

   struct node* temp=root->left;
   root->left=root->right;
   root->right=temp;
}

//count leaf nodes in binary tree

int leafnodes(struct node* root)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	return leafnodes(root->left)+leafnodes(root->right);
}

//Level order traversel in spiral form

int height(struct node* root)
{
	if(root==NULL)
		return 0;
	else
		 return max(height(root->left),height(root->right))+1;
}

void printLevelSpiral(struct node* root,int level,bool t)
{
   if(root==NULL)
   	return;
   if(level == 1)   
   	 printf("%d",root->data);
   else
   {
   	 if(t)
   	 	{
   	 		printLevelSpiral(root->left,level-1,t);
            printLevelSpiral(root->right,level-1,t);
         }
    else
         {
         printLevelSpiral(root->right,level-1,t);
            printLevelSpiral(root->left,level-1,t);	
         } 
     }
}
void moveToLevel(struct node* root)
{
	int h=height(root);
	bool t=true;
	for(i=1;i<=h;i++)
	{
		printLevelSpiral(root,i,t);
		t=!t;
	}
}

//  This method is o(n^2)
// Best use 2 stacks to do

//print all root to leaf paths
void printVectorPaths(vector<int> v,int ptr)
{
         for(int i=0;i<ptr;i++)
         	printf("%d",v[i]);
}

void printPaths(struct node* root,vector<int> v,int ptr)
{
   if(root==NULL)
   	 return;

   v.push(root->data);
   	ptr++;

   	if(root->left==NULL && root->right==NULL)
   		printVectorPaths(v,ptr);
   
   	printPaths(root->left,v,ptr);
   	printPaths(root->right,v,ptr);


}

void printRootToLeafPaths(struct node* root)
{
	int vector<int> v;int ptr=0
	printPaths(root,v,ptr);
}

//childern sum property
/*     10 
      / \
     8   2
    / \
   5   3       */

int checkChildrenSumProperty(struct node* root)
{
	if(root==NULL || !root->left && !root->right) 
		return 1;
	int ldata=0,rdata=0;
	if(root->left)
		ldata=root->left->data;
	if(root->right)
		rdata=root->right->data;

	if((root->data == ldata + rdata)
	         && checkChildrenSumProperty(root->left)
		        && checkChildrenSumProperty(root->right))
		return 1;
	else
		return 0;
}


//check if there exists a path from root to leaf with given sum

int pathwithGivenSum(struct node* root,int sum,int foundSum)
{
	if(root==NULL)
		return 0;
	foundSum+=root->data;
    if((!root->left && !root->right) && foundSum == sum)
    	 return 1;
   return( pathwithGivenSum(root->left,sum,foundSum);
   
    || pathwithGivenSum(root->right,sum,foundSum); 
   
   )
}

// Connect nodes at same level

struct node* getnextRight(struct node* p)
{
      struct node* temp=p->nextRight;

      while(temp)
      {
      	if(temp->left)
      		return temp->left;
      	if(temp->right)
      		return temp->right;

      	temp=temp->nextRight;
      }
      return NULL;
}

struct node* connectNodesAtSameLevel(struct node* p)
{
    if(!p)
    	return NULL;
    p->nextRight=NULL;
    while(p)
    {
    	struct node* q = p;
 
        while(q)
        {
        	if(q->left)
        		{
        			if(q->right)
        				q->left->nextRight=q->right;
        			else
        				q->left->nextRight=getnextRight(q);
        		}
        		if(q->right)
        			q->right->nextRight=getnextRight(q);
        		q=q->nextRight;
        }
        if(p->left)
        	p=p->left;
        else
        	if(p->right)
        		p=p->right;
        	else
        		p=p->nextRight;

    }
}

// Print Maximum sum path form root to leaf

bool printPathWithMaxSum(struct node* root,int curSum,int maxSum)
{
	if(!root)
		return false;
	curSum+=root->data;

	if(curSum==maxSum || printPathWithMaxSum(root->left,curSum,maxSum) || printPathWithMaxSum(root->right,curSum,maxSum))
    {
    	printf("%d , ",root->data);
    	return true;
    }
  return false;
}

void findMaxSum(struct node* root,int curSum,int *maxSum)
{
	if(!root)
		return;
	curSum+=root->data;
	if(!root->left && !root->right)
	{
		if(*maxSum<curSum)
			*maxSum=curSum;
	}
	findMaxSum(root->left,curSum,maxSum);
	findMaxSum(root->right,curSum,maxSum);
}

void printMaxSumPathRootToLeaf(struct node* root)
{
	int maxSum=INT_MIN;
    int curSum=0;
	findMaxSum(root,curSum,&maxsum);
	printPathWithMaxSum(root,curSum,maxSum);
}

// boundary tree traversal of binary tree

    void leftTraversal(struct node* root,vector<int>& v)
    {
        if(!root)
        	return;
    
    if(root->left)
      {
        v.push_back(root->data);
        leftTraversal(root->left,v);
      }
    else
        if(root->right)
        { 
         v.push_back(root->data);
         leftTraversal(root->right,v);

        }
    }
     
    void rightTraversal(struct node* root,vector<int>& v)
    {
    if(!root)
        	return;
       
    if(root->right)
      {
        v.push_back(root->data);
        leftTraversal(root->right,v);
      }
    else
        if(root->left)
        { 
         v.push_back(root->data);
         leftTraversal(root->left,v);

        }
    }
     
    void leafTraversal(struct node* root,vector<int>& v)
    {
     
         if(!root)
         	return;
         if(root->left==NULL && root->right==NULL)
         	v.push_back(root->data);
         leafTraversal(root->left,v);
         leafTraversal(root->right,v);
    }
     
    void boundaryTraversal(struct node* root)
    {
    	if(!root)
    		return;
    	vector<int> v;
        v.push_back(root->data);
    	leftTraversal(root->left,v);   	
        leafTraversal(root,v);
        rightTraversal(root->right,v);
    	
    	for(int i=0;i<v.size();i++)
    	   printf("%d ",v[i]);
    }

//Sum of difference between odd and even level of btree

int height(struct node* root)
{
	if(!root)
		return 0;
	int lheight=height(root->left);
	int rheight=height(root->right);
	if(lheight>rheight)
		return lheight+1;
	else
		return rheight+1;
}

void calculateCount(struct node* root,int level,int* oddSum,int* evenSum,int choice)
{
    if(!root)
    	return;
    if(level==1)
    {
    	if(choice==1)
    		*evenSum+=root->data;
    	else
    		if(choice==0)
    			*oddSum+=root->data;
    return;
    }
    calculateCount(root->left,level-1,oddSum,evenSum,choice);
    calculateCount(root->right,level-1,oddSum,evenSum,choice);
}

void DifferenceInLevel(struct node* root)
{
	int h=height(root);
	int oddSum=0,evenSum=0;
	for(int i=1;i<=root,i++)
	{
		if(i%2==0)
           calculateCount(root,i,&oddSum,&evenSum,1);
	    else
	       calculateCount(root,i,&oddSum,&evenSum,0)  
	}
	printf("difference is %d  : ",(evenSum-oddSum));
}

//depth of deepest odd level leaf node

int deepestOddLevel(struct node* root,int level)
{
      if(!root)
      	return 0;
      if(!root->left && !root->right && level&1)
      	return level;
      int lmax=deepestOddLevel(root->left,level+1);
      int rmax=deepestOddLevel(root->right,level+1);
      if(lmax>rmax)
      	 return lmax;
      	else
      		return rmax;
}

void findDepthOfOddLevelLeafNode(struct node* root)
{
	deepestOddLevel(root,0);
}

// Check if all leaves are at same Level

bool areLeavesAtSameLevel(struct node* root,int level,int* levelReference)
{
	if(!root)
		return true;
	if(!root->left && !root->right)
	{
		if(*levelReference==0)
		{
			*levelReference=level;
		}

		return (level==*levelReference);
	}
    
    return areLeavesAtSameLevel(root->left,level+1,levelReference);
        && areLeavesAtSameLevel(root->right,level+1,levelReference);

}
void checkLevesAtSameLevel(struct node* root)
{
	int level=0,levelReference=0;
	areLeavesAtSameLevel(root,level,&levelReference);
}

//Print the left View of Btree

void printLeftView(struct node* root,int level,int* maxlevel,vector<int> &v)
{
   if(!root)
   	return;
   if(*maxlevel<level)
   {
    v.push_back(root->data);
   	*maxlevel=level;
   }
   printLeftView(root->left,level+1,maxlevel,v);
   printLeftView(root->right,level+1,maxlevel,v);
}

void leftView(struct node* root)
{
	vector<int> v;
	int level=1,maxlevel=0;
	printLeftView(root,level,&maxlevel,v);
}

//Find Deepest left leaf node

void deepestLLeafNode(struct node* root,int level,int* maxlevel,int* value)
{
  if(!root)
  	return;
  if(level>*maxlevel)
  {
  	*maxlevel=level;
  	value=root->data;
  }

deepestLLeafNode(root->left,level+1,maxlevel,value);
deepestLLeafNode(root->right,level+1,maxlevel,value);
}

void findDeepestLLeafNode(struct node* root)
{
	int level=1,int maxlevel=0,int value=0;
    deepestLLeafNode(root,level,&maxlevel,&value);	
}

//Print the ancestors of given node

bool printAncestors(struct node* root,int key)
{
	if(!root)
		return false;
    if(root->data==Key || printAncestors(root->left,key) || printAncestors(root->right,key))
        {
        	printf("%d",root->data);
        	return true;
        }
    else
    	return false;
}

//check if given treee is a sumTree
int isLeaf(struct node* root)
{
	if(!root->left && !root->right)
		return 1;
	else
		return 0;
}

int checkSumTree(struct node* root)
{
	if(!root || isLeaf(root))
		return 1;
	int lnum,rnum;
	if(checkSumTree(root->left) && checkSumTree(root->right))
     {
     	if(root->left==NULL)
     		lnum=0;
     	else
     		if(isLeaf(root->left))
     			lnum=root->left->data;
     		else
     			lnum=root->left->data * 2;

     	if(root->right==NULL)
     		rnum=0;
     	else
     		if(isLeaf(root->right))
     			rnum=root->right->data;
     		else
     			rnum=root->right->data * 2;

     	return(root->data==lnum+rnum)
     }
     return 0;
}

//convert a tree to sum tree
int convetToSumTree(struct node* root)
{	if(!root)
	   return 0;

	int oldValue=root->data;

	root->data=convetToSumTree(root->left)+convetToSumTree(root->right);
    
    return oldValue+root->data;
}

//Print nodes at k distance from root

void printNodesAtKDistance(struct node* root,int k)
{
	if(!root)
		return;
    if(k==0)
    	{
    		printf("%d ",root->data)
            return;
        }
    else
    	{
    		printNodesAtKDistance(root->left,k-1);
            printNodesAtKDistance(root->right,k-1);
        }  
}
//Get the Level of a node in btree

int getLevelOfNode(struct node* root,int key,int level)
{
	if(!root)
    	return;
    if(root->data==key)
    {
    	return level;
    }

    int nodeLevel=getLevelOfNode(root->left,key,level+1);
    if(nodeLevel==0)
    	nodeLevel=getLevelOfNode(root->right,key,level+1);
    return nodeLevel;    
}

//Find the least Common Ancestor

struct node* LCA(struct node* root,int n1,int n2)
{
	if(!root)
		return NULL;
	if(root->data==n1 || root->data==n2)
		return root;

	struct node *llca=LCA(root->left,n1,n2);
	struct node *rlca=LCA(root->right,n1,n2);
    
    if(llca && rlca) return root;

    return(llca!=NULL)?llca:rlca;  
}
//when one of the node is not present then this method fails
  //use 2 variables to check whether both keys r present

//LCA can be found using 2 arrays without recursion

//Distance between 2 nodes

int findLevelDist(struct node* root,int k,int level)
{
    if(!root)
    	return 0;
    if(root->data==k)
    	return level;
int llevel=-1;
    int llevel=findLevelDist(root->left,k,level+1);
    if(level!=-1)
    	return llevel;
    else
        return findLevelDist(root->right,k,level+1);
}

void findLCADistance(struct node* root,int n1,int n2,int *d1,int *d2,int* dist,int level)
{
	if(!root)
		return NULL;

	if(root->data==n1)
	{
        *d1=level;
		return root;
	}
	if(root->data==n2)
	{
		*d2=level;
		return root;
	}

	struct node* llca=findLCADistance(root->left,n1,n2,d1,d2,dist,level+1);
	struct node* rlca=findLCADistance(root->right,n1,n2,d1,d2,dist,level+1);
   
    if(llca && rlca)
    {
    	(*dist)=(*d1)+(*d2)-2 * (level);
    	return root;
    }

    return (llca!=NULL)?llca:rlca;
}

int findDistaceBetweenNodes(struct node* root,int n1,int n2)
{
    int d1=-1,d2=-1,dist=0,level=1;
    
    struct node* lca=findLCADistance(root,n1,n2,&d1,&d2,&dist,level);
    
    if(d1!=-1 && d2!=-1)
    {
    	return dist;
    }

    if(d1!=-1)
    {
    	dist=findLevelDist(lca,n2,level);
        return dist;
    }
    if(d2!=-1)
    {
    	dist=findLevelDist(lca,n1,level);
        return dist;
    }
    return -1;
}

//Inorder traversal of btree (Iteratively)

void inorderIteratively(struct node* root)
{
	if(!root)
		return;
	struct node* current=root;
	stack<struct node*> s;
	bool done=0;
    while(!done)
    {
       if(current)
       {
       	  s.push(current);
       	  current=current->left;
       }
       else
       {
       	   if(!s.empty())
       	   {
       	   	current=s.pop();
       	   	printf("%d ",current->data);
       	    current=current->right;
       	   }
       	   else
       	   {
       	   	done=1;
       	   }

       }
     
    }
}

//Diameter of a BTree

int findDiameter(struct node* root,int *height)
{
	int lh=0,rh=0,ld=0,rd=0;
	if(!root)
		{
			*height=0;
			return 0;	
	    }
	ld=findDiameter(root->left,&lh);
	rd=findDiameter(root->right,&rh);

	*height=(lh>rh)?lh+1:rh+1;

	return max(lh+rh+1,max(ld,rd));
}

//PostOrder Traversal (Iterative)
// Using one stack

void postOrderIterative(struct node* root)
{
   stack<struct node*> s;
   do
   {
   	  while(root)
   	  {
   	  	if(root->right)
   	  		s.push(root->right);
   	  	s.push(root);
   	  	root=root->left;
   	  }

   	  root=s.pop()

   	  if(root->right && root->right==s.top())
   	  {
   	  	s.pop();
   	  	s.push(root);
        root=root->right;
   	  }
   	  else
   	  {
          cout<<root->data<<" ";
          root=NULL;
   	  }

   }while(!s.empty());
}

//Maximum sum path between 2 leaves

int maxSumPathLeaves(struct node* root,int* maxSum)
{
      if(!root)
      	return 0;
      if(!root->left && !root->right)
      	return root->data;
      int ls=maxSumPathLeaves(root->left,maxSum);
      int rs=maxSumPathLeaves(root->right,maxSum);

      if(root->left && root->right)
      {
      	*maxSum=max(*maxSum,ls+rs+root->data);
      	return *maxSum;
      }

      return (root->left)?ls+root->data:rs+root->data;
}

//check for validBST (Smart)

bool nTime=true;//global declaration
int prev=0;//global declaration

bool check(int val)
{
	if(nTime)
	{
		nTime=false;
		prev=val;
		return true;
	}

	if(prev>=val) return false;

	prev=val;
	return true;
}
bool isValidBST(struct node* root)
{
	if(!root)
		return true;
	return
	     isValidBST(root->left)
	      && check(root->data)
	        && isValidBST(root->right);
}

//Reverse alternate levels of Perfect Binary Tree
void preOrderTrick(struct node* root1,struct node* root2,int level)
{
   if(!root1 || !root2)
      return;
  if(level%2==0)
  	 swap(root1->data,root2->data);

  preOrderTrick(root1->left,root2->right,level+1);
  preOrderTrick(root1->right,root2->left,level+1)

}

void reverseAlternateLevel(struct node* root)
{
	preOrderTrick(root->left,root->right,0);
}


//
 //   Building a tree given traversals
//

//  from inorder and preorder traversals
int searchInorderIndex(int arr,int stPt,int endPt,int value )
{
	int i;
	for(i=stPt;i<endPt;i++)
	{
       if(arr[i]==value)
       	 return i;
	}

}

struct node* buildTree(int in[],int pre[],int stPt,int endPt)
{
	static int preIndex=0;

	if(stpt>endPt)
		return NULL;

	struct node* temp=pre[preIndex++];

	int inIndex=searchInorderIndex(in,endPt,temp);

    temp->left=buildTree(in,pre,stPt,iIndex-1);
    temp->right=buildTree(in,pre,iIndex+1,endPt);

    return temp;
}

//Find two trees are isomorphic

bool isIsomorphic(struct node* root1,struct node* root2)
{
	if(!root1 && !root2)
		return true;
	if(root1 || root2)
		return false;
	if(root1->data != root2->data)
		return false;

	return ( isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right)   
		       || isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left));
}

//find nodes at k distance from target node

void nodesDown(struct node* root,int k)
{
	if(!root)
		return;
	if(k==0)
		cout<<node->data;
	nodesDown(root->left,k-1);
	nodesDown(root->right,k-1);
}

int nodesAtKDistanceFromTarget(struct node* root,struct node* target,int k)
{
	if(!root)
		return -1;
	if(root==target)
	{
		nodesDown(root,k);
		return 0;
	}

	int ls=nodesAtKDistanceFromTarget(root->left,target,k);

	if(ls!=-1)
	{
		if(ls+1==k)
			cout<<root->data;
		else
			nodesDown(root->right,target,k-ls-2);
		return ls+1;

	} 
	int rs=nodesAtKDistanceFromTarget(root->right,target,k);
	if(rs!=-1)
	{
		if(rs+1==k)
			cout<<root->data;
		else
			nodesDown(root->left,target,k-ls-2);
		return rs+1;

	}
	return -1;

}

//check for height balanced tree (whose has leaf at same level or utmost 1 diff)

int checkForBalanced(struct node* root,int *height)
{
	if(!root)
	{
		*height=0;
		return 1;
	}

	int ls=0,rs=0,l,h;
    l=checkForBalanced(root->left,&ls);
    h=checkForBalanced(root->right,&rs);
    
    *height=((ls>rs)?ls:rs)+1;
    if(ls-rs>=2 || rs-ls>=2)
    	return 0;
    return (l&&h);

}
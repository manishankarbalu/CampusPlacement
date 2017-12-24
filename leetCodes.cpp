
//Minimum Path Sum.cpp


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        for(int i=1;i<m;i++)
            grid[i][0]+=grid[i-1][0];
        for(int i=1;i<n;i++)
            grid[0][i]+=grid[0][i-1];
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};

//Maximum Length of Pair Chain.cpp


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size()==0) return 0;
        sort(pairs.begin(),pairs.end(),cmp);
        int i=0,j=0,cnt=0;
        for(;j<pairs.size();j++)
        {
            if(pairs[i][1]<pairs[j][0] || j==0)
            {
                cnt++;i=j;
            }
        }
        return cnt;
    }
    static bool cmp(vector<int>a,vector<int>b)
    {
        return a[1]<b[1];
    }
};

//Reverse Words in a String.python


class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return " ".join(s.strip().split()[::-1])

//Permutations.python


class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        r=[list(i) for i in itertools.permutations(nums)]
        return r

//Find Minimum in Rotated Sorted Array II.cpp


class Solution {
public:
int findMin(vector<int> &num) {
    int start = 0;
    int end = num.size()-1;
    int mid;
    while(start<end){
        if(num[start]<num[end])
        break;
        mid = start+(end-start)/2;
        if(num[mid]>num[end]){
            start = mid+1;
        }
        else if(num[mid]==num[end]){
            start++;
            end--;
        }
        else
        end= mid;
    }
    return num[start];
 }
};

//Palindrome Linked List.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
     ListNode* reverseList(ListNode* head)
    {
        ListNode* cur=head,*prev=NULL,*nex=NULL;
        while(cur)
        {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
          return true;
          ListNode *slow=head,*fast=head;
          while(fast->next && fast->next->next)
          {
              fast=fast->next->next;
              slow=slow->next;
          cout<<slow->val;
              
          }
          slow->next=reverseList(slow->next);
          slow=slow->next;
          
          while(slow)
          {
              if(head->val!=slow->val)
               return false;
               head=head->next;
               slow=slow->next;
          }
          return true; 	
    }
};

//Number of Islands.cpp


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size()==0)
            return 0;
        if(grid[0].size()==0)
            return 0;
        int n=grid.size(),m=grid[0].size(),cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    find(i,j,n,m,grid);
                    cnt++;
                }
            }
        }
      /*  for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
         cout<<grid[i][j]<<' ';
            }
            cout<<'\n';
        }*/
        
        return cnt;
    }
    void find(int i,int j,int n,int m,vector<vector<char>>& grid)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0') return;
        grid[i][j]='0';
        find(i+1,j,n,m,grid);
        find(i-1,j,n,m,grid);
        find(i,j+1,n,m,grid);
        find(i,j-1,n,m,grid);
    }
};

//Spiral Matrix.cpp


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        
        vector<int> v;
       
         if(m.size()==0 || m[0].size()==0)
            return v;
        int rowbeg=0,rowend=m.size()-1, colbeg=0,colend=m[0].size()-1;
       
        while(rowbeg<=rowend && colbeg<=colend)
        {
            for(int i=colbeg;i<=colend;i++)
            {
                v.push_back(m[rowbeg][i]);
            }
            rowbeg++;
            for(int i=rowbeg;i<=rowend;i++)
            {
                v.push_back(m[i][colend]);
            }
            colend--;
            if(rowbeg<=rowend && colbeg<=colend)
            {
                for(int i=colend;i>=colbeg;i--)
                {
                    v.push_back(m[rowend][i]);
                }
               rowend--;
            
                for(int i=rowend;i>=rowbeg;i--)
                {
                    v.push_back(m[i][colbeg]);
                }
             colbeg++;
            }  
        }
        return v;
    }
};

//Validate Binary Search Tree.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool first = true;
    int prev = 0;
public:
    bool isValidBST(TreeNode *root) {
        if(root == NULL) return true;
        
        return (
            isValidBST(root->left)
            && check(root->val)
            && isValidBST(root->right));
    }
    
    bool check(int val)
    {
        if(first)
        {
            first = false;
            prev = val;
            return true;
        }
        
        if(prev >= val) return false;
        
        prev = val;
        return true;
    }
};

//Delete Operation for Two Strings.cpp


class Solution {
public:
    int minDistance(string w1, string w2) {
   int n1=w1.size();int n2=w2.size();
        if(n1==0) return n2;
        if(n2==0) return n1;
        //vector<vector<int>> v(w1.size(),vector<int> (w2.size(),0));
         int v[n1+1][n2+1]={0};  
            for(int i=0;i<=n2;i++)
                v[0][i]=i;
         for(int i=0;i<=n1;i++)
                v[i][0]=i;
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(w1[i-1]==w2[j-1])
                    v[i][j]=v[i-1][j-1];
                else
                    v[i][j]=min(v[i][j-1]+1,v[i-1][j]+1);
            }
        }
        return v[n1][n2];
    }
};

//Minimum Size Subarray Sum.cpp


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& arr) {
        int n=arr.size();
        int sum=0,start=0,minlen=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            while(sum>=s)
            {
                minlen=min(minlen,i-start+1);
                sum-=arr[start++];
            }
        }
        return (minlen==INT_MAX)?0:minlen;
    }
};

//Binary Tree Inorder Traversal.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
      void inorderTraversalUtil(TreeNode* root,vector<int> &v)
      {
         if(!root)
           return;
    
            inorderTraversalUtil(root->left,v);
            v.push_back(root->val);
             inorderTraversalUtil(root->right,v);
      }
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> v;
        inorderTraversalUtil(root,v);
        return v;
    }
};

//Remove Nth Node From End of List.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *ptr=head,*temp=head;int t=0;
        
        while(t<n)
        {
            ptr=ptr->next;
            t++;
        }
       // cout<<ptr->val;
        if(ptr==NULL)
        {
            head=head->next;
            delete(temp);
            return head;
        }
        while(ptr->next!=NULL)
        {
            temp=temp->next;
            ptr=ptr->next;
        }
        
        delete(temp->next);
        temp->next=temp->next->next;
        
        return head;
        
    }
};

//Is Subsequence.c


bool isSubsequence(char* s, char* t) {
    
    while (*t)
        {  //printf("%c ",s);
            s += *s == *t++;
            //printf("%c ",s);
        }
    return !*s;
}

//Binary Tree Right Side View.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void rightSideViewUtil(TreeNode* root,vector<int> &v,int* maxLevel,int level)
    {
        if(!root)
           return;
        if(*maxLevel<level)
        {
            *maxLevel=level;
            v.push_back(root->val);
        }
        
        rightSideViewUtil(root->right,v,maxLevel,level+1);
        rightSideViewUtil(root->left,v,maxLevel,level+1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> v;
        int level=1,maxLevel=0;
        rightSideViewUtil(root,v,&maxLevel,level);
        return v;
    }
};

//Multiply Strings.python


class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        return str(int(num1)*int(num2))

//Predict the Winner.cpp


class Solution {
public:
    
    int getVal(vector<int>& arr,int i,int j)
    {
        if(i==j) return arr[i];
        if(i+1==j) return max(arr[i],arr[j]);
        return max(arr[i]+min(getVal(arr,i+2,j),getVal(arr,i+1,j-1)),arr[j]+min(getVal(arr,i+1,j-1),getVal(arr,i,j-2)));
    }
    bool PredictTheWinner(vector<int>& arr) {
        
        int n=arr.size();
        int p1=0,p2=0;//bool flag=true;
        for(int i : arr)
            p2+=i;
        p1=getVal(arr,0,n-1);
        return (p1>=p2-p1)?true:false;
    }
};

//Sum of Left Leaves.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum(TreeNode* root,bool c)
    {
         if(!root)
             return 0;
         if(!root->left && !root->right && c)
             return root->val;
          return sum(root->left,true)+sum(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
     
         if(!root)
             return 0;
//if(!root->left && !root->right)
  //           return root->val;
          return sum(root->left,true)+sum(root->right,false);
               
        
    } 
};

//Binary Tree Zigzag Level Order Traversal.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
       vector<vector<int>> result;
        if(!root) return result;
        
        stack<TreeNode*> curLevel;
        curLevel.push(root);
        bool forward = true; // true: print left child first then right. false: print right child first then left child
        
        while(!curLevel.empty()){
            stack<TreeNode*> nxtLevel;
            vector<int> interim;
            while(!curLevel.empty()){
                TreeNode* cur = curLevel.top();
                curLevel.pop();
                interim.push_back(cur->val);
                if(forward){
                    if(cur->left) nxtLevel.push(cur->left);
                    if(cur->right) nxtLevel.push(cur->right);
                }else{
                    if(cur->right) nxtLevel.push(cur->right);
                    if(cur->left) nxtLevel.push(cur->left);
                }
            }
            forward = !forward;
            result.push_back(interim);
            curLevel = nxtLevel;
        }
        
        return result;
    }
};

//Lowest Common Ancestor of a Binary Tree.c


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* lowestCommonAncestorUtil(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q,int* v1,int* v2)
 {
 if(!root)
      return NULL;
      
    if(root==p)
    {
        *v1=1;
        return root;
    }
    if(root==q)
    {
        *v2=1;
        return root;
    }  
    struct TreeNode* llca=lowestCommonAncestorUtil(root->left,p,q,v1,v2);
    struct TreeNode* rlca=lowestCommonAncestorUtil(root->right,p,q,v1,v2);
    
    if(llca && rlca)
        return root;
    
    return (llca!=NULL)?llca:rlca;   
 }
 
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    int v1=0,v2=0;
    struct TreeNode* lca=lowestCommonAncestorUtil(root, p, q, &v1, &v2);
    return lca;
    
}

//ZigZag Conversion.cpp


class Solution {
public:
    string convert(string s, int n) {
        if(n<=1)
            return s;
        vector<string> v(n,"");int step=0,row=0;
        for(int i=0;i<s.length();i++)
        {
            v[row].push_back(s[i]);
            
            if(row==0)
                step=1;
            else
                 if(row==n-1)
                     step=-1;
            row+=step;
        }
        
        string s1="";
        for(string i : v)
             s1=s1+i;
        return s1;
    }
};

//Best Time to Buy and Sell Stock.c


int maxProfit(int* arr, int n) {
    if(n<2) return 0;
    int minEle=arr[0],maxDiff=arr[1]-arr[0];
        for(int i=1;i<n;i++)
        {
            if(maxDiff<arr[i]-minEle)
               maxDiff=arr[i]-minEle;
            if(minEle>arr[i])
               minEle=arr[i];
        }
        return (maxDiff>0)?maxDiff:0;
}

//Intersection of Two Linked Lists.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA || !headB)
               return NULL;
        if(headA==headB)
           return headA;
        ListNode *a=headA,*b=headB;
        int count1=0,count2=0;
        while(a)
        {
            count1++;
            a=a->next;
        }
        while(b)
        {
            count2++;
            b=b->next;
        }
        a=headA;b=headB;
        if(count1>count2)
        {
            int diff=count1-count2;
            while(diff)
            {
                a=a->next;
                diff--;
            }
        }
        else
        {
            int diff=count2-count1;
            while(diff)
            {
                b=b->next;
                diff--;
            }
            
        }
        
        while(a && b)
        {
            if(a==b)
               return a;
               
             a=a->next;
             b=b->next;
        }
        return NULL;
    }
};

//Best Time to Buy and Sell Stock III.cpp


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
    int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for(int j=0;j<n;j++){ int  i=prices[j];
            // Assume we only have 0 money at first
            release2 = max(release2, hold2+i);     // The maximum if we've just sold 2nd stock so far.
            hold2    = max(hold2,    release1-i);  // The maximum if we've just buy  2nd stock so far.
            release1 = max(release1, hold1+i);     // The maximum if we've just sold 1nd stock so far.
            hold1    = max(hold1,    -i);          // The maximum if we've just buy  1st stock so far. 
        }
        return release2;

        
    }
};

//Two Sum.cpp


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> v;
       map<int,int> m;
       for(int i=0;i<nums.size();i++)
       {
           int search=target-nums[i];
           if(m.find(search)!=m.end())
           {
               v.push_back(m[search]);
               v.push_back(i);
               return v;
           }
           m[nums[i]]=i;
       }
       return v;
    }
};

//Single Number.cpp


class Solution {
public:
    int singleNumber(vector<int>& nums) {
     int res=0;
        for(int i : nums)
            res^=i;
        return res;
    }
};

//Jump Game II.cpp


class Solution {
public:
    int jump(vector<int>& arr) {
          
          int step=0,start=0,end=0,n=arr.size();
          while(end<n-1)
          {
              step++;
              int maxend=end+1;
              for(int i=start;i<=end;i++)
              {
                  if(arr[i]+i >= n-1 )
                     return step;
                  maxend=max(maxend,i+arr[i]);     
              }
              start=end+1;
              end=maxend;
          }
          return step;
    }
};

//Power of Four.cpp


class Solution {
public:
    bool isPowerOfFour(int num) {
         return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};

//Maximum Product of Three Numbers.cpp


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
        
    }
};

//Maximal Rectangle.cpp


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        if(matrix[0].size()==0)
            return 0;
        int maxi=INT_MIN;
        vector<int> arr(matrix[0].size(),0);
        //for(int k : arr)
         //   cout<<k<<' ';
       // cout<<endl;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
               // cout<<matrix[i][j];
                if(matrix[i][j]=='0')
                    arr[j]=0;
                else
                    arr[j]+=matrix[i][j]-'0';
            }
            //for(int k : arr)
              //  cout<<k<<' ';
            //cout<<endl;
            //int x=largestRectangleArea(arr);
           // cout<<x<<endl;
         maxi=max(maxi,largestRectangleArea(arr));   
        }
      return maxi ; 
    }
         int largestRectangleArea(vector<int> arr) {
            if(arr.size()==0)
                return 0;
            if(arr.size()==1)
                return arr[0];
            int n=arr.size();
            int tp=0,area=0,maxarea=INT_MIN,i=0;
            stack<int> s;
            while(i<n)
            {
            if(s.empty() || arr[s.top()]<=arr[i])
                s.push(i++);
            else
            {
                tp=s.top();
                s.pop();
                area= arr[tp]*(s.empty()?i:(i-s.top()-1));
                maxarea=max(maxarea,area);
            }
            }
            while(!s.empty())
            {
                tp=s.top();
                s.pop();
                area= arr[tp]*(s.empty()?i:(i-s.top()-1));
                maxarea=max(maxarea,area);
            }
        return maxarea;
     }    
    
};

//Contiguous Array.cpp


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        map<int,int> m;int sum=0,maxlen=0;
        m[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=(nums[i]==0)?-1:1;
            auto it=m.find(sum);
            if(it!=m.end())
            {
                maxlen=max(maxlen,i-it->second);
            }
            else
                m[sum]=i;
        }
        return maxlen;
            
    }
};

//Partition Equal Subset Sum.cpp


class Solution {
public:
    bool canPartition(vector<int>& arr) {
     
        int n=arr.size();
        int sum=0;
        for (int i: arr)
            sum+=i;
        
        if(sum&1)
            return false;
        sum/=2;
        
        bool dp[sum+1][n+1];
        for(int i=0;i<=n;i++)
             dp[0][i]=true;
        for(int j=1;j<=sum;j++)
              dp[j][0]=false;
            
        for(int i=1;i<=sum;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i][j-1];
                if(i>=arr[j-1])
                    dp[i][j]|=dp[i-arr[j-1]][j-1];
            }
        }
        return dp[sum][n];
    }
};

//Product of Array Except Self.cpp


class Solution {
public:
   
   void prd(vector<int> &arr,int i,int n,int *l,int *r)
   {
       if(i==n)
       {
           *r=1;
           return;
       }
       
       int l1=*l;
       (*l)=(*l)*arr[i];
       prd(arr,i+1,n,l,r);
       int t=arr[i];
       arr[i]=l1*(*r);
       (*r)=(*r)*t;
   }

    vector<int> productExceptSelf(vector<int>& nums) {
        int l=1,r=1;
        prd(nums,0,nums.size(),&l,&r);
        return nums;
    }
};

//Maximum Product Subarray.cpp


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int front=1,back=1;
        int maxprd=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            front*=nums[i];
            back*=nums[n-i-1];
            maxprd=max(maxprd,max(front,back));
            front=(front==0)?1:front;
            back=(back==0)?1:back;
        }
        return maxprd;
}
};

//Next Greater Element II.cpp


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v(nums.size());
        stack<int> s;
        for(int i=nums.size()-1;i>=0;i--)
        {
            s.push(nums[i])   ;
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!s.empty() && nums[i]>=s.top())
              s.pop();
            if(!s.empty())
              v[i]=s.top();
            else
            v[i]=-1;
            
            s.push(nums[i]);
        }
     return v;   
    }
};

//Lowest Common Ancestor of a Binary Search Tree.c


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    if(!root)
      return NULL;
      
    if(root==p || root==q)
        return root;
      
    struct TreeNode* llca=lowestCommonAncestor(root->left,p,q);
    struct TreeNode* rlca=lowestCommonAncestor(root->right,p,q);
    
    if(llca && rlca)
        return root;
    
    return (llca!=NULL)?llca:rlca;   
        
}

//Linked List Cycle II.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head || !head->next)
          return NULL;
        ListNode *slow=head,*fast=head;
        bool isCycle=false;
        while(fast->next && fast->next->next)
        {
            
             slow=slow->next;
             fast=fast->next->next;
             if(slow==fast)
               {
                   isCycle=true;
                   break;
               }
        }
    if(!isCycle) return NULL;
    fast=head;
    while(fast!=slow)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return fast;
        
    }
};

//House Robber II.cpp


class Solution {
public:
    int robber(vector<int>& arr,int s,int e) {
                
       int inc=arr[s],ex=0,ne=0;
       for(int i=s+1;i<=e;i++)
       {
           ne=max(inc,ex);
           inc=ex+arr[i];
           ex=ne;
       }
    return max(inc,ex);
    }
    int rob(vector<int>& arr) {
        int n=arr.size();

        if(n==0) return 0;
        if(n==1) return arr[0];
        if(n==2) return (arr[0]>arr[1])?arr[0]:arr[1];
return max(robber(arr,0,n-2),robber(arr,1,n-1));       
    }
};

//Decode Ways.cpp


class Solution {
public:
 
    int numDecodings(string s) {
      if(s=="" )
          return 0;
          
      int n=s.length();
        //n-=1;
        vector<int> dp(n+1,0);
    dp[0]=1;
    if(s[0]=='0')
        dp[1]=0;
    else
        dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        int first=s[i-2]-'0';
        int second=s[i-1]-'0';
        int num=second+first*10;
        if(second)
            dp[i]=dp[i-1];
        if(num>=10 && num<=26)
           dp[i]+=dp[i-2];
   }
        return dp[n];
    }
};

//Reverse Linked List II.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
       if(m==n)return head;
       ListNode* ans=new ListNode(0);
        ans->next=head;
       ListNode *pre=ans,*ps;//,*p=head; 
       n-=m;
       while(--m) pre=pre->next;
       ps=pre->next;
       //ps=prev->next;
      while(n--)
      {
          ListNode *p=ps->next;
          ps->next=p->next;
          p->next=pre->next;
          pre->next=p;
      }
        return ans->next;      
        
    }
};

//Spiral Matrix II.cpp


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {         
        
        vector<vector<int>> v(n,vector<int>(n));
        if(n==0)
            return v;
        int rowbeg=0,rowend=n-1,colbeg=0,colend=n-1,k=1;
        while(rowbeg<=rowend && colbeg<=colend )
        {
            for(int i=colbeg;i<=colend;i++)
                {v[rowbeg][i]=k;k++;}
            rowbeg++;
            for(int i=rowbeg;i<=rowend;i++)
                {v[i][colend]=k;k++;}
            colend--;
            if(rowbeg<=rowend && colbeg<=colend)
            {
                   for(int i=colend;i>=colbeg;i--)
                        {v[rowend][i]=k;k++;}
                    rowend--;
                for(int i=rowend;i>=rowbeg;i--)
                        {v[i][colbeg]=k;k++;}
                    colbeg++;
            }  
        }
        return v;      
    }
};

//Merge Sorted Array.cpp


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=m-1,j=n-1,tar=m+n-1;
        while(j>=0)
        {
            nums1[tar--]=(i>=0) && (nums1[i]>nums2[j])?nums1[i--]:nums2[j--];
        }
                
    }
};

//Kth Smallest Element in a Sorted Matrix.python


class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        return sorted(ele for row in matrix for ele in row)[k-1]

//Diameter of Binary Tree.c


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 int max(int a ,int b)
 {
     return (a>b)?a:b;
 }
 
int diameterOfBinaryTreeUtil(struct TreeNode* root,int* height)
{
    
    int lh=0,rh=0,ld=0,rd=0;
    if(!root)
    {
        *height=0;
        return 0;
    }
    
    ld=diameterOfBinaryTreeUtil(root->left,&lh);
    rd=diameterOfBinaryTreeUtil(root->right,&rh);
    
    *height=(lh>rh)?lh+1:rh+1;
    
    return max(lh+rh,max(ld,rd));
    
    
}
int diameterOfBinaryTree(struct TreeNode* root) {
    int height=0;
    return diameterOfBinaryTreeUtil(root,&height);
    
}

//Counting Bits.cpp


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>dp(num+1,0);
        for(int i=1;i<=num;i++)
        {
                dp[i]=dp[i&i-1]+1;
        }
        return dp;
    }
};

//Next Permutation.cpp


class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        
        int n=arr.size(),i;
        if(n<2)
            return;
        for(i=n-1;i>0;i--)
        {
            if(arr[i]>arr[i-1])
                break;
        }
        if(i==0)
        {
            reverse(arr.begin(),arr.end());
            return;
        
        }int x=arr[i-1],small=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>x)
                small=j;
        }
        swap(arr[i-1],arr[small]);
            sort(arr.begin()+i,arr.end());
        for(int i : arr)
            cout<<i<<' ';
    }
};

//Maximal Square.cpp


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        if(matrix[0].size()==0)
            return 0;
        int m=matrix.size();
        int n=matrix[0].size(); int num=0;
        if(n==1)
            return matrix[0][0]-'0';
        vector<vector<int>> arr(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
            {arr[i][0]=matrix[i][0]-'0';
            num=max(num,arr[i][0]);}
        for(int i=0;i<n;i++)
            {arr[0][i]=matrix[0][i]-'0';
            num=max(num,arr[0][i]);}
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]=='1')
                    arr[i][j]=min(arr[i-1][j],min(arr[i][j-1],arr[i-1][j-1]))+1;
                num=max(num,arr[i][j]);
            }
        }
        return num*num;
    }
};

//Binary Tree Preorder Traversal.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preorderTraversalUtil(TreeNode* root,vector<int> &v)
    {
        if(!root)
           return;
        v.push_back(root->val);
        preorderTraversalUtil(root->left,v);
        preorderTraversalUtil(root->right,v);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> v;
        
        preorderTraversalUtil(root,v);
        
        return v;
    }
};

//Unique Paths II.cpp


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
      
        
        int m=obs.size(),n=obs[0].size();
        if(obs[0][0]!=0 || obs[m-1][n-1]!=0) return 0;
        int arr[m+1][n+1];//={{0}};
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                    arr[i][j]=0;
        
        arr[0][1]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(obs[i-1][j-1]==0)
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
        return arr[m][n];
    }   
    
};

//Ones and Zeroes.cpp


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
  int numZeroes, numOnes;

  for (auto &s : strs) {
    numZeroes = numOnes = 0;
    // count number of zeroes and ones in current string
    for (auto c : s) {
      if (c == '0')
	numZeroes++;
      else if (c == '1')
	numOnes++;
    }

    
    for (int i = m; i >= numZeroes; i--) {
	for (int j = n; j >= numOnes; j--) {
          memo[i][j] = max(memo[i][j], memo[i - numZeroes][j - numOnes] + 1);
	}
    }
  }
  return memo[m][n];
    }
};

//Symmetric Tree.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetricUtil(TreeNode* p,TreeNode* q)
    {
        if(p==NULL && q==NULL)
          return true;
        if(p && q)
          { return ((p->val == q->val) && isSymmetricUtil(p->left,q->right) && isSymmetricUtil(p->right,q->left));
          }
        return false;
        
    }
   
    bool isSymmetric(TreeNode* root) {
        if(!root)
         return true;
        
        return isSymmetricUtil(root,root);
        
    }
};

//Continuous Subarray Sum.cpp


class Solution {
public:
    bool func1(vector<int>& nums, int k,int l,int r)
    {
        if(r-l<2)
          return false;
        int sum=0;
        for(int i=l;i<r;i++)
           sum+=nums[i];
          if(sum==0 && k==0) return true;
        else
          if(sum!=0 && k==0) return false;
          else
          if(sum%k==0 ) return true;
        
        else
           return func1(nums,k,l+1,r) || func1(nums,k,l,r-1);
    }

    bool checkSubarraySum(vector<int>& nums, int k) {
       
        //return func1(nums,k,0,nums.size());

        set<int> s;
        int sum=0;int pre=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            
            int mod= (k==0)? sum: sum%k;
            
            if(s.count(mod)) return true;
            
            s.insert(pre);
            pre=mod;
            
        }
        return false;
    }
};

//Swap Nodes in Pairs.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head)
           return NULL;
        ListNode **ptr=&head,*a,*b;
        while((a=*ptr) && (b=a->next))
        {
            a->next=b->next;
            b->next=a;
            *ptr=b;
            ptr=&(a->next);
        }
        
        return head;
        
    }
};

//Simplify Path.python


class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = []
        for p in path.split("/"):
            if p == "..":
                if stack: stack.pop()
            elif p and p != '.': stack.append(p)
        return "/" + "/".join(stack)
        

//Single Number II.cpp


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one=0,two=0,three=0;
        for(int i: nums)
        {
            two|=one&i;
            one^=i;
            three=one&two;
            one^=three;
            two^=three;
        }
        return one;
    }
};

//Binary Tree Level Order Traversal II.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> V;
        if(!root)
           return V;
        q.push(root);
        int nodeCount=0;
        while(1)
        {
            nodeCount=q.size();
            vector<int> v;
            if(nodeCount==0)
               break;
            
            while(nodeCount>0)
            {
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);
                   
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);                    
                nodeCount--;
            }
            V.push_back(v);
        }
      reverse(V.begin(),V.end());
      return V;
    }
};

//Remove Duplicates from Sorted Array II.cpp


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
    }
};

//Kth Largest Element in an Array.python


class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        return nums[len(nums)-k]
        

//Find Mode in Binary Search Tree.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findModeUtil(TreeNode* root,map<int,int> &count,int &maxi){if(!root) return;count[root->val]+=1;maxi=(maxi>count[root->val])?maxi:count[root->val];findModeUtil(root->left,count,maxi);findModeUtil(root->right,count,maxi); }vector<int> findMode(TreeNode* root) {
        map<int,int> count;vector<int> v;int maxi=INT_MIN;findModeUtil(root,count,maxi);for(auto y : count){if(y.second==maxi) v.push_back(y.first);}return v;    
        
    }
};

//Remove Duplicates from Sorted List II.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       if(!head || !head->next)
           return head;
        ListNode *p1=head,*p2=head->next,*root=new ListNode(0),*ptr=root,*p;bool flag=true;
        while(p2)
        {
            if(p1->val!=p2->val)
            {
                ptr->next=p1;
                p1=p1->next;
                p2=p2->next;
                ptr=ptr->next;
                flag=true;
            }
            else
            {   p=p2;
                while(p1->val==p2->val && p2->next)
                {p=p2;p2=p2->next;}
                p1=p2;
                p2=(p2->next)?p2->next:NULL;
                flag=false;
            }
        }
        if(flag)ptr->next=p1;
        else
            if(p->val!=p1->val)
                ptr->next=p1;
             else   ptr->next=NULL;
        return root->next;
    }
};

//Binary Tree Paths.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void binaryTreePathsUtil(TreeNode* root,vector<string> &v,string s)
    {
        
        if(!root->left && !root->right)
        {
            v.push_back(s);
            return;
        }
        
        if(root->left)
        binaryTreePathsUtil(root->left,v,s+"->"+to_string(root->left->val));
        if(root->right)
        binaryTreePathsUtil(root->right,v,s+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> v;
        string s;
        if(root)
           binaryTreePathsUtil(root,v,to_string(root->val));
        return v;
        
    }
};

//Partition List.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *node1=new ListNode(0), *node2=new ListNode(0);
    ListNode *p1 = node1, *p2 = node2;
    while (head) {
        if (head->val < x)
            p1 = p1->next = head;
        else
            p2 = p2->next = head;
        head = head->next;
    }
    p2->next = NULL;
    p1->next = node2->next;
    return node1->next;
    }
};

//Same Tree.c


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    
      
    if(!p && !q)
       return true;
    if(p &&q)    
       return ( p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right) );
    else
       return false;
    
    
}

//Find Bottom Left Tree Value.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void findBottomLeftValueUtil(TreeNode* root,int *n,int level,int* maxlevel)
    {
        if(!root)
           return;
           
        if(*maxlevel<level)
        {
            *maxlevel=level;
            *n=root->val;
        }
        
        findBottomLeftValueUtil(root->left,n,level+1,maxlevel);
        findBottomLeftValueUtil(root->right,n,level+1,maxlevel);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        int n=0,level=1,maxlevel=INT_MIN;
        findBottomLeftValueUtil(root,&n,level,&maxlevel);
        return n;
    }
};

//Intersection of Two Arrays.python


class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        l=[]
        k=[]
        for i in nums1:
            for j in nums2:
                if(i==j):
                    l.append(i)
        #k = list(l for l, _ in itertools.groupby(l))
        k=list(set(l))
        return k
    

//Edit Distance.cpp


class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m=word1.length(),n=word2.length();
        if(m==0)
            return n;
        if(n==0)
            return m;
        int arr[m+1][n+1];//={{0}};
        for(int i=0;i<=n;i++)
            arr[0][i]=i;
        for(int i=0;i<=m;i++)
            arr[i][0]=i;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                if(word1[i-1]==word2[j-1])
                     arr[i][j]=arr[i-1][j-1];
                else
                    arr[i][j]=1+min(arr[i-1][j],min(arr[i][j-1],arr[i-1][j-1]));
        return arr[m][n];
        
    }
};

//Count Complete Tree Nodes.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int lheight(TreeNode* root)
    {
        if(!root)
          return 0;
          
        return lheight(root->left)+1;
    }
    int rheight(TreeNode* root)
    {
        if(!root)
          return 0;
          
        return rheight(root->right)+1;
    }
    int countNodes(TreeNode* root) {
        if(!root)
           return 0;
        int lh=lheight(root),rh=rheight(root);
        
        if(lh==rh) return (2<<(lh-1))-1;
        
        else
           return countNodes(root->left)+countNodes(root->right)+1;
        
    }
};

//Subarray Sum Equals K.cpp


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       
       int cur=0,count=0;
       map<int,int> result;
       result[0]++;
       for(int i=0;i<nums.size();i++)
       {
           cur+=nums[i];
           count+=result[cur-k];
           result[cur]++;
       }
        return count;
    }
};

//Sort List.java


public class Solution {
  
  public ListNode sortList(ListNode head) {
    if (head == null || head.next == null)
      return head;
        
    // step 1. cut the list to two halves
    ListNode prev = null, slow = head, fast = head;
    
    while (fast != null && fast.next != null) {
      prev = slow;
      slow = slow.next;
      fast = fast.next.next;
    }
    
    prev.next = null;
    
    // step 2. sort each half
    ListNode l1 = sortList(head);
    ListNode l2 = sortList(slow);
    
    // step 3. merge l1 and l2
    return merge(l1, l2);
  }
  
  ListNode merge(ListNode l1, ListNode l2) {
    ListNode l = new ListNode(0), p = l;
    //System.out.println(l1.val);
      //System.out.println(l2.val);
    while (l1 != null && l2 != null) {
      if (l1.val < l2.val) {
        p.next = l1;
        l1 = l1.next;
      } else {
        p.next = l2;
        l2 = l2.next;
      }
      p = p.next;
    }
    
    if (l1 != null)
      p.next = l1;
    
    if (l2 != null)
      p.next = l2;
    
    return l.next;
  }

}



//Invert Binary Tree.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   

    TreeNode* invertTree(TreeNode* root) {
        
if(root)
{      
   invertTree(root->left);
    invertTree(root->right);
    
    struct TreeNode* temp=root->left;
    root->left=root->right;
    root->right=temp;
}
return root;
    }
};

//Reverse Words in a String III.cpp


class Solution {
public:
    
    void reverse(string &s,int st,int en)
    {
        while(st<en)
        {
            char temp=s[st];
            s[st++]=s[en];
            s[en--]=temp;
        }
    }
    
    string reverseWords(string s) {
        
        int st=-1,i=0,n=s.length();
        
        while(i<n)
        {
            if((st==-1) && (s[i])!=' ' )
                st=i;
            if((st!=-1) && (s[i+1]==' ' || s[i+1]=='\0'))
            {
                reverse(s,st,i);
                st=-1;
            }
          i++;
        }
        return s;
    }
};

//Reverse String II.cpp


class Solution {
public:
    string reverseStr(string s, int k) {
        
        int i=0,n=s.length();
        while(i<n)
        {
            int j=min(i+k-1,n-1);
            int ni=j+k+1;
            while(i<j)
                swap(s[i++],s[j--]);
            i=ni;
                
        }
        return s;
    }
};

//Largest Rectangle in Histogram.cpp


class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        if(arr.size()==0)
            return 0;
        if(arr.size()==1)
            return arr[0];
        int n=arr.size();
        int tp=0,area=0,maxarea=INT_MIN,i=0;
	stack<int> s;
	while(i<n)
	{
		if(s.empty() || arr[s.top()]<=arr[i])
			s.push(i++);
		else
		{
			tp=s.top();
			s.pop();
			area= arr[tp]*(s.empty()?i:(i-s.top()-1));
			maxarea=max(maxarea,area);
		}
	}
	while(!s.empty())
	{
		    tp=s.top();
			s.pop();
			area= arr[tp]*(s.empty()?i:(i-s.top()-1));
			maxarea=max(maxarea,area);
	}
  return maxarea;
        
    }
};

//Linked List Cycle.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        struct ListNode *fptr=head;
        struct ListNode *sptr=head;
        while(sptr && fptr && fptr->next)
        {
            sptr=sptr->next;
            fptr=fptr->next->next;
            if(fptr==sptr)
            return true;
        }
        return false;
    }
};

//Reverse String.cpp


class Solution {
public:
    string reverseString(string s) {
       int j=s.length()-1;
        int i=0;
        while(i<=j)
        {
            swap(s[i++],s[j--]);
        }
        return s;
    }
};

//Largest Divisible Subset.cpp


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        vector<int> res;
        if(arr.size()==0)
            return res;
        int n=arr.size();
        vector<int> v(n,1);
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0 && v[i]<v[j]+1)
                    v[i]=v[j]+1;
            }
        }
        for(int i : v)
            cout<<i<<' ';
        int maxindex=0;
        for(int i=1;i<n;i++)
            maxindex=(v[i]>v[maxindex])?i:maxindex;
        int temp=arr[maxindex]; 
        int cur=v[maxindex];
        //res.push_back(arr[maxindex]);
        for(int i=maxindex;i>=0;i--)
        {
            if(temp%arr[i]==0 && cur==v[i])
            {
                res.push_back(arr[i]);
                temp=arr[i];
                cur--;
            }
        }
     reverse(res.begin(),res.end());
     return res;
    }
};

//Reverse Nodes in k-Group.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
		return NULL;
		if(k==1)
		  return head;
	ListNode *current=head,*prev=NULL,*next=NULL;
	int csize=0;
    while(current)
    {
        csize++;
        current=current->next;
    }
    current=head;
    int i=0;
    if(csize-k>=0)
    {
    while(current && i<k)
    {
    	next=current->next;
    	current->next=prev;
    	prev=current;
    	current=next;
    	i++;
    }
    
    if(next)
    	head->next=reverseKGroup(next,k);

    return prev;
    }
    else
    return head;
        
    }
};

//Find Largest Value in Each Tree Row.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<int> v;
        if(!root)
           return v;
        q.push(root);
        int nodeCount=0;
        while(1)
        {
            nodeCount=q.size();
            int maxValue=INT_MIN;
            if(nodeCount==0)
               break;
            
            while(nodeCount>0)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(maxValue<temp->val)
                   maxValue=temp->val;
                   
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);                    
                nodeCount--;
            }
            v.push_back(maxValue);
        }
        
        return v;
    }
};

//Number Complement.cpp


class Solution {
public:
    int findComplement(int num) {
        unsigned int mask=~0;
        while(num & mask)
            mask<<=1;
        return num^~mask;
    }
};

//Best Time to Buy and Sell Stock II.c


int max(int a,int b)
{
    return (a>b)?a:b;
}
int maxProfit(int* prices, int pricesSize) {
     int res=0;
     for(int i=1;i<pricesSize;i++)
         res+=max(prices[i]-prices[i-1],0);
     return res;
    
}

//Contains Duplicate.python


class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return len(nums)>len(set(nums))

//Longest Palindromic Subsequence.cpp


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        int L[n][n];
        memset(L,0,sizeof(L));
        for(int i=0;i<n;i++)
          L[i][i]=1;
        for(int cl=2;cl<=n;cl++)
        {
            for(int i=0;i<n-cl+1;i++)
            {
                int j=i+cl-1;
                
                if(s[i]==s[j] && cl==2)
                  L[i][j]=2;
                else
                  if(s[i]==s[j])
                   L[i][j]=L[i+1][j-1]+2;
                   else
                   L[i][j]=max(L[i+1][j],L[i][j-1]);
            }
        }
         return L[0][n-1] ;
    }
};

//Search Insert Position.cpp


class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
        
        int l=0,h=arr.size()-1;
        //if(l+1==h) return (arr[h]==x)?h:h+1;
        while(l<h)
        {
            int mid=(l+h)/2;
            
            if(arr[mid]==x)
                return mid;
                if(arr[mid]<x)
                    l=mid+1;
                else
                 h=mid-1;
        }
        return (arr[l]<x)?l+1:l;
        
    }
};

//Remove Duplicates from Sorted List.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        ListNode* root=new ListNode(0),*ptr=root,*p1=head,*p2=head->next,*p;bool flag=true;
        while(p2)
        {
            if(p1->val!=p2->val)
            {
                ptr->next=p1;
                ptr=ptr->next;
                p1=p1->next;
                p2=p2->next;
                flag=true;
            }
            else
            {
                ptr->next=p1;
                ptr=ptr->next;
                p=p2;
                while(p1->val==p2->val && p2->next)
                {p=p2;p2=p2->next;}
                p1=p2;
                p2=(p2->next)?p2->next:NULL;
                flag=false;
            }
        }
        if(flag)
            ptr->next=p1;
        else
          if(p->val!=p1->val)
                ptr->next=p1;
             else   ptr->next=NULL;
        
        return root->next;
    }
};

//Palindrome Number.cpp


class Solution {
public:
    bool isPalindrome(int x) {
        
         int y=0,z=x;
         while(x>0)
         {
             y=y*10+x%10;
             x=x/10;
         }
        return (z==y);
    }
};

//Rotate Image.python


class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        matrix[::]=zip(*matrix[::-1])
        
        

//Find Peak Element.cpp


class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if((i==0 || arr[i]>arr[i-1]) &&(i==n-1 || arr[i]>arr[i+1]))
                return i;
        }
        return 0;
    }
};

//Number of 1 Bits.cpp


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n)
        {
            n=n&(n-1);
            count++;
        }
    return count;
    }
};

//Reverse Vowels of a String.cpp


class Solution {
public:
    bool isVowel(char c)
    {
        return (c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u' || c=='A' ||c=='E' ||c=='I' ||c=='O' ||c=='U' );
    }
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        while(i<=j)
        {
            while(!isVowel(s[i]) && i<=j)i++;
            while(!isVowel(s[j]) && i<=j)j--;
            if(i<=j)
            {swap(s[i++],s[j--]);}
        }
     return s;       
    }
};

//Longest Substring Without Repeating Characters.cpp


class Solution {
int max=256;
public:
    int lengthOfLongestSubstring(string s) {
        
        int visited[max];
        memset(visited,-1,sizeof(visited));
        int curlen=1,maxlen=1,prev=0,i;
        int n=s.length();
        if(n==0) return 0;
        visited[s[0]]=0;
        for(int i=1;i<n;i++)
        {
            prev=visited[s[i]];
            
            if(prev==-1 || i-curlen>prev)
              curlen++;
            else
            {
                maxlen=(maxlen>curlen)?maxlen:curlen;
                curlen=i-prev;
            }
            visited[s[i]]=i;
        }
        maxlen=(maxlen>curlen)?maxlen:curlen;
        return maxlen;
        
    }
};

//Sort Colors.cpp


class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int l=0,m=0,h=nums.size()-1;
        while(m<=h)
        {
            switch(nums[m])
            {
                case 0:swap(nums[l++],nums[m++]);                    
                    break;
                case 1:
                     m++;
                    break;
                case 2:
                    swap(nums[m],nums[h--]);
                    break;
            }
        }
    }
};

//Unique Paths.cpp


class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <=0 || n <= 0) return 0;
        long long res = 1;
        for(int i = n; i < m+n-1 ; i++){
            res = res * i / (i- n + 1);
        }
        return (int)res;
        
    }
};

//Odd Even Linked List.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head)
           return NULL;
        if(!head->next)
           return head;
        ListNode *eHead,*oHead,*eptr,*optr,*ptr;
        optr=head;
        eHead=eptr=head->next;
        ptr=eptr->next;
        int i=1;
        while(ptr)
        {
            if(i&1)
            {
              optr->next=ptr;
              optr=optr->next;
            }
              
             else
               {
                   eptr->next=ptr;
                   eptr=eptr->next;
               }
            ptr=ptr->next;  
            i++;
            
        }
        optr->next=eHead;
        eptr->next=NULL;
        return head;
    }
};

//Next Greater Element III.cpp


class Solution {
public:
    int nextGreaterElement(int n) {
     
        string d=to_string(n);
        next_permutation(begin(d),end(d));
        auto r=stoll(d);
        return (r<=n || r>INT_MAX)?-1:r;
    }
};

//Serialize and Deserialize BST.python


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        def preorder(node):
            if node:
                vals.append(str(node.val))
                preorder(node.left)
                preorder(node.right)
        vals = []
        preorder(root)
        #print(vals)
        return ' '.join(vals)

    def deserialize(self, data):
        print(data)
        preorder = map(int, data.split())
        inorder = sorted(preorder)
        #print(preorder)
        #print(inorder)
        return self.buildTree(preorder, inorder)

    def buildTree(self, preorder, inorder):
        def build(stop):
            #print(inorder,preorder)
            if inorder and inorder[-1] != stop:
                print(preorder[0])
                root = TreeNode(preorder.pop())
                print(root.val)
                root.left = build(root.val)
                inorder.pop()
                root.right = build(stop)
                return root
        preorder.reverse()
        inorder.reverse()
        print(type(preorder))
        #print(preorder)
        #print(inorder)
        return build(None)
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))

//Climbing Stairs.cpp


class Solution {
public:
    int climbStairs(int n) {
        
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        //return climbStairs(n-1)+climbStairs(n-2);
    
        
        int dp[n+1];
        dp[0]=0;dp[1]=1;dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

//Repeated Substring Pattern.python


class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        ss=(s+s)[1:-1]
        return ss.find(s)!=-1
        
        
        

//Trapping Rain Water.cpp


class Solution {
public:
    int trap(vector<int>& height) {
      
      int l=0,r=height.size()-1,water=0,maxl=0,maxr=0;
      
      while(l<=r)
      {
          if(height[l]<=height[r])
          {
              if(height[l]>=maxl)
                maxl=height[l];
              else
                water+=maxl-height[l];
                
              l++;
          }
          else
          {
              if(height[r]>=maxr)
                maxr=height[r];
              else
                water+=maxr-height[r];
                
              r--;
          }
      }
      return water;
    }
};

//Search for a Range.cpp


class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        
        vector<int> ans(2,-1);
        if(arr.size()<1) return ans;
        int l=0,h=arr.size()-1;
        
        while(l<h)
        {
            int mid=(l+h)/2;
            if(arr[mid]<x)
                l=mid+1;
            else
                h=mid;
        }
        if(arr[l]==x) ans[0]=l;
        
        else return ans;
        h=arr.size()-1;
        while(l<h)
        {
            int mid=(l+h)/2+1;
            if(arr[mid]>x)
                h=mid-1;
            else
                l=mid;
            
        }
        ans[1]=h;
        return ans;
    }
};

//Longest Palindromic Substring.cpp


class Solution {
public:
    string longestPalindrome(string s) {
        string ns;int n=s.length();
        int st=0,ed=1;
        for(int i=0;i<n;)
        {
            int j=i,k=i;
            while(k<n-1 && s[k+1]==s[k]) ++k;
            i=k+1;
            while(k<n-1 && j>0 && s[k+1]==s[j-1]) {k++;j--;}
            int len=k-j+1;
            if(len>ed){st=j;ed=len;};
        }
        return s.substr(st,ed);
    }
};

//Find Minimum in Rotated Sorted Array.c


int findMinEle(int* arr,int l,int h)
{
    if(l>h) return -1;
    while(l<h)
    {
        if(arr[l]<arr[h])
            return arr[l];
        int mid=(l+h)/2;
        if(arr[mid]>=arr[l])
             l=mid+1;
        else
             h=mid;
        
    }
    return  arr[l];
}

int findMin(int* nums, int numsSize) {
    
    return findMinEle(nums,0,numsSize-1);
    
}

//Add Strings.cpp


class Solution {
public:
    string addStrings(string num1, string num2) {
      int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    while(i>=0 || j>=0 || carry){
        long sum = 0;
        if(i >= 0){sum += (num1[i] - '0');i--;}
        if(j >= 0){sum += (num2[j] - '0');j--;}
        sum += carry; 
        carry = sum / 10;
        sum = sum % 10;
        res =  to_string(sum) + res ;
    }
    //reverse(res.begin(), res.end());
    return res;
    }
};

//House Robber.cpp


class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        if(n==0) return 0;
        if(n==1) return arr[0];
        if(n==2) return (arr[0]>arr[1])?arr[0]:arr[1];
        int dp[n]={0};
        dp[0]=arr[0];dp[1]=(arr[0]>arr[1])?arr[0]:arr[1];
        
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};

//Two Sum II - Input array is sorted.cpp


class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> v;
        int s=0,e=arr.size()-1;
        while(s<e)
        {
            int sum=arr[s]+arr[e];
            if(sum==target)
            {
                v.push_back(s+1);
                v.push_back(e+1);
                return v;
            }
            else
              if(sum>target)
                e--;
                else
                  s++;
        }
        return v;
    }
};

//Path Sum.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int hasSum(TreeNode* root,int cursum,int sum)
    {
        if(!root)
            return 0;
        cursum+=root->val;
        if(!root->left && !root->right && cursum==sum)
            return 1;
        return hasSum(root->left,cursum,sum)||hasSum(root->right,cursum,sum);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return hasSum(root,0,sum);
        
    }
};

//Roman to Integer.cpp


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> maps={
                                        {'I',1},
                                        {'V',5},
                                        {'X',10},
                                        {'L',50},
                                        {'C',100},
                                        {'D',500},
                                        {'M',1000}
                                        
                                      };
                                      
        int sum=maps[s.back()];
        for(int i=s.size()-2;i>=0;--i)
        {
            if(maps[s[i]]<maps[s[i+1]])
            {
                sum-=maps[s[i]];
            }
            else
            {
                sum+=maps[s[i]];
            }
        }
        return sum;
    }
};

//Search in Rotated Sorted Array II.cpp


class Solution {
public:
    bool search(vector<int>& nums, int target) {
       if(nums.size()<1) return false;
        if(nums.size()==1) return (nums[0]==target)?true:false;
      int l = 0, h = nums.size() - 1;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] < nums[l]) {
                if (nums[mid] < target && nums[h] >= target) l = mid + 1;
                else h = mid - 1;
            } else if (nums[mid] > nums[l]) {
                if (nums[mid] > target && nums[l] <= target) h = mid - 1;
                else l = mid + 1;
            } else {////nums[mid] == nums[l]
                l++;
            }
        }
        return nums[l] == target;
    }
};

//Power of Two.cpp


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
     return !(n&n-1);   
    }
};

//Search in Rotated Sorted Array.c


int searchEle(int* arr, int l,int h, int target)
{
    if(l>h) return -1;
    
    int mid=(l+h)/2;
    
    if(target==arr[mid])
        return mid;
        
    if(arr[l]<=arr[mid])
    {
        if(target<=arr[mid] && target>=arr[l])
           return searchEle(arr,l,mid-1,target);
        else
           return searchEle(arr,mid+1,h,target);
    }
    else
    {
        if(target<=arr[h] && target>=arr[mid])
             return searchEle(arr,mid+1,h,target);
        else
            return searchEle(arr,l,mid-1,target);
    }
    
}
int search(int* nums, int numsSize, int target) {
    
    return searchEle(nums,0,numsSize-1,target);
    
}

//Move Zeroes.cpp


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int k=0;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]!=0)
           {
               nums[k]=nums[i];k++;
           }
           
       }
       for(;k<nums.size();k++)
        {
            nums[k]=0;
        }
    }
};

//Merge Two Sorted Lists.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
            if(!l1)
               return l2;
            else
               if(!l2)
                  return l1;
            ListNode* result;
            if(l1->val<l2->val)
                {
                    result=l1;
                    result->next=mergeTwoLists(l1->next,l2);   
                }
            else
                {
                    result=l2;
                    result->next=mergeTwoLists(l1,l2->next);   
                }
        return result;
    }
};

//Next Greater Element I.cpp


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> v;
        stack<int> s;
        unordered_map<int,int> m;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!s.empty() && nums[i]>=s.top())
              s.pop();
            if(!s.empty())
              m[nums[i]]=s.top();
            else
            m[nums[i]]=-1;
            
            s.push(nums[i]);
        }
       
        for(int i : findNums) v.push_back(m.count(i)?m[i]:-1);
        return v;
    }
};

//Count Primes.cpp


class Solution {
public:
    int countPrimes(int n) {
      if (n<=2) return 0;
	vector<bool> passed(n, false);
	int sum = 1;
	int upper = sqrt(n);
	for (int i=3; i<n; i+=2) {
		if (!passed[i]) {
			sum++;
			//avoid overflow
			if (i>upper) continue;
			for (int j=i*i; j<n; j+=i) {
				passed[j] = true;
			}
		}
	}
	return sum;   
    }
};

//Integer to English Words.cpp


class Solution {
public:

     string digits[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string int2string(int n) {
        if (n >= 1000000000) {
            return int2string(n / 1000000000) + " Billion" + int2string(n % 1000000000);
        } else if (n >= 1000000) {
            return int2string(n / 1000000) + " Million" + int2string(n % 1000000);
        } else if (n >= 1000) {
            return int2string(n / 1000) + " Thousand" + int2string(n % 1000);
        } else if (n >= 100) {
            return int2string(n / 100) + " Hundred" + int2string(n % 100);
        } else if (n >= 20) {
            return  " " + tens[n / 10] + int2string(n % 10);
        } else if (n >= 1) {
            return " " + digits[n];
        } else {
            return "";
        }
    }

    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        } else {
            string ret = int2string(num);
            return ret.substr(1, ret.length() - 1);
        }
    }
};

//Unique Binary Search Trees.cpp


class Solution {
public:
    unsigned long int binomialCoeff(int n, int k)
{
     unsigned long int res = 1;
  
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
  
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
  
    return res;
}
    int numTrees(int n) {
         unsigned long int c = binomialCoeff(2*n, n);
  
    // return 2nCn/(n+1)
    return c/(n+1);
        
    }
};

//Integer to Roman.cpp


class Solution {
public:
    string intToRoman(int num) {
    string M[] = {"", "M", "MM", "MMM"};
    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100]+ X[(num%100)/10] + I[num%10];
    }
};

//Coin Change.cpp


class Solution {
public:
    int coinChange(vector<int>& coins, int v) {
     
        if(v==0)
            return 0;
        int MAX=v+1;
        vector<int> value(v+1,MAX);
       // for (int i : value)
         //   cout<<i<<' ';
        value[0]=0;
        int n=coins.size();
        
        for(int i=1;i<=v;i++)
        {
            //int sub=INT_MAX;
            for(int j=0;j<n;j++)
            {
                if(coins[j]<=i)
                    value[i]=min(value[i],value[i-coins[j]]+1);
            }
            //value[i]=(sub!=INT_MAX)?sub+1:0;
        }
        //for (int i : value)
          //  cout<<i<<' ';
        return (value[v]>v)?-1:value[v];
    }
};

//Palindromic Substrings.cpp


class Solution {
public:
    int countSubstrings(string s) {
          if(s.length()==0)
              return 0;
          int n=s.length();
       int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=findlen(s,i,i,n);
            cnt+=findlen(s,i,i+1,n);
        }
        return cnt;
    }
    int findlen(string s,int l,int r,int n)
    {    int cnt=0;
        while(l>=0 && r<n && s[l--]==s[r++])cnt++;
        return cnt;
    }
};

//Container With Most Water.cpp


class Solution {
public:
    int maxArea(vector<int>& arr) {
        int water=0,l=0,r=arr.size()-1;
        while(l<r)
        {
            int h=min(arr[l],arr[r]);
            water=max(water,(r-l)*h);
            while(arr[l]<=h && l<r) l++;
            while(arr[r]<=h && l<r) r--;
        }
        return water;
    }
};

//Water and Jug Problem.cpp


class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    bool canMeasureWater(int x, int y, int z) {
     
        if((x+y)<z)
            return false;
        if(x==z || y==z || x+y==z)
            return true;
        return z%gcd(x,y)==0;
    }
};

//Maximum Depth of Binary Tree.c


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    
    if(!root)
       return 0;
       
    int lh=0,rh=0;
    
    lh=maxDepth(root->left);
    rh=maxDepth(root->right);
    
    return (lh>rh)?lh+1:rh+1;
}

//Rotate List.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
       if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};

//Power of Three.cpp


class Solution {
public:
    bool isPowerOfThree(int n) {
      return (n>0 && (1162261467%n)==0);
    }
};

//Add Two Numbers.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p;
        ListNode *res=NULL;
        int s=0,c=0;
        while(l1 || l2)
        {   s=0;
            int val1=0,val2=0;
            val1=(l1)?l1->val:0;
            val2=(l2)?l2->val:0;
            s=val1+val2+c;
            c=(s>=10)?1:0;
            s%=10;
            cout<<val1<<val2<<s<<c<<endl;
            if(!res)
            {
                res=new ListNode(s);
                p=res;
            }
            else
            {
                ListNode* temp=new ListNode(s);
                p->next=temp;
                p=p->next;
            }
            l1=(l1)?l1->next:NULL;
            l2=(l2)?l2->next:NULL;
        }
        if(c>0)
        {
            ListNode* temp=new ListNode(c);
                p->next=temp;
                p=p->next;
        }            
        return res;
    }
};

//Construct String from Binary Tree.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void trees(TreeNode* t,string &s)
    {
        if(!t)
        {
           // s+=")";
             return;
        }   
        s+=to_string(t->val)+"(";
        trees(t->left,s);
        s+=")(";
        trees(t->right,s);
        s+=")";
        return;     
    }
    
    string tree2str(TreeNode* t) {
        
 if (!t) return "";
        string s = to_string(t->val);

        if (t->left) {
            s += "(" + tree2str(t->left) + ")";
        }
        else if (t->right) {
            s += "()";
        }
        
        if (t->right) {
            s += "(" + tree2str(t->right) + ")";
        }

        return s;
        
    }
};

//Add Two Numbers II.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     
        ListNode *ans=new ListNode(0),*temp;int i=0,sum=0;
        stack<int> s1,s2;
        
        while(l1)
            {s1.push(l1->val);l1=l1->next;}
        
        while(l2)
            {s2.push(l2->val);l2=l2->next;}
        int c=0;
        while(!s1.empty() || !s2.empty())
        {   int n1=0,n2=0;
            
         if(!s1.empty())
                {n1=s1.top();s1.pop();}

            if(!s2.empty())
                {n2=s2.top();s2.pop();}
        
         sum+=(n1+n2);
         
         ans->val=(sum%10);
             temp=new ListNode(sum/=10);
             temp->next=ans;
             ans=temp;
        }
        
     return (ans->val)?ans:ans->next;   
    }
};

//Longest Increasing Subsequence.c


int max(int a,int b)
{
    return (a>b)?a:b;
}

int lengthOfLIS(int* nums, int n) {
      const int size=n;
      if(size==0) return 0;
      int arr[size];
        for(int i=0;i<n;i++)
        arr[i]=1;
        int len=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && arr[i]<arr[j]+1)
                    arr[i]=arr[j]+1;
            }
        }
        for(int i=0 ;i<n;i++)
           len=max(len,arr[i]);
        
        return len;
    
}

//Reverse Bits.cpp


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int res=0;
        for(int i=0;i<32;i++)
            res=(res<<1)+((n>>i)&1);
        return res;
    }
};

//Subsets.python


class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        r=[]
        for i in range(0,len(nums)+1):
            r+=([list(x) for x in itertools.combinations(nums,i)])
        return r

//Reverse Linked List.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //if (!head) return head;
        //ListNode* first = head;
        struct ListNode* rest;//=first->next;
       if(head==NULL) return NULL;
        if (head->next==NULL) return head;
        rest=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;
 
        
    }
};

//Reorder List.cpp


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *&head)
    {
         if (!head || !head->next) return;
    
    // find the middle node: O(n)
    ListNode *p1 = head, *p2 = head->next;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    
    // cut from the middle and reverse the second half: O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;
    
    //p2 = head2->next;
   /* head2->next = NULL;
    while (p2) {
        p1 = p2->next;
        p2->next = head2;
        head2 = p2;
        p2 = p1;
    }*/
        ListNode *cur=head2,*prev=NULL,*next=NULL;
        while(cur)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        p2=prev;
    
    // merge two lists: O(n)
    for (p1 = head, p2 = prev; p1; ) {
        auto t = p1->next;
        p1 = p1->next = p2;
        p2 = t;
    }
     //   return head;
    }
};

//Minimum Depth of Binary Tree.c


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void minDepthUtil(struct TreeNode* root,int *min,int level)
{
    if(!root)
       return ;
    if(!root->left && !root->right)
    {
        if(*min>level)
           *min=level;
    }
    
    minDepthUtil(root->left,min,level+1);
    minDepthUtil(root->right,min,level+1);
    
}
 
int minDepth(struct TreeNode* root) {
    
    int min=INT_MAX,level=0;
    if(root)
        {minDepthUtil(root,&min,level);
        return min+1;}
    else
        return 0;
}

//Jump Game.cpp


class Solution {
public:
    int mini(int a,int b)
    {
        return (a<b)?a:b;
    }
    bool canJump(vector<int>& nums) {
     
     int jumps[nums.size()];
     memset(jumps,INT_MAX,sizeof(jumps));
     jumps[0]=0;
     for(int i=1;i<nums.size();i++)
     {   jumps[i] = INT_MAX;
         for(int j=0;j<i;j++)
         {
             if(i<=j+nums[j] && jumps[j]!=INT_MAX)
                {jumps[i]=min(jumps[i],jumps[j]+1);break;}
         }
     }
     return (jumps[nums.size()-1]==INT_MAX)?false:true;    
        
    }
};

//Binary Tree Level Order Traversal.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         
        queue<TreeNode*> q;
        vector<vector<int>> V;
        if(!root)
           return V;
        q.push(root);
        int nodeCount=0;
        while(1)
        {
            nodeCount=q.size();
            vector<int> v;
            if(nodeCount==0)
               break;
            
            while(nodeCount>0)
            {
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);
                   
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);                    
                nodeCount--;
            }
            V.push_back(v);
        }
      return V;  
    }
};

//Path Sum II.cpp


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void hasSum(TreeNode* root,int cursum,int sum,vector<int> &p,vector<vector<int>> &P)
    {
        if(!root)
            return;
        cursum+=root->val;
        p.push_back(root->val);
        if(!root->left && !root->right && cursum==sum)
              P.push_back(p);
        hasSum(root->left,cursum,sum,p,P);
        hasSum(root->right,cursum,sum,p,P);
        p.pop_back();
            
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> P;
        vector<int> p;
        hasSum(root,0,sum,p,P);
        return P;        
    }
};

//Reverse Integer.cpp


class Solution {
public:
    int reverse(int x) {
        long long int rev=0;
        while(x)
        {
            rev=(rev*10)+(x%10);
            x=x/10;
        }
        //rev=(neg==1)?rev*-1:rev;
        return (rev>INT_MAX || rev<INT_MIN)?0:(int)rev;
    }
};

//Rotate Array.cpp


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        if(nums.size()==0 || k<=0)
            return;
        int n=nums.size();
        vector<int> arr(nums);
        for(int i=0;i<n;i++)
            nums[(i+k)%n]=arr[i];
        
    }
};

//Island Perimeter.cpp


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
     
        if(grid.size()==0)
            return 0;
        if(grid[0].size()==0)
            return 0;
        int m=grid.size(),n=grid[0].size(),cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                 
                {cnt+=checkpts(i,j,m,n,grid);}
                    
            }
        }
        return cnt;
    }
    int checkpts(int i,int j,int m,int n,vector<vector<int>> grid)
    {
        int cnt=0;
        if(i-1<0)
            cnt++;
        else
            if(grid[i-1][j]==0)
                cnt++;
        if(i+1>=m)
            cnt++;
        else
            if(grid[i+1][j]==0)
                cnt++;
        
        
        if(j-1<0)
            cnt++;
        else
            if(grid[i][j-1]==0)
                cnt++;
         if(j+1>=n)
            cnt++;
        else
            if(grid[i][j+1]==0)
                cnt++;
        return cnt;
    }
};

//Dungeon Game.cpp


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int M = dungeon.size();
        int N = dungeon[0].size();
        // hp[i][j] represents the min hp needed at position (i, j)
        // Add dummy row and column at bottom and right side
        vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
        hp[M][N - 1] = 1;
        hp[M - 1][N] = 1;
        for (int i = M - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
                hp[i][j] = need <= 0 ? 1 : need;
            }
        }
        return hp[0][0];
        }
};

//Maximum Subarray.cpp


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        
        int cursum=nums[0],maxsum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            cursum=max(nums[i],cursum+nums[i]);
            maxsum=max(maxsum,cursum);
        }
        return maxsum;
        
    }
};

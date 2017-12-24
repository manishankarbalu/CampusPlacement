
//Maximum profit by buying and selling a share at most twice

int maxProfit2times(int price[],int size)
{
	int profit[size];
	for(int i=0;i<size;i++)
	{
		profit[i]=0;
	}
	int maxPro=price[n-1];
	for(int i=size-2;i>=0;i--)
	{
		if(price[i]>maxPro)
			maxPro=price[i];

		profit[i]=max(profit[i+1],maxPro-price[i]);
	}
	int mini=price[0];
	for(int i=1;i<size;i++)
	{
		if(price[i]<mini)
			mini=price[i];

		profit[i]=max(profit[i-1],profit[i]+(price[i]-mini));
	}
	return profit[n-1];
}
//this can be also done by smart approach
int maxProfit2times(int prices[], int n)
{
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


// maximum profit by buying and selling one time
   //not (dp)

int maxProOneTime(int arr[],int size)
{
	int minEle=a[0],maxDiff=arr[1]-arr[0];
	for(int i=1;i<size;i++)
	{
		if(arr[i]-minEle>maxDiff)
			maxDiff=arr[i]-minEle;
		if(arr[i]<minEle)
			minEle=arr[i]
	}
	return maxDiff;
}

//find the max length of LIS (longest increasing subsequence)

int maxLengthOfLIS(int arr[],int size)
{
	int lis[size];
	for(int i=0;i<size;i++)
		lis[i]=1;
	for(int i=1;i<size;i++)
	{
		for(int j=0;j<i;j++)
			if(arr[i]>arr[j] && lis[i]<lis[j]+1)
				lis[i]=lis[j]+1;
	}
	int maxi=INT_MIN;
	for(int i=0;i<size;i++)
		maxi=max(maxi,lis[i]);
	return maxi;
}

// Sum of largest Increasing Subsequence

int sumOfLIS(int arr[],int size)
{
	int slis[size];
	for(int i=0;i<size;i++)
		slis[i]=arr[i];
	for(int i=1;i<size;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && slis[i]<slis[j]+arr[i])
				slis[i]=slis[j]+arr[i];
		}
	}
	int maxi=INT_MIN;
	for(int i=0;i<size;i++)
	{
		maxi=max(maxi,slis[i]);
	}
	return maxi;
}

//check if we can reach the end by jump (greedy) 

bool canJump(int A[], int n) {
    int i = 0;
    for (int reach = 0; i < n && i <= reach; ++i)
        reach = max(i + A[i], reach);
    return i == n;
}

// Minimum jumps needed to reach end

int minJumps(int arr[],int size)
{
	int jumps[size];
	jumps[size-1]=0;
	for(int i=size-2;i>=0;i--)
	{
		int min=INT_MAX;
		for(int j=i+1;j<size && j<arr[i]+i;j++)
		{
			if(min>jumps[j])
				min=jumps[j];
		}
		if(min!=INT_MAX)
			jumps[i]=min+1;
		else
			jumps[i]=min;
	}
}

//smart method for min jumps

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


//tapping rain water problem 

int findWaterSaved(int arr[],int size)
{
	int left[size];
	int right[size];
	left[0]=arr[0];
	right[size-1]=arr[size-1];
	int water=0;
	for(int i=1;i<size;i++)
		left[i]=max(left[i-1],arr[i]);
	for(int i=size-2;i>=0;i--)
		right[i]=max(right[i+1],arr[i]);
	for (int i = 0; i < n; i++)
      water += min(left[i],right[i]) - arr[i];
return water;
}

//O(n) O(1) solution

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
//fibbonacci
int MAX=100;
f[MAX];
int fibbo(int n)
{
	if(n==0)
		return 0;
	if(n==1 || n==2)
		return (f[n]=1);
	if(f[n])
		return f[n];
	int k=(n&1)?(n+1)/2:n/2;

	f[n]=(n&1)?(fibbo(k)*fibbo(K)+fibbo(k-1)*fibbo(k-1))
	          :fibbo(k)*(2*fibbo(k-1)+fibbo(k));
	
	return f[n];
}

//lcs

int lcs(string x,string y)
{
	int m=x.length();
	int n=y.length();

	L[m+1][n+1];

	for(int i=0;i<=m;i++)
	{
		for (int j = 0; i <= n; j++)
		{
			if(i==0 || j==0)
				L[i][j]=0;
			else
				if(x[i-1]==y[j-1])
					L[i][j]=L[i-1][j-1]+1;
				else
					L[i][j]=max(L[i-1][j],L[i][j-1])
		}
	}
	return L[m][n];
}

//nth ugly number

int getUglyNumber(int n)
{
	int ugly[n];
	ugly[0]=1;
	int nextUgly,i,i2,i3,i5;
	i=i2=i3=i5=0;
	int nextMulti2=2,nextMulti3=3,nextMulti5=5;
	for (int i=1;i<n;i++)
	{
		nextUgly=min(nextMulti2,nextMulti3,nextMulti5);
		ugly[i]=nextUgly;
		if(nextUgly==nextMulti2)
		{
			i2++;
			nextMulti2=ugly[i2]*2;
		}
		if(nextUgly==nextMulti3)
		{
		    i3++;
			nextMulti2=ugly[i3]*3;					
		}
		if(nextUgly==nextMulti5)
		{
			i5++;
			nextMulti2=ugly[i5]*5;			
		}
	}
	return nextUgly;
}

//Coin Change

int coinChange(S[],int size,int value)
{
	int temp[value+1];
	temp[0]=1;
	for(int i=1;i<value+1;i++)
		temp[i]=0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = S[i]; j <= value; ++j)
		{
			temp[j]+=temp[j-S[i]];
		}
	}
	return temp[value];
}

//equal sum partition

bool equalSumPartition(int arr[],int n)
{
	int sum,diff;
	for (int i = 0; i < n; ++i)
	{
		sum+=arr[i];
	}
    bool P[sum/2+1][n+1];

    for (int i = 1; i <= sum/2; ++i)
    {
    	P[i][0]=false;
    }
    for (int i = 1; i <= n; ++i)
    {
    	P[0][i]=true;
    }

    for (int i = 1; i <= sum/2; ++i)
    {
    	for (int j = 1; j <= n; ++j)
    	{
    		P[i][j]=P[i][j-1];
    		if(i>=arr[j-1])
    			P[i][j] |= p[i-arr[j-1]][j-1]
    	}
    }
return P[sum/2][n];
}

//min difference partitioning

int minDiffPartition(int arr[],int n)
{
	int sum=0,diff=INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		sum+=arr[i];
	}
    bool P[n+1][sum+1];

    for (int i = 0; i <= sum; ++i)
    {
    	P[0][i]=false;
    }
    for (int i = 1; i <= n; ++i)
    {
    	P[i][0]=true;
    }
    for (int i = 1; i <= n; ++i)
    {
    	for (int j = 1; j <= sum; ++j)
    	{
    		P[i][j]=P[i-1][j];
    		if(j>=arr[i-1])
    			P[i][j]|=P[i-1][j-arr[i-1]];
    	}
    }

for (int i = sum/2; i >= 0; ++i)
{
	if (P[n][j]==true)
	{
		diff=sum-2*j;
		break;
	}
}
return diff;
}

//knapSack problem

int knapSack(int arr[],int n,int w)
{
	int size=0;
	std::vector<int> val;
	std::vector<int> wt;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=-1)
		{
			val.push_back(arr[i]);
			wt.push_back(i+1);
			size++;
		}
	}
	n=size;
	int minCost[n+1][w+1];
	for(int i=0;i<=n;i++)
	{
		for (int j = 0; j <= w; ++j)
		{
			if(i==0)
				minCost[i][j]=INF;
			else
				minCost[i][j]=0;
		}
		
	}
	for (int i = 1; i <=n; ++i)
	{
		for (int j = 1; i <=w ; ++j)
		{
			if(wt[i-1]>j)
				minCost[i][j]=minCost[i-1][j];
			else
				minCost[i][j]=min( minCost[i-1][j]
					         ,minCost[i][j-wt[i-1]]+val[i-1])
		}
	}
return (minCost[n][w]==INF)?-1:minCost[n][w];
}

//rotate by 90 degree

void rotateMatrix(int a[][N])
{
	for(int x=0;x<N/2;x++)
	{
		for (int y = x; y < N-x-1; y++)
		{
			int temp=a[x][y];

			//move btmlft to lftup
			a[x][y]=a[N-y-1][x];

			//move btmrite to btmlft
			a[N-y-1][x]=a[N-x-1][N-y-1];

			//move toprit to btmrit
			a[N-x-1][N-y-1]=a[y][N-x-1];

			//move toplft to toprite
			a[y][N-x-1]=temp;
		}
	}
}

//pairing friends problem

int numberOfWaysSingleOrPaired(int arr[],int size)
{
	int dp[size+1];

	for(int i=0;i<=n;i++)
	{
		if(i<=2)
			dp[i]=i;
		else
			dp[i]=dp[i-1]+(i-1)*dp[i-2];
	}
	return dp[size];
}

//prince save princess (dungeon problem)

int minEnergyNeeded(int arr[],int m,int n)
{
	int dp[m+1][n+1]=INT_MAX;
	dp[m][n-1]=1;
	dp[m-1][n]=1;
	for(int i=m-1;i>=0;i--)
	{
		for (int j = n-1; j>=0; j--)
		{
			int need=min(dp[i+1][j],dp[i][j+1])-arr[i][j];
            dp[i][j]=(need>0)?need:1;
		}
	}
	return dp[0][0];
}

//cutting a rod problem

int maxProfitRod(int arr[],int n)
{
	int dp[n+1]={0};
	for(int i=1;i<=n;i++)
	{
		int maxi=INT_MIN;
		for(int j=0;j<i;j++)
		{
			maxi=max(maxi,arr[j]+dp[i-j-1]);
		}
		dp[i]=maxi;
	}
	return dp[n];
}


//infinite supply of coin minimum change needed to get a value

int minNoOFCoins(int arr[],int n,int v)
{
	int dp[v+1]={INT_MAX};
	dp[0]=0;
    //dp[1]=0;
	for(int i=1;i<=v;i++)
	{  // int need=0;
		for(int j=0;j<n;j++)
		{
			if(i>=arr[j])
			{
			int sub_res=dp[i-arr[j]];
			if(sub_res!=INT_MAX && sub_res+1<dp[i])
			     dp[i]=sub_res+1;	
			}	
		}
	}
	return dp[v];
}

//Input: "aaa"
//Output: 6
//Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

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


//histogram problem
int maximumHistogram(int arr[],int n)
{
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


//maximum rectangel area in matrix
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        if(matrix[0].size()==0)
            return 0;
        int maxi=INT_MIN;
        vector<int> arr(matrix[0].size(),0);
        for(int k : arr)
            cout<<k<<' ';
        cout<<endl;
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
            for(int k : arr)
                cout<<k<<' ';
            cout<<endl;
            int x=largestRectangleArea(arr);
            cout<<x<<endl;
         maxi=max(maxi,x);   
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

//predict the winner pick element from any of ends

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

//given a string 123 return sum of all its substrig 1+12+23+123=164

int substringSum(string s)
{
	int l=s.length();
	temp=s[0]-'0';
	out=s[0]-'0';
	for(int i=1;i<l;i++)
	{
		temp=temp*10+(i+1)*(s[i]-'0');
		out+=temp;
	}
	return out;
}

//cutting a rod

int maxValue1(vector<int> price)
{
        int maxi[price.size()+1]={0};
        for(int i=1; i <= price.size(); i++){
            maxi[i] = price[i-1];
        }
        for(int i=1 ; i <= price.size(); i++){
            for(int j=1; j < i ; j++){
                maxi[i] = max(maxi[i], maxi[i-j] + maxi[j]);
            }
        }
        for(int i: maxi)
           cout<<i<<' ';
        cout<<endl;
        return maxi[price.size()];
}

//palindromic subsequence and palindromic partitioning

int palindromeSubsequence(string s)
{
	int n=s.length();
	int a[n][n]={0};
	for(int i=0;i<n;i++)
	     a[i][i]=1;
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			
			if(s[i]==s[j] && l==2)
			     a[i][j]=2;
			else
			   if(s[i]==s[j])
			       a[i][j]=2+a[i+1][j-1];
			else
			   a[i][j]=max(a[i+1][j],a[i][j-1]);
			
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return a[0][n-1];
}

int palindromePartition(string s)
{
	int n=s.length();
	int a[n][n]={0};
	bool b[n][n]={false};
	for(int i=0;i<n;i++)
	    { a[i][i]=0;b[i][i]=true;}
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j=i+l-1;
			
			if(l==2)
			     b[i][j]=(s[i]==s[j]);
			else
			     b[i][j]=(s[i]==s[j] && a[i+1][j-1]);
			     
			if(b[i][j])
			    a[i][j]=0;
			else
			{
				a[i][j]=INT_MAX;
				for(int k=i;k<j;k++)
				    a[i][j]=min(a[i][j],a[i][k]+a[k+1][j]+1);
			}
			
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return a[0][n-1];
	
}
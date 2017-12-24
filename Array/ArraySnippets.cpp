#include<bits/stdc++.h>
using namespace std;

//reverse an array

void reverseArray(int arr[])
{
int start=0;
int end=(sizeof(arr)/sizeof(arr[0]))-1;
 	while(start<end)
 	{
 		int temp=arr[start];
 		arr[start]=arr[end];
 		arr[end]=temp;
 		start++;
 		end--;
 	}
}

//find the maximum occuring element

int findMaxOccuring(char arr[])
{
	int size=sizeof(arr)/sizeof(arr[0]);
	int maxindex=0,count=1;

	for(int i=1;i<size;i++)
	{
       if(arr[maxindex]==arr[i])
       	count++;
       else
       	count--;
       if(count==0)
       {
       	maxindex=i;
       	count=1;
       }
	}
	return a[max_index]  
}

//find the odd time of occuring element

int getOddOccuringElement(int arr)
{
	int size=sizeof(arr)/sizeof(arr[0]);
	int result=0;
	for(int i=0;i<size;i++)
	{
		result=result^arr[i];
	}
  return result;
}

//find the maximum subarray sum

int maxSubarraySum(int arr[])
{
	int size=sizeof(arr)/sizeof(arr[0]);
	int curr_max=arr[0],tot_max=arr[0];
	for(int i=1;i<size;i++)
	{
		curr_max=max(arr[i],curr_max+arr[i]);
		tot_max=max(tot_max,curr_max);
	}
	return tot_max;
}

//find the starting and ending index of max subarray

void indexOfMaxSubarraySum(int a[],int &start,int &end)
{
	int size=sizeof(arr)/sizeof(arr[0]);
    int max_ending=0,max_sofar=INT_MIN;
    for(int i=0;i<size;i++)
    {
    	max_ending+=arr[i];
    	if(max_sofar<max_ending)
    	{
    		max_sofar=max_ending;
    		start=s;
    		end=i;
    	}
    	if(max_ending<0)
    	{
    		max_ending=0;
    		s=i+1;
    	}
    }
}

//search element in sorted & pivoted array

int searchElementInSortedPivotedArray(int arr[]int l,int h,int k)
{
	if(l>h) return -1;

    int mid=l+h/2;

    if(k==arr[mid])
    	return mid;
    if(arr[l]<=arr[mid])
    {
    	if(k<arr=[mid] && k>=arr[l])
    		return searchElementInSortedPivotedArray(arr,l,mid-1,k);
    	else
    	    return searchElementInSortedPivotedArray(arr,mid+1,h,k);
    }
    else
    {
    	if(k>=arr[mid] && k<=arr[h])
    		return searchElementInSortedPivotedArray(arr,mid+1,h,k);
    	else
    		return searchElementInSortedPivotedArray(arr,l,mid-1,k);
    }

}

//merge 2 sorted array

void mergeTwoSortedArrays(int a[],int b[])
{
    int m=sizeof(a)/sizeof(a[0]);
    int n=sizeof(b)/sizeof(b[0]);
    for(int i=n-1;i>=0;i--)
    {    
       int j,last=a[m-1];
    	for(int j=m-2;j>=0 && a[j]>b[i];j--)
    	{
            a[j+1]=a[j];
    	}
    	if(j!=m-2 || last > b[i])
    	{
    		a[j+1]=b[i];
    		b[i]=last;
    	}
    }
}

//best code for rotate

void rotate(int nums[], int n, int k) {
    for (; k %= n; n -= k)
        for (int i = 0; i < k; i++)
            swap(*nums++, nums[n - k]);
}
//new best method
 void rotate(vector<int>& nums, int k) {
        
        if(nums.size()==0 || k<=0)
            return;
        int n=nums.size();
        vector<int> arr(nums);
        for(int i=0;i<n;i++)
            nums[(i+k)%n]=arr[i];
        
    }

// left rotate the  array

int GCD(int a,int b)
{
	if(b==0)
		return a;
	else
		return GCD(b,a%b);
}

void leftRotate(int arr[],int d,int n)
{
	int k,j,temp;
	for(int i=0;i<GCD(d,n);i++)
	{
		temp=arr[i];
		j=i;
		while(1)
		{
			k=j+d;
			if(k>=n)
				k=k-n;
			if(k==i)
				break;
			a[j]=a[k];
			j=k;
		}
        a[j]=temp;
	}
}

//maximum sum such that no 2 elements are adjacent

int maxSumNotAdjacent(int arr[])
{
	int size=sizeof(arr)/sizeof(arr[0]);
	int inc=arr[0],exc=0,exc_new=0;
	for(int i=0;i<size;i++)
	{
		exc_new=max(inc,exc);
		inc=exc+arr[i];
		exc=exc_new;
	}
	return max(inc,exc);
}

//find the smallest and second smallest elements in array

void findFirstAndSecondSmallest(int arr[],int size)
{
	int a=INT_MAX,b=INT_MAX;
	for(int i=0;i<size;i++)
	{
		if(arr[i]<a)
		{
			b=a;
			a=a[i];
		}
		else
			if(arr[i]<b && arr[i]!=a)
				b=a[i];
	}
	if(b!=INT_MAX)
		cout<<a<<"\t"<<b;
}

//Segregate 0s and 1s in an array

void segregate0sAnd1s(int arr[])
{
	int right=(sizeof(arr)/sizeof(arr[0])) - 1;
	int left=0;
	while(left<right)
	{
		while(arr[left]==0 && left<right)
			left++;
		while(arr[right]==1 && left<right)
			right--;
		if(left<right)
		{
			arr[left]=0;
			arr[right]=1;
			left++;
			right--;
		}
	}
}

// K'th smallest element /modify for (largest)

int partition(int arr[],int l,int r)
{
	int x=arr[r],i=l;
	for(int j=l;j<=r-1;j++)
	{
		if(arr[j]<=x)
		{
          swap(&arr[i],&arr[j]);
          i++;
		}			
	}
	swap(&arr[i],&arr[r]);
    return i;
}


int randomPartition(int arr[],int l,int r)
{
	int n=r-l+1;
	int pivot=rand()%n;
	swap(&arr[l+pivot],&arr[r]);
	return partition(arr,l,r);
}

int KthElement(int arr[],int l,int r,int k)
{
	if(k>0 && k<=r-l+1)
	{
		int pos=randomPartition(arr,l,r);

		if(pos-l==k-1)
			return arr[pos];
		if(pos-l>k-1)
		{
			return KthElement(arr,l,pos-1,k);
		}
		return KthElement(arr,pos+1,r,k-(pos-l+1));
	}
	return INT_MAX;
}

/* function invocation
     1)for kth smallest element
               KthElement(arr,0,n-1,k);
     2)for kth largest element
                KthElement(arr,0,n-1,n-k);
                */

//Maximum difference between two elements such that larger element appears after the smaller number

void maxDifference(int arr[],int size)
{
	int minEle=arr[0],maxDiff=arr[1]-arr[0];
	for(int i=1;i<size;i++)
	{
		if(arr[i]-minEle > maxDiff)
			maxDiff=arr[i]-minEle;
		if(arr[i] < minEle)
			minEle=arr[i];
	}
 return maxDiff; 
}

//find the ceil and floor of given value in sorted array
//          i-1 th and i+1 th indices

int binarySearch(int arr[],int l,int r,int k)
{
   if(l>r) return -1;
   int mid=(l+r)/2;
   if(arr[mid]==k)
   	return mid;
   if(arr[mid]>k)
   	return binarySearch(arr,l,mid-1,k);
   else
   	return binarySearch(arr,mid+1,r,k);
}
void findCeilAndFloor(int arr[],int size,int k)
{
	int pos=binarySearch(arr,0,size-1,k);
	if(pos-1>=0 && pos-1 <= size-1)
		cout<<"floor : "<<arr[pos-1]<<endl;
	if(pos+1>=0 && pos+1 <= size-1)
		cout<<"ceil : "<<arr[pos+1]<<endl;
}

//find ceil and floor in unsorted array

void findCeilAndFloorUnsrotedArray(int arr[],int size,int k)
{
	int cInd=0,cDiff=INT_MAX,fInd=0;fDiff=INT_MAX;
	for(int i=0;i<size;i++)
	{
       if(arr[i]<k && fDiff > k-arr[i])
       {
       	fDiff=k-arr[i];
        fInd=i;
       }
       if(arr[i]>k && cDiff > arr[i]-k)
       {
       	cDiff=arr[i]-k;
        cInd=i;
       }
	}
	if(cInd==INT_MAX)
		cout<<"no ceil";
	else
		cout<<cInd;
	if(fInd==INT_MAX)
		cout<<"no floor";
	else
		cout<<fInd;
}

//Segregate Even and Odd numbers
//all even numbers first, and then odd numbers. 

void SegregateEvenOdd(int arr[],int size)
{
	int l=0;r=size-1;
	while(l<r)
	{
		while(arr[l]%2==0 && l<r)
			l++;
		while(arr[r]%2!=0 && l<r)
			r--;
		if(l<r)
			{
				swap(&arr[l],&arr[r]);
				l++;
				r--;
			}
	}
}

//Product Array Puzzle the product of all the elements of arr[] except arr[i]

void productArray(int arr[],int size,int level,int *lh,int *rh)
{
    if(level==size)
    	{
    		*rh=1;
    		return;
    	}
    int l=*lh,r=1;
    *lh=*(lh)*arr[level];
    productArray(arr,size,level+1,lh,rh);
    r=*rh;
    (*rh) =(*rh) * arr[level];
    arr[level]=l*r;
}

//find repeating elements (changes the given array)

vector<int> findRepeatingElements(int arr[],int size)
{
	vector<int> v;
	for(int i=0;i<size;i++)
	{
		if(arr[abs(arr[i])]>0)
			arr[abs(arr[i])]=-arr[abs(arr[i])];
		else
			v.push_back(abs(arr[i]));
	}
	return v;
}

//find repeating elements using xor

//sort array of 0, 1, 2 (duch flag problem)

void duchSortArray(int arr[],int size)
{
	int lo=0,mid=0,hi=size-1;

	while(mid<=hi)
	{
		switch(arr[mid])
		{
			case 0:swap(&arr[lo++],&arr[mid++]);
			       break;
			case 1:mid++;
			       break;
			case 2:swap(&arr[mid],&arr[hi--]);
			       break;
		}
	}
} 

//find the equlibrium index

int equlibriumIndex(int arr[],int size,int *l,int *r,int level)
{
	if(level==size)
		return 0;
	int l1=*l;
	*l=*l+arr[level];

	equlibriumIndex(arr,size,&l1,r,level+1);

	int r1=*r;
	(*r) + = arr[level];
	
	if(l1-r1==0)
		return level;
	else
		return 0;
}

//next greater element

int* nextGreaterElement(int arr[],int size)
{
   stack<int> s;
   int list[size];
   for(int i=size-1;i>=0;i--)
   {
   	   while(!s.empty() && arr[i]>s.top())
   	   		s.pop();
   	   if(!s.empty())
   	   	list[i]=s.top();
   	   else
   	   	list[i]=-1;
   	   s.push(arr[i]);
   }
   return list;
}

//next Greater element in circular array
int* nextGreaterElementCircularArray(int arr[],int size)
{
   stack<int> s;
   int list[size];
   for(int i=size-1;i>=0;i--)
   {
      s.push(arr[i]);
   }
   for(int i=size-1;i>=0;i--)
   {
   	   while(!s.empty() && arr[i]>s.top())
   	   		s.pop();
   	   if(!s.empty())
   	   	list[i]=s.top();
   	   else
   	   	list[i]=-1;
   	   s.push(arr[i]);
   }
   return list;
}

bool areConsecutive(int arr[],int size)
{
	if(size<1)
		return false;
	if(size==1)
		return true;
	int min=arr[0],max=arr[0],sum=arr[0],refSum=0;
	for (int i = 1; i < size; i++)
	{
		sum+=arr[i];
		min=(min>arr[i])?arr[i]:min;
		max=(max<arr[i])?arr[i]:max;
	}
    refSum=((max-min+1)(max+min))/2;

    return (refSum==sum)?true:false;
}

//find the length of maxminum bitonic subarray

int maximumBitonicSubarray(int arr[],int size)
{
	int inc[size];
	int dec[size];
	inc[0]=1;dec[size-1]=1;
	for(int i=1;i<size;i++)
	{
		inc[i]=(arr[i]>arr[i-1])?inc[i-1]+1:1;
	}
	for(int i=size-2;i>=0;i--)
	{
		dec[i]=(arr[i]>arr[i+1])?dec[i+1]+1:1;
	}
	int max=inc[0]+dec[0]-1;
	for(int i=1;i<size;i++)
	{
		if(inc[i]+dec[i]-1>max)
			max=inc[i]+dec[i]-1;
	}
    return max;
}


//find subarray indices with given sum

int findSubArrayWithGivenSum(int arr[],int size,int sum)
{
	int start=0,curSum=arr[0],i;
	for(int i=1;i<size;i++)
	{
		while(curSum>sum && start<i-1)
		{
			curSum-=arr[start];
			start++:
		}
		if(curSum==sum)
		{
			cout<<"start and end indices are"<<start<<i;
			return 1;
		}
		curSum+=arr[i];
	}
	return 0;
}

//length of longest increasing subsequence (DP)

int lengthOfLIS(int arr[],int size)
{
	int lis[size];
	for(int i=0;i<size;i++)
		lis[i]=1;
	for(int i=1;i<size;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && lis[i]<lis[j]+1)
				lis[i]=lis[j]+1;
		}
	}
	int max=lis[0];
	for(int i=1;i<size;i++)
	{
		max=(max>lis[i])?max:lis[i];
	}
	return max;
}

//sum of longest increasing subsequence

int sumOfLIS(int arr[],int size)
{
	int lis[size];
	for(int i=0;i<size;i++)
		lis[i]=arr[i];
	for(int i=1;i<size;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && lis[i]<lis[j]+arr[j])
				lis[i]=lis[j]+arr[j];
		}
	}
	int max=lis[0];
	for(int i=1;i<size;i++)
	{
		max=(max>lis[i])?max:lis[i];
	}
	return max;
}

//Seggregate all neagative and positive number

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
    *b=temp;
}
void Seggregate(int arr[],int size)
{
	int l=0,h=size-1;
	while(l<h)
	{
		while(l<=0)
			l++;
		while(h>0)
			h--;
		while(l<h)
		{
			swap(&arr[l],&arr[h]);
			l++;--;
		}
	}
}

//Maximum Product Subarray

int maximumProductSubarray(int arr[],int size)
{
	int max_sofar=1,max_ending=1,min_ending=1;

	for(int i=0;i<size;i++)
	{
		if(arr[i]>0)
		{
			max_ending=max_ending*arr[i];
			min_ending=min(min_ending*arr[i],1)
		}
		else
			if(arr[i]==0)
			{
				max_ending=1;
				min_ending=1;
			}
			else
			{
				int temp=max_ending;
				max_ending=max(min_ending*arr[i],1);
				min_ending=temp*arr[i];
			}
	max_sofar=max(max_sofar,max_ending);
	}
	return max_sofar;
}

int maxprd(vector<int> nums[])
{
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
//Maximum profit by buying and selling a share at most twice

int findMaximumProfit(int price[],int size)
{
	int profit[size];
	for(int i=0;<size;i++)
		profit[i]=0;
	int mini=0,maxi=0;
	maxi=price[n-1];
	for(int i=size-2;i>=0;i--)
	{
		if(price[i]>maxi)
			maxi=price[i];
		profit[i]=max(profit[i+1],maxi-price[i]);
	}
	mini=price[0];
	for(int i=1;i<size;i++)
	{
		if(price[i]<mini)
			mini=price[i];
		profit[i]=max(profit[i-1],profit[i]+(price[i]-mini));
	}
	return profit[size-1];
}

//find minimum element in pivoted and rotated array

int findMinOfSortedPivoted(int arr[],int l,int h)
{
	if(l>h) return arr[0];
	if(l==h) return arr[l];
	
	int mid=l+(h-l)/2;

	if(arr[l]<arr[mid])
	{
		if(arr[mid]<arr[mid-1])
			return arr[mid];
		else
			if(arr[mid]>arr[mid-1])
				return findMinOfSortedPivoted(arr,mid+1,h);
			else
				return findMinOfSortedPivoted(arr,l,mid-1);       
	}
	else
	{
		if(arr[mid]>arr[mid-1])
			return findMinOfSortedPivoted(arr,l,mid-1);
		else
			return findMinOfSortedPivoted(arr,mid+1,h);

	} 

}

// this easy method can be used
while(l<h)
	{
	int mid=(l+h)/2;
  	if(arr[l]>arr[h])
  	{
	   	if(arr[mid]>arr[mid-1])
	    l=mid+1;
	   	else
	    h=mid;
	}
  else
	{
	  	if(arr[mid]>arr[mid-1])
	    h=mid-1;
	   	else
	    l=mid;
	}
}

//Rearrange an array such that ‘arr[j]’ becomes ‘i’ if ‘arr[i]’ is ‘j’

void rearrangeIndexAndValueUtil(int arr[],int size,int i)
{
	int val=-(i+1);

	i=arr[i]-1;

	while(arr[i]>0)
	{
		int newI=arr[i]-1;

		arr[i]=val;

		val=-(i+1);

		i=newI;
	}
}

void rearrangeIndexAndValue(int arr[],int size)
{
	for(int i=0;i<size;i++)
		arr[i]++;

	for(int i=0;i<size;i++)
	{
		if(arr[i]>0)
			rearrangeIndexAndValueUtil(arr,size,i);

	}

	for(int i=0;i<size;i++)
	{
		arr[i]=-(arr[i])-1;
	}
}

//Check if a given array contains duplicate elements within k distance from each other

bool checkForDuplicateAtKDistance(int arr[],int size)
{
	unordered_set<int> s;
	for(int i=0;i<size;i++)
	{
		if(i>=k)
			s.erase(arr[i-k]);
		if(s.find(arr[i])==s.end())
		{
			s.insert(arr[i]);
		}
		else
			return false;
		
	}
	return true;
}

//Zig-Zag fashion converted array
     // should be in form a < b > c < d > e < f. 

void zigZag(int arr[],int size)
{
	bool flag=true;
	for(int i=0;i<=size-2;i++)
	{
		if(flag)
		{
			if(arr[i]>arr[i+1])
				swap(&arr[i],&arr[i+1]);
		}
		else
		{
			if(arr[i]<arr[i+1])
				swap(&arr[i],&arr[i+1]);
		}
		flag=!flag;
	}
}

//count strictly increasing subarrays

int countIncreasingSubarrays(int arr[],int size)
{
	int count=1,totcnt=0;
	for(int i=0;i<size-1;i++)
	{
		if(arr[i]<arr[i+1])
			count++;
		else
		{
			totcnt+=((count-1)*count)/2;
			count=1;
		}
	}
	if(count>1)
		totcnt+=((count-1)*count)/2;
	return totcnt;
}

//rearrange array (smart)
// first element should be the maximum value,
  // second minimum value, third-second max, fourth-second min and so on. 

void rearrangeType(int arr[],int size)
{
	int maxEle=arr[size-1]+1;
	int maxind=size-1,minInd=0;
	for(int i=0;i<size;i++)
	{
		if(i%2==0)
		{
			arr[i]+=(arr[maxInd--]%maxEle)*maxEle;
		}
		else
		{
			arr[i]+=(arr[minInd++]%maxEle)*maxEle;
		}
	}
	for(int i=0;i<size;i++)
		arr[i]=arr[i]/maxEle;
}
//find the number of subarrays with given sum (k)

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

// find min len subarray with given sum
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

//maximizeZeroCount by fliping any of the 1's subarray
int maximizeZeroCount(int arr[],int size)
{
	int org0cnt=0,curmax=0,totmax=0;

	for(int i=0;i<size-1;i++)
	{
		if(arr[i]==0)
			org0cnt++;
		int val=(arr[i]==1)?1:-1;
		curmax=max(val,curmax+val);
		totmax=max(totmax,curmax);
	}
	return org0cnt+totmax;
}

//maximum subarray with  equal number of 1 and 0

int maxSubarray10(int arr[],int n)
{
	map<int,int> m;
	m[0]=-1;
	int sum=0,maxlen=0;
	for(int i=0;i<n;i++)
	{
        sum+=(arr[i]==0)?-1:1;
        auto it=m.find(sum);
        if(it!=m.end())
        	maxlen=max(maxlen,i-it->second());
        else
        	m[sum]=i;
	}
	return maxlen;
}

//find the next greater element with same digits

void nextGreaterLexicoNumberPermu(int arr[],int n,int &ans)
{
	
    for(int i=n-1;i>0;i--)
    	if(arr[i]>arr[i-1])
    		break;
    if(i==0)
    	{ans=-1;return;}
    int x=arr[i-1],small=i;
    for(int j=i+1;j<n;j++)
    	if(arr[j]>x && arr[j]<arr[small])
    		small=j;
    swap(&arr[i-1],&arr[small]);
    sort(arr+i,arr+n);
    for (int i : arr)
    {
    	ans=ans*10+i;
    }
    return ans;
}

//find the first and last indes of a target

vector<int> searchRange(vector<int>& arr, int x) {
        
        vector<int> ans(2,-1);
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

// merge 2 sorted array into one where the first one has extra space to accomodate second arr

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{     
    int i=m-1,j=n-1,tar=m+n-1;
    while(j>=0)
    {
        nums1[tar--]=(i>=0) && (nums1[i]>nums2[j])?nums1[i--]:nums2[j--];
    }
                
}

//find the median of two arrays [1,4,5] [2,3] ans is 3 [1,2,4][3,5,6] ans 4+3/2=3.5


class Solution {
    public:
        double findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
            int m = A.size(), n = B.size();
            if (m > n) return findMedianSortedArrays(B, A);
            int imin, imax, i, j; 
            imin = 0;
            imax = m;
            while (imin <= imax) {
                i = (imin + imax)/2;
                j = (m+n+1)/2 - i;
                if (j > 0 && i < m && B[j - 1] > A[i]) {
                    imin = i + 1;
                } else if (i > 0 && j < n && A[i - 1] > B[j]) {
                    imax = i - 1;
                } else {
                    // Figure out median now. 
                    int median1 = 0, median2 = 0;
                    if (i == 0) {
                        median1 = B[j - 1];
                    } else if (j == 0) {
                        median1 = A[i - 1];
                    } else {
                        median1 = max(A[i - 1], B[j - 1]);
                    }
                    if ((m+n) % 2 == 1) {
                        return 1.0 * median1;
                    }
                    if (i == m) {
                        median2 = B[j];
                    } else if (j == n) {
                        median2 = A[i];
                    } else {
                        median2 = min(A[i], B[j]);
                    }
                    return 1.0 * (median1 + median2) / 2.0;
                }
            }
            return -1.0;
        }

};

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

//find the next greater palindrome
int nextPalin(vector<int> v)
{   int n=v.size()/2;
	int mid=n;
	int i=mid-1;
	bool lar=false;
	int j=(n%2)?mid+1:mid;
	while(v[i]==v[j])
		{i--;j++;}
	if(v[i]<v[j])  lar=true;
	while(i>=0)
		v[j++]=v[i--];
	if(lar)
	{
		i=mid-1;
		int carry=1;
		if(n%2)
		{
			v[mid]+=carry;
			carry=v[mid]/10;
			v[mid]%10;
			j=mid+1;
		}
		else
			 j=mid;
		while(i>=0)
		{
			v[i]+=carry;
			carry=v[i]/10;
			v[i]%=10;
		    v[j++]=v[i--];
		}
 
	}
	int num=0;
	for(int i : v)
         num=num*10+i;
    return num;
}
bool areAll9(vector<int> v)
{
	for(int i : v)
	  if(i!=9)
	    return false;
	return true;
}
int findnextPalindrome(int num){
	vector<int> v;
	while(num>0)
	{
		v.push_back(num%10);
		num/=10;
	}
	if(areAll9(v))
	{
		int num=1;
		for(int j=0;j<v.size();j++)
		{
			num=num*10;
		}
		return num+1;
	}
	else
		return nextPalin(v);
}


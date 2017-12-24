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
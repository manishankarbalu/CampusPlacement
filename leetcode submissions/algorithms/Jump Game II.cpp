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
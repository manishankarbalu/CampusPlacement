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
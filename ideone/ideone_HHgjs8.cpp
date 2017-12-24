#include <iostream>
#include <vector>
using namespace std;
 int nonDuplicate(vector<int> arr,int l,int h)
    {
        int mid=(l+h)/2;
        
        if(mid==l && arr[mid]!=arr[mid+1])
            return arr[mid];
        if(mid==h && arr[mid]!=arr[mid-1])
            return arr[mid];
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
           return arr[mid];
           
        if(arr[mid]==arr[mid+1] && (mid+1)%2==0) 
            return nonDuplicate(arr,l,mid-1);
        if(arr[mid]==arr[mid-1] && (mid)%2!=0) 
            return nonDuplicate(arr,mid+1,h);
    }

    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()<2)
        return nums[0];
        return nonDuplicate(nums,0,nums.size()-1);
        
    }
int main() {
	
	vector<int> nums={3,3,7,7,10,11,11};
	cout<<singleNonDuplicate(nums)<<endl;
	return 0;
}
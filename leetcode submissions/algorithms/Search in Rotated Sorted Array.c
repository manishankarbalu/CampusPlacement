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
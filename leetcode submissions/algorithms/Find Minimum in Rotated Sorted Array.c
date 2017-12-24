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
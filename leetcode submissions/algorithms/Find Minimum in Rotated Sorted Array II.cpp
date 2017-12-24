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
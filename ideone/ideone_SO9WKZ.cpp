#include<stdio.h>
#include<stdlib.h>

bool areConsecutive(int arr[],int size)
{
	if(size<1)
		return false;
	if(size==1)
		return true;
	int min1=arr[0],max1=arr[0],sum=arr[0],refSum=0;
	for (int i = 1; i < size; i++)
	{
		sum+=arr[i];
		min1=(min1>arr[i])?arr[i]:min1;
		max1=(max1<arr[i])?arr[i]:max1;
	}
    refSum=(max1-min1+1)*(max1+min1)/2;

    return (refSum==sum)?true:false;
}

/* Driver program to test above functions */
int main()
{
    int arr[]= {1, 5, 3, 2, 6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    if(areConsecutive(arr, n) == true)
        printf(" Array elements are consecutive ");
    else
        printf(" Array elements are not consecutive ");
    getchar();
    return 0;
}
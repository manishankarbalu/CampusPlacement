#include <iostream>
using namespace std;

int findMin(int arr[],int l,int h)
{
	if(h<l) return arr[0];
	//if(h==l+1) return (arr[0]>arr[1])?arr[1]:arr[0];
	while(l<h)
	{
		int mid=(l+h)/2;
		if(arr[mid]<arr[mid-1])
		     return arr[mid];
	//	if(arr[mid]>=arr[l])
	//	{
			if(arr[mid]>arr[h])
				l=mid+1;
		    else
		        h=mid-1;
	/*	}
		else
		   {
		   		if(arr[mid]>arr[h])
		   		   l=mid+1;
		   		else
		   		   h=mid-1;
		   }
	*/	   
	}
	return arr[l];
}

int main()
{
    int arr1[] =  {5, 6, 1, 2, 3, 4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("The minimum element is %d\n", findMin(arr1, 0, n1-1));
 
    int arr2[] =  {1, 2, 3, 4};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("The minimum element is %d\n", findMin(arr2, 0, n2-1));
 
    int arr3[] =  {1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    printf("The minimum element is %d\n", findMin(arr3, 0, n3-1));
 
    int arr4[] =  {1, 2};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    printf("The minimum element is %d\n", findMin(arr4, 0, n4-1));
 
    int arr5[] =  {2, 1};
    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    printf("The minimum element is %d\n", findMin(arr5, 0, n5-1));
 
    int arr6[] =  {5, 6, 7, 1, 2, 3, 4};
    int n6 = sizeof(arr6)/sizeof(arr6[0]);
    printf("The minimum element is %d\n", findMin(arr6, 0, n6-1));
 
    int arr7[] =  {1, 2, 3, 4, 5, 6, 7};
    int n7 = sizeof(arr7)/sizeof(arr7[0]);
    printf("The minimum element is %d\n", findMin(arr7, 0, n7-1));
 
    int arr8[] =  {2, 3, 4, 5, 6, 7, 8, 1};
    int n8 = sizeof(arr8)/sizeof(arr8[0]);
    printf("The minimum element is %d\n", findMin(arr8, 0, n8-1));
 
    int arr9[] =  {3, 4, 5, 1, 2};
    int n9 = sizeof(arr9)/sizeof(arr9[0]);
    printf("The minimum element is %d\n", findMin(arr9, 0, n9-1));
    
    int arr91[] =  {2, 3, 1};
    int n91 = sizeof(arr91)/sizeof(arr91[0]);
    printf("The minimum element is %d\n", findMin(arr91, 0, n91-1));
 
    return 0;
}
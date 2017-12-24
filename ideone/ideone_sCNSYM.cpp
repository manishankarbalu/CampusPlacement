#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void productArray(int arr[],int size,int level,int *lh,int *rh)
{
    if(level==size)
    	{
    		*rh=1;
    		return;
    	}
    int l=*lh,r=1;
    int l1=l*arr[level];
    productArray(arr,size,level+1,&l1,rh);
    r=*rh;
    (*rh) =(*rh) * arr[level];
    arr[level]=l*r;
}
/* Driver program to test above functions */
int main()
{
  int arr[] = {10, 3, 5, 6, 2};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("The product array is: \n");int l=1,r=1;
  productArray(arr, n,0,&l,&r);
  for(int i=0;i<n;i++)
     cout<<arr[i]<<" ";
   cout<<endl;
 //getchar();
}
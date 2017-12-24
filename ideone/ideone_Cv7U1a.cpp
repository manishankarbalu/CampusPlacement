#include <stdio.h>
#include<iostream>
using namespace std;
void equlibriumIndex(int arr[],int size,int *l,int *r,int level,int *ans)
{
	if(level==size)
		return;
	
	int l1=(*l);
	*l=(*l)+arr[level];
	
	equlibriumIndex(arr,size,l,r,level+1,ans);

	int r1=*r;
	(*r)=(*r)+arr[level];
	
	if(l1-r1==0 && level>0 && level < size-1)
	       *ans=level;
} 
 

int main()
{
  int arr[] = {-7, 1, 5, 2, -4, 3, 0};
  int arr_size = sizeof(arr)/sizeof(arr[0]);int l=0,r=0;
  int ans=-1;
  equlibriumIndex(arr, arr_size,&l,&r,0,&ans);
  cout<<ans;
 
  getchar();
  return 0;
}
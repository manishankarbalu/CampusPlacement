#include<stdio.h>
 

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SegregateEvenOdd(int arr[],int size)
{
	int l=0,r=size-1;
	while(l<r)
	{
		while(arr[l]%2==0 && l<r)
			l++;
		while(arr[r]%2!=0 && l<r)
			r--;
		if(l<r)
			{
				swap(&arr[l],&arr[r]);
				l++;
				r--;
			}
	}
}
/* driver program to test */
int main()
{
    int arr[] = {12, 34, 45, 9, 8, 90, 3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
 
    SegregateEvenOdd(arr, arr_size);
 
    printf("Array after segregation ");
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
 
    return 0;
}
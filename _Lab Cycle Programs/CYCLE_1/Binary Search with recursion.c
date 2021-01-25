//Program to do binary search using recursion

#include <stdio.h> 

int main(void) 
{ 
    int a[10];
    int n,i,v;
    printf("Enter the no of items:");
    scanf("%d",&n);
    printf("Enter values in ascending order:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
   
    printf("Enter the value to be searched : ");
    scanf("%d",&v);
    int result = binarySearch(a, 0, n-1, v); 
    if(result == -1)
    printf("Value not found");
    else
    printf("Value found  at position %d", result+1); 
return 0; 
} 



int binarySearch(int a[], int l, int r, int x) 
{ 
if (r >= l) 
{ 
		int mid = l + (r - l)/2; 

		
		if (a[mid] == x) 
        return mid; 
        if (a[mid] > x) 
        return binarySearch(a, l, mid-1, x); 
        else
        return binarySearch(a, mid+1, r, x); 
} 
return -1; 
} 


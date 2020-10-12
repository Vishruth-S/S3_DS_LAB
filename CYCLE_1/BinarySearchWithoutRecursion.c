// Write a C program to do binary search without using recursion

#include <stdio.h> 
  

int binarySearch(int arr[], int l, int r, int x) 
{ 
   while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        if (arr[m] == x) 
            return m; 
  
        else if (arr[m] < x) 
            l = m + 1; 
        else{
            r = m - 1; 
        }
    }
    return -1;    
} 
  
  
void main() 
{ 
   int ele,n,result;
    int arr[100]; 
     
     printf("Enter the size of the array\n");
     scanf("%d",&n);

     printf("Entar the array\n");
     for(int i=0;i<n;i++){
         scanf("%d",&arr[i]);
     }

     printf("Enter the element to be searched for\n");
     scanf("%d",&ele);

    result = binarySearch(arr, 0, n - 1, ele); 
    
     if(result == -1){
         printf("Element is not present in array\n");
     }  
     else{
        printf("Element is present at position %d\n", result+1);  
     }                     
} 
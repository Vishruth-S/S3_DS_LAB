//Write a C program to do linear search without using recursion

#include<stdio.h>

int lsearch(int arr[], int n, int x) 
{ 

    for (int i=0;i<n;i++) 
        if (arr[i] == x) 
            return i; 
    
    return 0; 
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

     result = lsearch(arr, n, ele); 
    
    if(result == 0){
        printf("Element is not present in array\n");
    }
    else{
        printf("Element is present at position %d\n", result+1); 
    }
} 
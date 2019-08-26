#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//in a  array find no. of unique pairs (a,b) such that a+k = b.
int fun(void * ptr,void*ptr2)
{
    int * a=(int*)ptr;
    int * b=(int *)ptr2;
    return *a-*b;
}
int countPairs(int n, int* arr, int k) {
    qsort(arr,n,sizeof(int),fun);
    int res=0;
    int i=0,j=0;
    while(j<n-1 && i<n-1)
    {
       while(arr[j]==arr[j+1])j++;
       while(arr[i]==arr[i+1])i++;
       int c=arr[j]-arr[i];
       if(c==k)
       {
         res++;
         i++;
         j++;
       }
       else
       {
           if(c<k)
           {
             j++;
           }
           else if(c>k)
           {
              i++;
           }
       }
    }
    while(i!=j)
    {
        while(arr[i]==arr[i+1])i++; 
        int c=arr[j]-arr[i];
       if(c==k)
       {
         res++;
         i++;
       }
       else
       {
           i++;
       }
    }
    return res;
}

int main()
{
    int n,k,i;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&k);
    printf("%d",countPairs(n,arr,k));
}
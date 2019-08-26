#include<stdio.h>
#include<stdlib.h>
int maxDifference(int arr_count, int* arr) {
    if(arr_count==1)return 0;
    int i=0,max=arr[1]-arr[0],min= arr[0]<arr[1] ? arr[0] : arr[1],key=0;
    for(i=2;i<arr_count;i++)
    {
       if(arr[i]>min)
       {
           int temp=arr[i]-min;
           max=max>temp ? max : temp;
           key=1;
       }
       else if(arr[i]<min)
       {
           min=arr[i];
       }
    }
    if(key==1)
    return max;
    else
    return -1;
}
int main()
{
  int n,i;
  scanf("%d",&n);
  int arr[n];
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("%d\n",maxDifference(n,arr));
}
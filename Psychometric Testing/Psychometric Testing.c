
 int fun(void *ptr1,void *ptr2)
 {
     int *a=(int *)ptr1;
     int *b=(int *)ptr2;
     return *a-*b;
 }
 int upper_limit(int *scores,int n,int upper)
 {
     if(scores[n-1]<=upper)
     return n;
     int l=0,r=(n-1),mid=0;
     while(l<r)
     {
       mid=(l+r)/2;
       if(scores[mid]<=upper)
       l=mid+1;
       else  
       r=mid;
     }
     if(l==r)
     return l;
     else  
     return mid;
 }
 int lower_limit(int *scores,int n,int lower)
 {
     
     
     int l=0,r=(n),mid=0;
     while(l<r)
     {
       mid=(l+r)/2;
       if(scores[mid]<lower)
       l=mid+1;
       else  
       r=mid;
     }
     if(l==r)
     return l;
     else  
     return mid;
 }
 int* jobOffers(int scores_size, int* scores, int lower_size, int* lowerLimits, int upper_size, int* upperLimits, int* result_size) 
 {
    qsort(scores,scores_size,sizeof(int),fun);
    int *res=(int *)malloc(sizeof(int)*lower_size);
    int i;
    for(i=0;i<lower_size;i++)
    {
       int a=upper_limit(scores,scores_size,upperLimits[i]);
       int b=lower_limit(scores,scores_size,lowerLimits[i]);
       res[i]=(a-b);
    }
   *result_size=lower_size;
    return res;

}

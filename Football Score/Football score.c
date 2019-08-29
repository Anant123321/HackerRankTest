
 int fun(void * ptr, void * btr)
 {
     int * a = (int *)ptr;
     int * b = (int *)btr;
     return *a-*b;
 }
int* counts(int n1, int* A, int n2, int* B, int* result) {
    qsort(A,n1,sizeof(int),fun);
    int * arr=(int*)malloc(sizeof(int)*n2);
    int i=0,j=0,k=0,count=0,index=0;
    for(i=0;i<n2;i++)
    {
        int l=0,r=n1-1,mid=(l+r)/2,c=0;
        while(l<=r)
        {
          mid=(l+r)/2;
          if(A[mid]<=B[i])
          {
              l=mid+1;
              c=mid+1;
          }
          else
          {
              r=mid-1;
          }
        }
        arr[k++]=c;
    }
    *result=n2;
    return arr;
}
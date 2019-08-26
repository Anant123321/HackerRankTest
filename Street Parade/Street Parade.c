#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct node
{
    int data;
    struct node * next;
}node;

void push(node **head,int value)
{
    node * newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=(*head);
    (*head)=newnode;
}

int top(node * head)
{
    if(head==NULL)return 0;
    return head->data;
}

void pop(node ** head){
    (*head)=(*head)->next;
    }

void check(int *arr,int n)
{
    int var=1,i=0;
    node * head = NULL;
    for(i=0;i<n;i++)
    {
        if(arr[i]==var)
        {
            var++;
        }
        else
        {
            if(top(head)==var)
            {
                var++;
                pop(&head);
                i--;
            }
            else
            {
                push(&head,arr[i]);
            }
        }
    }
    int key=0;
    while(head!=NULL)
    {
        if(top(head)!=var)key=1;
        pop(&head);
        var++;
    }
    if(key==1)printf("no");
    else
    printf("yes");
}
int main() {
   int i=0,n=0,c;
   scanf("%d",&n);
   c=n;
   int *arr=(int*)malloc(sizeof(int)*n);
   while(n!=0)
   {
       for(i=0;i<n;i++)
       {
          scanf("%d",&arr[i]);
       }
       check(arr,n);
       scanf("%d",&n);
       if(n!=0)printf("\n");
       }
    return 0;
}


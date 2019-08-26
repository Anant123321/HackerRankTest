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

void push(int ele,node **head)
{
  node * newnode=(node*)malloc(sizeof(node));
  newnode->data=ele;
  newnode->next=(*head);
  (*head)=newnode;
}
 
void print(node * head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}
node * make_list(node * head,int arr[6])
{
    int i=0,j=3;
    while(i<3 && j<6)
    {
        if(arr[i]<=arr[j])
        {
            push(arr[i++],&head);
        }
        else
        {
            push(arr[j++],&head);
        }
    }
    while(i<3)
    {
        push(arr[i++],&head);
    }
    while(j<6)
    {
        push(arr[j++],&head);
    }
    return head;
}

int main() {
    int i=0,arr[6];
    node * head= NULL;
    for(i=0;i<6;i++)
    {
        scanf("%d",&arr[i]);
    }
    head=make_list(head,arr);
    print(head);
    return 0;
}


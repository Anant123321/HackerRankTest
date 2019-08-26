#include<stdio.h>
#include<stdlib.h>

/* structure for a node */
struct node
{
  int data;
  struct node *next;
};

void sortedInsert(struct node** head, struct node* newnode)
{
    typedef struct node node;
    if((*head)==NULL)
    {
        (*head)=newnode;
        newnode->next=(*head);
    }
    else{
        int key=0,var=1;
        node * current=(*head);
        node * prev =(*head)->next;
        while(prev->next!=(*head))
        {
            prev=prev->next;
        }
        while(current!=(*head) || var==1)
        {
            var=0;
            if(current->data<newnode->data)
            {
                prev=current;
                current=prev->next;
            }
            else{
                key=1;
                if(prev->next==(*head))
                {
                    newnode->next=prev->next;
                    prev->next=newnode;
                    (*head)=newnode;
                    
                }
                else{
                newnode->next=prev->next;
                prev->next=newnode;}
                break;
            }
        }
        if(key==0)
        {
            
            newnode->next=prev->next;
            prev->next=newnode;
        }
    }
}

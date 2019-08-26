
typedef struct SinglyLinkedListNode SinglyLinkedListNode;
SinglyLinkedListNode* removeNodes(SinglyLinkedListNode* head, int x) 
{
    SinglyLinkedListNode * current = head;
    SinglyLinkedListNode * prev = head;
    while(current != NULL)
    {
        if(current->data>x)
        {
            if(current==head)
            {
                head=head->next;
                current=head;
                prev=head;
            }
            else
            {
                prev->next=current->next;
                current=current->next;
            }

        }
        else
        {
            prev=current;
            current=current->next;
        }
    }
    return head;
}
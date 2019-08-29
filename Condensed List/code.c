

SinglyLinkedListNode* condense(SinglyLinkedListNode* head) {

typedef SinglyLinkedListNode node;
node * head2=head;
while(head!=NULL)
{
    node * prev=head;
    node * current=head->next;
    while(current!=NULL)
    { 
      if(current->data==head->data)
      {
         prev->next=current->next;
         current=current->next;
      }
      else
      {
          current=current->next;
          prev=prev->next;
      }
    }
    head=head->next;
}
return head2;
}
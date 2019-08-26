int checkpalindrome(listnode *A, listnode * B)
{
    while(A != NULL && B!= NULL)
    {
        if(A->val != B->val)return 0;
        A=A->next;
        B=B->next;
    }
    return 1;
}
listnode* reverse_list(listnode * first)
{
    listnode * second=NULL;
    if(first)
    {
        second=first->next;
    }
    if(first->next==NULL)return first;
    else
    {
        listnode * h = reverse_list(first->next);
        first->next=second->next;
        second->next=first;
        return h;
    }

} 
int isPalin(listnode* A){
    
    listnode * B=reverse_list(A);
    return checkpalindrome(A,B);

}
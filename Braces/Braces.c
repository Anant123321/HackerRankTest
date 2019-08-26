
typedef struct node
{
    char data;
    struct node * next;
}node;
void push(node ** head,char value)
{
    node * newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=(*head);
    (*head)=newnode;
}
int empty(node * head)
{
    if(head==NULL)return 1;
    else return 0;
}
char top(node * head)
{
    if(head)
    return head->data;
    else return 'y';
}
void pop(node ** head)
{
    if((*head)!=NULL)
    {
        (*head)=(*head)->next;
    }
}
char** braces(int n, char** arr, int* result) 
{
    char ** res = (char**)malloc(n*sizeof(char*));
    int i=0,j=0,k=0;
    for(i=0;i<n;i++)
    {
        node *head= NULL;
        for(j=0;arr[i][j]!='\0';j++)
        {
            if(arr[i][j]=='(' || arr[i][j]=='[' || arr[i][j]=='{')
            {
                push(&head,arr[i][j]);
            }
            else
            {
                if(arr[i][j]=='}' && top(head)=='{')
                pop(&head);
                else{
                         if(arr[i][j]==')' && top(head)=='(')
                         pop(&head);
                    else
                    {
                          if(arr[i][j]==']' && top(head)=='[')
                          pop(&head);
                          else
                          push(&head,'x');
                    }
                }
            }
        }
        if(empty(head)==0)
        {
            res[k++]="NO";
        }
        else
        {
            res[k++]="YES";
        }
    }
    *result=n;
    return res;
}

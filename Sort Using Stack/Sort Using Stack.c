#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define MAX 1000
typedef struct
{
int top;
int item[MAX];
}stack;
void init(stack *s)
{
s->top=-1;
}
int empty(stack *s)
{
return(s->top==-1);
}
int full(stack *s)
{
return(s->top==MAX-1);
}
void push(stack *s,int a)
{
if (full(s))
{
printf("stack is full");
exit(0);
}
else
s->item[++s->top]=a;
}
int pop(stack *s)
{
if(empty(s))
return (-1);
else
return(s->item[s->top--]);
}

int peek(stack *s)
{
    return s->item[s->top];
}
stack sort;
void sortfun(stack source,stack losers);

void sortfun(stack source,stack l)
{   
    stack s1;
    init(&s1);
    int i=0;
    while(!empty(&source))
    {
       int c = peek(&source);   
       if(empty(&s1))
       {
           push(&s1,c);
       }
       else
       {
          while(!empty(&s1) && peek(&s1)<c) 
          {
             int temp=pop(&s1);
             push(&l,temp);
          }
          push(&s1,c);
       }
       pop(&source);
    } 
    while(!empty(&l))
    {
        push(&s1,peek(&l));
        pop(&l);
    }  
    while(!empty(&s1))
    {
        printf("%d\n",peek(&s1));
        pop(&s1);
    }
}

int main()
{
 stack source, losers;
 int exp[MAX],temp;
    int i,n,a[20],f,c;
scanf("%d", &n);
init(&source);
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
push(&source,a[i]);
}
			init(&sort);
			init(&losers);
sortfun(source,losers);
    
      while(!empty(&sort))

	{            if(!empty(&sort))

      printf("%d\n",pop(&sort));
	 }
    return(0);}
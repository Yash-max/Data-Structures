#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
struct stack{
  int top;
  unsigned cap;
  int *arr;
};
struct stack* createStack(unsigned cap);
int isFull(struct stack * s);
int isEmpty(struct stack * s);
void push(struct stack * s,int item);
int pop(struct stack * s);
int peek(struct stack * s);
void main()
{
 clrscr();
 struct stack * s = createStack(30);
 int i,n,a;
 printf("Enter the number of elements : ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("\nEnter the element->%d : ",i+1);
 scanf("%d",&a);
 push(s,a);
 }
 printf("\n%d popped",pop(s));
 printf("\nSize of stack is : %d and of array is : %d with capacity : %d \n",sizeof(s),sizeof(s->arr),sizeof(s->cap));
 getch();
}
int peek(struct stack * s)
{
  if(isEmpty(s)){return 0;}
  return s->arr[s->top];
}

int pop(struct stack * s)
{
  if(isEmpty(s)){return 0;}
  return s->arr[s->top--];
}

void push(struct stack * s,int item)
{
 if(isFull(s)){return;}
 s->arr[++s->top]=item;
 printf("\n%d is pushed",s->arr[s->top]);
}

struct stack * createStack(unsigned cap)
{
  struct stack * s=(struct stack *)malloc(sizeof(struct stack)*cap);
  s->cap=cap;
  s->top=-1;
  s->arr=(int *)malloc(s->cap*sizeof(int));
  printf("\nSize of stack is : %d and of array is : %d with capacity : %d \n",sizeof(s),sizeof(s->arr),sizeof(cap));
  return s;
}
int isFull(struct stack * s)
{
  return s->top == s->cap -1;
}
int isEmpty(struct stack * s)
{
  return s->top == -1;
}
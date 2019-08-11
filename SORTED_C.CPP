#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<alloc.h>

struct node{
   int data;
   struct node * next;
};
void create(struct node **,int);
void sort_c(struct node **,int);
void show(struct node *);
void main()
{
 struct node * head = NULL;
 struct node * head1 = NULL;
 clrscr();
 printf("Enter the number of elements : ");
 int n;
 scanf("%d",&n);
 int i,a;
 for(i=1;i<=n;i++)
 {
  printf("\nEnter the element->%d : ",i);
  scanf("%d",&a);
  create(&head,a);
  sort_c(&head1,a);
  show(head);
 }
 printf("\nThe game is on : ");
 show(head1);
 getch();
}
void create(struct node ** head , int a)
{
 struct node * temp = (struct node *)malloc(sizeof(struct node));
 struct node * temp1 = (*head);
 temp->data=a;
 if((*head)==NULL)
 {
  temp->next=temp;
  (*head)=temp;
  return;
 }
 while(temp1->next!=(*head))
 {
  temp1=temp1->next;
 }
 temp1->next=temp;
 temp->next=(*head);
}
void show(struct node * head)
{
 struct node * temp = head;
 if(head == NULL)
 {printf("\nList is empty");return;}

 do{ printf("-->%d",temp->data);
     temp=temp->next;
 }while(temp!=(head));
}
void sort_c(struct node **head1,int a)
{
 struct node *temp=(struct node *)malloc(sizeof(struct node));
 struct node *temp1=(*head1);
 temp->data=a;
 if((*head1)==NULL)
 {
  temp->next=temp;
  (*head1)=temp;
  return;
 }
 if(temp1->data >= temp->data)
 {
 while(temp1->next!=(*head1))
 {
  temp1=temp1->next;
 }
   temp1->next=temp;
   temp->next=(*head1);
   (*head1)=temp;
   return;
 }
 else
 {
  while(temp1->next != (*head1) && temp1->next->data < temp->data)
  {
   temp1=temp1->next;
  }
  temp->next=temp1->next;
  temp1->next=temp;
 }
}

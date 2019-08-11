#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<alloc.h>
struct node{
   int data;
   struct node * next;
};

void create(struct node **h,int n)
{
 struct node * temp, *temp1 = *h;
 temp=(struct node *)malloc(sizeof(struct node));
 temp->data=n;
 if(*h==NULL)
 {
  *h=temp;
  temp->next=*h;
  return;
 }
 while(temp1->next!=*h)
 {
  temp1=temp1->next;
 }
 temp1->next=temp;
 temp->next=*h;
}
void show (struct node *h)
{
 struct node *temp=h;
 if(h==NULL)
 {
 printf("\nList is empty");
 return;
 }
 else
 {
  do
  {
   printf("-->%d",temp->data);
   temp=temp->next;
  }while(temp!=h);
 }
}

void splitList(struct node **head,struct node **head1,struct node **head2)
{
 struct node * slow = *head ;
 struct node * fast = *head ;

 if((*head)==NULL)
 {
 return;
 }
 //printf("bOo");
 if((*head)->next==(*head))
 {
 (*head1)=*head;
 (*head1)->next=*head1;
 printf("\nbOo");
 return;
 }
 if((*head)->next->next==(*head))
 {
  (*head1)=(*head);
  (*head2)=(*head)->next;
  (*head1)->next=(*head1);
  (*head2)->next=(*head2);
  return;
 }
 while(fast->next!=(*head)&&fast->next->next!=(*head))
 {
  fast=fast->next->next;
  slow=slow->next;
 }
 if(fast->next->next==(*head))
 {
  fast=fast->next;
 }
 fast->next=slow->next;
 (*head2)=slow->next;
 (*head1)=(*head);
 slow->next=(*head);
}

void main()
{
  clrscr();
  struct node * head=NULL;
  struct node * head1=NULL;
  struct node * head2=NULL;
  printf("Enter the number of elements : ");
  int i,a,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  printf("\nThe element %d is : ",i+1);
  scanf("%d",&a);
  create(&head,a);
  show(head);
  }
  splitList(&head,&head1,&head2);
  printf("\nList 1st : ");
  show(head1);
  printf("\nList 2nd : ");
  show(head2);
  getch();
}
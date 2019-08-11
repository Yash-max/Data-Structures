#include <stdio.h>
#include <string.h>
int precedence(char ch)
{
  switch (ch) {
    case '+':return 1;
    case '-':return 2;
    case '*':return 3;
    case '/':return 4;
    default : return 5;
  }
}
int stack[10];
top=-1;
void push(char ch)
{
  stack[++top]=ch;
}
int pop()
{
  return stack[top--];
}
int main()
{
  char postfix[15];
  printf("Enter the string to be evaluated : ");
  gets(postfix);
  int len=strlen(postfix);
  //printf("\n-->%d",len);
  for(int i=0;i<len;i++)
  {
    int t=precedence(postfix[i]);
    if(t==5)
    {
      push(postfix[i]-'0');
    }
    else
    {
      int y=pop();
      int x=pop();
      switch (t) {
        case 1:push(x+y);break;
        case 2:push(x-y);break;
        case 3:push(x*y);break;
        case 4:push(x/y);break;
        default :printf("\nInvalid input");
      }
    }
  }
  printf("\n-->%d",stack[top]);
  return 0;
}

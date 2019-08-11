#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[10];
int top=-1;
void push(char ch)
{
    stack[++top]=ch;
}
char pop()
{
    return stack[top--];
}
int prec(char ch)
{
    if(ch=='-'||ch=='+')
    {
        return 1;
    }
    if(ch=='*'||ch=='/')
    {
        return 2;
    }
    return 3;

}
void main()
{
    char in[30],pos[30];
    int i,j=0,t,len;
    gets(in);
    len=strlen(in);
    for(i=0;i<len;i++)
    {
        t=prec(in[i]);
        if(t==3)
        {
            pos[j++]=in[i];
        }
        else
        {
        if(top==-1||t>prec(stack[top]))
        {
            push(in[i]);
        }
        else
        {
            while(top!=-1&&prec(stack[top])>=t)
            {
            pos[j++]=pop();
            }
            push(in[i]);
        }


        }
    }
    while(top!=-1)
    {
        pos[j++]=pop();
    }
    pos[j]='\0';
    puts(pos);
}

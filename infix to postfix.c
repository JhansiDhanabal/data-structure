#include<stdio.h>
char stack[100];
int top=-1;
void push(char ch)
{
    stack[++top]=ch;
}
char pop()
{
    top=top-1;
    return stack[top+1];
}
int priority(char ch)
{
    if(ch=='+' || ch=='-')
    {
        return 1;
    }
    else if(ch=='*' || ch=='/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char exp[100],arr[100],x;
    printf("enter expression:");
    gets(exp);
    int I=0,j=0;
    while(exp[I]!='\0')
    {
        if(exp[I]>='a' && exp[I]<='z')
        {
            arr[j++]=exp[I];
        }
        else if(exp[I]=='(')
        {
            push(exp[I]);
        }
        else if(exp[I]==')')
        {
            x=pop();
            while(x!='(')
            {
                arr[j++]=x;
                x=pop();
            }
        }
        else
        {
        while(priority(exp[I])<=priority(stack[top]))
        {
            x=pop();
            arr[j++]=x;
        }
        if(priority(exp[I])>priority(stack[top]))
        {
            push(exp[I]);
        }
        }
        I++;
    }
    while(top!=-1)
    {
        x=pop();
        arr[j++]=x;
    }
    printf("postfix expression:%s",arr);
}

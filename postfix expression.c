#include<stdio.h>
#include<string.h>
#include<malloc.h>
int stack[100];
int top=-1;
void push(int ch)
{
	stack[++top]=ch;
}
int pop()
{
	--top;
	return stack[top+1];
}
int main()
{
	char exp[100];
  int x,y,p;
	printf("enter postfix expression:");
	gets(exp);
	int i=0;
	while(exp[i]!='\0')
	{
		if(exp[i]>='0' && exp[i]<='9')
		{
			push(exp[i]-48);
		}
		else
		{
			y=pop();
			x=pop();
    if(exp[i]=='+')
    {
        p=x+y;
    }
    if(exp[i]=='*')
    {
        p=x*y;
    }
    if(exp[i]=='/')
    {
        p=x/y;
    }
    if(exp[i]=='-')
    {
        p=x-y;
    }
			push(p);
		}
		i++;
	}
 printf("%d",stack[0]);
}

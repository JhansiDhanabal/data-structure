#include<stdio.h>
#include<string.h>
char stack[100];
int top=-1;
void push(char item)
{
	stack[++top]=item;
}
int isempty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void pop()
{
	top--;
}
int main()
{
	char exp[100];
	int i=0;
	printf("enter expression:");
	scanf("%s",exp);
	char c=exp[0];
	if(exp[0]==')')
	{
		printf("The expression is invalid");
	}
	else
	{
		int len=strlen(exp);
	while(i<len)
	{
		if(exp[i]=='(')
		{
			push(exp[i]);
		}
		if(exp[i]==')')
		{
			pop();
		}
		i++;
		char c=exp[i];
	}
	if(isempty())
	{
		printf("The expression has well formed parenthesis");
	}
	else
	{
		printf("The expression is invalid");
	}
    }
	return 0;
}

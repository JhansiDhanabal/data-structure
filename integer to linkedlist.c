#include<stdio.h>
#include<malloc.h>

struct node
{
	int value;
	struct node *next;
}*head=NULL;

void insert(int data)
{
	struct node *newnode;
	newnode=(struct node*)malloc (sizeof(struct node));
	newnode->value=data;
	newnode->next=NULL;
	if(head==NULL)
		head=newnode;
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void display()
{
	struct node *p=head;
	while(p!=NULL)
	{
		printf("%d ",p->value);
		p=p->next;
	}
}
void create()
{
	int num,rem;
	printf("enter the number:");
	scanf("%d",&num);
	while(num>0)
	{
		rem=num%10;
		insert(rem);
		num=num/10;
	}
}
void main()
{
	int choice,j=1;
	printf("1.create a list\n");
	printf("2.display\n");
	printf("3.exit");
	while(j==1)
	{
		printf("\nenter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				create();
				break;
		    case 2:
		    	display();
		    	break;
			case 3:
				j=0;
				break;
		}
	}
}


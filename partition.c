#include<stdio.h>
#include<malloc.h>
struct node
{
	int value;
	struct node *next;
}*head=NULL,*head1=NULL;

void insert()
{
	int data;
	struct node *newnode;
	newnode=(struct node*)malloc (sizeof(struct node));
	printf("enter the value:");
	scanf("%d",&data);
	newnode->value=data;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		struct node *p;
		p=head;
		while(p->next != NULL)
		{
			p=p->next;
		}
		p->next=newnode;
	}
}
void display()
{
	struct node *p;
	p=head;
	while(p->next != NULL)
	{
		printf("%d ",p->value);
		p=p->next;
	}
	printf("%d ",p->value);
}
void display1()
{
	struct node *p;
	p=head1;
	while(p->next != NULL)
	{
		printf("%d ",p->value);
		p=p->next;
	}
	printf("%d ",p->value);
}
int count()
{
	struct node *p;
	p=head;
	int i=1;
	while(p->next != NULL)
	{
		i++;
		p=p->next;
	}
	return i;
}

void partition()
{
	int n=count();
	int j,i,k;
	struct node *p;
	p=head;
	i=1;
	while(i<n/2)
	{
		p=p->next;
		i++;
	}
	head1=p->next;
	p->next=NULL;
	printf("\nfirst list:\n");
	display();
	printf("\nsecond list:\n");
	display1();
}


void main()
{
	int choice;
	int i=1;
	printf("1.create a list\n");
	printf("2.partition in the list\n");
	printf("3.exit");
	while(i)
	{
		printf("\n\nenter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				partition();
				break;
			case 3:
				i=0;
		}
	}
}

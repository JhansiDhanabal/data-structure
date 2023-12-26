#include<stdio.h>
#include<malloc.h>
struct node
{
	int value;
	struct node *next;
}*head=NULL;

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

void middle()
{
	struct node *p;
	p=head;
	int n=count();
	int j=0;
	while(j<n/2)
	{
		p=p->next;
		j++;
	}
	printf("%d ",p->value);
}

void main()
{
	int choice;
	printf("1.create a list\n");
	printf("2.middle element in the list\n");
	printf("3.exit");
	while(1)
	{
		printf("\n\nenter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				middle();
				break;
			case 3:
				exit(0);
		}
	}
}



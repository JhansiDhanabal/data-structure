#include<stdio.h>
#include<malloc.h>
struct node
{
	int value;
	struct node *next;
}*head=NULL;

void insertfirst()
{
	int data;
	struct node *newnode;
	newnode=(struct node*)malloc (sizeof(sructnode));
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
		newnode->next=head;
		head=newnode;
	}
}

void inserlast()
{
	int data;
	struct node *newnode;
	newnode=(struct node*)malloc (sizeof(sructnode));
	printf("enter the value:");
	scanf("%d",&data);
	newnode->value=data;
	new->next=NULL;
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
void insertmiddle()
{
	int data;
	struct node *newnode;
	newnode=(struct node*)malloc (sizeof(sructnode));
	printf("enter the value:");
	scanf("%d",&data);
	newnode->value=data;
	newnode->next=NULL;
	int num;
	printf("enter number after which given data has to be inserted:");
	scanf("%d",&num);
	struct node *p;
	p=head;
	while(p->value!=num)
	{
		p=p->next;
	}
	newnode->next=p->next;
	p->next=newnode;
}

void deletefirst()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("hey! fool how empty list will be deleted\n");
	}
	else
	{
		temp=head;
		head=temp->next;
		free(temp);
	}
}

void deletelast()
{
	struct node *temp;
	struct node *p;
	if(head==NULL)
	{
		printf("hey! fool how empty list will be deleted\n");
	}
	else
	{
		p=head;
		while(p->next->next!=NULL)
		{
			P=P->next;
		}
		temp=p->next;
		p->next=NULL;
		free(temp);
	}
}

void deletemiddle()
{
	int data;
	printf("enter value to be deleted:");
	scanf("%d",&data);
	struct node *p,*temp;
	p=head;
	while(p->next->value!=data)
	{
		p=p->next;
	}
	temp=p->next;
	p->next=temp->next;
	free(temp);
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

void main()
{
	printf("1.insert first\n");
	printf("2.insert last\n");
	printf("3.insert middle\n");
	printf("4.delete first\n");
	printf("5.delete last\n");
	printf("6.delete middle\n");
	printf("7.display\n");
	int choice;
	do
	{
		printf("\n\nenter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insertfirst();
				break;
			case 2:
				inserlast();
				break;
			case 3:
				insertmiddle();
				break;
			case 4:
				deletefirst();
				break;
			case 5:
				deletelast();
				break;
			case 6:
				deletemiddle();
				break;
			case 7:
				display();
				break;
			default:
			    break;
		}
	}while(choice>=7);
}







































































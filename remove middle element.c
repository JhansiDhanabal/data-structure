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
		head=newnode;
	else
	{
		struct node *p;
		p=head;
		while(p->next != NULL)
			p=p->next;
		p->next=newnode;
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
	struct node *p,*temp;
	p=head;
	int n=count();
	int j=0;
	while(j<n/2)
	{
		temp=p;
		p=p->next;
		j++;
	}
	printf("removed:%d ",p->value);
	temp->next=p->next;
	free(p);
}

void main()
{
	int choice,j=1;
	printf("1.create a list\n");
	printf("2.remove middle element in the list\n");
	printf("3.display\n");
	printf("4.exit");
	while(j==1)
	{
		printf("\nenter the choice:");
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
		    	display();
		    	break;
			case 4:
				j=0;
				break;
		}
	}
}


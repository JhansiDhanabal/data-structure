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
void display()
{
	struct node *p=head;
	while(p!=NULL)
	{
		printf("%d ",p->value);
		p=p->next;
	}
}
void minimum()
{
	struct node *p=head;
	int min=p->value;
	while(p!=NULL)
	{
		if(min>p->value)
		{
			min=p->value;
		}
		p=p->next;
	}
	printf("minimum value : %d\n",min);
}
void maximum()
{
	struct node *p=head;
	int max=p->value;
	while(p!=NULL)
	{
		if(max<p->value)
		{
			max=p->value;
		}
		p=p->next;
	}
	printf("maximum value : %d\n",max);
}
void main()
{
	int choice,j=1;
	printf("1.create a list\n");
	printf("2.minimum\n");
	printf("3.maximum\n");
	printf("4.display\n");
	printf("5.exit");
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
				minimum();
				break;
			case 3:
				maximum();
				break;
		    case 4:
		    	display();
		    	break;
			case 5:
				j=0;
				break;
		}
	}
}

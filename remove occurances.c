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
void removeoccurrences()
{
	int data;
	printf("enter data to be deleted:");
	scanf("%d",&data);
	struct node*p=head,*temp,*dummy;
	while(p!=NULL)
	{
		if(p->value==data)
		{
			temp=p;
			if(p==head)
			{
				head=head->next;
				p=p->next;
			}
			else
			{
				dummy->next=p->next;
				p=dummy;
			}
			free(temp);
		}
		else
		{
			dummy=p;
			p=p->next;
		}
	}
}
void main()
{
	int choice,j=1;
	printf("1.create a list\n");
	printf("2.remove\n");
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
				removeoccurrences();
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

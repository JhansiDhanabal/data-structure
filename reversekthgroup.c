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

void reverse()
{
	struct node*p,*p1;
	p=head;
	int temp;
	int i,j,k;
	printf("enter value of k:");
	scanf("%d",&i);
	(i%2==0)?(k=i/2):(k=i/2+1);
	while(k--)
	{
		j=1;
		p1=p;
		while(j<i)
		{
			p1=p1->next;
			j++;
		}
		temp=p->value;
		p->value=p1->value;
		p1->value=temp;
		
		p=p->next;
		i=i-2;
	}
}
void main()
{
	int choice;
	int i=1;
	printf("1.create a list\n");
	printf("2.reverse in the list\n");
	printf("3.display\n");
	printf("4.exit");
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
				reverse();
				break;
			case 3:
				display();
				break;
			case 4:
				i=0;
				break;
		}
	}
}

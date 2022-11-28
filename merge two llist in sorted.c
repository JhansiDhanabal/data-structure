#include<stdio.h>
#include<malloc.h>
struct node
{
	int value;
	struct node *next;
}*head1=NULL,*head2=NULL;
void insert2()
{
	int data;
	struct node *newnode;
	newnode=(struct node*)malloc (sizeof(struct node));
	printf("enter the value:");
	scanf("%d",&data);
	newnode->value=data;
	newnode->next=NULL;
	if(head2==NULL)
	{
		head2=newnode;
	}
	else
	{
		struct node *p;
		p=head2;
		while(p->next != NULL)
		{
			p=p->next;
		}
		p->next=newnode;
	}
}
void insert1()
{
	int data;
	struct node *newnode;
	newnode=(struct node*)malloc (sizeof(struct node));
	printf("enter the value:");
	scanf("%d",&data);
	newnode->value=data;
	newnode->next=NULL;
	if(head1==NULL)
	{
		head1=newnode;
	}
	else
	{
		struct node *p;
		p=head1;
		while(p->next != NULL)
		{
			p=p->next;
		}
		p->next=newnode;
	}
}
void display(struct node *head)
{
	struct node *p=head;
	while(p!=NULL)
	{
		printf("%d ",p->value);
		p=p->next;
	}
}
void sorted_ascending1()
{
    struct node *p,*p1;
    p=head1;
    int small;
    while(p!=NULL)
    {
        p1=p;
        small=p->value;
        while(p1!=NULL)
        {
            if(small>p1->value)
            {
                small=p1->value;
                p1->value=p->value;
                p->value=small;
            }
            p1=p1->next;
        }
        p=p->next;
        
    }
}
void sorted_ascending2()
{
    struct node *p,*p1;
    p=head2;
    int small;
    while(p!=NULL)
    {
        p1=p;
        small=p->value;
        while(p1!=NULL)
        {
            if(small>p1->value)
            {
                small=p1->value;
                p1->value=p->value;
                p->value=small;
            }
            p1=p1->next;
        }
        p=p->next;
        
    }
}
void merge()
{
    struct node *p;
    p=head1;
    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next=head2;
}
void main()
{
	int choice,j=1;
	printf("1.create a list 1\n");
	printf("2.create a list 2\n");
	printf("3.merge\n");
	printf("4.display list 1\n");
	printf("5.display list 2\n");
	printf("6.exit");
	while(j==1)
	{
		printf("\nenter the choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert1();
				sorted_ascending1();
				break;
			case 2:
				insert2();
				sorted_ascending2();
				break;
			case 3:
				merge();
				break;
		    case 4:
		    	display(head1);
		    	break;
		    case 5:
		    	display(head2);
		    	break;
			case 6:
				j=0;
				break;
		}
	}
}

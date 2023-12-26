#include<stdio.h>
#include<malloc.h>
struct node
{
	int value;
	struct node *next;
}*head=NULL,*head1=NULL,*head2[100];

void insertfirst()
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
		newnode->next=head;
		head=newnode;
	}
}

void inserlast()
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
void insertmiddle()
{
	int data;
	struct node *newnode;
	newnode=(struct node*)malloc (sizeof(struct node));
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

void deletelast()
{
	if(head == NULL)
	{
		printf("fool! how empty list is deleted");
	}
	else
	{
		struct node *p,*temp;
		p=head;
		while(p->next->next != NULL)
		{
			p=p->next;
		}
		temp=p->next;
		p->next=NULL;
		free(temp);
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
void partition_to_parts()
{
	int n=count();
	int j,i,k;
	struct node *p;
	p=head;
	printf("enter number of equal parts:");
	scanf("%d",&j);
	struct node *head2[j-1];
	for(k=0;k<j;k++)
	{
	    printf("/n %d linked list:\n",k+1);
	    i=1;
		while(i<n/j)
		{
		    printf("%d ",p->value);
			p=p->next;
		    i++;
	    }
	    printf("%d ",p->value);
	    head2[k]=p->next;
	    p->next=NULL;
	    p=head2[k];
    }
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

void reversekth()
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
void reverse()
{
	struct node*p,*p1;
	p=head;
	int temp;
	int i,j,k;
	i=count();
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
void palindrome()
{
	struct node*p,*p1;
	p=head;
	int temp;
	int i,j,k;
	int t=1;
	i=count();
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
		if(p->value!=p1->value)
		{
			t=0;
			break;
		}
		
		p=p->next;
		i=i-2;
	}
	if(t==0)
	{
		printf("given singly list is not palindrome");
	}
	else
	{
		printf("given singly list is palindrome");
	}
}
void circular()
{
	struct node *p;
	int n=count();
	while(n>0)
	{
		p=head;
		while(p->next->next != NULL)
		{
			p=p->next;
		}
		p->next->next=head;
		head=p->next;
		p->next=NULL;
		printf("\n");
		display();
		n--;
	}
}
void fromlast()
{
	struct node *p;
	p=head;
	int i=0,j,k;
	int n=count();
	printf("enter value of k:");
	scanf("%d",&k);
	j=n-k;
	while(i<j)
	{
		p=p->next;
		i++;
	}
	printf("%d ",p->value);
}
void convert_to_list()
{
	int n=count();
	int a[n];
	int i=0,j;
    struct node *p;
    p=head;
    for(i=0;i<n;i++)
    {
		a[i]=p->value;
		p=p->next;
	}
	printf("list:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	
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
	printf("8.middle\n");
	printf("9.partition to two\n");
	printf("10.partition to parts\n");
	printf("11.reverse\n");
	printf("12.reverse kth group\n");
	printf("13.palindrome\n");
	printf("14.convert to list\n");
	printf("15.kth element from last\n");
	printf("16.circular\n");
	printf("17.exit");
	int choice;
	int i=1;
	while(i)
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
			case 8:
				middle();
				break;
			case 9:
				partition();
				break;
			case 10:
				partition_to_parts();
				break;
			case 11:
				reverse();
				break;
			case 12:
				reversekth();
				break;
			case 13:
				palindrome();
				break;
			case 14:
				convert_to_list();
				break;
			case 15:
				fromlast();
				break;
			case 16:
				circular();
				break;
			case 17:
				i=0;
				break;
		}
	}
}






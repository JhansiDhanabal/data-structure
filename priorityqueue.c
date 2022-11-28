#include<stdio.h>
#include<malloc.h>
struct node
{
	int priority;
	int value;
	struct node *next;
}*rear=NULL,*front=NULL;
void enqueue()
{
	struct node *newnode,*p;
	int data,pri;
	printf("enter value:");
	scanf("%d",&data);
	printf("enter priority:");
	scanf("%d",&pri);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=data;
	newnode->priority=pri;
	newnode->next=NULL;
	if(rear==NULL)
	{
		rear=newnode;
		front=newnode;
	}
	else if(newnode->priority<front->priority)
	{
		newnode->next=front;
		front=newnode;
	}
	else
	{
		p=front;
		while(p->next!=NULL && newnode->priority>p->next->priority)
		{
			p=p->next;
		}
		newnode->next=p->next;
		p->next=newnode;
		if(newnode->next==NULL)
		{
			rear=newnode;
		}
	}
}
void dequeue()
{
	struct node *temp;
	if(front!=NULL)
	{
		temp=front;
		front=front->next;
		free(temp);
	}
	else
	{
		printf("queue is empty");
	}
}
void display()
{
	struct node *p=front;
	while(p!=rear)
	{
		printf("%d-%d\n",p->value,p->priority);
		p=p->next;
	}
	printf("%d-%d\n",p->value,p->priority);
}
int main()
{
  struct Node *root = NULL;
  int i=1,ch;
  printf("1.enqueue\n");
  printf("2.dequeue\n");
  printf("3.display\n");
  printf("4.exit");
  while(i==1)
  {
  	  printf("\nenter your choice:");
  	  scanf("%d",&ch);
  	  switch(ch)
  	  {
  	  	case 1:
  	  		enqueue();
  	  		break;
  	  	case 2:
  	  		dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			i=0;
			break;
	  }
  }
  return 0;
}

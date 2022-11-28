#include <stdio.h>
#include<malloc.h>
struct node
{
    struct node *left;
    int value;
    struct node *right;
}*t=NULL;

void insert(struct node *newnode,struct node *tr)
{
    if(newnode->value < tr->value)
    {
        if(tr->left==NULL)
        {
            tr->left=newnode;
        }
        else
        {
            insert(newnode,tr->left);
        }
    }
    else
    {
        if(tr->right==NULL)
        {
            tr->right=newnode;
        }
        else
        {
            insert(newnode,tr->right);
        }
    }
}
void create()
{
    int data;
    int ch=1;
    do
    {
        printf("enter value:");
        scanf("%d",&data);
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->left=NULL;
        newnode->value=data;
        newnode->right=NULL;
        if(t==NULL)
        {
            t=newnode;
            printf("%d ",t->value);
        }
        else
        {
            insert(newnode,t);
        }
        printf("do you want to continue?(1)(2):");
        scanf("%d",&ch);
    }while(ch==1);
}

int display(struct node *s)
{
    if(s!=NULL)
    {
        display(s->left);
        printf("%d ",s->value);
        display(s->right);
    }
}

void search(struct node *t,int data)
{
     if(t!=NULL)
     {
     if(t->value>data)
           search(t->left,data);
     else if(t->value <data)
     {
          search(t->right,data);
     }
     else
     {
         printf("search element is founded");
     }
     }
     else
     {
         printf("search element is not founded");        
     }
}

int max(int a, int b)
{
    if(a>b)
    {
           return a;      
    }
    else
    {
          return b;
    }
}
int height(struct node *t)
{
    if(t==NULL)
    {
               return 0;
    }
    else
    {
        return 1+max( height(t->left),height(t->right));
    }
}
int noofnodes(struct node  *t)
{
    if(t==NULL)
    {
               return 0;
    }
    else
    {
          return noofnodes(t->left)+noofnodes(t->right)+1;
    }
}
struct node* largest (struct node *t)
{
	if(t->right->right==NULL)
    {
		return t;
    }
    else
    {
		largest(t->right);
    }
}
struct node* delete(struct node *temp,int val)
{
	struct node *dummy;
	if(temp==NULL)
	return NULL;
	else if(val<temp->value)
     {
		  temp->left=delete(temp->left,val);
     }
    else if(val>temp->value)
     {
		  temp->right=delete(temp->right,val);
     }
      
     else
     {
     	if(temp->left==NULL && temp->right==NULL)
     	{
     	free(temp);
     	return NULL;
        }
     	else if(temp->left!=NULL)
     	{
     	dummy=temp->left; 
		free(temp);
		 return dummy;
        }
     	else if(temp->right!=NULL)
     	{
     	dummy=temp->right;
     	free(temp);
     	return dummy;
        }
     	else
     	{
     		dummy=temp;
			dummy=largest(dummy->left);
			temp->value=dummy->value;
			temp->left=delete(temp->left,temp->value);
		}
	 }
	return temp;
}

int main()
{
    printf("1.create\n");
    printf("2.search\n");
    printf("3.display\n");
    printf("4.number of nodes\n");
    printf("5.height\n");
    printf("6.delete\n");
    printf("7.exit");
    int ch,I=1;
    while(I==1)
    {
        printf("\nenter your choice:");
        scanf("%d",&ch);
       


        switch (ch)
        {
            case 1:
                create();
                break;
            case 2:
            {
                int data;
                printf("enter search element:");
                scanf("%d",&data);
                search(t,data);
                break;
            }
            case 3:
                display(t);
                break;
            case 4:
            {
                int d=noofnodes(t);
                printf("total nodes=%d",d);
                break;
            }
            case 5:
            {
                 int h=height(t);
                 printf("height=%d",h-1);
                 break;
            }
            case 6:
            {
                 int de;
                 printf("enter deleted element:");
                 scanf("%d",&de);
                 t=delete(t,de);
                 printf("deleted successfully\n");
                 break;
            }
            case 7:
                I=0;
                break;
        }
    }
    return 0;
}


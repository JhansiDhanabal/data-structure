#include<stdio.h>
#include<malloc.h>
 struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
}*t=NULL;
int max(int a, int b)
{
    return (a > b)? a : b;
}
int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return 1+max(height(N->left), height(N->right));
}
struct Node* allocation(int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->value  = data;
    newnode->left   = NULL;
    newnode->right  = NULL;
    return(newnode);
}
struct Node *LL(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}
struct Node *RR(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    return y;
}
int balancefactor(struct Node *temp)
{
    if (temp == NULL)
        return 0;
    return height(temp->left) - height(temp->right);
}
struct Node* insert(struct Node* temp, int data)
{
    if (temp == NULL)
        return(allocation(data));
    if (data < temp->value)
        temp->left  = insert(temp->left, data);
    else if (data > temp->value)
        temp->right = insert(temp->right, data);
    else
        return temp;
    int balance = balancefactor(temp);
    if (balance > 1 && data < temp->left->value)
        return LL(temp);
    if (balance < -1 && data > temp->right->value)
        return RR(temp);
    if (balance > 1 && data > temp->left->value)
    {
        temp->left =  RR(temp->left);
        return LL(temp);
    }
    if (balance < -1 && data < temp->right->value)
    {
        temp->right = LL(temp->right);
        return RR(temp);
    }
    return temp;
}
void display(struct Node *temp)
{
    if(temp != NULL)
    {
        display(temp->left);
        printf("%d ", temp->value);
        display(temp->right);
    }
}
void create()
{
	int data;
	printf("enter value:");
	scanf("%d",&data);
	t=insert(t,data);
}
int main()
{
  struct Node *root = NULL;
  int i=1,ch;
  printf("1.insert\n");
  printf("2.display\n");
  printf("3.exit");
  while(i==1)
  {
  	  printf("\nenter your choice:");
  	  scanf("%d",&ch);
  	  switch(ch)
  	  {
  	  	case 1:
  	  		create();
  	  		break;
  	  	case 2:
  	  	{
  	  		printf("Inorder traversal of the constructed AVL tree is \n");
			display(t);
			break;
		}
		case 3:
			i=0;
			break;
	  }
  }
  return 0;
}

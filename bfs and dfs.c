#include<stdio.h>
int queue[30],stack[30];
int rear=-1,front=-1,pos=-1,top=-1,p=-1;
int bfs[20],dfs[20];
int comparequeue(int data)
{
    int j=0;
	for(j=0;j<=rear;j++)
    {
        if(queue[j]==data)
        {
            return 0;
        }
    }
    return 1;
}
int equalsbfs(int data)
{
	int j;
    for(j=0;j<=pos;j++)
    {
        if(bfs[j]==data)
        {
            return 0;
        }
    }
    return 1;
}
int comparedstack(int data)
{
	int j;
    for(j=0;j<=top;j++)
    {
        if(stack[j]==data)
        {
            return 0;
        }
    }
    return 1;
}
int equaldfs(int data)
{
    int j;
	for(j=0;j<=p;j++)
    {
        if(dfs[j]==data)
        {
            return 0;
        }
    }
    return 1;
}
void breadth(int n,int arr[][n])
{
	int I=0,j,k;
    queue[++rear]=I;
    while(rear>=front)
    {
        if(comparequeue(I))
        {
            queue[++rear]=I;
        }
        if(equalsbfs(queue[front]))
        {
            bfs[++pos]=queue[front];
            printf("%d ",bfs[pos]);
        }
        I=queue[front];
        k=queue[front];
        front++;
        for(j=0;j<n;j++)
        {
            if(arr[k][j]==1)
            {
                if(comparequeue(j)&&equalsbfs(j))
                {
                    queue[++rear]=j;
                }
            }
        }
    }
}
int depth(int n,int arr[][n])
{
	int I=0,k,j;
    stack[++top]=I;
    while(top>=0)
    {
        if(comparedstack(I))
        {
            stack[++top]=I;
        }
        if(equaldfs(stack[top]))
        {
            dfs[++p]=stack[top];
            printf("%d ",dfs[p]);
        }
        k=stack[top];
        top--;
        I=stack[top];
        for(j=0;j<n;j++)
        {
            if(arr[k][j]==1)
            {
                if(comparedstack(j)&&equaldfs(j))
                {
                    stack[++top]=j;
                }
            }
        }
    }
}
int main()
{
    int n,I=0,j,s=1,ch,k;
    printf("enter number of vertices:");
    scanf("%d",&n);
    int arr[n][n];
    printf("creation of adjacency matrix:\n");
    for(I=0;I<n;I++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[I][j]);
        }
    }
    printf("1.bfs\n");
    printf("2.dfs\n");
    printf("3.exit");
    while(s==1)
    {
    printf("\nenter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
    {
    	breadth(n,arr);
	    break;
    }
    case 2:
    {
    	depth(n,arr);
        break;
    }
    case 3:
    {
        s=0;
        break;
    }
    }
    }
}

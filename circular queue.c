#include<stdio.h>
int rear=-1,front=-1;
int queue[10];
int isfull()
{
    if(front==(rear+1)%10)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue()
{
    int data;
    if(isfull())
    {
        printf("sorry queue is full\n");
    }
    else
    {
        printf("enter element to be inserted:");
        scanf("%d",&data);
        if(front==-1)
        {
            front=rear=0;
            queue[rear]=data;
        }
        else
        {
            rear=(rear+1)%10;
            queue[rear]=data;
        }
    }
}
int isempty()
{
    if(front==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void dequeue()
{
    if(isempty())
    {
        printf("sorry queue is empty!\n");
    }
    else
    {
        printf("deleted element:%d\n",queue[front]);
        if(rear==front)
        {
            rear=front=-1;
        }
        else
        {
            front=(front+1)%10;
        }
    }
}
void display()
{
    int I;
    I=front;
    while(I!=rear)
    {
        printf("%d ",queue[I]);
        I=(I+1)%10;
    }
    printf("%d ",queue[I]);
}
void main()
{
    printf("1.enqueue\n2.dequeue\n3.display\n");
    int ch,I=1;
    while(I==1)
    {
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch (ch)
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
        }
    }
}

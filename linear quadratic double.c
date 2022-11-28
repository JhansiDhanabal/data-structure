#include<stdio.h>
void linearprobing(int arr[],int I,int data,int size)
{
    int index=((data%size)+I)%size;
    if(arr[index]!=-1)
    {
        linearprobing(arr,I+1,data,size);
    }
    else
    {
        arr[index]=data;
    }
}
void quadraticprobing(int arr[],int I,int c1,int c2,int data,int size)
{
    int index=(((data%size)+c1*I+c2*I*I)%size);
    if(arr[index]!=-1)
    {
        quadraticprobing (arr,I+1,c1,c2,data,size);
    }
    else
    {
        arr[index]=data;
    }
}
void doublehashing(int arr[],int I,int m1,int data,int size)
{
    int index=((data%size)+I*(data%m1))%size;
    if(arr[index]!=-1)
    {
        doublehashing(arr,I+1,m1,data,size);
    }
    else
    {
        arr[index]=data;
    }
}
int main()
{
    int k=0,n,data,ch,I=1,c1,j,c2,m1;
    printf("enter size:");
    scanf("%d",&n);
    printf("enter c1:");
    scanf("%d",&c1);
    printf("enter c2:");
    scanf("%d",&c2);
    printf("enter m':");
    scanf("%d",&m1);
    printf("1.linear probing\n");
    printf("2.quadratic probing\n");
    printf("3.double hashing\n");
    printf("4.display\n");
    printf("5.exit");
    int a[n];
    for(j=0;j<n;j++)
    {
        a[j]=-1;
    }
    while(I==1)
    {
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
            {
               
				printf("enter number:");
                scanf("%d",&data);
                linearprobing(a,0,data,n);
                break;
            }
            case 2:
            {
				
				printf("enter data:");
                scanf("%d",&data);
                quadraticprobing (a,0,c1,c2,data,n);
                break;
            }
            case 3:
            {
				printf("enter data:");
                scanf("%d",&data);
                doublehashing (a,0,m1,data,n);
                break;
            }
            case 4:
            {
                for(j=0;j<n;j++)
                {
                    printf("%d ",a[j]);
                }
                break;
            }
            case 5:
            {
                I=0;
                break;
            }
        }
    }
    return 0;
}

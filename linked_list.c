#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* start=NULL;
void create(int n)
{
    struct Node *newNode,*temp;
    int data,i;
    if(n<=0){
        printf("Number of nodes should be greater than 0.\n ");
        return;
    }
    for(i=1;i<=n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        if (newNode==NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter data for the node %d :",i);
        scanf("%d",&data);

        newNode->data=data;
        newNode->next=NULL;

        if(start==NULL)
        {
            start=newNode;
            temp=start;
        }
        else
        {
            temp->next=newNode;
            temp=newNode;
        }
    }
}


void display()
{
    struct Node *temp=start;
    if(temp==NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    printf("Linked List:");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL.\n");
}

void insertAtBeginning(int data)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=start;
    start=newNode;
    printf("Inserted %d at beginning.\n",data);
}

void insertAtEnd(int data)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=start;
    newNode->data=data;
    newNode->next=NULL;
    if(start==NULL)
    {
        start=newNode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Inserted %d at end.\n",data);
}

void insertAtPosition(int data,int pos)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node* temp=start;
    int i;
    newNode->data=data;
    if(pos<=0)
    {
        printf("Invalid Position.\n");
        return;
    }
    if(pos==1)
    {
        newNode->next=start;
        start=newNode;
        printf("Inserted %d at position %d.\n",data,pos);
        return;
    }
    for(i=1;i<pos-1&&temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Position Out OF Range");
        return;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    printf("Inserted %d at position %d.\n",data,pos);
}

int main()
{
    int n,data,choice,pos;
    printf("Enter number of nodes to create:");
    scanf("%d",&n);
    create(n);
    display();

    while(1)
    {
        printf("\n\n");
        printf("1. Insert at Beginning.\n");
        printf("2. Insert at End.\n");
        printf("3. Insert at any Position.\n");
        printf("4. Display.\n");
        printf("5. Exit.\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter data:");
                    scanf("%d",&data);
                    insertAtBeginning(data);
                    break;

            case 2: printf("Enter data:");
                    scanf("%d",&data);
                    insertAtEnd(data);
                    break;

            case 3: printf("Enter data and position:");
                    scanf("%d%d",&data,&pos);
                    insertAtPosition(data,pos);
                    break;

            case 4: display();
                    break;

            case 5: exit(0);

            default: printf("Invalid choice.Try again.\n");
        }
    }
    return 0;
}


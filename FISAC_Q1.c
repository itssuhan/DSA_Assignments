#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create(struct node *head)
{
    struct node *temp, *newnode;
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
         
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}
struct node *merge(struct node *head1, struct node *head2)
{
    struct node *temp1, *temp2;
    temp1 = head1;
    temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = temp2->data;
            newnode->next = temp1;
            head1 = newnode;
            temp1 = head1;
            temp2 = temp2->next;
        }
        else if (temp1->data < temp2->data)
        {
            if (temp1->next != NULL)
            {
                if (temp1->next->data > temp2->data)
                {
                    struct node *newnode = (struct node *)malloc(sizeof(struct node));
                    newnode->data = temp2->data;
                    newnode->next = temp1->next;
                    temp1->next = newnode;
                    temp2 = temp2->next;
                }
                else
                {
                    temp1 = temp1->next;
                }
            }
            else
            {
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                newnode->data = temp2->data;
                newnode->next = NULL;
                temp1->next = newnode;
                temp2 = temp2->next;
            }
        }
    }
    return head1;
}

void display(struct node *head)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("");
}

int main()
{
    struct node *head1 = NULL, *head2 = NULL;
    head1 = create(head1);
    head2 = create(head2);
    head1 = merge(head1, head2);
    printf("The Merged List is \n");
    display(head1);
    return 0;
}







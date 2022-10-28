#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *insert_rear(int ele, struct Node *first)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node *));
    ptr->data = ele;
    if (first == NULL)
    {
        ptr->next = NULL;
        return ptr;
    }
    struct Node *temp = first;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = NULL;
    return first;
}

struct Node *sort(struct Node *first, struct Node *second)
{

    struct Node *t1 = second;
    struct Node *t2 = first;
    int flag = 0;
    if (t1->data < t2->data)
    {
        struct Node *ptr2;
        ptr2 = (struct Node *)malloc(sizeof(struct Node *));
        ptr2->data = t1->data;
        ptr2->next = t2;
        first = ptr2;
        second = second->next;
    }
    while (t1->next != NULL)
    {
        t1 = t1->next;
    }
    while (t2->next != NULL)
    {
        t2 = t2->next;
    }
    if (t1->data > t2->data)
    {
        struct Node *ptr2;
        ptr2 = (struct Node *)malloc(sizeof(struct Node *));
        ptr2->data = t1->data;
        t2->next = ptr2;
        ptr2->next = NULL;
        flag = 1;
    }
    struct Node *temp;
    temp = first;
    do
    {
        if (flag == 0)
        {
            if (second == NULL)
            {
                break;
            }
        }
        else
        {
            if (second->next == NULL)
            {
                break;
            }
        }
        if (second->data > temp->data && second->data < temp->next->data)
        {

            struct Node *ptr;
            ptr = (struct Node *)malloc(sizeof(struct Node *));
            ptr->data = second->data;
            ptr->next = temp->next;
            temp->next = ptr;
            second = second->next;
        }
        else
        {
            temp = temp->next;
        }

    } while ((1));

    return first;
}

void display(struct Node *first)
{
    if (first == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    printf("Contents of list are\n");
    while (first != NULL)
    {
        printf("%d\n", first->data);
        first = first->next;
    }
}

int main()
{
    struct Node *head1;
    struct Node *head2;

    head1 = (struct Node *)malloc(sizeof(struct Node *));
    head2 = (struct Node *)malloc(sizeof(struct Node *));
    printf("Enter number of elements of List 1\n");
    int n1, n2, t;
    scanf("%d", &n1);
    printf("Enter elements of list1\n");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &t);
        head1 = insert_rear(t, head1);
    }
    printf("Enter number of elements of List 2\n");
    scanf("%d", &n2);
    printf("Enter elements of list1\n");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &t);
        head2 = insert_rear(t, head2);
    }
    struct Node *t1 = head1->next;
    free(head1);
    head1 = t1;
    struct Node *t2 = head2->next;
    free(head2);
    head2 = t2;
    head1 = sort(head1, head2);
    display(head1);
    return 0;
}
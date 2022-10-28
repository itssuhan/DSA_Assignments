#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char *data;
    int count;
    struct Node *next;
};
void displaycount(struct Node *first)
{
    struct Node *temp = first;
    printf("Contents of list are\n");
    while (temp != NULL)
    {
        printf("%s,%d\n", temp->data, temp->count);
        temp = temp->next;
    }
}
void display(struct Node *first)
{
    struct Node *temp = first;
    while (temp != NULL)
    {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}
struct Node *insert_rear(char *ele, struct Node *first)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node *));
    ptr->data = (char *)malloc(10 * sizeof(char));
    ptr->data = ele;
    if (first == NULL)
    {
        ptr->next = NULL;
        return ptr;
    }
    struct Node *temp = first;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = NULL;
    return first;
}
struct Node *Create()
{
    struct Node *first;
    first = (struct Node *)malloc(sizeof(struct Node *));
    first = NULL;
    printf("Enter number of students\n");
    int n, i;
    scanf("%d", &n);
    char *s1;
    printf("Enter names of students\n");
    for (i = 0; i < n; i++)
    {
        s1 = (char *)malloc(10 * sizeof(char));
        scanf("%s", s1);
        first = insert_rear(s1, first);
    }
    return first;
}
struct Node *delete_rear(struct Node *first)
{
    struct Node *temp1 = first;
    struct Node *temp2 = first->next;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    temp1->next = NULL;
    free(temp2);
    return first;
}
void Search(struct Node *first)
{
    struct Node *temp1 = first;
    struct Node *temp3 = first;
    while (temp1 != NULL)
    {
        struct Node *temp2 = temp1->next;
        temp1->count = 1;
        while (temp2 != NULL)
        {
            if (strcmp(temp1->data, temp2->data) == 0 && temp2->next != NULL)
            {
                struct Node *temp = temp2;
                temp3->next = temp2->next;
                free(temp);
                temp2 = temp2->next;
                temp3 = temp3->next;
                temp1->count++;
            }
            else if (strcmp(temp1->data, temp2->data) == 0 && temp2->next == NULL)
            {
                first = delete_rear(first);
                temp1->count++;
                temp2 = temp2->next;
                temp3 = temp3->next;
            }
            else
            {

                temp2 = temp2->next;
                temp3 = temp3->next;
            }
        }
        temp1 = temp1->next;
        temp3 = temp1;
    }
}
int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node *));
    head = NULL;
    head = Create();
    display(head);
    printf("After removing occurences :\n");
    Search(head);
    displaycount(head);
    return 0;
}
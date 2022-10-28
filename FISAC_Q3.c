#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void display(struct Node *first)
{
    if(first == NULL)
    {
        printf("List is empty\n");
        exit(0);
    }
    printf("Contents of list are\n");
    while(first != NULL)
    {
        printf("%d\n",first->data);
     first = first->next;
    }
}

struct Node *insert_rear(int ele,struct Node *first)
{
   struct Node *ptr;
   ptr = (struct Node *)malloc(sizeof(struct Node *));
   ptr->data = ele;
   if(first == NULL)
   {
    ptr->next = NULL;
    return ptr;
   }
   struct Node *temp = first;;
   while(temp->next != NULL)
   {
    temp = temp->next;
   }
   temp->next = ptr;
   ptr->next = NULL;
   return first;
}

struct Node *fibo(int n,struct Node *head)
{
   head = insert_rear(0,head);
   head = insert_rear(1,head);
   int count =2,temp;
   struct Node *temp1 = head;
   struct Node *temp2 = head->next;
   while(count!=n)
   {
      temp = temp1->data+temp2->data;
      head = insert_rear(temp,head);
      count++;
      temp1=temp2;
      temp2 = temp2->next;
   }
   return head;
}

int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node *));
    int n;
    printf("Enter number of terms to be printed\n");
    scanf("%d",&n);
    struct Node *t1 = head->next;
    free(head);
    head = t1;
    head = fibo(n,head);
    display(head);
}
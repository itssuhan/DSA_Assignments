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

struct Node *sortlist(struct Node *head,struct Node *head1,struct Node *head2,int n)
{
   struct Node *ptr = head;
   int i = 1;
   while(ptr != NULL)
   {
    if(i%2 != 0)
    {
        head1 = insert_rear(ptr->data,head1);
        i++;
        ptr=ptr->next;
    }
    else{
         head2 = insert_rear(ptr->data,head2);
        i++;
        ptr=ptr->next;
    }
   }
     if(n==0)
     {
        return head1;
     }
     else
     {
        return head2;
     }
   }

  // return head1;
int main()
{
    struct Node *head;
    struct Node *head1;
    struct Node *head2;
    head = (struct Node *)malloc(sizeof(struct Node *));
    head1 = (struct Node *)malloc(sizeof(struct Node *));
    head2 = (struct Node *)malloc(sizeof(struct Node *));
    printf("Enter number of elements \n");
    head = NULL;
    head1=NULL;
    head2=NULL;
    int n1,n2,t;
    scanf("%d",&n1);
    printf("Enter elements \n");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&t);
        head = insert_rear(t,head);
    }
    display(head);
    printf("Odd list : \n");
    head1 = sortlist(head,head1,head2,0);
    display(head1);
    head2 = sortlist(head,head1,head2,1);
    printf("Even list : \n");
    display(head2);
    return 0;
}
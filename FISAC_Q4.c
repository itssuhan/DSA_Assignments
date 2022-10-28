#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char *name;
    int roll_no;
    int marks;
    struct Node *next;
};

void display(struct Node *first)
{
    struct Node *temp = first;
    printf("Contents of list are\n");
    while(temp != NULL)
    {
    printf("%s,%d,%d\n",temp->name,temp->roll_no,temp->marks);
    temp = temp->next;
    }
}
struct Node *insert_rear(char *n,int roll,int mark,struct Node *first)
{
   struct Node *ptr;
   ptr = (struct Node *)malloc(sizeof(struct Node *));
   ptr->name =  (char *)malloc(10*sizeof(char));
   ptr->name = n;
   ptr->roll_no = roll;
   ptr->marks = mark;
   if(first == NULL)
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
void swap(struct Node *first,struct Node *second)
{
    int temproll;
    char *t;
    t = (char *)malloc(sizeof(char *));
    int tempmark;
    t = first->name;
    temproll = first->roll_no;
    tempmark = first->marks;
    first->name = second->name;
    first->roll_no = second->roll_no;
    first->marks = second->marks;
    second->name = t;
    second->roll_no = temproll;
    second->marks = tempmark;
}
struct Node *sorthighest(struct Node *first,int n)
{
    int temp;
    struct Node *ptr = first;
    for(int i=0;i<n-1;i++)
    {
   while(ptr->next != NULL)
   {
          if(ptr->marks<ptr->next->marks)
          {
            swap(ptr,ptr->next);
            ptr = ptr->next;
          }
          else{
            ptr = ptr->next;
          }
   }
   ptr = first;
    }
    return first;
 }


int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node *));
    head = NULL;
    printf("Enter number of students\n");
    int n,i;
    scanf("%d",&n);
   // char s[n][15];
    char *s1;
    int roll,mark;
        for(i=0;i<n;i++)
        {
            printf("Enter name of student %d\n",(i+1));
            s1 =  (char *)malloc(10*sizeof(char));
            scanf("%s",s1);
            printf("Enter Roll number of student %d\n",(i+1));
            scanf("%d",&roll);
            printf("Enter marks of student %d\n",(i+1));
            scanf("%d",&mark);
            head = insert_rear(s1,roll,mark,head);
        }

    display(head);
    printf("After sorting according to marks :\n");
    head = sorthighest(head,n);
    //printf("After sorting according to marks :\n");
    display(head);
     printf("Second highest marks :\n%s,%d,%d",head->next->name,head->next->roll_no,head->next->marks);
    return 0;
}
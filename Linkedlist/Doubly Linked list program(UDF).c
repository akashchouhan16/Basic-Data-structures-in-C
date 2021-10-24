#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *prev;
};
typedef struct node NODE;
NODE *LLnode,*head,*temp,*prev;
NODE* insert_at_front(NODE *);
NODE* insert_at_end(NODE *);
NODE* delete_at_front(NODE *);
NODE* delete_at_end(NODE *);
void display(NODE *);


main()
{
int ch;
head=NULL;

do
{
    printf("1--insert node at the front\n");
    printf("2--insert node at the end\n");
    printf("3--delete a node at the front\n");
    printf("4--delete a node at the end\n");
    printf("5--display the linked list\n");
   printf("6--close the program\n");

printf("enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:  head=insert_at_front(head);

                break;
case 2: head=insert_at_end(head);

                break;
case 3:head=delete_at_front(head);

                 break;
case 4: head=delete_at_end(head);

                 break;
case 5:   display(head);
                break;
case 6: exit(0);break;
default:printf("Invalid choice\n");
                break;
}
}while(ch!=6);


}
NODE* insert_at_front(NODE *head)
{
    LLnode=(NODE *)malloc(sizeof(NODE));
                printf("enter the data\n");
                scanf("%d",&LLnode->data);

                if(head==NULL)
                {
                    head=LLnode;
                    head->next=NULL;
                    head->prev=NULL;
                }
                else
                {
                  LLnode->next=head;
                  head=LLnode;
                  head->prev=NULL;
                }
        return(head);

}

NODE* insert_at_end(NODE *head)
{
    LLnode=(NODE *)malloc(sizeof(NODE));
                printf("enter the data\n");
                scanf("%d",&LLnode->data);
                LLnode->next=NULL;
                if(head==NULL)
                {
                    head=LLnode;
                    head->next=NULL;
                    head->prev=NULL;
                }
                else
                {
                    temp=head;
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=LLnode;
                    LLnode->prev=temp;
                    LLnode->next=NULL;
                }
        return(head);

}

NODE* delete_at_front(NODE *head)
{
    if(head==NULL)
                {
                    printf("Linked list is empty...cant delete a node\n");
                 }
                 else if(head->next==NULL)
                 {
                     //temp=head;
                     printf("node deleted=%d\n",head->data);
                     free(head);
                     head=NULL;
                 }
                 else
                 {
                     temp=head->next;
                     printf("node deleted=%d\n",head->data);
                     free(head);
                     head=temp;
                     head->prev=NULL;
                 }
                return(head);
}

NODE*  delete_at_end(NODE *head)
{
    if(head==NULL)
                {
                    printf("Linked list is empty...cant delete a node\n");
                 }
                 else if(head->next==NULL)
                 {
                     printf("node deleted=%d\n",head->data);
                     free(head);
                     head=NULL;
                 }
                 else
                 {
                     temp=head;
                     while(temp->next!=NULL)
                     {
                         prev=temp;
                         temp=temp->next;
                     }
                     printf("node deleted=%d\n",temp->data);
                     free(temp);
                     prev->next=NULL;
                 }
                 return(head);
}


void display(NODE *head)
{
    if(head==NULL)
                {
                    printf("Linked list is empty\n");
                }
                else
                {
                printf("the linked list is as below\n");
                   temp=head;
                   while(temp!=NULL)
                   {
                       printf("%d->",temp->data);
                       temp=temp->next;
                   }
                   printf("\n");
                }
}

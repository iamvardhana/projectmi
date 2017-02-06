//doubly linked list
#include<stdio.h>
#include<malloc.h>
struct node
{
 int data;
struct node * next;
 struct node *prev;
}*start=NULL;

struct node * new_node()
{
    int data;
    static struct node *nn;
    printf("\nEnter the data_> ");
    scanf("%d",&data);
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    return nn;
}

void insert()
{
 int n;
  struct node *newnode;
  newnode=new_node();
 printf("\nEnter>\n1.insert at end\n2>insert at beginning\n3>insert at a position.\n>");
 scanf("%d",&n);
 switch(n)
 {
  case 1:

  if(start==NULL)
  {
  newnode->next=NULL;
  newnode->prev=NULL;
  start=newnode;
  }
  else if(start->next==NULL)
  {
   start->next=newnode;
   newnode->prev=start;
   newnode->next=NULL;
  }
  else
  {
   struct node *temp;
  temp->next=newnode;
  newnode->prev=temp;
  newnode->next=NULL;
  }
//  case 2:
//  case 3;



 }


}

void del()
{




}

void deallocate_mem()
{



}

void reverse()
{



}

void search( int data)
{




}

void display()
{
int choice,i;
struct node *temp;
temp=start;
    if(!temp)
        printf("\nList is empty\n");
    else
    {
        printf("\nEnter choice\n1>Display first node\n2>Display last node\n3>Display node at selected index\n4>Display all nodes\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nnode : 0\t\tdata : %d\n",start->data);
                    break;
//            case 2: temp=find_end(&choice);
//                    printf("\nnode : %d\t\tdata : %d\n",choice-1,temp->data);
//                    break;
            case 3: printf("\nEnter index of node to display_> ");
                    scanf("%d",&choice);
                    find_end(&i);
                    if(choice>=0 && choice<=i)
                    {
                        for(i=0;i<choice;i++)
                            temp=temp->next;
                        printf("\nnode : %d\t\tdata : %d\n",choice,temp->data);
                    }
                    else
                        printf("\nIndex does not exist\n");
                    break;
//            case 4: display_nodes();
//                    break;
           default: printf("\nInvalid input\n");
        }
    }




}

int main(){

int choice;
while(1)
{
printf("\nEnter the choice:\n1>Insert a node.\n2>Delete a node.\n3>display the list.");
printf("\n4>searching for an element.\n5>reversing.\nany other no to exit.\n>");
scanf("%d",&choice);
switch(choice)
{
  case 1:insert();
         break;
  case 2:del();
         break;
  case 3:display();
         break;
  case 4:if(!start)
           printf("\nThe list is empty.");
         else
         {
         printf("\nenter element to be searched>");
         scanf("%d",&choice);
         search(choice);
         }
         break;
  case 5: reverse();
          break;
  default:deallocate_mem();
          return 0;
}
}
}
